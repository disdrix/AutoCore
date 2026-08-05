// =============================================================================
// FUN_0058d8e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0058d8e0
// Address:   0x0058d8e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0058d8e0 @ 0x0058d8e0
// Stable ID: aa_0058d8e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0058c850, FUN_0058d8e0.
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

void FUN_0058d8e0(uint32_t /* width from decompiler */ param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

                 uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  if (param_2 == 0) {

    return;

  }

  local_20 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x160);

  local_1c = *(uint32_t /* width from decompiler */ *)(param_2 + 0x164);

  local_18 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x168);

  local_14 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x16c);

  local_10 = DAT_009d4d28;

  local_c = DAT_009d4d2c;

  local_8 = DAT_009d4d30;

  local_4 = DAT_009d4d34;

  FUN_0058c850(param_1,&local_20,param_3,param_4,param_5,param_6);

  return;

}
