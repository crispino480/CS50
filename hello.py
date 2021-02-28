# Written in Python
# A program that prompts a user for their name, and then prints hello, so-and-so, where so-and-so is their provided name,

from cs50 import get_string

answer = get_string("What is your name ?\n")

print(f"hello, {answer}")
