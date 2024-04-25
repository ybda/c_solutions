#ifndef CEXERCISES_BINARY_SEARCH_H
#define CEXERCISES_BINARY_SEARCH_H


int mid, val;
int binarySearch(int *arr, int l, int r, int num) {
    if (l <= r) {
        mid = (l + r) / 2;
        val = arr[mid];
        if (val > num) return binarySearch(arr, l, mid - 1, num);
        if (val < num) return binarySearch(arr, mid + 1, r, num);
        return mid;
    }

    return -1;
}


#endif //CEXERCISES_BINARY_SEARCH_H