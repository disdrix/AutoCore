// =============================================================================
// FUN_004fcd80
// -----------------------------------------------------------------------------
// Stable ID: aa_004fcd80
// Address:   0x004fcd80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004fcd80 @ 0x004fcd80
// Stable ID: aa_004fcd80
// Embedded strings (evidence for future rename):
//   - "_0%i"
//   - "black.dds"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~112 non-empty decompiler lines.
//  - Control keywords: if×8, do×4, while×4, return×2, for×2, goto×2.
//  - Notable callees: FUN_005858b0×3, FUN_00519d20×2, FUN_0096f3e0×2, FUN_009733d0×2, FUN_00989e00×2, FUN_004fc4c0, FUN_004fcd80, FUN_007b6770.
//  - Strings: "_0%i"; "_%i"; "black.dds".
//  - Return sites: 2.

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

void __fastcall FUN_004fcd80(int param_1)



{

  byte bVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  int *piVar6;

  char *pcVar7;

  char *pcVar8;

  uint32_t /* width from decompiler */ local_160;

  uint32_t /* width from decompiler */ local_15c;

  uint32_t /* width from decompiler */ local_158;

  uint32_t /* width from decompiler */ local_154;

  uint8_t local_150 [16];

  uint8_t local_140 [16];

  char local_130 [31];

  char acStack_111 [261];

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009a2d3d;

  local_c = ExceptionList;

  local_154 = 0;

  if (*(int *)(param_1 + 0x48) == 0) {

    return;

  }

  acStack_111[1] = 0;

  ExceptionList = &local_c;

  FUN_004fc4c0(acStack_111 + 1);

  bVar1 = *(byte *)(param_1 + 0x288);

  if (bVar1 != 0) {

    if (bVar1 < 10) {

      pcVar8 = "_0%i";

    }

    else {

      pcVar8 = "_%i";

    }

    sprintf(local_130,pcVar8,(uint)bVar1);

    pcVar8 = local_130;

    do {

      cVar2 = *pcVar8;

      pcVar8 = pcVar8 + 1;

    } while (cVar2 != '\0');

    uVar3 = (int)pcVar8 - (int)local_130;

    pcVar8 = acStack_111;

    do {

      pcVar7 = pcVar8 + 1;

      pcVar8 = pcVar8 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = local_130;

    for (uVar5 = uVar3 >> 2; uVar5 != 0; uVar5 = uVar5 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar8 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar8 = pcVar8 + 4;

    }

    for (uVar3 = uVar3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

      *pcVar8 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar8 = pcVar8 + 1;

    }

  }

  pcVar8 = acStack_111;

  do {

    pcVar7 = pcVar8;

    pcVar8 = pcVar7 + 1;

  } while (pcVar7[1] != '\0');

  *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = s__tint_dds_009cd060._0_4_;

  *(uint32_t /* width from decompiler */ *)(pcVar7 + 5) = s__tint_dds_009cd060._4_4_;

  *(uint16_t *)(pcVar7 + 9) = s__tint_dds_009cd060._8_2_;

  FUN_0096ef70();

  pcVar8 = acStack_111 + 1;

  local_4 = 0;

  FUN_007b6a20(pcVar8);

  cVar2 = FUN_007b6770(pcVar8);

  if (cVar2 == '\0') {

LAB_004fcea9:

    FUN_00989e00(&local_154,"black.dds");

    iVar4 = FUN_0096f3e0(&local_154,0);

    if (iVar4 < 0) goto LAB_004fcfc4;

  }

  else {

    FUN_00989e00(&local_154,acStack_111 + 1);

    iVar4 = FUN_0096f3e0(&local_154,0);

    if (iVar4 < 0) goto LAB_004fcea9;

  }

  local_15c = 0xffffffff;

  local_15c = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8));

  FUN_009733d0(&local_15c);

  local_158 = 0xffffffff;

  local_158 = FUN_00519d20(*(uint32_t /* width from decompiler */ *)(param_1 + 0x1ac));

  FUN_009733d0(&local_158);

  FUN_005858b0(*(uint32_t /* width from decompiler */ *)(param_1 + 0x48),local_150,local_140,local_160,&DAT_00afdf30,0);

  if (*(int *)(param_1 + 0x3a0) != 0) {

    FUN_005858b0(*(int *)(param_1 + 0x3a0),local_150,local_140,local_160,&DAT_00afdf30,0);

  }

  piVar6 = (int *)(param_1 + 0x340);

  iVar4 = 3;

  do {

    if (*piVar6 != 0) {

      FUN_005858b0(*piVar6,local_150,local_140,local_160,&DAT_00afdf30,0);

    }

    piVar6 = piVar6 + 1;

    iVar4 = iVar4 + -1;

  } while (iVar4 != 0);

LAB_004fcfc4:

  local_4 = 0xffffffff;

  FUN_0096efd0();

  ExceptionList = local_c;

  return;

}
