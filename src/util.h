#pragma once

// system includes
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <tuple>
#include <vector>

// library includes
#include <boost/filesystem.hpp>
#include <args.hxx>
#include <linuxdeploy/core/log.h>

typedef struct {
    bool success;
    int retcode;
    std::string stdoutOutput;
    std::string stderrOutput;
} procOutput;

procOutput check_command(const std::vector<std::string> &args);

template<typename Iter>
std::string join(Iter beg, Iter end) {
    std::stringstream rv;

    if (beg != end) {
        rv << *beg;

        for_each(++beg, end, [&rv](const std::string &s) {
            rv << " " << s;
        });
    }

    return rv.str();
}

std::map<std::string, std::string> queryQmake(const boost::filesystem::path& qmakePath);

boost::filesystem::path findQmake();

bool pathContainsFile(boost::filesystem::path dir, boost::filesystem::path file);

std::string join(const std::vector<std::string> &list);

std::string join(const std::set<std::string> &list);

bool strStartsWith(const std::string &str, const std::string &prefix);

bool strEndsWith(const std::string &str, const std::string &suffix);

bool isQtDebugSymbolFile(const std::string& filename);
bool isQtDebugSymbolFile(const boost::filesystem::path& path);
