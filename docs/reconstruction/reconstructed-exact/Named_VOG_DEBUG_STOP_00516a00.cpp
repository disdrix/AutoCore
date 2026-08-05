// READABILITY (auto CF):
//  - Body size: ~76 non-empty decompiler lines.
//  - Control keywords: if×12, return×5, for×2, while×2, switch×1.
//  - Notable callees: FUN_007a4480×4, FUN_00514e70×2, FUN_00516a00.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 5.

// =============================================================================
// Named_VOG_DEBUG_STOP_00516a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00516a00
// Address:   0x00516a00  (autoassault.exe, image base 0x400000)
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

void __thiscall Named_VOG_DEBUG_STOP_00516a00(int *param_1,char param_2)



{

  int iVar1;

  int iVar2;

  uint uVar3;

  int iVar4;

  

  switch(*(uint32_t /* width from decompiler */ *)(param_1[0x2a] + 0x38)) {

  case 6:

  case 10:

  case 0xc:

  case 0x10:

  case 0x1c:

  case 0x44:

  case 0x46:

    return;

  case 0xe:

    if (param_1[0x2b] == 0) {

      return;

    }

  }

  iVar2 = param_1[0x1c];

  if (iVar2 != 0) {

    iVar4 = 0;

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    while( true ) {

      iVar2 = param_1[0x1c];

      if (*(char *)(iVar2 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar4 == 0) {

        iVar4 = *(int *)(iVar2 + 0x14);

      }

      else {

        iVar4 = *(int *)(iVar4 + 0x14);

      }

      if (iVar4 == 0) {

        iVar2 = 0;

      }

      else {

        iVar2 = *(int *)(iVar4 + 8);

      }

      if (iVar2 == 0) break;

      if (((*(byte *)(iVar2 + 0x615) & 1) != 0) &&

         ((param_2 != '\0' || (0 < *(short *)(iVar2 + 0x5f6))))) {

        FUN_00514e70(*(uint32_t /* width from decompiler */ *)(iVar2 + 0x5fc));

      }

    }

    *(uint8_t *)(param_1[0x1c] + 0x1d) = 0;

  }

  iVar2 = (**(code **)(*param_1 + 0x1dc))();

  if (iVar2 == 0) {

    return;

  }

  iVar2 = (**(code **)(*param_1 + 0x1dc))();

  uVar3 = 0;

  iVar4 = 0;

  while( true ) {

    iVar1 = *(int *)(iVar2 + 0x550);

    if (iVar1 == 0) {

      return;

    }

    if ((uint)((*(int *)(iVar2 + 0x554) - iVar1) / 0xc) <= uVar3) break;

    if (((*(int *)(iVar4 + iVar1) != 0) && ((*(byte *)(*(int *)(iVar4 + iVar1) + 0x615) & 1) != 0))

       && ((param_2 != '\0' || (0 < *(short *)(*(int *)(iVar4 + iVar1) + 0x5f6))))) {

      FUN_00514e70(*(uint32_t /* width from decompiler */ *)(*(int *)(iVar4 + iVar1) + 0x5fc));

    }

    uVar3 = uVar3 + 1;

    iVar4 = iVar4 + 0xc;

  }

  return;

}
