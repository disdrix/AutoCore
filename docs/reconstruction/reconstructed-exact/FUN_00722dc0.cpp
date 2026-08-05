// =============================================================================
// FUN_00722dc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00722dc0
// Address:   0x00722dc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00722dc0 @ 0x00722dc0
// Stable ID: aa_00722dc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, do×2, while×2.
//  - Notable callees: _stricmp×2, FUN_00722aa0, FUN_00722dc0, memmove.
//  - Return sites: 3.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall FUN_00722dc0(int param_1,char *param_2)



{

  int iVar1;

  int *piVar2;

  code *pcVar3;

  int *piVar4;

  int *local_14;

  

  if (param_2 != (char *)0x0) {

    piVar4 = *(int **)(param_1 + 0x29c);

    pcVar3 = memmove_exref;

    if (piVar4 != *(int **)(param_1 + 0x2a0)) {

      local_14 = piVar4 + 1;

      do {

        iVar1 = _stricmp((char *)(*piVar4 + 0x20),param_2);

        if (iVar1 == 0) {

          iVar1 = *piVar4;

          FUN_00722aa0(*(uint32_t /* width from decompiler */ *)(iVar1 + 0x128),*(uint32_t /* width from decompiler */ *)(iVar1 + 300),

                       *(uint32_t /* width from decompiler */ *)(iVar1 + 0x130),0);

          pcVar3 = memmove_exref;

          if ((void *)*piVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)*piVar4);

          }

          memmove(piVar4,local_14,(*(int *)(param_1 + 0x2a0) - (int)local_14 >> 2) * 4);

          *(int *)(param_1 + 0x2a0) = *(int *)(param_1 + 0x2a0) + -4;

        }

        else {

          piVar4 = piVar4 + 1;

          local_14 = local_14 + 1;

        }

      } while (piVar4 != *(int **)(param_1 + 0x2a0));

    }

    piVar4 = *(int **)(param_1 + 0x28c);

    if (piVar4 != *(int **)(param_1 + 0x290)) {

      piVar2 = piVar4 + 1;

      do {

        iVar1 = _stricmp((char *)(*piVar4 + 0x20),param_2);

        if (iVar1 == 0) {

          if ((void *)*piVar4 != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

            operator_delete((void *)*piVar4);

          }

          (*pcVar3)(piVar4,piVar2,(*(int *)(param_1 + 0x290) - (int)piVar2 >> 2) * 4);

          *(int *)(param_1 + 0x290) = *(int *)(param_1 + 0x290) + -4;

        }

        else {

          piVar4 = piVar4 + 1;

          piVar2 = piVar2 + 1;

        }

      } while (piVar4 != *(int **)(param_1 + 0x290));

    }

  }

  return;

}
