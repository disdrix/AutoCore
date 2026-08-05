// =============================================================================
// FUN_00489f20
// -----------------------------------------------------------------------------
// Stable ID: aa_00489f20
// Address:   0x00489f20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00489f20 @ 0x00489f20
// Stable ID: aa_00489f20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~66 non-empty decompiler lines.
//  - Control keywords: if×4, do×2, for×2, while×2, return×1.
//  - Notable callees: FUN_00489f20×2.
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

void FUN_00489f20(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  float fVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  float *pfVar10;

  uint32_t /* width from decompiler */ *puVar11;

  int iVar12;

  int iVar13;

  

  do {

    fVar2 = *(float *)((param_2 + param_3 >> 1) * 0x30 + 0x14 + param_1);

    iVar12 = param_3;

    iVar13 = param_2;

    do {

      for (pfVar10 = (float *)(iVar13 * 0x30 + 0x14 + param_1); *pfVar10 < fVar2;

          pfVar10 = pfVar10 + 0xc) {

        iVar13 = iVar13 + 1;

      }

      for (pfVar10 = (float *)(iVar12 * 0x30 + 0x14 + param_1); fVar2 < *pfVar10;

          pfVar10 = pfVar10 + -0xc) {

        iVar12 = iVar12 + -1;

      }

      if (iVar12 < iVar13) break;

      if (iVar12 != iVar13) {

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar12 * 0x30 + param_1);

        puVar1 = (uint32_t /* width from decompiler */ *)(iVar12 * 0x30 + param_1);

        uVar5 = puVar1[2];

        uVar4 = puVar1[1];

        uVar6 = puVar1[4];

        uVar7 = puVar1[3];

        uVar8 = puVar1[5];

        uVar9 = puVar1[8];

        puVar11 = (uint32_t /* width from decompiler */ *)(iVar13 * 0x30 + param_1);

        *puVar1 = *puVar11;

        puVar1[1] = puVar11[1];

        puVar1[2] = puVar11[2];

        puVar1[3] = puVar11[3];

        puVar1[4] = puVar11[4];

        puVar1[5] = puVar11[5];

        puVar1[8] = puVar11[8];

        *puVar11 = uVar3;

        puVar11[1] = uVar4;

        puVar11[2] = uVar5;

        puVar11[3] = uVar7;

        puVar11[5] = uVar8;

        puVar11[4] = uVar6;

        puVar11[8] = uVar9;

      }

      iVar12 = iVar12 + -1;

      iVar13 = iVar13 + 1;

    } while (iVar13 <= iVar12);

    if (param_2 < iVar12) {

      FUN_00489f20(param_1,param_2,iVar12,param_4);

    }

    param_2 = iVar13;

    if (param_3 <= iVar13) {

      return;

    }

  } while( true );

}
