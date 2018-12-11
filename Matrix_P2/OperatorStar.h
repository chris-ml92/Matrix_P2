#ifndef OPERATORSTAR_H
#define OPERATORSTAR_H
#include"matrix.h"
#include"matrix_wrap.h"
#include<list>


template<typename T, unsigned H=1, unsigned W=1>
class mMult {

private:
	std::list<matrix_wrap<T>> matrix_List;
public:

	mMult() = default;
	typedef mMult<T, H, W> this_Type;
	static constexpr unsigned Height = H;
	static constexpr unsigned Width = W;
	
	//friend mMult<T,matrix_ref<T,Left>> 

template<class Right>
mMult<T,this_Type::Height,Right::Width> operator* ( const matrix_ref<T, Right>& right) {
	return *this;
}

};






#endif // !OPERATORSTAR_H
