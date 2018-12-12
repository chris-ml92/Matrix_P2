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
	
	template<class matrix_class>
	void empl_back(matrix_ref<T, matrix_class> m){
		this->matrix_List.emplace_back(m);
	}
	

template<class Right>
mMult<T,this_Type::Height,matrix_ref<T, Right>::Width> operator* (const matrix_ref<T, Right>& right) {
	this->matrix_List.emplace_back(right); // adds right to the end of matrix_List
	return *this;
}

};

template<typename T, class Left, class Right>
mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> operator* (const matrix_ref<T, Left>& left, const matrix_ref<T, Right>& right){
	mMult<T, matrix_ref<T, Left>::Height, matrix_ref<T, Right>::Width> chain;
	chain.empl_back(left);
	chain.empl_back(right);
	return chain;
}
	




#endif // !OPERATORSTAR_H
