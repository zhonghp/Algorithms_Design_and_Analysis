#include<iostream>
#include<cstdio>
using namespace std;

const int maxn = 100010;
int n;
int arr[maxn];
int tmp[maxn];

long long mergeSort(int beg, int end) {
    if(end <= beg+1) {
        return 0;
    }

    int mid = beg + (end - beg)/2;
    long long leftCnt = mergeSort(beg, mid);
    long long rightCnt = mergeSort(mid, end);
    long long totalCnt = leftCnt + rightCnt;
    int p = beg, q = mid, i = beg;
    while(p < mid || q < end) {
        if(p >= mid) {
            while(q < end) {
                tmp[i++] = arr[q++];
            }
        }
        else if(q >= end) {
            while(p < mid) {
                tmp[i++] = arr[p++];
            }
        }
        else {
            if(arr[p] < arr[q]) {
                tmp[i++] = arr[p++];
            }
            else {
                tmp[i++] = arr[q++];
                totalCnt += mid - p;
            }
        }
    }

    for(i = beg; i < end; i++) {
        arr[i] = tmp[i];
    }

    return totalCnt;
}

int main()
{
    freopen("IntegerArray.txt", "r", stdin);

    int num;
    n = 0;
    while(scanf("%d", &num) == 1) {
        arr[n++] = num;
    }

    printf("%lld\n", mergeSort(0, n));
    return 0;
}
