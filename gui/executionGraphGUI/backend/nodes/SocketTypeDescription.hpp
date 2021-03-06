// =========================================================================================
//  ExecutionGraph
//  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//
//  @date Fri Jul 06 2018
//  @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
//
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
// =========================================================================================

#ifndef executionGraphGUI_backend_nodes_SocketTypeDescription_hpp
#define executionGraphGUI_backend_nodes_SocketTypeDescription_hpp

#include <string>

//! A simple node description, describing a LogicSocket.
struct SocketTypeDescription
{
    SocketTypeDescription(const std::string& rtti)
        : m_rtti(rtti), m_name(m_rtti)
    {}
    SocketTypeDescription(const std::string& rtti, const std::string& name)
        : m_rtti(rtti), m_name(name)
    {}

    std::string m_rtti;  //!< The unique RTTI name of the socket
    std::string m_name;  //!< The readable name of the socket
};

#endif