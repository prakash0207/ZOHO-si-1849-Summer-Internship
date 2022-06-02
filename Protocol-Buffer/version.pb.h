// Generated by the protocol buffer compiler.  DO NOT EDIT!
// source: version.proto

#ifndef GOOGLE_PROTOBUF_INCLUDED_version_2eproto
#define GOOGLE_PROTOBUF_INCLUDED_version_2eproto

#include <limits>
#include <string>

#include <google/protobuf/port_def.inc>
#if PROTOBUF_VERSION < 3011000
#error This file was generated by a newer version of protoc which is
#error incompatible with your Protocol Buffer headers. Please update
#error your headers.
#endif
#if 3011003 < PROTOBUF_MIN_PROTOC_VERSION
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
#include <google/protobuf/metadata.h>
#include <google/protobuf/generated_message_reflection.h>
#include <google/protobuf/message.h>
#include <google/protobuf/repeated_field.h>  // IWYU pragma: export
#include <google/protobuf/extension_set.h>  // IWYU pragma: export
#include <google/protobuf/unknown_field_set.h>
// @@protoc_insertion_point(includes)
#include <google/protobuf/port_def.inc>
#define PROTOBUF_INTERNAL_EXPORT_version_2eproto
PROTOBUF_NAMESPACE_OPEN
namespace internal {
class AnyMetadata;
}  // namespace internal
PROTOBUF_NAMESPACE_CLOSE

// Internal implementation detail -- do not use these members.
struct TableStruct_version_2eproto {
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTableField entries[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::AuxillaryParseTableField aux[]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::ParseTable schema[3]
    PROTOBUF_SECTION_VARIABLE(protodesc_cold);
  static const ::PROTOBUF_NAMESPACE_ID::internal::FieldMetadata field_metadata[];
  static const ::PROTOBUF_NAMESPACE_ID::internal::SerializationTable serialization_table[];
  static const ::PROTOBUF_NAMESPACE_ID::uint32 offsets[];
};
extern const ::PROTOBUF_NAMESPACE_ID::internal::DescriptorTable descriptor_table_version_2eproto;
namespace version {
class FileBook;
class FileBookDefaultTypeInternal;
extern FileBookDefaultTypeInternal _FileBook_default_instance_;
class ParticularFile;
class ParticularFileDefaultTypeInternal;
extern ParticularFileDefaultTypeInternal _ParticularFile_default_instance_;
class ParticularFile_Version;
class ParticularFile_VersionDefaultTypeInternal;
extern ParticularFile_VersionDefaultTypeInternal _ParticularFile_Version_default_instance_;
}  // namespace version
PROTOBUF_NAMESPACE_OPEN
template<> ::version::FileBook* Arena::CreateMaybeMessage<::version::FileBook>(Arena*);
template<> ::version::ParticularFile* Arena::CreateMaybeMessage<::version::ParticularFile>(Arena*);
template<> ::version::ParticularFile_Version* Arena::CreateMaybeMessage<::version::ParticularFile_Version>(Arena*);
PROTOBUF_NAMESPACE_CLOSE
namespace version {

// ===================================================================

class ParticularFile_Version :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:version.ParticularFile.Version) */ {
 public:
  ParticularFile_Version();
  virtual ~ParticularFile_Version();

  ParticularFile_Version(const ParticularFile_Version& from);
  ParticularFile_Version(ParticularFile_Version&& from) noexcept
    : ParticularFile_Version() {
    *this = ::std::move(from);
  }

