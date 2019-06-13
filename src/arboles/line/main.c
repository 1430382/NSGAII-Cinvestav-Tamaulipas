 #include <stdio.h>
int main()
{
	FILE* file = fopen("zilla.grd", "r");
  char line[256];
  int i = 0;
	int VV;
	fprintf(stderr,"LINE:\n");
	scanf("%d",&VV);
  while (fgets(line, sizeof(line), file)) {
     i++;
	   if(i == VV )
     {
       printf("%s", line);   
     }
  }
  fclose(file);
  return 0;
}
