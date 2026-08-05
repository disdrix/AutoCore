// =============================================================================
// FUN_00680d90
// -----------------------------------------------------------------------------
// Stable ID: aa_00680d90
// Address:   0x00680d90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00680d90 @ 0x00680d90
// Stable ID: aa_00680d90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×2, for×2, return×2.
//  - Notable callees: FUN_00680d90.
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

uint __thiscall FUN_00680d90(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  uint uVar1;

  uint uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  uVar1 = *(uint *)(param_1 + 0xc);

  if ((uVar1 != 0) && (*(int *)(param_1 + 4) != 0)) {

    if (param_3 <= uVar1) {

      uVar1 = param_3;

    }

    puVar3 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + *(int *)(param_1 + 4));

    for (uVar2 = uVar1 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

      *param_2 = *puVar3;

      puVar3 = puVar3 + 1;

      param_2 = param_2 + 1;

    }

    for (uVar2 = uVar1 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

      *(uint8_t *)param_2 = *(uint8_t *)puVar3;

      puVar3 = (uint32_t /* width from decompiler */ *)((int)puVar3 + 1);

      param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    }

    return uVar1;

  }

  return 0;

}
