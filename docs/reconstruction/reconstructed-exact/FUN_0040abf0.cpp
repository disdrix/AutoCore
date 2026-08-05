// =============================================================================
// FUN_0040abf0
// -----------------------------------------------------------------------------
// Stable ID: aa_0040abf0
// Address:   0x0040abf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0040abf0 @ 0x0040abf0
// Stable ID: aa_0040abf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: CONCAT31, FUN_0040abf0.
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

uint32_t /* width from decompiler */ __thiscall FUN_0040abf0(int *param_1,ushort param_2)



{

  ushort uVar1;

  int iVar2;

  uint uVar3;

  

  if (*(int *)(param_1[0x2a] + 0x38) == 4) {

    uVar3 = 999999;

  }

  else {

    uVar1 = *(ushort *)(*(int *)(param_1[0x2a] + 0x3c) + 0x4ba);

    uVar3 = (uint)uVar1;

    if (uVar1 == 0) {

      uVar3 = 200;

    }

  }

  iVar2 = (**(code **)(*param_1 + 0x25c))();

  return CONCAT31((int3)(iVar2 + (uint)param_2 >> 8),

                  (int)(iVar2 + (uint)param_2) <= (int)(uVar3 & 0xffff));

}
