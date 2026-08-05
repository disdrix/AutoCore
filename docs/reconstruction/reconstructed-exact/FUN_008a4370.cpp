// =============================================================================
// FUN_008a4370
// -----------------------------------------------------------------------------
// Stable ID: aa_008a4370
// Address:   0x008a4370  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008a4370 @ 0x008a4370
// Stable ID: aa_008a4370
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007916e0, FUN_008a2040, FUN_008a2df0, FUN_008a3510, FUN_008a4370.
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

void __thiscall FUN_008a4370(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ uVar2;

  

  FUN_007916e0(param_2);

  if ((char)param_2 != '\0') {

    cVar1 = (**(code **)(*param_1 + 0x3d8))();

    if (cVar1 != '\0') {

      FUN_008a2df0();

      uVar2 = FUN_008a2040();

      FUN_008a3510(uVar2);

    }

  }

  return;

}
