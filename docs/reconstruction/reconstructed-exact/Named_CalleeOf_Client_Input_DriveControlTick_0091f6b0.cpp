// =============================================================================
// Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0091f6b0
// Callee of Client_Input_DriveControlTick
// Address:   0x0091f6b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Client_Input_DriveControlTick: drive/input helper. Evidence string: "You have no mod chip!". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "You have no mod chip!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: Client_SendSectorPacket×2, FUN_0040ce50×2, FUN_007fdfb0, FUN_008f8200, FUN_0091f6b0, Skill_FormatFailureMessage.
//  - Strings: "You have no mod chip!".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Callee of Client_Input_DriveControlTick
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

void __fastcall Named_CalleeOf_Client_Input_DriveControlTick_0091f6b0(uint32_t /* width from decompiler */ param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  char bSkipBusyCheck;

  int iVar2;

  void *pvVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint32_t /* width from decompiler */ local_108;

  uint32_t /* width from decompiler */ local_104 [65];

  

  if (((DAT_00d1b6d8 != (void *)0x0) && (*(char *)(DAT_00d1b644 + 0xf5) == '\0')) &&

     (*(char *)((int)DAT_00d1b6d8 + 0x6bb) == '\0')) {

    *(uint32_t /* width from decompiler */ *)(param_2 + 0xc2c) = 9999999;

    pvVar3 = DAT_00d1b6d8;

    if (*(char *)((int)DAT_00d1b6d8 + 0x6b9) != '\0') {

      local_118 = 0x202c;

      puVar1 = (uint32_t /* width from decompiler */ *)

               (*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x164 + (int)DAT_00d1b6d8);

      local_110 = *puVar1;

      local_10c = puVar1[1];

      local_108 = puVar1[2];

      local_104[0] = puVar1[3];

      Client_SendSectorPacket(&DAT_00d1a840,0x18,&local_118);

      return;

    }

    if ((*(int *)((int)DAT_00d1b6d8 + 0x250) == 0) || (iVar2 = FUN_0040ce50(), iVar2 == -1)) {

      FUN_007fdfb0(&DAT_00d1a840,"You have no mod chip!",0xffffffff,1,0);

    }

    else {

      iVar2 = *(int *)(*(int *)(*(int *)((int)pvVar3 + 4) + 4) + 4 + (int)pvVar3);

      pvVar3 = (void *)FUN_0040ce50(0);

      bSkipBusyCheck = (**(code **)(iVar2 + 0x234))();

      iVar2 = Skill_LocalCastValidate

                        ((void *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 +

                                 (int)DAT_00d1b6d8),(void *)0x0,bSkipBusyCheck,pvVar3);

      if (iVar2 == 0) {

        puVar1 = (uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 0x164 + (int)DAT_00d1b6d8);

        uStack_114 = *puVar1;

        local_110 = puVar1[1];

        local_10c = puVar1[2];

        local_108 = puVar1[3];

        Client_SendSectorPacket(&DAT_00d1a840,0x18,&stack0xfffffee4);

        return;

      }

      pvVar3 = DAT_00d1b6d8;

      if (DAT_00d1b6d8 != (void *)0x0) {

        pvVar3 = (void *)(*(int *)(*(int *)((int)DAT_00d1b6d8 + 4) + 4) + 4 + (int)DAT_00d1b6d8);

      }

      pcVar4 = Skill_FormatFailureMessage(iVar2,(char *)local_104,pvVar3);

      if (DAT_00d1b8dc != 0) {

        FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,pcVar4,0);

        return;

      }

    }

  }

  return;

}
