// =============================================================================
// FUN_005e5060
// -----------------------------------------------------------------------------
// Stable ID: aa_005e5060
// Address:   0x005e5060  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005e5060 @ 0x005e5060
// Stable ID: aa_005e5060
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~29 non-empty decompiler lines.
//  - Control keywords: if×1, while×1, for×1, return×1.
//  - Notable callees: FUN_005e5060.
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

void __thiscall

FUN_005e5060(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ *param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  

  if (param_3 != param_4) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);

    puVar2 = param_3;

    while (param_4 != puVar1) {

      puVar3 = param_4 + 0xf;

      puVar5 = puVar2 + 0xf;

      puVar6 = param_4;

      puVar7 = puVar2;

      for (iVar4 = 0xf; param_4 = puVar3, puVar2 = puVar5, iVar4 != 0; iVar4 = iVar4 + -1) {

        *puVar7 = *puVar6;

        puVar6 = puVar6 + 1;

        puVar7 = puVar7 + 1;

      }

    }

    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2;

  }

  *param_2 = param_3;

  return;

}
