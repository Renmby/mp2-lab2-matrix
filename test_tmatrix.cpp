#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicMatrix, can_create_matrix_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicMatrix<int> m(5));
}

TEST(TDynamicMatrix, cant_create_too_large_matrix)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(MAX_MATRIX_SIZE + 1));
}

TEST(TDynamicMatrix, throws_when_create_matrix_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicMatrix<int> m(-5));
}

TEST(TDynamicMatrix, can_create_copied_matrix)
{
  TDynamicMatrix<int> m(5);

  ASSERT_NO_THROW(TDynamicMatrix<int> m1(m));
}

TEST(TDynamicMatrix, copied_matrix_is_equal_to_source_one)
{
	TDynamicMatrix<int> M(3);
	int k = 1;
	for(int i=0;i<3;i++){
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			k += 1;
		}
	}
	TDynamicMatrix<int> M1 = M;
	EXPECT_EQ(M, M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, copied_matrix_has_its_own_memory)
{
	TDynamicMatrix<int> M(3);
	int k = 1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			k += 1;
		}
	}
	TDynamicMatrix<int> M1 = M;
	EXPECT_NE(&M, &M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_get_size)
{
	TDynamicMatrix<int> M(3);
	EXPECT_EQ(3, M[0].size());
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_set_and_get_element)
{
	TDynamicMatrix<int> M(3);
	M[2][1] = 5;
	EXPECT_EQ(5, M[2][1]);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, throws_when_set_element_with_negative_index)
{
	TDynamicMatrix<int> M(3);
	ASSERT_ANY_THROW(M[2][-1]);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, throws_when_set_element_with_too_large_index)
{
	TDynamicMatrix<int> M(3);
	ASSERT_ANY_THROW(M[2][3]);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrix_to_itself)
{
	TDynamicMatrix<int> M(3);
	int k = 1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			k += 1;
		}
	}
	ASSERT_NO_THROW(M = M);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_equal_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(3);
	ASSERT_NO_THROW(M = M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, assign_operator_change_matrix_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(7);
	M = M1;
	EXPECT_EQ(M[0].size(), 7);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_assign_matrices_of_different_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(7);
	ASSERT_NO_THROW(M = M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_equal_matrices_return_true)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(3);
	int k = 1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			M1[i][j] = k;
			k += 1;
		}
	}
	EXPECT_TRUE(M == M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, compare_matrix_with_itself_return_true)
{
	TDynamicMatrix<int> M(3);
	int k = 1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			k += 1;
		}
	}
	EXPECT_TRUE(M == M);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, matrices_with_different_size_are_not_equal)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(4);
	int k = 1;
	for (int i = 0;i < 3;i++) {
		for (int j = 0;j < 3;j++) {
			M[i][j] = k;
			M1[i][j] = k;
			k += 1;
		}
	}
	EXPECT_FALSE(M == M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_add_matrices_with_equal_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(3);
	ASSERT_NO_THROW(M + M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_add_matrices_with_not_equal_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(4);
	ASSERT_ANY_THROW(M + M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, can_subtract_matrices_with_equal_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(3);
	ASSERT_NO_THROW(M - M1);
  //ADD_FAILURE();
}

TEST(TDynamicMatrix, cant_subtract_matrixes_with_not_equal_size)
{
	TDynamicMatrix<int> M(3);
	TDynamicMatrix<int> M1(4);
	ASSERT_ANY_THROW(M - M1);
	//ADD_FAILURE();
}
//TEST(TBandedMatrix, transfomation_from_band_matrix_to_normal_matrix) {
//	TDynamicMatrix<int>M(5);
//	TDynamicMatrix<int>A(5);
//	TBandedMatrix<int>B(1);
//	int k = 1;
//	for (int i = 0;i < 3;i++) {
//		for (int j = 0;i < 3;j++) {
//			B.at(i, j) = k;
//			k++;
//		}
//	}
//	B.TransformIntoMatrix(M);
//	EXPECT_EQ(A, M);
//}

