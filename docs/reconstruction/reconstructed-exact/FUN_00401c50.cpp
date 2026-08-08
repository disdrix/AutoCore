// =============================================================================
// FUN_00401c50 — scaffold twin of StdMap_StringKey_InsertOrFind_Via401db0_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00401c50
// Address:   0x00401c50–0x00401d26 inclusive (215 B / 0xD7)
// Agent:     MEGA-064 OWN-ONLY dual 2026-08-05
// Canonical: docs/reconstruction/reconstructed-exact/
//            StdMap_StringKey_InsertOrFind_Via401db0_Inferred.cpp
// Exactness: Ghidra symbol retained for xref continuity; prefer named clean.
// Terminal:  false
// =============================================================================
//
// Prior Named_CalleeOf_Named_CalleeOf_Mission_Attempting_to_open_null_d_00401c50
// scaffold RETIRED — chain-of-caller plate is not product English.
//
// See named clean for full ABI/structs/CF. This twin keeps FUN_* entry for
// tools that resolve by Ghidra symbol only.

#include <cstdint>

// Forward to named reconstruction (link-time / documentation twin).
extern "C" void* StdMap_StringKey_InsertOrFind_Via401db0_Inferred(
    void* map /*stack*/,
    const void* key /*EAX*/,
    void* out /*EBX*/);

// Ghidra symbol alias — same body, same ABI (stack map + EAX key + EBX out; RET 4).
extern "C" void* FUN_00401c50(
    void* map /*stack*/,
    const void* key /*EAX*/,
    void* out /*EBX*/)
{
  return StdMap_StringKey_InsertOrFind_Via401db0_Inferred(map, key, out);
}
