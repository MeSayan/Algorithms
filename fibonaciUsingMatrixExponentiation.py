def matrixMultiply(A, B):
    m = len(A)
    n = len(A[0])
    p = len(B[0])
    
    C = [ [0 for i in range(p)] for j in range(m) ]
    
    for i in range(m):
        for j in range(p):
            sum = 0
            for k in range(n):
                sum += A[i][k] * B[k][j]
            C[i][j] = sum
    
    return C


def matrixExp(A, n):
    ''' Using technique similar to binary exponentiation above,
    we obtain the matrix A raised to power n.
    If n is even, calculate A^2 and return it raised to power n/2
    If n is odd, the calculate A^n-1 and then return A*A^n-1.
    Time Complexity: O(logN)
    '''
    
    if  n == 1:
        return A
    
    if n % 2 == 0:
        A = matrixMultiply(A, A)
        return matrixExp(A, n/2)
    else:
        return matrixMultiply(A, matrixExp(A, n-1))
        

def fib(N):
    ''' Using matrix exponentiation, obtain the nth fibonaci
    number in O(logN) complexity
    f(n) = f(n-1) + f(n-2)
    | f(n)   | =  | 1 1 | | 1 |
    | f(n-1) | =  | 1 0 | | 0 |
    F = A ^ (n-1) * B
    '''
    
    # Trivial Cases
    
    if N == 0:
        return 0
    
    if N == 1:
        return 1
    
    
    A = [ [ 1, 1], [ 1, 0] ]
    
    # Compute A^n-1
    A = matrixExp(A, N-1)
    
    # Declare B
    B = [ [1], [0]]
    
    # Multiply A with B 
    F = matrixMultiply(A, B)
    
    # The first element in F is f(n)
    return F[0]


if __name__=="__main__":
    print(fib(100))
