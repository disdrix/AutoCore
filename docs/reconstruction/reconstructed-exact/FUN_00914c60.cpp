// =============================================================================
// FUN_00914c60
// -----------------------------------------------------------------------------
// Stable ID: aa_00914c60
// Address:   0x00914c60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00914c60 @ 0x00914c60
// Stable ID: aa_00914c60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×6, goto×5, return×1.
//  - Notable callees: FUN_007902a0, FUN_007fb990, FUN_00914c20, FUN_00914c60.
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

void __thiscall FUN_00914c60(int param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  if ((char)param_2 == '\0') {

    if (*(char *)(param_1 + 0x493) == '\0') goto LAB_00914cce;

    FUN_007fb990();

    FUN_00914c20();

    if (DAT_00d1b9a8 == (int *)0x0) goto LAB_00914cce;

    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();

    if (cVar1 == '\0') goto LAB_00914cce;

    uVar2 = 0;

  }

  else {

    if ((*(char *)(param_1 + 0x493) != '\0') || (DAT_00d1b9a8 == (int *)0x0)) goto LAB_00914cce;

    cVar1 = (**(code **)(*DAT_00d1b9a8 + 0xd0))();

    if (cVar1 != '\0') goto LAB_00914cce;

    uVar2 = 1;

  }

  (**(code **)(*DAT_00d1b9a8 + 4))(uVar2);

LAB_00914cce:

  *(uint32_t /* width from decompiler */ *)(param_1 + 0x538) = 0;

  FUN_007902a0(param_2);

  return;

}
