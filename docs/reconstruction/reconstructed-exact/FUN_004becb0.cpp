// =============================================================================
// FUN_004becb0
// -----------------------------------------------------------------------------
// Stable ID: aa_004becb0
// Address:   0x004becb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004becb0 @ 0x004becb0
// Stable ID: aa_004becb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~90 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0074ba00×3, FUN_00764030×3, FUN_00410420×2, FUN_004becb0×2, CONCAT31, FUN_00972cc0.
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

int * __thiscall FUN_004becb0(int *param_1,int param_2,char param_3)



{

  int iVar1;

  void *pvVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009a18ea;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  param_1[4] = (int)&PTR_LAB_009cb5cc;

  param_1[5] = 0;

  param_1[6] = 0;

  param_1[7] = 0;

  param_1[8] = (int)&PTR_LAB_009cb5cc;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xb] = 0;

  local_4 = 1;

  uStack_3 = 0;

  FUN_00764030();

  local_4 = 2;

  FUN_00764030();

  local_4 = 3;

  FUN_00764030();

  local_4 = 4;

  FUN_0074ba00();

  local_4 = 5;

  FUN_0074ba00();

  local_4 = 6;

  FUN_0074ba00();

  local_4 = 7;

  FUN_00972cc0();

  param_1[0x15f] = 0;

  param_1[0x160] = 0;

  param_1[0x161] = 0;

  param_1[0x163] = 0;

  param_1[0x164] = 0;

  param_1[0x165] = 0;

  local_4 = 9;

  if (param_3 == '\0') {

    param_1[3] = param_2;

    *(uint8_t *)(param_1 + 0x15c) = 0;

    *(uint8_t *)(param_1 + 0x15d) = 0;

    *(uint8_t *)((int)param_1 + 0x571) = 1;

    *(uint8_t *)(param_1 + 0x169) = 0;

    FUN_00410420(0,0);

    FUN_00410420(0,0);

    *(uint8_t *)((int)param_1 + 0x5c5) = 0;

    *param_1 = 0;

    param_1[1] = 0;

    param_1[0x172] = 0;

    param_1[0x173] = 0;

    if (*(int *)(param_2 + 0x14) == 0) {

      iVar1 = 0;

    }

    else {

      iVar1 = *(int *)(param_2 + 0x18) - *(int *)(param_2 + 0x14) >> 2;

    }

    *(bool *)((int)param_1 + 0x572) = iVar1 != 0;

    *(uint8_t *)((int)param_1 + 0x573) = 1;

    param_1[2] = DAT_00b03738;

    *(uint8_t *)(param_1 + 0x171) = 0;

    *(uint8_t *)(param_1 + 0x174) = 0;

    param_1[0x16d] = 0;

    param_1[0x16e] = 0;

    param_1[0x16f] = 0;

    if (DAT_00b0373c == 0) {

      pvVar2 = operator_new(0x5e0);

      _local_4 = CONCAT31(uStack_3,10);

      if (pvVar2 == (void *)0x0) {

        DAT_00b03730 = (int *)0x0;

      }

      else {

        DAT_00b03730 = (int *)FUN_004becb0(0,1);

      }

      *DAT_00b03730 = (int)DAT_00b03730;

      DAT_00b03730[1] = (int)DAT_00b03730;

    }

    DAT_00b0373c = DAT_00b0373c + 1;

    DAT_00b03734 = DAT_00b03734 + 1;

    *param_1 = *DAT_00b03730;

    param_1[1] = (int)DAT_00b03730;

    *(int **)(*DAT_00b03730 + 4) = param_1;

    *DAT_00b03730 = (int)param_1;

  }

  ExceptionList = local_c;

  return param_1;

}
