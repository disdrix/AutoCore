// =============================================================================
// FUN_00429d60
// -----------------------------------------------------------------------------
// Stable ID: aa_00429d60
// Address:   0x00429d60  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00429d60 @ 0x00429d60
// Stable ID: aa_00429d60
// Embedded strings (evidence for future rename):
//   - "Stack trace is:\n"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00631dc0×8, CONCAT31, FUN_00429d60, FUN_00631da0, FUN_00631e10, FUN_00631ff0, FUN_00632030, FUN_00637f50.
//  - Strings: "Stack trace is:\n".
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

void __thiscall

FUN_00429d60(int *param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,

            uint32_t /* width from decompiler */ param_5,uint32_t /* width from decompiler */ param_6)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  undefined *puVar4;

  uint8_t *puVar5;

  undefined *puVar6;

  undefined *puVar7;

  uint8_t local_268 [8];

  uint8_t auStack_260 [8];

  uint8_t auStack_258 [76];

  uint8_t local_20c [508];

  void *pvStack_10;

  void *pvStack_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009bc2e6;

  pvStack_c = ExceptionList;

  ExceptionList = &pvStack_c;

  FUN_00637f50(local_268,&DAT_00a9ac98);

  FUN_00631ff0(local_20c,0x200);

  puVar7 = &DAT_00a9ac84;

  puVar6 = &DAT_00a9ac8c;

  puVar5 = local_268;

  puVar4 = &DAT_00a9ac90;

  uVar2 = 0x28;

  local_4 = 0;

  uVar3 = param_6;

  FUN_00631dc0(param_5);

  FUN_00631da0(uVar2);

  FUN_00631e10(uVar3);

  FUN_00631dc0(puVar4);

  FUN_00631dc0(puVar5);

  FUN_00631dc0(puVar6);

  FUN_00631dc0(param_2);

  FUN_00631dc0(puVar7);

  FUN_00631dc0(param_4);

  FUN_00631dc0();

  (**(code **)(*param_1 + 0x34))();

  if ((char)param_6 != '\0') {

    FUN_00643570();

    puStack_8 = (uint8_t *)CONCAT31(puStack_8._1_3_,1);

    iVar1 = FUN_00643480(auStack_260,0x14);

    if (2 < iVar1) {

      (**(code **)(*param_1 + 0x34))("Stack trace is:\n");

      FUN_00643320(auStack_258,iVar1 + -2,&LAB_00429ef0,param_1);

    }

    puStack_8 = (uint8_t *)((uint)puStack_8 & 0xffffff00);

    FUN_006432c0();

  }

  puStack_8 = (uint8_t *)0xffffffff;

  FUN_00632030();

  ExceptionList = pvStack_10;

  return;

}
