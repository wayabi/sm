#include "sm.h"

void sm::process_event(std::shared_ptr<sm_event> e)
{
	for(auto ite = f_transition_.begin();ite != f_transition_.end();++ite){
		auto next = (*ite)(state_current_, e);
		if(next.get() != nullptr){
			if(state_current_->event_acceptable(e)){
				state_current_->on_exit(e);
				state_current_ = next;
				state_current_->on_entry(e);
			}
		}
	}
}

void sm::update()
{
	state_current_->on_update();
}

