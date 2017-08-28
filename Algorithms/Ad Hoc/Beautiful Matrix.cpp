#include <cstdio>

using namespace std;

int abs(int a){
    if (a >= 0) return a;
    return -a;
}

int main() {
    int r, c;
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            int a;
            scanf("%d", &a);
            if (a == 1) c = j, r = i;
        }
    }
    printf("%d", abs(c-2) + abs(r-2));
}