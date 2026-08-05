// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, for×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_0051a0e0, FUN_0090c810.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_0090c810
// -----------------------------------------------------------------------------
// Stable ID: aa_0090c810
// Address:   0x0090c810  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int Named_VOG_DEBUG_STOP_0090c810(void)



{

  int iVar1;

  int unaff_EBX;

  int iVar2;

  int iVar3;

  

  if (unaff_EBX == 0) {

    return 0;

  }

  if (*(int *)(unaff_EBX + 0x574) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(unaff_EBX + 0x578) - *(int *)(unaff_EBX + 0x574) >> 2;

  }

  iVar1 = *(int *)(unaff_EBX + 0x540);

  iVar3 = 0;

  if (*(char *)(iVar1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar1 + 0x1d) = 1;

  while( true ) {

    iVar1 = *(int *)(unaff_EBX + 0x540);

    if (*(char *)(iVar1 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar1 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(iVar3 + 8);

    }

    if (iVar1 == 0) break;

    iVar1 = FUN_0051a0e0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x100));

    if (iVar1 != 0) {

      iVar2 = iVar2 + 1;

    }

  }

  *(uint8_t *)(*(int *)(unaff_EBX + 0x540) + 0x1d) = 0;

  return iVar2;

}
