// READABILITY (auto CF):
//  - Body size: ~51 non-empty decompiler lines.
//  - Control keywords: if×9, for×2, do×1, while×1, return×1.
//  - Notable callees: FUN_007a4480×4, FUN_00411e40, FUN_0078dac0.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal".
//  - Return sites: 1.

// =============================================================================
// Named_VOG_DEBUG_STOP_0078dac0
// -----------------------------------------------------------------------------
// Stable ID: aa_0078dac0
// Address:   0x0078dac0  (autoassault.exe, image base 0x400000)
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

int __fastcall Named_VOG_DEBUG_STOP_0078dac0(int param_1)



{

  int *piVar1;

  int iVar2;

  int iVar3;

  int local_8;

  

  iVar3 = *(int *)(param_1 + 0x4c0);

  local_8 = -1;

  if ((iVar3 != 0) && (*(int *)(param_1 + 0x928) != -1)) {

    local_8 = 0;

    if (*(char *)(iVar3 + 0x1d) != '\0') {

      FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    *(uint8_t *)(iVar3 + 0x1d) = 1;

    piVar1 = (int *)FUN_00411e40();

    if (piVar1 != (int *)0x0) {

      iVar3 = 0;

      do {

        iVar2 = (**(code **)(*piVar1 + 0x78))();

        if (0x67 < iVar2) {

          iVar2 = (**(code **)(*piVar1 + 0x78))();

          if (iVar2 == *(int *)(param_1 + 0x928)) break;

          local_8 = local_8 + 1;

        }

        iVar2 = *(int *)(param_1 + 0x4c0);

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

          piVar1 = (int *)0x0;

        }

        else {

          piVar1 = *(int **)(iVar3 + 8);

        }

      } while (piVar1 != (int *)0x0);

    }

    *(uint8_t *)(*(int *)(param_1 + 0x4c0) + 0x1d) = 0;

    if (*(int *)(*(int *)(param_1 + 0x4c0) + 0xc) <= local_8) {

      local_8 = -1;

    }

  }

  return local_8;

}
