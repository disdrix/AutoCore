// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00726070
// -----------------------------------------------------------------------------
// Stable ID: aa_00726070
// Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
// Address:   0x00726070  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PlayNamedInterfaceSound: presentation/world helper with no high-value strings in clean/raw. Role inferred from parent name only; refine when decompile strings or xrefs improve.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~148 non-empty decompiler lines.
//  - Control keywords: if×12, return×7, for×1.
//  - Notable callees: CONCAT22×3, FUN_0071f010×2, FUN_004802e0, FUN_0071e6e0, FUN_0071ee60, FUN_00725e50, FUN_00726070.
//  - Return sites: 7.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PlayNamedInterfaceSound
 * Xref/callee-driven rename (parent seed scan)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

int __thiscall

Named_CalleeOf_Named_CalleeOf_Client_PlayNamedInterfaceSound_00726070(int param_1,int *param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ param_4,uint32_t /* width from decompiler */ param_5,

            uint32_t /* width from decompiler */ param_6,uint32_t /* width from decompiler */ param_7,uint32_t /* width from decompiler */ param_8)



{

  ushort uVar1;

  ushort uVar2;

  int *piVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int *unaff_EBX;

  void *pvVar6;

  int *piVar7;

  uint32_t /* width from decompiler */ in_stack_0000002c;

  int in_stack_00000030;

  uint32_t /* width from decompiler */ local_ac;

  uint16_t local_a8;

  ushort uStack_a6;

  int local_a4;

  int local_a0;

  ushort local_9c;

  ushort uStack_9a;

  uint32_t /* width from decompiler */ local_98;

  uint32_t /* width from decompiler */ local_94;

  uint32_t /* width from decompiler */ local_90;

  uint32_t /* width from decompiler */ local_8c;

  uint32_t /* width from decompiler */ local_88;

  uint32_t /* width from decompiler */ local_84;

  uint16_t local_80;

  ushort uStack_7e;

  uint16_t local_7c;

  uint16_t uStack_7a;

  uint32_t /* width from decompiler */ local_78;

  uint32_t /* width from decompiler */ local_74;

  uint16_t local_70;

  int local_6c [4];

  uint16_t *local_5c;

  uint32_t /* width from decompiler */ local_58;

  uint32_t /* width from decompiler */ local_54;

  uint32_t /* width from decompiler */ local_50;

  uint32_t /* width from decompiler */ local_4c;

  void *pvStack_48;

  uint8_t local_30 [36];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0xffffffff;

  puStack_8 = &LAB_009b1719;

  local_c = ExceptionList;

  if (DAT_00afa9b0 == '\0') {

    return 0;

  }

  if (*unaff_EBX != 0) {

    if ((param_1 == 0) || (param_2 == (int *)0x0)) {

      return -0x7ff8ffa9;

    }

    pvVar6 = (void *)0x0;

    local_ac = 0;

    if (in_stack_00000030 == 2) {

      ExceptionList = &local_c;

      pvVar6 = operator_new(0x58);

      if (pvVar6 == (void *)0x0) {

        pvVar6 = (void *)0x0;

      }

      else {

        pvVar6 = (void *)FUN_0071ee60();

      }

      piVar3 = (int *)FUN_00725e50(unaff_EBX,local_30,param_1,param_3,in_stack_0000002c,0);

      piVar7 = local_6c;

      for (iVar5 = 9; iVar5 != 0; iVar5 = iVar5 + -1) {

        *piVar7 = *piVar3;

        piVar3 = piVar3 + 1;

        piVar7 = piVar7 + 1;

      }

      if (local_6c[0] == 0) {

        if (pvVar6 == (void *)0x0) {

          ExceptionList = local_c;

          return -0x7fffbffb;

        }

        FUN_0071f010();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar6);

      }

      local_58 = param_4;

      local_54 = param_5;

      local_4c = param_7;

      local_50 = param_6;

      puVar4 = (uint32_t /* width from decompiler */ *)FUN_004802e0();

      local_80 = (uint16_t)*puVar4;

      uStack_7e = (ushort)((uint)*puVar4 >> 0x10);

      iVar5 = puVar4[1];

      local_7c = (uint16_t)iVar5;

      uStack_7a = (uint16_t)((uint)iVar5 >> 0x10);

      local_78 = puVar4[2];

      local_74 = puVar4[3];

      local_70 = *(uint16_t *)(puVar4 + 4);

    }

    else {

      iVar5 = CONCAT22(uStack_7a,local_7c);

      ExceptionList = &local_c;

    }

    if (uStack_7e < 3) {

      local_5c = &local_80;

    }

    else {

      uVar1 = (ushort)((uint)local_74 >> 0x10);

      uVar2 = (uVar1 >> 3) * uStack_7e;

      _local_9c = CONCAT22(uVar1,uVar2);

      local_a0 = (uint)uVar2 * iVar5;

      local_90 = DAT_00aa9100;

      local_8c = DAT_00aa9104;

      local_5c = &local_a8;

      _local_a8 = CONCAT22(uStack_7e,0xfffe);

      local_98 = 0x16;

      local_88 = DAT_00aa9108;

      local_84 = DAT_00aa910c;

      local_94 = 0x3f;

      local_a4 = iVar5;

    }

    iVar5 = (**(code **)(*(int *)*unaff_EBX + 0xc))((int *)*unaff_EBX,local_6c,&local_ac,0);

    if (iVar5 < 0) {

      if (pvVar6 != (void *)0x0) {

        FUN_0071f010();

                    /* WARNING: Subroutine does not return */

        operator_delete(pvVar6);

      }

    }

    else {

      if ((uint32_t /* width from decompiler */ *)*param_2 != (uint32_t /* width from decompiler */ *)0x0) {

        (*(code *)**(uint32_t /* width from decompiler */ **)*param_2)(1);

      }

      *param_2 = 0;

      pvStack_48 = operator_new(0x250);

      uStack_4 = 0;

      if (pvStack_48 == (void *)0x0) {

        iVar5 = 0;

        *param_2 = 0;

      }

      else {

        iVar5 = FUN_0071e6e0(local_ac,0,param_8,local_6c[2],param_3,1,in_stack_0000002c);

        *param_2 = iVar5;

        iVar5 = 0;

      }

    }

    ExceptionList = local_c;

    return iVar5;

  }

  return -0x7ffbfe10;

}
