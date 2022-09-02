#include "./tests.hpp"

int main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	// std::string choice;
	// if (argc != 2)
	// {
	// 	std::cout << "No test given, testing vector." << std::endl;
	// 	choice = "vector";
	// }
	// else
	// 	choice = std::string(argv[1]);
	// if (choice == "vector")
		test_vector();
	// else if (choice == "map")
	// 	test_map();
	// else if (choice == "stack")
	// 	test_stack();
	// else if (choice == "all")
	// {
	// 	test_vector();
	// 	test_map();
	// 	test_stack();
	// }
	// else
	// 	std::cout << "No test for " << choice << std::endl;

	return (0);
}
