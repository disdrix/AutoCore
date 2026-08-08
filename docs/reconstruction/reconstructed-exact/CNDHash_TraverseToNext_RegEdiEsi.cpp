// =============================================================================
// CNDHash_TraverseToNext_RegEdiEsi
// -----------------------------------------------------------------------------
// Stable ID: aa_00411e40
// Address:   0x00411e40–0x00411e80 inclusive (65 B / 0x41)
// Module:    autoassault.exe, image base 0x400000
// System:    interaction-activation / CNDHash container
// Generated: 2026-08-05 MEGA-114 OWN dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// PURPOSE:
//   CNDHash ordered-list iterator step under an already-held TraversalLock.
//   Register-ABI twin of dualed CNDHash_TraverseToNext (0x00411900 thiscall).
//
// ABI (assembly-sealed; no portable MSVC prototype for freestanding regargs):
//   EDI = CNDHash* hash
//   ESI = node** cursor (in/out)
//   EAX = payload at node+8, or 0
//   Bare RET (no stack args; not RET 4)
//
// Offsets (0x1c-class node family):
//   hash+0x1d  TraversalLock byte (read-only check; log if unlocked)
//   hash+0x14  list head node*
//   node+0x14  list-next node*
//   node+0x08  payload / value (returned)
//
// Strings:
//   "HashError:TraverseToNext, not locked for traversal" @ 0x00a27c9c
//   "VOG_DEBUG_STOP" @ 0x00a15844
//
// Callee: FUN_007a4480 (log) only.
// Does NOT set/clear lock, freelist, or membership.
// Scaffold Named_VOG_DEBUG_STOP_00411e40 RETIRED (string-only misname).
// =============================================================================

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *msg);

// Ghidra models this as void(void) because EDI/ESI are not formal parameters.
// Locals below stand in for live registers so CF is reviewable.

extern "C" uint32_t CNDHash_TraverseToNext_RegEdiEsi(void)
{
  int iVar1;
  int *unaff_ESI; // ESI = node** cursor
  int unaff_EDI;  // EDI = CNDHash* hash (as int base)

  if (*(char *)(unaff_EDI + 0x1d) == '\0') {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (*unaff_ESI == 0) {
    *unaff_ESI = *(int *)(unaff_EDI + 0x14);
    iVar1 = *(int *)(unaff_EDI + 0x14);
  } else {
    iVar1 = *(int *)(*unaff_ESI + 0x14);
    *unaff_ESI = iVar1;
  }
  if (iVar1 != 0) {
    return *(uint32_t *)(iVar1 + 8);
  }
  return 0;
}
