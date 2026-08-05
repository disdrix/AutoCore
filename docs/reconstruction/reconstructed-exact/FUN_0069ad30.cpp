// =============================================================================
// FUN_0069ad30
// -----------------------------------------------------------------------------
// Stable ID: aa_0069ad30
// Address:   0x0069ad30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0069ad30 @ 0x0069ad30
// Stable ID: aa_0069ad30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~22 non-empty decompiler lines.
//  - Control keywords: if×3, while×1, return×1.
//  - Notable callees: FUN_0069ab20, FUN_0069ad30.
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

void FUN_0069ad30(int param_1,int param_2,int param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5)



{

  int iVar1;

  int iVar2;

  

  iVar2 = param_2;

  while( true ) {

    iVar1 = iVar2 * 2 + 2;

    if (param_3 <= iVar1) break;

    if (*(float *)(*(int *)(param_1 + -4 + iVar1 * 4) + 0x2c) <

        *(float *)(*(int *)(param_1 + iVar1 * 4) + 0x2c)) {

      iVar1 = iVar2 * 2 + 1;

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + iVar1 * 4);

    iVar2 = iVar1;

  }

  if (iVar1 == param_3) {

    *(uint32_t /* width from decompiler */ *)(param_1 + iVar2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + -4 + param_3 * 4);

    iVar2 = param_3 + -1;

  }

  FUN_0069ab20(param_1,iVar2,param_2,param_4,param_5);

  return;

}
