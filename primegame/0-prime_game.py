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


def is_prime(n):
    """Check if a number is prime"""
    if n < 2:
        return False
    for i in range(2, int(n ** 0.5) + 1):
        if n % i == 0:
            return False
    return True


def get_primes_up_to(n):
    """Get list of prime numbers up to n using Sieve of Eratosthenes"""
    sieve = [True] * (n + 1)
    sieve[0] = sieve[1] = False

    for i in range(2, int(n ** 0.5) + 1):
        if sieve[i]:
            for j in range(i * i, n + 1, i):
                sieve[j] = False

    return [i for i in range(2, n + 1) if sieve[i]]


def play_round(n):
    """Simulate a single round of the game"""
    if n < 2:
        return 'Ben'
    primes = get_primes_up_to(n)
    moves = len(primes)
    return 'Maria' if moves % 2 == 1 else 'Ben'
