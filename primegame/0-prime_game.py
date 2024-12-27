#!/usr/bin/python3
"""Function that determine who the winner of each game is."""


def isWinner(x, nums):
    """Determine the winner of the Prime Game"""
    if not nums or x < 1:
        return None

    maria_wins = 0
    ben_wins = 0

    for n in nums[:x]:
        winner = play_round(n)
        if winner == 'Maria':
            maria_wins += 1
        else:
            ben_wins += 1

    if maria_wins > ben_wins:
        return 'Maria'
    elif ben_wins > maria_wins:
        return 'Ben'
    else:
        return None
