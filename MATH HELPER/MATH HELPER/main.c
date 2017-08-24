#include "Header.h"
int main(void)
{
	srand(time(NULL));
	int challenge = 1;
	int score = 0;
	char name[4] = { '\0' };
	FILE * save = savefile();
	load(save, name, &score, &challenge);
	menu(challenge,score,name,save);
}