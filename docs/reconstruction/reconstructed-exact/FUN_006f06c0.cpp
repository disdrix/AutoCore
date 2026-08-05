// =============================================================================
// FUN_006f06c0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f06c0
// Address:   0x006f06c0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f06c0 @ 0x006f06c0
// Stable ID: aa_006f06c0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_005d6ae0, FUN_006f06c0.
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

void __thiscall FUN_006f06c0(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ *param_4)



{

  char *pcVar1;

  uint8_t local_31;

  uint8_t local_30 [20];

  uint32_t /* width from decompiler */ local_1c;

  

  local_1c = param_4[1];

  pcVar1 = (char *)(**(code **)(*param_1 + 0x20))(&local_31,param_2,local_30);

  if (*pcVar1 != '\0') {

    FUN_005d6ae0(*(int *)(param_3 + 8) + 0x20,&stack0xffffffc4);

    (**(code **)*param_4)(param_3,&stack0xffffffc4);

  }

  return;

}
