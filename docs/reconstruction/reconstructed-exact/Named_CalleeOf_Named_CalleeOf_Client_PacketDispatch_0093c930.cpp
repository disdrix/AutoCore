// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0093c930
// -----------------------------------------------------------------------------
// Stable ID: aa_0093c930
// Callee of Named_CalleeOf_Client_PacketDispatch
// Address:   0x0093c930  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Called from Named_CalleeOf_Client_PacketDispatch: packet/network helper. Evidence string: "Error: Your convoy member ". Supports parent flow (not a free-standing entry point).
// Embedded strings (evidence):
//   - "Error: Your convoy member "
//   - "Unknown Member"
//   - " doesn\'t meet the requirements."
//   - "Error: InvalidTournament"
//   - "Error: The tournament is full!"
//   - "Error: Too many members of your team have registered!"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~469 non-empty decompiler lines.
//  - Control keywords: do×35, while×35, if×22, for×17, return×10, goto×7, switch×1.
//  - Notable callees: FUN_007a6de0×21, FUN_00574760×4, FUN_0093a0c0×3, sprintf×2, FUN_007a69d0, FUN_007fdfb0, FUN_0086b3c0, FUN_0093c930.
//  - Strings: "Error: Your convoy member "; "Unknown Member"; " doesn\'t meet the requirements."; "Error: InvalidTournament".
//  - Return sites: 10.

