// READABILITY (auto CF):
//  - Body size: ~159 non-empty decompiler lines.
//  - Control keywords: if×11, return×2, for×1.
//  - Notable callees: FUN_00793aa0×4, FUN_007a75e0×2, FUN_008f8200×2, __RTDynamicCast×2, Client_LookupObjectByTfid_Inferred, Client_MaybeShowFirstTimeTip, Client_RecvBroadcast, FUN_00404c90.
//  - Strings: "[System]".
//  - Return sites: 2.

// =============================================================================
// Client_RecvBroadcast
// -----------------------------------------------------------------------------
// Purpose:  S2C broadcast / chat-style message handler. Gates on client chat UI
//           host (param_2+0x109c). Branches on type@packet+4; formats display name
//           (system / other / local player); optional speech bubble; posts to
//           CDlgChatLog via FUN_008f8200.
//
// Address:  0x00810a80  (autoassault.exe, image base 0x400000)
// Stable:   aa_00810a80
// System:   network-sector
//
// Packet (partial; not full enum sealed):
//   +0x04  i32 type discriminator (3 = object-target resolve path; 2 = tip 0x22)
//   +0x08  TFID sender lo/hi (all-ones -> "[System]", force type 6)
//   +0x10  u8  format flag
//   +0x12  i16 message length
//   +0x14  name string region
//   +0x25  message body start
//
// Control flow summary:
//   1) Gate client+0x109c non-null
//   2) Optional global chat sink DAT_00d1d8c8 + flag DAT_00d1b225 -> FUN_0079d560
//   3) type==3: resolve object target name -> chat log path; return
//   4) TFID all-ones: name="[System]", type=6
//   5) else if TFID == local char: refresh name; stamp chat timers +0x30e8/+0x30f0
//      else copy name from packet; type==2 -> first-time tip 0x22
//   6) Optional world filter (client+0xe04+0xf6) rebuilds message buffer
//   7) RTDynamicCast dialog -> CDlgChatLog; FUN_008f8200 display
//   8) Optional world bubble: LookupObjectByTfid -> spawn float text object
//
// Key offsets:
//   client+0x109c chat/dialog host
//   client+0xe98  local character
//   client+0xe04  world/sim
//   client+0xac0  float-text list host (FUN_00405e20)
//   client+0x30e8 / +0x30f0 local-chat timers
//
// Exactness: CF mirrors raw; many FUN_* UI callees open.
// Dual reviews:
//   reviews/A_aa_00810a80_Client_RecvBroadcast.md
//   reviews/B_aa_00810a80_Client_RecvBroadcast.md
// =============================================================================

void __thiscall Client_RecvBroadcast(int param_1,int param_2)



