// =============================================================================
// FUN_00983eb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00983eb0
// Address:   0x00983eb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00983eb0 @ 0x00983eb0
// Stable ID: aa_00983eb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, return×1.
//  - Notable callees: FUN_00436ef0, FUN_0043bfb0, FUN_00983eb0, FUN_00989e00.
//  - Return sites: 1.

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

uint32_t /* width from decompiler */ FUN_00983eb0(int *param_1,int param_2)



{

  int iVar1;

  int *piVar2;

  int in_EAX;

  undefined *puVar3;

  int *piVar4;

  int unaff_ESI;

  int *piVar5;

  int local_8;

  int *local_4;

  

  piVar2 = param_1;

  piVar5 = *(int **)(in_EAX + 8);

  piVar4 = (int *)*piVar5;

  local_4 = piVar5;

  if (piVar4 != piVar5) {

    do {

      puVar3 = (undefined *)piVar4[2];

      if ((undefined *)piVar4[2] == (undefined *)0x0) {

        puVar3 = PTR_DAT_00afa2bc;

      }

      FUN_00989e00(&param_1,puVar3);

      (**(code **)(*piVar2 + 0x10))(&param_1,&local_8);

      if ((param_2 == 0) || (local_8 == param_2)) {

        iVar1 = *(int *)(unaff_ESI + 4);

        if ((iVar1 == 0) ||

           ((uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 2) <=

            (uint)(*(int *)(unaff_ESI + 8) - iVar1 >> 2))) {

          FUN_0043bfb0(*(uint32_t /* width from decompiler */ *)(unaff_ESI + 8),1,&param_1);

        }

        else {

          iVar1 = *(int *)(unaff_ESI + 8);

          FUN_00436ef0(param_1);

          *(int *)(unaff_ESI + 8) = iVar1 + 4;

          piVar5 = local_4;

        }

      }

      piVar4 = (int *)*piVar4;

    } while (piVar4 != piVar5);

  }

  return 0;

}
