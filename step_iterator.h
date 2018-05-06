#ifndef STEP_ITERATOR
#define STEP_ITERATOR
#include <iterator>
#include <iostream>
#include <boost/iterator/iterator_facade.hpp>
#include <boost/iterator/iterator_adaptor.hpp>
//implemented in stl-like
//no inherit, use iterator as template argument
template <class _Iter, std::ptrdiff_t _Step=2>
//class step_iterator1 : public boost::iterator_adaptor<step_iterator1<_Iter,_Step>, _Iter, boost::use_default, boost::use_default, boost::use_default>{
class step_iterator1 : public boost::iterator_adaptor<step_iterator1<_Iter,_Step>, _Iter>{
	private:
			typedef  step_iterator1<_Iter, _Step> Self;
			using typename step_iterator1::iterator_adaptor_::difference_type; //why need stp_iterator::
//			friend class boost::iterator_core_access;	
	public:
			step_iterator1(_Iter i):step_iterator1::iterator_adaptor_(i){}
			void increment(){
				this->base_reference()+=_Step;
			}
			void decrement(){
				this->base_reference()-=_Step;
			}
			difference_type distance_to(const  Self& other) {
				return distance_to(this->base_reference(), other.base_reference())/_Step;
			}


};
//inherit std::iterator, use Value as template argument
template <class _Iter, std::ptrdiff_t _Step=2>
class step_iterator2 : public std::iterator<typename std::iterator_traits<_Iter>::iterator_category, typename std::iterator_traits<_Iter>::value_type>{
//class step_iterator2{
	private:
			_Iter m_iter;
			typedef  step_iterator2<_Iter, _Step> Self;
			typedef std::iterator<typename std::iterator_traits<_Iter>::iterator_category, typename std::iterator_traits<_Iter>::value_type> BaseIter;
	public:
			using typename BaseIter::iterator_category;
			using typename BaseIter::value_type;
			using typename BaseIter::reference;
			using typename BaseIter::pointer;
			using typename BaseIter::difference_type;
	public:
			/**
			typedef typename std::iterator_traits<_Iter>::iterator_category iterator_category;
			typedef typename std::iterator_traits<_Iter>::value_type value_type;
			typedef typename std::iterator_traits<_Iter>::pointer pointer;
			typedef typename std::iterator_traits<_Iter>::reference reference;
			typedef typename std::iterator_traits<_Iter>::difference_type difference_type;
			**/
	public:
			step_iterator2(_Iter i):m_iter(i){}
			
			reference operator*(){ return *m_iter; }
			pointer operator->(){ return m_iter; }
			Self& operator++(){
				std::advance(m_iter, _Step);
				return *this;
			}
			Self operator++(int){
				Self temp=this;
				std::advance(m_iter, _Step);
				return temp;
			}
			
			Self& operator--(){
				std::advance(m_iter,-_Step);
				return *this;
			}
			Self operator--(int){
				Self temp=this;
				std::advance(m_iter, -_Step);
				return temp;
			}
			bool operator!=(const Self& other) const{
				return m_iter!=other.m_iter;
			}
		
			difference_type operator-(const Self& other){
				return std::distance(other.m_iter,m_iter)/_Step;
			}

};

//implemented in boost-like


#endif
