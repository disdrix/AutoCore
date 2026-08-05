// =============================================================================
// FUN_00468fd0
// -----------------------------------------------------------------------------
// Stable ID: aa_00468fd0
// Address:   0x00468fd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00468fd0 @ 0x00468fd0
// Stable ID: aa_00468fd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~20 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_004690c0×5, FUN_00468fd0.
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

void FUN_00468fd0(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  int iVar1;

  int iVar2;

  int iVar3;

  

  iVar1 = param_3 - param_1 >> 2;

  if (0x28 < iVar1) {

    iVar1 = iVar1 + 1;

    iVar2 = (int)(iVar1 + (iVar1 >> 0x1f & 7U)) >> 3;

    iVar1 = iVar2 * 4 + param_1;

    FUN_004690c0(param_1,iVar1,iVar2 * 8 + param_1,param_4);

    FUN_004690c0(param_2 + iVar2 * -4,param_2,iVar2 * 4 + param_2,param_4);

    iVar3 = param_3 + iVar2 * -4;

    FUN_004690c0(param_3 + iVar2 * -8,iVar3,param_3,param_4);

    FUN_004690c0(iVar1,param_2,iVar3,param_4);

    return;

  }

  FUN_004690c0(param_1,param_2,param_3,param_4);

  return;

}
