// READABILITY (auto CF):
//  - Body size: ~185 non-empty decompiler lines.
//  - Control keywords: if×21, goto×3, return×2, do×2, while×2.
//  - Notable callees: BitStream_readBits×7, FUN_00424e50×2, FUN_0042bdf0×2, FUN_0042e5b0×2, FUN_0042e9a0×2, FUN_0040b290, FUN_00424c90, FUN_00425000.
//  - Strings: "LogNetInterface"; "Received Connect Request %8x".
//  - Return sites: 2.

// =============================================================================
// Mission_Received_Connect_Request_8x_0042df20
// -----------------------------------------------------------------------------
// Stable ID: aa_0042df20
// Address:   0x0042df20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Received Connect Request %8x"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

/* WARNING: Type propagation algorithm not settling */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void Mission_Received_Connect_Request_8x_0042df20(int *param_1,uint32_t /* width from decompiler */ param_2,int param_3,uint32_t /* width from decompiler */ param_4)



{

  char cVar1;

  int iVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  int *piVar5;

  int iVar6;

  int *piVar7;

  bool bVar8;

  int iStack_3f8;

  int aiStack_3f4 [2];

  uint8_t local_3ec;

  char local_3eb;

  uint8_t local_3ea;

  uint8_t local_3e9;

  int local_3e8 [6];

  int iStack_3d0;

  uint32_t /* width from decompiler */ local_3cc;

  uint32_t /* width from decompiler */ local_3c8;

  uint32_t /* width from decompiler */ local_3c4;

  uint32_t /* width from decompiler */ local_3c0;

  uint8_t auStack_3ba [16];

  uint8_t auStack_3aa [18];

  uint32_t /* width from decompiler */ local_398;

  uint32_t /* width from decompiler */ local_394;

  uint32_t /* width from decompiler */ local_390;

  uint8_t local_38c;

  uint8_t uStack_38b;

  uint32_t /* width from decompiler */ local_388;

  uint8_t uStack_384;

  uint8_t auStack_37c [256];

  uint8_t auStack_27c [636];

  

  if ((char)param_1[0x24] == '\0') {

    return;

  }

  local_3cc = 0;

  local_3c8 = 0;

  local_3c4 = 0;

  local_3c0 = 0;

  local_390 = 0;

  local_398 = 0;

  local_394 = 0;

  local_388 = 0;

  local_38c = 0;

  local_3e9 = 0;

  local_3eb = '\0';

  local_3ea = 0;

  local_3ec = 0;

  uStack_384 = 0;

  uStack_38b = 0;

  BitStream_readBits(0x40,local_3e8);

  BitStream_readBits(0x40,local_3e8 + 2);

  BitStream_readBits(0x20,&iStack_3f8);

  iStack_3d0 = iStack_3f8;

  iVar2 = FUN_0042c460(param_1,param_2,local_3e8);

  if (iStack_3d0 == iVar2) {

    BitStream_readBits(0x20,&iStack_3f8);

    local_3e8[4] = iStack_3f8;

    BitStream_readBits(0x20,&iStack_3f8);

    local_3e8[5] = iStack_3f8;

    iVar2 = FUN_0042c6c0();

    aiStack_3f4[0] = iVar2;

    if (iVar2 != 0) {

      iVar6 = 2;

      bVar8 = true;

      piVar5 = (int *)(iVar2 + 0x138);

      piVar7 = local_3e8;

      do {

        if (iVar6 == 0) break;

        iVar6 = iVar6 + -1;

        bVar8 = *piVar5 == *piVar7;

        piVar5 = piVar5 + 1;

        piVar7 = piVar7 + 1;

      } while (bVar8);

      if (bVar8) {

        iVar6 = 2;

        bVar8 = true;

        piVar5 = (int *)(iVar2 + 0x140);

        piVar7 = local_3e8 + 2;

        do {

          if (iVar6 == 0) break;

          iVar6 = iVar6 + -1;

          bVar8 = *piVar5 == *piVar7;

          piVar5 = piVar5 + 1;

          piVar7 = piVar7 + 1;

        } while (bVar8);

        if (bVar8) {

          FUN_0042e5b0(param_1,param_4);

          goto LAB_0042e36a;

        }

      }

    }

    iVar6 = FUN_00974590(iStack_3f8,local_3e8,local_3e8 + 2,iStack_3d0);

    if (iVar6 == 0) {

      cVar1 = FUN_00424e50();

      if (cVar1 != '\0') {

        if (param_1[0xf] == 0) goto LAB_0042e36a;

        local_3eb = '\x01';

        pvVar3 = operator_new(0x24);

        if (pvVar3 != (void *)0x0) {

          FUN_0042be80(param_3);

        }

        FUN_00430110();

        FUN_004300e0();

        *(uint *)(param_3 + 0x18) = *(int *)(param_3 + 0x18) + 7U & 0xfffffff8;

        uVar4 = FUN_0098b790(local_3c8,&iStack_3f8);

        FUN_00426b40(uVar4);

        FUN_0040b290();

        FUN_007838a0();

        cVar1 = FUN_0042bd10(param_3,5,auStack_27c);

        if (cVar1 == '\0') {

          FUN_0042bdf0();

          goto LAB_0042e36a;

        }

        BitStream_readBits(0x80,auStack_3ba);

        FUN_00975f50(auStack_3aa,0x10);

        FUN_0042bdf0();

        iVar2 = aiStack_3f4[0];

      }

      uStack_384 = FUN_00424e50();

      BitStream_readBits(0x20,aiStack_3f4);

      if ((_DAT_00d217fc & 1) == 0) {

        _DAT_00d217fc = _DAT_00d217fc | 1;

        DAT_00d217f8 = FUN_00783b60("LogNetInterface");

      }

      if (*(char *)(DAT_00d217f8 + 4) != '\0') {

        DAT_00d179a0 = DAT_00d217f8;

        FUN_00783aa0("Received Connect Request %8x",iStack_3d0);

        DAT_00d179a0 = 0;

      }

      if (iVar2 != 0) {

        FUN_0042fe60();

      }

      FUN_0042ba90(auStack_37c);

      piVar5 = (int *)FUN_00425000(auStack_37c);

      if (piVar5 != (int *)0x0) {

        piVar5[2] = piVar5[2] + 1;

        FUN_0042e380();

        FUN_00425460();

        piVar5[0x27] = aiStack_3f4[0];

        piVar5[0x23] = aiStack_3f4[0];

        piVar5[0x29] = aiStack_3f4[0];

        FUN_00424c90();

        (**(code **)(*piVar5 + 0x4c))();

        if (local_3eb != '\0') {

          pvVar3 = operator_new(0x274);

          if (pvVar3 != (void *)0x0) {

            FUN_007839b0();

          }

          FUN_004269b0();

        }

        aiStack_3f4[1] = 0;

        cVar1 = (**(code **)(*piVar5 + 0x24))(param_3,aiStack_3f4 + 1);

        if (cVar1 == '\0') {

          FUN_0042e9a0(param_1,piVar5[0x43],param_2);

          piVar7 = piVar5 + 2;

          *piVar7 = *piVar7 + -1;

          if (*piVar7 == 0) {

            (**(code **)(*piVar5 + 8))();

          }

        }

        else {

          (**(code **)(*param_1 + 0xc))(piVar5);

          piVar5[0x6e] = 7;

          (**(code **)(*piVar5 + 0x14))();

          FUN_0042e5b0(param_1,param_4);

          piVar7 = piVar5 + 2;

          *piVar7 = *piVar7 + -1;

          if (*piVar7 == 0) {

            (**(code **)(*piVar5 + 8))();

          }

        }

      }

    }

    else {

      FUN_0042e9a0(param_1,param_4,param_2);

    }

  }

LAB_0042e36a:

  FUN_004252e0();

  return;

}
