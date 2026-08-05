// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, return×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_00540350, _stricmp.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 2.

// =============================================================================
// Named_VOG_DEBUG_STOP_00540350
// -----------------------------------------------------------------------------
// Stable ID: aa_00540350
// Address:   0x00540350  (autoassault.exe, image base 0x400000)
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

int __thiscall Named_VOG_DEBUG_STOP_00540350(int param_1,char *param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar2 = *(int *)(param_1 + 0xf10);

  iVar3 = 0;

  if (*(char *)(iVar2 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar2 + 0x1d) = 1;

  while( true ) {

    iVar2 = *(int *)(param_1 + 0xf10);

    if (*(char *)(iVar2 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar3 == 0) {

      iVar3 = *(int *)(iVar2 + 0x14);

    }

    else {

      iVar3 = *(int *)(iVar3 + 0x14);

    }

    if (iVar3 == 0) {

      iVar2 = 0;

    }

    else {

      iVar2 = *(int *)(iVar3 + 8);

    }

    if (iVar2 == 0) break;

    iVar1 = _stricmp((char *)(iVar2 + 0x40),param_2);

    if (iVar1 == 0) {

      *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

      return iVar2;

    }

  }

  *(uint8_t *)(*(int *)(param_1 + 0xf10) + 0x1d) = 0;

  return 0;

}
