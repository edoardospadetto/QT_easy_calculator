
enum available_op{ADD,MULTIPLY,DIVIDE,SUBTRACT,NONE};

class BinaryExpression
{
	float a = 0;
	float b = 0;
	float* buffer = &(this->a);
	float res = 0;
	available_op op=NONE;
	public :
		int SetBuffer(int idx); // 1 or 2
		void UpdateBuffer(int num);
		int DoOp();
		void SetOp(available_op OP);
		void Print();

	private :
		float Add();
		float Multiply();
		float Subtract();
		float Divide();
};
