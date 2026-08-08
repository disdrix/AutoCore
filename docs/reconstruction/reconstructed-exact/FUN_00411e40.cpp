// =============================================================================
// FUN_00411e40  (Ghidra name twin of CNDHash_TraverseToNext_RegEdiEsi)
// -----------------------------------------------------------------------------
// Stable ID: aa_00411e40
// Address:   0x00411e40–0x00411e80 inclusive (65 B / 0x41)
// Module:    autoassault.exe, image base 0x400000
// System:    interaction-activation / CNDHash container
// Generated: 2026-08-05 MEGA-114 OWN dual
// Canonical: CNDHash_TraverseToNext_RegEdiEsi
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly ABI seal.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: not claimed.
// =============================================================================
//
// ABI: EDI=CNDHash*, ESI=node** cursor, EAX=payload@node+8|0, bare RET.
// Twin thiscall: CNDHash_TraverseToNext @ 0x00411900 (RET 4).
// Scaffold Named_VOG_DEBUG_STOP_00411e40 retired.
// =============================================================================

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *msg);

// Ghidra signature is void(void) because register args are not modeled.
// Prefer CNDHash_TraverseToNext_RegEdiEsi for the named contract.

extern "C" uint32_t FUN_00411e40(void)
{
  // unaff_EDI = hash*, unaff_ESI = cursor*  (decompiler names)
  int iVar1;
  int *unaff_ESI; // ESI
  int unaff_EDI;  // EDI

  // NOTE: In the live binary, EDI/ESI are live on entry (no prologue).
  // This C form preserves CF for review; see named clean for ABI plate.

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
