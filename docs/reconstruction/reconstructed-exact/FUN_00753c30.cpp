// =============================================================================
// FUN_00753c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00753c30
// Address:   0x00753c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00753c30 @ 0x00753c30
// Stable ID: aa_00753c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_0076c3c0×2, FUN_00753c30, FUN_007572a0.
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

uint32_t /* width from decompiler */ FUN_00753c30(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ uVar5;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = DAT_00d1f614;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b093d;

  local_c = ExceptionList;

  uVar2 = *(uint32_t /* width from decompiler */ *)(DAT_00d1f614 + 0xc4);

  ExceptionList = &local_c;

  if (*(char *)(DAT_00d1f614 + 200) == '\0') {

    ExceptionList = &local_c;

    iVar4 = FUN_0076c3c0();

    piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

    *(int *)(iVar3 + 0x30) = iVar4;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = 3;

  }

  local_4 = 0;

  uVar5 = FUN_007572a0(param_1);

  if (*(char *)(iVar3 + 200) == '\0') {

    iVar4 = FUN_0076c3c0();

    piVar1 = (int *)(iVar3 + 0x34 + *(int *)(iVar3 + 0xc4) * 4);

    *piVar1 = *piVar1 + (iVar4 - *(int *)(iVar3 + 0x30));

    *(int *)(iVar3 + 0x30) = iVar4;

    *(uint32_t /* width from decompiler */ *)(iVar3 + 0xc4) = uVar2;

  }

  ExceptionList = local_c;

  return uVar5;

}
