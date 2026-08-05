// =============================================================================
// FUN_0092fdd0
// -----------------------------------------------------------------------------
// Stable ID: aa_0092fdd0
// Address:   0x0092fdd0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0092fdd0 @ 0x0092fdd0
// Stable ID: aa_0092fdd0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~24 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_007fca10×5, FUN_0092fdd0.
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

void FUN_0092fdd0(void)



{

  int iVar1;

  int iVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ local_10 [2];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  *(uint8_t *)(*(int *)(in_EAX + 0xe98) + 0x4fc) = 0;

  iVar1 = *(int *)(in_EAX + 0xe98);

  local_10[0] = 0x9003;

  iVar2 = *(int *)(*(int *)(iVar1 + 4) + 4);

  local_8 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + iVar1);

  local_4 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + iVar1);

  if (*(int *)(in_EAX + 0xc78) != 0) {

    (**(code **)(**(int **)(in_EAX + 0xc78) + 0x18))(0xffffffff,local_10,0x10,0);

  }

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  FUN_007fca10();

  return;

}
