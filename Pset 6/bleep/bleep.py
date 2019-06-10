from cs50 import get_string
from sys import argv


def main():

    # Check if usage is correct and the user has entered exactly 2 arguments
    if not len(argv) == 2:
        exit("Usage: python bleep.py dictionary")
        return 1

    # After correct usage is ensured, proceed with getting a message from the user
    text = get_string("What message would you like to censor?\n")

    # Define a set for the words from the dictionary to be stored in
    words_dictionary = list()

    # Load the words in the dictionary into a words list
    dictionary = argv[1]
    file = open(dictionary, 'r')
    for line in file:
        words_dictionary.append(line.rstrip("\n"))

    # Create a list of the words in the provided text
    text_list = str.split(text)

    # For each word in the provided text list check if it exists in dictionary list
    for word in text_list:
        word_low = word.lower()
        if word_low in words_dictionary:
            for j in range(len(word_low)):
                print("*", end="")
        else:
            print(word, end="")
        print(" ", end="")
    print()

if __name__ == "__main__":
    main()
