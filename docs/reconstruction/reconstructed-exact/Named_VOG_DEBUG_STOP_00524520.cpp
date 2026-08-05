// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×6, return×2, for×2, do×1, goto×1, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_00524520, FUN_0059d9c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00524520
// -----------------------------------------------------------------------------
// Stable ID: aa_00524520
// Address:   0x00524520  (autoassault.exe, image base 0x400000)
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

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_00524520(int param_1,int param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  if (param_2 == 0) {

    return 0;

  }

  iVar4 = *(int *)(param_1 + 0x548);

  iVar3 = 0;

  uVar2 = 0;

  if (*(char *)(iVar4 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar4 + 0x1d) = 1;

  do {

    iVar4 = *(int *)(param_1 + 0x548);

    if (*(char *)(iVar4 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar4 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(iVar3 + 8);

    }

    if (iVar4 == 0) goto LAB_005245b6;

    cVar1 = FUN_0059d9c0(param_1,param_2);

  } while (cVar1 == '\0');

  uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x10);

LAB_005245b6:

  *(uint8_t *)(*(int *)(param_1 + 0x548) + 0x1d) = 0;

  return uVar2;

}
