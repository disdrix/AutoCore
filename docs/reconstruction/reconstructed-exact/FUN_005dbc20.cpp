// =============================================================================
// FUN_005dbc20
// -----------------------------------------------------------------------------
// Stable ID: aa_005dbc20
// Address:   0x005dbc20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005dbc20 @ 0x005dbc20
// Stable ID: aa_005dbc20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_005b04b0×2, FUN_005dbc20.
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

void __fastcall FUN_005dbc20(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x168);

  if (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x16c)) {

    do {

      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

      FUN_005b04b0(*puVar2,*(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

      iVar1 = *(int *)(*(int *)(param_1 + 4) + 4);

      FUN_005b04b0(puVar2[1],*(uint32_t /* width from decompiler */ *)(iVar1 + param_1 + 0x164),

                   *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + param_1));

      puVar2 = puVar2 + 3;

    } while (puVar2 != *(uint32_t /* width from decompiler */ **)(param_1 + 0x16c));

  }

  return;

}
