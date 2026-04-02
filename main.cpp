#include <iostream>
#include <vector>
#include "libtcc.h"

int main(int argc, char** argv) {
    if (argc < 2) {
        return 1;
    }

    TCCState* s = tcc_new();
    if (!s) {
        return 1;
    }

    tcc_set_output_type(s, TCC_OUTPUT_MEMORY);

    if (tcc_add_file(s, argv[1]) == -1) {
        tcc_delete(s);
        return 1;
    }

    int script_argc = argc - 1;
    char** script_argv = argv + 1;

    int result = tcc_run(s, script_argc, script_argv);

    tcc_delete(s);
    return result;
}