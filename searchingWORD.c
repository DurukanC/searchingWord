#include <stdio.h>
#include <string.h>

#define MAX_LINE_SIZE 1000

int main() {
	FILE *fp;
	char line[MAX_LINE_SIZE],*ptr;
	char search_word[MAX_LINE_SIZE];
	int line_number= 0,count= 0;
	printf("Please enter the word to be searched:");
	scanf("%s",search_word);
	fp=fopen("deneme.txt","r");
	if(fp==NULL) {
		printf("An error occured while opening the file.\n");
		return 1;	
	}
	
	while(fgets(line,MAX_LINE_SIZE,fp)!=NULL) {
		line_number++;
		ptr=line;
		while((ptr=strstr(ptr,search_word))!=NULL) {
			count ++;
			ptr+=strlen(search_word);
		}
	}
	
	printf("The word %s occurs %d times in the file.\n",search_word,count);
	fclose(fp);
	
	return 0;
	
}
