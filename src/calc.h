#include<string>

enum available_op{ADD,MULTIPLY,DIVIDE,SUBTRACT,NONE};

class BinaryExpression
{
	float a = 0;
	float b = 0;
	float* buffer = NULL;
	float res = 0;
	bool fullExpr = false;
	available_op op=NONE;
	std::string expr_rep;
	public :
		BinaryExpression();
		int SetBuffer(int idx); // 1 or 2
		void UpdateBuffer(int num);
		int DoOp();
		void SetOp(available_op OP);
		std::string* GetExpr();

	private :
		float Add();
		float Multiply();
		float Subtract();
		float Divide();
};
