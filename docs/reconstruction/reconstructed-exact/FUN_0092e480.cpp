// =============================================================================
// FUN_0092e480
// -----------------------------------------------------------------------------
// Stable ID: aa_0092e480
// Address:   0x0092e480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092e480 @ 0x0092e480
// Stable ID: aa_0092e480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~30 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0092e480.
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

void FUN_0092e480(void)



{

  int iVar1;

  int iVar2;

  int unaff_ESI;

  uint32_t /* width from decompiler */ local_20 [2];

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar1 = *(int *)(unaff_ESI + 0xe98);

  local_20[0] = 0x20a5;

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_10 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  local_14 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30dc);

  local_18 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30d8);

  local_8 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30e0);

  local_4 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30e4);

  if (*(int **)(unaff_ESI + 0xc78) != (int *)0x0) {

    (**(code **)(**(int **)(unaff_ESI + 0xc78) + 0x18))(0xffffffff,local_20,0x20,0);

  }

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30d8) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30dc) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30e0) = 0xffffffff;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x30e4) = 0xffffffff;

  return;

}
