#include "forward_l.h"
template <typename T>
fwd::Forward_list<T>::Forward_list (const Forward_list<T>& src) : head{nullptr}
{
    if (src.head != nullptr)
    {
        Node* n_node = new Node();
        head = n_node;
        Node* tmp = src.head;
        while (tmp)
        {
            if (tmp->next == nullptr)
            {
                n_node->data = tmp->data;
                n_node->next = nullptr;
                break;                
            }
            n_node->next = new Node();
            n_node->data = tmp->data;
            n_node = n_node->next;
            n_node->next = nullptr;
            tmp = tmp->next;
        }
    }
}

template <typename T>
void fwd::Forward_list<T>::clear ()
{
    Node* tmp = head;
    while (tmp)
    {
        tmp = tmp->next;
        delete head;
        head = tmp;
    }
    head = nullptr;
    tmp = nullptr;
}

template <typename T>
fwd::Forward_list<T>::Forward_list (Forward_list&& src) : head {nullptr}
{
    if (src.head)
    {
        head = src.head;
        src.head = nullptr;
    }
}

template <typename T>
fwd::Forward_list<T>::~Forward_list ()
{
    clear();
}

template <typename T>
fwd::Forward_list<T> fwd::Forward_list<T>::operator = (const Forward_list<T>& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if (head)
    {
        clear();
    }
    if (rhs.head)
    {
        Node* n_node = new Node();
        head = n_node;
        Node* tmp = rhs.head;
        while (tmp)
        {
            if (tmp->next == nullptr)
            {
                n_node->data = tmp->data;
                n_node->next = nullptr;
                break;                
            }
            n_node->next = new Node();
            n_node->data = tmp->data; 
            n_node = n_node->next;
            tmp = tmp->next;   
        }
    }
    
    return *this;
}

template <typename T>
fwd::Forward_list<T> fwd::Forward_list<T>::operator = (Forward_list<T>&& rhs)
{
    if (this == &rhs)
    {
        return *this;
    }
    if(head)
    {
        clear();
    }
    head = rhs.head;
    rhs.head = nullptr;
    return *this;
}

template <typename T>
fwd::Forward_list<T> fwd::Forward_list<T>::operator + (const Forward_list<T>& rhs)
{
    Forward_list<T> tmp;
    Node* n_tmp = new Node(); 
    tmp.head = n_tmp;
    Node* m_tmp = head;
    Node* r_tmp = rhs.head;
    while (m_tmp || r_tmp)
    {   
        if (!m_tmp)
        {
            if (r_tmp->next == nullptr)
            {
                n_tmp->data = r_tmp->data;
                n_tmp->next = nullptr;
                break;   
            }
            n_tmp->next = new Node();
            n_tmp->data = r_tmp->data;
            n_tmp = n_tmp->next;
            r_tmp = r_tmp->next;    
        }
        else if (!r_tmp)
        {
            if (m_tmp->next == nullptr)
            {
                n_tmp->data = m_tmp->data;
                n_tmp->next = nullptr;
                break;   
            }
            n_tmp->next = new Node();
            n_tmp->data = m_tmp->data;
            n_tmp = n_tmp->next;
            m_tmp = m_tmp->next;
        }
        else
        {
            n_tmp->next = new Node();
            n_tmp->data = m_tmp->data + r_tmp->data;
            n_tmp = n_tmp->next;
            m_tmp = m_tmp->next;
            r_tmp = r_tmp->next;
        }
    }
    return tmp;
}

template <typename T>
T fwd::Forward_list<T>::front ()
{
    if (!head)
    {
        return -1;
    }
    return head->data;
}

template <typename T>
T fwd::Forward_list<T>::back ()
{
    Node* tmp = head;
    while (tmp)
    {
        if(tmp->next == nullptr)
        {
            return tmp->data;
        }
        tmp = tmp->next;
    }
    return -1;
}

template <typename T>
void fwd::Forward_list<T>::push_back (T elem)
{
    if (!head)
    {
        head = new Node();
        head->data = elem;
        head->next = nullptr;
        return;
    }
    Node* tmp = head;
    while (tmp)
    {
        if(tmp->next == nullptr)
        {
            tmp->next = new Node();
            tmp = tmp->next;
            tmp->data = elem;
            tmp->next = nullptr;
            return;
        }
        tmp = tmp->next;
    }
}

template <typename T>
void fwd::Forward_list<T>::push_front (T elem)
{
    if (!head)
    {
        head = new Node();
        head->data = elem;
        head->next = nullptr;
        return;
    }

    Node* tmp = new Node();
    tmp->data = elem;
    tmp->next = head;
    head = tmp;
}

template <typename T>
void fwd::Forward_list<T>::insert (int index, T elem)
{
    if (!head)
    {
        return;
    }
    int i = 1;
    if (index == 0)
    {
        push_front(elem);
        return;
    }
    Node* tmp = head->next;
    Node* tmp_2 = head;
    while (tmp)
    {
        if (i == index)
        {
            break; 
        }
        ++i;
        tmp = tmp->next;
        tmp_2 = tmp_2->next;
    }
    if (!tmp && tmp_2)
    {
        push_back(elem);
        return;
    }
    else if (!tmp && !tmp_2)
    {
        return;
    }
    else if (tmp && tmp_2)
    {
        Node* tmp_3 = new Node();
        tmp_3->data = elem;
        tmp_3->next = tmp;
        tmp_2->next = tmp_3;
    }
}

template <typename T>
void fwd::Forward_list<T>::remove_at (int index)
{
    if (!head)
    {
        return;
    }
    if (index == 0)
    {
        Node* tmp = head;
        head = head->next;
        delete tmp;
        return;
    }
    Node* tmp = head->next;
    Node* tmp_prev = head;
    int i = 1;
    while (tmp)
    {
        if (i == index)
        {
            Node* tmp_3 = tmp;
            tmp_prev->next = tmp->next;
            delete tmp_3;
            return;
        }
        ++i;
        tmp = tmp->next;
        tmp_prev = tmp_prev->next;
    }
}