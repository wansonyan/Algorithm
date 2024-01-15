'''
Descripttion: 
version: 
Author: vansson
Date: 2024-01-08 11:06:43
LastEditors: vansson
LastEditTime: 2024-01-09 10:42:25
'''
import json
from collections import OrderedDict

def calculate_instance_area(bbox):
    width = float(bbox[2])
    height = float(bbox[3])
    area = width * height
    return area

def count_json_categories_by_area(json_file_path, area_ranges):
    categories = {}
    area_counts = {area_range: 0 for area_range in area_ranges}
    total_instances = 0
    total_count = 0
    image_ids = set()

    with open(json_file_path, 'r') as file:
        data = json.load(file)
        annotations = data['annotations']

        for instance in annotations:
            category_id = instance['category_id']
            image_id = instance['image_id']
            bbox = instance['bbox']



            area = calculate_instance_area(bbox)

            if category_id in categories:
                categories[category_id] += 1
            else:
                categories[category_id] = 1

            total_instances += 1

            if category_id == 1:
                image_ids.add(image_id)
                for area_range in area_ranges:
                    if area > area_range[0] and area <= area_range[1]:
                        area_counts[area_range] += 1
                        total_count += 1
                        break
                    
    num_images_with_category_1 = len(image_ids)

    return categories, area_counts, total_instances, total_count, num_images_with_category_1


json_file_path = '/media/vansson/etc/downloads/helmet_dataset/instances_val.json'
area_ranges = [(0, 64**2), (64**2, 128**2), (128**2, 192**2), (192**2, 256**2), (256**2, 320**2), (320**2, 384**2),
               (384**2, 448**2), (448**2, 512**2), (512**2,576**2), (576**2, 640**2), (640**2,704**2),
               (704**2, 768**2), (768**2, 832**2), (832**2, 896**2), (896**2, 960**2),(960**2, 1024**2), (1024**2, 1000000000000000)]  # 设置不同像素面积范围
categories, area_counts, total_instances, total_count, num_images_with_category_1= count_json_categories_by_area(json_file_path, area_ranges)

# 打印类别及其数量
sorted_categories = sorted(categories.items(), key=lambda x:x[0])
for category_id, count in sorted_categories:
    print(f'类别ID: {category_id}, 数量: {count}')

# 打印不同像素面积范围下的数量
for area_range, count in area_counts.items():
    print(f'像素面积范围: {area_range}, 数量: {count}')

#打印实例总数
print(f'实例数量：{total_instances}')

# 打印总数量
print(f'总数量: {total_count}')

# 打印图片数量
print(f'图片数量: {num_images_with_category_1}')