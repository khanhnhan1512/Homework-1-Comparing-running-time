import time

def read_matrix(filename):
    matrix = []
    with open(filename) as f:
        rows = f.readlines()
        for row in rows:
            matrix.append([int(x) for x in row.split()])
    return matrix

def multiply_matrix(matrixA, matrixB):
    if len(matrixA[0]) != len(matrixB):
        return None
    return [[sum(i * j for i, j in zip(row, col)) for col in zip(*matrixB)] for row in matrixA]

def main():
    matrix_size = [10, 50, 100, 250, 500, 750, 1000]
    matrixA = read_matrix('Matrix Folder/matrix_A_10.txt')
    matrixB = read_matrix('Matrix Folder/matrix_B_10.txt')
    result = multiply_matrix(matrixA, matrixB)
    print(result)

if __name__ == '__main__':
    main()
