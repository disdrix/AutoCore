// =============================================================================
// FUN_006e4850
// -----------------------------------------------------------------------------
// Stable ID: aa_006e4850
// Address:   0x006e4850  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006e4850 @ 0x006e4850
// Stable ID: aa_006e4850
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~11 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006e47d0, FUN_006e4850.
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

void FUN_006e4850(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  uint32_t /* width from decompiler */ unaff_retaddr;

  uint32_t /* width from decompiler */ uVar2;

  

  uVar2 = 0x1a;

  iVar1 = (**(code **)(*DAT_00b05060 + 0x10))(0xf0,0x1a);

  *(uint16_t *)(iVar1 + 4) = 0xf0;

  FUN_006e47d0(uVar2,unaff_retaddr,param_2);

  return;

}
