#include <Application.hpp>
#include <stdexcept>
#include <iostream>
#include <filesystem>

int main () {
	// try {
    //     std::filesystem::path currentPath = std::filesystem::current_path();
    //     std::cout << "Current directory: " << currentPath << std::endl;
    // } catch (const std::filesystem::filesystem_error& e) {
    //     std::cerr << "Error: " << e.what() << std::endl;
    // }

	Application app("Project1");

	try {
		app.run();
	}
	catch (const std::exception &e) {
		std::cerr << e.what() << std::endl;
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}