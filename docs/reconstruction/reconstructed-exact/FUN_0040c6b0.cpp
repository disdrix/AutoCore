// =============================================================================
// FUN_0040c6b0  (Ghidra surface twin)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c6b0
// Address:   0x0040c6b0  (autoassault.exe, image base 0x400000)
// Named:     CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred
// Seal:      MEGA-112 2026-08-05
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

// Named reconstruction (preferred):
//   reconstructed-exact/CNDHash_TraverseToNext_TFID_Node0x28_RegEdiEsi_Inferred.cpp
//
// Retired scaffolds (do not use):
//   Named_VOG_DEBUG_STOP_0040c6b0.cpp  — string-only misname (VOG_DEBUG_STOP is log tag)
//   Named_CalleeOf_* (if any)          — parent-chain scaffold

#include <cstdint>

extern "C" void FUN_007a4480(int level, const char *msg);

// Retail register ABI: EDI=hash*, ESI=cursor**, EAX=payload*, plain RET.
// Decompiler form preserves unaff_* names from live Ghidra.

extern "C" uint32_t FUN_0040c6b0(void)
{
  int iVar1;
  int *unaff_ESI;  // Node**  (cursor)
  int unaff_EDI;   // CNDHash* (hash)

  if (*(char *)(unaff_EDI + 0x1d) == '\0') {
    FUN_007a4480(0, "HashError:TraverseToNext, not locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  if (*unaff_ESI == 0) {
    *unaff_ESI = *(int *)(unaff_EDI + 0x14);
    iVar1 = *(int *)(unaff_EDI + 0x14);
  } else {
    iVar1 = *(int *)(*unaff_ESI + 0x20);
    *unaff_ESI = iVar1;
  }
  if (iVar1 != 0) {
    return *(uint32_t *)(iVar1 + 0xc);
  }
  return 0;
}
