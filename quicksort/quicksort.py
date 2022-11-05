def partition(A, start, end):
    x = A[end]
    i = start - 1
    for j in range(start, end):
        if A[j] <= x:
            i = i + 1
            A[i], A[j] = A[j], A[i]
    A[i + 1], A[end] = A[end], A[i + 1]
    return i + 1

def Quicksort(A, start, end):
    if start < end:
        q = partition(A, start, end)
        Quicksort(A, start, q - 1)
        Quicksort(A, q + 1, end)

if __name__ == "__main__":
    A = [5,4,1,6,7,3]
    print(f"Array before sorting is: ")
    print(A)
    print(f"Array after sorting is:")
    Quicksort(A, 0, len(A) - 1)
    print(A)

