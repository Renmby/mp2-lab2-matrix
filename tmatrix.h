// ННГУ, ИИТММ, Курс "Алгоритмы и структуры данных"
//
// Copyright (c) Сысоев А.В.
//
//

#ifndef __TDynamicMatrix_H__
#define __TDynamicMatrix_H__

#include <iostream>

using namespace std;

const int MAX_VECTOR_SIZE = 100000000;
const int MAX_MATRIX_SIZE = 10000;

// Динамический вектор - 
// шаблонный вектор на динамической памяти
template<typename T>
class TDynamicVector
{
protected:
  size_t sz;
  T* pMem;
public:
  TDynamicVector(size_t size = 1) : sz(size)
  {
    if ((sz == 0) || (sz > MAX_VECTOR_SIZE)) {
        throw("error");
    }
    pMem = new T[sz]();// {}; // У типа T д.б. констуктор по умолчанию
  }
  TDynamicVector(T* arr, size_t s) : sz(s)
  {
    assert(arr != nullptr && "TDynamicVector ctor requires non-nullptr arg");
    pMem = new T[sz];
    std::copy(arr, arr + sz, pMem);
  }
  TDynamicVector(const TDynamicVector& v)
  {
      // assert(v.pMem != nullptr && "TDynamicVector ctor requires non-nullptr arg");
      sz = v.sz;
      pMem = new T[sz];
      std::copy(v.pMem, v.pMem + sz, pMem);
  }

  TDynamicVector(TDynamicVector&& v) noexcept
  {
      if (this != &v) {
          pMem = v.pMem;
          sz = v.sz;
          v.pMem = nullptr;
          v.sz = 0;
      }
  }
  ~TDynamicVector()
  {
      delete[]pMem;
  }

  TDynamicVector& operator=(const TDynamicVector& v)
  {
      //sz = v.sz;
      if (this != &v) {
          if (sz != v.sz) {
              delete[] pMem;
              sz = v.sz;
              pMem = new T[sz];
          }
          std::copy(v.pMem, v.pMem + sz, pMem);
      }
      return *this;
  }
  TDynamicVector& operator=(TDynamicVector&& v) noexcept
  {
      if (this != &v) {
          delete[] pMem;
          sz = v.sz;
          pMem = v.pMem;
          v.sz = 0;
          v.pMem = nullptr;
      }
      return *this;
  }

  size_t size() const noexcept { return sz; }

  // индексация
  T& operator[](size_t ind)
  {
      if ((ind < 0) || (ind >= sz)) {
          throw("error");
      }
      return pMem[ind];
  }
  const T& operator[](size_t ind) const
  {
      if ((ind < 0) || (ind >= sz)) {
          throw("error");
      }
      return pMem[ind];
  }
  // индексация с контролем
  T& at(size_t ind)
  {
      if ((ind < 0) || (ind >= sz)) {
          throw("error");
      }
      return pMem[ind];
  }
  const T& at(size_t ind) const
  {
      if ((ind < 0) || (ind >= sz)) {
          throw("error");
      }
      return pMem[ind];
  }

