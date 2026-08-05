// =============================================================================
// FUN_0096a630  (scaffold twin of AssKey_FormatAssIdLogString_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a630
// Address:   0x0096a630–0x0096a6e1 exclusive  (177 B)
// Canonical named twin: reconstructed-exact/AssKey_FormatAssIdLogString_Inferred.cpp
// Generated: 2026-08-04 W38-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Embedded string: "assId: [%s]"
// =============================================================================

#include <stdint.h>
#include <stdio.h>

// ABI: __thiscall ECX=key (int* / char**); stack out basic_string*; RET 4
// Returns out in EAX. SEH LAB_009ab872. Null *key → PTR_DAT_00afa2bc ("").

// Ghidra types retained for graph matching:
// basic_string* __thiscall FUN_0096a630(int *param_1, basic_string *param_2)

struct BasicStringChar; // opaque retail std::basic_string<char>

extern "C" {
  void __thiscall basic_string_ctor_default(BasicStringChar* self);
  void __thiscall basic_string_op_assign_cstr(BasicStringChar* self, const char* s);
  void __thiscall basic_string_ctor_copy(BasicStringChar* self, const BasicStringChar* other);
  void __thiscall basic_string_dtor(BasicStringChar* self);
  extern char* PTR_DAT_00afa2bc; // → ""
}

BasicStringChar* __thiscall FUN_0096a630(int* key, BasicStringChar* out)
{
  BasicStringChar local_tmp; // decompiler local_12c
  char local_110[260];

  basic_string_ctor_default(&local_tmp);

  char* name = (char*)*key;
  if (name == nullptr) {
    name = PTR_DAT_00afa2bc;
  }
  sprintf(local_110, "assId: [%s]", name);
  basic_string_op_assign_cstr(&local_tmp, local_110);
  basic_string_ctor_copy(out, &local_tmp);
  basic_string_dtor(&local_tmp);
  return out;
}