/*
 * Behavioral notes:
 * Callee of Named_CalleeOf_Client_PacketDispatch
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

void __thiscall

Named_CalleeOf_Named_CalleeOf_Client_PacketDispatch_0093c930(char param_1,int param_2,ushort param_3,byte param_4,byte param_5,byte param_6)



{

  int *piVar1;

  char cVar2;

  int in_EAX;

  uint uVar3;

  int iVar4;

  char *pcVar5;

  uint uVar6;

  char *pcVar7;

  int *piVar8;

  char *pcVar9;

  char *pcVar10;

  char acStack_114 [15];

  char cStack_105;

  char acStack_104 [260];

  

  piVar1 = *(int **)(param_2 + 0x10d0);

  if (param_1 == '\0') {

    FUN_0093a0c0();

    if (piVar1 == (int *)0x0) {

      return;

    }

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    piVar1[0x155] = in_EAX;

    piVar1[0x154] = 0;

    piVar1[0x156] = (uint)param_3;

    *(ushort *)(piVar1 + 0x157) = (ushort)param_4;

    *(ushort *)((int)piVar1 + 0x55e) = (ushort)param_5;

    return;

  }

  if (param_1 == '\r') {

    FUN_0093a0c0();

    if (piVar1 == (int *)0x0) {

      return;

    }

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    piVar1[0x155] = in_EAX;

    piVar1[0x154] = 0x7fffffff;

    piVar1[0x156] = (uint)param_3;

    *(ushort *)(piVar1 + 0x157) = (ushort)param_4;

    *(ushort *)((int)piVar1 + 0x55e) = (ushort)param_5;

    return;

  }

  if (param_1 == '\n') {

    FUN_0093a0c0();

    if (piVar1 == (int *)0x0) {

      return;

    }

    cVar2 = (**(code **)(*piVar1 + 0x3d8))();

    if (cVar2 == '\0') {

      return;

    }

    piVar1[0x156] = 0;

    *(uint16_t *)(piVar1 + 0x157) = 0;

    *(uint16_t *)((int)piVar1 + 0x55e) = 0;

    piVar1[0x154] = (uint)param_3;

    return;

  }

  *(uint8_t *)(*(int *)(param_2 + 0xe98) + 0x4fc) = 0;

  if ((piVar1 != (int *)0x0) && (cVar2 = (**(code **)(*piVar1 + 0x3d8))(), cVar2 != '\0')) {

    FUN_0086b3c0();

  }

  FUN_007a69d0();

  uVar3 = (uint)param_6;

  if (param_6 == 0) {

    uVar3 = (uint)param_1;

  }

  switch(uVar3) {

  case 1:

    iVar4 = *(int *)(param_2 + 0xe98);

    if (*(int *)(iVar4 + 0xcb0) != 0) {

      iVar4 = FUN_00574760(param_3);

    }

    pcVar5 = (char *)FUN_007a6de0("Error: Your convoy member ",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    if (iVar4 == 0) {

      pcVar5 = (char *)FUN_007a6de0("Unknown Member",0xffffffff);

      pcVar7 = pcVar5;

    }

    else {

      pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160)

                       )();

      pcVar7 = pcVar5;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    pcVar10 = &cStack_105;

    do {

      pcVar9 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar7;

    for (uVar3 = (uint)((int)pcVar5 - (int)pcVar7) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar3 = (int)pcVar5 - (int)pcVar7 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar10 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    }

    pcVar5 = (char *)FUN_007a6de0(" doesn\'t meet the requirements.",0xffffffff);

    pcVar7 = pcVar5;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    uVar3 = (int)pcVar7 - (int)pcVar5;

    pcVar7 = &cStack_105;

    do {

      pcVar10 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar10 != '\0');

    goto LAB_0093d09e;

  case 2:

    pcVar5 = (char *)FUN_007a6de0("Error: InvalidTournament",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 3:

    pcVar5 = (char *)FUN_007a6de0("Error: The tournament is full!",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 4:

    pcVar5 = (char *)FUN_007a6de0("Error: Too many members of your team have registered!",0xffffffff

                                 );

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 5:

    piVar8 = *(int **)piVar1[0x159];

    if (piVar8 != (int *)piVar1[0x159]) {

LAB_0093cc36:

      if (*(int *)piVar8[2] != in_EAX) goto code_r0x0093cc3d;

      pcVar5 = (char *)FUN_007a6de0("Error: Your convoy must be between ",0xffffffff);

      pcVar7 = acStack_104;

      do {

        cVar2 = *pcVar5;

        *pcVar7 = cVar2;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      sprintf(acStack_114,"%d",*(uint32_t /* width from decompiler */ *)(piVar8[2] + 0x2a4));

      pcVar7 = acStack_114;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar3 = (int)pcVar7 - (int)acStack_114;

      pcVar7 = &cStack_105;

      do {

        pcVar5 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = acStack_114;

      for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar7 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      }

      pcVar5 = (char *)FUN_007a6de0(" and ",0xffffffff);

      pcVar7 = pcVar5;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      pcVar10 = &cStack_105;

      do {

        pcVar9 = pcVar10 + 1;

        pcVar10 = pcVar10 + 1;

      } while (*pcVar9 != '\0');

      pcVar9 = pcVar5;

      for (uVar3 = (uint)((int)pcVar7 - (int)pcVar5) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

        pcVar9 = pcVar9 + 4;

        pcVar10 = pcVar10 + 4;

      }

      for (uVar3 = (int)pcVar7 - (int)pcVar5 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar10 = *pcVar9;

        pcVar9 = pcVar9 + 1;

        pcVar10 = pcVar10 + 1;

      }

      sprintf(acStack_114,"%d",*(uint32_t /* width from decompiler */ *)(piVar8[2] + 0x2a8));

      pcVar7 = acStack_114;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar3 = (int)pcVar7 - (int)acStack_114;

      pcVar7 = &cStack_105;

      do {

        pcVar5 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = acStack_114;

      for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

        *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        pcVar7 = pcVar7 + 4;

      }

      for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

        *pcVar7 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        pcVar7 = pcVar7 + 1;

      }

      pcVar5 = (char *)FUN_007a6de0(" members.",0xffffffff);

      pcVar7 = pcVar5;

      do {

        cVar2 = *pcVar7;

        pcVar7 = pcVar7 + 1;

      } while (cVar2 != '\0');

      uVar3 = (int)pcVar7 - (int)pcVar5;

      pcVar7 = &cStack_105;

      do {

        pcVar10 = pcVar7 + 1;

        pcVar7 = pcVar7 + 1;

      } while (*pcVar10 != '\0');

      goto LAB_0093d09e;

    }

