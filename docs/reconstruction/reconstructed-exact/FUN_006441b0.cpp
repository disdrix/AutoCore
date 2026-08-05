// =============================================================================
// FUN_006441b0
// -----------------------------------------------------------------------------
// Stable ID: aa_006441b0
// Address:   0x006441b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006441b0 @ 0x006441b0
// Stable ID: aa_006441b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, return×2, while×2.
//  - Notable callees: FUN_006441b0, SQRT.
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

void __thiscall

FUN_006441b0(int param_1,int param_2,int param_3,int param_4,int param_5,int param_6)



{

  uint16_t uVar1;

  int iVar2;

  int iVar3;

  int iVar4;

  int iVar5;

  int iVar6;

  float fVar7;

  float fVar8;

  

  iVar2 = *(int *)(param_6 + 0x3e0);

  iVar3 = *(int *)(param_1 + 0xc);

  uVar1 = *(uint16_t *)(iVar2 + (*(int *)(param_6 + 0x10) * param_5 + param_4) * 2);

  iVar4 = *(int *)(param_1 + 4);

  param_4 = 0;

  if (0 < iVar4) {

    do {

      if (*(int *)(param_6 + 0x14) <= param_3) {

        return;

      }

      iVar6 = 0;

      iVar5 = param_2;

      if (0 < iVar4) {

        do {

          if (*(int *)(param_6 + 0x10) <= iVar5) break;

          if ((iVar3 == 0) ||

             (fVar7 = (float)(*(int *)(param_1 + 4) >> 1), fVar8 = (float)param_4 - fVar7,

             fVar7 = (float)iVar6 - fVar7,

             SQRT(fVar8 * fVar8 + fVar7 * fVar7) <= (float)(iVar4 >> 1))) {

            *(uint16_t *)(iVar2 + (*(int *)(param_6 + 0x10) * param_3 + iVar5) * 2) = uVar1;

          }

          iVar4 = *(int *)(param_1 + 4);

          iVar6 = iVar6 + 1;

          iVar5 = iVar5 + 1;

        } while (iVar6 < iVar4);

      }

      iVar4 = *(int *)(param_1 + 4);

      param_4 = param_4 + 1;

      param_3 = param_3 + 1;

    } while (param_4 < iVar4);

  }

  return;

}
