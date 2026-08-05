// =============================================================================
// FUN_006f4830
// -----------------------------------------------------------------------------
// Stable ID: aa_006f4830
// Address:   0x006f4830  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f4830 @ 0x006f4830
// Stable ID: aa_006f4830
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, for×2, while×2, return×1.
//  - Notable callees: FUN_006f4830×2.
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

void FUN_006f4830(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  float *pfVar7;

  uint32_t /* width from decompiler */ *puVar8;

  int iVar9;

  int iVar10;

  

  do {

    fVar2 = *(float *)((param_2 + param_3 >> 1) * 0x10 + param_1 + 8);

    iVar9 = param_3;

    iVar10 = param_2;

    do {

      for (pfVar7 = (float *)(iVar10 * 0x10 + 8 + param_1); *pfVar7 < fVar2; pfVar7 = pfVar7 + 4) {

        iVar10 = iVar10 + 1;

      }

      for (pfVar7 = (float *)(iVar9 * 0x10 + 8 + param_1); fVar2 < *pfVar7; pfVar7 = pfVar7 + -4) {

        iVar9 = iVar9 + -1;

      }

      if (iVar9 < iVar10) break;

      if (iVar9 != iVar10) {

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar9 * 0x10 + param_1);

        uVar3 = *puVar1;

        uVar4 = puVar1[1];

        uVar5 = puVar1[2];

        uVar6 = puVar1[3];

        puVar8 = (uint32_t /* width from decompiler */ *)(iVar10 * 0x10 + param_1);

        *puVar1 = *puVar8;

        puVar1[1] = puVar8[1];

        puVar1[2] = puVar8[2];

        puVar1[3] = puVar8[3];

        *puVar8 = uVar3;

        puVar8[1] = uVar4;

        puVar8[2] = uVar5;

        puVar8[3] = uVar6;

      }

      iVar9 = iVar9 + -1;

      iVar10 = iVar10 + 1;

    } while (iVar10 <= iVar9);

    if (param_2 < iVar9) {

      FUN_006f4830(param_1,param_2,iVar9,param_4);

    }

    param_2 = iVar10;

    if (param_3 <= iVar10) {

      return;

    }

  } while( true );

}
