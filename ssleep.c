#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(){

	FILE *sys_power_file;

	if( getuid() != 0){
		fprintf(stderr, "run as root\n");
		return(1);
	}

	sys_power_file = fopen("/sys/power/state", "w");
	
	if(sys_power_file == NULL){
		fprintf(stderr, "cannot open file, is suspend support in the kernel?\n");
		return(1);
	}
	
	fprintf(sys_power_file, "mem");

	return(0);

}
