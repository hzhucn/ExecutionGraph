// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_SOCKETTYPEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_SOCKETTYPEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"

namespace executionGraphGUI {
namespace serialization {

struct SocketTypeDescription;

struct SocketTypeDescription FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_NAME = 4,
    VT_TYPE = 6
  };
  const flatbuffers::String *name() const {
    return GetPointer<const flatbuffers::String *>(VT_NAME);
  }
  const flatbuffers::String *type() const {
    return GetPointer<const flatbuffers::String *>(VT_TYPE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_NAME) &&
           verifier.Verify(name()) &&
           VerifyOffsetRequired(verifier, VT_TYPE) &&
           verifier.Verify(type()) &&
           verifier.EndTable();
  }
};

struct SocketTypeDescriptionBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_name(flatbuffers::Offset<flatbuffers::String> name) {
    fbb_.AddOffset(SocketTypeDescription::VT_NAME, name);
  }
  void add_type(flatbuffers::Offset<flatbuffers::String> type) {
    fbb_.AddOffset(SocketTypeDescription::VT_TYPE, type);
  }
  explicit SocketTypeDescriptionBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  SocketTypeDescriptionBuilder &operator=(const SocketTypeDescriptionBuilder &);
  flatbuffers::Offset<SocketTypeDescription> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<SocketTypeDescription>(end);
    fbb_.Required(o, SocketTypeDescription::VT_NAME);
    fbb_.Required(o, SocketTypeDescription::VT_TYPE);
    return o;
  }
};

inline flatbuffers::Offset<SocketTypeDescription> CreateSocketTypeDescription(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> name = 0,
    flatbuffers::Offset<flatbuffers::String> type = 0) {
  SocketTypeDescriptionBuilder builder_(_fbb);
  builder_.add_type(type);
  builder_.add_name(name);
  return builder_.Finish();
}

inline flatbuffers::Offset<SocketTypeDescription> CreateSocketTypeDescriptionDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *name = nullptr,
    const char *type = nullptr) {
  return executionGraphGUI::serialization::CreateSocketTypeDescription(
      _fbb,
      name ? _fbb.CreateString(name) : 0,
      type ? _fbb.CreateString(type) : 0);
}

}  // namespace serialization
}  // namespace executionGraphGUI

#endif  // FLATBUFFERS_GENERATED_SOCKETTYPEDESCRIPTION_EXECUTIONGRAPHGUI_SERIALIZATION_H_