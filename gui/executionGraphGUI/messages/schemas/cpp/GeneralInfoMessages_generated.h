// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_GENERALINFOMESSAGES_EXECUTIONGRAPHGUI_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_GENERALINFOMESSAGES_EXECUTIONGRAPHGUI_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"

#include "executionGraph/serialization/schemas/cpp/GraphTypeDescription_generated.h"
#include "executionGraph/serialization/schemas/cpp/NodeTypeDescription_generated.h"
#include "executionGraph/serialization/schemas/cpp/SocketTypeDescription_generated.h"

namespace executionGraphGUI {
namespace serialization {

struct GetAllGraphTypeDescriptionsResponse;

struct GetAllGraphTypeDescriptionsResponse FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_GRAPHSTYPES = 4
  };
  const flatbuffers::Vector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>> *graphsTypes() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>> *>(VT_GRAPHSTYPES);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffset(verifier, VT_GRAPHSTYPES) &&
           verifier.Verify(graphsTypes()) &&
           verifier.VerifyVectorOfTables(graphsTypes()) &&
           verifier.EndTable();
  }
};

struct GetAllGraphTypeDescriptionsResponseBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_graphsTypes(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>>> graphsTypes) {
    fbb_.AddOffset(GetAllGraphTypeDescriptionsResponse::VT_GRAPHSTYPES, graphsTypes);
  }
  explicit GetAllGraphTypeDescriptionsResponseBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  GetAllGraphTypeDescriptionsResponseBuilder &operator=(const GetAllGraphTypeDescriptionsResponseBuilder &);
  flatbuffers::Offset<GetAllGraphTypeDescriptionsResponse> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<GetAllGraphTypeDescriptionsResponse>(end);
    return o;
  }
};

inline flatbuffers::Offset<GetAllGraphTypeDescriptionsResponse> CreateGetAllGraphTypeDescriptionsResponse(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>>> graphsTypes = 0) {
  GetAllGraphTypeDescriptionsResponseBuilder builder_(_fbb);
  builder_.add_graphsTypes(graphsTypes);
  return builder_.Finish();
}

inline flatbuffers::Offset<GetAllGraphTypeDescriptionsResponse> CreateGetAllGraphTypeDescriptionsResponseDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const std::vector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>> *graphsTypes = nullptr) {
  return executionGraphGUI::serialization::CreateGetAllGraphTypeDescriptionsResponse(
      _fbb,
      graphsTypes ? _fbb.CreateVector<flatbuffers::Offset<executionGraph::serialization::GraphTypeDescription>>(*graphsTypes) : 0);
}

}  // namespace serialization
}  // namespace executionGraphGUI

#endif  // FLATBUFFERS_GENERATED_GENERALINFOMESSAGES_EXECUTIONGRAPHGUI_SERIALIZATION_H_