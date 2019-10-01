#include <stdio.h>

#include "sm.h"
#include "sm_state_init.h"
#include "sm_state_start.h"

int main(){
	sm sm_;
	sm_.set_initial_state<sm_state_init>();
	sm_.update();

	printf("aa\n");
	return 0;
}
