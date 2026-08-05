// =============================================================================
// FUN_004ac220
// -----------------------------------------------------------------------------
// Stable ID: aa_004ac220
// Address:   0x004ac220  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ac220 @ 0x004ac220
// Stable ID: aa_004ac220
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: while×1, if×1, return×1.
//  - Notable callees: FUN_005be7b0×2, FUN_004ac100, FUN_004ac220.
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

void __fastcall FUN_004ac220(uint32_t /* width from decompiler */ *param_1)



{

  char cVar1;

  uint32_t /* width from decompiler */ *local_4;

  

  local_4 = param_1;

  cVar1 = FUN_005be7b0(&local_4);

  while (cVar1 != '\0') {

    *(uint32_t /* width from decompiler */ *)(param_1[0xe3] + (local_4[0x35] * param_1[0xe1] + local_4[0x34]) * 4) = 0;

    if (local_4 != (uint32_t /* width from decompiler */ *)0x0) {

      (**(code **)*local_4)(1);

    }

    local_4 = (uint32_t /* width from decompiler */ *)0x0;

    cVar1 = FUN_005be7b0(&local_4);

  }

  FUN_004ac100(0);

  return;

}
