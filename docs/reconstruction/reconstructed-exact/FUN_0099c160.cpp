// =============================================================================
// FUN_0099c160
// -----------------------------------------------------------------------------
// Stable ID: aa_0099c160
// Address:   0x0099c160  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0099c160 @ 0x0099c160
// Stable ID: aa_0099c160
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_00426f60×2, FUN_00744970, FUN_007449f0, FUN_007450b0, FUN_0099c160.
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

void __thiscall FUN_0099c160(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  uint8_t local_18 [12];

  uint8_t local_c [12];

  

  cVar1 = FUN_007449f0(param_1,param_3);

  if (cVar1 != '\0') {

    FUN_00744970(param_1,param_3,0);

    return;

  }

  FUN_00426f60();

  FUN_00426f60();

  FUN_007450b0(param_1,local_c,local_18);

  return;

}
