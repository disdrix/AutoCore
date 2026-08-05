// =============================================================================
// FUN_0041eb40
// -----------------------------------------------------------------------------
// Stable ID: aa_0041eb40
// Address:   0x0041eb40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041eb40 @ 0x0041eb40
// Stable ID: aa_0041eb40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, for×1, return×1.
//  - Notable callees: FUN_0041eb40.
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

uint32_t /* width from decompiler */ * FUN_0041eb40(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if (param_3 != param_4) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

    puVar2 = param_3;

    while (param_4 != puVar1) {

      puVar4 = param_4 + 0x55;

      puVar5 = puVar2 + 0x55;

      puVar6 = param_4;

      puVar7 = puVar2;

      for (iVar3 = 0x55; puVar2 = puVar5, param_4 = puVar4, iVar3 != 0; iVar3 = iVar3 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2;

  }

  *param_2 = param_3;

  return param_2;

}
