#pragma once 

#include <iostream>
#include <array>

namespace matrix {


template<int n , int m , typename Scalar>
class Matrix; 

template<int n, int m , typename Scalar>
std::ostream& operator<<(std::ostream& os, const Matrix<n,m,Scalar>& matrix);

template<int n , int m , typename Scalar=double>
class Matrix{

    public: 
    Matrix(Scalar value=0);
    Matrix(const std::array<Scalar, n*m>& vecteur);
    Matrix(const Matrix<n,m,Scalar>& ) = default;// par recopie
    Matrix(Matrix<n,m,Scalar>&& ) = default;// par recopie
    // Matrix<n,m,Scalar> operator=(const Matrix<n,m,Scalar>&) == default;
    // Matrix<n,m,Scalar> operator=(Matrix<n,m,Scalar>&&) == default;

    ~Matrix();

    Scalar& operator[](const std::pair<int,int>& index);
    std::array<Scalar, n*m> get_matrix() const; 


    private : 
    std::array<Scalar, n*m> m_matrix;
    // attention ici au putain de template operator<<
    friend std::ostream& operator<< <n,m,Scalar>(std::ostream& os, const Matrix<n,m,Scalar>& matrix);

};



template<int n , int m , typename Scalar>
Matrix<n,m,Scalar>::Matrix(Scalar value){
    for(auto& elem : m_matrix){
        elem = value;
    }
};

// par copie d'un vecteur
template<int n , int m , typename Scalar>
Matrix<n,m,Scalar>::Matrix(const std::array<Scalar, n * m>& vecteur):m_matrix(vecteur){};


// template<int n , int m , typename Scalar>
// Matrix<n,m,Scalar>::Matrix(const Matrix<n,m,Scalar>& matrix){
//     m_matrix=matrix.m_matrix;
// }// par recopie  mais on a mis default 


template<int n , int m , typename Scalar>
Matrix<n,m,Scalar>::~Matrix(){};

template<int n , int m , typename Scalar>
Scalar&  Matrix<n,m,Scalar>::operator[](const std::pair<int,int>& index){
    return m_matrix[std::get<0>(index)*m + std::get<1>(index)];
};

template<int n, int m, typename Scalar>
std::array<Scalar, n*m> Matrix<n,m,Scalar>::get_matrix() const{
    return m_matrix;
  };


template<int n, int m, typename Scalar>
std::ostream& operator<<(std::ostream& os ,const Matrix<n,m,Scalar>&  matrix){
    auto ptr=matrix.m_matrix.begin();
    for(int i(0) ; i!=n ; ++i){//loop sur les lignes 
    for(int j(0) ; j!=m ; ++j){
        os <<' '<< *ptr++ ;
    }
    os << std::endl;
    }

    return os;
}

}