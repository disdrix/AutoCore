// =============================================================================
// FUN_00521440
// -----------------------------------------------------------------------------
// Stable ID: aa_00521440
// Address:   0x00521440  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00521440 @ 0x00521440
// Stable ID: aa_00521440
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, if×1, return×1.
//  - Notable callees: FUN_00521440, NetObject_SetMaskBits.
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

void __thiscall FUN_00521440(int param_1,char *param_2)



{

  char cVar1;

  void *this;

  int iVar2;

  

  iVar2 = (param_1 + 0xcfc) - (int)param_2;

  do {

    cVar1 = *param_2;

    param_2[iVar2] = cVar1;

    param_2 = param_2 + 1;

  } while (cVar1 != '\0');

  this = *(void **)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x18 + param_1);

  if (this != (void *)0x0) {

    NetObject_SetMaskBits(this,0x20000000,0);

  }

  return;

}
