// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005b81e0, FUN_007a4480.
//  - Strings: "NO MAXPARTICLES ON MASTER FLUID".
//  - Return sites: 1.

// =============================================================================
// Named_NO_MAXPARTICLES_ON_MASTER_FLUID
// -----------------------------------------------------------------------------
// Stable ID: aa_005b81e0
// Address:   0x005b81e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "NO MAXPARTICLES ON MASTER FLUID"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __fastcall Named_NO_MAXPARTICLES_ON_MASTER_FLUID(uint32_t /* width from decompiler */ *param_1)



{

  int iVar1;

  int iVar2;

  

  iVar2 = (**(code **)*param_1)();

  if (*(int *)(iVar2 + 0xc) == 0) {

    FUN_007a4480(0,"NO MAXPARTICLES ON MASTER FLUID");

  }

  iVar1 = *(int *)(iVar2 + 0x10);

  *(uint *)(iVar2 + 0x10) = (iVar1 + 1U) % *(uint *)(iVar2 + 0xc);

  return iVar1;

}
