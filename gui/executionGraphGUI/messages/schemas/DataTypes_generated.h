// automatically generated by the FlatBuffers compiler, do not modify


#ifndef FLATBUFFERS_GENERATED_DATATYPES_EXECUTIONGRAPHGUI_SERIALIZATION_H_
#define FLATBUFFERS_GENERATED_DATATYPES_EXECUTIONGRAPHGUI_SERIALIZATION_H_

#include "flatbuffers/flatbuffers.h"

namespace executionGraphGUI {
namespace serialization {

struct Bool;

struct ConstructorKV;

enum ConstructorValue {
  ConstructorValue_NONE = 0,
  ConstructorValue_Bool = 1,
  ConstructorValue_MIN = ConstructorValue_NONE,
  ConstructorValue_MAX = ConstructorValue_Bool
};

inline const ConstructorValue (&EnumValuesConstructorValue())[2] {
  static const ConstructorValue values[] = {
    ConstructorValue_NONE,
    ConstructorValue_Bool
  };
  return values;
}

inline const char * const *EnumNamesConstructorValue() {
  static const char * const names[] = {
    "NONE",
    "Bool",
    nullptr
  };
  return names;
}

inline const char *EnumNameConstructorValue(ConstructorValue e) {
  const size_t index = static_cast<int>(e);
  return EnumNamesConstructorValue()[index];
}

template<typename T> struct ConstructorValueTraits {
  static const ConstructorValue enum_value = ConstructorValue_NONE;
};

template<> struct ConstructorValueTraits<Bool> {
  static const ConstructorValue enum_value = ConstructorValue_Bool;
};

bool VerifyConstructorValue(flatbuffers::Verifier &verifier, const void *obj, ConstructorValue type);
bool VerifyConstructorValueVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types);

FLATBUFFERS_MANUALLY_ALIGNED_STRUCT(1) Bool FLATBUFFERS_FINAL_CLASS {
 private:
  uint8_t value_;

 public:
  Bool() {
    memset(this, 0, sizeof(Bool));
  }
  Bool(bool _value)
      : value_(flatbuffers::EndianScalar(static_cast<uint8_t>(_value))) {
  }
  bool value() const {
    return flatbuffers::EndianScalar(value_) != 0;
  }
};
FLATBUFFERS_STRUCT_END(Bool, 1);

struct ConstructorKV FLATBUFFERS_FINAL_CLASS : private flatbuffers::Table {
  enum {
    VT_KEY = 4,
    VT_VALUE_TYPE = 6,
    VT_VALUE = 8
  };
  const flatbuffers::String *key() const {
    return GetPointer<const flatbuffers::String *>(VT_KEY);
  }
  const flatbuffers::Vector<uint8_t> *value_type() const {
    return GetPointer<const flatbuffers::Vector<uint8_t> *>(VT_VALUE_TYPE);
  }
  const flatbuffers::Vector<flatbuffers::Offset<void>> *value() const {
    return GetPointer<const flatbuffers::Vector<flatbuffers::Offset<void>> *>(VT_VALUE);
  }
  bool Verify(flatbuffers::Verifier &verifier) const {
    return VerifyTableStart(verifier) &&
           VerifyOffsetRequired(verifier, VT_KEY) &&
           verifier.Verify(key()) &&
           VerifyOffsetRequired(verifier, VT_VALUE_TYPE) &&
           verifier.Verify(value_type()) &&
           VerifyOffsetRequired(verifier, VT_VALUE) &&
           verifier.Verify(value()) &&
           VerifyConstructorValueVector(verifier, value(), value_type()) &&
           verifier.EndTable();
  }
};

struct ConstructorKVBuilder {
  flatbuffers::FlatBufferBuilder &fbb_;
  flatbuffers::uoffset_t start_;
  void add_key(flatbuffers::Offset<flatbuffers::String> key) {
    fbb_.AddOffset(ConstructorKV::VT_KEY, key);
  }
  void add_value_type(flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value_type) {
    fbb_.AddOffset(ConstructorKV::VT_VALUE_TYPE, value_type);
  }
  void add_value(flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> value) {
    fbb_.AddOffset(ConstructorKV::VT_VALUE, value);
  }
  explicit ConstructorKVBuilder(flatbuffers::FlatBufferBuilder &_fbb)
        : fbb_(_fbb) {
    start_ = fbb_.StartTable();
  }
  ConstructorKVBuilder &operator=(const ConstructorKVBuilder &);
  flatbuffers::Offset<ConstructorKV> Finish() {
    const auto end = fbb_.EndTable(start_);
    auto o = flatbuffers::Offset<ConstructorKV>(end);
    fbb_.Required(o, ConstructorKV::VT_KEY);
    fbb_.Required(o, ConstructorKV::VT_VALUE_TYPE);
    fbb_.Required(o, ConstructorKV::VT_VALUE);
    return o;
  }
};

inline flatbuffers::Offset<ConstructorKV> CreateConstructorKV(
    flatbuffers::FlatBufferBuilder &_fbb,
    flatbuffers::Offset<flatbuffers::String> key = 0,
    flatbuffers::Offset<flatbuffers::Vector<uint8_t>> value_type = 0,
    flatbuffers::Offset<flatbuffers::Vector<flatbuffers::Offset<void>>> value = 0) {
  ConstructorKVBuilder builder_(_fbb);
  builder_.add_value(value);
  builder_.add_value_type(value_type);
  builder_.add_key(key);
  return builder_.Finish();
}

inline flatbuffers::Offset<ConstructorKV> CreateConstructorKVDirect(
    flatbuffers::FlatBufferBuilder &_fbb,
    const char *key = nullptr,
    const std::vector<uint8_t> *value_type = nullptr,
    const std::vector<flatbuffers::Offset<void>> *value = nullptr) {
  return executionGraphGUI::serialization::CreateConstructorKV(
      _fbb,
      key ? _fbb.CreateString(key) : 0,
      value_type ? _fbb.CreateVector<uint8_t>(*value_type) : 0,
      value ? _fbb.CreateVector<flatbuffers::Offset<void>>(*value) : 0);
}

inline bool VerifyConstructorValue(flatbuffers::Verifier &verifier, const void *obj, ConstructorValue type) {
  switch (type) {
    case ConstructorValue_NONE: {
      return true;
    }
    case ConstructorValue_Bool: {
      return true;
    }
    default: return false;
  }
}

inline bool VerifyConstructorValueVector(flatbuffers::Verifier &verifier, const flatbuffers::Vector<flatbuffers::Offset<void>> *values, const flatbuffers::Vector<uint8_t> *types) {
  if (!values || !types) return !values && !types;
  if (values->size() != types->size()) return false;
  for (flatbuffers::uoffset_t i = 0; i < values->size(); ++i) {
    if (!VerifyConstructorValue(
        verifier,  values->Get(i), types->GetEnum<ConstructorValue>(i))) {
      return false;
    }
  }
  return true;
}

}  // namespace serialization
}  // namespace executionGraphGUI

#endif  // FLATBUFFERS_GENERATED_DATATYPES_EXECUTIONGRAPHGUI_SERIALIZATION_H_