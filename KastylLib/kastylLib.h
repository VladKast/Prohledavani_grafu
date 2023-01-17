#pragma once



namespace kastylLib
{
	template <typename T>

	class ZasobnikNeobektove
	{
	public:

		struct Tstruct {
			int value;
			Tstruct* next;
		};
		// Functions declarations
		/*
		StackInit - initializes stack
		in: Tstruct* *TOP - the address of address of top of stack
		out: void
		*/
		void StackInit(Tstruct** TOP) {
			*TOP = NULL;
		};
		/*
		StackPush - pushes a new value into the stack
		in: Tstruct * TOP - the address of top of stack
		int VALUE - input value
		out: Tstruct * - pointer to the top of stack
		*/
		Tstruct* StackPush(Tstruct* TOP, int VALUE) {
			Tstruct* l_hlp;
			l_hlp = new (std::nothrow) Tstruct; // create new structure
			// if the l_hlp is null, then there is no enough memory –
			// the aplication must be stopped
			if (l_hlp == nullptr) {

				throw std::runtime_error("Out of memory");
				return NULL;
			}
			// new member points to the recent TOP
			l_hlp->next = TOP;
			//store value
			l_hlp->value = VALUE;
			// returns the pointer to new top of stack
			return l_hlp;
		};
		/*
		StackPop - pops topmost value from the stack
		in: Tstruct* *TOP - the address of address of top of stack
		out: int - value stored on the top of stack
		*/
		int StackPop(Tstruct** TOP) {
			if (*TOP == NULL) {
				throw std::runtime_error("Stack is empty");
				return 0;
			}
			// helping variables
			Tstruct* l_hlp;
			int l_val;
			// store pointer to the TOP
			l_hlp = *TOP;
			// TOP points to the following element
			*TOP = l_hlp->next;
			//store value from the TOP
			l_val = l_hlp->value;
			// delete previous TOP
			delete l_hlp;
			// returns the value from previous TOP
			return l_val;
		};
		/*
		StackShow - shows topmost value in the stack without popping it
		in: Tstruct *TOP - the address of top of stack
		out: int - the value stored on the top of stack
		*/
		int StackShow(Tstruct* TOP) {
			if (TOP) {
				return TOP->value;
			}
			else {
				throw std::runtime_error("Stack is empty");
				return 0;
			}
		};
		/*
		StackIsEmpty - returns true/false if the stack is/is not empty
		in: Tstruct *TOP - the address of top of stack
		out: bool - true/false
		*/
		bool StackIsEmpty(Tstruct* TOP) {
			if (TOP) return false; else return true;
		};
	};


}

