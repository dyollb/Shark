#define BOOST_TEST_MODULE DirectSearch_CMA
#include <boost/test/unit_test.hpp>
#include <boost/test/floating_point_comparison.hpp>

#include <shark/Algorithms/DirectSearch/CMA.h>
#include <shark/Algorithms/DirectSearch/ElitistCMA.h>
#include <shark/ObjectiveFunctions/Benchmarks/Rosenbrock.h>
#include <shark/ObjectiveFunctions/Benchmarks/Cigar.h>
#include <shark/ObjectiveFunctions/Benchmarks/Discus.h>
#include <shark/ObjectiveFunctions/Benchmarks/Ellipsoid.h>

#include "../testFunction.h"

using namespace shark;
using namespace shark::benchmarks;

BOOST_AUTO_TEST_SUITE (Algorithms_DirectSearch_ElitistCMA)

BOOST_AUTO_TEST_CASE( ElitistCMA_Cigar )
{
	Cigar function(3);
	ElitistCMA optimizer;
	optimizer.activeUpdate() = true;

	std::cout<<"Testing: "<<optimizer.name()<<" with "<<function.name()<<std::endl;
	testFunction( optimizer, function, 10, 1000, 1E-10 );
}

BOOST_AUTO_TEST_CASE( ElitistCMA_Discus )
{
	Discus function(3);
	ElitistCMA optimizer;
	optimizer.activeUpdate() = true;
	
	std::cout<<"\nTesting: "<<optimizer.name()<<" with "<<function.name()<<std::endl;
	testFunction( optimizer, function, 10, 1000, 1E-10 );
}


BOOST_AUTO_TEST_CASE( ElitistCMA_Ellipsoid )
{
	Ellipsoid function(5);
	ElitistCMA optimizer;
	optimizer.activeUpdate() = true;
	
	std::cout << "\nTesting: " << optimizer.name() << " with " << function.name() << std::endl;
	testFunction( optimizer, function, 10, 1000, 1E-10 );
}
BOOST_AUTO_TEST_CASE( ElitistCMA_Rosenbrock )
{
	Rosenbrock function(3);
	ElitistCMA optimizer;
	optimizer.activeUpdate() = true;

	std::cout << "\nTesting: " << optimizer.name() << " with " << function.name() << std::endl;
	testFunction( optimizer, function, 10, 2000, 1E-10 );
}

BOOST_AUTO_TEST_SUITE_END()
