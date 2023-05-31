# Define the function to check if a triple is a Pythagorean triple
def is_pythagorean_triple(triple):
    a, b, c = triple
    return a**2 + b**2 == c**2

# Generate all possible combinations of numbers smaller than 10
numbers = range(1, 10)

# Use filter and comprehension to find the Pythagorean triples
pythagorean_triples = [
    (a, b, c)
    for a in numbers
     for b in numbers
     for c in numbers
    if is_pythagorean_triple((a, b, c))
]

# Print the Pythagorean triples
for triple in pythagorean_triples:
    print(triple)