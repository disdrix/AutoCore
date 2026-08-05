// =============================================================================
// FUN_006a13e0
// -----------------------------------------------------------------------------
// Stable ID: aa_006a13e0
// Address:   0x006a13e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006a13e0 @ 0x006a13e0
// Stable ID: aa_006a13e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~67 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_0056f570×6, FUN_006a1220×5, FUN_00696d50×2, FUN_00697010×2, FUN_004490a0, FUN_00696db0, FUN_00696ee0, FUN_00697180.
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

void __thiscall FUN_006a13e0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint32_t /* width from decompiler */ param_4)



{

  uint32_t /* width from decompiler */ *puVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t local_6c [24];

  uint8_t local_54 [24];

  uint8_t local_3c [24];

  uint8_t local_24 [24];

  void *local_c;

  uint8_t *puStack_8;

  int local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ab1d0;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00696d50(*param_2,param_2[1]);

  local_4 = 0;

  FUN_00696d50(*param_3,param_3[1]);

  local_4._0_1_ = 1;

  FUN_00697180();

  if ((*(int *)(param_1 + 0x10) != 0) &&

     ((*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x18 != 0)) {

    iVar2 = 0;

    if (*(int *)(param_1 + 0x10) != 0) {

      iVar2 = (*(int *)(param_1 + 0x14) - *(int *)(param_1 + 0x10)) / 0x18;

    }

    uVar3 = FUN_00697010(local_24,*(uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 0x30) + -4 + iVar2 * 4));

    local_4._0_1_ = 2;

    uVar3 = FUN_00696db0(local_3c,uVar3);

    local_4._0_1_ = 3;

    FUN_006a1220(uVar3);

    local_4._0_1_ = 2;

    FUN_0056f570();

    local_4._0_1_ = 1;

    FUN_0056f570();

    uVar3 = FUN_00697010(local_3c,param_4);

    local_4._0_1_ = 4;

    uVar3 = FUN_00696ee0(local_24,uVar3);

    local_4._0_1_ = 5;

    FUN_006a1220(uVar3);

    local_4._0_1_ = 4;

    FUN_0056f570();

    local_4._0_1_ = 1;

    FUN_0056f570();

  }

  FUN_006a1220(local_54);

  FUN_006a1220(local_54);

  FUN_006a1220(local_6c);

  iVar2 = *(int *)(param_1 + 0x30);

  if ((iVar2 == 0) ||

     ((uint)(*(int *)(param_1 + 0x38) - iVar2 >> 2) <= (uint)(*(int *)(param_1 + 0x34) - iVar2 >> 2)

     )) {

    FUN_004490a0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x34),1,&param_4);

  }

  else {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x34);

    *puVar1 = param_4;

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x34) = puVar1 + 1;

  }

  local_4 = (uint)local_4._1_3_ << 8;

  FUN_0056f570();

  local_4 = 0xffffffff;

  FUN_0056f570();

  ExceptionList = local_c;

  return;

}
