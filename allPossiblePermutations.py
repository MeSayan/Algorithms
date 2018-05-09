
def allPossiblePermutations(A):
    ''' This function prints all possible permutations
    of a list of size N. The complexity is 2**Nlog(N)
    '''
    N = len(A)

    for i in range(0, 2**N):
        for j in range(0, N):
            # if the jth bit is set in i, print A[j]
            if (i & (1 << j)):
                print(A[j], end=" ")
        #Print a new line at the end of each permutation
        print()
    

if __name__=="__main__":
    allPossiblePermutations([1,2,12,1,21,21])


