#include <iostream>
#include <fstream>
#include <cstring>
#include <algorithm>
#include <thread>
#include <regex>
#include <mutex>
#include <omp.h>

#include "util.h"
#include "translator.h"
#include "cleanliness.h"

#ifdef useBF
    #ifndef MAX_KMER_SIZE
        #define MAX_KMER_SIZE (((maxK-1)/32) + 1) * 32
    #endif
    #include <bifrost/CompactedDBG.hpp>
    #include <bifrost/ColoredCDBG.hpp>
#endif



using namespace std;

// Symmetric Alignment-free phylogeNomic Splits
// simple efficient re-implementation + filters
#define SANS_VERSION "2.2_12A"    // SANS serif

/**
 * This is the entry point of the program.
 *
 * @param argc number of cmd args
 * @param argv cmd args
 * @return exit status
 */ 
int main(int argc, char* argv[]);

void apply_filter(string filter, string newick, std::function<string(const uint64_t&)> map, multiset<pair<double, color_t>, greater<>>* split_list_ptr, bool verbose);
