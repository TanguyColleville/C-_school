#pragma once
#include <array>
#include <iostream>



namespace matrix{

// forward declaration 
template< int n, int m,typename Scalar>// pour dire qu'on va parler d'1 class matrix in the future
class Matrix;// qui est un template

template< int n, int m,typename Scalar>// os stream est donc une fonction 
// template de fait parce qu'elle s'applique sur un objet d'une classe qui est un template. 
std::ostream& operator<<(std::ostream& os, const Matrix<n,m,Scalar>& ma_matrice);// on va recevoir une ref 
//d'un objet matrix qu'on ne modifie pas

template< int n, int m,typename Scalar=double>
class Matrix {
    
    public : 
    using scalar_type=Scalar;

    Matrix(Scalar value=0);// par défaut 0 
    Matrix(const std::array<std::array<Scalar,m>,n>& tab);// on ne change pas tab et on le copie pas
    ~Matrix();

    Scalar& get_coords(int x, int y) const;
    void set_coords(int x,int y,Scalar value);

    Scalar& operator[](const std::pair<int,int>& ma_liste);
    const Scalar& operator[](const std::pair<int,int>& ma_liste) const ;

    Matrix<n,m,Scalar> operator+=( const Matrix<n,m,Scalar>& matrice_2) ;// virer const si pauvre version

    Matrix<n,m,Scalar> operator+( Matrix<n,m,Scalar>& matrice_2) const;// virer const sur la martrice si pauvre version


    template<int z> // le dimension de la matrice de sortie va être imposée par la matrice2 
    Matrix<n,z,Scalar> operator*(Matrix<m,z,Scalar>& matrice_2);

    std::array<std::array<Scalar,m>,n> get_matrix();// accesseur on ne modifie pas this 


    // on ne va pas changerv this ni la matrice d'entrée qu'on passe par ref pour ne pas la copier

