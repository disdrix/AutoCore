// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×8, return×2, goto×1, do×1, while×1.
//  - Notable callees: FUN_007a4480×3, FUN_00786990×2, FUN_00787d40×2, CONCAT31, CVOGReaction_GiveItemByCbid, FUN_00403430, FUN_0040fb90, FUN_0051b350.
//  - Strings: "ServerCreateFromPacket"; "Invalid CBID allocated: %d, coid : %I64d"; "Invalid CBID initified: %d, coid : %I64d".
//  - Return sites: 2.

// =============================================================================
// Named_Invalid_COID_initified_d_coid_I64d_in_ServerCrea_0051b350
// -----------------------------------------------------------------------------
// Stable ID: aa_0051b350
// Address:   0x0051b350  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int * Named_Invalid_COID_initified_d_coid_I64d_in_ServerCrea_0051b350(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2)



{

  int iVar1;

  int *piVar2;

  int *piVar3;

  int *unaff_EDI;

  bool bVar4;

  int local_28;

  int local_24;

  int local_20;

  int local_1c;

  int *piStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a36ec;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_00786a00("ServerCreateFromPacket");

  local_4 = 0;

  piVar3 = (int *)0x0;

  FUN_00787d40(&local_28,4);

  if (local_28 == -1) {

LAB_0051b528:

    local_4 = 0xffffffff;

    FUN_00786990();

    ExceptionList = local_c;

    return piVar3;

  }

  FUN_00787d40(&local_20,8);

  iVar1 = DAT_00b041fc;

  Map_LowerBoundFindByIntKey((void *)(DAT_00b041fc + 4),&local_24,&local_28,unaff_EDI);

  bVar4 = local_24 != *(int *)(iVar1 + 8);

  if (bVar4) {

    local_28 = *(int *)(local_24 + 0x10);

  }

  piVar3 = (int *)CVOGReaction_GiveItemByCbid(local_28);

  if (piVar3 == (int *)0x0) {

    FUN_007a4480(1,"Invalid CBID allocated: %d, coid : %I64d",local_28,local_20,local_1c);

  }

  else {

    iVar1 = (**(code **)(*piVar3 + 8))(local_28,param_2,1);

    if (iVar1 < 0) {

      FUN_007a4480(1,"Invalid CBID initified: %d, coid : %I64d",local_28,local_20,local_1c);

    }

    else {

      piVar3[0x58] = local_20;

      piVar3[0x59] = local_1c;

      *(uint8_t *)(piVar3 + 0x5a) = 1;

      iVar1 = (**(code **)(*piVar3 + 0x20))(local_20,local_1c,0,param_1,1);

      if (-1 < iVar1) {

        if (bVar4) {

          *(byte *)(piVar3 + 0x5f) = *(byte *)(piVar3 + 0x5f) | 0x80;

        }

        goto LAB_0051b528;

      }

      FUN_007a4480(1,"Invalid COID initified: %d, coid : %I64d (in ServerCreateFromPacket)",local_28

                   ,local_20,local_1c);

      uStack_14 = FUN_0040fb90();

      uStack_10 = 0;

      local_4 = CONCAT31(local_4._1_3_,1);

      (**(code **)(*piVar3 + 0x2b0))(&piStack_18);

      piVar3 = (int *)*piStack_18;

      piVar2 = piStack_18;

      if (piVar3 != piStack_18) {

        do {

          if ((uint32_t /* width from decompiler */ *)piVar3[2] != (uint32_t /* width from decompiler */ *)0x0) {

            (*(code *)**(uint32_t /* width from decompiler */ **)piVar3[2])(1);

            piVar2 = piStack_18;

          }

          piVar3 = (int *)*piVar3;

        } while (piVar3 != piVar2);

      }

      FUN_00403430();

    }

  }

  local_4 = 0xffffffff;

  FUN_00786990();

  ExceptionList = local_c;

  return (int *)0x0;

}
