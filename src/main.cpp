#include <stdio.h>

#include "sm.h"
#include "sm_state_init.h"
#include "sm_state_start.h"
#include "sm_events.h"

int main(){
	std::shared_ptr<sm> sm_ = std::make_shared<sm>();
	//add_event<source_state, event, next_state>
	sm_->add_event<sm_state_init, e_1, sm_state_start>();
	sm_->add_event<sm_state_init, e_2, sm_state_init>();
	sm_->add_event<sm_state_start, e_3, sm_state_init>();
	sm_->add_event<sm_state_start, e_4, sm_state_start>();

	sm_->set_initial_state<sm_state_init>();

	//call (super_state:sm_state).on_update()
	sm_->update();

	sm_->process_event(std::make_shared<e_1>());
	sm_->update();
	sm_->process_event(std::make_shared<e_4>());
	sm_->update();
	sm_->process_event(std::make_shared<e_3>());
	sm_->update();
	sm_->process_event(std::make_shared<e_2>());
	sm_->update();
	sm_->process_event(std::make_shared<e_1>());
	sm_->update();

	return 0;
}
