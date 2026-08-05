// =============================================================================
// FUN_008b6150
// -----------------------------------------------------------------------------
// Stable ID: aa_008b6150
// Address:   0x008b6150  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008b6150 @ 0x008b6150
// Stable ID: aa_008b6150
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_007a4ee0, FUN_008b5ea0, FUN_008b6150.
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

void __thiscall FUN_008b6150(int *param_1,uint param_2,uint param_3)



{

  char cVar1;

  int iVar2;

  

  cVar1 = (**(code **)(*param_1 + 0x3d8))();

  if (cVar1 != '\0') {

    if ((((param_1[0x146] & param_1[0x147]) != 0xffffffff) &&

        (iVar2 = FUN_007a4ee0(param_1[0x146],param_1[0x147]), iVar2 != 0)) &&

       (((param_2 & param_3) == 0xffffffff ||

        ((*(uint *)(iVar2 + 0x1f0) == param_2 && (*(uint *)(iVar2 + 500) == param_3)))))) {

      FUN_008b5ea0();

    }

  }

  return;

}
