#include <stdio.h>

#include "sm.h"
#include "sm_state_init.h"
#include "sm_state_start.h"
#include "sm_events.h"

int main(){
	sm sm_;
	sm_.add_event<sm_state_init, e_1, sm_state_start>();
	sm_.set_initial_state<sm_state_init>();
	sm_.update();
	sm_.process_event(std::make_shared<e_1>());
	sm_.update();

	printf("aa\n");
	return 0;
}
