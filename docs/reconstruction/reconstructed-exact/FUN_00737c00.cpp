// =============================================================================
// FUN_00737c00
// -----------------------------------------------------------------------------
// Stable ID: aa_00737c00
// Address:   0x00737c00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00737c00 @ 0x00737c00
// Stable ID: aa_00737c00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~35 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_0043f4b0, FUN_0044b930, FUN_00734550, FUN_00737c00, FUN_00752df0, FUN_00967150, FUN_00972b20, FUN_00972e50.
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

void FUN_00737c00(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0044b930(0);

  }

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(*(int *)(param_1 + 0x14) + 0x34) == 0) {

    FUN_00967150(*(int *)(param_1 + 0x14) + 0x24);

  }

  FUN_00734550();

  if (*(int *)(DAT_00d1f05c + 4) != 0) {

    piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))

              (piVar1,*(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x24),param_1 + 0xb0,0xffffffff);

  }

  uVar2 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 200) + 0xc);

  if ((*(uint *)(*(int *)(param_1 + 100) + 0xbc) >> 2 & 1) == 0) {

    iVar3 = *(int *)(param_1 + 100) + 0xa8;

  }

  else {

    iVar3 = FUN_00972b20();

  }

  iVar4 = *(int *)(param_1 + 100);

  if ((*(byte *)(iVar4 + 0xbc) & 1) != 0) {

    iVar4 = FUN_00972e50();

  }

  FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),iVar4,1,iVar3,*(uint32_t /* width from decompiler */ *)(param_1 + 0xb0),uVar2);

  return;

}