  // сравнение
  bool operator==(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 0;
      }
      for (size_t i = 0; i < sz; i++) {
          if (pMem[i] != v.pMem[i]) {
              return 0;
          }
      }
      return 1;
  }
  bool operator!=(const TDynamicVector& v) const noexcept
  {
      if (sz != v.sz) {
          return 1;
      }
      for (size_t i = 0;i < sz;i++) {
          if (pMem[i] != v.pMem[i])
              return 1;
      }
      return 0;
  }

  // скалярные операции
  TDynamicVector operator+(T val)
  {
      TDynamicVector A(sz);
      for (size_t i = 0;i < sz;i++) {
          A.pMem[i] =pMem[i]+val;
      }
      return A;
  }
  TDynamicVector operator-(T val)
  {
      TDynamicVector A(sz);
      for (size_t i = 0;i < sz;i++) {
          A.pMem[i] = pMem[i] - val;
      }
      return A;
  }
  TDynamicVector operator*(T val)
  {
      TDynamicVector A(sz);
      for (size_t i = 0;i < sz;i++) {
          A.pMem[i] = pMem[i] * val;
      }
      return A;
  }

  // векторные операции
  TDynamicVector operator+(const TDynamicVector& v)
  {
      if (sz != v.sz) {
          throw("error");
      }
      TDynamicVector A(sz);
      for (size_t i = 0;i < sz;i++) {
          A.pMem[i] = pMem[i] +v.pMem[i];
      }
      return A;
  }
  TDynamicVector operator-(const TDynamicVector& v)
  {
      if (sz != v.sz) {
          throw("error");
      }
      TDynamicVector A(sz);
      for (size_t i = 0;i < sz;i++) {
          A.pMem[i] = pMem[i] - v.pMem[i];
      }
      return A;
  }
  T operator*(const TDynamicVector& v) //noexcept(noexcept(T())) //скалярное произведение
  {
      if (sz != v.sz) {
          throw("error");
      }
      T sum = 0;
      for (size_t i = 0;i < sz;i++) {
          sum += (pMem[i] * v.pMem[i]);
      }
      return sum;
  }

  friend void swap(TDynamicVector& lhs, TDynamicVector& rhs) noexcept
  {
    std::swap(lhs.sz, rhs.sz);
    std::swap(lhs.pMem, rhs.pMem);
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      istr >> v.pMem[i]; // требуется оператор>> для типа T
    return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicVector& v)
  {
    for (size_t i = 0; i < v.sz; i++)
      ostr << v.pMem[i] << ' '; // требуется оператор<< для типа T
    return ostr;
  }
};


// Динамическая матрица - 
// шаблонная матрица на динамической памяти
template<typename T>
class TDynamicMatrix : private TDynamicVector<TDynamicVector<T>>
{
  using TDynamicVector<TDynamicVector<T>>::pMem;
  using TDynamicVector<TDynamicVector<T>>::sz;
public:
  TDynamicMatrix(size_t s = 1) : TDynamicVector<TDynamicVector<T>>(s)
  {
      if ((sz == 0) || (sz > MAX_MATRIX_SIZE)) {
          throw("error");
      }
    for (size_t i = 0; i < sz; i++)
      pMem[i] = TDynamicVector<T>(sz);
  }

  using TDynamicVector<TDynamicVector<T>>::operator[];

  // сравнение
  bool operator==(const TDynamicMatrix& m) const noexcept
  {
      if (sz != m.sz) {
          return 0;
      }
      for (int i = 0;i < sz;i++) {
          if (pMem[i]!= m.pMem[i]) {
              return 0;
          }
      }
      return 1;
  }

  // матрично-скалярные операции
  TDynamicMatrix operator*(const T& val)
  {
      TDynamicMatrix M(sz);
      for (int i = 0;i < sz;i++) {
          M.pMem[i] = pMem[i] * val;
      }
      return M;
  }

  // матрично-векторные операции
  TDynamicVector<T> operator*(const TDynamicVector<T>& v)
  {
      TDynamicMatrix M(sz);
      for (int i = 0;i < sz;i++) {
          M.pMem[i] = pMem[i] * v;
      }
      return M;
  }

  // матрично-матричные операции
  TDynamicMatrix operator+(const TDynamicMatrix& m)
  {
      TDynamicMatrix M(sz);
      for (int i = 0;i < sz;i++) {
          M.pMem[i] = pMem[i] + m.pMem[i];
      }
      return M;
  }
  TDynamicMatrix operator-(const TDynamicMatrix& m)
  {
      TDynamicMatrix M(sz);
      for (int i = 0;i < sz;i++) {
          M.pMem[i] = pMem[i] - m.pMem[i];
      }
      return M;
  }
  TDynamicMatrix operator*(const TDynamicMatrix& m)
  {
      TDynamicMatrix M(sz);
      for (int i = 0;i < sz;i++) {
          for (int j = 0;j < sz;j++) {
              for (int k = 0;k < sz;k++) {
                  M.pMem[i][j] += (pMem[i][k] * m.pMem[k][j]);
              }
          }
      }
      return M;
  }

  // ввод/вывод
  friend istream& operator>>(istream& istr, TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          istr >> v.pMem[i]; // требуется оператор>> для типа T
      return istr;
  }
  friend ostream& operator<<(ostream& ostr, const TDynamicMatrix& v)
  {
      for (size_t i = 0; i < v.sz; i++)
          ostr << v.pMem[i] << endl; // требуется оператор<< для типа T
      return ostr;
  }
};

