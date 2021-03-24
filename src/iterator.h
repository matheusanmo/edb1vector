#ifndef ITERATOR_H
#define ITERATOR_H

namespace sc {
  template<typename T>
  class iterator {
    public:
      //=== Aliases
      typedef T              value_type;
      typedef std::ptrdiff_t diff_t;
      typedef value_type*    pointer;
      typedef value_type&    reference;
      typedef std::bidirectional_iterator_tag iterator_category;

      //=== Membros especiais
      // TODO: como construir a partir de iterator do std? qual assinatura?
      // construtor a partir de ponteiro
      explicit iterator(const pointer& p);
      // construtor padrao vazio
      iterator(void);
      // copy constructor
      iterator(const iterator& rhs);
      // copy assignment operator
      iterator& operator=(const iterator& rhs);

      //=== Operadores
      // dereference operator
      reference operator*() const;
      // pre-increment operator (move e retorna referencia)
      iterator& operator++();
      // post-increment operator (cria copia, incrementa obj,  retorna copia)
      iterator& operator++(int n);
      // pre-decrement operator
      iterator& operator--();
      // post-decrement operator
      iterator& operator--(int n);
      // equal to
      bool operator==(const iterator& other) const;
      // not equal to
      bool operator!=(const iterator& other) const;

      //=== Funções friend
      // TODO: fazer funcionar funcoes friend
      // operador aritmetico +
      //friend iterator (::operator+)(const iterator& it, const diff_t& n);
      // operador aritmetico +
      //friend iterator ::operator+(const diff_t& n, const iterator& it);
      // operador aritmetico -
      //friend iterator ::operator-(const iterator& it, const diff_t& n);

    private:
      pointer m_current;
  }; // class iterator

  template<typename T>
  iterator<T>::iterator(const iterator::pointer& p) {
    m_current = p;
  }

  template<typename T>
  iterator<T>::iterator(void) {
    m_current = nullptr;
  }

  template<typename T>
  iterator<T>::iterator(const iterator& rhs) {
    m_current = rhs.m_current;
  }

  template<typename T>
  iterator<T>& iterator<T>::operator=(const iterator& rhs) {
    m_current = rhs.m_current;
    return *this;
  }

  template<typename T>
  typename iterator<T>::reference iterator<T>::operator*() const {
    // https://stackoverflow.com/questions/610245/where-and-why-do-i-have-to-put-the-template-and-typename-keywords
    return *m_current;
  }

  template<typename T>
  iterator<T>& iterator<T>::operator++() {
    m_current++;
    return *this;
  }

  template<typename T>
  iterator<T>& iterator<T>::operator++(int n) {
    if (n != 0) {
      // TODO
    }
    iterator* tmp = new iterator {*this};
    ++(*this);
    return *tmp;
  }

  template<typename T>
  iterator<T>& iterator<T>::operator--() {
    m_current--;
    return *this;
  }

  template<typename T>
  iterator<T>& iterator<T>::operator--(int n) {
    if (n != 0) {
      // TODO
    }
    iterator* tmp = new iterator {*this};
    --(*this);
    return *tmp;
  }

  template<typename T>
  bool iterator<T>::operator==(const iterator& other) const {
    return m_current == other.m_current;
  }

  template<typename T>
  bool iterator<T>::operator!=(const iterator& other) const {
    return m_current != other.m_current;
  }
} // namespace sc

#endif
