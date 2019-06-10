from nltk import sent_tokenize


def lines(a, b):

    # Create list of the lines in A and list of the lines in B
    listA = a.splitlines()
    listB = b.splitlines()
    lines = list()

    # Iterate over each line in listA
    for line in listA:

        # Check if the line in listA appears in listB
        if line in listB:

            # Check if the line is not already in the lines output list
            if line not in lines:

                # If the above checks are ok, then append the line to the lines output list
                lines.append(line)

    return lines


def sentences(a, b):

    # Create sets for the sentences in A and B
    listA = sent_tokenize(a)
    listB = sent_tokenize(b)
    sentences = list()

    # Iterate over each sentence in listA
    for sentence in listA:

        # Check if the sentence in listA appears as well in listB
        if sentence in listB:

            # Check if the matching sentence is not already in the sentences output list
            if sentence not in sentences:

                # Then append it to the sentences list
                sentences.append(sentence)

    return sentences


def substrings(a, b, n):

    # Create list A and list B based on the provided n input for characters length
    listA = [a[i:i+n] for i in range(0, len(a), n)]
    listB = [b[i:i+n] for i in range(0, len(b), n)]
    substrings = list()

    # Iterate over each substring in listA
    for substring in listA:

        # Check if the string appears as well in listB
        if substring in listB:

            # Check if the match has not already been included in the substrings output list
            if substring not in substrings:

                # In case above conditions are met, append the substring to the output list
                substrings.append(substring)

    return substrings
