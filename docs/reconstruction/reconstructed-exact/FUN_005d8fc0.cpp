// =============================================================================
// FUN_005d8fc0
// -----------------------------------------------------------------------------
// Stable ID: aa_005d8fc0
// Address:   0x005d8fc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005d8fc0 @ 0x005d8fc0
// Stable ID: aa_005d8fc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_005d89f0, FUN_005d8fc0.
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

uint32_t /* width from decompiler */ FUN_005d8fc0(uint32_t /* width from decompiler */ param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = 0xc;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0x68,0xc);

  if (iVar1 != 0) {

    uVar2 = FUN_005d89f0(uVar2,unaff_retaddr,param_1);

    return uVar2;

  }

  return 0;

}
