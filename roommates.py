from openpyxl import Workbook
from openpyxl.compat import range
from openpyxl.utils import get_column_letter
from openpyxl.styles import *

wb = Workbook ()
ws = wb.active
ws.title = "Roommates"
ws.sheet_properties.tabColor = "000398"

roomMates = [
	['Name', 'Ali', 'Turan', 'Ilkin', 'Nima', 'Xalil'],
	['Height (cm)', '176', '168', '170', '177', '174'],
	['Weight (kg)', '60', '51', '55', '60', '64']
]

for col in range (1, 4):
	for row in range (1, 7):
		ws.cell(column = col, row = row, value = roomMates [col - 1] [row - 1])

firstCol = ws.column_dimensions['A']
firstRow = ws.row_dimensions[1]
firstCol.font = Font(bold = True)
firstRow.font = Font(bold = True)

wb.save("guys.xlsx")
