// =============================================================================
// FUN_0041f030
// -----------------------------------------------------------------------------
// Stable ID: aa_0041f030
// Address:   0x0041f030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0041f030 @ 0x0041f030
// Stable ID: aa_0041f030
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines.
//  - Control keywords: for×2, if×1, return×1.
//  - Notable callees: FUN_0041f030.
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

uint32_t /* width from decompiler */ * FUN_0041f030(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  

  if (param_3 != param_4) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

    puVar3 = param_3;

    for (; param_4 != puVar1; param_4 = (uint32_t /* width from decompiler */ *)((int)param_4 + 0x82)) {

      puVar4 = param_4;

      puVar5 = puVar3;

      for (iVar2 = 0x20; iVar2 != 0; iVar2 = iVar2 + -1) {

        *puVar5 = *puVar4;

        puVar4 = puVar4 + 1;

        puVar5 = puVar5 + 1;

      }

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 0x82);

      *(uint16_t *)puVar5 = *(uint16_t *)puVar4;

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar3;

  }

  *param_2 = param_3;

  return param_2;

}
