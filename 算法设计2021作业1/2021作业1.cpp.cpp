#include<iostream>
using namespace std;
class Stack {//定义栈及其成员函数，作为生成并输出要求数字串的工具。
private:
    int top = -1;
	int a[100];//栈的存储数组，用于存储数字串
public:
	bool isempty();
	void Push_back(int);
	void Pop();
	int Top();
	void print(int);
	void printfir(int);
};
	

bool Stack::isempty() {//判断栈是否为空
	if (top == -1)return 1;
	else return 0;
}

void Stack::Push_back(int x) {//将数字压入到栈顶
	top ++;
	a[top] = x;
}

void Stack::Pop() {//将数字从栈顶弹出
	top --;
}

int Stack::Top() {//读取栈顶的数字，不弹出
	return a[top];
}

void Stack::print(int x)//先输出“，”，输出栈内的前x个数字
{
	cout << ",";
	for (int i = 0; i < x; i++)cout << a[i];
}

void Stack::printfir(int x) {//直接输出栈内的前x个数字
	for (int i = 0; i < x; i++)cout << a[i];
}

int main() 
{   
	
	int count;//计数变量，用于计算栈内的数字个数，方便判断是否进行输出
	Stack seq;//构建数字串类
	int n;
	int k;
	bool judge = 1;
	while (judge)
	{
		cout << "请输入数字串的长度n，相邻两个数字的绝对值之差k：";
		cin >> n >> k;
		cout << "结果为：";
		if (n <= 1)cout << "[]";//当n<=1时，无任何可能满足要求的串，所以无需继续判断，直接输出空
		if (n > 1)//当n>1时，作进一步判断
		{
			cout << "[";
			for (int i = 1; i <= 9; i++)//做循环，当第一个数字从1到9时，分别输出满足条件的所有数字串
			{
				if (i - k < 0 && i + k>9)continue;
				seq.Push_back(i);//将当前的循环变量i作为首数字放入栈中。
				count = 1;
				while (count < n)//当count小于n时进行循环。首先判断当前栈顶元素减去k是否符合范围，若符合则压入栈中，
				//否则判断加上k是否满足，进而决定是否压入栈中，并使得count加1.
				{
					int m = seq.Top();
					seq.Pop();
					count--;
					if (m - k >= 0) { seq.Push_back(m); seq.Push_back(m - k); count += 2; }
					else if (m + k <= 9) { seq.Push_back(m); seq.Push_back(m + k); count += 2; }
					else break;
				}//以减的优先级大于加的优先级进行生成数字串，并得到第一个数字串，此时栈中有n个元素进行输出。
				if (i == 1)seq.printfir(n);
				else if (k == 9)seq.printfir(n);
				else seq.print(n);
				while (!seq.isempty())//当栈不为空时，进行循环，方式类似于深度搜索的非递归形式，但做出了相应的调整
				{
					int x = seq.Top();
					seq.Pop();
					count--;//首先弹出栈顶元素，并记录它的值，count减一
					if (x < seq.Top() && seq.Top() + k <= 9)//当此元素的值小于前一个元素，并且加上2k后的值仍在范围内时，
						                                   //进行以下操作，否则完成此轮循环
					{
						seq.Push_back(seq.Top() + k); count++;//将当前栈顶元素加k压入栈顶
						while (count < n)//进行前面生成第一个数字串时的操作
						{
							int m = seq.Top();
							seq.Pop();
							count--;
							if (m - k >= 0) { seq.Push_back(m); seq.Push_back(m - k); count += 2; }
							else if (m + k <= 9) { seq.Push_back(m); seq.Push_back(m + k); count += 2; }
						}
						seq.print(n);//输出数字串
					}
				}

			}
			cout << "]";
		}
		cout << endl << endl << "是否继续？y/任意输入：";//用户选择是否继续进行操作
		char curren;
		cin >> curren;
		if (curren == 'y')judge = 1;
		else {
			judge = 0; cout << "感谢使用！";
		}
	}
	system("pause");
	return 0;
}



			