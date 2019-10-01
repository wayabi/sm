#include <stdio.h>

#include "sm_state_init.h"

void sm_state_init::on_entry()
{
	printf("on_entry:%s", TAG);
}

void sm_state_init::on_exit()
{
	printf("on_exit:%s", TAG);
}

void sm_state_init::on_update()
{
	printf("on_update:%s", TAG);
}
