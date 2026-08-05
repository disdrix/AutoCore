// =============================================================================
// FUN_005ec550
// -----------------------------------------------------------------------------
// Stable ID: aa_005ec550
// Address:   0x005ec550  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ec550 @ 0x005ec550
// Stable ID: aa_005ec550
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: FUN_005ec550.
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

void __thiscall FUN_005ec550(int *param_1,float *param_2,int param_3,int param_4)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fVar4;

  uint uVar5;

  int iVar6;

  int iVar7;

  int *piVar8;

  int iVar9;

  

  uVar5 = 0;

  if (param_1[3] != 0) {

    piVar8 = param_1 + 4;

    do {

      if (*piVar8 == param_3) {

        if (*(char *)(uVar5 + 0x18 + (int)param_1) == '\0') {

          iVar9 = **(int **)(param_4 + 0x10);

          iVar6 = *param_1;

          iVar7 = param_1[1];

        }

        else {

          iVar6 = param_1[1];

          iVar9 = **(int **)(param_4 + 0x10);

          iVar7 = *param_1;

        }

        fVar1 = *(float *)(iVar9 + 4 + iVar7 * 0xc);

        fVar2 = *(float *)(iVar9 + 8 + iVar7 * 0xc);

        fVar3 = *(float *)(iVar9 + 4 + iVar6 * 0xc);

        fVar4 = *(float *)(iVar9 + 8 + iVar6 * 0xc);

        *param_2 = *(float *)(iVar9 + iVar7 * 0xc) - *(float *)(iVar9 + iVar6 * 0xc);

        param_2[1] = fVar1 - fVar3;

        param_2[2] = fVar2 - fVar4;

        return;

      }

      uVar5 = uVar5 + 1;

      piVar8 = piVar8 + 1;

    } while (uVar5 < (uint)param_1[3]);

  }

  *param_2 = 0.0;

  param_2[1] = 0.0;

  param_2[2] = 0.0;

  return;

}
