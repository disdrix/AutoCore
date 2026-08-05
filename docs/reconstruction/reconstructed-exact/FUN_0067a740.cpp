// =============================================================================
// FUN_0067a740
// -----------------------------------------------------------------------------
// Stable ID: aa_0067a740
// Address:   0x0067a740  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067a740 @ 0x0067a740
// Stable ID: aa_0067a740
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: return×1.
//  - Notable callees: FUN_006810a0×5, CONCAT31×2, FUN_0067a740.
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

FUN_0067a740(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint8_t param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7)



{

  uint8_t local_4;

  undefined3 uStack_3;

  

  _local_4 = CONCAT31((int3)((uint)param_1 >> 8),0x15);

  FUN_006810a0(&local_4,1);

  FUN_006810a0(&param_3,1);

  param_3 = CONCAT31(param_3._1_3_,param_4);

  FUN_006810a0(&param_3,1);

  param_3 = param_5;

  FUN_006810a0(&param_3,2);

  FUN_006810a0(param_6,param_7);

  return;

}
