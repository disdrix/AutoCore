// =============================================================================
// FUN_00938340
// -----------------------------------------------------------------------------
// Stable ID: aa_00938340
// Address:   0x00938340  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00938340 @ 0x00938340
// Stable ID: aa_00938340
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~12 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00938340.
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

void __fastcall FUN_00938340(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  uint32_t /* width from decompiler */ local_c [2];

  uint32_t /* width from decompiler */ local_4;

  

  local_c[0] = 0x20a0;

  if (*(int *)(in_EAX + 0xc78) != 0) {

    local_4 = param_2;

    (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_c,0xc,0);

  }

  return;

}
