// =============================================================================
// FUN_007abe20
// -----------------------------------------------------------------------------
// Stable ID: aa_007abe20
// Address:   0x007abe20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007abe20 @ 0x007abe20
// Stable ID: aa_007abe20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007abe20.
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

void __fastcall FUN_007abe20(int *param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint8_t local_8 [8];

  

  local_c = 0;

  *(uint8_t *)((int)param_1 + 0xcf) = 1;

  if (param_1[0xa5] == 0) {

    local_10 = 0;

  }

  else {

    puVar1 = (uint32_t /* width from decompiler */ *)(**(code **)(*param_1 + 0x140))(local_8,1);

    local_10 = *puVar1;

    local_c = puVar1[1];

  }

  (**(code **)(*param_1 + 0x2cc))(&local_10);

  return;

}
