#pragma once

# include <iostream>
# include <vector>
# include <ctime>
# include <sstream>
# include <algorithm>
# include <deque>

class PmergeMe
{
    private:
        std::vector<int>    _vec;
        std::deque<int>     _deq;
        int                 _size;

        template<typename T>
        void mergeSort(T &v, size_t l, size_t r)
        {
            size_t m = (l + r) / 2;
            if (l < r)
            {
                mergeSort(v, l, m);
                mergeSort(v, m + 1, r);
            }
            merge_sorted(v, l, m, r);
        }

        template<typename T>
        void merge_sorted(T &v, size_t l, size_t m, size_t r)
        {
            T tmp(r + 1);
            size_t i = l, j = m + 1, k = l;
            while (i <= m && j <= r)
            {
                if (v[i] < v[j])
                {
                    tmp[k] = v[i];
                    k++;
                    i++;
                }
                else
                {
                    tmp[k] = v[j];
                    k++;
                    j++;
                }
            }
            while (i <= m)
            {
                tmp[k] = v[i];
                k++;
                i++;
            }
            while (j <= r)
            {
                tmp[k] = v[j];
                k++;
                j++;
            }
            i = l;
            while (i <= r)
            {
                v[i] = tmp[i];
                i++;
            }
        }

        template<typename T>
        void    merge_insert_sort(T &v)
        {
            int strag;
            std::vector<T> pairs;
            bool is_strag = false;

            if (v.size() % 2 != 0)
            {
                strag = *(v.end() -1);
                v.pop_back();
                is_strag = true;
            }
            pairs = this->create_pairs(v);
            sort_by_larger_value(pairs);
            v.clear();
            for (int i = (int)(pairs.size() - 1); i >= 0; --i)
            {
                v.push_back(pairs[i][0]);
            }
            for(size_t i = 0; i < pairs.size(); i++)
            {
                insert_right_place(v, pairs[i][1]);
            }
            if (is_strag)
                insert_right_place(v, strag);
            std::reverse(v.begin(), v.end());
        }

        template <typename T>
        void insert_right_place(T &v, int value)
        {
            typename T::iterator l = v.begin();
            typename T::iterator r = v.end();
            while (l != r)
            {
                if (*l < value)
                {
                    v.insert(l, value);
                    break;
                }
                if (*(r - 1) > value)
                {
                    v.insert(r, value);
                    break;
                }
                l++;
                r--;
            }
        }

        template <typename T>
        std::vector<T>  create_pairs(T &v)
        {
            std::vector<T> total_pairs;
            T   pair;
            for (size_t i = 0; i < v.size(); i++)
            {
                if (i % 2 != 0)
                {
                    if (v[i] > v[i - 1])
                    {
                        pair.push_back(v[i - 1]);
                        pair.push_back(v[i]);
                    }
                    else
                    {
                        pair.push_back(v[i]);
                        pair.push_back(v[i - 1]);
                    }
                    total_pairs.push_back(pair);
                    pair.clear();
                }
            }
            return (total_pairs);
        }

        template <typename T>
        void    sort_by_larger_value(std::vector<T> &pairs)
        {
            mergeSort(pairs, 0, pairs.size() - 1);
        }

    public:
        void    mergeMe(char **args, int len);
        PmergeMe(void);
        PmergeMe(PmergeMe const &src);
        ~PmergeMe(void);
        PmergeMe& operator=(PmergeMe const &rhs);
};