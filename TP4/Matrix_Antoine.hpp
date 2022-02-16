#pragma once

#include <iostream>
#include <vector>
#include <array>



namespace matrix{

    template <int n, int m, typename Scalar>
    class Matrix;
    template <int n, int m, typename Scalar>
    std::ostream&  operator<<( std::ostream& os, const Matrix<n, m, Scalar>& mat);


    template <int n, int m, typename Scalar = double>
    class Matrix{

        public : 
            using scalar_type=Scalar;

            Matrix(Scalar value=0);
            Matrix(const Matrix& mat) = default;
            //Matrix(const std::array<Scalar,n , m>, & mat);
            ~Matrix();

            Scalar& operator[](const std::pair<int,int>& coords);
            friend std::ostream& operator<< <n, m, Scalar> (std::ostream& os, const Matrix& mat);
            Matrix<n, m, Scalar> operator+=(Matrix<n, m, Scalar>& mat);
            Matrix<n, m, Scalar> operator+(Matrix<n, m, Scalar>& mat) const;
            template <int z>
            Matrix<n, z, Scalar> operator*(Matrix<m, z, Scalar>& mat) const;

            template <int z,int y>
            Matrix<n, z, Scalar> operator*(Matrix<y, z, Scalar>& mat) const;

            std::array<Scalar, n * m>& getMatrix();

        private:
            std::array<Scalar, n * m> m_matrix;

    };

    // Constructeur par recopie
    //template <int n, int m, typename Scalar>
    //Matrix<n,m, Scalar>::Matrix(const std::array<std::array<Scalar,m>,n>& mat) {}


    // Constructeur par défaut
    template <int n, int m, typename Scalar>
    Matrix<n,m, Scalar>::Matrix(Scalar value)
    {
        for(auto& elt : m_matrix)
        {
            elt = value;
        }
    }

    template <int n, int m, typename Scalar>
    Matrix<n,m, Scalar>::~Matrix() {}

    // Assessor
    template <int n, int m, typename Scalar>
    std::array<Scalar, n * m>& Matrix<n, m, Scalar>::getMatrix()
    {
        return this -> m_matrix;
    }


    template <int n, int m, typename Scalar>
    Scalar& Matrix<n,m, Scalar>::operator[](const std::pair<int,int>& coords)
    {
        return this -> m_matrix[ coords.first * m + coords.second];
    }


    template <int n, int m, typename Scalar>
    std::ostream& operator<< (std::ostream& os, const Matrix<n,m,Scalar>& mat)
    {
        auto coef = mat.m_matrix.begin(); // auto = std::array<int>::iterator
        for (int i = 0 ; i != n ; ++i)
        {
            for (int j = 0; j != m ; ++j)
            {
                os << ' ' << *coef;
                coef++;
            }
            os << std::endl;
        }
        return os;
    }

    template <int n, int m, typename Scalar>
    Matrix<n, m, Scalar> Matrix<n, m, Scalar>::operator+=(Matrix<n, m, Scalar>& mat){
        auto it = mat.m_matrix.begin(); // create an iterator on mat's arguments
        for (auto myIt = this -> m_matrix.begin(); myIt !=  this -> m_matrix.end() ; ++it, ++myIt) // Create a 2nd iterator on our matrix arguments and increase both.
        {
            *myIt += *it;// add the derefence value of the Matrix' arguement to the deferenced value of the first one
        }
        return *this;
        
    }

    template <int n, int m, typename Scalar>
    Matrix<n, m, Scalar> Matrix<n, m, Scalar>::operator+( Matrix<n, m, Scalar>& mat) const{
        Matrix res(*this);
        res += mat;
        return res;
    }

    template <int n, int m, typename Scalar>
    template <int z>
    Matrix<n, z, Scalar> Matrix<n, m, Scalar>::operator*(Matrix<m, z, Scalar>& mat) const{
        
        // Create the matrix n x l to return 
        Matrix< n, z, Scalar> res;
        auto itRes = res.getMatrix().begin(); // ... and an iterator on it

        // First case : column vector * row vector
        if constexpr(m == 1)// constexpr il peut le checker cette valeur à la compilation 
        {
            for( auto& myElt : this -> m_matrix)
            {
                for (auto& matElt : mat.getMatrix())
                {
                    *itRes = myElt * matElt;
                }
            }
        }
        // Second case : default case
        else
        {
            // One takes output matrix' dimensions and iteres on it (1st and 2nd for)
            for (int i = 0 ; i != n; ++i)
            {
                for (int j = 0; j != z; ++j)
                {
                    // One creates 2 iterators 
                    // on se deplace de i*m pour passer d'une ligne à une autre 
                    auto myIt = this -> m_matrix.begin() + i * m; // <=> 2D-rep : Start at line i so i * m ième components of 1D-rep
                    auto matIt = mat.getMatrix().begin() + j;
                    // We must create it here because of further incrementations
                    // Iterator of the second matrix must be incremented by l = number of columns if it were a 2D-representation
                    for(int k = 0; k != m; ++k)
                    {
                        *itRes += *myIt * *matIt; // Compute...
                        // ... and increase iterators
                        ++myIt;
                        matIt += z;
                    }
                    ++itRes; // increase itRes
                }
            }
        }    
        return res;
    }

    template <int n, int m, typename Scalar>
    template <int z,int y>
    Matrix<n, z, Scalar> Matrix<n,m,Scalar>::operator*(Matrix<y, z, Scalar>& mat) const{
        static_assert(z == y, "Inconsistent matrix size for product");// condition barre print notre erreur 
        if constexpr (z == y)
	    return *this * mat;} 

}