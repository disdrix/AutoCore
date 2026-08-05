// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: if×9, return×4.
//  - Notable callees: FUN_007fdfb0×3, Client_LookupObjectByTfid_Inferred, Client_SendSectorPacket, FUN_007a69d0, FUN_007a6de0, FUN_007fc360, FUN_008a70e0, FUN_0094c430.
//  - Strings: "You are already involved in a trade."; "Character not found."; "Requesting to trade with"; "%s %s.".
//  - Return sites: 4.

// =============================================================================
// Mission_Requesting_to_trade_with_0094c8b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0094c8b0
// Address:   0x0094c8b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "Requesting to trade with"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void Mission_Requesting_to_trade_with_0094c8b0(uint32_t /* width from decompiler */ param_1,uint32_t /* width from decompiler */ param_2,uint param_3,uint param_4)



{

  int *piVar1;

  int iVar2;

  char cVar3;

  void *in_EAX;

  int iVar4;

  void *pvVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ auStack_120 [2];

  uint32_t /* width from decompiler */ uStack_118;

  uint32_t /* width from decompiler */ uStack_114;

  uint uStack_110;

  uint uStack_10c;

  uint8_t uStack_108;

  uint8_t uStack_107;

  char acStack_100 [256];

  

  if (*(int *)((int)in_EAX + 0xe98) != 0) {

    piVar1 = *(int **)((int)in_EAX + 0x1050);

    if (piVar1 != (int *)0x0) {

      cVar3 = (**(code **)(*piVar1 + 0x3d8))();

      if (cVar3 != '\0') {

        cVar3 = (**(code **)(*piVar1 + 0xd0))();

        if (cVar3 != '\0') {

          FUN_007fdfb0(in_EAX,"You are already involved in a trade.",0xffffffff,1,0);

          return;

        }

      }

    }

    if (*(int *)((int)in_EAX + 0x1118) != 0) {

      cVar3 = (**(code **)(**(int **)((int)in_EAX + 0x1118) + 0x3d8))();

      if (cVar3 != '\0') {

        iVar4 = FUN_008a70e0();

        if (iVar4 == 0x4e31) {

          if ((*(uint *)(*(int *)((int)in_EAX + 0xe98) + 0xcd8) == param_3) &&

             (*(uint *)(*(int *)((int)in_EAX + 0xe98) + 0xcdc) == param_4)) {

            FUN_007fc360();

            FUN_0094c4c0(1);

            return;

          }

          FUN_0094c430();

        }

      }

    }

    FUN_007a69d0();

    pvVar5 = Client_LookupObjectByTfid_Inferred(1,param_3,param_4);

    if (pvVar5 == (void *)0x0) {

      FUN_007fdfb0(in_EAX,"Character not found.",0xffffffff,1,0);

      return;

    }

    uVar6 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar5 + 4) + 4) + 4 + (int)pvVar5) + 0x160

                        ))();

    uVar7 = FUN_007a6de0("Requesting to trade with",0xffffffff);

    sprintf(acStack_100,"%s %s.",uVar7,uVar6);

    FUN_007fdfb0(in_EAX,acStack_100,0x4e32,1,0);

    iVar4 = *(int *)(*(int *)((int)pvVar5 + 4) + 4);

    iVar2 = *(int *)((int)in_EAX + 0xe98);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcd8) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x164 + (int)pvVar5);

    *(uint32_t /* width from decompiler */ *)(iVar2 + 0xcdc) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x168 + (int)pvVar5);

    uStack_118 = param_1;

    uStack_10c = param_4;

    auStack_120[0] = 0x2087;

    uStack_114 = param_2;

    uStack_110 = param_3;

    uStack_108 = 1;

    uStack_107 = 0;

    Client_SendSectorPacket(in_EAX,0x20,auStack_120);

  }

  return;

}
