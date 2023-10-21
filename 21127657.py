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

def record_running_time(matrix_size):
    with open('Time/python.txt', 'w') as f:
        for size in matrix_size:
            matrixA = read_matrix(f'Matrix Folder/matrix_A_{size}.txt')
            matrixB = read_matrix(f'Matrix Folder/matrix_B_{size}.txt')
            start = time.time()
            result = multiply_matrix(matrixA, matrixB)
            end = time.time()
            running_time = int((end - start)*1000)
            print(f'Time taken to mutiply 2 matrices size {size}x{size}: {running_time} ms')
            f.write(f'{running_time}\n')
    f.close()

def main():
    matrix_size = [10, 100, 250, 500, 750, 1000, 2000]
    record_running_time(matrix_size)

if __name__ == '__main__':
    main()
