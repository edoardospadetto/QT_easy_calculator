#include "calc.h"

#include <iostream>

BinaryExpression::BinaryExpression(){this->SetBuffer(1);}

void BinaryExpression::UpdateBuffer(int num)
{
	if(this->fullExpr) 
	{	
		this->fullExpr=false; 
		this->expr_rep="";
		this->a=0;
		this->b=0;
	}

	float* bf = this->buffer;
	*bf = (*bf)*10+num;
	this->expr_rep = this->expr_rep + std::to_string(num) ;
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
	this->expr_rep = this->expr_rep + '=';
	this->fullExpr = true;
	this->SetBuffer(1);

	switch (this->op)
	{
		case ADD:
			this->res = this->Add();
			this->expr_rep = this->expr_rep + std::to_string(this->res);
			return 0;
			break;
		case MULTIPLY:
			this->res = this->Multiply();
			this->expr_rep = this->expr_rep + std::to_string(this->res);
			return 0;
			break;
		case SUBTRACT:
			this->res = this->Subtract();
			this->expr_rep = this->expr_rep + std::to_string(this->res);
			return 0;
			break;
		case DIVIDE:
			this->res = this->Subtract();
			this->expr_rep = this->expr_rep + std::to_string(this->res);
			return 0;
			break;

		return 1;
	}
}

void BinaryExpression::SetOp(available_op OP)
{
	this->op = OP;
	switch (this->op)
	{
		case ADD:
			this->expr_rep = this->expr_rep + '+';
			break;
		case MULTIPLY:
			this->expr_rep = this->expr_rep + 'x';
			break;
		case SUBTRACT:
			this->expr_rep = this->expr_rep + '-';
			break;
		case DIVIDE:
			this->expr_rep = this->expr_rep + '/';
			break;
	}
}

std::string* BinaryExpression::GetExpr() {return &(this->expr_rep);} 