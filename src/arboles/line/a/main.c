#include <stdio.h>

int main(void)
{
    char linebuf[1024];
    FILE *input = fopen("zilla.grd", "r");
		FILE *output = fopen("test.txt","w");
    int lineno = 0, VV;
		fprintf(stderr,"LINE:\n");
		scanf("%d",&VV);
    char *line;
    while (line = fgets(linebuf, 1024, input))
    {
        ++lineno;
        if (lineno == VV)
        {
            fputs("line ", stdout);
						printf("%s", line);
            fputs( line, output );
            break;
        }
    }
    fclose(input);
    return 0;
}