{

  float fVar1;

  int iVar2;

  byte bVar3;

  int *piVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint32_t /* width from decompiler */ uVar6;

  DWORD DVar7;

  void *pvVar8;

  void *pvVar9;

  char *_Dest;

  int iVar10;

  int *piVar11;

  uint32_t /* width from decompiler */ *puVar12;

  uint8_t *puVar13;

  uint16_t *puVar14;

  uint32_t /* width from decompiler */ uVar15;

  uint uVar16;

  int local_444;

  uint8_t local_428 [20];

  void *local_414;

  uint16_t local_410;

  uint32_t /* width from decompiler */ local_40e [252];

  void *local_1c;

  uint8_t *puStack_18;

  uint32_t /* width from decompiler */ local_14;

  

  local_14 = 0xffffffff;

  puStack_18 = &LAB_009b80c3;

  local_1c = ExceptionList;

  if (*(int *)(param_2 + 0x109c) != 0) {

    local_428[0] = 0;

    ExceptionList = &local_1c;

    if ((DAT_00d1d8c8 != 0) && (ExceptionList = &local_1c, DAT_00d1b225 != '\0')) {

      ExceptionList = &local_1c;

      FUN_0079d560(DAT_00d1d8c8,param_1 + 0x25);

    }

    local_444 = *(int *)(param_1 + 4);

    if (local_444 == 3) {

      piVar4 = (int *)CVOGReaction_ResolveObjectTarget

                                (1,*(uint32_t /* width from decompiler */ *)(param_1 + 8),*(uint32_t /* width from decompiler */ *)(param_1 + 0xc));

      if (piVar4 != (int *)0x0) {

        uVar5 = (**(code **)(*piVar4 + 0x160))(0x11);

        FUN_00793aa0(local_428,uVar5);

      }

      uVar5 = *(uint32_t /* width from decompiler */ *)(param_1 + 4);

      uVar15 = 0;

      param_1 = param_1 + 0x25;

      puVar13 = local_428;

      uVar6 = __RTDynamicCast(*(uint32_t /* width from decompiler */ *)(param_2 + 0x109c),0,&CVOGDialog::RTTI_Type_Descriptor,

                              &CDlgChatLog::RTTI_Type_Descriptor,0,uVar5,puVar13,param_1,0);

      FUN_008f8200(uVar6,uVar5,puVar13,param_1,uVar15);

      ExceptionList = local_1c;

      return;

    }

    if ((*(uint *)(param_1 + 8) & *(uint *)(param_1 + 0xc)) == 0xffffffff) {

      FUN_00793aa0(local_428,"[System]",0x11);

      local_444 = 6;

    }

    else {

      iVar10 = *(int *)(param_2 + 0xe98);

      if (((iVar10 == 0) ||

          (iVar2 = *(int *)(*(int *)(iVar10 + 4) + 4),

          *(uint *)(param_1 + 8) != *(uint *)(iVar2 + 0x164 + iVar10))) ||

         (*(int *)(param_1 + 0xc) != *(int *)(iVar2 + 0x168 + iVar10))) {

        FUN_00793aa0(local_428,param_1 + 0x14,0x11);

        if (*(int *)(param_1 + 4) == 2) {

          Client_MaybeShowFirstTimeTip(0x22);

        }

      }

      else {

        uVar5 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar10 + 4) + 4) + 4 + iVar10) + 0x160))

                          (0x11);

        FUN_00793aa0(local_428,uVar5);

        DVar7 = GetTickCount();

        *(DWORD *)(param_2 + 0x30f0) = DVar7 - *(int *)(param_2 + 0x30e8);

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x30e8) = 0;

        *(uint32_t /* width from decompiler */ *)(param_2 + 0x30ec) = 0;

      }

    }

    if ((*(int *)(param_2 + 0xe04) == 0) || (*(char *)(*(int *)(param_2 + 0xe04) + 0xf6) == '\0')) {

      bVar3 = *(byte *)(param_1 + 0x10);

      puVar14 = (uint16_t *)(param_1 + 0x25);

      uVar5 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x109c);

    }

    else {

      local_410 = 0;

      puVar12 = local_40e;

      for (iVar10 = 0xf9; iVar10 != 0; iVar10 = iVar10 + -1) {

        *puVar12 = 0;

        puVar12 = puVar12 + 1;

      }

      *(uint16_t *)puVar12 = 0;

      puVar14 = &local_410;

      FUN_007a75e0();

      bVar3 = *(byte *)(param_1 + 0x10);

      uVar5 = *(uint32_t /* width from decompiler */ *)(param_2 + 0x109c);

    }

    uVar16 = (uint)bVar3;

    puVar13 = local_428;

    uVar5 = __RTDynamicCast(uVar5,0,&CVOGDialog::RTTI_Type_Descriptor,

                            &CDlgChatLog::RTTI_Type_Descriptor,0,local_444,puVar13,puVar14,uVar16);

    FUN_008f8200(uVar5,local_444,puVar13,puVar14,uVar16);

    pvVar8 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(param_1 + 8),*(uint *)(param_1 + 0xc));

    if ((pvVar8 != (void *)0x0) &&

       (iVar10 = *(int *)(*(int *)((int)pvVar8 + 4) + 4),

       iVar10 = FUN_00573a90(*(uint32_t /* width from decompiler */ *)(iVar10 + 0x164 + (int)pvVar8),

                             *(uint32_t /* width from decompiler */ *)(iVar10 + 0x168 + (int)pvVar8)), iVar10 == 0)) {

      piVar11 = (int *)0x0;

      piVar4 = (int *)FUN_00404c90();

      iVar10 = *piVar4;

      fVar1 = (float)piVar4[1];

      iVar2 = piVar4[2];

      pvVar9 = operator_new(0x60);

      local_14 = 0;

      if (pvVar9 != (void *)0x0) {

        piVar11 = (int *)FUN_004050f0();

      }

      local_14 = 0xffffffff;

      _Dest = operator_new__((int)*(short *)(param_1 + 0x12) + 1);

      *piVar11 = (int)_Dest;

      strncpy(_Dest,(char *)(param_1 + 0x25),(int)*(short *)(param_1 + 0x12));

      *(uint8_t *)((int)*(short *)(param_1 + 0x12) + *piVar11) = 0;

      piVar11[9] = *(int *)(&DAT_00d1e4a0 + *(int *)(param_1 + 4) * 4);

      piVar11[7] = *(int *)(param_2 + 0x9b4);

      piVar11[8] = *(int *)(param_2 + 0x9b4);

      piVar11[1] = iVar10;

      piVar11[2] = (int)(fVar1 + DAT_00aaa688);

      piVar11[3] = iVar2;

      piVar11[10] = 0;

      piVar11[0xb] = 0;

      piVar11[0xc] = 0;

      piVar4 = (int *)(*(int *)(*(int *)((int)pvVar8 + 4) + 4) + 0x164 + (int)pvVar8);

      piVar11[0xe] = *piVar4;

      piVar11[0xf] = piVar4[1];

      piVar11[0x10] = piVar4[2];

      piVar11[0x11] = piVar4[3];

      piVar11[0x12] = 3;

      local_414 = operator_new(0xd0);

      local_14 = 1;

      if (local_414 == (void *)0x0) {

        iVar10 = 0;

      }

      else {

        iVar10 = FUN_007972f0(local_414,0,1);

      }

      local_14 = 0xffffffff;

      piVar11[0x17] = iVar10;

      *(uint8_t *)(iVar10 + 0xb6) = 0;

      FUN_00797a10(piVar11[0x17]);

      FUN_007a75e0();

      FUN_00798720(piVar11[0x17],&local_410,piVar11[9],&DAT_00d1e7e0 + piVar11[0x12],0x3f800000,0);

      FUN_007979c0(piVar11[0x17]);

      FUN_00405e20(param_2 + 0xac0);

    }

  }

  ExceptionList = local_1c;

  return;

}
