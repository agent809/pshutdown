#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#define CONFIG_ERROR "An error occurred while loading the config file...\n"

int readConfigFile();
int analyze(char *inputCommand, int size);
char installCommand[50];
char uninstallCommand[50];
char install[50];
char uninstall[50];


int analyze(char *inputCommand, int size){
	char installCommand[] = "install_command";
	char uninstallCommand[] = "remove_command";
	int equalsPos = 0;

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
				//printf("Install...\n");
				int cnt = 0;
				for (int i = equalsPos + 1; i < size; i++){
					install[cnt] = inputCommand[i];
					cnt++;
				}
				install[cnt + 1] = '\0';
				return 1;
			}else{
				return 0;
			}
			//printf("%s\n", newString);
		}else if(equalsPos == 14){
			if (strcmp(newString, uninstallCommand) == 0){
				//printf("Uninstall...\n");
				int cnt = 0;
				for (int i = equalsPos + 1; i < size; i++){
					uninstall[cnt] = inputCommand[i];
					cnt++;
				}
				uninstall[cnt + 1] = '\0';
				return 1;
			}else{
				return 0;
			}
			printf("%s\n", newString);
		}
		printf("%d\n", equalsPos);
	}else{
		return 0;
	}
}


int readConfigFile(){
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
			if (analyze(file, counter) == 0){
				printf("%s", CONFIG_ERROR);
				return 0;
			}
			counter = 0;
			continue;
		}

		if (copy){
			file[counter] = ch;
			counter += 1;
		}
	}
	
	fclose(fp);
	printf("Config file loaded...\nInstall Command: %s\nUninstall Command: %s\n", install,  uninstall);
}

int main(){
	if (readConfigFile() == 0){
		return 0;
	}
}
