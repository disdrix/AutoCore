// =============================================================================
// FUN_0046c890
// -----------------------------------------------------------------------------
// Stable ID: aa_0046c890
// Address:   0x0046c890  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0046c890 @ 0x0046c890
// Stable ID: aa_0046c890
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0046c1b0, FUN_0046c890, FUN_0046c8f0.
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

int __fastcall FUN_0046c890(int param_1)



{

  uint32_t /* width from decompiler */ *in_EAX;

  int *piVar1;

  int local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  FUN_0046c1b0();

  if (local_18[0] == *(int *)(param_1 + 8)) {

    local_10 = *in_EAX;

    local_c = 0;

    local_8 = 0;

    local_4 = 0;

    piVar1 = (int *)FUN_0046c8f0(local_18,&local_10);

    local_18[0] = *piVar1;

  }

  return local_18[0] + 0xc;

}
