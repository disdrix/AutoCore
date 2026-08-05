// =============================================================================
// FUN_00967ec0
// -----------------------------------------------------------------------------
// Stable ID: aa_00967ec0
// Address:   0x00967ec0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00967ec0 @ 0x00967ec0
// Stable ID: aa_00967ec0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~82 non-empty decompiler lines.
//  - Control keywords: if×6, return×4, for×2.
//  - Notable callees: FUN_0074e2d0×2, FUN_0043fb50, FUN_00456960, FUN_00967b10, FUN_00967cc0, FUN_00967ec0, _eh_vector_constructor_iterator_.
//  - Return sites: 4.

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

void FUN_00967ec0(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  int iVar5;

  int *piVar6;

  uint uVar7;

  int *local_18;

  uint8_t local_14 [8];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar5 = DAT_00d1a54c;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009afa36;

  local_c = ExceptionList;

  uVar7 = 0;

  if (DAT_00d1a54c == 0) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 8) = 0;

    return;

  }

  puVar1 = (uint32_t /* width from decompiler */ *)(param_1 + 8);

  if ((*(int **)(param_1 + 8) != (int *)0x0) && (**(int **)(param_1 + 8) == DAT_00d1a54c)) {

    ExceptionList = &local_c;

    FUN_0074e2d0();

    ExceptionList = local_c;

    return;

  }

  for (; (*(int *)(param_1 + 0x10) != 0 &&

         (uVar7 < (uint)(*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10) >> 2)));

      uVar7 = uVar7 + 1) {

    if (**(int **)(*(int *)(param_1 + 0x10) + uVar7 * 4) == DAT_00d1a54c) {

      ExceptionList = &local_c;

      *puVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x10) + uVar7 * 4);

      FUN_0074e2d0();

      ExceptionList = local_c;

      return;

    }

  }

  ExceptionList = &local_c;

  piVar6 = operator_new(0x54);

  local_4 = 0;

  local_18 = piVar6;

  if (piVar6 == (int *)0x0) {

    piVar6 = (int *)0x0;

  }

  else {

    *piVar6 = 0;

    _eh_vector_constructor_iterator_(piVar6 + 1,0x10,4,FUN_004565f0,FUN_00691630);

    piVar6[0x11] = 0;

    piVar6[0x12] = 0;

    piVar6[0x13] = 0;

    piVar6[0x14] = 0;

  }

  local_4 = 0xffffffff;

  *puVar1 = piVar6;

  *piVar6 = iVar5;

  iVar2 = *(int *)(param_1 + 0x10);

  if ((iVar2 == 0) ||

     ((uint)(*(int *)(param_1 + 0x18) - iVar2 >> 2) <= (uint)(*(int *)(param_1 + 0x14) - iVar2 >> 2)

     )) {

    FUN_00456960(*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

  }

  else {

    puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x14);

    *puVar3 = *puVar1;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x14) = puVar3 + 1;

  }

  local_18 = (int *)*puVar1;

  FUN_0043fb50(local_14,&local_18);

  FUN_00967cc0(param_1);

  piVar4 = *(int **)(iVar5 + 0xc);

  for (piVar6 = *(int **)(iVar5 + 8); piVar6 != piVar4; piVar6 = piVar6 + 1) {

    if (*(char *)(*piVar6 + 0xd0) != '\0') {

      FUN_00967b10(param_1,*piVar6);

    }

  }

  ExceptionList = local_c;

  return;

}
