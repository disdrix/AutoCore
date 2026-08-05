// READABILITY (auto CF):
//  - Body size: ~69 non-empty decompiler lines.
//  - Control keywords: if×10, return×3, for×2, while×1.
//  - Notable callees: FUN_007a4480×4, FUN_007a69d0×3, FUN_007a6de0×3, FUN_0080f7a0, FUN_008f8200, FUN_0092fd00, sprintf.
//  - Strings: "HashError:TraversalLock, already locked for traversal"; "VOG_DEBUG_STOP"; "HashError:TraverseToNext, not locked for traversal"; "has changed your active mission to".
//  - Return sites: 3.

// =============================================================================
// Client_NotifyConvoyActiveMissionChanged
// -----------------------------------------------------------------------------
// Purpose:  Alternate path for convoy-leader active-mission change notification.
//
// Address:  0x0080f7a0  (autoassault.exe, image base 0x400000)
// Stable:   aa_0080f7a0
// System:   missions-progression
//
// String evidence: "has changed your active mission to" / "Your Convoy Leader"
//
// Exactness: Behavior-preserving rewrite of decompiler control flow (scaffold).
// Bit-for-bit vs retail EXE: DEFERRED.
// Source:    Prefer over FUN_0080f7a0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes:
 * - Renamed from FUN_0080f7a0 using string evidence: "has changed your active mission to" / "Your Convoy Leader"
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 */

void Client_NotifyConvoyActiveMissionChanged(int param_1)

{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int iVar2;

  int iVar3;

  char *pcVar4;

  uint32_t /* width from decompiler */ uVar5;

  char local_100 [256];

  

  if ((*(int *)(in_EAX + 0xe98) == 0) ||

     (iVar3 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x548), iVar3 == 0)) {

    *(uint *)(in_EAX + 0x4d4) = (uint)*(ushort *)(param_1 + 0x10);

    return;

  }

  iVar2 = 0;

  if (*(char *)(iVar3 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:TraversalLock, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  *(uint8_t *)(iVar3 + 0x1d) = 1;

  while( true ) {

    iVar3 = *(int *)(*(int *)(in_EAX + 0xe98) + 0x548);

    if (*(char *)(iVar3 + 0x1d) == '\0') {

      FUN_007a4480(0,"HashError:TraverseToNext, not locked for traversal");

      FUN_007a4480(0,"VOG_DEBUG_STOP");

    }

    if (iVar2 == 0) {

      iVar2 = *(int *)(iVar3 + 0x14);

    }

    else {

      iVar2 = *(int *)(iVar2 + 0x14);

    }

    if (iVar2 == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar2 + 8);

    }

    if (iVar3 == 0) break;

    if ((*(uint **)(iVar3 + 0x14c) != (uint *)0x0) &&

       (**(uint **)(iVar3 + 0x14c) == (uint)*(ushort *)(param_1 + 0x10))) {

      *(uint8_t *)(*(int *)(*(int *)(in_EAX + 0xe98) + 0x548) + 0x1d) = 0;

      if (*(int *)(*(int *)(in_EAX + 0x4d0) + 0x10) != *(int *)(iVar3 + 0x10)) {

        FUN_0092fd00();

        if (*(int *)(*(int *)(in_EAX + 0x4d0) + 0x10) == *(int *)(iVar3 + 0x10)) {

          uVar1 = *(uint32_t /* width from decompiler */ *)(*(int *)(iVar3 + 0x14c) + 0x14c);

          uVar5 = 0xffffffff;

          FUN_007a69d0(uVar1,0xffffffff);

          uVar1 = FUN_007a6de0(uVar1,uVar5);

          uVar5 = 0xffffffff;

          pcVar4 = "has changed your active mission to";

          FUN_007a69d0("has changed your active mission to",0xffffffff,uVar1);

          uVar1 = FUN_007a6de0(pcVar4,uVar5);

          uVar5 = 0xffffffff;

          pcVar4 = "Your Convoy Leader";

          FUN_007a69d0("Your Convoy Leader",0xffffffff,uVar1);

          uVar1 = FUN_007a6de0(pcVar4,uVar5);

          sprintf(local_100,"%s %s \"%s.\"",uVar1);

          if (DAT_00d1b8dc != 0) {

            FUN_008f8200(DAT_00d1b8dc,6,&DAT_00a156cc,local_100,0);

          }

        }

      }

      return;

    }

  }

  *(uint8_t *)(*(int *)(*(int *)(in_EAX + 0xe98) + 0x548) + 0x1d) = 0;

  return;

}
