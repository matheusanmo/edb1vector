#include <iostream>
using std::cout;
using std::endl;

#include "iterator.h"


namespace sc {
    template<typename T>
    T* copy_array(const T*& array, size_t size, T*& new_array = nullptr) {
        if (new_array = nullptr) {
            new_array = new T[size];
        }
        for (size_t i = 0; i < size; i++) {
            new_array[i] = array[i];
        }
        return new_array;
    }

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
            // default constructor (lista vazia) OK
            vector(void);
            // tamanho `size` contendo apenas T{} OK
            explicit vector(size_type size = 0);
            // a partir do range [first,last) OK
            template<typename InputIterator>
            vector(InputIterator first, InputIterator last) {
                auto index = first;
                size_type size = 0;
                while (index != last) {
                    size += 1;
                    index++;
                }
                size_type i = 0;
                while (first != last) {
                    m_data[i] = *first++;
                }
            }
            // copy constructor, deep copy `other` OK
            vector(const vector& other);
            // constroi a partir da initializer list
            vector(std::initializer_list<T> ilist);
            // destrutor OK
            ~vector();
            // copy assignment operator OK
            vector& operator=(const vector& rhs);
            // substitui conteudo deste vetor pelo conteudo da ilist
            vector& operator=(std::initializer_list<T> ilist);

            //=== Operações comuns
            // acessor tamanho OK
            size_type size(void) const;
            // transforma vetor em vetor vazio OK
            void clear(void);
            // insere elemento na cauda do vetor
            void push_back(const value_type& value);
            // apaga elemento final da lista
            void pop_back(void);
            // retorna elemento final
            const value_type& back() const;
            // retorna elemento primeiro
            const value_type& front() const;
            // substitui conteudo do vector por `count` copias de `value`
            void assign(size_type count, const value_type& value);

            //=== Operações de arrays dinâmicos
            // acesso a indice sem bounds-checking
            reference operator[](size_type pos);
            // acesso a indice com bounds-checking
            reference at(size_type pos);
            // capacidade real do array interno
            size_type capacity();
            // expande m_capacity se new_cap > m_capacity
            void reserve(size_type new_cap);
            // realoca para manter size=capacity
            void shrink_to_fit();

        private:
            size_type m_size;     // quantidade de elementos
            size_type m_capacity; // capacidade alocada
            pointer   m_data;     // array interno dinamico

            // nao inicializa elementos, nao deleta m_data, faz new[] OK
            void init_data(size_type size); 

    }; //class vector

    template<typename T>
        void vector<T>::init_data(vector::size_type size) {
            if (size == 0) {
                m_data = nullptr;
            } else {
                m_data = new value_type[size];
            }
            m_size     = size;
            m_capacity = size;
            return;
        }

    template<typename T>
        vector<T>::vector(void) {
            init_data(0);
        }

    template<typename T>
        vector<T>::vector(size_type size) {
            init_data(size);
            for (size_type i = 0; i < size; i++) {
                m_data[i] = value_type{};
            }
        }

    template<typename T>
        vector<T>::vector(const vector& other) {
            // deep copy
            init_data(other.m_size);
            for (size_type i = 0; i < m_size; i++) {
                m_data[i] = other.m_data[i];
            }
        }

    template<typename T>
        vector<T>::vector(std::initializer_list<T> ilist) {
            // TODO
            init_data(0);
        }

    template<typename T>
        vector<T>::~vector() {
            m_capacity = 0;
            m_size     = 0;
            delete[] m_data;
        }

    template<typename T>
    vector<T>& vector<T>::operator=(const vector& rhs) {
        // copy assignment operator deve se preocupar com cleanup do lhs se necessario
        if (m_capacity < rhs.m_size) {
            clear();
            init_data(rhs.m_size);
        } else {
            size = rhs.m_size;
        }
        for (size_type i = 0; i < size; i++) {
            m_data[i] = rhs.m_data[i];
        }
        return *this;
    }

    template<typename T>
    vector<T>& vector<T>::operator=(std::initializer_list<T> ilist) {
        // TODO
        return *this;
    }

    template<typename T>
    typename vector<T>::size_type vector<T>::size(void) const {
        return m_size;
    }

    template<typename T>
    void vector<T>::clear(void) {
        delete[] m_data;
        init_data(0);
    }

    template<typename T>
    void vector<T>::push_back(const value_type& value) {
        if (m_size + 1 > m_capacity) {
            // realocar
        }
    }

    template<typename T>
    void vector<T>::reserve(size_type new_cap) {
        if (new_cap <= m_capacity) {
            return;
        }
        pointer data_new = new value_type[new_cap];
        copy_array<value_type>(m_data, m_size, data_new);
        delete[] m_data;
        m_data = data_new;
        return;
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

