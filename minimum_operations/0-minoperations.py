#!/usr/bin/python3
"""Method that calculate the fewest number of operations"""

def minOperations(n):
    """initialize a variable to count the operations"""
    if n <= 1:
        return 0

    operations = 0
    factorization = 2
"""While n divisible by factorization"""
    while n > 1:
        while n % factorization == 0:
            operations += factorization
            n //= factorization
        factorization += 1

    return operations
