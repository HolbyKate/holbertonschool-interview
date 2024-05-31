#!/usr/bin/python3
"""Module that calculate the fewest number of operations"""


def minOperations(n):
    """
    Calculate the minimum number of operations required to obtain n from 1
    """
    if n <= 1:
        return 0

    operations = 0
    factorization = 2

    while n > 1:
        """While n divisible by factorization"""
        while n % factorization == 0:
            operations += factorization
            n //= factorization
        factorization += 1

    return operations
