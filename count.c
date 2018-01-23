//Baljit Kaur
#include "count.h"

int main(int argc, char *argv[]) {
	if (argc != 2){
		printf("error\n");
		return;
	}
	FILE *file = fopen(argv[1], "r");
	if (file == 0){
		printf("error\n");
		return;
	}
	else{
		int i;
        	char address[17];
       		while(fscanf(file,"%s \n", &address) == 1){
        		if(isValid(address) == 0){
        			continue;
			}
        		unsigned long long dec = hextodec(address);
			int key = dec % SIZE;
			if(table[key] == NULL){
				table[key] = (Entry_t *)malloc(sizeof(Entry_t));
				table[key]->key = key;
				strcpy(table[key]->address, address);
				table[key]->next = NULL;
			}else{
				Entry_t *ptr = table[key];
				while(ptr->next != NULL){
					ptr = ptr->next;
				}
				ptr->next = (Entry_t *)malloc(sizeof(Entry_t));
				ptr->next->key = key;
				strcpy(ptr->next->address, address);
				ptr->next->next = NULL;
			}
		}
		int count = 0;
		for(i = 0; i < SIZE; i++){
			if(table[i] != NULL){
				count++;
			}
		}
		printf("%d\n", count);
		for(i = 0; i < SIZE; i++){
			if(table[i] != NULL){
				Entry_t *ptr = table[i];
				Entry_t *prev = table[i];
				while(ptr != NULL){
					prev = ptr;
					ptr = ptr->next;
					free(prev);
				}
			}
		}
	}
	fclose(file);
	return 0;
}

unsigned long long hextodec(char *str){
	unsigned long long dec = 0;
	int i, length, val;
	length = strlen(str) - 1;
    for(i = 0; str[i] != '\0'; i++)
    {
        switch(str[i])
        {
            case '0':
                val = 0;
                break;
            case '1':
                val = 1;
                break;
            case '2':
                val = 2;
                break;
            case '3':
                val = 3;
                break;
            case '4':
                val = 4;
                break;
            case '5':
                val = 5;
                break;
            case '6':
                val = 6;
                break;
            case '7':
                val = 7;
                break;
            case '8':
                val = 8;
                break;
            case '9':
                val = 9;
                break;
            case 'a':
            case 'A':
                val = 10;
                break;
            case 'b':
            case 'B':
                val = 11;
                break;
            case 'c':
            case 'C':
                val = 12;
                break;
            case 'd':
            case 'D':
                val = 13;
                break;
            case 'e':
            case 'E':
                val = 14;
                break;
            case 'f':
            case 'F':
                val = 15;
                break;
        }
        dec += val * pow(16, length);
        length--;
	}
	return dec;
}

int isValid(char *str){ //returns 1 if valid, 0 if invalid
	int i;
	char *invalid = "ghijklmnopqrstuvwxyz";
	char sub[strlen(str) - 1];
	strncpy(sub, str+2, strlen(str) - 1);
	sub[strlen(sub)] = '\0';
	char *c = sub;
	for(i = 0; i < strlen(str); i++){
        if(!(isalnum(str[i]))){
        	return 0;
		}
	}
	while(*c){
		if (strchr(invalid, *c)){
			return 0;
    	}
       c++;
	}
    if(str[0] != '0' || str[1] != 'x'){
        return 0;
	}
	return 1;
}