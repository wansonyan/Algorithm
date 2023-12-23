'''
Descripttion: 
version: 
Author: vansson
Date: 2023-12-15 16:44:44
LastEditors: vansson
LastEditTime: 2023-12-15 16:51:05
'''
# import PyPDF3  
  
# # 打开第一个PDF文件  
# pdf1 = open('/home/vansson/Downloads/1.pdf', 'rb')  
# pdf_reader1 = PyPDF.PdfFileReader(pdf1)  
  
# # 打开第二个PDF文件  
# pdf2 = open('/home/vansson/Downloads/22.pdf', 'rb')  
# pdf_reader2 = PyPDF.PdfFileReader(pdf2)  
  
# # 创建一个新的PDF写入对象  
# pdf_writer = PyPDF.PdfFileWriter()  
  
# # 合并第一个PDF文件的所有页面到新的PDF  
# for page in range(pdf_reader1.getNumPages()):  
#     pdf_writer.addPage(pdf_reader1.getPage(page))  
  
# # 合并第二个PDF文件的所有页面到新的PDF  
# for page in range(pdf_reader2.getNumPages()):  
#     pdf_writer.addPage(pdf_reader2.getPage(page))  
  
# # 将合并后的PDF写入到一个新的文件中  
# with open('merged.pdf', 'wb') as output_pdf:  
#     pdf_writer.write(output_pdf)  
  
# # 关闭所有打开的PDF文件和写入对象  
# pdf1.close()  
# pdf2.close()  
# pdf_writer.close()
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
