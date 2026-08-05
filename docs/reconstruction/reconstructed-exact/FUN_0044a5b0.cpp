// =============================================================================
// FUN_0044a5b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0044a5b0
// Address:   0x0044a5b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0044a5b0 @ 0x0044a5b0
// Stable ID: aa_0044a5b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×3, return×3.
//  - Notable callees: FUN_0044a5b0, FUN_0044a730, FUN_0044a800, FUN_0044a860.
//  - Return sites: 3.

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

int FUN_0044a5b0(uint32_t /* width from decompiler */ param_1)



{

  int *in_EAX;

  int iVar1;

  int unaff_EDI;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  

  (**(code **)(*in_EAX + 0x38))();

  (**(code **)(*in_EAX + 0x34))();

  FUN_0044a800();

  if (uStack_1c != *(int *)(unaff_EDI + 4)) {

    return *(int *)(uStack_1c + 0x14);

  }

  (**(code **)(*in_EAX + 0x30))();

  FUN_0044a860();

  if (uStack_18 == DAT_00d21968) {

    return 0;

  }

  iVar1 = (**(code **)(uStack_18 + 0x10))(param_1);

  if (iVar1 != 0) {

    FUN_0044a730();

  }

  return iVar1;

}
