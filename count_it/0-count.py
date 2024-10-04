#!/usr/bin/python3

import requests
"""
    queries the Reddit API,
    parses the title of all hot articles,
    and prints a sorted count of given keywords
    """


def count_words(subreddit, word_list, after=None, word_count=None):
    if word_count is None:
        # Initialize the word count dictionary
        word_count = {word.lower(): 0 for word in word_list}

    # Set up the URL for the Reddit API
    url = f'https://www.reddit.com/r/{subreddit}/hot.json'
    headers = {'User-Agent': 'Mozilla/5.0'}
    params = {'after': after} if after else {}

    # Make the request to the Reddit API
    response = requests.get(url, headers=headers, params=params)

    # Check for valid subreddit response
    if response.status_code != 200:
        return  # If invalid subreddit, just return

    # Parse the JSON response
    data = response.json()
    articles = data.get('data', {}).get('children', [])

    # Iterate through each article and count words
    for article in articles:
        title = article['data']['title']
        title_words = title.lower().split()

        for word in title_words:
            # Check for matches in word count
            for keyword in word_count.keys():
                # Normalize and check the keyword
                if keyword in word:
                    word_count[keyword] += 1

    # Check if there is a next page and continue recursively
    after = data.get('data', {}).get('after')
    if after:
        count_words(subreddit, word_list, after, word_count)

    # After all recursive calls, print the results
    if after is None:  # Only print when we've finished all recursion
        print_sorted_counts(word_count)


def print_sorted_counts(word_count):
    # Filter out words with no matches
    filtered_counts = {word: count for word,
                       count in word_count.items() if count > 0}

    # Sort the results first by count
    sorted_counts = sorted(filtered_counts.items(),
                           key=lambda x: (-x[1], x[0]))

    # Print results
    for word, count in sorted_counts:
        print(f"{word}: {count}")
