// =============================================================================
// FUN_00448300
// -----------------------------------------------------------------------------
// Stable ID: aa_00448300
// Address:   0x00448300  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00448300 @ 0x00448300
// Stable ID: aa_00448300
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: for×1, if×1, return×1.
//  - Notable callees: FUN_00447660, FUN_00447a30, FUN_00448300.
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

int __fastcall FUN_00448300(int param_1)



{

  int in_EAX;

  int unaff_ESI;

  int local_4;

  

  local_4 = param_1;

  for (; param_1 != unaff_ESI; param_1 = param_1 + 0xc) {

    if (in_EAX != param_1) {

      FUN_00447660(&local_4,**(uint32_t /* width from decompiler */ **)(in_EAX + 4),*(uint32_t /* width from decompiler */ **)(in_EAX + 4));

      FUN_00447a30();

    }

    in_EAX = in_EAX + 0xc;

  }

  return in_EAX;

}
