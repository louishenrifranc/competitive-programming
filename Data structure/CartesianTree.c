#include <cstdlib>
#include <iostream>
#include <fstream>
#include <memory>
#include <time.h>


/*****************************************************************************
 *                        C a r t e s i a n   T r e e                        *
 *****************************************************************************/
namespace CT
{
    // ============================= Node structure =============================
    template <typename K, typename P>
    class node_t
    {
        public:
            using link = std::shared_ptr<node_t<K, P>>;

        public:
            node_t(const K& key, const P& priority)
            : _key     (key)
            , _priority(priority)
            , _father  (nullptr)
            , _left    (nullptr)
            , _right   (nullptr)
            , _size    (1)
            , _flags   (0)
            {
            }

            P&              priority  ()       { return _priority; }
            const P&        priority  () const { return _priority; }
            K&              key       ()       { return _key;      }
            const K&        key       () const { return _key;      }
            link&           father    ()       { return _father;   }
            const link&     father    () const { return _father;   }
            link&           left      ()       { return _left;     }
            const link&     left      () const { return _left;     }
            link&           right     ()       { return _right;    }
            const link&     right     () const { return _right;    }
            uint64_t&       size      ()       { return _size;     }
            const uint64_t& size      () const { return _size;     }

            void recalc()
            {
                size() = 1;
                if (left())  size() += left()->size();
                if (right()) size() += right()->size();
            }

        private:
            K        _key;
            P        _priority;
            link     _father;
            link     _left;
            link     _right;
            uint64_t _size;
            uint64_t _flags;
    };

    // =============================== Node type ================================
    template <typename K, typename P> using node  = typename node_t<K,P>::link;

    // ================================ Methods =================================
    template <typename K, typename P> node<K,P> merge(node<K,P>, node<K,P>);
    template <typename K, typename P> void      split(node<K,P>, node<K,P>&, node<K,P>&, const K& k);
    template <typename K, typename P> void      print(node<K,P>);

    // ================================= Merge ==================================
    template <typename K, typename P>
    node<K,P> merge(node<K,P> left, node<K,P> right)
    {
        if (!left ) return right;
        if (!right) return left;
        if (left->priority() > right->priority())
        {
            left->size() += right->size();
            node<K,P> tmp = merge<K,P>(left->right(), right);
            tmp->father() = left;
            left->right() = tmp;
            return left;
        }
        else
        {
            right->size() += left->size();
            node<K,P> tmp = merge<K,P>(left, right->left());
            tmp->father() = right;
            right->left() = tmp;
            return right;
        }
    }

    // ================================= Split ==================================
    template <typename K, typename P>
    void split(node<K,P> root, node<K,P>& left, node<K,P>& right, const K& k)
    {
        if (!root)
        {
            left  = nullptr;
            right = nullptr;
            return;
        }
        else if (root->key() < k)
        {
            split<K,P>(root->right(), root->right(), right, k);
            root->recalc();
            left = root;
        }
        else
        {
            split<K,P>(root->left(), left, root->left(), k);
            root->recalc();
            right = root;
        }
    }

    // ================================= Insert =================================
    template <typename K, typename P>
    void insert(node<K,P>& root, const K& k, const P& p)
    {
        node<K,P> l, r, tmp = std::make_shared<node_t<K,P>>(k, p);
        split<K,P>(root, l, r, k);
        root = merge<K,P>(l, tmp);
        root = merge<K,P>(root, r);
    }

    // ================================= Remove =================================
    template <typename K, typename P>
    void remove(node<K,P>& root, const K& k)
    {
        node<K,P> l, c, r;
        split<K,P>(root, l, r, k);
        split<K,P>(r,    c, r, k+1);
        root = merge<K,P>(l, r);
    }

    // ================================= Remove =================================
    template <typename K, typename P>
    bool exists(node<K,P> root, const K& k)
    {
        if (!root)
            return false;
        else if (root->key() == k)
            return true;
        else if (root->key() > k)
            return exists<K,P>(root->left(), k);
        else
            return exists<K,P>(root->right(), k);
    }

    template <typename K, typename P>
    bool next(node<K,P> root, const K& key, K& result)
    {
        if (!root)
        {
            return false;
        }
        else if (root->key() <= key)
        {
            return next<K,P>(root->right(), key, result);
        }
        else
        {
            if (!next<K,P>(root->left(), key, result))
                result = root->key();
            return true;
        }
    }

    template <typename K, typename P>
    bool prev(node<K,P> root, const K& key, K& result)
    {
        if (!root)
        {
            return false;
        }
        else if (root->key() >= key)
        {
            return prev<K,P>(root->left(), key, result);
        }
        else
        {
            if (!prev<K,P>(root->right(), key, result))
                result = root->key();
            return true;
        }
    }


    // ================================= Print ==================================
    template <typename K, typename P>
    void print(node<K,P> root, std::ostream& out)
    {
        if (root)
        {
            out << "(";
            if (root->left() ) print<K,P>(root->left(),  out);
            out << root->key();
            if (root->right()) print<K,P>(root->right(), out);
            out << ")";
        }
    }

};








/*****************************************************************************
 *                                  M a i n                                  *
 *****************************************************************************/
int main()
{
    srand(time(0));

    CT::node<int64_t, uint64_t> ct = nullptr;

    std::ifstream in("bst.in");
    std::ofstream out("bst.out");

    std::string s;
    int64_t     k;

    while(in >> s >> k)
    {
        // std::cout << "-------------------" << std::endl;
        // CT::print<int64_t,uint64_t>(ct, std::cout);
        // std::cout << std::endl;
        // std::cout << "-------------------" << std::endl;

        switch(s[0])
        {
            case 'i':
                CT::insert<int64_t,uint64_t>(ct, k, rand());
                break;
            case 'd':
                CT::remove<int64_t,uint64_t>(ct, k);
                break;
            case 'e':
                if (CT::exists<int64_t,uint64_t>(ct, k)) out << "true"  << std::endl;
                else                                     out << "false" << std::endl;
                break;
            case 'p':
            {
                int64_t r;
                if (CT::prev<int64_t,uint64_t>(ct, k, r)) out << r      << std::endl;
                else                                      out << "none" << std::endl;
                break;
            }
            case 'n':
            {
                int64_t r;
                if (CT::next<int64_t,uint64_t>(ct, k, r)) out << r      << std::endl;
                else                                      out << "none" << std::endl;
                break;
            }
        }

    }

    return 0;
}
