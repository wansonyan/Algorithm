'''
Descripttion: 
version: 
Author: vansson
Date: 2023-12-15 16:44:44
LastEditors: vansson
LastEditTime: 2023-12-23 11:11:45
'''
import fitz  # PyMuPDF

def merge_pdfs(pdf1_path, pdf2_path, output_path):
    # 打开两个 PDF 文件
    pdf1 = fitz.open(pdf1_path)
    pdf2 = fitz.open(pdf2_path)

    # 创建新的 PDF 文档
    merged_pdf = fitz.open()

    # 将第一个 PDF 文件的页面添加到新文档
    for page_num in range(pdf1.page_count):
        page = pdf1[page_num]
        merged_pdf.insert_pdf(pdf1, from_page=page_num, to_page=page_num, start_at=merged_pdf.page_count)

    # 将第二个 PDF 文件的页面添加到新文档
    for page_num in range(pdf2.page_count):
        page = pdf2[page_num]
        merged_pdf.insert_pdf(pdf2, from_page=page_num, to_page=page_num, start_at=merged_pdf.page_count)

    # 保存合并后的 PDF 到输出文件
    merged_pdf.save(output_path)

    # 关闭所有打开的 PDF 文件
    pdf1.close()
    pdf2.close()
    merged_pdf.close()

# 使用示例
pdf1_path = '/home/vansson/Downloads/1.pdf'
pdf2_path = '/home/vansson/Downloads/22.pdf'
output_path = '/home/vansson/Downloads/output.pdf'

merge_pdfs(pdf1_path, pdf2_path, output_path)
