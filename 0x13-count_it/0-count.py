#!/usr/bin/python3
"""Queries the Reddit API
prints sorted count of given keywords, delimited by spaces
from titles of all hot articles for given subreddit.
if not valid subreddit do nothing.
"""
import requests


def count_words(subreddit, word_list, after=None, words={}):
    """Prints sorted count of given keywords."""

    if len(words) == 0:
        for word in word_list:
            words[word] = 0
    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    user_agent = {"User-Agent": "Hello There 1.0"}
    response = requests.get(url, headers=user_agent, allow_redirects=False,
                            params={"after": after})
    if response.status_code != 200:
        return None
    children = response.json()["data"]["children"]
    for child in children:
        for key, value in words.items():
            key = key.lower()
            titles = child["data"]["title"]
            word_count = titles.lower().split().count(key)
            if key in titles.lower():
                words[key] += word_count
    after = response.json()["data"]["after"]
    if after is None:
        for key, value in sorted(words.items(), key=lambda word: word[1],
                                 reverse=True):
            if value > 0:
                print("{}: {}".format(key, value))
        return
    return count_words(subreddit, word_list, after, words)
