#!/usr/bin/python3
"""Method that calculate the fewest n umber of operations"""

def minOperations(n):
    """initialize a variable to count the operations"""
    if n <= 1:
        return 0

    operations = 2
    factorization = 0

    while n > 1:
        while n % operations == 0:
            factorization += operations
            n // = operations
        operations += 1

    return operations
