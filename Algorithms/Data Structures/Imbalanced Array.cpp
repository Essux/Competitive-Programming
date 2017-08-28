#include <cstdio>
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    int nums[N];
    for (int i = 0; i < N; i++) scanf("%d", nums + i);
    vector<int> left(N, -1);
    stack<int> st;
    for (int i = 0; i < N; i++) {
        while (!st.empty() and nums[st.top()] > nums[i]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }
    vector<int> right(N, -1);
    st = stack<int>();
    for (int i = N-1; i >= 0; i--) {
        while (!st.empty() and nums[st.top()] >= nums[i]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }
    /*printf("Min Right\n");
    for (int i = 0; i < N; i++) printf("%d ", right[i]);
    printf("Min Left\n");
    for (int i = 0; i < N; i++) printf("%d ", left[i]);
    printf("\n");*/
    long long sumMin = 0;
    for (int i = 0; i < N; i++) {
        int l = left[i];
        int r = right[i];
        if (l == -1) l = 0;
        else l++;
        if (r == -1) r = N-1;
        else r--;
        sumMin += (long long) (r - i + 1) * (long long) (i - l + 1) * (long long) nums[i];
    }

    left = vector<int>(N, -1);
    st = stack<int>();
    for (int i = 0; i < N; i++) {
        while (!st.empty() and nums[st.top()] < nums[i]) st.pop();
        if (!st.empty()) left[i] = st.top();
        st.push(i);
    }
    right = vector<int>(N, -1);
    st = stack<int>();
    for (int i = N-1; i >= 0; i--) {
        while (!st.empty() and nums[st.top()] <= nums[i]) st.pop();
        if (!st.empty()) right[i] = st.top();
        st.push(i);
    }
    /*printf("Max Right\n");
    for (int i = 0; i < N; i++) printf("%d ", right[i]);
    printf("Max Left\n");
    for (int i = 0; i < N; i++) printf("%d ", left[i]);
    printf("\n");*/
    long long sumMax = 0;
    for (int i = 0; i < N; i++) {
        int l = left[i];
        int r = right[i];
        if (l == -1) l = 0;
        else l++;
        if (r == -1) r = N-1;
        else r--;
        sumMax += (long long) (r - i + 1) * (long long) (i - l + 1) * (long long) nums[i];
    }
    cout << (sumMax - sumMin);
}