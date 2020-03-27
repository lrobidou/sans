#include <iostream>

#include <map>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <limits>

using namespace std;

#include "kmer32.h"
#include "kmerXX.h"

#if K > 32 // store k-mers in a bitset, allows larger k-mers
    typedef kmerXX kmer;
    typedef bitset<2*K> kmer_t;
#else // store k-mer bits in an integer, optimizes performance
    typedef kmer32 kmer;
    typedef uint64_t kmer_t;
#endif

#include "color64.h"
#include "colorXX.h"

#if N > 64 // store colors in a bitset, allows more input files
    typedef colorXX color;
    typedef bitset<N> color_t;
#else // store color bits in an integer, optimizes performance
    typedef color64 color;
    typedef uint64_t color_t;
#endif

class graph {

private:

    /**
     * This is a hash table mapping k-mers to colors [O(1)].
     */
    static unordered_map<kmer_t, color_t> kmer_table;

    /**
     * This is a hash table mapping colors to weights [O(1)].
     */
    static unordered_map<color_t, array<uint32_t,2>> color_table;

    /**
     * This is an ordered tree collecting the splits [O(log n)].
     */
    static multimap<double, color_t, greater<>> split_list;

public:

    /**
     * This is the size of the top list.
     */
    static uint64_t t;

    /**
     * This function initializes the top list size.
     *
     * @param t top list size
     */
    static void init(uint64_t& top_size);

    /**
     * This function extracts k-mers from a sequence and adds them to the hash table.
     *
     * @param str dna sequence
     * @param color color flag
     */
    static void add_kmers(string& str, uint64_t& color);

    /**
     * This function extracts k-mers from a sequence and adds them to the hash table.
     *
     * @param str dna sequence
     * @param color color flag
     * @param max_iupac allowed number of ambiguous k-mers per position
     */
    static void add_kmers_iupac(string& str, uint64_t& color, uint64_t& max_iupac);

    /**
     * This function iterates over the hash table and calculates the split weights.
     *
     * @param mean weight function
     */
    static void add_weights(double mean(uint32_t&, uint32_t&));

    /**
     * This function filters a maximum weight 1-tree compatible subset.
     */
    static void filter_tree1();

    /**
     * This function filters a maximum weight 2-tree compatible subset.
     */
    static void filter_tree2();

    /**
     * This function does not filter the splits in the output list.
     */
    static void filter_none();

    /**
     * This function prints the splits ordered by weight to an output file stream.
     *
     * @param out output stream
     * @param names file names
     */
    static void output_splits(ostream& out, vector<string>& names);

protected:

    /**
     * This function tests if a split is compatible with an existing set of splits.
     *
     * @param color new split
     * @param color_set set of splits
     * @return true, if compatible
     */
    static bool test_set(color_t& color, vector<color_t>& color_set);

    /**
     * This function shifts a set of iupac ambiguous k-mers to the right.
     *
     * @param prev set of k-mers
     * @param input iupac character
     */
    static void shift_right_iupac(unordered_set<kmer_t>& prev, char& input);

};
