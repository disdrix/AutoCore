// =============================================================================
// FUN_00844bb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00844bb0
// Address:   0x00844bb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00844bb0 @ 0x00844bb0
// Stable ID: aa_00844bb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~14 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00844bb0.
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

void __thiscall FUN_00844bb0(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  char cVar2;

  

  cVar2 = (**(code **)(*param_1 + 0xd0))();

  if (cVar2 != (char)param_2) {

    if ((param_1[0x14d] != 0) && (iVar1 = *(int *)(param_1[0x14d] + 0x2a4), iVar1 != 0)) {

      *(char *)(iVar1 + 400) = (char)param_2;

    }

    (**(code **)(*param_1 + 0xcc))(param_2);

    (**(code **)(*param_1 + 0x34c))();

  }

  return;

}
