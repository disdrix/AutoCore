// =============================================================================
// FUN_00524680
// -----------------------------------------------------------------------------
// Stable ID: aa_00524680
// Address:   0x00524680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00524680 @ 0x00524680
// Stable ID: aa_00524680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×2, goto×2.
//  - Notable callees: FUN_00522f70, FUN_00524680, NetObject_SetMaskBits.
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

void __thiscall FUN_00524680(int param_1,int param_2)



{

  int iVar1;

  int iVar2;

  void *this;

  uint dwMaskLo;

  

  if (*(int *)(param_1 + 0x514) == param_2) {

    return;

  }

  iVar1 = *(int *)(*(int *)(param_1 + 4) + 4) + param_1;

  iVar2 = *(int *)(iVar1 + 0xa8);

  if (*(char *)(iVar2 + 0x7e) == '\0') goto LAB_005246f7;

  if ((*(char *)(iVar2 + 0xf5) == '\0') || (this = *(void **)(iVar1 + 0x18), this == (void *)0x0)) {

    iVar1 = *(int *)(param_1 + 0x250);

    if ((iVar1 != 0) && (*(int *)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1) != 0)) {

      this = *(void **)(*(int *)(*(int *)(iVar1 + 4) + 4) + 0x18 + iVar1);

      dwMaskLo = 0x1000000;

      goto LAB_005246e5;

    }

  }

  else {

    dwMaskLo = 0x40000000;

LAB_005246e5:

    NetObject_SetMaskBits(this,dwMaskLo,0);

  }

  *(int *)(param_1 + 0x514) = param_2;

  FUN_00522f70();

LAB_005246f7:

  *(int *)(param_1 + 0x514) = param_2;

  return;

}
