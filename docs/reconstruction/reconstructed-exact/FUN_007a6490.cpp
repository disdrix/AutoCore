// =============================================================================
// FUN_007a6490
// -----------------------------------------------------------------------------
// Stable ID: aa_007a6490
// Address:   0x007a6490  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_007a6490 @ 0x007a6490
// Stable ID: aa_007a6490
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~125 non-empty decompiler lines.
//  - Control keywords: if×12, do×6, while×6, for×1, return×1, goto×1.
//  - Notable callees: FUN_007a6260×2, FUN_007a6490.
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

/* WARNING: Function: __chkstk replaced with injection: alloca_probe */



void __fastcall FUN_007a6490(int param_1)



{

  char cVar1;

  byte bVar2;

  char *pcVar3;

  byte *pbVar4;

  uint uVar5;

  char *pcVar6;

  char *pcVar7;

  byte *pbVar8;

  char *unaff_EDI;

  char local_1000 [4092];

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = 0x7a649a;

  pcVar7 = local_1000;

  pcVar3 = unaff_EDI;

  do {

    cVar1 = *pcVar3;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  FUN_007a6260();

  pcVar3 = *(char **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

  pcVar6 = unaff_EDI;

  do {

    cVar1 = *pcVar6;

    *pcVar3 = cVar1;

    pcVar6 = pcVar6 + 1;

    pcVar3 = pcVar3 + 1;

  } while (cVar1 != '\0');

  pcVar3 = *(char **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

  cVar1 = *pcVar3;

  do {

    if (cVar1 == '\0') {

      *pcVar7 = '\0';

      do {

        cVar1 = *unaff_EDI;

        unaff_EDI = unaff_EDI + 1;

      } while (cVar1 != '\0');

      FUN_007a6260();

      pcVar3 = *(char **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

      pcVar7 = local_1000;

      do {

        cVar1 = *pcVar7;

        *pcVar3 = cVar1;

        pcVar7 = pcVar7 + 1;

        pcVar3 = pcVar3 + 1;

      } while (cVar1 != '\0');

      pbVar8 = *(byte **)(param_1 + 4 + *(int *)(param_1 + 0xc0) * 4);

      pbVar4 = pbVar8;

      do {

        bVar2 = *pbVar4;

        pbVar4 = pbVar4 + 1;

      } while (bVar2 != 0);

      uVar5 = 0xffffffff;

      for (pbVar4 = pbVar4 + (4 - (int)(pbVar8 + 1)); pbVar4 != (byte *)0x0; pbVar4 = pbVar4 + -1) {

        uVar5 = uVar5 ^ (uint)*pbVar8 << 0x18;

        pbVar8 = pbVar8 + 1;

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

        if ((int)uVar5 < 0) {

          uVar5 = uVar5 * 2 ^ 0x4c11db7;

        }

        else {

          uVar5 = uVar5 * 2;

        }

      }

      return;

    }

    if (cVar1 == '\\') {

      pcVar3 = pcVar3 + 1;

      if (*pcVar3 == 'n') {

        *pcVar7 = '\n';

LAB_007a64fe:

        pcVar7 = pcVar7 + 1;

      }

    }

    else if ((cVar1 != -0x60) && (cVar1 != '\r')) {

      *pcVar7 = cVar1;

      goto LAB_007a64fe;

    }

    cVar1 = pcVar3[1];

    pcVar3 = pcVar3 + 1;

  } while( true );

}
