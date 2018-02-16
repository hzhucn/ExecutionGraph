//! ========================================================================================
//!  ExecutionGraph
//!  Copyright (C) 2014 by Gabriel Nützi <gnuetzi (at) gmail (døt) com>
//!
//!  @date Mon Jan 08 2018
//!  @author Gabriel Nützi, <gnuetzi (at) gmail (døt) com>
//!
//!  This Source Code Form is subject to the terms of the Mozilla Public
//!  License, v. 2.0. If a copy of the MPL was not distributed with this
//!  file, You can obtain one at http://mozilla.org/MPL/2.0/.
//! ========================================================================================

#include "BackendSchemeHandlerFactory.hpp"
#include <cef_parser.h>
#include <wrapper/cef_helpers.h>
#include <wrapper/cef_stream_resource_handler.h>
#include "cefapp/Loggers.hpp"
#include "cefapp/SchemeHandlerHelper.hpp"

CefRefPtr<CefResourceHandler> BackendSchemeHandlerFactory::Create(CefRefPtr<CefBrowser> browser,
                                                                  CefRefPtr<CefFrame> frame,
                                                                  const CefString& scheme_name,
                                                                  CefRefPtr<CefRequest> request)
{
    CEF_REQUIRE_IO_THREAD();
    std::string requestUrl = request->GetURL().ToString();
    CefURLParts urlParts;
    if(CefParseURL(request->GetURL(), urlParts))
    {
        std::string query = CefString(urlParts.query.str).ToString();
        //! todo: why do we get here a urlParts.path.str as "//host/folderA/folderB"
        //! Shouldnt it be : "folderA/folderB".
        //! the host is somehow not parsed?: http://www.magpcss.org/ceforum/viewtopic.php?f=6&t=6048

        // e.g. "////host/folderA/folderB/file.ext"
        std::string temp = CefString(urlParts.path.str).ToString();
        auto path        = schemeHandlerHelper::splitPrefixFromPath(temp, m_pathPrefix);

        if(!path)
        {
            EXECGRAPHGUI_APPLOG_ERROR("BackendSchemeHandlerFactory: requestUrl '{0}' failed!", requestUrl);
            return nullptr;
        }

        std::string requestId = path->filename();
        EXECGRAPHGUI_ASSERTMSG(!requestId.empty(), "Empty requestId in '{0}'!", requestUrl);

        // Printing the binary data ============
        CefRefPtr<CefPostData> postData = request->GetPostData();
        if(postData)
        {
            EXECGRAPHGUI_APPLOG_DEBUG("Received {0} post data elements.", postData->GetElementCount());
            CefPostData::ElementVector elements;
            postData->GetElements(elements);
            for(CefRefPtr<CefPostDataElement> element : elements)
            {
                std::vector<uint8_t> buffer(element->GetBytesCount());
                element->GetBytes(buffer.size(), static_cast<void*>(buffer.data()));
                std::stringstream ss;
                for(auto& byte : buffer)
                {
                    ss << byte << ",";
                }
                EXECGRAPHGUI_APPLOG_DEBUG("Post Data Binary: bytes: '{0}', data: '{1}'", element->GetBytesCount(), ss.str());
            }
        }
        // =====================================
        EXECGRAPHGUI_APPLOG_DEBUG("BackendSchemeHandlerFactory:: Received requestId: '{0}', query: '{1}'", requestId, query);
    }

    EXECGRAPHGUI_APPLOG_ERROR("BackendSchemeHandlerFactory: requestUrl '{0}' failed!", requestUrl);
    return nullptr;
}