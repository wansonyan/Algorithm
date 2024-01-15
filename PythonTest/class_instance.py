'''
Descripttion: 
version: 
Author: vansson
Date: 2023-12-27 16:56:18
LastEditors: vansson
LastEditTime: 2024-01-11 16:48:33
'''
import os
from xml.etree import ElementTree as ET

def calculate_instance_area(bbox):
    xmin = float(bbox.find('xmin').text)
    ymin = float(bbox.find('ymin').text)
    xmax = float(bbox.find('xmax').text)
    ymax = float(bbox.find('ymax').text)
    width = xmax - xmin
    height = ymax - ymin
    area = width * height
    return area

def count_xml_categories_by_area(folder_path, area_ranges):
    categories = {}
    area_counts = {area_range: 0 for area_range in area_ranges}
    total_instances = 0 # 实例总数
    total_count = 0 # 统计不同尺度下的实例总数

    # 遍历文件夹中的每个XML文件
    for filename in os.listdir(folder_path):
        if filename.endswith('.xml'):
            file_path = os.path.join(folder_path, filename)
            tree = ET.parse(file_path)
            root = tree.getroot()

            # 获取XML文件中的类别和框信息
            for obj in root.findall('object'):
                category = obj.find('name').text
                bbox = obj.find('bndbox')

                # 计算实例的像素面积
                area = calculate_instance_area(bbox)
                
                # 统计类别及其数量
                if category in categories:
                    categories[category] += 1
                else:
                    categories[category] = 1
                    
                total_instances += 1

                # 根据面积范围统计数量
                for area_range in area_ranges:
                    if area > area_range[0] and area <= area_range[1]:
                        area_counts[area_range] += 1
                        total_count += 1
                        break

    return categories, area_counts, total_instances, total_count

folder_path = r'/media/vansson/etc/downloads/helmet_dataset/Hardhat/Train/Annotation'
area_ranges = [(0, 64**2), (64**2, 128**2), (128**2, 192**2), (192**2, 256**2), (256**2, 320**2), 
               (320**2, 384**2), (384**2, 448**2), (448**2, 512**2), (512**2,576**2), (576**2, 640**2), 
               (640**2,704**2), (704**2, 768**2), (768**2, 832**2), (832**2, 896**2), (896**2, 960**2), 
               (960**2, 1024**2), (1024**2, 1000000000000000)]  # 设置不同像素面积范围
categories, area_counts ,total_instances, total_count= count_xml_categories_by_area(folder_path, area_ranges)

# 打印类别及其数量
for category, count in categories.items():
    print(f'类别: {category}, 数量: {count}')

# 打印不同像素面积范围下的数量
for area_range, count in area_counts.items():
    print(f'像素面积范围: {area_range}, 数量: {count}')

# 打印实例总数   
print(f'实例总数：{total_instances}')

# 打印统计不同尺度下的实例总数   
print(f'实例总数：{total_count}')