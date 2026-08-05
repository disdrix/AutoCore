// =============================================================================
// FUN_00771a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00771a00
// Address:   0x00771a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00771a00 @ 0x00771a00
// Stable ID: aa_00771a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~43 non-empty decompiler lines.
//  - Control keywords: if×4, do×1, while×1, for×1, return×1.
//  - Notable callees: FUN_00770490, FUN_00771a00.
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

int FUN_00771a00(int *param_1,int *param_2)



{

  uint uVar1;

  int iVar2;

  uint uVar3;

  uint *puVar4;

  int iVar5;

  uint *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if ((*param_1 + 1 <= param_2[1]) || (iVar2 = FUN_00770490(), iVar2 == 0)) {

    iVar2 = *param_2;

    *param_2 = *param_1;

    puVar4 = (uint *)param_1[3];

    puVar6 = (uint *)param_2[3];

    iVar5 = 0;

    uVar3 = 0;

    if (0 < *param_1) {

      do {

        uVar1 = *puVar4;

        *puVar6 = uVar1 * 2 & 0xfffffff | uVar3;

        uVar3 = uVar1 >> 0x1b;

        iVar5 = iVar5 + 1;

        puVar6 = puVar6 + 1;

        puVar4 = puVar4 + 1;

      } while (iVar5 < *param_1);

      if (uVar3 != 0) {

        *puVar6 = 1;

        *param_2 = *param_2 + 1;

      }

    }

    iVar5 = *param_2;

    if (iVar5 < iVar2) {

      puVar7 = (uint32_t /* width from decompiler */ *)(param_2[3] + iVar5 * 4);

      for (iVar2 = iVar2 - iVar5; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar7 = 0;

        puVar7 = puVar7 + 1;

      }

    }

    param_2[2] = param_1[2];

    iVar2 = 0;

  }

  return iVar2;

}
