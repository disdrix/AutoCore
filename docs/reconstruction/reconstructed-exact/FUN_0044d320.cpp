// =============================================================================
// FUN_0044d320
// -----------------------------------------------------------------------------
// Stable ID: aa_0044d320
// Address:   0x0044d320  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044d320 @ 0x0044d320
// Stable ID: aa_0044d320
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~62 non-empty decompiler lines.
//  - Control keywords: while×3, if×3, do×1, return×1.
//  - Notable callees: FUN_0044d320.
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

void FUN_0044d320(int param_1,int param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ uVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  uint32_t /* width from decompiler */ **ppuVar9;

  int iVar10;

  int iVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint32_t /* width from decompiler */ *local_10;

  uint32_t /* width from decompiler */ *local_c [3];

  

  puVar5 = param_3;

  iVar10 = (int)param_3 - param_1 >> 3;

  iVar11 = param_2 - param_1 >> 3;

  iVar8 = iVar11;

  param_2 = iVar10;

  while (iVar3 = iVar8, iVar3 != 0) {

    iVar8 = param_2 % iVar3;

    param_2 = iVar3;

  }

  if ((param_2 < iVar10) && (0 < param_2)) {

    puVar12 = (uint32_t /* width from decompiler */ *)(param_1 + param_2 * 8);

    do {

      uVar1 = puVar12[1];

      uVar2 = *puVar12;

      if (puVar12 + iVar11 * 2 == puVar5) {

        puVar7 = &param_1;

      }

      else {

        param_3 = puVar12 + iVar11 * 2;

        puVar7 = &param_3;

      }

      puVar6 = (uint32_t /* width from decompiler */ *)*puVar7;

      puVar7 = puVar12;

      while (puVar4 = puVar6, puVar4 != puVar12) {

        *puVar7 = *puVar4;

        puVar7[1] = puVar4[1];

        iVar8 = (int)puVar5 - (int)puVar4 >> 3;

        if (iVar11 < iVar8) {

          local_10 = puVar4 + iVar11 * 2;

          ppuVar9 = &local_10;

        }

        else {

          local_c[0] = (uint32_t /* width from decompiler */ *)(param_1 + (iVar8 * 0x1fffffff + iVar11) * 8);

          ppuVar9 = local_c;

        }

        puVar7 = puVar4;

        puVar6 = *ppuVar9;

      }

      puVar12 = puVar12 + -2;

      param_2 = param_2 + -1;

      *puVar7 = uVar2;

      puVar7[1] = uVar1;

    } while (param_2 != 0);

  }

  return;

}
