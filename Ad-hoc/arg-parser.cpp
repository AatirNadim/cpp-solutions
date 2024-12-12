#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>
#include <getopt.h> // --> provides a standard interface for parsing command line options

using namespace std;

// define a structure to hold the parsed arguments
struct Arguments {
    string input_file;
    string output_file;
    int verbosity_level;
    bool help_requested;
};

// function to parse the command-line arguments
Arguments parse_arguments(int argc, char* argv[]) {
    Arguments args;
    args.verbosity_level = 0;
    args.help_requested = false;

    // define the options
    static struct option long_options[] = {
        {"input", required_argument, nullptr, 'i'},
        {"output", required_argument, nullptr, 'o'},
        {"verbose", no_argument, nullptr, 'v'},
        {"help", no_argument, nullptr, 'h'},
        {nullptr, 0, nullptr, 0}
    };

    int option_index = 0;
    int c;

    while ((c = getopt_long(argc, argv, "i:o:vh", long_options, &option_index)) != -1) {
        switch (c) {
            case 'i':
                args.input_file = optarg;
                break;
            case 'o':
                args.output_file = optarg;
                break;
            case 'v':
                args.verbosity_level++;
                break;
            case 'h':
                args.help_requested = true;
                break;
            default:
                throw std::invalid_argument("Invalid option");
        }
    }

    // check for any remaining arguments
    if (optind < argc) {
        throw invalid_argument("Unexpected arguments");
    }

    return args;
}

int main(int argc, char* argv[]) {
    try {
        Arguments args = parse_arguments(argc, argv);

        if (args.help_requested) {
            cout << "Usage: " << argv[0] << " [options]\n";
            cout << "Options:\n";
            cout << "  -i, --input <file>   Input file\n";
            cout << "  -o, --output <file>   Output file\n";
            cout << "  -v, --verbose          Increase verbosity level\n";
            cout << "  -h, --help              Display this help message\n";
            return 0;
        }

        // process the parsed arguments
        cout << "Input file: " << args.input_file << "\n";
        cout << "Output file: " << args.output_file << "\n";
        cout << "Verbosity level: " << args.verbosity_level << "\n";

    } catch (const exception& e) {
        cerr << "Error: " << e.what() << "\n";
        return 1;
    }

    return 0;
}