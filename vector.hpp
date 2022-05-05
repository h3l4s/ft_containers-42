#ifndef VECTOR_HPP
# define VECTOR_HPP


#include <iostream>
#include <memory>
#include <exception>
#include <iterator>

namespace ft
{

    template <typename T, class Alloc = std::allocator<T> >
    class vector{
        public:

            typedef Alloc												allocator_type;
            typedef size_t												    size_type;

//••••••••••••••••••••••••••••••••••••••CONSTRUCTOR••••••••••••••••••••••••••••••••••••••••••••••••••//


            explicit vector (const allocator_type& alloc = allocator_type()) 
            {
                this->_size = 0;
                this->_size_hide = 0;
                this->_myTab = NULL;
                this->_tab = alloc;
            }

            explicit vector (int n, const T & val = T(), const allocator_type& alloc = allocator_type()) 
            {
                this->_tab = alloc;
                this->_size = n;
                this->_size_hide = n;
                this->_myTab = this->_tab.allocate(n);
                for (int i = 0; i < n; i++) 
                    this->_tab.construct(this->_myTab + i, val);
            }

            template <class InputIterator>
            vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
            {
                    InputIterator it = first;
                    InputIterator ite = last;
                    int count = 0;
                    this->_tab = alloc;
                    if (first > last)
                        throw std::length_error("Error : at out of range error");
                    while (it != ite)
                    {
                        count++;
                        it++;
                    }
                    T tmp[count];
                    count = 0;
                    while (first != last)
                    {
                        tmp[count] = *first;
                        count++;
                        first++;
                    }
                    this->_size = count;
                    this->_size_hide = count;
                    this->_myTab = this->_tab.allocate(count + 1, 0);
                    for(int i = 0; i < count; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                }

            vector( vector const & src ) 
            {
                *this = src;
                return ;
            }


//••••••••••••••••••••••••••••••••••••••CLASS•ITERATOR••••••••••••••••••••••••••••••••••••••••••••••••••••••//

            class iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    iterator(void) 
                    {
                        return ;
                    }
                    iterator(T * x) :p(x) 
                    {
                        return ;
                    }

                    iterator & operator=( iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    iterator(iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T& operator*( void ) const
                    {
                        return *p;
                    }

                    bool operator==( iterator const & it ) const
                    {
                        if (it.p == this->p)
                            return true;
                        return false;
                    }

                    bool operator!=( iterator const & ite) const
                    {
                        if (this->p == ite.p)
                            return false;
                        return true;
                    }

                    iterator operator++(int) 
                    {
                        iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    iterator& operator++(void) 
                    {
                        this->p++;
                        return *this;
                    }


                    iterator operator--(int) 
                    {
                        iterator  temp = *this;
                        --*this;
                        return temp;
                    }

                    iterator& operator--(void) 
                    {
                        this->p--;
                        return *this;
                    }

                    bool  operator>=( iterator const & src ) const
                    {
                        if (this->p >= src.p)
                            return true;
                        return false;
                    }

                    bool  operator<=( iterator const & src ) const
                    {
                        if (this->p <= src.p)
                            return true;
                        return false;
                    }

                    bool  operator>( iterator const & src ) const
                    {
                        if (this->p > src.p)
                            return true;
                        return false;
                    }

                    bool    operator<( iterator const & src ) const
                    {
                        if (this->p < src.p)
                            return true;
                        return false;
                    }

                    iterator  operator+( iterator const & src )
                    {
                        iterator temp;
                        temp.p = this->p + src.p; 
                        return temp;
                    }

                    iterator  operator-( iterator const & src )
                    {
                        iterator temp;
                        temp.p = this->p - src.p; 
                        return temp;
                    }

                    iterator  operator+=( int val ) 
                    {
                        this->p = this->p + val; 
                        return *this;
                    }

                    iterator  operator-=( int val ) 
                    {
                        this->p = this->p - val; 
                        return *this;
                    }

                    iterator  operator/( iterator const & src )
                    {
                        iterator temp;
                        temp.p = this->p / src.p;
                        return temp;
                    }

                    iterator  operator*( iterator const & src )
                    {
                        iterator temp;
                        temp.p= this->p * src.p; 
                        return temp ;
                    }

                private :
                    T * p;
            };

            class const_iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    const_iterator(void) 
                    {
                        return ;
                    }
                    const_iterator(T * x) :p(x) 
                    {
                        return ;
                    }

                    const_iterator & operator=( const_iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    const_iterator(const_iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T const & operator*( void ) const
                    {
                        return *p;
                    }

                    bool operator==( const_iterator const & it ) const
                    {
                        if (it.p == this->p)
                            return true;
                        return false;
                    }

                    bool operator!=( const_iterator const & ite) const
                    {
                        if (this->p == ite.p)
                            return false;
                        return true;
                    }

                    const_iterator operator++(int) 
                    {
                        const_iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    const_iterator& operator++(void) 
                    {
                        this->p++;
                        return *this;
                    }

                    const_iterator operator--(int) 
                    {
                        const_iterator  temp = *this;
                        --*this;
                        return temp;
                    }

                    const_iterator& operator--(void) 
                    {
                        this->p--;
                        return *this;
                    }

                    bool  operator>=( const_iterator const & src ) const
                    {
                        if (this->p >= src.p)
                            return true;
                        return false;
                    }

                    bool  operator<=( const_iterator const & src ) const
                    {
                        if (this->p <= src.p)
                            return true;
                        return false;
                    }

                    bool  operator>( const_iterator const & src ) const
                    {
                        if (this->p > src.p)
                            return true;
                        return false;
                    }

                    bool    operator<( const_iterator const & src ) const
                    {
                        if (this->p < src.p)
                            return true;
                        return false;
                    }

                    const_iterator const  operator+( const_iterator const & src )
                    {
                        const_iterator temp;
                        temp.p = this->p + src.p; 
                        return temp;
                    }

                    const_iterator  const operator-( const_iterator const & src )
                    {
                        const_iterator temp;
                        temp.p = this->p - src.p; 
                        return temp;
                    }

                    const_iterator operator+=( int val ) 
                    {
                        this->p = this->p + val; 
                        return *this;
                    }

                    const_iterator operator-=( int val ) 
                    {
                        this->p = this->p - val; 
                        return *this;
                    }

                    const_iterator const operator/( const_iterator const & src )
                    {
                        const_iterator temp;
                        temp.p = this->p / src.p;
                        return temp;
                    }

                    const_iterator const operator*( const_iterator const & src )
                    {
                        const_iterator temp;
                        temp.p= this->p * src.p; 
                        return temp ;
                    }

                private :
                    T * p;
            };

            class const_reverse_iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    const_reverse_iterator(void) 
                    {
                        return ;
                    }
                    const_reverse_iterator(T * x) :p(x) 
                    {
                        return ;
                    }

                    const_reverse_iterator & operator=( const_reverse_iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    const_reverse_iterator(const_reverse_iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T const & operator*( void ) const
                    {
                        return *p;
                    }

                    bool operator==( const_reverse_iterator const & it ) const
                    {
                        if (it.p == this->p)
                            return true;
                        return false;
                    }

                    bool operator!=( const_reverse_iterator const & ite) const
                    {
                        if (this->p == ite.p)
                            return false;
                        return true;
                    }

                    const_reverse_iterator operator++(int) 
                    {
                        const_reverse_iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    const_reverse_iterator& operator++(void) 
                    {
                        this->p--;
                        return *this;
                    }

                    const_reverse_iterator operator--(int) 
                    {
                        const_reverse_iterator  temp = *this;
                        --*this;
                        return temp;
                    }

                    const_reverse_iterator& operator--(void) 
                    {
                        this->p++;
                        return *this;
                    }

                    bool  operator>=( const_reverse_iterator const & src ) const
                    {
                        if (this->p >= src.p)
                            return true;
                        return false;
                    }

                    bool  operator<=( const_reverse_iterator const & src ) const
                    {
                        if (this->p <= src.p)
                            return true;
                        return false;
                    }

                    bool  operator>( const_reverse_iterator const & src ) const
                    {
                        if (this->p > src.p)
                            return true;
                        return false;
                    }

                    bool    operator<( const_reverse_iterator const & src ) const
                    {
                        if (this->p < src.p)
                            return true;
                        return false;
                    }

                    const_reverse_iterator const operator+( const_reverse_iterator const & src )
                    {
                        const_reverse_iterator temp;
                        temp.p = this->p + src.p; 
                        return temp;
                    }

                    const_reverse_iterator const operator-( const_reverse_iterator const & src )
                    {
                        const_reverse_iterator temp;
                        temp.p = this->p - src.p; 
                        return temp;
                    }

                    const_reverse_iterator operator+=( int val ) 
                    {
                        this->p = this->p + val; 
                        return *this;
                    }

                    const_reverse_iterator operator-=( int val ) 
                    {
                        this->p = this->p - val; 
                        return *this;
                    }

                    const_reverse_iterator const operator/( const_reverse_iterator const & src )
                    {
                        const_reverse_iterator temp;
                        temp.p = this->p / src.p;
                        return temp;
                    }

                    const_reverse_iterator const operator*( const_reverse_iterator const & src )
                    {
                        const_reverse_iterator temp;
                        temp.p= this->p * src.p; 
                        return temp ;
                    }

                private :
                    T * p;
            };

            class reverse_iterator : public std::iterator<std::input_iterator_tag, int>{
                public:
                    reverse_iterator(void) 
                    {
                        return ;
                    }
                    reverse_iterator(T * x) :p(x) 
                    {
                        return ;
                    }

                    reverse_iterator & operator=( reverse_iterator const & src) 
                    {
                        this->p = src.p;
                        return *this ;
                    }

                    reverse_iterator(reverse_iterator const & test) :p(test.p) 
                    {
                        return ;
                    }

                    T& operator*( void ) 
                    {
                        return *p;
                    }

                    bool operator==( reverse_iterator const & it ) 
                    {
                        if (it.p == this->p)
                            return true;
                        return false;
                    }

                    bool operator!=( reverse_iterator const & ite) 
                    {
                        if (this->p == ite.p)
                            return false;
                        return true;
                    }

                    reverse_iterator operator++(int) 
                    {
                        reverse_iterator  temp = *this;
                        ++*this;
                        return temp;
                    }

                    reverse_iterator& operator++(void) 
                    {
                        this->p--;
                        return *this;
                    }

                    reverse_iterator operator--(int) 
                    {
                        reverse_iterator  temp = *this;
                        --*this;
                        return temp;
                    }

                    reverse_iterator& operator--(void) 
                    {
                        this->p++;
                        return *this;
                    }

                    bool  operator>=( reverse_iterator const & src ) const
                    {
                        if (this->p >= src.p)
                            return true;
                        return false;
                    }

                    bool  operator<=( reverse_iterator const & src ) const
                    {
                        if (this->p <= src.p)
                            return true;
                        return false;
                    }

                    bool  operator>( reverse_iterator const & src ) const
                    {
                        if (this->p > src.p)
                            return true;
                        return false;
                    }

                    bool    operator<( reverse_iterator const & src ) const
                    {
                        if (this->p < src.p)
                            return true;
                        return false;
                    }

                    reverse_iterator  operator+( reverse_iterator const & src )
                    {
                        reverse_iterator temp;
                        temp.p = this->p + src.p; 
                        return temp;
                    }

                    reverse_iterator  operator-( reverse_iterator const & src )
                    {
                        reverse_iterator temp;
                        temp.p = this->p - src.p; 
                        return temp;
                    }
                    
                    reverse_iterator operator+=( int val ) 
                    {
                        this->p = this->p + val; 
                        return *this;
                    }

                    reverse_iterator operator-=( int val ) 
                    {
                        this->p = this->p - val; 
                        return *this;
                    }

                    reverse_iterator  operator/( reverse_iterator const & src )
                    {
                        reverse_iterator temp;
                        temp.p = this->p / src.p;
                        return temp;
                    }

                    reverse_iterator  operator*( reverse_iterator const & src )
                    {
                        reverse_iterator temp;
                        temp.p= this->p * src.p; 
                        return temp ;
                    }
                private :
                    T * p;
            };

//•••••••••••••••••••••••••••••••••ITERATOR•FUNCTION••••••••••••••••••••••••••••••••••••••••••••••••••••//
            
            iterator   begin( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                iterator   it(this->_myTab);
                return (it);
            }

            iterator   end( void ) const
            {
                if (this->_size_hide == 0)
                {    
                    iterator   it1(this->_myTab);
                    return it1;
                }
                iterator   it(this->_myTab + this->_size_hide);
                return (it);
            }

            iterator   begin( void ) 
            {
                if (this->_size_hide == 0)
                    return NULL;
                iterator   it(this->_myTab);
                return (it);
            }

            iterator   end( void )
            {
                if (this->_size_hide == 0)
                {    
                    iterator   it1(this->_myTab);
                    return it1;
                }
                iterator   it(this->_myTab + this->_size_hide);
                return (it);
            }

            const_iterator   cbegin( void ) const
            {
                if (this->_size_hide == 0)
                    return NULL;
                const_iterator   it(this->_myTab);
                return (it);
            }

            const_iterator   cend( void ) const
            {
                if (this->_size_hide == 0)
                {    
                    const_iterator   it1(this->_myTab);
                    return it1;
                }
                const_iterator   it(this->_myTab + this->_size_hide);
                return (it);
            }

            const_iterator   cbegin( void ) 
            {
                if (this->_size_hide == 0)
                    return NULL;
                const_iterator   it(this->_myTab);
                return (it);
            }

            const_iterator   cend( void )
            {
                if (this->_size_hide == 0)
                {    
                    const_iterator   it1(this->_myTab);
                    return it1;
                }
                const_iterator   it(this->_myTab + this->_size_hide);
                return (it);
            }
            
            const_reverse_iterator   crbegin( void  )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                const_reverse_iterator   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            const_reverse_iterator   crend( void )  
            {
                if (this->_size_hide == 0)
                {    
                    const_reverse_iterator   it1(this->_myTab);
                    return it1;
                }
                const_reverse_iterator   it(this->_myTab - 1);
                return (it);
            }

            const_reverse_iterator   crbegin( void  )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                const_reverse_iterator   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            const_reverse_iterator   crend( void )  const
            {
                if (this->_size_hide == 0)
                {    
                    const_reverse_iterator   it1(this->_myTab);
                    return it1;
                }
                const_reverse_iterator   it(this->_myTab - 1);
                return (it);
            }

            reverse_iterator   rbegin( void  )  const
            {
                if (this->_size_hide == 0)
                    return NULL;
                reverse_iterator   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            reverse_iterator   rend( void )  const
            {
                if (this->_size_hide == 0)
                {    
                    reverse_iterator   it1(this->_myTab);
                    return it1;
                }
                reverse_iterator   it(this->_myTab - 1);
                return (it);
            }

            reverse_iterator   rbegin( void  )  
            {
                if (this->_size_hide == 0)
                    return NULL;
                reverse_iterator   it(this->_myTab + this->_size_hide - 1);
                return (it);
            }

            reverse_iterator   rend( void )  
            {
                if (this->_size_hide == 0)
                {    
                    reverse_iterator   it1(this->_myTab);
                    return it1;
                }
                reverse_iterator   it(this->_myTab - 1);
                return (it);
            }

//•••••••••••••••••••••••••••••••••ASSIGNATION•OPERATION••••••••••••••••••••••••••••••••••••••••••••••••••••//
            
            vector<T> & operator=(vector<T> const & src)
            {
				if(*this == src){
					if(src._myTab == NULL)
						this->_myTab = NULL;
					return *this;
				}
				if(src._myTab == NULL)
				{
					this->_size = 0;
					this->_size_hide = 0;
					this->_tab.deallocate(this->_myTab, 1);
					this->_myTab = NULL;
					return *this;
				}
				this->clear();
				if(src.begin() != NULL)
					this->insert(this->end(), src.begin(), src.end());
				else
					this->_myTab = NULL;
				this->_size = src._size;
            	this->_size_hide = src._size_hide;
                return *this;
            }

            T & operator[]( unsigned int i ) const
            {
                return this->_myTab[i];
            }

//•••••••••••••••••••••••••••••••••DESTRUCTOR•••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••••//
            ~vector( void )
            {
                if (this->_myTab != NULL)
                    this->_tab.deallocate(this->_myTab, this->_size_hide);
                return ;
            }

//•••••••••••••••••••••••••••ELEMENT•ACCESS•FUNCTION••••••••••••••••••••••••••••••••••••••••••••••••••••••••//

            bool empty( void ) const
            {
                if (this->_size_hide == 0)
                    return true;
                return false;
            }

            unsigned int size( void ) const
            {
                return (unsigned int)this->_size_hide;
            }

            T   & front( void ) const
            {
                return this->_myTab[0];
            }
            
            T   * data( void ) const
            {
                if (this->_size == 0)
                    return NULL;
                return &this->_myTab[0];
            }

            T   & at( size_type value ) const
            {
                if (value > this->_size_hide)
                    throw std::out_of_range("Error : at out of range error");
                return this->_myTab[value];
            }

            T   & back( void ) const
            {
                return this->_myTab[this->_size - 1];
            }

//•••••••••••••••••••••••••••••••••CAPACITY•FUNCTION••••••••••••••••••••••••••••••••••••••••••••••••••••••••//

            void push_back(const T & val)
            {
                T *tmp = NULL;
                if (this->_myTab)
                {    
                    tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                    for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]); 
                    this->_tab.deallocate(this->_myTab, this->_size_hide);
                }
                this->_myTab = this->_tab.allocate(this->_size + 1, 0);
                if (tmp != NULL)
                {
                    for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                    this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
                }
                this->_tab.construct(this->_myTab + _size_hide, val);
                if (this->_size <= this->_size_hide)
                    _size++;
                this->_size_hide++;
                return ;
            }

            void pop_back( void )
            {
                if (this->_size_hide == 0)
                    return ;
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]); 
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size--;
                this->_size_hide--;
                for (size_type i = 0; i < this->_size ; i++)
                    this->_tab.construct(this->_myTab + i, tmp[i]);
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
                return ;
            }

            void clear( void )
            {
                size_t len = this->_size;
                if (len > 1000)
                    len = 0;
                for (size_t i = 0; i < len; i++) {
                    this->_tab.destroy(this->_myTab + i);
                }
                this->_size_hide = 0;
            }

            size_type max_size() const
            {
                return this->_tab.max_size();
            }

            template <class Erase>
            Erase   erase( Erase it) 
            {
                Erase it1 = this->begin();
                size_type to_erase = 0;

                while (it1 != it )
                {
                    to_erase++;
                    it1++;
                }
                T *tmp = this->_myTab;
                this->_tab.destroy(this->_myTab + to_erase);
                //this->_myTab = this->_tab.allocate(this->_size, 0);
                this->_size_hide--;
                int temp = 0;
                for (size_type i = 0; i < this->_size ; i++)
                {    
                    if ( i != to_erase)
                    {    
                        this->_tab.construct(this->_myTab + temp, tmp[i]);
                        temp++;
                    }
                }
                this->_size--;
                return (++it1);
            } 

            template <class Poly_erase>
            Poly_erase   erase( Poly_erase it, Poly_erase ite) 
            {
                Poly_erase it1 = this->begin();
                size_type to_erase_begin = 0;
                size_type to_erase_end = 0;

                if (it > ite)
                        throw std::length_error("Error : at out of range error");
                while (it1 != ite )
                {
                    to_erase_end++;
                    it1++;
                }
                it1 = this->begin();
                while (it1 != it )
                {
                    to_erase_begin++;
                    it1++;
                }
                T *tmp = this->_myTab;
                for (size_type i = to_erase_begin; i < to_erase_end; i++ )
                    this->_tab.destroy(this->_myTab + i);
                //this->_myTab = this->_tab.allocate(this->_size - (to_erase_end - to_erase_begin), 0);
                this->_size_hide-= (to_erase_end - to_erase_begin);
                int temp = 0;
                for (size_type i = 0; i < this->_size  ; i++)
                {    
                    if ( i < to_erase_begin || i >= to_erase_end )
                    {    
                        this->_tab.construct(this->_myTab + temp, tmp[i]);
                        temp++;
                    }
                }
                this->_size -= (to_erase_end - to_erase_begin );
                while(to_erase_begin != to_erase_end)
                {
                    it++;
                    to_erase_begin++;
                }
                
                return (it);
            } 
            
            template <class InputIterator>
			void insert (iterator position, InputIterator first, InputIterator last)
            {
				iterator it1 = this->begin();
                size_type place = 0;
				int temp = 0;
				size_type count = 0;
                int value_counter = 0;

                if (first > last)
                        throw std::length_error("Error : at out of range error");
				while (first != last )
                {
                    count++;
                    if (count > this->_size_hide)
                        return ;
                    first++;
                }
                T value[count];
				first -=count;
				while (it1 != position)
				{
					it1++;
					place++;
				}
                for (int i = 0;first != last; i++ )
                {
                    value[i] = *first;
                    first++;
                }
				it1 -= place;
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_size +=count;
                this->_size_hide +=count;
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (size_type i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                    {
                        while (count > 0)
                        {
                            this->_tab.construct(this->_myTab + i, value[value_counter]);
                            i++;
							value_counter++;
                            count--;
                        }
                        i--;
                    }
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
			}

            void insert(iterator it, int n, const T & val)
            {
                iterator it1 = this->begin();
                size_t place = 0;
                int temp = 0;

                if (it1 > it)
                    throw std::length_error("Error : at out of range error");
                while (it1 != it )
                {
                    place++;
                    it1++;
                }
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_size += n;
                this->_size_hide += n;
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (size_type i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                    {
                        while (n > 0)
                        {
                            this->_tab.construct(this->_myTab + i, val); 
                            i++; 
                            n--;
                        }
                        i--;
                    }
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
            }

            iterator insert(iterator it, const T & val)
            {
                iterator it1 = this->begin();
                size_type place = 0;
                int temp = 0;

                while (it1 != it )
                {
                    place++;
                    it1++;
                }
                T *tmp = this->_tab_tmp.allocate(this->_size_hide + 1, 0);
                for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab.construct(tmp + i, this->_myTab[i]);
                this->_size++;
                this->_size_hide++;
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(this->_size , 0);
                for (size_type i = 0; i < this->_size  ; i++)
                {  
                    
                    if (i == place)
                        this->_tab.construct(this->_myTab + i, val); 
                    else
                        this->_tab.construct(this->_myTab + i, tmp[temp++]);  
                }
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
                iterator it2 = this->begin();
                while (place > 0)
                {
                    place--;
                    it2++;
                }
                return it2;
            }

            

            void assign( int n, const T & val)
            {
                if (this->_myTab != NULL)
                    this->_tab.deallocate(this->_myTab, this->_size);
                this->_myTab = this->_tab.allocate(n, 0);
                this->_size = n;
                this->_size_hide = n;
                for (int i = 0; i < n; i++)
                    this->_tab.construct(this->_myTab + i, val); 
                return ;
            }

            template <class InputIterator>
                void assign (InputIterator first, InputIterator last)
                {
                    if (first > last)
                        throw std::length_error("Error : at out of range error");
                    InputIterator it = first;
                    InputIterator ite = last;
                    int count = 0;
                    
                    while (it != ite)
                    {
                        count++;
                        it++;
                    }
                    T tmp[count];
                    count = 0;
                    while (first != last)
                    {
                        tmp[count] = *first;
                        count++;
                        first++;
                    }
                    if (this->_myTab != NULL)
                        this->_tab.deallocate(this->_myTab, this->_size);
                    this->_size = count;
                    this->_size_hide = count;
                    this->_myTab = this->_tab.allocate(count + 1, 0);
                    for(int i = 0; i < count; i++)
                        this->_tab.construct(this->_myTab + i, tmp[i]);
                }

            void swap(vector<T> & src)
            {
                std::allocator<T>    _tab1;
                std::allocator<T>    _tab_tmp1;
                T                    *_myTab1;
                size_type                 _size1;
                size_type                 _size_hide1;

                _tab1 = src._tab;
                _tab_tmp1 = src._tab_tmp;
                _myTab1 = src._myTab;
                _size1 = src._size;
                _size_hide1 = src._size_hide;
                src._tab = this->_tab;
				src._myTab = this->_myTab;
				src._size = this->_size;
				src._size_hide = this->_size_hide;
                this->_tab = _tab1;
                this->_tab_tmp = _tab_tmp1;
                this->_myTab = _myTab1;
                this->_size = _size1;
                this->_size_hide = _size_hide1;
                return ;
            }

			size_type capacity() const
            {
                size_type cap = 0;
                size_type i = 1;
                while (i < this->_size )
                    i *= 2;
                cap = i;
				return cap ;
			}

			void reserve(size_type n)
            {
				if(n <= this->_size)
					return;
				this->_size = n;
                int temp = 0;
                T *tmp = this->_tab_tmp.allocate(this->_size_hide, 0);
                for (size_type i = 0; i < this->_size_hide; i++)
                        this->_tab_tmp.construct(tmp + i, this->_myTab[i]);
                this->_tab.deallocate(this->_myTab, this->_size_hide);
                this->_myTab = this->_tab.allocate(n + 1 , 0);
				for (size_type i = 0; i < this->_size_hide  ; i++) 
                	this->_tab.construct(this->_myTab + i, tmp[temp++]);
                this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
				return;
			}

			void resize (size_type n, T val = T())
            {
				iterator its = this->begin();
				iterator ite = this->end();
				int place = 0;
				if(n < this->size())
				{
					for(size_type i = 0; i < n ; i++)
					{
						its++;
						place++;
					}
					for((void)its; its != ite; its++)
					{
						this->_tab.destroy(this->_myTab + place);
						place++;
						this->_size_hide--;
					}
				}
				else if (n > this->size())
				{
					if(this->_size > n)
					{
						for (size_t i = this->_size_hide; i < this->_size - 1  ; i++)
						{
                			this->_tab.construct(this->_myTab + i, val);
							this->_size_hide++;
						}
					}
					else{
               			T *tmp = this->_tab_tmp.allocate(this->_size_hide, 0);
                		for (size_type i = 0; i < this->_size_hide; i++)
                        	this->_tab.construct(tmp + i, this->_myTab[i]);
                		this->_tab.deallocate(this->_myTab, this->_size_hide);
                		this->_myTab = this->_tab.allocate(n , 0);
						for (size_type i = 0; i < this->_size_hide  ; i++) 
                			this->_tab.construct(this->_myTab + i, tmp[i]);
						for (size_t i = this->_size_hide; i < n  ; i++)
						{
                			this->_tab.construct(this->_myTab + i, val);
							this->_size_hide++;
						}
                		this->_tab_tmp.deallocate(tmp, this->_size_hide + 1);
						this->_size = n;
					}
				}
				return;
			}

//•••••••••••••••••••••••••••••••••RELATIONAL•OPERATOR••••••••••••••••••••••••••••••••••••••••••••••••••//

            friend bool operator==(const vector & lhs, const vector & rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    for(size_type i = 0; i < lhs.size(); i++)
                    {
                        if (lhs.at(i) != rhs.at(i))
                            return false;
                    }
                    return true;
                }
                return false;
            }

            friend bool operator!=(const vector & lhs, const vector & rhs)
            {
                if (lhs.size() == rhs.size())
                {
                    for(size_type i = 0; i < lhs.size(); i++)
                    {
                        if (lhs.at(i) != rhs.at(i))
                            return true;
                    }
                    return false;
                }
                return true;
            }

            friend bool operator<(const vector & lhs, const vector & rhs)
            {
				size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(size_t i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return false;
                    }
				if(lhs == rhs)
					return false;
                return true;
            }

            friend bool operator<=(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(size_t i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return false;
                    }
                return true;
            }

            friend bool operator>(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(size_t i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return true;
                    }
                return false;
            }

            friend bool operator>=(const vector & lhs, const vector & rhs)
            {
                size_t len;
				if(lhs.size() > rhs.size())
					len = lhs.size();
				else
					len = rhs.size();
                for(size_t i = 0; i < len; i++)
                    {
						if(lhs.at(i) > rhs.at(i))
							return true;
                    }
				if(lhs == rhs)
					return true;
                return false;
            } 

        private:
            std::allocator<T>    _tab;
            std::allocator<T>    _tab_tmp;
            T                    *_myTab;
            size_type                 _size;
            size_type                 _size_hide;
    };
}

#endif //VECTOR_HPP