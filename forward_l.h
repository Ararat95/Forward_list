#ifndef FORWARD_L_H
#define FORWARD_L_H
#include <iostream>
namespace fwd
{

    template <typename T>
    class Forward_list
    {
    public:
        Forward_list () : head{nullptr} {}
        Forward_list (const Forward_list&);
        Forward_list (Forward_list&&);
        ~Forward_list ();
        Forward_list<T> operator = (const Forward_list<T>&);
        Forward_list<T> operator = (Forward_list<T>&&);
        Forward_list<T> operator + (const Forward_list<T>&);
    public:
        template <typename U>
        friend std::ostream& operator << (std::ostream& os, const Forward_list<U>& rhs)
        {
        os << '|';
            Node* tmp = rhs.head;
            while (tmp)
            {
                os << tmp->data <<' ';
                tmp = tmp->next;
            }
            os << '|';
            return os;
        }
    public:
        T front ();
        T back ();
        void insert (int, T);
        void push_front (T);
        void push_back (T);
        void clear ();
        void remove_at (int);
    private:
        struct Node
        {
            Node* next = nullptr;
            T data;            
        }* head;
    };    
};

#endif//FORWARD_L_H