LAB_0093cc47:

    pcVar5 = (char *)FUN_007a6de0("Error: Your team size is incorrect!",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 6:

    iVar4 = *(int *)(param_2 + 0xe98);

    if (*(int *)(iVar4 + 0xcb0) != 0) {

      iVar4 = FUN_00574760(param_3);

    }

    pcVar5 = (char *)FUN_007a6de0("Error: Your convoy member ",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    if (iVar4 == 0) {

      pcVar5 = (char *)FUN_007a6de0("Unknown Member",0xffffffff);

      pcVar7 = pcVar5;

    }

    else {

      pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160)

                       )();

      pcVar7 = pcVar5;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    pcVar10 = &cStack_105;

    do {

      pcVar9 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar7;

    for (uVar3 = (uint)((int)pcVar5 - (int)pcVar7) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar3 = (int)pcVar5 - (int)pcVar7 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar10 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    }

    pcVar5 = (char *)FUN_007a6de0(" doesn\'t meet the requirements.",0xffffffff);

    pcVar7 = pcVar5;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    uVar3 = (int)pcVar7 - (int)pcVar5;

    pcVar7 = &cStack_105;

    do {

      pcVar10 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar10 != '\0');

    goto LAB_0093d09e;

  case 7:

    pcVar5 = (char *)FUN_007a6de0("Error: You are not the convoy leader!",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 8:

    pcVar5 = (char *)FUN_007a6de0("Error: Already registered for a tournament!",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    break;

  case 0xb:

    iVar4 = *(int *)(param_2 + 0xe98);

    if (*(int *)(iVar4 + 0xcb0) != 0) {

      iVar4 = FUN_00574760(param_3);

    }

    pcVar5 = (char *)FUN_007a6de0("Error: Your convoy member ",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    if (iVar4 == 0) {

      pcVar5 = (char *)FUN_007a6de0("Unknown Member",0xffffffff);

      pcVar7 = pcVar5;

    }

    else {

      pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160)

                       )();

      pcVar7 = pcVar5;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    pcVar10 = &cStack_105;

    do {

      pcVar9 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar7;

    for (uVar3 = (uint)((int)pcVar5 - (int)pcVar7) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar3 = (int)pcVar5 - (int)pcVar7 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar10 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    }

    pcVar5 = (char *)FUN_007a6de0(" refused to enter",0xffffffff);

    pcVar7 = pcVar5;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    uVar3 = (int)pcVar7 - (int)pcVar5;

    pcVar7 = &cStack_105;

    do {

      pcVar10 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar10 != '\0');

    goto LAB_0093d09e;

  case 0xc:

    iVar4 = *(int *)(param_2 + 0xe98);

    if (*(int *)(iVar4 + 0xcb0) != 0) {

      iVar4 = FUN_00574760(param_3);

    }

    pcVar5 = (char *)FUN_007a6de0("Error: Your convoy member ",0xffffffff);

    pcVar7 = acStack_104;

    do {

      cVar2 = *pcVar5;

      *pcVar7 = cVar2;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    if (iVar4 == 0) {

      pcVar5 = (char *)FUN_007a6de0("Unknown Member",0xffffffff);

      pcVar7 = pcVar5;

    }

    else {

      pcVar5 = (char *)(**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x160)

                       )();

      pcVar7 = pcVar5;

    }

    do {

      cVar2 = *pcVar5;

      pcVar5 = pcVar5 + 1;

    } while (cVar2 != '\0');

    pcVar10 = &cStack_105;

    do {

      pcVar9 = pcVar10 + 1;

      pcVar10 = pcVar10 + 1;

    } while (*pcVar9 != '\0');

    pcVar9 = pcVar7;

    for (uVar3 = (uint)((int)pcVar5 - (int)pcVar7) >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar10 = *(uint32_t /* width from decompiler */ *)pcVar9;

      pcVar9 = pcVar9 + 4;

      pcVar10 = pcVar10 + 4;

    }

    for (uVar3 = (int)pcVar5 - (int)pcVar7 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar10 = *pcVar9;

      pcVar9 = pcVar9 + 1;

      pcVar10 = pcVar10 + 1;

    }

    pcVar5 = (char *)FUN_007a6de0(" cannot join the tournament.",0xffffffff);

    pcVar7 = pcVar5;

    do {

      cVar2 = *pcVar7;

      pcVar7 = pcVar7 + 1;

    } while (cVar2 != '\0');

    uVar3 = (int)pcVar7 - (int)pcVar5;

    pcVar7 = &cStack_105;

    do {

      pcVar10 = pcVar7 + 1;

      pcVar7 = pcVar7 + 1;

    } while (*pcVar10 != '\0');

LAB_0093d09e:

    for (uVar6 = uVar3 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar7 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      pcVar7 = pcVar7 + 4;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar7 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      pcVar7 = pcVar7 + 1;

    }

  }

  FUN_007fdfb0(param_2,acStack_104,0xffffffff,1,0);

  return;

code_r0x0093cc3d:

  piVar8 = (int *)*piVar8;

  if (piVar8 == (int *)piVar1[0x159]) goto LAB_0093cc47;

  goto LAB_0093cc36;

}
