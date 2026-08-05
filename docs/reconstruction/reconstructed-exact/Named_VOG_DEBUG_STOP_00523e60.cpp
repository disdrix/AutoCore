// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, for×2, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00411900, FUN_00514e70, FUN_00523e60, FUN_005536c0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_00523e60
// -----------------------------------------------------------------------------
// Stable ID: aa_00523e60
// Address:   0x00523e60  (autoassault.exe, image base 0x400000)
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

void __fastcall Named_VOG_DEBUG_STOP_00523e60(int param_1)



{

  int iVar1;

  int iVar2;

  int local_4;

  

  iVar2 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

  local_4 = 0;

  if (iVar2 != 0) {

    if (*(char *)(iVar2 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar2 + 0x1d) = 1;

    iVar1 = FUN_00411900(&local_4);

    iVar2 = local_4;

    while (iVar1 != 0) {

      FUN_005536c0(param_1);

      if ((0 < *(short *)(iVar1 + 0xdc)) && ((*(byte *)(iVar1 + 0x615) & 1) != 0)) {

        FUN_00514e70(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x5fc));

      }

      iVar1 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1);

      if (*(char *)(iVar1 + 0x1d) == '\0') {

        FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

        FUN_007a4480(0,"VOG_DEBUG_STOP");

      }

      if (iVar2 == 0) {

        iVar2 = *(int *)(iVar1 + 0x14);

      }

      else {

        iVar2 = *(int *)(iVar2 + 0x14);

      }

      if (iVar2 == 0) {

        iVar1 = 0;

      }

      else {

        iVar1 = *(int *)(iVar2 + 8);

      }

    }

    *(uint8_t *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x74 + param_1) + 0x1d) = 0;

  }

  return;

}
