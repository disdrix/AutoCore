// =============================================================================
// FUN_005238e0
// -----------------------------------------------------------------------------
// Stable ID: aa_005238e0
// Address:   0x005238e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005238e0 @ 0x005238e0
// Stable ID: aa_005238e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: if×8, for×1, return×1.
//  - Notable callees: FUN_007878f0×9, FUN_005238e0, FUN_00787af0, FUN_00787cf0, FUN_00787db0.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __thiscall FUN_005238e0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  uint32_t /* width from decompiler */ local_23a8 [103];

  int iStack_220c;

  int iStack_2208;

  short sStack_2204;

  short sStack_2202;

  byte bStack_2200;

  void *pvStack_1078;

  void *pvStack_1074;

  void *pvStack_1070;

  void *pvStack_106c;

  void *pvStack_1068;

  void *pvStack_1064;

  void *pvStack_1060;

  void *pvStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  int iStack_18;

  void *pvStack_14;

  uint8_t *puStack_10;

  uint32_t /* width from decompiler */ uStack_c;

  

  uStack_c = 0xffffffff;

  puStack_10 = &LAB_009a3839;

  pvStack_14 = ExceptionList;

  uStack_1c = 0x523906;

  puVar3 = local_23a8;

  for (iVar2 = 0x4d6; iVar2 != 0; iVar2 = iVar2 + -1) {

    *puVar3 = 0;

    puVar3 = puVar3 + 1;

  }

  ExceptionList = &pvStack_14;

  iStack_18 = param_1;

  uVar1 = (**(code **)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 4 + param_1) + 0xbc))

                    (local_23a8,2,param_4);

  *param_3 = uVar1;

  FUN_00787cf0();

  iStack_18 = 0;

  if ((char)param_4 == '\0') {

    FUN_007878f0(&stack0xffffdc4c,*param_3);

  }

  else {

    FUN_007878f0(&stack0xffffdc4c,0x1358);

    FUN_007878f0(pvStack_1078,(uint)bStack_2200 * 8);

    FUN_007878f0(pvStack_1074,iStack_220c * 4);

    FUN_007878f0(pvStack_1070,sStack_2204 * 4);

    FUN_007878f0(pvStack_106c,sStack_2202 * 4);

    FUN_007878f0(pvStack_1068,sStack_2202 * 4);

    FUN_007878f0(pvStack_1064,sStack_2202 * 4);

    FUN_007878f0(pvStack_1060,iStack_2208 * 0x48);

    if (pvStack_1060 != (void *)0x0) {

      operator_delete__(pvStack_1060);

    }

    pvStack_1060 = (void *)0x0;

    if (pvStack_1074 != (void *)0x0) {

      operator_delete__(pvStack_1074);

    }

    pvStack_1074 = (void *)0x0;

    if (pvStack_1078 != (void *)0x0) {

      operator_delete__(pvStack_1078);

    }

    pvStack_1078 = (void *)0x0;

    if (pvStack_1070 != (void *)0x0) {

      operator_delete__(pvStack_1070);

    }

    pvStack_1070 = (void *)0x0;

    if (pvStack_106c != (void *)0x0) {

      operator_delete__(pvStack_106c);

    }

    pvStack_106c = (void *)0x0;

    if (pvStack_1068 != (void *)0x0) {

      operator_delete__(pvStack_1068);

    }

    pvStack_1068 = (void *)0x0;

    if (pvStack_1064 != (void *)0x0) {

      operator_delete__(pvStack_1064);

    }

    pvStack_1064 = (void *)0x0;

  }

  FUN_00787db0(param_2,param_3,1);

  iStack_18 = 0xffffffff;

  FUN_00787af0();

  ExceptionList = pvStack_20;

  return;

}
