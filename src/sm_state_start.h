#ifndef __U_SM_STATE_START__
#define __U_SM_STATE_START__

#include "sm_state.h"

class sm_state_start : public sm_state {
public:
	const std::string TAG = "sm_state_start";
	using sm_state::sm_state;
	void on_entry(std::shared_ptr<sm_event> e) override;
	void on_exit(std::shared_ptr<sm_event> e) override;
	void on_update() override;
};

#endif
