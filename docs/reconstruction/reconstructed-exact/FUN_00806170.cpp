// =============================================================================
// FUN_00806170
// -----------------------------------------------------------------------------
// Stable ID: aa_00806170
// Address:   0x00806170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00806170 @ 0x00806170
// Stable ID: aa_00806170
// Embedded strings (evidence for future rename):
//   - "Auto Assault"
//   - "Experience:"
//   - "Power"
//   - "Shields"
//   - "        "
//   - "Last Item"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~163 non-empty decompiler lines.
//  - Control keywords: return×5, if×5, do×4, while×4, switch×1.
//  - Notable callees: FUN_007a6de0×6, FUN_007a69d0, FUN_00806170, strncpy.
//  - Strings: "Auto Assault"; "Experience:"; "Power"; "Shields".
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

void FUN_00806170(void)



{

  int in_EAX;

  uint32_t /* width from decompiler */ uVar1;

  int *piVar2;

  int *piVar3;

  char *pcVar4;

  int iVar5;

  char *pcVar6;

  bool bVar7;

  int *piVar8;

  int iStack_4;

  

  FUN_007a69d0();

  piVar2 = (int *)(in_EAX + 0xb64);

  iVar5 = 3;

  piVar3 = piVar2;

  do {

    (**(code **)(*piVar3 + 0x2c))(0);

    piVar3 = piVar3 + 0x13;

    iVar5 = iVar5 + -1;

  } while (iVar5 != 0);

  piVar3 = (int *)(in_EAX + 0x70);

  iStack_4 = 4;

  piVar8 = piVar3;

  do {

    (**(code **)(*piVar8 + 0x2c))(0);

    (**(code **)(*piVar8 + 0x88))(0);

    (**(code **)(*piVar8 + 0x74))(8);

    piVar8 = piVar8 + 0x5c;

    iStack_4 = iStack_4 + -1;

  } while (iStack_4 != 0);

  piVar8 = (int *)(in_EAX + 0x670);

  iStack_4 = 4;

  do {

    (**(code **)(*piVar8 + 0x2c))(0);

    piVar8 = piVar8 + 0xf;

    iStack_4 = iStack_4 + -1;

  } while (iStack_4 != 0);

  (**(code **)(*(int *)(in_EAX + 0x630) + 0x2c))(0);

  (**(code **)(*(int *)(in_EAX + 0x8f8) + 0x2c))(0);

  piVar8 = (int *)0x0;

  (**(code **)(*(int *)(in_EAX + 0x760) + 0x2c))();

  switch(*(uint8_t *)(in_EAX + 0xd1c)) {

  case 0:

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcd4) = 0xff;

    (**(code **)(*piVar3 + 0x2c))(1);

    (**(code **)(*piVar3 + 0xa4))(1);

    (**(code **)(*piVar3 + 0xc))(0,0);

    iVar5 = *piVar3;

    uVar1 = FUN_007a6de0("Auto Assault",0xffffffff);

    (**(code **)(iVar5 + 0x80))(uVar1);

    (**(code **)(*piVar8 + 0x2c))(1);

    return;

  case 1:

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcd4) = 0x80;

    (**(code **)(*piVar3 + 0xc))(0,0);

    (**(code **)(*piVar3 + 0xa4))(0);

    (**(code **)(*piVar3 + 0x2c))(1);

    piVar2 = (int *)(in_EAX + 0x1e0);

    (**(code **)(*(int *)(in_EAX + 0x1e0) + 0xc))(0,0xf);

    (**(code **)(*piVar2 + 0xa4))(0);

    iVar5 = *piVar2;

    uVar1 = FUN_007a6de0("Experience:",0xffffffff);

    (**(code **)(iVar5 + 0x80))(uVar1);

    (**(code **)(*piVar2 + 0x2c))(1);

    piVar2 = (int *)(in_EAX + 0xbb0);

    (**(code **)(*(int *)(in_EAX + 0xbb0) + 0xc))(0x46,0x14);

    (**(code **)(*piVar2 + 0x70))(0,1000);

    (**(code **)(*piVar2 + 0x18))(0x4b,5);

    (**(code **)(*piVar2 + 0x2c))(1);

    (**(code **)(*(int *)(in_EAX + 0x350) + 0xc))(0,0x1e);

    (**(code **)(*(int *)(in_EAX + 0x350) + 0xa4))(0);

    (**(code **)(*(int *)(in_EAX + 0x350) + 0x2c))(1);

    return;

  case 2:

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcd4) = 0x80;

    (**(code **)(*piVar3 + 0x2c))(1);

    (**(code **)(*piVar3 + 0xa4))(0);

    (**(code **)(*piVar3 + 0xc))(0,0);

    iVar5 = *piVar3;

    uVar1 = FUN_007a6de0(&DAT_00a2dbbc,0xffffffff);

    (**(code **)(iVar5 + 0x80))(uVar1);

    (**(code **)(*piVar2 + 0x2c))(1);

    (**(code **)(*piVar2 + 0x70))(0,100);

    (**(code **)(*piVar2 + 0x18))(100,5);

    (**(code **)(*piVar2 + 0xc))(0x32,5);

    piVar2 = (int *)(in_EAX + 0x1e0);

    (**(code **)(*(int *)(in_EAX + 0x1e0) + 0x2c))(1);

    (**(code **)(*piVar2 + 0xc))(0,0xf);

    (**(code **)(*piVar2 + 0xa4))(0);

    iVar5 = *piVar2;

    uVar1 = FUN_007a6de0("Power",0xffffffff);

    (**(code **)(iVar5 + 0x80))(uVar1);

    piVar2 = (int *)(in_EAX + 0xbb0);

    (**(code **)(*(int *)(in_EAX + 0xbb0) + 0x2c))(1);

    (**(code **)(*piVar2 + 0x70))(0,100);

    (**(code **)(*piVar2 + 0xc))(0x32,0x14);

    (**(code **)(*piVar2 + 0x18))(100,5);

    if (*(int *)(*(int *)(DAT_00d1b6d8 + 0x250) + 0x148) != 0) {

      piVar2 = (int *)(in_EAX + 0x350);

      (**(code **)(*(int *)(in_EAX + 0x350) + 0xa4))(0);

      (**(code **)(*piVar2 + 0x2c))(1);

      (**(code **)(*piVar2 + 0xc))(0,0x1e);

      iVar5 = *piVar2;

      uVar1 = FUN_007a6de0("Shields",0xffffffff);

      (**(code **)(iVar5 + 0x80))(uVar1);

      piVar2 = (int *)(in_EAX + 0xbfc);

      (**(code **)(*(int *)(in_EAX + 0xbfc) + 0x2c))(1);

      (**(code **)(*piVar2 + 0x70))(0,100);

      (**(code **)(*piVar2 + 0x18))(100,5);

      (**(code **)(*piVar2 + 0xc))(0x32,0x23);

      return;

    }

    break;

  case 3:

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcd4) = 0x80;

    (**(code **)(*(int *)(in_EAX + 0x8f8) + 0xc))(0,0);

    (**(code **)(*(int *)(in_EAX + 0x8f8) + 0x2c))(1);

    uVar1 = DAT_00b00228;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x940) = DAT_00b0022c;

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0x944) = uVar1;

    iVar5 = 9;

    bVar7 = true;

    pcVar4 = (char *)(in_EAX + 0xa58);

    pcVar6 = "        ";

    do {

      if (iVar5 == 0) break;

      iVar5 = iVar5 + -1;

      bVar7 = *pcVar4 == *pcVar6;

      pcVar4 = pcVar4 + 1;

      pcVar6 = pcVar6 + 1;

    } while (bVar7);

    if (!bVar7) {

      strncpy((char *)(in_EAX + 0xa58),"        ",0x100);

      *(uint32_t /* width from decompiler */ *)(in_EAX + 0x950) = 1;

    }

    if (DAT_00d1b8c8 != 0) {

      piVar2 = (int *)(in_EAX + 0x1e0);

      (**(code **)(*(int *)(in_EAX + 0x1e0) + 0xa4))(1);

      (**(code **)(*piVar2 + 0x88))(1);

      (**(code **)(*piVar2 + 0xc))(0,0xf);

      (**(code **)(*piVar2 + 0x2c))(1);

      return;

    }

    break;

  case 4:

    *(uint32_t /* width from decompiler */ *)(in_EAX + 0xcd4) = 0x80;

    (**(code **)(*piVar3 + 0xc))(0,0);

    (**(code **)(*piVar3 + 0xa4))(1);

    (**(code **)(*piVar3 + 0x2c))(1);

    iVar5 = *piVar3;

    uVar1 = FUN_007a6de0("Last Item",0xffffffff);

    (**(code **)(iVar5 + 0x80))(uVar1);

    if (DAT_00d1b8d8 != 0) {

      piVar2 = (int *)(in_EAX + 0x1e0);

      (**(code **)(*(int *)(in_EAX + 0x1e0) + 0x88))(1);

      (**(code **)(*piVar2 + 0xa4))(1);

      (**(code **)(*piVar2 + 0xc))(0,0xf);

      (**(code **)(*piVar2 + 0x2c))(1);

    }

  }

  return;

}
