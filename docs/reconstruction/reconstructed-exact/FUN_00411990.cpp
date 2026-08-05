// =============================================================================
// FUN_00411990
// -----------------------------------------------------------------------------
// Stable ID: aa_00411990
// Address:   0x00411990  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00411990 @ 0x00411990
// Stable ID: aa_00411990
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00411990.
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

void FUN_00411990(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int in_EAX;

  

  if (*(int *)(in_EAX + 0x660) < 1) {

    if (*(int *)(in_EAX + 0x654) < 1000000) {

      *(int *)(in_EAX + 0x654) = *(int *)(in_EAX + 0x654) + 1;

    }

  }

  else {

    *(int *)(in_EAX + 0x660) = *(int *)(in_EAX + 0x660) + -1;

  }

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x658) = param_1;

  *(uint32_t /* width from decompiler */ *)(in_EAX + 0x65c) = param_2;

  return;

}
