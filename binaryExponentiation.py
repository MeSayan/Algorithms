
def binaryExponentiation(x, n):
    ''' An efficient manner of computing x^n in O(log(n))
    time instead of O(n).
    To compute x^n do, if n is even do (x^2)^n/2
    if n is odd do, x*x^n-1, and apply method for even, powers
    given above.
    '''
    res = 1
    while( n != 0):
        if n % 2 == 0:
           x = x*x
           n = n/2
        else:
            res = res*x
            n = n-1

    return res


if __name__=="__main__":
    print(binaryExponentiation(2,1000))

