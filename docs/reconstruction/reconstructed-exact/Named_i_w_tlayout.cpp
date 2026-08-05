// =============================================================================
// Named_i_w_tlayout
// -----------------------------------------------------------------------------
// Stable ID: aa_00920310
// Address:   0x00920310  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_i_w_tlayout @ 0x00920310
// Stable ID: aa_00920310
// Embedded strings (evidence for future rename):
//   - "i_w_tlayout.xml"
//   - "i_w_pi.xml"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~147 non-empty decompiler lines.
//  - Control keywords: if×13, do×2, while×2, return×1.
//  - Notable callees: FUN_0087d250×3, FUN_00837a40, FUN_00856930, FUN_0090c560, FUN_00910640, Named_i_w_tlayout.
//  - Strings: "i_w_tlayout.xml"; "i_w_pi.xml".
//  - Return sites: 1.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "i_w_tlayout.xml"
 * Domain alias of FUN_00920310 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __fastcall Named_i_w_tlayout(int *param_1)



{

  int *piVar1;

  void *pvVar2;

  int iVar3;

  int iVar4;

  int *piVar5;

  void *pvVar6;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7e3b;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  *(uint8_t *)((int)param_1 + 0xa83) = DAT_00d1b211;

  param_1[0x309] = 0;

  param_1[0x30a] = 0;

  param_1[0x308] = 0;

  param_1[0x30c] = 0;

  *(uint32_t /* width from decompiler */ *)(param_1[0xa9] + 4) = *(uint32_t /* width from decompiler */ *)(DAT_00d1b644 + 0xe894);

  FUN_00910640();

  iVar3 = *(int *)(DAT_00d1b644 + 0xe890);

  *(uint32_t /* width from decompiler */ *)(iVar3 + 0x10c) = DAT_00aaac04;

  *(uint8_t *)(iVar3 + 0x48) = 1;

  *(uint8_t *)(iVar3 + 0xcc) = 1;

  pvVar2 = operator_new(0x4c4);

  local_4 = 0;

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00837a40(pvVar2);

  }

  local_4 = 0xffffffff;

  param_1[0x32c] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x32c] + 0x28))("i_w_tlayout.xml");

  (**(code **)(*(int *)param_1[0x32c] + 0xcc))(1);

  piVar5 = param_1 + 0x323;

  iVar3 = 4;

  do {

    pvVar2 = operator_new(0x538);

    if (pvVar2 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_0087d250(pvVar2);

    }

    *piVar5 = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    piVar1 = (int *)*piVar5;

    if (*(char *)((int)piVar1 + 0x529) != '\x01') {

      *(uint8_t *)((int)piVar1 + 0x529) = 1;

      (**(code **)(*piVar1 + 0x34c))();

    }

    piVar1 = (int *)*piVar5;

    if ((char)piVar1[0x14a] != '\x01') {

      *(uint8_t *)(piVar1 + 0x14a) = 1;

      (**(code **)(*piVar1 + 0x34c))();

    }

    iVar4 = *piVar5;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x534) = DAT_00aaac00;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x530) = 0;

    piVar1 = (int *)*piVar5;

    if (piVar1[0x14b] != 1) {

      piVar1[0x14b] = 1;

      (**(code **)(*piVar1 + 0x34c))();

    }

    (**(code **)(*(int *)*piVar5 + 0x43c))();

    (**(code **)(*(int *)*piVar5 + 0xcc))(0);

    piVar5 = piVar5 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  piVar5 = param_1 + 799;

  iVar3 = 4;

  do {

    pvVar2 = operator_new(0x538);

    if (pvVar2 == (void *)0x0) {

      iVar4 = 0;

    }

    else {

      iVar4 = FUN_0087d250(pvVar2);

    }

    *piVar5 = iVar4;

    (**(code **)(*param_1 + 0xa8))(iVar4);

    piVar1 = (int *)*piVar5;

    if ((char)piVar1[0x14a] != '\x01') {

      *(uint8_t *)(piVar1 + 0x14a) = 1;

      (**(code **)(*piVar1 + 0x34c))();

    }

    piVar1 = (int *)*piVar5;

    if (piVar1[0x14b] != 0) {

      piVar1[0x14b] = 0;

      (**(code **)(*piVar1 + 0x34c))();

    }

    (**(code **)(*(int *)*piVar5 + 0x43c))();

    (**(code **)(*(int *)*piVar5 + 0xcc))(0);

    piVar5 = piVar5 + 1;

    iVar3 = iVar3 + -1;

  } while (iVar3 != 0);

  pvVar2 = operator_new(0x538);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0087d250(pvVar2);

  }

  param_1[0x32b] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  piVar5 = (int *)param_1[0x32b];

  if ((char)piVar5[0x14a] != '\x01') {

    *(uint8_t *)(piVar5 + 0x14a) = 1;

    (**(code **)(*piVar5 + 0x34c))();

  }

  piVar5 = (int *)param_1[0x32b];

  if (piVar5[0x14b] != 2) {

    piVar5[0x14b] = 2;

    (**(code **)(*piVar5 + 0x34c))();

  }

  (**(code **)(*(int *)param_1[0x32b] + 0x43c))();

  pvVar6 = (void *)0x0;

  (**(code **)(*(int *)param_1[0x32b] + 0xcc))();

  pvVar2 = operator_new(0x544);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_0090c560(pvVar2);

  }

  param_1[0x32d] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x32d] + 0x43c))();

  pvVar2 = operator_new(0x49c);

  if (pvVar2 == (void *)0x0) {

    iVar3 = 0;

  }

  else {

    iVar3 = FUN_00856930(pvVar2);

  }

  param_1[0x32e] = iVar3;

  (**(code **)(*param_1 + 0xa8))(iVar3);

  (**(code **)(*(int *)param_1[0x32e] + 0x28))("i_w_pi.xml");

  (**(code **)(*(int *)param_1[0x32e] + 4))(0);

  ExceptionList = pvVar6;

  return;

}
