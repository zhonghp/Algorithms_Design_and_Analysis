
def mergeSort(arr, tmp, beg, end):
    if end <= beg+1:
        return 0

    mid = beg + (end - beg)/2
    leftCnt = mergeSort(arr, tmp, beg, mid)
    rightCnt = mergeSort(arr, tmp, mid, end)
    totalCnt = leftCnt + rightCnt

    p = beg
    q = mid
    for i in range(end-beg):
        if p >= mid:
            tmp[beg+i] = arr[q]
            q += 1
        elif q >= end:
            tmp[beg+i] = arr[p]
            p += 1
        elif arr[p] < arr[q]: 
            tmp[beg+i] = arr[p]
            p += 1
        else:
            tmp[beg+i] = arr[q]
            q += 1
            totalCnt += mid - p

    arr[beg:end] = tmp[beg:end]
    return totalCnt


arr = [int(line) for line in open('IntegerArray.txt').readlines()]
tmp = arr[:]
print mergeSort(arr, tmp, 0, len(arr))
