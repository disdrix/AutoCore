// =============================================================================
// FUN_00808a90
// -----------------------------------------------------------------------------
// Stable ID: aa_00808a90
// Address:   0x00808a90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00808a90 @ 0x00808a90
// Stable ID: aa_00808a90
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~16 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00808a90.
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

void __fastcall FUN_00808a90(uint32_t /* width from decompiler */ param_1,int param_2)



{

  int iVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int unaff_ESI;

  

  iVar1 = *(int *)(unaff_ESI + 0xe98);

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  if ((*(int *)(param_2 + 8) == *(int *)(iVar2 + 0x164 + iVar1)) &&

     (*(int *)(param_2 + 0xc) == *(int *)(iVar2 + 0x168 + iVar1))) {

    uVar3 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x10);

    *(uint *)(iVar1 + 0x634) = *(uint *)(iVar1 + 0x634) | 1;

    *(uint32_t /* width from decompiler */ *)(iVar1 + 0x6b4) = uVar3;

  }

  return;

}
