// =============================================================================
// FUN_004c38a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c38a0
// Address:   0x004c38a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c38a0 @ 0x004c38a0
// Stable ID: aa_004c38a0
// Embedded strings (evidence for future rename):
//   - "obj_gen_n_corpse_01_metalchunks_dead"
//   - "obj_gen_n_corpse_01_fleshandbone_dead"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~18 non-empty decompiler lines.
//  - Control keywords: if×2, return×2.
//  - Notable callees: FUN_00540350×2, FUN_004c38a0.
//  - Strings: "obj_gen_n_corpse_01_metalchunks_dead"; "obj_gen_n_corpse_01_fleshandbone_dead".
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

void FUN_004c38a0(void)



{

  int iVar1;

  

  iVar1 = FUN_00540350("obj_gen_n_corpse_01_metalchunks_dead");

  if (iVar1 == 0) {

    DAT_00b037a4 = 0xffffffff;

  }

  else {

    DAT_00b037a4 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

  }

  iVar1 = FUN_00540350("obj_gen_n_corpse_01_fleshandbone_dead");

  if (iVar1 != 0) {

    DAT_00b037a0 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x34);

    return;

  }

  DAT_00b037a0 = 0xffffffff;

  return;

}
