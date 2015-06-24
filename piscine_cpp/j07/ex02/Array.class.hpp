#include <iostream>

template<typename T>
class   Array {

	private:
		T *             _array;
		unsigned int    _size;

	public:
		Array( void ) : _array(new T[0]), _size(0) { }
		Array<T>( unsigned int n ) : _array(new T[n]), _size(n) {
			
			for (unsigned int i = 0; i < this->_size; i++) {
			
				_array[i] = T();
			}
		}
		Array( Array const & src ) { this->_array = src; this->_size = src.size(); }
		~Array( void ) { delete [] _array; }

		Array & operator=( Array const & rhs ) {

			delete [] this->_array;
			this->_array = new T[rhs.size()];
			for (unsigned int i = 0; i < rhs._size; i++) {

				this->_array[i] = rhs._array[i];
			}
			this->_size = rhs._size;
			return *this;
		}

		T &		operator[]( int n ) {

			if (n >= (int)this->_size || n < 0)
				throw OutOfBound_exception();
			
			return (_array[n]);
		}
		
		unsigned int    size( void ) const { return this->_size; }

		class OutOfBound_exception : public std::exception {
			public:
				virtual ~OutOfBound_exception( void ) throw() {}
				virtual const char* what( void ) const throw() { return "OutOfBound_exception: out of array range"; }
		};
};
