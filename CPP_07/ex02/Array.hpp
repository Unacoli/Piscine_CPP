#ifndef ARRAY_HPP
# define ARRAY_HPP
# include <iostream>

template<typename T>
class   Array
{
    private:
        T   *_t;
        unsigned int    _n;
    public:
        Array(void) : _n(0)
        {
            _t = new T[1];
            _t[0] = 0;
            return ;
        }
        Array(unsigned int n) : _n(n) 
        {
            _t = new T[n];
            return ;
        }
        Array(Array const &src) : _n(src.size())
        {
            T   *src_t = src.getT();
            _t = new T[_n];
            unsigned int i = 0;
            while (i < _n)
            {
                _t[i] = src_t[i];
                i++;
            } 
            return ;
        }
        ~Array(void)
        {
            delete [] this->_t;
            return ;
        }
        Array & operator=(Array const &rhs)
        {
            T   *rhs_t = rhs.getT();
            this->_n = rhs.size();
            delete [] this->_t;
            this->_t = new T[_n];
            unsigned int i = 0;
            while (i < _n)
            {
                _t[i] = rhs_t[i];
                i++;
            }
            return (*this);
        }
        T & operator[](int i)
        {
            if (i < 0 || i >= static_cast<int>(this->_n))
                throw (std::exception());
            else
                return (*(_t + i));
        }
        T   *getT(void) const
        {
            return (_t);
        }
        unsigned int    size(void) const
        {
            return (_n);
        }
};

template<typename T>
std::ostream & operator<<(std::ostream &out, Array<T> const &in)
{
    unsigned int i = 0;
    while (i < in.size())
    {
        std::cout << "[" << i << "] : " << (in.getT())[i] << std::endl;
        i++;
    }
    return (out);
}

#endif