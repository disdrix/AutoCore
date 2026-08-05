// READABILITY (auto CF):
//  - Body size: ~138 non-empty decompiler lines.
//  - Control keywords: if×21, return×10, do×2, goto×1, while×1, for×1.
//  - Notable callees: FUN_007a6de0×5, FUN_008f8200×5, CONCAT44×2, Client_SendInstantRepairRequest×2, Client_SendRespawnInSector×2, GetTickCount×2, block×2, Client_INC_ContactCountdownTick.
//  - Strings: "Contacting INC..."; "Contacting INC... Please do nothing for 5 more seconds!"; "INC Contact Established!  Initiating Repair Process..."; "You cannot afford the repair fee!".
//  - Return sites: 10.

// =============================================================================
// Client_INC_ContactCountdownTick
// -----------------------------------------------------------------------------
// Stable ID: aa_0091ee20
// Address:   0x0091ee20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

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

/* WARNING: Removing unreachable block (ram,0x0091f0c8) */

/* WARNING: Removing unreachable block (ram,0x0091f15d) */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

/* Client_INC_ContactCountdownTick - INC contact UI countdown.

   

   Option at this+0xc30:

     0 = repair station airlift -> Client_SendRespawnInSector (0x2073)

     1 = instant repair -> Client_SendInstantRepairRequest (0x20B6)

     2 = transfer (fee check)

   

   Shows "Contacting INC..." then option-specific success strings.

   Option 0 message: "INC Contact Established! Returning you to nearest repair station..." */



void Client_INC_ContactCountdownTick(void)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  DWORD DVar4;

  longlong lVar5;

  char *pcVar6;

  

  FUN_007a69d0();

  if (*(int *)(in_EAX + 0xc24) < 1) {

    return;

  }

  if (DAT_00d1b6d8 == 0) {

    return;

  }

  if (*(int *)(DAT_00d1b6d8 + 0x250) != 0) {

    cVar1 = '\0';

    do {

      iVar2 = *(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x260) + cVar1 * 4);

      if ((iVar2 != 0) && (*(char *)(iVar2 + 199) != '\0')) goto LAB_0091f1da;

      cVar1 = cVar1 + '\x01';

    } while (cVar1 < '\x03');

  }

  iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x1b0

                      ))();

  if ((((*(int *)(in_EAX + 0xc2c) <= iVar2) &&

       (*(float *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x138) <= _DAT_00aaabf4)) &&

      ((*(byte *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 0xb8 + DAT_00d1b6d8) & 0xc3) == 0)) &&

     ((iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                           0x19c))(), iVar2 != 0 &&

      (iVar2 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                           0x19c))(),

      (*(uint *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0x180 + iVar2) >> 3 & 1) == 0)))) {

    (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) + 0x19c))();

    cVar1 = FUN_005134e0();

    if ((cVar1 == '\0') && (*(char *)(DAT_00d1b6d8 + 0x6b9) == '\0')) {

      uVar3 = (**(code **)(*(int *)(*(int *)(*(int *)(DAT_00d1b6d8 + 4) + 4) + 4 + DAT_00d1b6d8) +

                          0x1b0))();

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc2c) = uVar3;

      DVar4 = GetTickCount();

      iVar2 = DVar4 - *(int *)(in_EAX + 0xc20);

      if ((((5000 < *(int *)(in_EAX + 0xc28)) && (5000 < *(int *)(in_EAX + 0xc24))) &&

          (*(int *)(in_EAX + 0xc24) - iVar2 < 0x1389)) &&

         (uVar3 = FUN_007a6de0("Contacting INC... Please do nothing for 5 more seconds!",0xffffffff)

         , DAT_00d1b8dc != 0)) {

        FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar3,0);

      }

      *(int *)(in_EAX + 0xc24) = *(int *)(in_EAX + 0xc24) - iVar2;

      DVar4 = GetTickCount();

      *(DWORD *)(in_EAX + 0xc20) = DVar4;

      if (*(int *)(in_EAX + 0xc24) < 0) {

        *(uint32_t /* width from decompiler */ *)(in_EAX + 0xc24) = 0;

      }

      if (((DAT_00d1b960 != (int *)0x0) &&

          (cVar1 = (**(code **)(*DAT_00d1b960 + 0x3d8))(), cVar1 != '\0')) &&

         (DAT_00d1b960[0x146] != 0)) {

        (**(code **)(*(int *)DAT_00d1b960[0x146] + 0x3b0))

                  (g_flOne - (float)*(int *)(in_EAX + 0xc24) / (float)*(int *)(in_EAX + 0xc28));

      }

      if (*(int *)(in_EAX + 0xc24) == 0) {

        iVar2 = *(int *)(in_EAX + 0xc30);

        if (iVar2 == 0) {

          uVar3 = FUN_007a6de0("INC Contact Established!  Returning you to nearest repair station..."

                               ,0xffffffff);

          if (DAT_00d1b8dc != 0) {

            FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar3,0);

          }

          Client_SendRespawnInSector();

          return;

        }

        if (iVar2 == 1) {

          if ((DAT_00d1b6d8 == 0) ||

             (lVar5 = FUN_0040ad20(),

             lVar5 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                               (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) <

                                     *(uint *)(DAT_00d1b6d8 + 0x728)),

                               *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))

          {

            uVar3 = FUN_007a6de0("INC Contact Established!  Initiating Repair Process...",0xffffffff

                                );

            if (DAT_00d1b8dc != 0) {

              FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar3,0);

            }

            Client_SendInstantRepairRequest();

            return;

          }

          pcVar6 = "You cannot afford the repair fee!";

        }

        else {

          if (iVar2 != 2) {

            return;

          }

          if (DAT_00d1b644 == 0) {

            return;

          }

          if (DAT_00d1b8c0 == 0) {

            return;

          }

          if (((*(int *)(DAT_00d1b8c0 + 0x544) == *(int *)(DAT_00d1b644 + 0xfc)) ||

              (DAT_00d1b6d8 == 0)) ||

             (lVar5 = FUN_0040ccb0(),

             lVar5 <= CONCAT44((*(int *)(DAT_00d1b6d8 + 0x724) - *(int *)(DAT_00d1b6d8 + 0x72c)) -

                               (uint)(*(uint *)(DAT_00d1b6d8 + 0x720) <

                                     *(uint *)(DAT_00d1b6d8 + 0x728)),

                               *(uint *)(DAT_00d1b6d8 + 0x720) - *(uint *)(DAT_00d1b6d8 + 0x728))))

          {

            uVar3 = FUN_007a6de0("INC Contact Established!  Initiating Transfer...",0xffffffff);

            if (DAT_00d1b8dc != 0) {

              FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,uVar3,0);

            }

            FUN_008ed650();

            return;

          }

          pcVar6 = "You cannot afford the transfer fee!";

        }

        uVar3 = FUN_007a6de0(pcVar6,0xffffffff);

        if (DAT_00d1b8dc != 0) {

          FUN_008f8200(DAT_00d1b8dc,0x18,&DAT_00a156cc,uVar3,0);

        }

      }

      return;

    }

  }

LAB_0091f1da:

  FUN_0091edd0(in_EAX);

  return;

}
