#include <stack.hpp>
#include <catch.hpp>

using namespace std;

SCENARIO("init"){
	stack<int> st();
	REQUIRE(st.count() == 0);
}

SCENARIO("push") {
	stack<int> st1();
	st.push(1);
	st.push(2);
	REQUIRE(st.count() == 2);
}

SCENARIO("pop") {
	stack<int> st();
	st.push(1);
	st.push(2);
	st.pop();
	REQUIRE(st.count() == 1 );
}

SCENARIO("operator=") {
	stack<int> st1();
	stack<int> st2();
	st1.push(1);
	st1.push(2);
	st1.push(3);
	s2 = s1;
	REQUIRE(s1.count() == s2.count());

}