  inline ParticularFile_Version& operator=(const ParticularFile_Version& from) {
    CopyFrom(from);
    return *this;
  }
  inline ParticularFile_Version& operator=(ParticularFile_Version&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
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
  static const ParticularFile_Version& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ParticularFile_Version* internal_default_instance() {
    return reinterpret_cast<const ParticularFile_Version*>(
               &_ParticularFile_Version_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    0;

  friend void swap(ParticularFile_Version& a, ParticularFile_Version& b) {
    a.Swap(&b);
  }
  inline void Swap(ParticularFile_Version* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ParticularFile_Version* New() const final {
    return CreateMaybeMessage<ParticularFile_Version>(nullptr);
  }

  ParticularFile_Version* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ParticularFile_Version>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ParticularFile_Version& from);
  void MergeFrom(const ParticularFile_Version& from);
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
  void InternalSwap(ParticularFile_Version* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "version.ParticularFile.Version";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_version_2eproto);
    return ::descriptor_table_version_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFilecontentFieldNumber = 3,
    kVersionnoFieldNumber = 1,
    kOperationnoFieldNumber = 2,
  };
  // required string filecontent = 3;
  bool has_filecontent() const;
  private:
  bool _internal_has_filecontent() const;
  public:
  void clear_filecontent();
  const std::string& filecontent() const;
  void set_filecontent(const std::string& value);
  void set_filecontent(std::string&& value);
  void set_filecontent(const char* value);
  void set_filecontent(const char* value, size_t size);
  std::string* mutable_filecontent();
  std::string* release_filecontent();
  void set_allocated_filecontent(std::string* filecontent);
  private:
  const std::string& _internal_filecontent() const;
  void _internal_set_filecontent(const std::string& value);
  std::string* _internal_mutable_filecontent();
  public:

  // required int32 versionno = 1;
  bool has_versionno() const;
  private:
  bool _internal_has_versionno() const;
  public:
  void clear_versionno();
  ::PROTOBUF_NAMESPACE_ID::int32 versionno() const;
  void set_versionno(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_versionno() const;
  void _internal_set_versionno(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 operationno = 2;
  bool has_operationno() const;
  private:
  bool _internal_has_operationno() const;
  public:
  void clear_operationno();
  ::PROTOBUF_NAMESPACE_ID::int32 operationno() const;
  void set_operationno(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_operationno() const;
  void _internal_set_operationno(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:version.ParticularFile.Version)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::internal::ArenaStringPtr filecontent_;
  ::PROTOBUF_NAMESPACE_ID::int32 versionno_;
  ::PROTOBUF_NAMESPACE_ID::int32 operationno_;
  friend struct ::TableStruct_version_2eproto;
};
// -------------------------------------------------------------------

class ParticularFile :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:version.ParticularFile) */ {
 public:
  ParticularFile();
  virtual ~ParticularFile();

  ParticularFile(const ParticularFile& from);
  ParticularFile(ParticularFile&& from) noexcept
    : ParticularFile() {
    *this = ::std::move(from);
  }

  inline ParticularFile& operator=(const ParticularFile& from) {
    CopyFrom(from);
    return *this;
  }
  inline ParticularFile& operator=(ParticularFile&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
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
  static const ParticularFile& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const ParticularFile* internal_default_instance() {
    return reinterpret_cast<const ParticularFile*>(
               &_ParticularFile_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    1;

  friend void swap(ParticularFile& a, ParticularFile& b) {
    a.Swap(&b);
  }
  inline void Swap(ParticularFile* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline ParticularFile* New() const final {
    return CreateMaybeMessage<ParticularFile>(nullptr);
  }

  ParticularFile* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<ParticularFile>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const ParticularFile& from);
  void MergeFrom(const ParticularFile& from);
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
  void InternalSwap(ParticularFile* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "version.ParticularFile";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_version_2eproto);
    return ::descriptor_table_version_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  typedef ParticularFile_Version Version;

  // accessors -------------------------------------------------------

  enum : int {
    kVerFieldNumber = 3,
    kUseridFieldNumber = 1,
    kFileidFieldNumber = 2,
  };
  // repeated .version.ParticularFile.Version ver = 3;
  int ver_size() const;
  private:
  int _internal_ver_size() const;
  public:
  void clear_ver();
  ::version::ParticularFile_Version* mutable_ver(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile_Version >*
      mutable_ver();
  private:
  const ::version::ParticularFile_Version& _internal_ver(int index) const;
  ::version::ParticularFile_Version* _internal_add_ver();
  public:
  const ::version::ParticularFile_Version& ver(int index) const;
  ::version::ParticularFile_Version* add_ver();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile_Version >&
      ver() const;

  // required int32 userid = 1;
  bool has_userid() const;
  private:
  bool _internal_has_userid() const;
  public:
  void clear_userid();
  ::PROTOBUF_NAMESPACE_ID::int32 userid() const;
  void set_userid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_userid() const;
  void _internal_set_userid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // required int32 fileid = 2;
  bool has_fileid() const;
  private:
  bool _internal_has_fileid() const;
  public:
  void clear_fileid();
  ::PROTOBUF_NAMESPACE_ID::int32 fileid() const;
  void set_fileid(::PROTOBUF_NAMESPACE_ID::int32 value);
  private:
  ::PROTOBUF_NAMESPACE_ID::int32 _internal_fileid() const;
  void _internal_set_fileid(::PROTOBUF_NAMESPACE_ID::int32 value);
  public:

  // @@protoc_insertion_point(class_scope:version.ParticularFile)
 private:
  class _Internal;

  // helper for ByteSizeLong()
  size_t RequiredFieldsByteSizeFallback() const;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile_Version > ver_;
  ::PROTOBUF_NAMESPACE_ID::int32 userid_;
  ::PROTOBUF_NAMESPACE_ID::int32 fileid_;
  friend struct ::TableStruct_version_2eproto;
};
// -------------------------------------------------------------------

class FileBook :
    public ::PROTOBUF_NAMESPACE_ID::Message /* @@protoc_insertion_point(class_definition:version.FileBook) */ {
 public:
  FileBook();
  virtual ~FileBook();

  FileBook(const FileBook& from);
  FileBook(FileBook&& from) noexcept
    : FileBook() {
    *this = ::std::move(from);
  }

  inline FileBook& operator=(const FileBook& from) {
    CopyFrom(from);
    return *this;
  }
  inline FileBook& operator=(FileBook&& from) noexcept {
    if (GetArenaNoVirtual() == from.GetArenaNoVirtual()) {
      if (this != &from) InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet& unknown_fields() const {
    return _internal_metadata_.unknown_fields();
  }
  inline ::PROTOBUF_NAMESPACE_ID::UnknownFieldSet* mutable_unknown_fields() {
    return _internal_metadata_.mutable_unknown_fields();
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
  static const FileBook& default_instance();

  static void InitAsDefaultInstance();  // FOR INTERNAL USE ONLY
  static inline const FileBook* internal_default_instance() {
    return reinterpret_cast<const FileBook*>(
               &_FileBook_default_instance_);
  }
  static constexpr int kIndexInFileMessages =
    2;

  friend void swap(FileBook& a, FileBook& b) {
    a.Swap(&b);
  }
  inline void Swap(FileBook* other) {
    if (other == this) return;
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  inline FileBook* New() const final {
    return CreateMaybeMessage<FileBook>(nullptr);
  }

  FileBook* New(::PROTOBUF_NAMESPACE_ID::Arena* arena) const final {
    return CreateMaybeMessage<FileBook>(arena);
  }
  void CopyFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void MergeFrom(const ::PROTOBUF_NAMESPACE_ID::Message& from) final;
  void CopyFrom(const FileBook& from);
  void MergeFrom(const FileBook& from);
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
  void InternalSwap(FileBook* other);
  friend class ::PROTOBUF_NAMESPACE_ID::internal::AnyMetadata;
  static ::PROTOBUF_NAMESPACE_ID::StringPiece FullMessageName() {
    return "version.FileBook";
  }
  private:
  inline ::PROTOBUF_NAMESPACE_ID::Arena* GetArenaNoVirtual() const {
    return nullptr;
  }
  inline void* MaybeArenaPtr() const {
    return nullptr;
  }
  public:

  ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadata() const final;
  private:
  static ::PROTOBUF_NAMESPACE_ID::Metadata GetMetadataStatic() {
    ::PROTOBUF_NAMESPACE_ID::internal::AssignDescriptors(&::descriptor_table_version_2eproto);
    return ::descriptor_table_version_2eproto.file_level_metadata[kIndexInFileMessages];
  }

  public:

  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------

  enum : int {
    kFileFieldNumber = 1,
  };
  // repeated .version.ParticularFile file = 1;
  int file_size() const;
  private:
  int _internal_file_size() const;
  public:
  void clear_file();
  ::version::ParticularFile* mutable_file(int index);
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile >*
      mutable_file();
  private:
  const ::version::ParticularFile& _internal_file(int index) const;
  ::version::ParticularFile* _internal_add_file();
  public:
  const ::version::ParticularFile& file(int index) const;
  ::version::ParticularFile* add_file();
  const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile >&
      file() const;

  // @@protoc_insertion_point(class_scope:version.FileBook)
 private:
  class _Internal;

  ::PROTOBUF_NAMESPACE_ID::internal::InternalMetadataWithArena _internal_metadata_;
  ::PROTOBUF_NAMESPACE_ID::internal::HasBits<1> _has_bits_;
  mutable ::PROTOBUF_NAMESPACE_ID::internal::CachedSize _cached_size_;
  ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile > file_;
  friend struct ::TableStruct_version_2eproto;
};
// ===================================================================


// ===================================================================

#ifdef __GNUC__
  #pragma GCC diagnostic push
  #pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// ParticularFile_Version

// required int32 versionno = 1;
inline bool ParticularFile_Version::_internal_has_versionno() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ParticularFile_Version::has_versionno() const {
  return _internal_has_versionno();
}
inline void ParticularFile_Version::clear_versionno() {
  versionno_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile_Version::_internal_versionno() const {
  return versionno_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile_Version::versionno() const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.Version.versionno)
  return _internal_versionno();
}
inline void ParticularFile_Version::_internal_set_versionno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  versionno_ = value;
}
inline void ParticularFile_Version::set_versionno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_versionno(value);
  // @@protoc_insertion_point(field_set:version.ParticularFile.Version.versionno)
}

// required int32 operationno = 2;
inline bool ParticularFile_Version::_internal_has_operationno() const {
  bool value = (_has_bits_[0] & 0x00000004u) != 0;
  return value;
}
inline bool ParticularFile_Version::has_operationno() const {
  return _internal_has_operationno();
}
inline void ParticularFile_Version::clear_operationno() {
  operationno_ = 0;
  _has_bits_[0] &= ~0x00000004u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile_Version::_internal_operationno() const {
  return operationno_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile_Version::operationno() const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.Version.operationno)
  return _internal_operationno();
}
inline void ParticularFile_Version::_internal_set_operationno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000004u;
  operationno_ = value;
}
inline void ParticularFile_Version::set_operationno(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_operationno(value);
  // @@protoc_insertion_point(field_set:version.ParticularFile.Version.operationno)
}

// required string filecontent = 3;
inline bool ParticularFile_Version::_internal_has_filecontent() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ParticularFile_Version::has_filecontent() const {
  return _internal_has_filecontent();
}
inline void ParticularFile_Version::clear_filecontent() {
  filecontent_.ClearToEmptyNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
  _has_bits_[0] &= ~0x00000001u;
}
inline const std::string& ParticularFile_Version::filecontent() const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.Version.filecontent)
  return _internal_filecontent();
}
inline void ParticularFile_Version::set_filecontent(const std::string& value) {
  _internal_set_filecontent(value);
  // @@protoc_insertion_point(field_set:version.ParticularFile.Version.filecontent)
}
inline std::string* ParticularFile_Version::mutable_filecontent() {
  // @@protoc_insertion_point(field_mutable:version.ParticularFile.Version.filecontent)
  return _internal_mutable_filecontent();
}
inline const std::string& ParticularFile_Version::_internal_filecontent() const {
  return filecontent_.GetNoArena();
}
inline void ParticularFile_Version::_internal_set_filecontent(const std::string& value) {
  _has_bits_[0] |= 0x00000001u;
  filecontent_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), value);
}
inline void ParticularFile_Version::set_filecontent(std::string&& value) {
  _has_bits_[0] |= 0x00000001u;
  filecontent_.SetNoArena(
    &::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::move(value));
  // @@protoc_insertion_point(field_set_rvalue:version.ParticularFile.Version.filecontent)
}
inline void ParticularFile_Version::set_filecontent(const char* value) {
  GOOGLE_DCHECK(value != nullptr);
  _has_bits_[0] |= 0x00000001u;
  filecontent_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), ::std::string(value));
  // @@protoc_insertion_point(field_set_char:version.ParticularFile.Version.filecontent)
}
inline void ParticularFile_Version::set_filecontent(const char* value, size_t size) {
  _has_bits_[0] |= 0x00000001u;
  filecontent_.SetNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(),
      ::std::string(reinterpret_cast<const char*>(value), size));
  // @@protoc_insertion_point(field_set_pointer:version.ParticularFile.Version.filecontent)
}
inline std::string* ParticularFile_Version::_internal_mutable_filecontent() {
  _has_bits_[0] |= 0x00000001u;
  return filecontent_.MutableNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline std::string* ParticularFile_Version::release_filecontent() {
  // @@protoc_insertion_point(field_release:version.ParticularFile.Version.filecontent)
  if (!_internal_has_filecontent()) {
    return nullptr;
  }
  _has_bits_[0] &= ~0x00000001u;
  return filecontent_.ReleaseNonDefaultNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited());
}
inline void ParticularFile_Version::set_allocated_filecontent(std::string* filecontent) {
  if (filecontent != nullptr) {
    _has_bits_[0] |= 0x00000001u;
  } else {
    _has_bits_[0] &= ~0x00000001u;
  }
  filecontent_.SetAllocatedNoArena(&::PROTOBUF_NAMESPACE_ID::internal::GetEmptyStringAlreadyInited(), filecontent);
  // @@protoc_insertion_point(field_set_allocated:version.ParticularFile.Version.filecontent)
}

// -------------------------------------------------------------------

// ParticularFile

// required int32 userid = 1;
inline bool ParticularFile::_internal_has_userid() const {
  bool value = (_has_bits_[0] & 0x00000001u) != 0;
  return value;
}
inline bool ParticularFile::has_userid() const {
  return _internal_has_userid();
}
inline void ParticularFile::clear_userid() {
  userid_ = 0;
  _has_bits_[0] &= ~0x00000001u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile::_internal_userid() const {
  return userid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile::userid() const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.userid)
  return _internal_userid();
}
inline void ParticularFile::_internal_set_userid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000001u;
  userid_ = value;
}
inline void ParticularFile::set_userid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_userid(value);
  // @@protoc_insertion_point(field_set:version.ParticularFile.userid)
}

// required int32 fileid = 2;
inline bool ParticularFile::_internal_has_fileid() const {
  bool value = (_has_bits_[0] & 0x00000002u) != 0;
  return value;
}
inline bool ParticularFile::has_fileid() const {
  return _internal_has_fileid();
}
inline void ParticularFile::clear_fileid() {
  fileid_ = 0;
  _has_bits_[0] &= ~0x00000002u;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile::_internal_fileid() const {
  return fileid_;
}
inline ::PROTOBUF_NAMESPACE_ID::int32 ParticularFile::fileid() const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.fileid)
  return _internal_fileid();
}
inline void ParticularFile::_internal_set_fileid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _has_bits_[0] |= 0x00000002u;
  fileid_ = value;
}
inline void ParticularFile::set_fileid(::PROTOBUF_NAMESPACE_ID::int32 value) {
  _internal_set_fileid(value);
  // @@protoc_insertion_point(field_set:version.ParticularFile.fileid)
}

