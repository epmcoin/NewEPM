// Copyright (c) 2014-2018 The Dash Core developers
// Copyright (c) 2018-2019 The PACGlobal developers
// Copyright (c) 2019 The Extreme Private MasternodeCoin developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef EPMCOIN_STACKTRACES_H
#define EPMCOIN_STACKTRACES_H

#include <string>
#include <sstream>
#include <exception>

#include <cxxabi.h>

#include "tinyformat.h"

std::string DemangleSymbol(const std::string& name);

std::string GetCurrentStacktraceStr(size_t skip = 0, size_t max_depth = 16);

std::string GetExceptionStacktraceStr(const std::exception_ptr& e);
std::string GetPrettyExceptionStr(const std::exception_ptr& e);

template<typename T>
std::string GetExceptionWhat(const T& e);

template<>
inline std::string GetExceptionWhat(const std::exception& e)
{
    return e.what();
}

// Default implementation
template<typename T>
inline std::string GetExceptionWhat(const T& e)
{
    std::ostringstream s;
    s << e;
    return s.str();
}

void RegisterPrettyTerminateHander();
void RegisterPrettySignalHandlers();

#endif//EPM_STACKTRACES_H
