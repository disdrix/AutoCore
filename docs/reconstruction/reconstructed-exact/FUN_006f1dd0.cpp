// =============================================================================
// FUN_006f1dd0
// -----------------------------------------------------------------------------
// Stable ID: aa_006f1dd0
// Address:   0x006f1dd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006f1dd0 @ 0x006f1dd0
// Stable ID: aa_006f1dd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_006f1dd0.
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

void FUN_006f1dd0(int param_1,int param_2,int param_3)



{

  uint uVar1;

  uint uVar2;

  

  *(uint32_t /* width from decompiler */ *)(param_3 + 0x34) = *(uint32_t /* width from decompiler */ *)(param_2 + 0x34);

  uVar1 = *(uint *)(param_3 + 0x38);

  uVar2 = (uVar1 - *(int *)(param_2 + 0x34)) + *(int *)(param_1 + 0x24);

  if (((0x1f < uVar2) && ((2 < uVar1 || (0xff < uVar2)))) &&

     (((uVar1 < 0x20 && (0x1f < *(uint *)(param_2 + 0x38))) ||

      (((uVar1 < 0x100 && (0xff < *(uint *)(param_2 + 0x38))) ||

       ((uVar1 < 0x10000 && (0xffff < *(uint *)(param_2 + 0x38))))))))) {

    *(int *)(param_3 + 0x34) = *(int *)(param_1 + 0x24);

  }

  return;

}
