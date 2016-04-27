#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void readConfigFile();
void analyze(char *inputCommand, int size);
char installCommand[50];
char uninstallCommand[50];


void analyze(char *inputCommand, int size){
	char installCommand[] = "install_command";
	char uninstallCommand[] = "remove_command";
	int equalsPos = 0;

	/*
	//For testing
	for (int i = 0; i < size; i++){
		printf("%c", inputCommand[i]);
	}
	printf("\n");
	*/


	for (int i = 0; i < size; i++){
		if (inputCommand[i] == '='){
			equalsPos = i;
			break;
		}else{
			continue;
		}
	}


	char newString[equalsPos];

	if (equalsPos != 0){
		for (int i = 0; i < equalsPos; i++){
			newString[i] = inputCommand[i];
			//printf("%c", inputCommand[i]);
		}
		newString[equalsPos] = '\0';
		
		if (equalsPos == 15){
			if (strcmp(newString, installCommand) == 0){
				printf("Install...\n");
			}
			printf("%s\n", newString);
		}else if(equalsPos == 14){
			if (strcmp(newString, uninstallCommand) == 0){
				printf("Uninstall...\n");
			}
			printf("%s\n", newString);
		}
		printf("%d\n", equalsPos);
	}else{
		printf("Failure");
	}
	/*
	printf("\n");
	*/
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
