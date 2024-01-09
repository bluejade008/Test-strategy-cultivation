#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {

    time_t now;
    struct tm *ts;
    char curtimestring[20], *ver;
    ver=(char *)malloc(sizeof(char)*40);
    if(!ver) 
		printf("memory allocation failure.\n");
    ver=strcpy(ver,"BOS6116-");
    printf("original ver val=%s\n",ver);
    printf("now time second=%ld\n", time(&now));
    ts = localtime( &now );
    strftime(curtimestring, 20, "%Y%m%d", ts);
    strncat(ver,curtimestring,20);
    printf("add time stamp later,  val=%s\n",ver);
    printf("%s\n",ver);

    FILE *fd;
    fd=fopen("/etc/bbuver","w+");
    fwrite(ver,16,1,fd);
    fwrite("\n",1,1,fd);
    fclose(fd);

	return 0;

}

