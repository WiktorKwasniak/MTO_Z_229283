#!/usr/bin/env python3

import sys
import re

def convertHex(string):
    converted = ''
    for char in string:
        if 'a' <= char <= 'f':
            char = chr(ord(char)+6)
 
        if char == '0':
            char = 'o'

        converted += char

    return converted


def addZeros(hexValue, amount):
    hexLen = len(hexValue)
    if hexLen < int(amount):
        for i in range(int(amount) - hexLen):
            hexValue = '0' + hexValue

    return hexValue


def my_printf(format_string, param):
    shouldDo = True
    shouldDoIt = 0
    for idx in range(0, len(format_string)):
        if shouldDoIt > 0:
            shouldDoIt -= 1
            continue

        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'j' and param.isnumeric():
                hexValue = f"{int(param):x}"
                print(convertHex(hexValue), end="")

                shouldDo = False
            elif format_string[idx] == '#' and format_string[idx+1] == '.' and format_string[idx+2].isnumeric():
                if re.search('#\.[0-9]+j', format_string[idx:]) and param.isnumeric():
                    amount = re.search('#\.[0-9]+j', format_string[idx:]).group(0)[2:-1]
                    hexValue = f"{int(param):x}"

                    if int(amount) >= len(param):
                        hexValue = addZeros(hexValue, amount)
                        print(convertHex(hexValue), end="")
                    else:
                        print(convertHex(hexValue), end="")

                    shouldDoIt = len(amount) + 2
                else:
                    print(format_string[idx], end="")
            else:
                print(format_string[idx], end="")
        else:
            shouldDo = True
    print("")


data = sys.stdin.readlines()

for i in range(0, len(data), 2):
    my_printf(data[i].rstrip(), data[i+1].rstrip())
