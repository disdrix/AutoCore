// =============================================================================
// FUN_0089bc30
// -----------------------------------------------------------------------------
// Stable ID: aa_0089bc30
// Address:   0x0089bc30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0089bc30 @ 0x0089bc30
// Stable ID: aa_0089bc30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×5, while×2, return×2, do×1.
//  - Notable callees: FUN_00411900×2, FUN_00572060×2, FUN_0089a260×2, CONCAT31, FUN_004023f0, FUN_00402c40, FUN_00403430, FUN_004f1e20.
//  - Return sites: 2.

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

void FUN_0089bc30(int param_1)



{

  int *piVar1;

  uint8_t uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  int *piVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ local_20;

  uint32_t /* width from decompiler */ local_1c;

  uint8_t local_18 [4];

  int *local_14;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  iVar3 = param_1;

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009ad24b;

  local_c = ExceptionList;

  if ((((DAT_00d1b570 != 0) && (DAT_00d1b6d8 != 0)) && (*(int *)(param_1 + 0x56c) != 0)) &&

     (*(int *)(param_1 + 0x568) != 0)) {

    local_20 = 0;

    if (*(char *)(param_1 + 0x538) != '\0') {

      ExceptionList = &local_c;

      FUN_004023f0();

      local_4 = 0;

      FUN_00572060(0x1a,local_18);

      FUN_00572060(0x1a,local_18);

      piVar6 = (int *)*local_14;

      if (piVar6 != local_14) {

        do {

          piVar1 = (int *)piVar6[2];

          if ((piVar1 != (int *)0x0) &&

             (iVar3 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(piVar1[0x2a] + 0x3c),0,

                                      &nsCloneStructs::SCloneBaseObject::RTTI_Type_Descriptor,

                                      &nsCloneStructs::SCloneBaseCommodity::RTTI_Type_Descriptor,0),

             *(int *)(iVar3 + 0x4d0) != -1)) {

            iVar3 = piVar1[0x2a];

            uVar7 = 1;

            uVar4 = (**(code **)(*piVar1 + 0x25c))(1);

            FUN_0089a260(param_1,iVar3,uVar4,uVar7);

          }

          piVar6 = (int *)*piVar6;

        } while (piVar6 != local_14);

      }

      local_4 = 0xffffffff;

      FUN_00403430();

      ExceptionList = local_c;

      return;

    }

    ExceptionList = &local_c;

    FUN_00402c40();

    iVar5 = FUN_00411900(&local_20);

    while (iVar5 != 0) {

      if (((*(int *)(iVar5 + 0x3c) != 0) || (FUN_004f1e20(0,1), *(int *)(iVar5 + 0x3c) != 0)) &&

         (*(int *)(iVar5 + 0x38) == 0x1a)) {

        param_1 = 0;

        uVar2 = FUN_00522060(iVar5,&param_1,0,*(uint8_t *)(iVar3 + 0x538));

        local_1c = CONCAT31(local_1c._1_3_,uVar2);

        FUN_0089a260(iVar3,iVar5,param_1,local_1c);

      }

      iVar5 = FUN_00411900(&local_20);

    }

    *(uint8_t *)(*(int *)(DAT_00d1b570 + 0xf14) + 0x1d) = 0;

  }

  ExceptionList = local_c;

  return;

}
