# # Use enumerate to generate the sequence of lowercase ASCII letters
lowercase_letters = [chr(letter) for letter in range(ord('a'), ord('z')+1)]
enumerated_letters = list(enumerate(lowercase_letters, start=1))

# Print the enumerated sequence of lowercase letters
for index, letter in enumerated_letters:
    print(f"{index}: {letter} {ord(letter)}")