// =============================================================================
// FUN_0094fa60
// -----------------------------------------------------------------------------
// Stable ID: aa_0094fa60
// Address:   0x0094fa60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0094fa60 @ 0x0094fa60
// Stable ID: aa_0094fa60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~19 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_008073b0, FUN_0094fa60.
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

uint32_t /* width from decompiler */ __fastcall FUN_0094fa60(int param_1)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ local_18 [2];

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  

  if (*(int *)(param_1 + 0xe98) != 0) {

    iVar1 = *(int *)(param_1 + 0xe98);

    local_18[0] = 0x901f;

    iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

    local_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

    local_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

    local_8 = 0xffffffff;

    FUN_008073b0(0x18,local_18);

  }

  return 1;

}
