#include "pch.h"
#include "CppUnitTest.h"
#include "../../Lab 1/Lab 1/MyList.h"
#include "../../Lab 1/Lab 1/MyList.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

#include <vector> 
#include <sstream> 

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		TEST_METHOD(DefaultConstructor)
		{
			MyList l;
			Assert::IsTrue(l.isEmpty());
			Assert::AreEqual(l.get_size(), 0u);
		}

		//checking before puch_back & push_front
		TEST_METHOD(at_WHERE_exception_throwed)
		{
			MyList l;

			srand(time(0));

			//counting throwed exception on empty list
			size_t N = rand() % 100;
			size_t exception_counter = 0u;

			for (size_t i = 0u; i < N; i++) {
				try {
					l.at(i);
				}
				catch (const std::range_error& e) {
					exception_counter++;
				}
			}

			Assert::AreEqual(exception_counter, N);
		}

		//checking before CopyConstructor & Destructor
		TEST_METHOD(push_back_AND_at)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//checking elements in direct order
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at(i), rand_number[i]);
		}

		TEST_METHOD(push_front_AND_at)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in front of list
			for (size_t i = 0u; i < N; i++)
				l.push_front(rand_number[i]);

			//checking elements in reverse order
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at((N - 1u) - i), rand_number[i]);
		}

		TEST_METHOD(CopyConstructor)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;
			size_t N = rand() % 100u;

			for (size_t i = 0u; i < N; i++)
				l.push_back(rand());

			//checking copy-list for equal elements
			MyList l_copy(l);

			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at(i), l_copy.at(i));
			Assert::AreEqual(l_copy.get_size(), N);

			//checking copy-list for independence of original list
			l.clear();

			Assert::IsFalse(l_copy.isEmpty());
			Assert::AreEqual(l_copy.get_size(), N);
		}

		TEST_METHOD(Destructor)
		{
			MyList* pointer_to_list;

			{
				//creating list of random elements
				MyList l;

				size_t N = rand() % 100;

				for (size_t i = 0u; i < N; i++)
					l.push_back(rand());

				//saving address of list
				pointer_to_list = &l;

				//end of block causes destructor calling
			}

			//referring to a non-existent object (destructor deleted all elements & zero head, tail, size)
			Assert::IsTrue(pointer_to_list->isEmpty());
		}

		TEST_METHOD(at_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//checking elements by position 
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at(i), rand_number[i]);
		}

		TEST_METHOD(pop_back_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//popping elements from the end & checking
			for (size_t i = 0u; i < N; i++) {
				//checking size of list before and after popping
				Assert::AreEqual(l.get_size(), N - i);

				l.pop_back();

				Assert::AreEqual(l.get_size(), N - i - 1u);

				//checking order of remaining elements
				for (size_t j = 0u; j < N - i - 1u; j++)
					Assert::AreEqual(l.at(j), rand_number[j]);
			}
		}

		TEST_METHOD(pop_back_WHERE_exception_throwed)
		{
			//creating empty list
			MyList l;

			//is catced exception
			bool isCathed = false;

			//try insert from the end
			try {
				l.pop_back();
			}
			catch (const std::range_error& e) {
				isCathed = true;
			}

			Assert::IsTrue(isCathed);
		}

		TEST_METHOD(pop_front_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//popping elements from the start & checking
			for (size_t i = 0u; i < N; i++) {
				//checking size of list before and after popping
				Assert::AreEqual(l.get_size(), N - i);

				l.pop_front();

				Assert::AreEqual(l.get_size(), N - i - 1u);

				//checking order of remaining elements
				for (size_t j = 0u; j < N - i - 1u; j++)
					Assert::AreEqual(l.at(j), rand_number[i + j + 1]);
			}
		}

		TEST_METHOD(pop_front_WHERE_exception_throwed)
		{
			//creating empty list
			MyList l;

			//is catced exception
			bool isCathed = false;

			//try insert from the end
			try {
				l.pop_front();
			}
			catch (const std::range_error& e) {
				isCathed = true;
			}

			Assert::IsTrue(isCathed);
		}

		TEST_METHOD(insert_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//inserting elements before everyone
			for (size_t i = 0u; i < N; i++)
				l.insert(-1 * (int)i, 2u * i);

			//checking size
			Assert::AreEqual(l.get_size(), N * 2u);

			//checking position of old elements
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at(i * 2u + 1u), rand_number[i]);

			//checking position of new elements
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l.at(i * 2u), -1 * (int)i);
		}

		TEST_METHOD(insert_WHERE_exception_throwed)
		{
			//creating list of random values
			MyList l;

			size_t N = rand() % 100;

			for (size_t i = 0u; i < N; i++)
				l.push_back(rand());

			//is catched exception
			bool isCathed = false;

			//try set after the end
			try {
				l.insert(rand(), l.get_size());
			}
			catch (const std::range_error& e) {
				isCathed = true;
			}

			Assert::IsTrue(isCathed);
		}

		TEST_METHOD(remove_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//removing every second element
			for (size_t i = 0u; i < N / 2u; i++)
				l.remove(i);

			//checking size
			Assert::AreEqual(l.get_size(), (N + 1u) / 2u);

			//checking remaining elements
			for (size_t i = 0u; i < N / 2; i++)
				Assert::AreEqual(l.at(i), rand_number[2u * i + 1u]);
		}

		TEST_METHOD(remove_WHERE_exception_throwed)
		{
			//creating empty list
			MyList l;

			srand(time(0));

			//counting throwed exception on empty list
			size_t N = rand() % 100;
			size_t exception_counter = 0u;

			for (size_t i = 0u; i < N; i++) {
				try {
					l.remove(i);
				}
				catch (const std::range_error& e) {
					exception_counter++;
				}
			}

			Assert::AreEqual(exception_counter, N);

			//changing to list of random values

			for (size_t i = 0u; i < N; i++)
				l.push_back(rand());

			//counting throwed exception on list after the end
			exception_counter = 0u;

			//try remove after the end
			for (size_t i = 0u; i < N; i++) {
				try {
					l.remove(l.get_size() + i);
				}
				catch (const std::range_error& e) {
					exception_counter++;
				}
			}

			Assert::AreEqual(exception_counter, N);
		}

		TEST_METHOD(get_size)
		{
			srand(time(0));

			//vector of random lists which size is equal index in array
			size_t N = rand() % 100;
			std::vector<MyList> list(N);

			for (size_t i = 0; i < N; i++)
				for (size_t j = 0u; j < i; j++)
					list[i].push_back(rand());

			//checking sizes
			for (size_t i = 0; i < N; i++)
				Assert::AreEqual(list[i].get_size(), i);
		}

		//checkind isEmpty before clear
		TEST_METHOD(isEmpty)
		{
			//empty list
			MyList l;
			Assert::IsTrue(l.isEmpty());

			//one element
			l.push_back(rand());
			Assert::IsFalse(l.isEmpty());

			//two elements
			l.push_back(rand());
			Assert::IsFalse(l.isEmpty());

			//one element
			l.pop_front();
			Assert::IsFalse(l.isEmpty());

			//two elements
			l.push_front(rand());
			Assert::IsFalse(l.isEmpty());

			//zero elements
			l.pop_front();
			l.pop_front();
			Assert::IsTrue(l.isEmpty());
		}

		TEST_METHOD(clear)
		{
			srand(time(0));

			//vector of random lists which size is equal index in array
			size_t N = rand() % 100;
			std::vector<MyList> list(N);

			//filling lists
			for (size_t i = 0; i < N; i++)
				for (size_t j = 0u; j < i; j++)
					list[i].push_back(rand());

			//clear lists
			for (size_t i = 0; i < N; i++)
				list[i].clear();

			//checking sizes
			for (size_t i = 0; i < N; i++)
				Assert::AreEqual(list[i].get_size(), 0u);
		}

		TEST_METHOD(set_WITHOUT_exception)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//double every second element
			for (size_t i = 0u; i < N; i += 2)
				l.set(i, -1);

			//checking size
			Assert::AreEqual(l.get_size(), N);

			//checking values of old elements (must be equal)
			for (size_t i = 1u; i < N; i += 2)
				Assert::AreEqual(l.at(i), rand_number[i]);

			//checking values of new elements (must be NOT equal with old, but equal with -1)
			for (size_t i = 0u; i < N; i += 2) {
				Assert::AreNotEqual(l.at(i), rand_number[i]);
				Assert::AreEqual(l.at(i), -1);
			}
		}

		TEST_METHOD(set_WHERE_exception_throwed)
		{
			//creating empty list
			MyList l;

			srand(time(0));

			//counting throwed exception on empty list
			size_t N = rand() % 100;
			size_t exception_counter = 0u;

			for (size_t i = 0u; i < N; i++) {
				try {
					l.set(i, rand());
				}
				catch (const std::range_error& e) {
					exception_counter++;
				}
			}

			Assert::AreEqual(exception_counter, N);

			//changing to list of random values

			for (size_t i = 0u; i < N; i++)
				l.push_back(rand());

			//counting throwed exception on list after the end
			exception_counter = 0u;

			//try set after the end
			for (size_t i = 0u; i < N; i++) {
				try {
					l.set(l.get_size() + i, rand());
				}
				catch (const std::range_error& e) {
					exception_counter++;
				}
			}

			Assert::AreEqual(exception_counter, N);
		}

		TEST_METHOD(push_front_list_WHERE_both_are_NOT_empty)
		{
			srand(time(0u));

			//creating two lists of random values
			MyList l1, l2;

			size_t N1 = rand() % 100;
			size_t N2 = rand() % 100;

			std::vector<int> rand_number1(N1);
			std::vector<int> rand_number2(N2);

			for (size_t i = 0u; i < N1; i++)
				rand_number1[i] = rand();

			for (size_t i = 0u; i < N2; i++)
				rand_number2[i] = rand();

			//fiiling lists by array's values
			for (size_t i = 0u; i < N1; i++)
				l1.push_back(rand_number1[i]);

			for (size_t i = 0u; i < N2; i++)
				l2.push_back(rand_number2[i]);

			//push second list in front of first
			l1.push_front(l2);

			//checking sizes and elements
			Assert::AreEqual(l1.get_size(), N1 + N2);
			Assert::AreEqual(l2.get_size(), N2);

			//checking first list
			for (size_t i = 0u; i < N2; i++)
				Assert::AreEqual(l1.at(i), rand_number2[i]);

			for (size_t i = 0u; i < N1; i++)
				Assert::AreEqual(l1.at(N2 + i), rand_number1[i]);

			//checking second list
			for (size_t i = 0u; i < N2; i++)
				Assert::AreEqual(l2.at(i), rand_number2[i]);

		}

		TEST_METHOD(push_front_list_WHERE_first_is_empty)
		{
			srand(time(0u));

			//first list is empty
			MyList l1, l2;

			size_t N = rand() % 100;

			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//fiiling second list by array's values
			for (size_t i = 0u; i < N; i++)
				l2.push_back(rand_number[i]);

			//push second list in front of first
			l1.push_front(l2);

			//checking sizes and elements
			Assert::AreEqual(l1.get_size(), N);
			Assert::AreEqual(l2.get_size(), N);

			//checking first list
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l1.at(i), rand_number[i]);

			//checking second list
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l2.at(i), rand_number[i]);
		}

		TEST_METHOD(push_front_list_WHERE_second_is_empty)
		{
			srand(time(0u));

			//first list is empty
			MyList l1, l2;

			size_t N = rand() % 100;

			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//fiiling first list by array's values
			for (size_t i = 0u; i < N; i++)
				l1.push_back(rand_number[i]);

			//push second list in front of first
			l1.push_front(l2);

			//checking sizes and elements
			Assert::AreEqual(l1.get_size(), N);
			Assert::AreEqual(l2.get_size(), 0u);

			//checking first list
			for (size_t i = 0u; i < N; i++)
				Assert::AreEqual(l1.at(i), rand_number[i]);
		}

		TEST_METHOD(output_operator)
		{
			srand(time(0u));

			//creating list of random values
			MyList l;

			size_t N = rand() % 100;
			std::vector<int> rand_number(N);

			for (size_t i = 0u; i < N; i++)
				rand_number[i] = rand();

			//pushing numbers in back of list
			for (size_t i = 0u; i < N; i++)
				l.push_back(rand_number[i]);

			//pushing data from list into stream
			std::stringstream string1;
			string1 << l;

			//checking all elements from the stream
			int number;
			for (size_t i = 0; i < N; i++) {
				string1 >> number;

				Assert::AreEqual(number, rand_number[i]);
			}
		}
	};
}
