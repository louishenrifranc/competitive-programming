#include <bits/stdc++.h>
#include <memory>
/**
*   Classe représentant un AVL Tree
**/
namespace Tree
{
/// Classe représentant un noeud
template<typename T>
class Node
{

public:
    // Constructeur par défaut
    Node():
        m_height (1),
        m_left(nullptr),
        m_right(nullptr)
    {
    }

    ~Node();
public:
    // Getter constant et normaux + setter
    inline const T &key() const
    {
        return this->m_key;
    }
    inline const Node<T> *left() const
    {
        return this->m_left;
    }
    inline const Node<T> *right() const
    {
        return this->m_right;
    }
    inline const int &height() const
    {
        return this->m_height;
    }
    inline T key()
    {
        return this->m_key;
    }
    Node<T> *left()
    {
        return this->m_left;
    }
    Node<T> *right()
    {
        return this->m_right ;
    }
    inline int height()
    {
        return this->m_height;
    }
    inline void setKey(T key)
    {
        this->m_key=key;
    }
    inline void setLeft(Node *left)
    {
        this->m_left=left;
    }
    inline void setRight(Node *right)
    {
        this->m_right=right;
    }
    inline void setHeight(int height)
    {
        this->m_height=height;
    }
private:
    // Une clé
    T m_key;
    // Une hauteur
    int m_height;
    // Un fils gauche
    Node * m_left;
    // Un fils droit
    Node *m_right;

};



// Chercher si le noeud n'existe pas déja
template<typename T>
Node<T> *chercher(T key,Node<T> *root)
{
    if(root ==  nullptr )
        return nullptr;
    if(key > root->key())
        return chercher(key,root->right());
    else if(key < root->key())
        return chercher(key,root->left());
    else if (key == root->key())
        return root;

}



// Creer un nouveau noeud
template<typename T>
Node<T> * creerNoeud(T& key)
{
    Node<T> * noeud = new Node<T>();
    noeud->setKey(key);
    //  std::cerr << "Noeud cree"<<std::endl;
    return noeud;
}
template<typename T>
T max(const T &a,const T &b)
{
    return (a > b) ?  a : b;
}

// Recuperer la hauteur de l'arbre
template<typename T>
int hauteur(Node<T> *noeud)
{
    if(noeud == nullptr)
        return 0;
    return noeud->height();
}


// Recuperer la différence des hauteurs des deux fils
template<typename T>
int getBalance(Node<T> *noeud)
{
    if(noeud == nullptr)
        return 0;
    return hauteur(noeud->left())-hauteur(noeud->right());
}


/// Faire une rotation a gauche
template<typename T>
Node<T> *leftRotate(Node<T> * node)
{

    Node<T> *x= node->right();
    Node<T> *y = x->left();

    // Effectue la rotation
    x->setLeft(node);
    node->setRight(y);

    // Update les hauteurs
    node->setHeight(max(hauteur(node->left()),hauteur(node->right()))+1);
    x->setHeight(max(hauteur(x->left()),hauteur(x->right()))+1);
    std::cerr << "Rotation a gauche";
    return x;
}


/// Faire une rotation a droite
template<typename T>
Node<T> *rightRotate(Node<T> *node)
{
    Node<T> *x=node->left();
    Node<T> *y= x->right();

    // Effectue la rotation
    x->setRight(node);
    node->setLeft(y);

    node->setHeight(max(hauteur(node->left()),hauteur(node->right()))+1);
    x->setHeight(max(hauteur(x->left()),hauteur(x->right()))+1);
    std::cerr << "Rotation a droite"<<std::endl;
    return x;
}

/// Ajouter un noeud a l'arbre
template<typename T>
Node<T>* insererNoeudUtil(T key, Node<T> *root)
{

    int balance;
    // Arbre vide
    if(root == nullptr)
        return creerNoeud(key);
    // Ajouter a droite
    if(root->key() < key)
        root->setRight(insererNoeudUtil(key,root->right()));
    // Ajouter a gauche
    else
        root->setLeft(insererNoeudUtil(key,root->left()));

    // Mettre a jour la hauteurr
    root->setHeight(max(hauteur(root->right()),hauteur(root->left()))+1);

    // Difference de taille entre la gauche et la droite
    balance = getBalance(root);

    // Rotation de l'arbre
    if(balance > 1 && key > root->left()->key())
    {
        root->setLeft(leftRotate(root->left()));
        return rightRotate(root);
    }
    else if(balance < -1 && key > root->right()->key())
        return leftRotate(root);
    else if(balance > 1 && key < root->left()->key())
        return rightRotate(root);
    else if(balance <-1 && key < root->right()->key())
    {
        root->setRight(rightRotate(root->right()));
        return leftRotate(root);
    }

    // Si aucune rotation a éfféctuer
    return root;
}

/// Fonction qui vérifie si le noeud n'existe pas déja
template<typename T>
Node<T> * insererNoeud(T key,Node<T> *root)
{

    if(chercher(key,root) == nullptr)
        return insererNoeudUtil(key,root);
    else
        return root;
}

/// Référence universelle
template<typename T>
Node<T> * insererNoeud(T&& key,Node<T> *root)
{

    if(chercher(key,root) == nullptr)
        return insererNoeudUtil(key,root);
    else
        return root;
}

/// Affiche le parcours en largeur de l'arbre
template<typename T>
void BFS(Node<T> *root)
{
    std::queue< std::pair<int,Node<T> *> > q;
    q.push(std::pair<int,Node<T>* >(1,root));
    int level=0;
    while(!q.empty())
    {
        auto u=q.front();
        q.pop();
        if(level!= u.first)
        {
            level++;
            std::cout << std::endl << "Level "<<u.first<<" : ";
        }
        std::cout<<" "<<u.second->key();
        if(u.second->left() != nullptr) q.push(std::make_pair(u.first+1,u.second->left()));
        if(u.second->right() != nullptr) q.push(std::make_pair(u.first+1,u.second->right()));

    }
    std::cout << std::endl << std::endl;
}

/// Affiche le parcours en profondeur de l'arbre
template<typename T>
void DFS(Node<T> *root)
{
    if(root == nullptr)
        return;
    std::cout << root->key() << " ";
    DFS(root->left());
    DFS(root->right());
    return;
}

}
int main()
{
    using namespace Tree;
    uint32_t N;
    Node<int> *root=nullptr;
    srand(time(NULL));
    std::cout << "Nombre de valeurs a ajouter a l'arbre ";
    std::cin >> N;
    for(int i=0; i<N; i++)
    {
        root = insererNoeud(i,root);
    }
    // root = insererNoeud(a,root);
    // root = insererNoeud(b,root);
    // root = insererNoeud(c,root);
    // root = insererNoeud(d,root);

    //  root = insererNoeud(15,root);
    //  root = insererNoeud("aab",root);
    //  root = insererNoeud("abc",root);
    //  root = insererNoeud("baa",root);

    // Parcours en profondeur
    std::cout<< std::endl<<"Parcours en profondeur:"<<std::endl;
    DFS(root);

    // Parcours en largeur
    std::cout<< std::endl<<"Parcours en largeur:"<<std::endl;
    BFS(root);


    // Resultats coupe:
    std::cout << "Si je coupe sur l'arc a gauche de la racine,\n on a taille arbre gauche : " << root->left()->height() << " et la taille arbre droit : " << root->right()->height() + 1 /* pour la racine */ ;
    return 0;
}
