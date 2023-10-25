import os

files_list = os.listdir()

for file in files_list:
    if file.endswith(".cpp"):
        with open(file, "r", encoding='utf-8') as f:
            lines = f.readlines()
        with open(file, "w", encoding='utf-8') as f:
            lines.insert(0, "// NAME: HAMMAD ZAFAR\n")
            lines.insert(1, "// ROLL NO : 2022-CS-639 (A)\n\n")
            f.writelines(lines)
