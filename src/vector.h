#ifndef VECTOR_H
#define VECTOR_H

#include <stdlib.h>
using ::size_t;

namespace sc {
  template <typename T>
    class vector {
      public:
        using size_type       = unsigned long;
        using value_type      = T;
        using pointer         = value_type*;
        using reference       = value_type&;
        using const_reference = const value_type&; // (poderia ser `const reference`?)
        using iterator        = iterator<T>;
        using const_iterator  = iterator<const T>;

        //=== Membros especiais
        explicit vector(size_type n = 0);
        template <typename Iter>
        vector(Iter first, Iter last) {
          // devemos declarar aqui ou no .cpp o corpo desta funcao?
          // esperar ate implementarmos funcoes de iterators e []
          } 
        vector(const vector& other); // vector<T>? esperar p implementar em termos de vector(Iter first, Iter lasst)
        vector(std::initializer_list<T> ilist);
        virtual ~vector(void);
        vector& operator=(const vector& other);
        vector& operator=(std::initializer_list<T> ilist);

      private:
        T *m_storage;
    };


  vector::vector(size_type n) {
    m_storage = new value_type[n];
  }

  vector::~vector(void) {
    delete[] m_storage;
  }


}

