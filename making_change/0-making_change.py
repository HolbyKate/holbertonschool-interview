#!/usr/bin/python3
"""
Determine the fewest number of coins needed to meet a given amount total
"""


def makeChange(coins, total):
    if total <= 0:
        return 0

    # Initialize a dynamic programming array
    dp = [total + 1] * (total + 1)
    dp[0] = 0

    # Sort coins in descending order for optimization
    coins.sort(reverse=True)

    # Iterate through all amounts from 1 to total
    for i in range(1, total + 1):
        # Try each coin
        for coin in coins:
            if coin <= i:
                dp[i] = min(dp[i], dp[i - coin] + 1)

    return dp[total] if dp[total] != total + 1 else -1
