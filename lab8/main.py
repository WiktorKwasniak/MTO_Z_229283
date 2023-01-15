#!/usr/bin/env python3

import sys


def convertHex(string):
    converted = ''
    for char in string:
        if 'a' <= char <= 'f':
            char = chr(ord(char)+6)
 
        if char == '0':
            char = 'o'
            
        converted += char

    return converted


def my_printf(format_string, param):
    shouldDo = True
    for idx in range(0, len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'j' and param.isnumeric():
                hexValue = f"{int(param):x}"
                print(convertHex(hexValue), end="")

                shouldDo = False
            else:
                print(format_string[idx], end="")
        else:
            shouldDo = True
    print("")


data = sys.stdin.readlines()

for i in range(0, len(data), 2):
    my_printf(data[i].rstrip(), data[i+1].rstrip())
