// =============================================================================
// AssKey_FormatAssIdLogString_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096a630
// Address:   0x0096a630–0x0096a6e1 exclusive  (177 B / 0xB1)
// Module:    autoassault.exe (image base 0x400000)
// System:    asset / ass-key logging (client::ass)
// Generated: 2026-08-04 W38-B dual seal (from raw + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Runtime / differential: OPEN
//
// PURPOSE: Format key name into log-facing std::string "assId: [%s]".
//   *key (first dword) is char* name; null → empty string via PTR_DAT_00afa2bc.
//   Used heavily by AssPreloader failure/tally logs and other gfx/load paths.
//
// ABI: __thiscall; ECX = key*; stack out basic_string*; RET 4; returns out*.
// SEH: LAB_009ab872
// Format VA: 0x00aa1c18 "assId: [%s]"
// Null fallback: [0x00afa2bc] → 0x00a1419b ""
//
// Reject scaffold: Named_CalleeOf_Named_gfxBody_0096a630 (multi-caller).
// =============================================================================

#include <stdint.h>
#include <stdio.h>
#include <string>

// Minimal stand-in for retail key: object whose first field is char* name.
struct AssKeyView {
  const char* name; // +0x00
};

// MSVC retail uses std::basic_string with SSO; port may use std::string.
std::string* AssKey_FormatAssIdLogString_Inferred(
    AssKeyView* key /*ECX*/,
    std::string* out /*stack*/)
{
  std::string tmp;
  char buf[260];

  const char* name = key->name;
  if (name == nullptr) {
    // PTR_DAT_00afa2bc → empty C string
    name = "";
  }
  sprintf(buf, "assId: [%s]", name);
  tmp = buf;
  *out = tmp;
  return out;
}

// Scaffold alias
std::string* __thiscall FUN_0096a630(AssKeyView* key, std::string* out)
{
  return AssKey_FormatAssIdLogString_Inferred(key, out);
}
