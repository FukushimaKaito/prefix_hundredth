/*-----------------
小数点 2桁を含めた出力に改修
------------------*/
#include <stdio.h>
#include <stdlib.h>
int decimalprefix(char *dst, int dlen, char *srcstr)
{
    int srcnum;
    float tmpnum;
    srcnum = atoi(srcstr); //char->int
    if (srcnum >= 1000 * 1000)
    {
        tmpnum = srcnum / (1000.0 * 1000.0);
        sprintf(dst, "%.2fM", tmpnum);
    }
    else if (srcnum >= 1000)
    {
        tmpnum = srcnum / 1000.0;
        sprintf(dst, "%.2fK", tmpnum);
    }
    else
    {
        sprintf(dst, "%d", srcnum);
    }
    return 0;
}
int main()
{
    int ik;
    char ibuf[BUFSIZ];
    char obuf[BUFSIZ];
    while (fgets(ibuf, BUFSIZ, stdin))
    {
        ik = decimalprefix(obuf, BUFSIZ, ibuf);
        fprintf(stdout, "%*s <- %s", 8, obuf, ibuf);
    }
}
