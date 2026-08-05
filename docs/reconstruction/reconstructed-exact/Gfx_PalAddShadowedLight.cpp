// =============================================================================
// Gfx_PalAddShadowedLight
// -----------------------------------------------------------------------------
// Stable ID: aa_00734100
// Address:   0x00734100  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_PalAddShadowedLight @ 0x00734100
// Stable ID: aa_00734100
// Embedded strings (evidence for future rename):
//   - "PalAddShadowedLight.fx"
//   - "PhaseAlpha_Test.fx"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_009701d0×2, FUN_00989e00×2, Gfx_PalAddShadowedLight.
//  - Strings: "PalAddShadowedLight.fx"; "PhaseAlpha_Test.fx".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "PalAddShadowedLight.fx"
 * Domain alias of FUN_00734100 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Gfx_PalAddShadowedLight(int param_1)



{

  int iVar1;

  int local_4;

  

  local_4 = param_1;

  FUN_00989e00(&local_4,"PalAddShadowedLight.fx");

  iVar1 = FUN_009701d0(&local_4);

  if (-1 < iVar1) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x18) + 8) + 0x28) = 2;

  }

  FUN_00989e00(&local_4,"PhaseAlpha_Test.fx");

  iVar1 = FUN_009701d0(&local_4);

  if (-1 < iVar1) {

    *(uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 0x20) + 8) + 0x28) = 1;

  }

  return;

}
