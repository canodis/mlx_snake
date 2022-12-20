#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

int	randomRange(int min, int max)
{
	struct timeval t;
	gettimeofday(&t, 0);
	srand(t.tv_sec + t.tv_usec);
	return (rand() % (max - min + 1) + min);
}
