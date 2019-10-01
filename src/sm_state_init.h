#ifndef __U_SM_STATE_INIT__
#define __U_SM_STATE_INIT__

#include "sm_state.h"

class sm_state_init : public sm_state {
public:
	const std::string TAG = "sm_state_init";
	void on_entry() override;
	void on_exit() override;
	void on_update() override;
};

#endif
