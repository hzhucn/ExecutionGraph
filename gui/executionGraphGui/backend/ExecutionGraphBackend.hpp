//! ========================================================================================
//!  ExecutionGraph
//!  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//!
//!  @date Sun Jan 14 2018
//!  @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
//!
//!  This Source Code Form is subject to the terms of the Mozilla Public
//!  License, v. 2.0. If a copy of the MPL was not distributed with this
//!  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//! ========================================================================================

#ifndef executionGraphGui_backend_ExecutionGraphBackend_hpp
#define executionGraphGui_backend_ExecutionGraphBackend_hpp

#include "backend/Backend.hpp"
#include <executionGraph/common/ObjectID.hpp>

class ExecutionGraphBackend : public Backend
{
public:
    using Backend::Id;
    using Backend::Handler;
    using Backend::HandlerList;
    static const Id defaultId;

public:
    ExecutionGraphBackend(const Id& id = defaultId)
        : Backend(id), m_dummyHandler(Id("DummyHandler"))
    {}
    virtual ~ExecutionGraphBackend() override = default;

public:
    //! Get the Messagehandlers
    virtual HandlerList getMessageHandlers() override { return std::initializer_list<Handler*>{ &m_dummyHandler }; } 

private:
    Handler m_dummyHandler; //! A single dummy test handler.

};

#endif