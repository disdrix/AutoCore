// =============================================================================
// FUN_00702cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00702cb0
// Address:   0x00702cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00702cb0 @ 0x00702cb0
// Stable ID: aa_00702cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, do×1, while×1.
//  - Notable callees: FUN_00702cb0.
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

uint FUN_00702cb0(int *param_1,int param_2)



{

  int iVar1;

  char cVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  uint uVar6;

  

  piVar5 = param_1;

  uVar6 = 0;

  if (param_1[1] < param_2 + param_1[2] * 8 + param_1[3]) {

    param_1[5] = 1;

  }

  if (param_1[5] == 0) {

    if (param_2 != 0) {

      iVar3 = *param_1;

      param_1 = (int *)param_2;

      do {

        iVar4 = piVar5[3];

        cVar2 = *(char *)(iVar3 + piVar5[2]);

        iVar1 = iVar4 + 1;

        piVar5[3] = iVar1;

        uVar6 = uVar6 * 2 | (int)cVar2 >> (7U - (char)iVar4 & 0x1f) & 1U;

        if (iVar1 == 8) {

          piVar5[3] = 0;

          piVar5[2] = piVar5[2] + 1;

        }

        param_1 = (int *)((int)param_1 + -1);

      } while (param_1 != (int *)0x0);

    }

    return uVar6;

  }

  return 0;

}
