// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_NODEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_NODEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"
#include "flatbuffers/flexbuffers.h"

#include "LogicNode_generated.h"
#include "SocketTypeDescription_generated.h"

namespace executionGraphGUI {
namespace serialization {

struct NodeDescription;

struct NodeDescription FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NODE = 4,
    VT_INPUTSOCKETS = 6,
    VT_OUTPUTSOCKETS = 8
  };
  const executionGraph::serialization::LogicNode *node() const {
    return GetPointer<const executionGraph::serialization::LogicNode *>(VT_NODE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>> *inputSockets() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>> *>(VT_INPUTSOCKETS);
  }
  const flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>> *outputSockets() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>> *>(VT_OUTPUTSOCKETS);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NODE) &&
           verifier.VerifyTable(node()) &&
           VerifyOffset(verifier, VT_INPUTSOCKETS) &&
           verifier.Verify(inputSockets()) &&
           verifier.VerifyVectorOfTables(inputSockets()) &&
           VerifyOffset(verifier, VT_OUTPUTSOCKETS) &&
           verifier.Verify(outputSockets()) &&
           verifier.VerifyVectorOfTables(outputSockets()) &&
           verifier.EndTable();
  }
};

struct NodeDescriptionBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_node(flatbuffers::Offset<executionGraph::serialization::LogicNode> node) {
    fbb_.AddOffset(NodeDescription::VT_NODE, node);
  }
  void add_inputSockets(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>>> inputSockets) {
    fbb_.AddOffset(NodeDescription::VT_INPUTSOCKETS, inputSockets);
  }
  void add_outputSockets(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>>> outputSockets) {
    fbb_.AddOffset(NodeDescription::VT_OUTPUTSOCKETS, outputSockets);
  }
  explicit NodeDescriptionBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  NodeDescriptionBuilder &operator=(const NodeDescriptionBuilder &);
  flatbuffers::Offset<NodeDescription> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<NodeDescription>(end);
    fbb_.Required(o, NodeDescription::VT_NODE);
    return o;
  }
};

inline flatbuffers::Offset<NodeDescription> CreateNodeDescription(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<executionGraph::serialization::LogicNode> node = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>>> inputSockets = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<SocketTypeDescription>>> outputSockets = 0) {
  NodeDescriptionBuilder builder_(_fbb);
  builder_.add_outputSockets(outputSockets);
  builder_.add_inputSockets(inputSockets);
  builder_.add_node(node);
  return builder_.Finish();
}

inline flatbuffers::Offset<NodeDescription> CreateNodeDescriptionDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<executionGraph::serialization::LogicNode> node = 0,
    const std::vector<flatbuffers::Offset<SocketTypeDescription>> *inputSockets = nullptr,
    const std::vector<flatbuffers::Offset<SocketTypeDescription>> *outputSockets = nullptr) {
  return executionGraphGUI::serialization::CreateNodeDescription(
      _fbb,
      node,
      inputSockets ? _fbb.CreateVector<flatbuffers::Offset<SocketTypeDescription>>(*inputSockets) : 0,
      outputSockets ? _fbb.CreateVector<flatbuffers::Offset<SocketTypeDescription>>(*outputSockets) : 0);
}

}  // namespace serialization
}  // namespace executionGraphGUI

#endif  // FLATBUFFERS_GENERATED_NODEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_
