#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <functional>
#include <iomanip>

using namespace std;

/*main函数中第二种Lambda使用方法相当于如下操作*/
class Functor
{
public:
	Functor(int i, int step) :_i(i), _step(step){};
	int operator()()
	{
		return _i += _step;
	}

private:
	int _i;
	int _step;
};

void foo(function<int(int, int)> f)//声明模板函数
{
	cout << f(1, 2) << endl;
}

int main()
{
	vector<int> numbers(10);
	//[]是Lambda的捕获语句，函数体通过{}包围
	generate(numbers.begin(), numbers.end(), []{return rand() % 100; });

	//判断上句生成随机数中有多少个偶数，even：偶数
	//Lambda传递方式有按值传递和按引用传递，默认方式为按值传递
	int even_count = 0;
	for_each(numbers.begin(), numbers.end(),[&even_count](int value){
			if (value % 2 == 0) ++even_count;
	});
	//生成等差数列
	int step = 2;
	int i = -step;
	vector<int> seq(10);
	generate(seq.begin(), seq.end(), [&i, &step]{//按引用传递，改变i的值
		return i += step;
	});
	copy(seq.begin(), seq.end(), ostream_iterator<int>(cout, " "));
	cout << endl << "i = " << i << endl << endl;//i = 18
	i = -step;
	vector<int> v(10);
	//mutable使得可以在Lambda的函数体修改按值传递的变量，但这些修改对Lambda之外是不可看的
	generate(v.begin(), v.end(), [i, step]() mutable{//按值传递，不改变i的值，必须使用mutable,必须使用参数列表即使没有参数
		return i += step;
	});
	copy(v.begin(), v.end(), ostream_iterator<int>(cout, " "));
	cout << endl << "i = " << i << endl << endl;;//i = -2

	int step_ = 2;
	int i_ = -step_;
	vector<int> seq_(10);
	generate(seq_.begin(), seq_.end(), Functor(i_, step_));
	copy(seq_.begin(), seq_.end(), ostream_iterator<int>(cout, " "));
	cout << endl << endl;

	auto f1 = [](int x, int y){
		return x + y;
	};
	for (int i = 0; i < 10; ++i)
	{
		cout << f1(i,i-1) << ' ';
	}
	cout << endl;

	foo(f1);

	function<void()> func_1 = [](){cout << "hello,world !" << endl; };
	func_1();

	//捕获变量的值在声明Lambda的那一刻就已经确定变量的值了，如果都为按值调用则不能再修改，如果是按引用传递，修改变量的值可以修改Lambda里面的内容
	int x = 1, y = 2;
	auto f = [x, &y]{return x + y; };
	x = 3, y = 4;
	cout << f() << endl << endl;//输出为5，1 + 4

	//Lambda在只包含一条返回语句或者没有返回值的时候可以省略返回值类型
	//当需要加上返回值类型的时候，必须把它放在参数列表后面，并且在返回值类型前面加上"->"符号
	auto f2 = [](int x, int y) -> float{
		return float(x + y);
	};
	printf("%f\n", f2(2, 3));
	cout << setiosflags(ios_base::fixed) << f2(3, 4) << endl << endl;
	return 0;
}
