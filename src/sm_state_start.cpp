#include <stdio.h>

#include "sm_state_start.h"

void sm_state_start::on_entry()
{
	printf("on_entry:%s", TAG);
}

void sm_state_start::on_exit()
{
	printf("on_exit:%s", TAG);
}

void sm_state_start::on_update()
{
	printf("on_update:%s", TAG);
}
