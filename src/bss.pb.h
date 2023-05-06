// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: bss.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_bss_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_bss_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3012000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3012004 < PROTOBUF_MIN_PROTOC_VERSION
#error This file was generated by an older version of protoc which is
#error incompatible with your Protocol Buffer headers. Please
#error regenerate this file with a newer version of protoc.
#endif

#include <google/protobuf/port_undef.inc>
#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/arena.h>
#include <google/protobuf/arenastring.h>
#include <google/protobuf/generated_message_table_driven.h>
#include <google/protobuf/generated_message_util.h>
#include <google/protobuf/inlined_string_field.h>
#include <google/protobuf/metadata_lite.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_bss_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_bss_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[1]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_bss_2eproto;
namespace bss {
class Measurement;
class MeasurementDefaultTypeInternal;
extern MeasurementDefaultTypeInternal _Measurement_default_instance_;
}  // namespace bss
PROTOBUF_NAMESPACE_OPEN
template<> ::bss::Measurement* Arena::CreateMaybeMessage<::bss::Measurement>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace bss {

// ===================================================================

class Measurement PROTOBUF_FINAL :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:bss.Measurement) */ {
 public:
  inline Measurement() : Measurement(nullptr) {};
  virtual ~Measurement();

  Measurement(const Measurement& from);
  Measurement(Measurement&& from) noexcept
    : Measurement() {
    *this = ::std::move(from);
  }

