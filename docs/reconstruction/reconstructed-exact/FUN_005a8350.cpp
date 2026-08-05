// =============================================================================
// FUN_005a8350
// -----------------------------------------------------------------------------
// Stable ID: aa_005a8350
// Address:   0x005a8350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005a8350 @ 0x005a8350
// Stable ID: aa_005a8350
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×1, do×1, while×1, return×1.
//  - Notable callees: FUN_005a75f0, FUN_005a8350.
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

void __thiscall FUN_005a8350(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3)



{

  char cVar1;

  int iVar2;

  

  cVar1 = *(char *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac + param_1) + 0x3c)

                   + 0x4ce);

  if (((cVar1 != '\x02') && (cVar1 != '\x04')) && (iVar2 = 0, 0 < *(int *)(param_1 + 0xf0))) {

    do {

      FUN_005a75f0(iVar2,param_2,param_3);

      iVar2 = iVar2 + 1;

    } while (iVar2 < *(int *)(param_1 + 0xf0));

  }

  return;

}
