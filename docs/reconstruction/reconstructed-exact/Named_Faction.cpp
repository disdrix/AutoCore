// =============================================================================
// Named_Faction
// -----------------------------------------------------------------------------
// Stable ID: aa_00832170
// Address:   0x00832170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Faction @ 0x00832170
// Stable ID: aa_00832170
// Embedded strings (evidence for future rename):
//   - "1. General"
//   - "5. LFC"
//   - "4. Trade"
//   - "Local"
//   - "6. Faction"
//   - "2. French"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~179 non-empty decompiler lines.
//  - Control keywords: do×13, while×13, for×4, if×2, return×2, switch×1.
//  - Notable callees: FUN_007a69d0×10, FUN_007a6de0×10, Named_Faction.
//  - Strings: "1. General"; "5. LFC"; "4. Trade"; "Local".
//  - Return sites: 2.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "6. Faction"
 * Domain alias of FUN_00832170 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Faction(char *param_1,char param_2)



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

    case 4:

      uVar7 = 0xffffffff;

      puVar6 = &DAT_00a36bcc;

      FUN_007a69d0(&DAT_00a36bcc,0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(puVar6,uVar7);

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

      pcVar3 = "1. General";

      FUN_007a69d0("1. General",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 8:

      uVar7 = 0xffffffff;

      pcVar3 = "5. LFC";

      FUN_007a69d0("5. LFC",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 9:

      uVar7 = 0xffffffff;

      pcVar3 = "4. Trade";

      FUN_007a69d0("4. Trade",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 10:

      uVar7 = 0xffffffff;

      pcVar3 = "Local";

      FUN_007a69d0("Local",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 0xd:

      uVar7 = 0xffffffff;

      pcVar3 = "6. Faction";

      FUN_007a69d0("6. Faction",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 0xe:

      uVar7 = 0xffffffff;

      pcVar3 = "2. French";

      FUN_007a69d0("2. French",0xffffffff);

      pcVar2 = (char *)FUN_007a6de0(pcVar3,uVar7);

      pcVar3 = param_1;

      do {

        cVar1 = *pcVar2;

        *pcVar3 = cVar1;

        pcVar2 = pcVar2 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      break;

    case 0xf:

      uVar7 = 0xffffffff;

      pcVar3 = "3. German";

      FUN_007a69d0("3. German",0xffffffff);

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
