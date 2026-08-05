// READABILITY (auto CF):
//  - Body size: ~126 non-empty decompiler lines.
//  - Control keywords: if×12, return×5.
//  - Notable callees: FUN_004e87d0×2, FUN_004e88e0×2, CONCAT31, FUN_008024d0, FUN_00811e00, FUN_0092a200, FUN_009972a0, OutputDebugStringA.
//  - Strings: "Requesting ProcessSectorUpdate\n".
//  - Return sites: 5.

// =============================================================================
// Mission_Requesting_ProcessSectorUpdate_00811e00
// -----------------------------------------------------------------------------
// Stable ID: aa_00811e00
// Address:   0x00811e00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Requesting ProcessSectorUpdate
"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Mission_Requesting_ProcessSectorUpdate_00811e00(int param_1,int param_2)



{

  uint *puVar1;

  uint32_t /* width from decompiler */ *puVar2;

  char cVar3;

  int *in_EAX;

  int iVar4;

  int *piVar5;

  uint32_t /* width from decompiler */ *puVar6;

  byte bVar7;

  int iStack_70;

  int iStack_6c;

  uint32_t /* width from decompiler */ uStack_68;

  uint32_t /* width from decompiler */ uStack_64;

  uint8_t *puStack_60;

  uint *puStack_5c;

  uint8_t *puStack_58;

  uint local_44;

  uint8_t auStack_40 [12];

  uint8_t auStack_34 [4];

  int iStack_30;

  int iStack_2c;

  int aiStack_28 [3];

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  puStack_58 = (uint8_t *)0x811e1e;

  OutputDebugStringA("Requesting ProcessSectorUpdate\n");

  if (*(char *)(param_1 + 0xa1) != '\0') {

    uStack_64 = *(uint32_t /* width from decompiler */ *)(param_2 + 0xe04);

    puStack_58 = (uint8_t *)0x0;

    puStack_5c = (uint *)0x0;

    puStack_60 = (uint8_t *)0x0;

    uStack_68 = 2;

    iStack_70 = 0x811e43;

    iStack_6c = param_1;

    (**(code **)(*in_EAX + 0xc4))();

    iStack_70 = 0x811e4a;

    FUN_009972a0();

    iStack_70 = in_EAX[0x59];

    FUN_008024d0(param_2,DAT_00d1d86c,DAT_00d1d870,0,0,0,in_EAX[0x58]);

    return;

  }

  if (*(int *)(param_2 + 0xe98) != 0) {

    iVar4 = *(int *)(*(int *)(param_2 + 0xe98) + 0x250);

    if (iVar4 != 0) {

      iVar4 = *(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4;

    }

    if (in_EAX[0x2b] == iVar4) {

      return;

    }

  }

  if ((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) != 0xffffffff) {

    puStack_58 = (uint8_t *)0x811ec3;

    (**(code **)(*in_EAX + 0x260))();

    return;

  }

  in_EAX[0x5f] = in_EAX[0x5f] ^ ((uint)*(byte *)(param_1 + 0xa8) * 4 ^ in_EAX[0x5f]) & 4;

  if (*(char *)(param_1 + 0xa8) == '\0') {

    local_44 = *(uint *)(param_2 + 0x4d0);

    cVar3 = FUN_0092a200();

    if (cVar3 != '\0') {

      *(uint8_t *)(local_44 + 4) = 1;

    }

  }

  piVar5 = (int *)(**(code **)(*in_EAX + 0x1cc))();

  if (piVar5 != (int *)0x0) {

    bVar7 = 0;

    if (((((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) == 0xffffffff) &&

         (*(char *)(param_1 + 0xc0) == '\0')) && (*(char *)(param_1 + 0xa8) == '\0')) &&

       (*(char *)(param_1 + 0xa0) == '\0')) {

      bVar7 = 1;

    }

    uStack_14 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x7c);

    iStack_30 = *(int *)(param_1 + 100);

    iStack_2c = *(int *)(param_1 + 0x68);

    aiStack_28[0] = *(int *)(param_1 + 0x6c);

    uStack_1c = *(uint32_t /* width from decompiler */ *)(param_1 + 0x74);

    uStack_18 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x78);

    aiStack_28[2] = *(uint32_t /* width from decompiler */ *)(param_1 + 0x70);

    aiStack_28[1] = 0;

    in_EAX[0x20] = iStack_30;

    in_EAX[0x21] = iStack_2c;

    in_EAX[0x22] = aiStack_28[0];

    in_EAX[0x23] = 0;

    puVar1 = (uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x188);

    *puVar1 = *puVar1 ^ ((uint)bVar7 ^ *(uint *)((int)piVar5 + *(int *)(piVar5[1] + 4) + 0x188)) & 1

    ;

    if (((piVar5[2] == 0) && (*(char *)(param_1 + 0xa2) == '\0')) &&

       ((*(char *)(param_1 + 0xa8) == '\0' && (*(char *)(param_1 + 0xc0) == '\0')))) {

      if ((bVar7 != 0) || (local_44 = local_44 & 0xffffff00, *(char *)(param_1 + 0xa0) != '\0')) {

        local_44 = CONCAT31(local_44._1_3_,1);

      }

      puVar2 = (uint32_t /* width from decompiler */ *)*piVar5;

      puStack_58 = auStack_40;

      puStack_5c = (uint *)0x812023;

      puVar6 = (uint32_t /* width from decompiler */ *)FUN_004e87d0();

      uStack_64 = *puVar6;

      puStack_60 = (uint8_t *)puVar6[1];

      puStack_5c = (uint *)puVar6[2];

      puStack_58 = (uint8_t *)puVar6[3];

      FUN_004e88e0(&iStack_70,&iStack_30);

      (*(code *)*puVar2)(local_44);

      return;

    }

    puStack_58 = (uint8_t *)0x812082;

    (**(code **)(*piVar5 + 0x18))();

    if ((int *)piVar5[2] != (int *)0x0) {

      iVar4 = *(int *)piVar5[2];

      puStack_58 = auStack_34;

      puStack_5c = &local_44;

      puStack_60 = (uint8_t *)0x81209a;

      puStack_58 = (uint8_t *)FUN_004e88e0();

      puStack_5c = (uint *)0x8120a3;

      (**(code **)(iVar4 + 0x18))();

      iVar4 = *(int *)piVar5[2];

      puStack_5c = (uint *)aiStack_28;

      puStack_60 = &stack0xffffffb8;

      uStack_64 = 0x8120b7;

      puStack_5c = (uint *)FUN_004e87d0();

      puStack_60 = (uint8_t *)0x8120c0;

      (**(code **)(iVar4 + 0x14))();

    }

  }

  return;

}
