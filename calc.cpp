#include "calc.h"

#include <iostream>



void BinaryExpression::UpdateBuffer(int num)
{
	float* bf = this->buffer;
	*bf = (*bf)*10+num;
	std::cout << *bf << std::endl;
}

int BinaryExpression::SetBuffer(int idx)
{
	if(idx ==1)
	{
		this->buffer = &(this->a);
		return 0;
	}
	else if( idx ==2)
	{
		this->buffer = &(this->b);
		return 0;

	}
	else return 1;
}	


float BinaryExpression::Add() {return a+b;}
float BinaryExpression::Multiply() {return a*b;}
float BinaryExpression::Subtract() {return a-b;}
float BinaryExpression::Divide() {return a/b;}

int BinaryExpression::DoOp()
{
	switch (this->op)
	{
		case ADD:
			this->res = this->Add();
			return 0;
			break;
		case MULTIPLY:
			this->res = this->Multiply();
			return 0;
			break;
		case SUBTRACT:
			this->res = this->Subtract();
			return 0;
			break;
		case DIVIDE:
			this->res = this->Subtract();
			return 0;
			break;

		return 1;
	}
}

void BinaryExpression::SetOp(available_op OP){this->op = OP;}

void BinaryExpression::Print() {std::cout << a << " " << b << " = " << res << std::endl;}