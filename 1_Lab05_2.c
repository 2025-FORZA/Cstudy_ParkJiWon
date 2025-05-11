#include <stdio.h>
#include <stdlib.h>

typedef struct { int x, y; } Point;

int cmp_x(const void* a, const void* b) { return ((Point*)a)->x - ((Point*)b)->x; }
int cmp_y(const void* a, const void* b) { return ((Point*)a)->y - ((Point*)b)->y; }

long long dist(Point a, Point b) {
    long long dx = a.x - b.x, dy = a.y - b.y;
    return dx * dx + dy * dy;
}

long long min(long long a, long long b) { return a < b ? a : b; }

long long closest(Point* p, int l, int r) {
    if (r - l <= 3) {
        long long m = 1e18;
        for (int i = l; i < r; i++)
            for (int j = i + 1; j < r; j++)
                m = min(m, dist(p[i], p[j]));
        return m;
    }

    int m = (l + r) / 2;
    long long d = min(closest(p, l, m), closest(p, m, r));

    Point tmp[r - l];
    int cnt = 0;
    for (int i = l; i < r; i++)
        if ((long long)(p[i].x - p[m].x) * (p[i].x - p[m].x) < d)
            tmp[cnt++] = p[i];

    qsort(tmp, cnt, sizeof(Point), cmp_y);

    for (int i = 0; i < cnt; i++)
        for (int j = i + 1; j < cnt && (long long)(tmp[j].y - tmp[i].y) * (tmp[j].y - tmp[i].y) < d; j++)
            d = min(d, dist(tmp[i], tmp[j]));

    return d;
}

int main() {
    int n;
    scanf("%d", &n);

    Point* p = malloc(sizeof(Point) * n);
    for (int i = 0; i < n; i++)
        scanf("%d %d", &p[i].x, &p[i].y);

    qsort(p, n, sizeof(Point), cmp_x);
    printf("%lld\n", closest(p, 0, n));

    free(p);
    return 0;
}
