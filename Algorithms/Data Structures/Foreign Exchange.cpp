#include <cstdio>
#include <set>

using namespace std;

typedef pair<int, int> ii;


int main() {
    int N;
    while (scanf("%d", &N) and N) {
        multiset<ii> s;
        while (N--) {
            int a, b;
            scanf("%d %d", &a, &b);
            ii p = ii(a, b);
            ii inverse = ii(b, a);
            if (s.count(inverse)) {
                s.erase(s.find(inverse));
            }
            else {
                s.insert(p);
            }
        }
        if ((int) s.size() > 0) printf("NO\n");
        else printf("YES\n");
    }
}