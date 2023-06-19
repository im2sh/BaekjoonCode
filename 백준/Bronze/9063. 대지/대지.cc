#include <stdio.h>
 
int main()
{
    int n, x, y;;
    scanf("%d", &n);
    int maxx = -10000, minx = 10000; 
    int maxy = -10000, miny = 10000; 
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &x, &y);
        if (x >= maxx) maxx = x;
        if (x < minx) minx = x;
        if (y >= maxy) maxy = y;
        if (y < miny) miny = y;
    }
    printf("%d", (maxx - minx) * (maxy - miny));
 
    return 0;
}