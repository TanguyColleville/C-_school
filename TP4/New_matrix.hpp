#pragma once 

#include <array>
#include <iostream>

namespace matrix{
//forward declaration
template<int n, int m, typename Scalar>
class Matrix; 

template<int n, int m, typename Scalar>
std::ostream& operator<<(std::ostream& os ,const Matrix<n,m,Scalar>&  matrix);

template<int n, int m, typename Scalar=double>
class Matrix {
    public : 
        Matrix(Scalar value=0);// par défaut valeur 0 dans ma matrice
        Matrix(const Matrix& matrix2);// on copie pas et modifie pas, construct par recopie
        Matrix(const std::array<Scalar , n * m>& tab);
        ~Matrix();
        Scalar& operator[](const std::pair<int,int>& coords);
        Matrix<n,m,Scalar> operator+=(Matrix<n,m,Scalar> added_matrix);
        Matrix<n,m,Scalar> operator+(Matrix<n,m,Scalar> added_matrix);

    private : 
        std::array<Scalar , n * m> m_matrix;// on définit notre matrice comme une ligne 
        friend std::ostream& operator<< <n,m,Scalar>(std::ostream& os, const Matrix<n,m,Scalar>&  matrix);

};

template<int n, int m,typename Scalar>
Matrix<n,m,Scalar>::~Matrix(){}

// constructeur par valeur 
template<int n, int m, typename Scalar>
Matrix<n,m,Scalar>::Matrix(Scalar value){
    for(auto& elem : m_matrix){
        elem=value;
    }
};

template<int n, int m, typename Scalar>
Matrix<n,m,Scalar>::Matrix(const std::array<Scalar , n * m>& tab):m_matrix(tab){};

template<int n, int m, typename Scalar>
Matrix<n,m,Scalar>::Matrix(const Matrix& matrix_2){
    m_matrix=matrix_2.m_matrix;
};

template<int n ,int m,typename Scalar>
// la paire représente i , j de notre tableau 
Scalar& Matrix<n ,m,Scalar>::operator[](const std::pair<int,int>& coords){
    return m_matrix[ std::get<0>(coords)*m + std::get<1>(coords)];
};


template<int n, int m, typename Scalar>
std::ostream& operator<<(std::ostream& os, const Matrix<n,m,Scalar>& matrix){
        auto coef = matrix.m_matrix.begin(); // auto = std::array<int>::iterator
        for (int i = 0 ; i != n ; ++i)// gestion de la ligne 
        {
            for (int j = 0; j != m ; ++j)// tant qu'on n'a pas balayé toutes les colonnes
            {
                os << ' ' << *coef++;
            }
            os << std::endl;// on a balayé toutes les oclonnes de la ligne alors on met un retour à la ligne. 
        }
        return os;
    }
// template<int n , int m , typename Scalar>
// Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+=(Matrix<n,m,Scalar> added_matrix){
//     auto ptr = m_matrix.begin(); // auto = std::array<int>::iterator
//     auto ptr_add = added_matrix.m_matrix.begin(); // auto = std::array<int>::iterator
//         for (int i = 0 ; i != n ; ++i)// gestion de la ligne 
//         {
//             for (int j = 0; j != m ; ++j)// tant qu'on n'a pas balayé toutes les colonnes
//             {
//                 *ptr++ += *ptr_add++;
//             }
//             // on a balayé toutes les oclonnes de la ligne alors on met un retour à la ligne. 
//         }
//     return *this;
// };
template<int n , int m , typename Scalar>
Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+=(Matrix<n,m,Scalar> added_matrix){

    auto ptr_add = added_matrix.m_matrix.begin(); // auto = std::array<int>::iterator
    for(auto ptr = m_matrix.begin();ptr!=m_matrix.end();++ptr){
        *ptr += *ptr_add++;
    }
    return *this;
};

template<int n , int m , typename Scalar>
Matrix<n,m,Scalar> Matrix<n,m,Scalar>::operator+(Matrix<n,m,Scalar> added_matrix){
    Matrix<n,m,Scalar> res(*this);
    res+=added_matrix;
    return res;
}

};

