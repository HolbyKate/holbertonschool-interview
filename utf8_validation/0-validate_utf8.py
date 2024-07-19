#!/usr/bin/python3
"""Method that determines if given data set represents valid UTF-8 encoding"""


def validUTF8(data):
    num_bytes = 0

    for byte in data:
        binary_rep = format(byte, '#010b')[-8:]
        if num_bytes == 0:
            # Determine how many bytes the current UTF-8 character requires
            if binary_rep[0] == '0':
                continue
            elif binary_rep.startswith('110'):
                num_bytes = 1
            elif binary_rep.startswith('1110'):
                num_bytes = 2
            elif binary_rep.startswith('11110'):
                num_bytes = 3
            else:
                return False
        else:
            # Check continuation bytes: must start with '10'
            if not binary_rep.startswith('10'):
                return False
            num_bytes -= 1

    return num_bytes == 0
