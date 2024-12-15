/*
    problem link --> https://www.interviewbit.com/problems/black-shapes/
*/

void func(vector<string>& A, int i, int j, int& m, int& n) {
    if(i == m or i < 0 or j == n or j < 0 or A[i][j] == 'O') return;
    A[i][j] = 'O';
    func(A, i + 1, j, m, n);
    func(A, i - 1, j, m, n);
    func(A, i, j + 1, m, n);
    func(A, i, j - 1, m, n);
}

int Solution::black(vector<string> &A) {
    int m = A.size(), n = A[0].size(), res = 0;
    for(int i=0;i<m;i++) {
        for(int j=0;j<n;j++) {
            if(A[i][j] == 'X') {
                res++;
            }
            func(A, i, j, m, n);
        }
    }
    return res;
}

