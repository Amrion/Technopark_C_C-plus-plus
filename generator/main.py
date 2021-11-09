import random
import string


def generate_random_symbols(length):
    f = open('../symbols.txt', 'w')
    symbols = string.ascii_lowercase
    random_symbols = ''.join(random.choice(symbols) for i in range(length))
    f.write(random_symbols)
    f.close()


generate_random_symbols(100000000)