// repeated .version.ParticularFile.Version ver = 3;
inline int ParticularFile::_internal_ver_size() const {
  return ver_.size();
}
inline int ParticularFile::ver_size() const {
  return _internal_ver_size();
}
inline void ParticularFile::clear_ver() {
  ver_.Clear();
}
inline ::version::ParticularFile_Version* ParticularFile::mutable_ver(int index) {
  // @@protoc_insertion_point(field_mutable:version.ParticularFile.ver)
  return ver_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile_Version >*
ParticularFile::mutable_ver() {
  // @@protoc_insertion_point(field_mutable_list:version.ParticularFile.ver)
  return &ver_;
}
inline const ::version::ParticularFile_Version& ParticularFile::_internal_ver(int index) const {
  return ver_.Get(index);
}
inline const ::version::ParticularFile_Version& ParticularFile::ver(int index) const {
  // @@protoc_insertion_point(field_get:version.ParticularFile.ver)
  return _internal_ver(index);
}
inline ::version::ParticularFile_Version* ParticularFile::_internal_add_ver() {
  return ver_.Add();
}
inline ::version::ParticularFile_Version* ParticularFile::add_ver() {
  // @@protoc_insertion_point(field_add:version.ParticularFile.ver)
  return _internal_add_ver();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile_Version >&
ParticularFile::ver() const {
  // @@protoc_insertion_point(field_list:version.ParticularFile.ver)
  return ver_;
}

// -------------------------------------------------------------------

// FileBook

// repeated .version.ParticularFile file = 1;
inline int FileBook::_internal_file_size() const {
  return file_.size();
}
inline int FileBook::file_size() const {
  return _internal_file_size();
}
inline void FileBook::clear_file() {
  file_.Clear();
}
inline ::version::ParticularFile* FileBook::mutable_file(int index) {
  // @@protoc_insertion_point(field_mutable:version.FileBook.file)
  return file_.Mutable(index);
}
inline ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile >*
FileBook::mutable_file() {
  // @@protoc_insertion_point(field_mutable_list:version.FileBook.file)
  return &file_;
}
inline const ::version::ParticularFile& FileBook::_internal_file(int index) const {
  return file_.Get(index);
}
inline const ::version::ParticularFile& FileBook::file(int index) const {
  // @@protoc_insertion_point(field_get:version.FileBook.file)
  return _internal_file(index);
}
inline ::version::ParticularFile* FileBook::_internal_add_file() {
  return file_.Add();
}
inline ::version::ParticularFile* FileBook::add_file() {
  // @@protoc_insertion_point(field_add:version.FileBook.file)
  return _internal_add_file();
}
inline const ::PROTOBUF_NAMESPACE_ID::RepeatedPtrField< ::version::ParticularFile >&
FileBook::file() const {
  // @@protoc_insertion_point(field_list:version.FileBook.file)
  return file_;
}

#ifdef __GNUC__
  #pragma GCC diagnostic pop
#endif  // __GNUC__
// -------------------------------------------------------------------

// -------------------------------------------------------------------


// @@protoc_insertion_point(namespace_scope)

}  // namespace version

// @@protoc_insertion_point(global_scope)

#include <google/protobuf/port_undef.inc>
#endif  // GOOGLE_PROTOBUF_INCLUDED_GOOGLE_PROTOBUF_INCLUDED_version_2eproto
