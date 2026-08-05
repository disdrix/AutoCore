// =============================================================================
// FUN_0055f6c0
// -----------------------------------------------------------------------------
// Stable ID: aa_0055f6c0
// Address:   0x0055f6c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055f6c0 @ 0x0055f6c0
// Stable ID: aa_0055f6c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~48 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, do×1, while×1.
//  - Notable callees: FUN_0055f6c0, FUN_0055f750, FUN_005b3370.
//  - Return sites: 2.

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

void __thiscall FUN_0055f6c0(int param_1,int *param_2)



{

  int iVar1;

  int iVar2;

  int *piVar3;

  int *piVar4;

  

  if (*(int *)(param_1 + 4) == 0) {

    iVar2 = 0;

  }

  else {

    iVar2 = *(int *)(param_1 + 4) + 0x10;

  }

  iVar1 = *param_2;

  if (iVar1 == iVar2) {

    iVar1 = param_2[1];

  }

  if (iVar1 == 0) {

    iVar1 = 0;

  }

  else {

    iVar1 = iVar1 + -0x10;

  }

  if (*(char *)(*(int *)(iVar1 + 0x20) + 0x40) == '\0') {

    iVar2 = *(int *)(*(int *)(iVar1 + 0x20) + 0x44);

    FUN_0055f750(param_2);

    piVar4 = (int *)(param_1 + 8);

    iVar1 = 0;

    if (0 < *(int *)(param_1 + 0xc)) {

      piVar3 = (int *)*piVar4;

      do {

        if (*piVar3 == iVar2) {

          if (iVar1 != -1) {

            return;

          }

          break;

        }

        iVar1 = iVar1 + 1;

        piVar3 = piVar3 + 1;

      } while (iVar1 < *(int *)(param_1 + 0xc));

    }

    if (*(uint *)(param_1 + 0xc) == (*(uint *)(param_1 + 0x10) & 0x7fffffff)) {

      FUN_005b3370(piVar4,4);

    }

    *(int *)(*piVar4 + *(int *)(param_1 + 0xc) * 4) = iVar2;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + 1;

  }

  return;

}
