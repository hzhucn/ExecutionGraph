//! ========================================================================================
//!  ExecutionGraph
//!  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//!
//!  @date Tue Jan 09 2018
//!  @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
//!
//!  This Source Code Form is subject to the terms of the Mozilla Public
//!  License, v. 2.0. If a copy of the MPL was not distributed with this
//!  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//! ========================================================================================

#ifndef executionGraph_common_ObjectID_hpp
#define executionGraph_common_ObjectID_hpp

#include <rttr/type>
#include "executionGraph/common/Identifier.hpp"

namespace executionGraph
{
    /* ---------------------------------------------------------------------------------------*/
    /*!
        Interface which provides an ID.

        @date Sun Feb 18 2018
        @author Gabriel Nützi, gnuetzi (at) gmail (døt) com
    */
    /* ---------------------------------------------------------------------------------------*/
    class IObjectID
    {
        RTTR_ENABLE()
    protected:
        IObjectID() = default;

    public:
        virtual ~IObjectID() = default;

    public:
        virtual const Id& getId() const = 0;
    };
}  // namespace executionGraph

    //! Macro to define the implementation.
#    define EXECGRAPH_OBJECT_ID_DECLARATION                     \
    public:                                                     \
        using Id = executionGraph::Id;                          \
        const Id& getId() const override final { return m_id; } \
                                                                \
    private:                                                    \
        const Id m_id;

#    define EXECGRAPH_OBJECT_ID_NON_VIRTUAL_DECLARATION \
    public:                                             \
        using Id = executionGraph::Id;                  \
        const Id& getId() const { return m_id; }        \
                                                        \
    private:                                            \
        const Id m_id;
#endif