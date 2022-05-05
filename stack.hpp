#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"

namespace ft
{

    template <class T, class Container = ft::vector<T> > 
    class stack {
        public:

            typedef T                          value_type; 
            typedef size_t                     size_type;
            typedef Container                  container_type;
            
            explicit stack (const container_type& ctnr = container_type()) 
            {
				if(ctnr.size() != 0)
                	this->_vect = ctnr;
                return ;
            }

            ~stack( void )
            {
                return ;
            }

            void push (const value_type& val)
            {
                this->_vect.push_back(val);
                return ;
            }

            bool empty( void )
            {
                return this->_vect.empty();
            }
            
            size_type   size( void )
            {
                return this->_vect.size();
            }

            value_type & top( void )
            {
                int len = this->_vect.size() - 1;
                value_type &valued = this->_vect[len];
				return valued;
            }

            const value_type& top() const
            {
				int len = this->_vect.size() - 1;
                return this->_vect[len];
            }
 
            void pop( void )
            {
                this->_vect.pop_back();
                return ;
            }

			friend bool operator== (const stack& lhs, const stack& rhs) { return lhs._vect == rhs._vect; }
            friend bool operator!= (const stack& lhs, const stack& rhs) { return lhs._vect != rhs._vect; }
            friend bool operator<  (const stack& lhs, const stack& rhs) { return lhs._vect < rhs._vect; }
            friend bool operator<= (const stack& lhs, const stack& rhs) { return lhs._vect <= rhs._vect; }
            friend bool operator>  (const stack& lhs, const stack& rhs) { return lhs._vect > rhs._vect; }
            friend bool operator>= (const stack& lhs, const stack& rhs) { return lhs._vect >= rhs._vect; }

            private :
                ft::vector<T> _vect;

    };
}
#endif