#include <iostream>

#include "sm_state_init.h"

using namespace std;

void sm_state_init::on_entry(std::shared_ptr<sm_event> e)
{
	cout << "on_entry:" << TAG <<  endl;
}

void sm_state_init::on_exit(std::shared_ptr<sm_event> e)
{
	cout << "on_exit:" << TAG <<  endl;
}

void sm_state_init::on_update()
{
	cout << "on_update:" << TAG <<  endl;
}
