#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define MAX_HISTORY 100

char history[MAX_HISTORY][1024];
int history_count = 0;

void add_history(const char *cmd){
	if(history_count < MAX_HISTORY){
		strncpy(history[history_count++], cmd, 1023);
	}
}

void show_history(){
	for(int i =0; i<history_count; i++){
		printf("%d: %s\n", i+1, history[i]);
	}
}

void execute_command(char *cmd){
	char *args[100];
        char *token = strtok(cmd, " ");
        int i = 0;

        while (token != NULL && i < 99){
        	args[i++] = token;
                token = strtok(NULL, " ");
        }
        args[i] = NULL;

        if(strcmp(args[0], "cd") == 0){
		if(args[1] == NULL){
			fprintf(stderr, "argument missing Bro!! tell me directory name.");
		} else if(chdir(args[1]) != 0){
			perror("Damn cd Failed!!");
		}
		return;
	}

	if(strcmp(args[0], "help") == 0){
		printf("Prash SHELL COMMANDS :)\n");
		printf("	cd <dir>-change directory\n");
		printf("	history	-show command history\n");
		printf("	clear	-clear screen\n");
		printf("	help	-show this help message\n");
		printf("	exit	-exitthe shell\n");
		printf("You can also run external commands like ls, cat, echo, etc.\n");
		return;
	}

	if(strcmp(args[0], "clear") == 0){
		system("clear");
		return;
	}

	if(strcmp(args[0], "history") == 0){
		show_history();
		return;
	}

	if(strcmp(args[0], "exit") == 0){
		exit(0);
	}
	
	pid_t pid = fork();
        if(pid == 0){
             execvp(args[0], args);
             perror("Execution failed");
             exit(1);
        } else{
          	waitpid(pid, NULL, 0);
        }
}

int main(){
	char cmd[1024];
	
	while (1){
		printf("Prash:) ");
		fflush(stdout);

		if(!fgets(cmd, sizeof(cmd), stdin))
			break;

		cmd[strcspn(cmd, "\n")] = '\0';

		if(strcmp(cmd, "exit") == 0)
			break;

		if(strlen(cmd) == 0)
			continue;

		add_history(cmd);
		execute_command(cmd);
	}
	return 0;
}
