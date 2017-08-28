#include <cstdio>
#include <iostream>
#include <string>
#include <bitset>

using namespace std;

#define D(_x) cout << #_x":" << _x << endl;

int num_char[128];

long long pow(int b, int e) {
    long long x = 1;
    for (int i = 0; i < e; i++) {
        x *= b;
    }
    return x;
}

void print_num(long long n) {
    if (n < 0) {
        printf("-");
        n *= -1;
    }
    int arr[16], i;
    printf("%d.", (n / pow(10, 16))%10);
    for (i = 0; i < 16; i++) {
        //D(i);
        //D((n / pow(10, i))%10);
        if ((n / pow(10, i))%10 != 0) break;
    }
    if (i==16) i--;
    for (int j = 15; j >= i; j--) {
        printf("%d",( n / pow(10, j))%10);
    }
}

int main() {
    string alphabet = "PQWERTYUIOJ#SZK*?F@D!HNM&LXGABCV";
    for (int i = 0; i < alphabet.size(); i++) {
        num_char[alphabet[i]] = i;
    }
    int N;
    scanf("%d", &N);
    while (N--) {
        int a, d;
        char c, s;
        scanf("%d %c %d %c", &a, &c, &d, &s);
        int c_num = num_char[c];
        bitset<17> bs;
        bs.reset();
        for (int i = 0; i < 5; i++)
            if (c_num & (1 << i)) bs[4-i] = 1;
        for (int i = 0; i < 11; i++)
            if (d & (1 << i)) bs[15-i] = 1;
        if (s == 'D') bs[16] = 1;
        //for (int i = 0; i < 17; i++) if (bs[i]) printf("1"); else printf("0");
        //printf("\n");

        long long num;
        if (!bs[0]) {
            num = 0;
            for (int i = 1; i < 17; i++) {
                if (bs[i]) num += 152587890625 * pow(2, 16 - i);
            }
        }
        else {
            num = -10000000000000000;
            for (int i = 1; i < 17; i++) {
                if (bs[i]) num += 152587890625 * pow(2, 16 - i);
            }
        }
        //printf("%d %lld\n", a, num);
        printf("%d ", a);
        print_num(num);
        printf("\n");
    }
}