  inline Measurement& operator=(const Measurement& from) {
    CopyFrom(from);
    return *this;
  }
  inline Measurement& operator=(Measurement&& from) noexcept {
    if (GetArena() == from.GetArena()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::PROTOBUF_NAMESPACE_ID::Descriptor* GetDescriptor() {
    return GetMetadataStatic().descriptor;
  }
  static const ::PROTOBUF_NAMESPACE_ID::Reflection* GetReflection() {
    return GetMetadataStatic().reflection;
  }
  static const Measurement& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const Measurement* internal_default_instance() {
    return reinterpret_cast<const Measurement*>(
               &_Measurement_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(Measurement& a, Measurement& b) {
    a.Swap(&b);
  }
  inline void Swap(Measurement* other) {
    if (other == this) return;
    if (GetArena() == other->GetArena()) {
      InternalSwap(other);
    } else {
      ::PROTOBUF_NAMESPACE_ID::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(Measurement* other) {
    if (other == this) return;
    GOOGLE_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline Measurement* New() const final {
    return CreateMaybeMessage<Measurement>(nullptr);
  }

  Measurement* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<Measurement>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const Measurement& from);
  void MergeFrom(const Measurement& from);
  PROTOBUF_ATTRIBUTE_REINITIALIZES void Clear() final;
  bool IsInitialized() const final;

  size_t ByteSizeLong() const final;
  const char* _InternalParse(const char* ptr, ::PROTOBUF_NAMESPACE_ID::internal::ParseContext* ctx) final;
  ::PROTOBUF_NAMESPACE_ID::uint8* _InternalSerialize(
      ::PROTOBUF_NAMESPACE_ID::uint8* target, ::PROTOBUF_NAMESPACE_ID::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const final { return _cached_size_.Get(); }

  private:
  inline void SharedCtor();
  inline void SharedDtor();
  void SetCachedSize(int size) const final;
  void InternalSwap(Measurement* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "bss.Measurement";
  }
  protected:
  explicit Measurement(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  private:
  static void ArenaDtor(void* object);
  inline void RegisterArenaDtor(::PROTOBUF_NAMESPACE_ID::Arena* arena);
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_bss_2eproto);
    return ::descriptor_table_bss_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kNodeIdFieldNumber = 1,
    kTemperatureFieldNumber = 2,
    kHumidityFieldNumber = 3,
    kAmbientLightFieldNumber = 4,
  };
  // uint32 node_id = 1;
  void clear_node_id();
  ::PROTOBUF_NAMESPACE_ID::uint32 node_id() const;
  void set_node_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_node_id() const;
  void _internal_set_node_id(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // sint32 temperature = 2;
  bool has_temperature() const;
  private:
  bool _internal_has_temperature() const;
  public:
  void clear_temperature();
  ::PROTOBUF_NAMESPACE_ID::int32 temperature() const;
  void set_temperature(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_temperature() const;
  void _internal_set_temperature(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // uint32 humidity = 3;
  bool has_humidity() const;
  private:
  bool _internal_has_humidity() const;
  public:
  void clear_humidity();
  ::PROTOBUF_NAMESPACE_ID::uint32 humidity() const;
  void set_humidity(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_humidity() const;
  void _internal_set_humidity(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // uint32 ambient_light = 4;
  bool has_ambient_light() const;
  private:
  bool _internal_has_ambient_light() const;
  public:
  void clear_ambient_light();
  ::PROTOBUF_NAMESPACE_ID::uint32 ambient_light() const;
  void set_ambient_light(::PROTOBUF_NAMESPACE_ID::uint32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::uint32 _internal_ambient_light() const;
  void _internal_set_ambient_light(::PROTOBUF_NAMESPACE_ID::uint32 value);
  public:

  // @@protoc_insertion_point(class_scope:bss.Measurement)
 private:
  class _Internal;

  template <typename T> friend class ::PROTOBUF_NAMESPACE_ID::Arena::InternalHelper;
  typedef void InternalArenaConstructable_;
  typedef void DestructorSkippable_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::uint32 node_id_;
  ::PROTOBUF_NAMESPACE_ID::int32 temperature_;
  ::PROTOBUF_NAMESPACE_ID::uint32 humidity_;
  ::PROTOBUF_NAMESPACE_ID::uint32 ambient_light_;
  friend struct ::TableStruct_bss_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// Measurement

// uint32 node_id = 1;
inline void Measurement::clear_node_id() {
  node_id_ = 0u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::_internal_node_id() const {
  return node_id_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::node_id() const {
  // @@protoc_insertion_point(field_get:bss.Measurement.node_id)
  return _internal_node_id();
}
inline void Measurement::_internal_set_node_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  
  node_id_ = value;
}
inline void Measurement::set_node_id(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_node_id(value);
  // @@protoc_insertion_point(field_set:bss.Measurement.node_id)
}

// sint32 temperature = 2;
inline bool Measurement::_internal_has_temperature() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool Measurement::has_temperature() const {
  return _internal_has_temperature();
}
inline void Measurement::clear_temperature() {
  temperature_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Measurement::_internal_temperature() const {
  return temperature_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 Measurement::temperature() const {
  // @@protoc_insertion_point(field_get:bss.Measurement.temperature)
  return _internal_temperature();
}
inline void Measurement::_internal_set_temperature(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  temperature_ = value;
}
inline void Measurement::set_temperature(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_temperature(value);
  // @@protoc_insertion_point(field_set:bss.Measurement.temperature)
}

// uint32 humidity = 3;
inline bool Measurement::_internal_has_humidity() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool Measurement::has_humidity() const {
  return _internal_has_humidity();
}
inline void Measurement::clear_humidity() {
  humidity_ = 0u;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::_internal_humidity() const {
  return humidity_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::humidity() const {
  // @@protoc_insertion_point(field_get:bss.Measurement.humidity)
  return _internal_humidity();
}
inline void Measurement::_internal_set_humidity(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000002u;
  humidity_ = value;
}
inline void Measurement::set_humidity(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_humidity(value);
  // @@protoc_insertion_point(field_set:bss.Measurement.humidity)
}

// uint32 ambient_light = 4;
inline bool Measurement::_internal_has_ambient_light() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool Measurement::has_ambient_light() const {
  return _internal_has_ambient_light();
}
inline void Measurement::clear_ambient_light() {
  ambient_light_ = 0u;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::_internal_ambient_light() const {
  return ambient_light_;
}
inline ::PROTOBUF_NAMESPACE_ID::uint32 Measurement::ambient_light() const {
  // @@protoc_insertion_point(field_get:bss.Measurement.ambient_light)
  return _internal_ambient_light();
}
inline void Measurement::_internal_set_ambient_light(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _has_bits_[0] |= 0x00000004u;
  ambient_light_ = value;
}
inline void Measurement::set_ambient_light(::PROTOBUF_NAMESPACE_ID::uint32 value) {
  _internal_set_ambient_light(value);
  // @@protoc_insertion_point(field_set:bss.Measurement.ambient_light)
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)

}  // namespace bss

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_bss_2eproto