#!/usr/bin/env python3

import sys
import re

def convert_number(param):
    new_str = ''
    for idy in range(0, len(param)):
        if param[idy] == '0':
            new_str += str((9 * 9 + 1) % 10)
        else:
            new_str += str((int(param[idy]) * 9 + 1) % 10)

    return new_str

def my_printf(format_string, param):
    shouldDo = True
    for idx in range(0,len(format_string)):
        if shouldDo:
            if format_string[idx] == '#' and format_string[idx+1] == 'g' and format_string[idx-1] != '#':
                if param.isnumeric():
                    new_str = convert_number(param)

                    print(new_str, end="")
                    shouldDo = False
                else:
                    print(format_string[idx], end="")
            elif format_string[idx] == '#' and format_string[idx+1] == '.' and format_string[idx+2].isnumeric():
                if re.search('#\.[0-9]+g', format_string[idx:]):
                    amount = re.search('#\.[0-9]+g', format_string[idx:]).group(0)[1:-1]
                    new_str = convert_number(param)


                    print('{0: >{width}}'.format(new_str, width=amount), end="")
                else:
                    print(format_string[idx], end="")

            else:
                print(format_string[idx], end="")

        else:
            shouldDo=True

    print("")

data=sys.stdin.readlines()
for i in range(0,len(data),2):
    my_printf(data[i].rstrip(),data[i+1].rstrip())
