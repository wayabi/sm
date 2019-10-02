#ifndef __U_SM_STATE_INIT__
#define __U_SM_STATE_INIT__

#include "sm_state.h"

class sm_state_init : public sm_state {
public:
	const std::string TAG = "sm_state_init";
	using sm_state::sm_state;
	void on_entry(std::shared_ptr<sm_event> e) override;
	void on_exit(std::shared_ptr<sm_event> e) override;
	void on_update() override;
};

#endif
