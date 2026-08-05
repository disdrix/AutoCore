// =============================================================================
// BasicString_CopyEnsureTrailingDirSep
// -----------------------------------------------------------------------------
// Stable ID: aa_009694e0
// Address:   0x009694e0–0x009695b1 exclusive (209 B / 0xD1, autoassault.exe base 0x400000)
// System:    assManager / path-string normalize helper
// Generated: 2026-07-29 W32-A dual A/B (decompile + read_memory)
// Exactness: Behavior-preserving CF + ABI. Nested FUN_00416510 unowned.
// Bit-for-bit vs retail EXE: DEFERRED.
// Ghidra:    FUN_009694e0
// Reject:    Named_CalleeOf_Named_CalleeOf_Named_assManager_009694e0 (scaffold)
// =============================================================================
//
// PURPOSE:
//   Copy src basic_string into out. If non-empty and the last character is not
//   ':', '/', or '\\', produce a copy with '/' appended (via FUN_00416510) and
//   store that in out. Used by StringVec path-list helpers (push_front / find /
//   push_back-if-absent) so directory roots always end with a separator.
//
// ABI (bytes):
//   cdecl; stack: out*, src*; returns out* in EAX
//   SEH LAB_009ab825; local temp string 0x1c on append path
//   IAT copy-ctor @ [0x009c62ec]; IAT dtor @ [0x009c62f4]
//
// MSVC basic_string layout (this binary, sizeof 0x1c):
//   +0x04  SSO buf or heap ptr (when _Myres >= 0x10)
//   +0x14  _Mysize
//   +0x18  _Myres
// =============================================================================

#include <cstdint>

struct MsvcBasicString {
  uint8_t  raw[0x1c];
};

// Unowned / IAT
extern "C" MsvcBasicString* FUN_00416510(MsvcBasicString* out,
                                         const MsvcBasicString* src,
                                         char ch); // copy + operator+=(ch)
extern "C" void basic_string_copy_ctor(MsvcBasicString* self,
                                       const MsvcBasicString* other);
extern "C" void basic_string_dtor(MsvcBasicString* self);

static inline uint32_t str_size(const MsvcBasicString* s)
{
  return *reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(s) + 0x14);
}

static inline uint32_t str_res(const MsvcBasicString* s)
{
  return *reinterpret_cast<const uint32_t*>(reinterpret_cast<const uint8_t*>(s) + 0x18);
}

static inline const char* str_data(const MsvcBasicString* s)
{
  if (str_res(s) < 0x10u) {
    return reinterpret_cast<const char*>(reinterpret_cast<const uint8_t*>(s) + 4);
  }
  return *reinterpret_cast<const char* const*>(reinterpret_cast<const uint8_t*>(s) + 4);
}

// Retail cdecl; returns out
extern "C" MsvcBasicString* BasicString_CopyEnsureTrailingDirSep(
    MsvcBasicString* out,
    const MsvcBasicString* src)
{
  // SEH + ExceptionList omitted (structure only)

  if (str_size(src) == 0u) {
    basic_string_copy_ctor(out, src);
    return out;
  }

  const char last = str_data(src)[str_size(src) - 1u];
  if (last != ':' && last != '/' && last != '\\') {
    MsvcBasicString tmp{};
    // EH state = 1 around temp lifetime
    FUN_00416510(&tmp, src, '/');
    basic_string_copy_ctor(out, &tmp);
    basic_string_dtor(&tmp);
    return out;
  }

  basic_string_copy_ctor(out, src);
  return out;
}

// Scaffold alias
extern "C" MsvcBasicString* FUN_009694e0(MsvcBasicString* out,
                                         const MsvcBasicString* src)
{
  return BasicString_CopyEnsureTrailingDirSep(out, src);
}
