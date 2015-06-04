class Solution {
public:
  double findMedianSortedArrays(int A[], int m, int B[], int n) {
    if (m > n) return findMedianSortedArrays(B, n, A, m);
    int minidx = 0, maxidx = m, i, j, num1, mid = (m + n + 1) >> 1,num2;
    while (minidx <= maxidx)
    {
      i = (minidx + maxidx) >> 1;
      j = mid - i;
      if (i<m && j>0 && B[j-1] > A[i]) minidx = i + 1;
      else if (i>0 && j<n && B[j] < A[i-1]) maxidx = i - 1;
      else
      {
        if (i == 0) num1 = B[j-1];
        else if (j == 0) num1 = A[i - 1];
        else num1 = max(A[i-1],B[j-1]);
        break;
      }
    }
    if (((m + n) & 1)) return num1;
    if (i == m) num2 = B[j];
    else if (j == n) num2 = A[i];
    else num2 = min(A[i],B[j]);
    return (num1 + num2) / 2.;
  }
};
