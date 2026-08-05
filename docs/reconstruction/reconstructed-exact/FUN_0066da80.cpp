// =============================================================================
// FUN_0066da80
// -----------------------------------------------------------------------------
// Stable ID: aa_0066da80
// Address:   0x0066da80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0066da80 @ 0x0066da80
// Stable ID: aa_0066da80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×6, do×3, while×3, goto×1, return×1.
//  - Notable callees: FUN_00507210, FUN_00507310, FUN_0055e570, FUN_0066da80.
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

void __thiscall FUN_0066da80(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  

  iVar5 = 0;

  if (0 < *(int *)(param_1 + 0x20)) {

    do {

      FUN_00507210(param_1 + 0x18);

      iVar5 = iVar5 + 1;

    } while (iVar5 < *(int *)(param_1 + 0x20));

  }

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x20) = 0;

  iVar5 = *(int *)(param_2 + 4);

  if (0 < iVar5) {

    FUN_0055e570(0,param_2);

    iVar6 = 0;

    if (0 < iVar5) {

      do {

        iVar1 = *(int *)(*(int *)(param_1 + 0x1c) + iVar6 * 4);

        iVar2 = *(int *)(iVar1 + 0x80);

        iVar3 = 0;

        if (0 < iVar2) {

          piVar4 = *(int **)(iVar1 + 0x7c);

          do {

            if (*piVar4 == param_1 + 0x18) {

              if (-1 < iVar3) goto LAB_0066dafe;

              break;

            }

            iVar3 = iVar3 + 1;

            piVar4 = piVar4 + 1;

          } while (iVar3 < iVar2);

        }

        FUN_00507310(param_1 + 0x18);

LAB_0066dafe:

        iVar6 = iVar6 + 1;

      } while (iVar6 < iVar5);

    }

  }

  return;

}
