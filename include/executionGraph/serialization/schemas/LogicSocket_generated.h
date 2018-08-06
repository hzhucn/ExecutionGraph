// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_LOGICSOCKET_EXECUTIONGRAPH_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_LOGICSOCKET_EXECUTIONGRAPH_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"

namespace executionGraph {
namespace serialization {

struct LogicSocket;

struct LogicSocket FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_INDEX = 4,
    VT_TYPE = 6,
    VT_NAME = 8
  };
  uint64_t index() const {
    return GetField<uint64_t>(VT_INDEX, 0);
  }
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyField<uint64_t>(verifier, VT_INDEX) &&
           VerifyOffsetRequired(verifier, VT_TYPE) &&
           verifier.Verify(type()) &&
           VerifyOffset(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           verifier.EndTable();
  }
};

struct LogicSocketBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_index(uint64_t index) {
    fbb_.AddElement<uint64_t>(LogicSocket::VT_INDEX, index, 0);
  }
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(LogicSocket::VT_TYPE, type);
  }
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(LogicSocket::VT_NAME, name);
  }
  explicit LogicSocketBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  LogicSocketBuilder &operator=(const LogicSocketBuilder &);
  flatbuffers::Offset<LogicSocket> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<LogicSocket>(end);
    fbb_.Required(o, LogicSocket::VT_TYPE);
    return o;
  }
};

inline flatbuffers::Offset<LogicSocket> CreateLogicSocket(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t index = 0,
    flatbuffers::Offset<flatbuffers::String> type = 0,
    flatbuffers::Offset<flatbuffers::String> name = 0) {
  LogicSocketBuilder builder_(_fbb);
  builder_.add_index(index);
  builder_.add_name(name);
  builder_.add_type(type);
  return builder_.Finish();
}

inline flatbuffers::Offset<LogicSocket> CreateLogicSocketDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    uint64_t index = 0,
    const char *type = nullptr,
    const char *name = nullptr) {
  return executionGraph::serialization::CreateLogicSocket(
      _fbb,
      index,
      type ? _fbb.CreateString(type) : 0,
      name ? _fbb.CreateString(name) : 0);
}

}  // namespace serialization
}  // namespace executionGraph

#endif  // FLATBUFFERS_GENERATED_LOGICSOCKET_EXECUTIONGRAPH_SERIALIZATION_H_
