import random


def randomize_matrix(filename, size):
    with open(filename, 'w') as f:
        for _ in range(size):
            for _ in range(size):
                f.write(f'{random.randint(0, 1000)} ')
            f.write('\n')
    f.close()
    
def main():
    matrix_size = [10, 100, 250, 500, 750, 1000, 2000]
    for size in matrix_size:
        randomize_matrix(f'Matrix Folder/matrix_A_{size}.txt', size)
        randomize_matrix(f'Matrix Folder/matrix_B_{size}.txt', size)
    
if __name__ == '__main__':
    main()
    