// =============================================================================
// FUN_0067c260
// -----------------------------------------------------------------------------
// Stable ID: aa_0067c260
// Address:   0x0067c260  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0067c260 @ 0x0067c260
// Stable ID: aa_0067c260
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0067c260.
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

void __thiscall FUN_0067c260(int param_1,int *param_2)



{

  uint uVar1;

  int iVar2;

  

  iVar2 = *param_2 + *(int *)(param_1 + 0x29e8);

  uVar1 = *(int *)(param_1 + 0x29e0) * iVar2;

  *(int *)(param_1 + 0x29cc) = *(int *)(param_1 + 0x29cc) + uVar1 / 1000;

  *(uint *)(param_1 + 0x29e8) = uVar1 % 1000;

  if ((0 < (int)*(uint *)(param_1 + 0x29cc)) &&

     (*(uint *)(param_1 + 0x29d8) < *(uint *)(param_1 + 0x29cc))) {

    *(uint *)(param_1 + 0x29cc) = *(uint *)(param_1 + 0x29d8);

  }

  *(int *)(param_1 + 0x29d0) =

       *(int *)(param_1 + 0x29d0) + (uint)(*(int *)(param_1 + 0x29e4) * iVar2) / 1000;

  if (*(uint *)(param_1 + 0x29dc) < *(uint *)(param_1 + 0x29d0)) {

    *(uint *)(param_1 + 0x29d0) = *(uint *)(param_1 + 0x29dc);

  }

  return;

}