template <typename T>
class TBandedMatrix {
private:
    size_t sz;
    size_t Width; //ширина ленты от диагонали
    TDynamicVector<T> pMem; 
public:
    TBandedMatrix(size_t size = 1, size_t bandwidth = 1): 
        sz(size), Width(bandwidth), pMem(sz* (2 * Width + 1)) {
        if ((sz == 0) || (Width >= sz)) {
            throw ("error");
        }
    }
    size_t size() const noexcept { return sz; }
    size_t getWidth() const noexcept { return Width; }
    T& at(size_t i, size_t j) {
        if ((i==0) || (j==0) || (i>=sz) || (j>=sz)) {
            throw("error");
        }
        return pMem[i * (2 * Width + 1) + (j - i + Width)];
    }
    TBandedMatrix TransformIntoMatrix(TDynamicMatrix<T> v) {
        TDynamicMatrix<T> M(v.sz);
        int col = 0;
        for (size_t i = 0;i < v.sz;i++) {
            int k = col;
            for (size_t j = col;j < col+(v.Width * 2 + 1);j++) {
                M[i][j] = v.at(i, j);
            }
            col = k;
            col += 1;
        }
        return M;
    }
};
template <typename T>
class TSparse_Coordinate {
private:
    size_t sz;
    //size_t NNE; //количество ненулевых элементов
    TDynamicVector<T> values;
    TDynamicVector<T> rows;
    TDynamicVector<T> columns;
public:
    TSparse_Coordinate(size_t size = 1) : sz(size), rows(size)
    {
        if ((sz == 0) || (sz > MAX_VECTOR_SIZE)) {
            throw("error");
        }
        TDynamicVector<T> values(sz);
        TDynamicVector<T> rows(sz);
        TDynamicVector<T> columns(sz);
    }
    TSparse_Coordinate<T> TransformIntoSparseMatrix(size_t NNE, TDynamicMatrix<T> M) {
        TSparse_Coordinate<T> S(sz);
        int k = 0;
        for (size_t i = 0;i < sz;i++) {
            for (size_t j = 0;j < sz;j++) {
                if (M[i][j] != 0) {
                    S.values[k] = M[i][j];
                    S.rows[k] = i;
                    S.columns[k] = j;
                    k += 1;
                }
            }
        }
        return S;
    }
    size_t size() const noexcept { return sz; }
    size_t NNElements() const noexcept { return values.size(); }
    /*void OutputSparse(TSparse_Coordinate<T> S) {
        cout << S.values << endl;
        cout << S.rows << endl;
        cout << S. << endl;
    }*/
};
template <typename T>
class TSparse_CSR {
private:
    size_t sz;
    TDynamicVector<T> values;    
    TDynamicVector<size_t> rows;
    TDynamicVector<size_t> columns; 
public:
    TSparse_CSR(size_t size = 1) : sz(size), rows(sz + 1) {
        if (sz == 0) {
            throw ("error");
        }
        //rows[0] = 0;
    }
    TSparse_CSR(const TDynamicMatrix<T>& M) : sz(M.size()), rows(sz + 1) {
        rows[0] = 0;
        size_t NNE = 0; //ненулевые элементы
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                if (M[i][j] != 0) {
                    NNE++;
                }
            }
        }
        values = TDynamicVector<T>(NNE);
        columns = TDynamicVector<size_t>(NNE);
        size_t idx = 0;
        for (size_t i = 0; i < sz; i++) {
            for (size_t j = 0; j < sz; j++) {
                if (M[i][j] != 0) {
                    values[idx] = M[i][j];
                    columns[idx] = j;
                    idx++;
                }
            }
            rows[i + 1] = idx;
        }
    }
    size_t size() const noexcept { return sz; }
    size_t NNElements() const noexcept { return values.size(); }
    void set(size_t i, size_t j, const T& value) {
        if (i >= sz || j >= sz)
            throw ("error");
        TDynamicMatrix<T> M(sz);

        for (size_t row = 0; row < sz; row++) {
            for (size_t col = 0; col < sz; col++) {
                dense[row][col] = this->at(row, col);
            }
        }
        M[i][j] = value;

        *this = TCSRMatrix<T>(dense);
    }
    T at(size_t i, size_t j) const {
        if (i >= sz || j >= sz)
            throw ("error");
        for (size_t k = rows[i]; k < rows[i + 1]; k++) {
            if (columns[k] == j) {
                return values[k];
            }
        }
        return T();
    }
};
#endif
