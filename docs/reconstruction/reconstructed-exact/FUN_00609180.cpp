// =============================================================================
// FUN_00609180
// -----------------------------------------------------------------------------
// Stable ID: aa_00609180
// Address:   0x00609180  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00609180 @ 0x00609180
// Stable ID: aa_00609180
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~13 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CreateSimpleObject_Serialize, FUN_00609180.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00609180(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4)



{

  CreateSimpleObject_Serialize(param_2,param_3,param_4);

  if (param_2 == (uint32_t /* width from decompiler */ *)0x0) {

    return 0;

  }

  *param_2 = 0x201a;

  param_2[0x36] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x20);

  param_2[0x37] = *(uint32_t /* width from decompiler */ *)(param_1 + -0x1c);

  *(uint8_t *)(param_2 + 0x28) = 0;

  return 0xe0;

}
