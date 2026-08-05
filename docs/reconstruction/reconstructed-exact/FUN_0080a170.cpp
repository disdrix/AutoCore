// =============================================================================
// FUN_0080a170
// -----------------------------------------------------------------------------
// Stable ID: aa_0080a170
// Address:   0x0080a170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080a170 @ 0x0080a170
// Stable ID: aa_0080a170
// Embedded strings (evidence for future rename):
//   - "Trade refused."
//   - "Do you wish to trade with"
//   - "%s %s"
//   - "is already trading... try again later"
//   - "%s %s."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×9, return×5, goto×1.
//  - Notable callees: FUN_007a6de0×3, FUN_007fdfb0×3, Client_SendSectorPacket×2, FUN_007fc360×2, sprintf×2, Client_LookupObjectByTfid_Inferred, FUN_00573a90, FUN_007a69d0.
//  - Strings: "Trade refused."; "Do you wish to trade with"; "%s %s"; "is already trading... try again later".
//  - Return sites: 5.

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

void FUN_0080a170(void)



{

  int iVar1;

  char cVar2;

  int in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  void *pvVar4;

  int iVar5;

  void *unaff_ESI;

  uint32_t /* width from decompiler */ uVar6;

  uint32_t /* width from decompiler */ uVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ local_120 [2];

  uint32_t /* width from decompiler */ local_118;

  uint32_t /* width from decompiler */ local_114;

  uint32_t /* width from decompiler */ local_110;

  uint32_t /* width from decompiler */ local_10c;

  uint8_t local_108;

  uint8_t local_107;

  char acStack_100 [256];

  

  if (*(int *)((int)unaff_ESI + 0xe98) != 0) {

    FUN_007a69d0();

    local_110 = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

    local_10c = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

    iVar5 = *(int *)((int)unaff_ESI + 0xe98);

    local_120[0] = 0x2085;

    iVar1 = *(int *)(*(int *)(iVar5 + 4) + 4);

    local_118 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x164 + iVar5);

    local_114 = *(uint32_t /* width from decompiler */ *)(iVar1 + 0x168 + iVar5);

    local_108 = 0;

    local_107 = 0;

    if (*(char *)(in_EAX + 0x1a) == '\0') {

      FUN_007fc360();

      iVar5 = *(int *)((int)unaff_ESI + 0xe98);

      uVar8 = 0;

      uVar7 = 1;

      uVar6 = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xcd8) = 0xffffffff;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0xcdc) = 0xffffffff;

      uVar3 = FUN_007a6de0("Trade refused.",0xffffffff);

      FUN_007fdfb0(unaff_ESI,uVar3,uVar6,uVar7,uVar8);

      return;

    }

    if (*(char *)(in_EAX + 0x1b) == '\0') {

      iVar5 = FUN_00573a90(local_110,local_10c);

      if (iVar5 != 0) {

        local_108 = 1;

LAB_0080a340:

        Client_SendSectorPacket(unaff_ESI,0x20,local_120);

        return;

      }

      if (*(char *)(in_EAX + 0x18) != '\0') {

        if (((*(int *)((int)unaff_ESI + 0x1118) != 0) && (*(int *)((int)unaff_ESI + 0xf40) != 0)) &&

           (cVar2 = (**(code **)(**(int **)((int)unaff_ESI + 0x1118) + 0x3d8))(), cVar2 != '\0')) {

          iVar5 = FUN_008a70e0();

          if (((iVar5 != -1) || (iVar5 = FUN_008a70c0(), iVar5 != 0x4e32)) ||

             ((*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0xcd8) != *(int *)(in_EAX + 8) ||

              (*(int *)(*(int *)((int)unaff_ESI + 0xe98) + 0xcdc) != *(int *)(in_EAX + 0xc))))) {

            local_108 = 1;

            Client_SendSectorPacket(unaff_ESI,0x20,local_120);

            return;

          }

          FUN_007fc360();

          local_107 = 1;

          goto LAB_0080a340;

        }

        pvVar4 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(in_EAX + 8),*(uint *)(in_EAX + 0xc))

        ;

        if (pvVar4 != (void *)0x0) {

          iVar5 = *(int *)((int)unaff_ESI + 0xe98);

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0xcd8) = *(uint32_t /* width from decompiler */ *)(in_EAX + 8);

          *(uint32_t /* width from decompiler */ *)(iVar5 + 0xcdc) = *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc);

          uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar4 + 4) + 4) + 4 + (int)pvVar4) +

                              0x160))();

          uVar6 = FUN_007a6de0("Do you wish to trade with",0xffffffff);

          sprintf(acStack_100,"%s %s",uVar6,uVar3);

          FUN_007fdfb0(unaff_ESI,acStack_100,0x4e32,1,0);

        }

      }

    }

    else {

      pvVar4 = Client_LookupObjectByTfid_Inferred

                         (1,*(uint *)(in_EAX + 0x10),*(uint *)(in_EAX + 0x14));

      if (pvVar4 != (void *)0x0) {

        iVar5 = *(int *)(*(int *)((int)pvVar4 + 4) + 4);

        uVar3 = FUN_007a6de0("is already trading... try again later",0xffffffff);

        uVar3 = (**(code **)(*(int *)(iVar5 + 4 + (int)pvVar4) + 0x160))(uVar3);

        sprintf(acStack_100,"%s %s.",uVar3);

        FUN_007fdfb0(unaff_ESI,acStack_100,0xffffffff,1,0);

        return;

      }

    }

  }

  return;

}
