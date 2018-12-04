#include <iostream>

template< typename T >
class List;

template< typename T >
bool operator==(const List< T > &, const List< T > &);
template< typename T >
bool operator!=(const List< T > &, const List< T > &);

template< typename T >
class List
{
    struct Node
    {
        Node(const T &data):
        m_data(data),
        m_next(),
        m_prev()
        {
        }

        T m_data;
        Node *m_next;
        Node *m_prev;
    };

public:
    List():
    m_head(),
    m_tail(),
    m_size()
    {
    }

    List(const List &source):
    m_head(),
    m_tail(),
    m_size()
    {
        Node *i = source.m_head;

        while (i != 0)
        {
            push_back(i->m_data);

            i = i->m_next;
        }
    }

    ~List()
    {
        clear();
    }

    size_t size() const
    {
        return m_size;
    }

    bool is_empty() const
    {
        return m_size == 0;
    }

    void clear()
    {
        while (m_size != 0)
            pop_back();
    }

    void push_back(const T &data)
    {
        Node *add_elem = new Node (data);

        if (m_size == 0)
        {
            m_head = add_elem;
        }
        else
        {
            m_tail->m_next = add_elem;
            add_elem->m_prev = m_tail;
        }

        m_tail = add_elem;

        ++m_size;
    }

    T pop_back()
    {
        if (m_size == 0)
            return T ();

        T ret_elem = m_tail->m_data;
        Node *new_tail = m_head == m_tail ? 0 : m_tail->m_prev;

        delete m_tail;

        if (m_head == m_tail)
            m_head = 0;

        m_tail = new_tail;

        --m_size;

        return ret_elem;
    }

    void push_front(const T &data)
    {
        Node *add_elem = new Node (data);

        if (m_size == 0)
        {
            m_tail = add_elem;
        }
        else
        {
            m_head->m_prev = add_elem;
            add_elem->m_next = m_head;
        }

        m_head = add_elem;

        ++m_size;
    }

    T pop_front()
    {
        if (m_size == 0)
            return T ();

        T ret_elem = m_head->m_data;
        Node *new_head = m_head == m_tail ? 0 : m_head->m_next;

        delete m_head;

        if (m_head == m_tail)
            m_tail = 0;

        m_head = new_head;

        --m_size;

        return ret_elem;
    }

    friend bool operator==< >(const List< T > &left, const List< T > &right);
    friend bool operator!=< >(const List< T > &left, const List< T > &right);

    List &operator=(const List &source)
    {
        if (this != &source)
        {
            clear();

            Node *i = source->m_head;

            while (i != source->m_tail)
            {
                push_back(i->m_data);

                i = i->m_next;
            }
        }

        return *this;
    }

private:
    Node *m_head;
    Node *m_tail;
    size_t m_size;
};

template< typename T >
bool operator==(const List< T > &left, const List< T > &right)
{
    if (left.m_size != right.m_size)
        return false;

    list< T >::Node *p_left = left.m_head;
    List< T >::Node *p_right = right.m_head;

    while (p_left != left.m_tail)
    {
        if (p_left->m_data != p_right->m_data)
            return false;

        p_left = p_left->m_next;
        p_right = p_right->m_next;
    }

    return true;
}

template< typename T >
bool operator!=(const List< T > &left, const List< T > &right)
{
    return !(left == right);
}
