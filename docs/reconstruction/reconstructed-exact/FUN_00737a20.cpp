// =============================================================================
// FUN_00737a20
// -----------------------------------------------------------------------------
// Stable ID: aa_00737a20
// Address:   0x00737a20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00737a20 @ 0x00737a20
// Stable ID: aa_00737a20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~83 non-empty decompiler lines.
//  - Control keywords: if×10, for×1, goto×1, return×1.
//  - Notable callees: FUN_00414b60, FUN_0043f4b0, FUN_00447ea0, FUN_0044b930, FUN_00734550, FUN_00737720, FUN_00737a20, FUN_00752df0.
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

uint8_t FUN_00737a20(int param_1,int param_2)



{

  int *piVar1;

  uint8_t uVar2;

  int iVar3;

  int iVar4;

  int local_2c;

  int local_28;

  uint8_t local_24 [4];

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint32_t /* width from decompiler */ local_18;

  int local_14;

  uint32_t /* width from decompiler */ local_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  puStack_8 = &LAB_009b07e2;

  pvStack_c = ExceptionList;

  local_20 = 0;

  local_1c = 0;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_4 = 0;

  iVar3 = *(int *)(param_1 + 0x14);

  ExceptionList = &pvStack_c;

  FUN_00447ea0();

  local_14 = *(int *)(iVar3 + 0x34);

  local_10 = *(uint32_t /* width from decompiler */ *)(iVar3 + 0x38);

  iVar3 = *(int *)(*(int *)(param_1 + 200) + 0xc);

  if (*(int *)(param_1 + 0xb4) + -2 + *(int *)(*(int *)(param_1 + 200) + 0x14) * 2 < 0x11) {

    if (*(int *)(param_1 + 0xd4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4) >> 3;

    }

  }

  else {

    if (*(int *)(param_1 + 0xd4) == 0) {

      iVar4 = 0;

    }

    else {

      iVar4 = *(int *)(param_1 + 0xd8) - *(int *)(param_1 + 0xd4) >> 3;

    }

    for (; 0 < iVar4; iVar4 = iVar4 + -1) {

      if (*(float *)(iVar3 + iVar4 * 4) != 0.0) goto LAB_00737b0a;

    }

    iVar4 = 0;

  }

LAB_00737b0a:

  uVar2 = FUN_00737720(param_1,iVar4,iVar3,local_24,&local_2c);

  if (local_14 == 0) {

    FUN_00967150(local_24);

  }

  FUN_00734550();

  if (*(int *)(param_1 + 0x14) != 0) {

    FUN_0043f4b0();

  }

  if (*(int *)(param_1 + 0xc) != 0) {

    FUN_0044b930(0);

  }

  local_28 = local_2c + -1;

  if (*(int *)(DAT_00d1f05c + 4) != 0) {

    piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

    (**(code **)(*piVar1 + 0x50))(piVar1,*(uint32_t /* width from decompiler */ *)(DAT_00d1f05c + 0x24),&local_28,0xffffffff);

  }

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

  FUN_00752df0(*(uint32_t /* width from decompiler */ *)(param_2 + 4),iVar4,1,iVar3,local_28,&DAT_00d0e168);

  FUN_00414b60();

  ExceptionList = pvStack_c;

  return uVar2;

}
