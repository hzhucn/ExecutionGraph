// =========================================================================================
//  ExecutionGraph
//  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//
//  @date Sun Mar 11 2018
//  @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
//
//  This Source Code Form is subject to the terms of the Mozilla Public
//  License, v. 2.0. If a copy of the MPL was not distributed with this
//  file, You can obtain one at http://mozilla.org/MPL/2.0/.
// =========================================================================================

#ifndef executionGraphGUI_cefapp_BackendRequestDispatcher_hpp
#define executionGraphGUI_cefapp_BackendRequestDispatcher_hpp

#include "backend/BackendRequestHandler.hpp"
#include "cefapp/RequestCef.hpp"
#include "cefapp/ResponseCef.hpp"
#include "common/RequestDispatcher.hpp"

/* ---------------------------------------------------------------------------------------*/
/*!
    The actual backend request dispatcher.

    @date Sun Mar 11 2018
    @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
 */
/* ---------------------------------------------------------------------------------------*/
class BackendRequestDispatcher final : public RequestDispatcher<BackendRequestHandler,
                                                                Request,
                                                                ResponsePromise>
{
public:
    using Base = RequestDispatcher<BackendRequestHandler,
                                   Request,
                                   ResponsePromise>;

public:
    template<typename... Args>
    BackendRequestDispatcher(Args&&... args)
        : Base(std::forward<Args>(args)...)
    {}

    virtual ~BackendRequestDispatcher() = default;
};

#endif