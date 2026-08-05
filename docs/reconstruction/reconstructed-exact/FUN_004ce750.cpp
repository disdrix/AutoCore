// =============================================================================
// FUN_004ce750
// -----------------------------------------------------------------------------
// Stable ID: aa_004ce750
// Address:   0x004ce750  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004ce750 @ 0x004ce750
// Stable ID: aa_004ce750
// Embedded strings (evidence for future rename):
//   - "_0%i"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~71 non-empty decompiler lines.
//  - Control keywords: do×6, while×6, if×2, for×2, return×1.
//  - Notable callees: FUN_004ce750, sprintf, strncat.
//  - Strings: "_0%i"; "_%i".
//  - Return sites: 1.

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

void __thiscall FUN_004ce750(int param_1,char *param_2)



{

  char cVar1;

  int iVar2;

  char *pcVar3;

  char *pcVar4;

  uint uVar5;

  uint uVar6;

  char *pcVar7;

  char local_10c [8];

  char local_104 [260];

  

  if (param_2 != (char *)0x0) {

    pcVar4 = (char *)(param_1 + 0xe198);

    *param_2 = '\0';

    iVar2 = -(int)pcVar4;

    do {

      cVar1 = *pcVar4;

      pcVar4[(int)(local_104 + iVar2)] = cVar1;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    pcVar4 = local_104;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    strncat(param_2,local_104,(size_t)(pcVar4 + (-4 - (int)(local_104 + 1))));

    pcVar4 = param_2 + -1;

    do {

      pcVar7 = pcVar4;

      pcVar4 = pcVar7 + 1;

    } while (pcVar7[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar7 + 1) = DAT_009cc334;

    *(uint16_t *)(pcVar7 + 5) = DAT_009cc338;

    if (*(byte *)(param_1 + 0x7c) < 10) {

      pcVar4 = "_0%i";

    }

    else {

      pcVar4 = "_%i";

    }

    sprintf(local_10c,pcVar4,(uint)*(byte *)(param_1 + 0x7c));

    pcVar4 = local_10c;

    do {

      cVar1 = *pcVar4;

      pcVar4 = pcVar4 + 1;

    } while (cVar1 != '\0');

    uVar5 = (int)pcVar4 - (int)local_10c;

    pcVar4 = param_2 + -1;

    do {

      pcVar7 = pcVar4 + 1;

      pcVar4 = pcVar4 + 1;

    } while (*pcVar7 != '\0');

    pcVar7 = local_10c;

    for (uVar6 = uVar5 >> 2; uVar6 != 0; uVar6 = uVar6 - 1) {

      *(uint32_t /* width from decompiler */ *)pcVar4 = *(uint32_t /* width from decompiler */ *)pcVar7;

      pcVar7 = pcVar7 + 4;

      pcVar4 = pcVar4 + 4;

    }

    for (uVar5 = uVar5 & 3; pcVar3 = param_2 + -1, uVar5 != 0; uVar5 = uVar5 - 1) {

      *pcVar4 = *pcVar7;

      pcVar7 = pcVar7 + 1;

      pcVar4 = pcVar4 + 1;

    }

    do {

      pcVar4 = pcVar3;

      pcVar3 = pcVar4 + 1;

    } while (pcVar4[1] != '\0');

    *(uint32_t /* width from decompiler */ *)(pcVar4 + 1) = DAT_00a2c53c;

    pcVar4[5] = DAT_00a2c540;

  }

  return;

}
