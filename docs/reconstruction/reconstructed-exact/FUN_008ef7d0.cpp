// =============================================================================
// FUN_008ef7d0
// -----------------------------------------------------------------------------
// Stable ID: aa_008ef7d0
// Address:   0x008ef7d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008ef7d0 @ 0x008ef7d0
// Stable ID: aa_008ef7d0
// Embedded strings (evidence for future rename):
//   - "sec_"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×10, return×5, goto×3.
//  - Notable callees: FUN_0040e230, FUN_0079c860, FUN_007a70f0, FUN_008ec080, FUN_008ef7d0, _wcsnicmp.
//  - Strings: "sec_".
//  - Return sites: 5.

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

void __thiscall FUN_008ef7d0(int *param_1,int *param_2)



{

  int iVar1;

  void *pvVar2;

  uint uVar3;

  int *piVar4;

  uint8_t auStack_1c [16];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b7522;

  local_c = ExceptionList;

  piVar4 = (int *)0x0;

  if (param_1 == (int *)0x0) {

    return;

  }

  if ((float)param_1[0x2b] == 0.0) {

    return;

  }

  if ((float)param_1[0x2c] == 0.0) {

    return;

  }

  ExceptionList = &local_c;

  iVar1 = _wcsnicmp((wchar_t *)(param_1 + 7),L"sec_",4);

  if (iVar1 != 0) {

    ExceptionList = local_c;

    return;

  }

  pvVar2 = operator_new(0x4cc);

  local_4 = 0;

  if (pvVar2 != (void *)0x0) {

    piVar4 = (int *)FUN_0079c860();

  }

  local_4 = 0xffffffff;

  (**(code **)(*param_2 + 0xa8))();

  uVar3 = param_1[3];

  if ((param_1[6] != 0) && (DAT_00d1b6d8 != 0)) {

    uVar3 = (uint)*(byte *)(*(int *)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xac +

                                             DAT_00d1b6d8) + 0x3c) + 0x532);

  }

  param_2._0_1_ = (char)pvVar2;

  if ((char)param_2 == '\0') {

    (**(code **)(*piVar4 + 0x28))();

    goto LAB_008ef906;

  }

  if ((char)param_2 != '\x01') {

    if (uVar3 == 2) {

      (**(code **)(*piVar4 + 0x28))();

      goto LAB_008ef906;

    }

    if ((uVar3 != 1) && (uVar3 == 0)) {

      (**(code **)(*piVar4 + 0x28))();

      goto LAB_008ef906;

    }

  }

  (**(code **)(*piVar4 + 0x28))();

LAB_008ef906:

  piVar4[0x8d] = param_1[0x2b];

  piVar4[0x8f] = param_1[0x2c];

  FUN_008ec080(auStack_1c,param_1[0x2b],param_1[0x2c]);

  (**(code **)(*piVar4 + 0x140))(auStack_1c,1);

  (**(code **)(*piVar4 + 0x140))(&stack0xffffffdc,1);

  (**(code **)(*piVar4 + 0x118))(&stack0xffffffcc);

  (**(code **)(*piVar4 + 0x74))(*param_1 + 0x9c45);

  (**(code **)(*piVar4 + 0x308))(0);

  FUN_007a70f0();

  (**(code **)(*piVar4 + 0xfc))(1,0x3f000000);

  FUN_0040e230();

  ExceptionList = local_c;

  return;

}
