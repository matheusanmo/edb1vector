#include <iostream>
using std::cout;
using std::endl;

#include "iterator.h"

namespace sc {
  template<typename T>
  class vector {
    public:
      //=== Aliases
      using value_type          = T;
      using size_type           = size_t;
      using pointer             = value_type*;
      using reference           = value_type&;
      using const_reference     = const value_type&;
      using iterator_type       = iterator<T>;
      using const_iterator_type = iterator<const T>;

      //=== Membros especiais
      // default constructor (lista vazia)
      vector(void);
      // tamanho `size` contendo apenas T{}
      explicit vector(size_type size = 0);
      // a partir do range [first,last)
      template<typename InputIterator>
      vector(InputIterator first, InputIterator last);
      // copy constructor, deep copy `other`
      vector(const vector& other);
      // constroi a partir da initializer list
      vector(std::initializer_list<T> ilist);
      // destrutor (lembrar de deletar)
      ~vector();
      // copy assignment operator
      vector& operator=(const vector& other);
      // substitui conteudo deste vetor pelo conteudo da ilist
      vector& operator=(std::initializer_list<T> ilist);

    private:
      size_type m_size;     // quantidade de elementos
      size_type m_capacity; // capacidade alocada
      pointer   m_data;
  }; //class vector

  template<typename T>
  vector<T>::vector(void) {
      m_size     = 0;
      m_capacity = 0;
      m_data     = nullptr;
  }

  template<typename T>
  vector<T>::vector(size_type size): vector{} {
      m_data     = new value_type[size];
      for (size_type i = 0; i < size; i++) {
        m_data[i] = value_type{};
      }
      m_size     = size;
      m_capacity = size;
  }



} // namespace sc

int main() { // int argc, char* argv[]) {
  int teste[5] = {0,1,2,3,4};
  int* p = teste;
  sc::iterator<int> it{p};
  std::cout << *it++ << endl;
  std::cout << *it++ << endl;
  std::cout << *it++ << endl;
  std::cout << *it++ << endl;

  return 0;
}

