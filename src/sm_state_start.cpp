#include <iostream>

#include "sm_state_start.h"

using namespace std;

void sm_state_start::on_entry(std::shared_ptr<sm_event> e)
{
	cout << "on_entry:" << TAG << endl;
}

void sm_state_start::on_exit(std::shared_ptr<sm_event> e)
{
	cout << "on_exit:" << TAG << endl;
}

void sm_state_start::on_update()
{
	cout << "on_update:" << TAG << endl;
}
