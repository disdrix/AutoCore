// =============================================================================
// FUN_004d2ac0
// -----------------------------------------------------------------------------
// Stable ID: aa_004d2ac0
// Address:   0x004d2ac0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d2ac0 @ 0x004d2ac0
// Stable ID: aa_004d2ac0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~9 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: CNDHash_LookupByKey, FUN_004d2ac0.
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

bool __thiscall FUN_004d2ac0(int param_1,int param_2,uint32_t /* width from decompiler */ param_3,uint param_4)



{

  void *pvVar1;

  

  if (*(char *)(param_1 + 0x83) != '\0') {

    return true;

  }

  pvVar1 = CNDHash_LookupByKey(*(void **)(param_2 + 0x534),param_4);

  return pvVar1 != (void *)0x0;

}
