// =============================================================================
// FUN_0072b380
// -----------------------------------------------------------------------------
// Stable ID: aa_0072b380
// Address:   0x0072b380  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0072b380 @ 0x0072b380
// Stable ID: aa_0072b380
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×8, return×1.
//  - Notable callees: FUN_0072b380×5, CONCAT31.
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

uint32_t /* width from decompiler */ * __thiscall FUN_0072b380(uint32_t /* width from decompiler */ *param_1,uint32_t /* width from decompiler */ *param_2)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ uVar2;

  void *local_c;

  uint8_t *puStack_8;

  uint8_t local_4;

  undefined3 uStack_3;

  

  puStack_8 = &LAB_009abea0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  *param_1 = *param_2;

  param_1[1] = param_2[1];

  param_1[2] = param_2[2];

  param_1[3] = param_2[3];

  param_1[4] = param_2[4];

  param_1[5] = param_2[5];

  param_1[6] = param_2[6];

  param_1[7] = 0;

  param_1[8] = 0;

  param_1[9] = 0;

  param_1[10] = 0;

  param_1[0xc] = 0;

  param_1[0xd] = 0;

  param_1[0xe] = 0;

  local_4 = 0;

  uStack_3 = 0;

  if (param_2[7] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 1;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(param_2[7]);

    }

    param_1[7] = uVar2;

  }

  local_4 = 0;

  if (param_2[8] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 2;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(param_2[8]);

    }

    param_1[8] = uVar2;

  }

  local_4 = 0;

  if (param_2[9] != 0) {

    pvVar1 = operator_new(0x3c);

    local_4 = 3;

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(param_2[9]);

    }

    param_1[9] = uVar2;

  }

  local_4 = 0;

  if (param_2[10] != 0) {

    pvVar1 = operator_new(0x3c);

    _local_4 = CONCAT31(uStack_3,4);

    if (pvVar1 == (void *)0x0) {

      uVar2 = 0;

    }

    else {

      uVar2 = FUN_0072b380(param_2[10]);

    }

    param_1[10] = uVar2;

  }

  ExceptionList = local_c;

  return param_1;

}
