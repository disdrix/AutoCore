// =============================================================================
// FUN_007214e0
// -----------------------------------------------------------------------------
// Stable ID: aa_007214e0
// Address:   0x007214e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007214e0 @ 0x007214e0
// Stable ID: aa_007214e0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~140 non-empty decompiler lines.
//  - Control keywords: if×7, return×2, for×1.
//  - Notable callees: CONCAT22×2, Client_GetMissionCompleteAudioTable×2, EnterCriticalSection, FUN_0071ee60, FUN_0071f010, FUN_007214e0, FUN_00725e50, FUN_0099caa0.
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

uint32_t /* width from decompiler */ __thiscall

FUN_007214e0(int param_1,int param_2,int *param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8,uint32_t /* width from decompiler */ param_9)



{

  ushort uVar1;

  ushort uVar2;

  void *pvVar3;

  uint32_t /* width from decompiler */ uVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int iVar6;

  LPCRITICAL_SECTION lpCriticalSection;

  uint32_t /* width from decompiler */ *puVar7;

  uint8_t *puVar8;

  uint32_t /* width from decompiler */ uVar9;

  uint32_t /* width from decompiler */ uVar10;

  uint32_t /* width from decompiler */ local_98;

  uint16_t local_94;

  ushort uStack_92;

  int local_90;

  int local_8c;

  ushort local_88;

  ushort uStack_86;

  uint32_t /* width from decompiler */ local_84;

  uint32_t /* width from decompiler */ local_80;

  uint32_t /* width from decompiler */ local_7c;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint32_t /* width from decompiler */ local_70;

  uint16_t local_6c;

  ushort uStack_6a;

  uint16_t local_68;

  uint16_t uStack_66;

  uint32_t /* width from decompiler */ local_64;

  uint32_t /* width from decompiler */ local_60;

  uint16_t local_5c;

  LPCRITICAL_SECTION local_58;

  uint32_t /* width from decompiler */ local_54 [4];

  uint16_t *local_44;

  uint32_t /* width from decompiler */ local_40;

  uint32_t /* width from decompiler */ local_3c;

  uint32_t /* width from decompiler */ local_38;

  uint32_t /* width from decompiler */ local_34;

  uint8_t local_30 [36];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1db8;

  local_c = ExceptionList;

  if ((param_1 == 0) || (param_3 == (int *)0x0)) {

    uVar4 = 0x80070057;

  }

  else {

    local_98 = 0;

    ExceptionList = &local_c;

    pvVar3 = operator_new(0x58);

    if (pvVar3 == (void *)0x0) {

      pvVar3 = (void *)0x0;

    }

    else {

      pvVar3 = (void *)FUN_0071ee60();

    }

    uVar10 = 1;

    uVar9 = 0;

    puVar8 = local_30;

    uVar4 = Client_GetMissionCompleteAudioTable(puVar8,param_1,param_4,0,1);

    puVar5 = (uint32_t /* width from decompiler */ *)FUN_00725e50(uVar4,puVar8,param_1,param_4,uVar9,uVar10);

    puVar7 = local_54;

    for (iVar6 = 9; iVar6 != 0; iVar6 = iVar6 + -1) {

      *puVar7 = *puVar5;

      puVar5 = puVar5 + 1;

      puVar7 = puVar7 + 1;

    }

    if (pvVar3 == (void *)0x0) {

      uVar4 = 0x80004005;

    }

    else {

      local_3c = param_6;

      local_40 = param_5;

      local_38 = param_7;

      local_34 = param_8;

      local_6c = (uint16_t)*(uint32_t /* width from decompiler */ *)((int)pvVar3 + 8);

      uStack_6a = (ushort)((uint)*(uint32_t /* width from decompiler */ *)((int)pvVar3 + 8) >> 0x10);

      iVar6 = *(int *)((int)pvVar3 + 0xc);

      local_68 = (uint16_t)iVar6;

      uStack_66 = (uint16_t)((uint)iVar6 >> 0x10);

      local_64 = *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x10);

      local_60 = *(uint32_t /* width from decompiler */ *)((int)pvVar3 + 0x14);

      local_5c = *(uint16_t *)((int)pvVar3 + 0x18);

      if (uStack_6a < 3) {

        local_44 = &local_6c;

      }

      else {

        uVar1 = (ushort)((uint)local_60 >> 0x10);

        uVar2 = (uVar1 >> 3) * uStack_6a;

        _local_88 = CONCAT22(uVar1,uVar2);

        local_8c = (uint)uVar2 * iVar6;

        local_7c = DAT_00aa9100;

        local_78 = DAT_00aa9104;

        local_44 = &local_94;

        _local_94 = CONCAT22(uStack_6a,0xfffe);

        local_84 = 0x16;

        local_74 = DAT_00aa9108;

        local_70 = DAT_00aa910c;

        local_80 = 0x3f;

        local_90 = iVar6;

      }

      lpCriticalSection = (LPCRITICAL_SECTION)(param_2 + 0x158);

      local_58 = lpCriticalSection;

      EnterCriticalSection(lpCriticalSection);

      local_4 = 0;

      puVar5 = (uint32_t /* width from decompiler */ *)Client_GetMissionCompleteAudioTable();

      iVar6 = (**(code **)(*(int *)*puVar5 + 0xc))((int *)*puVar5,local_54,&local_98,0);

      if (iVar6 < 0) {

        FUN_0071f010();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar3);

      }

      local_4 = 0xffffffff;

      LeaveCriticalSection(lpCriticalSection);

      if ((uint32_t /* width from decompiler */ *)*param_3 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*param_3)(1);

      }

      *param_3 = 0;

      local_58 = operator_new(800);

      local_4 = 1;

      if (local_58 == (void *)0x0) {

        uVar4 = 0;

        *param_3 = 0;

      }

      else {

        iVar6 = FUN_0099caa0(local_98,0,pvVar3,param_9,local_54[2]);

        *param_3 = iVar6;

        uVar4 = 0;

      }

    }

  }

  ExceptionList = local_c;

  return uVar4;

}
