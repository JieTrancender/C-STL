//fo/compose11.hpp

#include <functional>

//组合一个“运行准则”
template <class OP1,class OP2>
class compose_f_gx_t : public std::unary_function < typename OP2::argument_type, typename OP1::result_type >
{
private:
	OP1 op1;
	OP2 op2;

public:
	compose_f_gx_t(const OP1 &o1, const OP2 &o2) :op1(o1), op2(o2){};

	//function call
	typename OP1::result_type operator()(const typename OP2::argument_type &x) const
	{
		return op1(op2(x));
	}
};

//convenience functions for the compose_f_gx adapter(适配器)
template <class OP1,class OP2>
inline compose_f_gx_t<OP1, OP2> compose_f_gx(const OP1 &o1, const OP2 &o2)
{
	return compose_f_gx_t<OP1, OP2>(o1, o2);
}
