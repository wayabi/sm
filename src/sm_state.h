#ifndef __U_SM_STATE__
#define __U_SM_STATE__

#include "sm.h"

class sm;

class sm_event {
public:
	virtual ~sm_event(){}
};

class sm_state : public std::enable_shared_from_this<sm_state> {
public:
	const std::string TAG;
	virtual void on_entry(){};
	virtual void on_exit(){};
	virtual void on_update(){};
	virtual ~sm_state(){}
protected:
	std::shared_ptr<sm> sm_;

};

#endif


