//! ========================================================================================
//!  ExecutionGraph
//!  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//!
//!  @date Mon Jan 15 2018
//!  @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
//!
//!  This Source Code Form is subject to the terms of the Mozilla Public
//!  License, v. 2.0. If a copy of the MPL was not distributed with this
//!  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//! ========================================================================================

#ifndef executionGraphGui_backend_requestHandlers_GraphInfoRequestHandler_hpp
#define executionGraphGui_backend_requestHandlers_GraphInfoRequestHandler_hpp

#include <backend/BackendRequestHandler.hpp>
#include <common/FunctionMap.hpp>

class ExecutionGraphBackend;

class GraphInfoRequestHandler final : public BackendRequestHandler
{
    RTTR_ENABLE(BackendRequestHandler)

public:
    using Id       = BackendRequestHandler::Id;
    using Function = std::function<void(GraphInfoRequestHandler&, const Request& request, ResponsePromise& response)>;

public:
    GraphInfoRequestHandler(std::shared_ptr<ExecutionGraphBackend> backend,
                            const Id& id = "GraphInfoRequestHandler");

    void handleRequest(const Request& request, ResponsePromise& response) override;
    const std::unordered_set<std::string>& getRequestTypes() const override;

private:
    void handleGetAllGraphTypeDescriptions(const Request& request,
                                           ResponsePromise& response);

private:
    static FunctionMap<Function> initFunctionMap();
    static const FunctionMap<Function> m_functionMap;

    std::shared_ptr<ExecutionGraphBackend> m_backend;
};

#endif
