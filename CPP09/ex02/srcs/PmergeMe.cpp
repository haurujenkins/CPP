/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:51:57 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/10 15:01:54 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

int myAtoi(const char* str)
{
    int result = 0;
    int i = 0;

    if (str[i] == '-')
    {
        throw std::runtime_error("Error: numbers must be positive");
    }
    while (str[i] != '\0')
    {
        if (str[i] < '0' || str[i] > '9')
        {
            throw std::invalid_argument("Error: arg is not a number");
        }
        if (result > (INT_MAX - (str[i] - '0')) / 10)
        {
            throw std::overflow_error("Error: arg is bigger than INT_MAX");
        }
        result = result * 10 + (str[i] - '0');
        i++;
    }
    return result;
}

template <typename Container>
Container generateJacobsthalSequence(int size)
{
    Container jacobsthal;
    int a = 0, b = 1;
    
    jacobsthal.push_back(a);
    if (size > 1) jacobsthal.push_back(b);
    for (int i = 2; i < size;)
    {
        int next = b + 2 * a; // Jacobsthal(n) = Jacobsthal(n-1) + 2*Jacobsthal(n-2)
        jacobsthal.push_back(next);
        a = b;
        b = next;
        i = next;
    }
    return jacobsthal;
}

template <typename Container>
void insertIntoSorted(Container& sortedList, typename Container::value_type value)
{
    typename Container::iterator it = sortedList.begin();
    while (it != sortedList.end() && *it < value)
    {
        ++it;
    }
    sortedList.insert(it, value);
}

template <typename Container>
void fordJohnsonSort(Container& container)
{
    if (container.size() < 2) return;

    Container small, large;
    
    for (size_t i = 0; i + 1 < container.size(); i += 2)
    {
        if (container[i] < container[i + 1])
        {
            small.push_back(container[i]);
            large.push_back(container[i + 1]);
        } else
        {
            small.push_back(container[i + 1]);
            large.push_back(container[i]);
        }
    }
    if (container.size() % 2 != 0) 
    {
        large.push_back(container.back());
    }

    std::sort(small.begin(), small.end());

    Container jacobsthal = generateJacobsthalSequence<Container>(large.size());
    size_t index;
    for (size_t i = 0; i < large.size(); ++i)
    {
        if (i < jacobsthal.size())
            index = jacobsthal[i];
        else
            index = i;
        if (index >= small.size()) index = small.size();
        insertIntoSorted(small, large[i]);
    }
    container = small;
}

template <typename Container>
void printContainer(const Container& container)
{
    std::cout << "[ ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename Container>
double measureSortTime(Container& container)
{
    struct timeval start, end;
    gettimeofday(&start, NULL);
    //clock_t start = clock();
    fordJohnsonSort(container);
    gettimeofday(&end, NULL);
    long seconds = end.tv_sec - start.tv_sec;
    long microseconds = end.tv_usec - start.tv_usec;
    if (microseconds < 0)
    {
        seconds -= 1;
        microseconds += 1000000;
    }
    double elapsed = microseconds;
    //clock_t end = clock();
    //return static_cast<double>(end - start) / CLOCKS_PER_SEC;
    return elapsed;
}

double  sortListVector(int argc, char *argv[])
{
    std::vector<int> list;

    for (int i = 1; i < argc; i++)
    {
        int num = myAtoi(argv[i]);
        if (num != 0 || argv[i][0] == '0')
            list.push_back(num);
    }
    double time = measureSortTime(list);
    std::cout << "After w/ std::vector ";
    printContainer(list);
    return time * 1000.0;
    
}

double  sortListDeque(int argc, char *argv[])
{
    std::deque<int> list;
    for (int i = 1; i < argc; i++)
    {
        int num = myAtoi(argv[i]);
        if (num != 0 || argv[i][0] == '0')
            list.push_back(num);
    }
    double time = measureSortTime(list);
    std::cout << "After w/ std::deque  ";
    printContainer(list);
    return time * 1000.0;
}

void    PmergeMe::sortList(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
        myAtoi(argv[i]);
    std::cout << "\nBefore : [ ";
    for (int i = 1; i < argc; i++)
        std::cout << argv[i] << " ";
    std::cout << "]\n" << std::endl;
    
    double v_time = sortListVector(argc, argv);
    double d_time = sortListDeque(argc, argv);
    std::cout << "\nTime past:\n[std::vector]: " << v_time << " ms" << std::endl;
    std::cout << "[std::deque]: " << d_time << " ms" << std::endl;
}