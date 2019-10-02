#ifndef __U_SM__
#define __U_SM__

#include <vector>
#include <memory>
#include <functional>

#include "sm_state.h"
class sm_state;
class sm_event;

class sm {
public:
	template<typename S1, typename E, typename S2>
	bool add_event(){
		std::shared_ptr<S1> s1 = get<S1>();
		std::shared_ptr<S2> s2 = get<S2>();
		if(s1 == nullptr || s2 == nullptr) return false;

		auto f = [=](std::shared_ptr<sm_state> s0, std::shared_ptr<sm_event> se){
			if(!dynamic_cast<E*>(se.get())){
				return std::shared_ptr<S2>();
			}
			if(s0.get() == s1.get()){
				return s2;
			}
			return std::shared_ptr<S2>();
		};
		f_transition_.push_back(f);
		return true;
	}

	void process_event(std::shared_ptr<sm_event> e);

	template<typename S>
	std::shared_ptr<S> get(){
		for(auto ite = states_.begin();ite != states_.end();++ite){
			if(dynamic_cast<S*>(ite->get())){
				return std::dynamic_pointer_cast<S>(*ite);
			}
		}
		auto p = std::make_shared<S>();
		if(dynamic_cast<sm_state*>(p.get())){
			states_.push_back(p);
			return p;
		}else{
			return nullptr;
		}
	}

	template<typename S>
	void set_initial_state()
	{
		auto p = get<S>();
		state_current_ = p;
		p->on_entry();
	}
	
	void update();
	
private:
	std::vector<std::shared_ptr<sm_state>> states_;
	std::shared_ptr<sm_state> state_current_;
	std::vector<std::function<std::shared_ptr<sm_state>(std::shared_ptr<sm_state>, std::shared_ptr<sm_event>)>> f_transition_;
};
#endif
