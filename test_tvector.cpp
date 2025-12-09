#include "tmatrix.h"

#include <gtest.h>

TEST(TDynamicVector, can_create_vector_with_positive_length)
{
  ASSERT_NO_THROW(TDynamicVector<int> v(5));
}

TEST(TDynamicVector, cant_create_too_large_vector)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(MAX_VECTOR_SIZE + 1));
}

TEST(TDynamicVector, throws_when_create_vector_with_negative_length)
{
  ASSERT_ANY_THROW(TDynamicVector<int> v(-5));
}

TEST(TDynamicVector, can_create_copied_vector)
{
  TDynamicVector<int> v(10);

  ASSERT_NO_THROW(TDynamicVector<int> v1(v));
}

TEST(TDynamicVector, copied_vector_is_equal_to_source_one)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B = A;
	EXPECT_EQ(A, B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, copied_vector_has_its_own_memory)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B = A;
	EXPECT_NE(&A, &B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_get_size)
{
  TDynamicVector<int> v(4);

  EXPECT_EQ(4, v.size());
}
TEST(TDynamicVector, throws_when_set_element_with_negative_index)
{
	TDynamicVector<int> A(3);
	ASSERT_ANY_THROW(A[-2]);
  //ADD_FAILURE();
}

TEST(TDynamicVector, throws_when_set_element_with_too_large_index)
{
	TDynamicVector<int> A(3);
	ASSERT_ANY_THROW(A[4]);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vector_to_itself)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	ASSERT_NO_THROW(A = A);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_equal_size)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (1, 2, 3)
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	ASSERT_NO_THROW(A = B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, assign_operator_change_vector_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(7);
	A = B;
	EXPECT_EQ(A.size(), 7);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_assign_vectors_of_different_size)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(4); // (1, 2, 3, 4)
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	B[3] = 4;
	ASSERT_NO_THROW(A=B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, compare_equal_vectors_return_true)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (3, 0, 5)
	B[0] = 3;
	B[2] = 5;
	EXPECT_TRUE(A == B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, compare_vector_with_itself_return_true)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	EXPECT_TRUE(A == A);
  //ADD_FAILURE();
}

TEST(TDynamicVector, vectors_with_different_size_are_not_equal)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(4); // (3, 0, 5, 0)
	B[0] = 3;
	B[1] = 0;
	B[2] = 5;
	B[3] = 0;
	EXPECT_FALSE(A == B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_add_scalar_to_vector)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (5, 2, 7)
	B[0] = 5;
	B[1] = 2;
	B[2] = 7;
	EXPECT_EQ(A+2, B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_scalar_from_vector)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (1, -2, 3)
	B[0] = 1;
	B[1] = -2;
	B[2] = 3;
	EXPECT_EQ(A - 2, B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_scalar_by_vector)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (6, 0, 10)
	B[0] = 6;
	B[2] = 10;
	EXPECT_EQ(A * 2, B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_add_vectors_with_equal_size)
{
	TDynamicVector<int> A(3); // (3, 0, 5)
	A[0] = 3;
	A[2] = 5;
	TDynamicVector<int> B(3); // (1, 2, 3)
	B[0] = 1;
	B[1] = 2;
	B[2] = 3;
	ASSERT_NO_THROW(A + B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_add_vectors_with_not_equal_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(4);
	ASSERT_ANY_THROW(A + B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_subtract_vectors_with_equal_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(3);
	ASSERT_NO_THROW(A - B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_subtract_vectors_with_not_equal_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(4);
	ASSERT_ANY_THROW(A - B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, can_multiply_vectors_with_equal_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(3);
	ASSERT_NO_THROW(A * B);
  //ADD_FAILURE();
}

TEST(TDynamicVector, cant_multiply_vectors_with_not_equal_size)
{
	TDynamicVector<int> A(3);
	TDynamicVector<int> B(4);
	ASSERT_ANY_THROW(A * B);
  //ADD_FAILURE();
}

