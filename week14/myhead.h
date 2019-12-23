#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/param.h>
#include <string.h>
#include <errno.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/syscall.h>
#include <wait.h>
#include <signal.h>
#include <sys/time.h>
#include <time.h>
#include <pthread.h>
#include <limits.h>
#include <assert.h>
#define err_exit(MESSAGE)(
		perror(MESSAGE),
		exit(1)
		)


#define check_error(return_val,mag){			
	if(return_val != 0){				
		fprintf(stderr, "%s : %s\n",msg,strerror(return_val));
		exit(-1);
	}
}


