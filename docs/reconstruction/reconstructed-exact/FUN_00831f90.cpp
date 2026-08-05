// =============================================================================
// FUN_00831f90
// -----------------------------------------------------------------------------
// Stable ID: aa_00831f90
// Address:   0x00831f90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00831f90 @ 0x00831f90
// Stable ID: aa_00831f90
// Embedded strings (evidence for future rename):
//   - "Dmg Done (Yours)"
//   - "Dmg Done (Others)"
//   - "Dmg Taken (Yours)"
//   - "Dmg Taken (Others)"
//   - "Completed"
//   - "Upcoming"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~153 non-empty decompiler lines.
//  - Control keywords: do×11, while×11, for×4, if×2, return×2, switch×1.
//  - Notable callees: FUN_007a69d0×8, FUN_007a6de0×8, Done×4, Taken×4, FUN_00831f90.
//  - Strings: "Dmg Done (Yours)"; "Dmg Done (Others)"; "Dmg Taken (Yours)"; "Dmg Taken (Others)".
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

void __thiscall FUN_00831f90(char *param_1,char param_2)



{

  char cVar1;

  uint32_t /* width from decompiler */ in_EAX;

  char *pcVar2;

  char *pcVar3;

  uint uVar4;

  char *pcVar5;

  undefined *puVar6;

  uint32_t /* width from decompiler */ uVar7;

  

  if (param_1 != (char *)0x0) {

    *param_1 = '\0';

    switch(in_EAX) {

    case 0:

      uVar7 = 0xffffffff;

      pcVar3 = "Dmg Done (Yours)";

      FUN_007a69d0("Dmg Done (Yours)",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 1:

      uVar7 = 0xffffffff;

      pcVar3 = "Dmg Done (Others)";

      FUN_007a69d0("Dmg Done (Others)",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 2:

      uVar7 = 0xffffffff;

      pcVar3 = "Dmg Taken (Yours)";

      FUN_007a69d0("Dmg Taken (Yours)",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 3:

      uVar7 = 0xffffffff;

      pcVar3 = "Dmg Taken (Others)";

      FUN_007a69d0("Dmg Taken (Others)",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 4:

      uVar7 = 0xffffffff;

      pcVar3 = "Completed";

      FUN_007a69d0("Completed",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 5:

      uVar7 = 0xffffffff;

      pcVar3 = "Upcoming";

      FUN_007a69d0("Upcoming",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

    }

    pcVar3 = param_1 + -1;

    do {

      pcVar2 = pcVar3;

      pcVar3 = pcVar2 + 1;

    } while (pcVar2[1] != '\0');

    *(uint16_t *)(pcVar2 + 1) = DAT_00a3ad3c;

    pcVar2[3] = DAT_00a3ad3e;

    uVar7 = 0xffffffff;

    if (param_2 != '\0') {

      puVar6 = &DAT_00a70b44;

      FUN_007a69d0(&DAT_00a70b44);

      pcVar2 = (char *)FUN_007a6de0(puVar6,uVar7);

      pcVar3 = pcVar2;

      do {

        cVar1 = *pcVar3;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      param_1 = param_1 + -1;

      do {

        pcVar5 = param_1 + 1;

        param_1 = param_1 + 1;

      } while (*pcVar5 != '\0');

      pcVar5 = pcVar2;

      for (uVar4 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

        *(uint32_t /* width from decompiler */ *)param_1 = *(uint32_t /* width from decompiler */ *)pcVar5;

        pcVar5 = pcVar5 + 4;

        param_1 = param_1 + 4;

      }

      for (uVar4 = (int)pcVar3 - (int)pcVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

        *param_1 = *pcVar5;

        pcVar5 = pcVar5 + 1;

        param_1 = param_1 + 1;

      }

      return;

    }

    puVar6 = &DAT_00a70b40;

    FUN_007a69d0(&DAT_00a70b40,0xffffffff);

    pcVar2 = (char *)FUN_007a6de0(puVar6,uVar7);

    pcVar3 = pcVar2;

    do {

      cVar1 = *pcVar3;

      pcVar3 = pcVar3 + 1;

    } while (cVar1 != '\0');

    param_1 = param_1 + -1;

    do {

      pcVar5 = param_1 + 1;

      param_1 = param_1 + 1;

    } while (*pcVar5 != '\0');

    pcVar5 = pcVar2;

    for (uVar4 = (uint)((int)pcVar3 - (int)pcVar2) >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {

      *(uint32_t /* width from decompiler */ *)param_1 = *(uint32_t /* width from decompiler */ *)pcVar5;

      pcVar5 = pcVar5 + 4;

      param_1 = param_1 + 4;

    }

    for (uVar4 = (int)pcVar3 - (int)pcVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {

      *param_1 = *pcVar5;

      pcVar5 = pcVar5 + 1;

      param_1 = param_1 + 1;

    }

  }

  return;

}
