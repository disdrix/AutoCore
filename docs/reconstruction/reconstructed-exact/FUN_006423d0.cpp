// =============================================================================
// FUN_006423d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006423d0
// Address:   0x006423d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006423d0 @ 0x006423d0
// Stable ID: aa_006423d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_00641900×3, FUN_00656110×3, FUN_00638060, FUN_006416b0, FUN_00641860, FUN_006418e0, FUN_00641ad0, FUN_006423d0.
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

void FUN_006423d0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint32_t /* width from decompiler */ uVar1;

  

  FUN_006416b0(0xd);

  FUN_00656110(param_1);

  FUN_00656110(param_2);

  FUN_00656110(param_3);

  FUN_00641900(param_4);

  FUN_00641900(param_5);

  FUN_00641900(param_6);

  uVar1 = FUN_00638060(param_7);

  FUN_006418e0(uVar1);

  FUN_00641860(param_7,uVar1);

  FUN_00641ad0();

  return;

}
