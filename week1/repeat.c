#include <stdio.h>

int main() {
	char buffer[128]; //128 is the max byte that can be held
	fgets(buffer, sizeof(buffer), stdin);
	printf("%s\n", buffer);
	return 0;
}

