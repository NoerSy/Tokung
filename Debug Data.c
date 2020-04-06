#include <stdio.h>

int main(int argc, char** argv)
{
	int i=0;
	
	int line;
	
	line = (i == 0) ? 1 : 0;
	printf("%d", line);
	
	int input, input2, input3;
	scanf("%d", &input);
	scanf("%d", &input2);	
	scanf("%d", &input3);	
		FILE *Record = fopen("data/record.bin", "wb");
		fwrite(&input, sizeof(int), 3, Record);
		fwrite(&input2, sizeof(int), 3, Record);
		fwrite(&input3, sizeof(int), 3, Record);
		fclose(Record);
	return 0;
}