    private : 
    std::array<std::array<Scalar,m>,n> m_matrix;
    // operator est un template qui va dependre du type de matrice
    friend std::ostream& operator<< <n,m,Scalar>(std::ostream& os,const Matrix<n,m,Scalar>& ma_matrice);
    // pour qu'il puisse prendre les coeffs
};


template<int n, int m,typename Scalar>
Matrix<n,m,Scalar>::Matrix(const std::array<std::array<Scalar,m>,n>& tab):m_matrix(tab){};


template<int n, int m,typename Scalar> // int c'est comme mettre typename sauf qu'on sait que c'est int 
Matrix<n,m,Scalar>::Matrix(Scalar value){
    for(auto& line : m_matrix)
        for(auto& elem :line)
            elem=value;
}

template<int n, int m,typename Scalar>
Matrix<n,m,Scalar>::~Matrix(){}// les array se détruisent tout seul


template<int n, int m,typename Scalar>
Scalar& Matrix<n,m,Scalar>::get_coords(int x , int y) const {
    return m_matrix[x][y];
}


template<int n, int m,typename Scalar>
void Matrix<n,m,Scalar>::set_coords(int x, int y, Scalar value){
    m_matrix[x][y]=value;
}

// renvoyer une ref c'est malin pour lire ou affecter une val à la case mémoire
template<int n, int m,typename Scalar>
Scalar& Matrix<n,m,Scalar>::operator[](const std::pair<int,int>& ma_liste){
    return m_matrix[std::get<0>(ma_liste)][std::get<1>(ma_liste)];
}// on renvoie une ref de la case qui nous intéresse ==> r as w 

template<int n, int m,typename Scalar>
std::ostream& operator<<(std::ostream& os,const Matrix<n,m,Scalar>& ma_matrice){
        for(auto& line : ma_matrice.m_matrix)
        {
            for(auto& elem :line)
            {
                os<<elem;
            }
            os<<std::endl;
        }
            return os;
}


// version du pauvre faut pas mettre les const
/*
template<int n , int m, typename Scalar> 
Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+=( Matrix<n,m,Scalar>& matrix_2){
    for( int i = 0 ; i<n ; i++){// ça fait des multiplications poru suater la ligne 
        for(int j=0; j<m;j++){
            (*this)[{i,j}]+=matrix_2[{i,j}];// ça marche si const mais nul 
        }
    }
    return *this;
}
*/



// version panache 
template<int n , int m , typename Scalar> 
Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+=(const Matrix<n,m,Scalar>& matrix_2){
        auto line_dst = m_matrix.begin();
        auto line_src = matrix_2.m_matrix.begin();
        auto line_dst_end = m_matrix.end();
        while (line_dst != line_dst_end){
            auto col_dst = line_dst->begin();// on prend le début de la ligne de matrix 2
            auto col_src = (line_src++)->begin();//  on prend le début de la ligne de this et on incrémente la ligne
            auto col_dst_end = (line_dst++)->end(); // définit notre condition pour le seoncd while qu'on incrémente 
            // à chaque tour de la première boucle while 

            while (col_dst!=col_dst_end)// tant qu'on n'arrive pas au bout d'une ligne 

            *(col_dst++) += *(col_src++); // on change affecte nos valeurs puis passe à l'élément suivant dans la ligne
    
        }
//    for ( auto ptr_s = std::make_pair(m_matrix.begin(),matrix_2.m_matrix.begin());
//    std::tie(std::get<0>(ptr_s),std::get<1>(ptr_s)) != std::tie(m_matrix.end(),matrix_2.m_matrix.end()); ++std::get<0>(ptr_s), ++std::get<1>(ptr_s))
    return *this;
}



template<int n , int m, typename Scalar> 
Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+(Matrix<n,m,Scalar>& matrice_2) const {
    Matrix<n,m,Scalar> resultat(*this); // on fait une copie de this 
    resultat+=matrice_2; 
    return resultat; 
}

template<int n , int m , typename Scalar> 
std::array<std::array<Scalar,m>,n> Matrix<n,m,Scalar>::get_matrix(){
    return m_matrix;
}

template<int n, int m ,typename Scalar>
template<int z>// la dim de sortie 
Matrix<n,z,Scalar> Matrix<n,m,Scalar>::operator*(Matrix<m,z,Scalar>& matrice_2){
    Matrix<n,z,Scalar> resultat;// on instance que resultat va être un objet matrix n z Scalar, vide pour le moment

    if constexpr(m==1){//si c'est un vecteur ligne l'autre est un colonne donc 
    Scalar sum(0);
    for(auto& elem1 : m_matrix){
        for(auto& elem2 : matrice_2.get_matrix()){
            sum+= elem1*elem2;
        }
    }
    resultat.m_matrix=sum; 
    }

    else {
    
    
    auto line_a = m_matrix.begin();
    auto line_b = matrice_2.get_matrix().begin();
    auto line_res_end = resultat.get_matrix().end();// condition d'arrêt sur la ligne de C
    auto line_res = resultat.get_matrix().begin();

    while (line_res != line_res_end){ // on se promène dans les lignes de C 

        auto col_res = line_res->begin();
        auto col_res_end = (line_res++)->end();// je change ma condition du 1 while ici  
        
        auto col_b = (line_b)->begin();

        while (col_res!=col_res_end){
            Scalar sum(0); 

            // auto col_b = (line_b)->begin()+(col_res_end-col_res); // b 0,0 et maintenant je veux faire varier la ligne pour une colonne fixée je suis eu 
            // // là c'est pas un begin() que je veux c'est un rang j 

            auto col_a = (line_a)->begin();// a i,0
            auto col_a_end = (line_a++)->end();// a i ,m

            while (col_a != col_a_end){// tant qu'on n'est pas au bout de la ligne de a[i,:] 


                sum += *(col_a++) *  *(col_b);// passe à la colonne suivante pour a 
                line_b++;// passe à la lgine suivante pour b 
            }
            
            *(col_res++)=sum;// je change la condi du deuxième while 
            col_b++;
        
        }
    }
    }
    return resultat; 
}


}