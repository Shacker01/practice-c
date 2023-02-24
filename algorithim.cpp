#include<algorithm>
template<typename Type>
class Binary_node{
    protected:
        Type node_value;
        Binary_node *p_left_tree;
        Binary_node *p_right_tree;

    public:
        Binary_node(Type const &);

        Type_value() const;
        Binary_node *left() const;
        Binary_node *right() const;

        bool is_leaf() const;
        int size() const;
        int height() const;
        void clear();
};