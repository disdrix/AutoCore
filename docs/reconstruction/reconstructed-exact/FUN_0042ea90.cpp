// =============================================================================
// FUN_0042ea90
// -----------------------------------------------------------------------------
// Stable ID: aa_0042ea90
// Address:   0x0042ea90  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0042ea90 @ 0x0042ea90
// Stable ID: aa_0042ea90
// Embedded strings (evidence for future rename):
//   - "LogNetInterface"
//   - "Received Connect Reject - reason %s"
//   - "Puzzle"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~77 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, return×2.
//  - Notable callees: BitStream_readBits×2, FUN_0042ba90, FUN_0042bf20, FUN_0042c540, FUN_0042c5a0, FUN_0042d510, FUN_0042ea90, FUN_00783aa0.
//  - Strings: "LogNetInterface"; "Received Connect Reject - reason %s"; "Puzzle".
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_0042ea90(void)



{

  int *piVar1;

  int iVar2;

  int *piVar3;

  char *pcVar4;

  int *piVar5;

  char *pcVar6;

  bool bVar7;

  int local_110 [4];

  char local_100 [256];

  

  BitStream_readBits(0x40,local_110 + 2);

  BitStream_readBits(0x40,local_110);

  piVar1 = (int *)FUN_0042c5a0();

  if ((piVar1 != (int *)0x0) && ((piVar1[0x6e] == 1 || (piVar1[0x6e] == 4)))) {

    iVar2 = 2;

    bVar7 = true;

    piVar3 = piVar1 + 0x4e;

    piVar5 = local_110 + 2;

    do {

      if (iVar2 == 0) break;

      iVar2 = iVar2 + -1;

      bVar7 = *piVar3 == *piVar5;

      piVar3 = piVar3 + 1;

      piVar5 = piVar5 + 1;

    } while (bVar7);

    if (bVar7) {

      iVar2 = 2;

      bVar7 = true;

      piVar3 = piVar1 + 0x50;

      piVar5 = local_110;

      do {

        if (iVar2 == 0) break;

        iVar2 = iVar2 + -1;

        bVar7 = *piVar3 == *piVar5;

        piVar3 = piVar3 + 1;

        piVar5 = piVar5 + 1;

      } while (bVar7);

      if (bVar7) {

        FUN_0042ba90(local_100);

        if ((_DAT_00d20d7c & 1) == 0) {

          _DAT_00d20d7c = _DAT_00d20d7c | 1;

          DAT_00d20d78 = FUN_00783b60("LogNetInterface");

        }

        if (*(char *)(DAT_00d20d78 + 4) != '\0') {

          DAT_00d179a0 = DAT_00d20d78;

          FUN_00783aa0("Received Connect Reject - reason %s",local_100);

          DAT_00d179a0 = 0;

        }

        iVar2 = 7;

        bVar7 = true;

        pcVar4 = local_100;

        pcVar6 = "Puzzle";

        do {

          if (iVar2 == 0) break;

          iVar2 = iVar2 + -1;

          bVar7 = *pcVar4 == *pcVar6;

          pcVar4 = pcVar4 + 1;

          pcVar6 = pcVar6 + 1;

        } while (bVar7);

        if ((bVar7) && (*(char *)((int)piVar1 + 0x137) == '\0')) {

          *(uint8_t *)((int)piVar1 + 0x137) = 1;

          piVar1[0x68] = 0;

          piVar1[0x6e] = 1;

          FUN_0042bf20(piVar1 + 0x4e);

          FUN_0042d510();

          return;

        }

        piVar1[0x6e] = 6;

        (**(code **)(*piVar1 + 0xc))(2,local_100);

        FUN_0042c540();

      }

    }

  }

  return;

}
