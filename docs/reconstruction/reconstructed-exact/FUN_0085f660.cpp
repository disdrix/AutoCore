// =============================================================================
// FUN_0085f660
// -----------------------------------------------------------------------------
// Stable ID: aa_0085f660
// Address:   0x0085f660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0085f660 @ 0x0085f660
// Stable ID: aa_0085f660
// Embedded strings (evidence for future rename):
//   - "Attempting to tinker this item may result in its destruction. You have a %.02f %% chance o"
//   - "The object has no available slots to open."
//   - "You do not possess the Tinkering skill to work on this object."
//   - "This Tinkering Kit is too primitive to use on this object."
//   - "Power Plants"
//   - "Other"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~158 non-empty decompiler lines.
//  - Control keywords: do×9, while×8, return×6, if×2, switch×2.
//  - Notable callees: FUN_007a69d0×10, FUN_007a6de0×10, FUN_007fdfb0×6, sprintf×2, FUN_00513c10, FUN_00521f20, FUN_0085f660.
//  - Strings: "

    ;

    FUN_007a69d0("; "The object has no available slots to open."; "This Tinkering Kit is too primitive to use on this object."; "Power Plants".
//  - Return sites: 6.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void __fastcall FUN_0085f660(int param_1)



{

  char cVar1;

  int in_EAX;

  int iVar2;

  char *pcVar3;

  float10 fVar4;

  char *pcVar5;

  uint32_t /* width from decompiler */ uVar6;

  uint64_t uVar7;

  char local_300 [256];

  char local_200 [512];

  

  iVar2 = FUN_00513c10(DAT_00d1b6d8,param_1);

  if (iVar2 == 4) {

    iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);

    _DAT_00d1d918 = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x164 + param_1);

    _DAT_00d1d91c = *(uint32_t /* width from decompiler */ *)(iVar2 + 0x168 + param_1);

    _DAT_00d1d920 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x160);

    _DAT_00d1d924 = *(uint32_t /* width from decompiler */ *)(in_EAX + 0x164);

    fVar4 = (float10)FUN_00521f20(in_EAX,param_1);

    uVar6 = 0xffffffff;

    pcVar5 = 

    "Attempting to tinker this item may result in its destruction. You have a %.02f %% chance of success."

    ;

    FUN_007a69d0("Attempting to tinker this item may result in its destruction. You have a %.02f %% chance of success."

                 ,0xffffffff,(double)(fVar4 * (float10)DAT_00aaa7ac));

    pcVar5 = (char *)FUN_007a6de0(pcVar5,uVar6);

    sprintf(local_300,pcVar5);

    FUN_007fdfb0(&DAT_00d1a840,local_300,0x4e4f,1,0);

    return;

  }

  if ((*(uint *)(in_EAX + 0x17c) >> 0x13 & 1) == 0) {

    _DAT_00d1d918 = 0xffffffff;

    _DAT_00d1d91c = 0xffffffff;

    _DAT_00d1d920 = 0xffffffff;

    _DAT_00d1d924 = 0xffffffff;

    switch(iVar2) {

    case 0:

      FUN_007fdfb0(&DAT_00d1a840,"The object has no available slots to open.",0xffffffff,1,0);

      return;

    case 1:

      FUN_007fdfb0(&DAT_00d1a840,"You do not possess the Tinkering skill to work on this object.",

                   0xffffffff,1,0);

      return;

    case 2:

      FUN_007fdfb0(&DAT_00d1a840,"This Tinkering Kit is too primitive to use on this object.",

                   0xffffffff,1,0);

      return;

    case 3:

      switch(*(uint32_t /* width from decompiler */ *)(param_1 + 0xb4)) {

      case 10:

        uVar7 = 0xffffffff00a64cc8;

        FUN_007a69d0("Power Plants");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      default:

        uVar7 = 0xffffffff00a2da84;

        FUN_007a69d0("Other");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0xc:

        uVar7 = 0xffffffff00a64cc0;

        FUN_007a69d0("Weapons");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0xe:

        uVar7 = 0xffffffff00a64cb4;

        FUN_007a69d0("Vehicles");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0x10:

        uVar7 = 0xffffffff00a64ca8;

        FUN_007a69d0("Wheelsets");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0x1c:

        uVar7 = 0xffffffff00a2e6a4;

        FUN_007a69d0("Armor");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0x44:

        uVar7 = 0xffffffff00a2e670;

        FUN_007a69d0("Ornament");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

        break;

      case 0x46:

        uVar7 = 0xffffffff00a57e4c;

        FUN_007a69d0("Hazard Kit");

        pcVar3 = (char *)FUN_007a6de0(uVar7);

        pcVar5 = local_300;

        do {

          cVar1 = *pcVar3;

          *pcVar5 = cVar1;

          pcVar3 = pcVar3 + 1;

          pcVar5 = pcVar5 + 1;

        } while (cVar1 != '\0');

      }

      pcVar5 = "This Tinkering Kit can only be used on %s.";

      FUN_007a69d0("This Tinkering Kit can only be used on %s.",0xffffffff);

      pcVar5 = (char *)FUN_007a6de0(pcVar5);

      sprintf(local_200,pcVar5);

      FUN_007fdfb0(&DAT_00d1a840,local_200,0xffffffff,1,0);

    }

    return;

  }

  FUN_007fdfb0(&DAT_00d1a840,"You cannot use Tinkering Kits on Broken Items!",0xffffffff,1,0);

  return;

}
