#define BOOST_TEST_MODULE myMatrix
#include <boost/test/included/unit_test.hpp>
#include <cassert>
#include <tuple>
#include<memory>

#include"Matrix.h"
 

BOOST_AUTO_TEST_SUITE(myMatrix)
BOOST_AUTO_TEST_CASE(myMatrix)
{
  BOOST_TEST(1 == 1);
  BOOST_TEST(true);
  Matrix<int, -1> matrix;
  BOOST_TEST(matrix.Size() == 0);
  auto a = matrix[0][0];
  BOOST_TEST(a == -1);
  BOOST_TEST(matrix.Size() == 0);
  matrix[100][100] = 257;
  BOOST_TEST(matrix.Size() == 1);
  BOOST_TEST(matrix[100][100] == 257);
  for (auto c : matrix)
  {
      int x;
      int y;
      int v;
      std::tie(x, y, v) = c; 
      BOOST_TEST(x == 100);
      BOOST_TEST(y == 100);
      BOOST_TEST(v == 257);
  }
}
BOOST_AUTO_TEST_SUITE_END()
