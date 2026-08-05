// =============================================================================
// FUN_0080c5e0
// -----------------------------------------------------------------------------
// Stable ID: aa_0080c5e0
// Address:   0x0080c5e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0080c5e0 @ 0x0080c5e0
// Stable ID: aa_0080c5e0
// Embedded strings (evidence for future rename):
//   - "General failure"
//   - "You are already in an arena match"
//   - "That arena is already full"
//   - "Invalid password entered"
//   - "Your class is not allowed"
//   - "Your race is not allowed"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~244 non-empty decompiler lines.
//  - Control keywords: do×15, while×15, if×8, return×8, for×3, switch×1.
//  - Notable callees: FUN_007a6de0×20, sprintf×3, FUN_00937150×2, CARRY4, Client_LookupObjectByTfid_Inferred, FUN_007a69d0, FUN_007fca10, FUN_007fdfb0.
//  - Strings: "General failure"; "You are already in an arena match"; "That arena is already full"; "Invalid password entered".
//  - Return sites: 8.

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

void FUN_0080c5e0(int param_1)



{

  uint *puVar1;

  uint uVar2;

  int *piVar3;

  uint uVar4;

  int iVar5;

  char cVar6;

  int in_EAX;

  void *pvVar7;

  uint32_t /* width from decompiler */ uVar8;

  uint32_t /* width from decompiler */ uVar9;

  char *pcVar10;

  uint32_t /* width from decompiler */ uVar11;

  char *pcVar12;

  uint64_t uVar13;

  char local_208 [260];

  char acStack_104 [260];

  

  if (*(int *)(param_1 + 0xe98) == 0) {

    return;

  }

  FUN_007a69d0();

  piVar3 = *(int **)(param_1 + 0x10c0);

  switch(*(uint32_t /* width from decompiler */ *)(in_EAX + 0xc0)) {

  case 0:

    iVar5 = *(int *)(param_1 + 0xe98);

    uVar4 = *(uint *)(in_EAX + 0x10);

    puVar1 = (uint *)(iVar5 + 0x728);

    uVar2 = *puVar1;

    *puVar1 = *puVar1 + uVar4;

    piVar3 = (int *)(iVar5 + 0x72c);

    *piVar3 = *piVar3 + *(int *)(in_EAX + 0x14) + (uint)CARRY4(uVar2,uVar4);

    FUN_00937150();

    piVar3 = *(int **)(param_1 + 0x10c0);

    if (piVar3 == (int *)0x0) {

      return;

    }

    cVar6 = (**(code **)(*piVar3 + 0x3d8))();

    if (cVar6 == '\0') {

      return;

    }

    iVar5 = *(int *)(in_EAX + 0x18);

    piVar3[0x151] = 0;

    piVar3[0x152] = iVar5;

    return;

  default:

    pcVar10 = (char *)FUN_007a6de0("General failure",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 2:

    pcVar10 = (char *)FUN_007a6de0("You are already in an arena match",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 3:

    pcVar10 = (char *)FUN_007a6de0("That arena is already full",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 4:

    pcVar10 = (char *)FUN_007a6de0("Invalid password entered",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 5:

    pcVar10 = (char *)FUN_007a6de0("Your class is not allowed",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 6:

    pcVar10 = (char *)FUN_007a6de0("Your race is not allowed",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 7:

    pcVar10 = (char *)FUN_007a6de0("You are ranked too high",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 8:

    uVar13 = (**(code **)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0xe98) + 4) + 4) + 4 +

                                  *(int *)(param_1 + 0xe98)) + 0x16c))();

    uVar11 = FUN_007a6de0("Your total value is too high",0xffffffff);

    sprintf(local_208,"%s: %I64d",uVar11,(int)uVar13,(int)((ulonglong)uVar13 >> 0x20));

    break;

  case 9:

    pcVar10 = (char *)FUN_007a6de0("You are too high of level",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 10:

    pcVar10 = (char *)FUN_007a6de0("You don\'t have enough money",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 0xb:

    pcVar10 = (char *)FUN_007a6de0("No available spectator tickets",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 0xc:

    pcVar10 = (char *)FUN_007a6de0("You are not the convoy leader",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 0xd:

    pvVar7 = Client_LookupObjectByTfid_Inferred(1,*(uint *)(in_EAX + 8),*(uint *)(in_EAX + 0xc));

    if (pvVar7 == (void *)0x0) {

      uVar11 = FUN_007a6de0("Unknown Member",0xffffffff);

    }

    else {

      uVar11 = (**(code **)(*(int *)(*(int *)(*(int *)((int)pvVar7 + 4) + 4) + 4 + (int)pvVar7) +

                           0x160))();

    }

    uVar8 = FUN_007a6de0("refused to enter",0xffffffff);

    uVar9 = FUN_007a6de0("Your convoy member",0xffffffff);

    sprintf(local_208,"%s %s %s",uVar9,uVar11,uVar8);

    FUN_007fca10();

    break;

  case 0xe:

    if ((*(uint *)(*(int *)(param_1 + 0xe98) + 0xca8) & *(uint *)(*(int *)(param_1 + 0xe98) + 0xcac)

        ) == 0xffffffff) {

      pcVar10 = (char *)FUN_007a6de0("You need a convoy for this match",0xffffffff);

      pcVar12 = local_208;

      do {

        cVar6 = *pcVar10;

        *pcVar12 = cVar6;

        pcVar10 = pcVar10 + 1;

        pcVar12 = pcVar12 + 1;

      } while (cVar6 != '\0');

    }

    else {

      pcVar10 = (char *)FUN_007a6de0("Convoy is incorrect size for this match",0xffffffff);

      pcVar12 = local_208;

      do {

        cVar6 = *pcVar10;

        *pcVar12 = cVar6;

        pcVar10 = pcVar10 + 1;

        pcVar12 = pcVar12 + 1;

      } while (cVar6 != '\0');

    }

    break;

  case 0x10:

    pcVar10 = (char *)FUN_007a6de0("Not all convoy members are present",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 0x11:

    pcVar10 = (char *)FUN_007a6de0("You cannot be in a convoy for this match",0xffffffff);

    pcVar12 = local_208;

    do {

      cVar6 = *pcVar10;

      *pcVar12 = cVar6;

      pcVar10 = pcVar10 + 1;

      pcVar12 = pcVar12 + 1;

    } while (cVar6 != '\0');

    break;

  case 0x12:

    FUN_00937150();

    piVar3 = *(int **)(param_1 + 0x10c0);

    if (piVar3 == (int *)0x0) {

      return;

    }

    cVar6 = (**(code **)(*piVar3 + 0x3d8))();

    if (cVar6 == '\0') {

      return;

    }

    iVar5 = *(int *)(in_EAX + 0x18);

    piVar3[0x152] = 0;

    piVar3[0x151] = iVar5;

    return;

  }

  if ((piVar3 != (int *)0x0) && (cVar6 = (**(code **)(*piVar3 + 0x3d8))(), cVar6 != '\0')) {

    (**(code **)(*(int *)piVar3[0x15e] + 0xd4))(1);

    (**(code **)(*(int *)piVar3[0x15e] + 0x34c))();

  }

  pcVar12 = local_208;

  uVar11 = FUN_007a6de0("Failed to enter the arena",0xffffffff);

  sprintf(acStack_104,"%s: %s.",uVar11,pcVar12);

  *(uint8_t *)(*(int *)(param_1 + 0xe98) + 0x4fc) = 0;

  FUN_007fdfb0(param_1,acStack_104,0xffffffff,1,0);

  return;

}
