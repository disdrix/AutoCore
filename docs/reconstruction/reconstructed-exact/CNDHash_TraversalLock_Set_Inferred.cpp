// =============================================================================
// CNDHash_TraversalLock_Set_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00402c40
// Address:   0x00402c40  (autoassault.exe, image base 0x400000)
// Range:     0x00402c40–0x00402c69 inclusive (42 B / 0x2A); pad CC after
// System:    interaction-activation (shared CNDHash TraversalLock primitive)
// Generated: 2026-08-05 MEGA-110 dual seal (from live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler/assembly control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: OPEN (no Launcher this wave).
// =============================================================================
//
// PURPOSE
//   Soft-set the CNDHash TraversalLock flag at hash+0x1d.
//   If already locked, log HashError + VOG_DEBUG_STOP via FUN_007a4480, then
//   still force the flag to 1 (no throw / no abort / no CS).
//
// ABI (sealed)
//   ECX = CNDHash* (hash table object)
//   No stack arguments; bare RET; void return.
//   Ghidra decompiler shows __fastcall — correct for ECX-only formal.
//
// STRINGS
//   0x00a27cd0  "HashError:TraversalLock, already locked for traversal"
//   0x00a15844  "VOG_DEBUG_STOP"
//
// CALLEES
//   FUN_007a4480  debug/log (cdecl; level + fmt string) ×2
//
// DISTINCT FROM
//   List_TraversalLock (0x004294f0) — CS list family, flag +0x28, EnterCS
//   Scaffold Named_VOG_DEBUG_STOP_* — assert string only, not identity
//
// PAIR
//   CNDHash_TraverseToNext (0x00411900) — ordered walk under this lock
// =============================================================================

#include <cstdint>

// Forward: debug logger used for soft HashError asserts (not dualled here).
extern void FUN_007a4480(int level, const char *fmt);

void __fastcall CNDHash_TraversalLock_Set_Inferred(int hash /* ECX */)
{
  if (*(char *)(hash + 0x1d) != '\0') {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *(uint8_t *)(hash + 0x1d) = 1;
  return;
}
