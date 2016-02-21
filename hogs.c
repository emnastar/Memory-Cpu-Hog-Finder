#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#define SIZE 127

int main( int argc, char *argv[]) {
	/* print error message and return */
	if (argc < 2) {
		printf("not enough arguments");
		return 1;
	}
	/* skip first line */
	char temp[SIZE] = {0};
	scanf("%126[^\n]", temp);

	/* variables to store data in each column */
	char user[SIZE] = {0};
	int pid = 0;
	double cpu = 0;
	double mem = 0;
	int vsz = 0;
	int rss = 0;
	char tty[SIZE] = {0};
	char stat[SIZE] = {0};
	char start[SIZE] = {0};
	int time_hour = 0;
	int time_minute = 0;
	char command[SIZE] = {0};
	
	/* result variables with greatest cpu or memory */
	int result_pid = -1;
	double result_cm = 0;
	char result_command[SIZE];
	
	/* option = 0 if no optional argument,
		option = 1 if optional argument is -m
		option = 2 if optional argument is -c
	*/
	int option = 0;

	if ( (strcmp("-m", argv[1]) == 0) && argc > 2) {
		option = 1;
	}
	if ( (strcmp("-c", argv[1]) == 0) && argc > 2) {

		option = 2;
	}
	/* iterate through the entire stdin and set variables accordingly */
	while(EOF != scanf("%s", user)){
		scanf("%d", &pid);
		scanf("%lf", &cpu);
		scanf("%lf", &mem);
		scanf("%d", &vsz);
		scanf("%d", &rss);
		scanf("%s", tty);
		scanf("%s", stat);
		scanf("%s", start);
		scanf("%d:%d", &time_hour, &time_minute);
		scanf("%126[^\n]", command);
		/* if result hasn't been set to anything but the username matches then
		 * set that result with its corresponding values in the current row*/
		if ( 0 == strcmp(user, argv[argc - 1])) {
			/* option 1 */
			if ((option == 1) && (mem >= result_cm)){
				if (mem > result_cm) {
					result_cm = mem;
					strncpy(result_command, command, sizeof(result_command));
					result_command[SIZE - 1] = '\0';
					result_pid = pid;
				}
			
				else if ( (result_pid == -1) || (strcasecmp(result_command, command) < 0)) {
					result_cm = mem;
					strncpy(result_command, command, sizeof(result_command));
					result_command[SIZE - 1] = '\0';
					result_pid = pid;
				}
			}
			/*option 2 and 0 */	
			else if (cpu >= result_cm) {
				if (cpu > result_cm) {
					result_cm = cpu;
					strncpy(result_command, command, sizeof(result_command));
					result_command[SIZE - 1] = '\0';
					result_pid = pid;
				}
				else if ((result_pid == -1) || (strcasecmp(result_command, command) < 0)) {
					result_cm = cpu;
					strncpy(result_command, command, sizeof(result_command));
					result_command[SIZE - 1] = '\0';
					result_pid = pid;
				}
						
			}
		}
	}
	/* print iff there is a result */	
	if (result_pid != -1){
		printf("%d\t%.1lf\t%s\n", result_pid, result_cm, result_command);
	}
	return 0;
}
