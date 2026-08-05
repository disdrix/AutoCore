// =============================================================================
// FUN_0064ae60
// -----------------------------------------------------------------------------
// Stable ID: aa_0064ae60
// Address:   0x0064ae60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0064ae60 @ 0x0064ae60
// Stable ID: aa_0064ae60
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~17 non-empty decompiler lines.
//  - Control keywords: do×1, while×1, return×1.
//  - Notable callees: FUN_0064acc0, FUN_0064ae60, FUN_0065cfe0, FUN_0065d600.
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

void __thiscall FUN_0064ae60(int param_1,int *param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  

  uVar1 = FUN_0065d600(*(uint32_t /* width from decompiler */ *)(*(int *)(*param_2 + 0xc) + 0xc),param_2[1]);

  FUN_0064acc0(uVar1);

  FUN_0065cfe0();

  *(int *)(param_1 + 0x44) = param_2[2];

  *(int *)(param_1 + 0x48) = param_2[3];

  *(int *)(param_1 + 8) = *param_2;

  iVar2 = 0;

  do {

    *(uint8_t *)(param_1 + 0xc + iVar2) = *(uint8_t *)((int)param_2 + iVar2 + 0x10);

    iVar2 = iVar2 + 1;

  } while (iVar2 < 0x20);

  return;

}
