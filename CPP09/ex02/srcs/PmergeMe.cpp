/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lle-pier <lle-pier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 12:51:57 by lle-pier          #+#    #+#             */
/*   Updated: 2024/12/09 17:10:01 by lle-pier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/PmergeMe.hpp"

// print list | ok
// afficher les entiers tries | 
// calcul du temps passe | ok

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

// Fonction pour calculer les nombres de Jacobsthal
template <typename Container>
Container generateJacobsthalSequence(int size) {
    Container jacobsthal;
    int a = 0, b = 1; // Jacobsthal de base
    jacobsthal.push_back(a);
    if (size > 1) jacobsthal.push_back(b);
    for (int i = 2; i < size; ++i) {
        int next = b + 2 * a; // Jacobsthal(n) = Jacobsthal(n-1) + 2*Jacobsthal(n-2)
        jacobsthal.push_back(next);
        a = b;
        b = next;
    }
    return jacobsthal;
}

// Insère un élément dans un container trié à la bonne position
template <typename Container>
void insertIntoSorted(Container& sortedList, typename Container::value_type value) {
    typename Container::iterator it = sortedList.begin();
    while (it != sortedList.end() && *it < value) {
        ++it;
    }
    sortedList.insert(it, value); // Insère dans l'ordre croissant
}

// Implémentation de Ford-Johnson Sort
template <typename Container>
void fordJohnsonSort(Container& container) {
    if (container.size() < 2) return; // Rien à trier si la taille est < 2

    // Étape 1 : Trier les paires
    Container small, large;
    for (size_t i = 0; i + 1 < container.size(); i += 2) {
        if (container[i] < container[i + 1]) {
            small.push_back(container[i]);
            large.push_back(container[i + 1]);
        } else {
            small.push_back(container[i + 1]);
            large.push_back(container[i]);
        }
    }
    if (container.size() % 2 != 0) { // Si la taille est impaire, ajouter le dernier élément à la fin
        large.push_back(container.back());
    }

    // Étape 2 : Trier les "small" avec std::sort (ou un autre tri récursif si nécessaire)
    std::sort(small.begin(), small.end());

    // Étape 3 : Insérer les "large" dans la liste triée (en utilisant les indices Jacobsthal)
    Container jacobsthal = generateJacobsthalSequence<Container>(large.size());
    for (size_t i = 0; i < large.size(); ++i) {
        size_t index = (i < jacobsthal.size()) ? jacobsthal[i] : i; // Indice basé sur Jacobsthal
        if (index >= small.size()) index = small.size();        // Éviter un dépassement
        insertIntoSorted(small, large[i]);
    }

    // Remplacer le container original par le résultat trié
    container = small;
}

// Fonction pour afficher un container
template <typename Container>
void printContainer(const Container& container) {
    std::cout << "[ ";
    for (typename Container::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << "]" << std::endl;
}

template <typename Container>
double measureSortTime(Container& container) {
    clock_t start = clock();  // Commence la mesure du temps
    fordJohnsonSort(container);
    clock_t end = clock();  // Fin de la mesure du temps
    return static_cast<double>(end - start) / CLOCKS_PER_SEC;  // Temps en secondes
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
    std::cout << "[std::list]: " << d_time << " ms" << std::endl;
}