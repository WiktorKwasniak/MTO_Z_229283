#!/usr/bin/env python3

import sys

def convertHex(string):
    converted = ''
    for char in string:
        if 'a' <= char <= 'f':
            converted += chr(ord(char)+6)
        else:
            converted += char

    return converted


def my_printf(format_string, param):
    #print(format_string)
    shouldDo = True
    for idx in range(0, len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'j':
                if param.isnumeric():
                    hexValue = f"{int(param):x}"
                    convertedStr = convertHex(hexValue)
                    print(f'\n{convertedStr}')
                    print(hexValue, end="")
                    shouldDo = False
                else:
                    print(format_string[idx], end="")
            else:
                print(format_string[idx], end="")
        else:
            shouldDo = True
    print("")

data=sys.stdin.readlines()

for i in range(0, len(data), 2):
    my_printf(data[i].rstrip(), data[i+1].rstrip())
