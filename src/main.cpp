#include <iostream>
#include <thread>

#include <boost/program_options.hpp>

#include "config.hpp"
#include "information.hpp"

namespace po = boost::program_options;

int main(int argc, char **argv)
{
    /********************************************
     * Argument handling starts here
     ********************************************/
    int debug_level;
    po::options_description generic("Generic options");
    generic.add_options()("help,h", "Print usage information and exit.")(
        "info,i", "Print program's information and exit.")("version,v", "Print program's version and exit.");

    po::options_description config("Configuration");
    config.add_options()("debug-level,l", po::value<int>(&debug_level)->default_value(6),
                         "Set debug level to print logs equal to level and higher.\n"
                         "Default debug level is 6.\n"
                         "Levels:\n"
                         "  Trace:    0\n"
                         "  Debug:    1\n"
                         "  Info:     2\n"
                         "  Warn:     3\n"
                         "  Error:    4\n"
                         "  Critical: 5\n"
                         "  Off:      6");

    po::variables_map vm;
    po::options_description cmdline_options;
    cmdline_options.add(generic).add(config);
    po::store(po::parse_command_line(argc, argv, cmdline_options), vm);
    po::notify(vm);

    if (vm.count("help"))
    {
        std::cout << std::endl;
        std::cout << generic << std::endl;
        std::cout << config << std::endl;
        return EXIT_SUCCESS;
    }
    if (vm.count("info"))
    {
        std::cout << "Project name: " << PROJECT_NAME << std::endl;
        std::cout << "Project version: v" << PROJECT_VERSION << std::endl;
        std::cout << "Project build timestamp: " << PROJECT_TIMESTAMP << std::endl;
        std::cout << "Project Description: " << PROJECT_DESCRIPTION << std::endl;
        return EXIT_SUCCESS;
    }

    if (vm.count("version"))
    {
        std::cout << "version: v" << PROJECT_VERSION << std::endl;
        return EXIT_SUCCESS;
    }
    /********************************************
     * Argument handling ends here
     ********************************************/

    /*********************************************
     * Setup spdlog starts here
     **********************************************/

    /*********************************************
     * Setup spdlog ends here
     **********************************************/

    /********************************************
     * Main program starts here
     ********************************************/

    return EXIT_SUCCESS;
}
