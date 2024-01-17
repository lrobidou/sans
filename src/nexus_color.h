#include <string>
#include <iostream>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <cctype>
#include <algorithm>
#include <vector>
#include <cmath>
#include <unordered_map>

using namespace std;

#ifndef SRC_NEXUS_COLOR_H
#define SRC_NEXUS_COLOR_H

namespace nexus_color{

    /**
     * This function adds a network to the initially generated nexus file via SplitsTree.
     * @param nexus_file Path to the initial nexus file
     * @param verbose If info should be printed
     * @param splitstree_path Path to SplitsTree
     */
    void mod_via_splitstree(const string& nexus_file, const string& pdf, bool verbose = false, const string splitstree_path = "SplitsTree");

    /**
     * This function adds color values to the nodes of a given nexus file. Already colored nodes
     * will not be recolored.
     * @param nexus_file The nexus file containing the network to be colored.
     * @param tax_grp_file A tab seperated file containing the taxa name and their respective group.
     * @param grp_clr_file A tab separated file containing the group and 3 integers for the rgb value of the color.
     */
    void color_nexus(const string& nexus_file, const string& tax_grp_file, const string& grp_clr_file = "");

    /**
     * Tests whether a program can be found and executed.
     * @param programName Program to be tested.
     * @return bool if program is executable
     */
    bool program_in_path(const string& programName);
}

#endif //SRC_NEXUS_COLOR_H