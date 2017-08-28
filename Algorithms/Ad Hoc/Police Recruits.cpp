#include <cstdio>

using namespace std;

int main() {
    int N;
    scanf("%d", &N);
    long long work = 0, miss = 0;
    while (N--) {
        int a;
        scanf("%d", &a);
        if (a == -1) {
            if (work > 0) work--;
            else miss++;
        }
        else {
            work += a;
        }
    }
    printf("%d", miss);
}