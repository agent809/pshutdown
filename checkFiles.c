#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void readConfigFile();
void analyze(char *inputCommand, int size);
char installCommand[50];
char uninstallCommand[50];


void analyze(char *inputCommand, int size){
	for (int i = 0; i < size; i++){
		printf("%c", inputCommand[i]);
	}
	printf("\n");
}


void readConfigFile(){
	FILE * fp = fopen("pshutdown.cfg", "r");
	//Gets the size of the file
	fseek(fp, 0, SEEK_END);
	int size = ftell(fp);
	rewind(fp);

	char ch;
	bool copy = true;
	char file[size];
	int counter = 0;
	for (int i = 0; i < size; i++){
		ch = fgetc(fp);
		if (ch == '{'){
			copy = false;
			continue;
		}else if(ch == '}'){
			copy = true;
			continue;
		}else if (ch == '\n'){
			continue;
		}else if(ch == ';'){
			analyze(file, counter);
			counter = 0;
			continue;
		}

		if (copy){
			file[counter] = ch;
			counter += 1;
		}
	}
	
	fclose(fp);
}

void main(){
	/*
	char * p;
	p = getInCommand();
	for (int i = 0; i <= 1000; i++){
		printf("%c", *(p + i));
	}
	*/
	readConfigFile();
}
