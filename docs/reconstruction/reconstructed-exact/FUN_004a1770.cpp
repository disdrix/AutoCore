// =============================================================================
// FUN_004a1770  (twin of StringTable_FindOrIntern_u16_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a1770
// Address:   0x004a1770 – 0x004a18a8 exclusive (312 B / 0x138)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W34-I OWN-ONLY dual 2026-07-29
// =============================================================================

// PURPOSE: Linear find-or-intern into global vector<basic_string> @ 0x00b03608.
// Preferred name: StringTable_FindOrIntern_u16_Inferred
// REJECT: Named_CalleeOf_Named_VOG_DEBUG_STOP_004a1770
//
// ABI: cdecl (const char* name) → uint index; bare RET.
// Hit: return index & 0xffff. Miss empty: push "Empty" then name, return size-1.
// Miss non-empty: push name, return size-1.
// Sole caller: FUN_004a18b0 @ 0x004a1bb1 / 0x004a1c4a.

#include <cstdint>

extern "C" unsigned FUN_004a1770(const char* name);

// See StringTable_FindOrIntern_u16_Inferred.cpp for sealed contract notes.
// Authoritative CF: docs/reconstruction/raw/aa_004a1770_FUN_004a1770.md (W34-I append).
