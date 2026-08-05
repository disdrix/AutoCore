// =============================================================================
// FUN_0096fe40
// -----------------------------------------------------------------------------
// Stable ID: aa_0096fe40
// Address:   0x0096fe40  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0096fe40 @ 0x0096fe40
// Stable ID: aa_0096fe40
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~25 non-empty decompiler lines.
//  - Control keywords: if×5, return×3.
//  - Notable callees: FUN_00448fc0, FUN_00752800, FUN_0096fdf0, FUN_0096fe40.
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

uint32_t /* width from decompiler */ __thiscall FUN_0096fe40(int *param_1,int param_2,uint32_t /* width from decompiler */ param_3,int param_4)



{

  int iVar1;

  char cVar2;

  int iVar3;

  

  if (param_4 == 0) {

    return 0;

  }

  cVar2 = FUN_0096fdf0();

  iVar1 = *param_1;

  if (-1 < param_2) {

    FUN_00752800(param_2);

    return 0;

  }

  if ((cVar2 != '\0') && (iVar1 != 0)) {

    iVar3 = *(int *)(iVar1 + 0x18);

    if (*(int *)(iVar1 + 0x18) == 0) {

      iVar3 = iVar1;

    }

    if (iVar3 != iVar1) {

      FUN_00448fc0(iVar3);

    }

  }

  return 0xffffffff;

}
