// =============================================================================
// FUN_00747390
// -----------------------------------------------------------------------------
// Stable ID: aa_00747390
// Address:   0x00747390  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00747390 @ 0x00747390
// Stable ID: aa_00747390
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×5, do×2, while×2, return×1, goto×1.
//  - Notable callees: FUN_00445fa0, FUN_0044cc30, FUN_0045f220, FUN_00746910, FUN_00747390.
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

uint32_t /* width from decompiler */ __fastcall FUN_00747390(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int iVar4;

  uint32_t /* width from decompiler */ *puVar5;

  int unaff_ESI;

  uint local_c;

  uint16_t local_8;

  uint16_t local_6;

  uint8_t local_4;

  uint8_t local_3;

  uint8_t local_2;

  uint8_t local_1;

  

  puVar5 = *(uint32_t /* width from decompiler */ **)(param_1 + 4);

  puVar2 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 8) + -8);

  do {

    if (puVar5 == puVar2) {

      local_c = (uint)puVar2 & 0xffffff00;

      iVar4 = *(int *)(unaff_ESI + 8) + -8;

      FUN_0044cc30(*(int *)(unaff_ESI + 4),iVar4,iVar4 - *(int *)(unaff_ESI + 4) >> 3,local_c);

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

      *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

      FUN_00746910();

      return 0;

    }

    iVar4 = *(int *)(unaff_ESI + 8);

    iVar1 = *(int *)(unaff_ESI + 4);

    if (iVar1 != iVar4 + -8) {

      iVar3 = iVar1;

      do {

        if ((*(char *)(iVar3 + 6) == *(char *)((int)puVar5 + 6)) &&

           (*(char *)(iVar3 + 7) == *(char *)((int)puVar5 + 7))) {

          if (*(char *)(iVar3 + 6) == '\x02') {

            *(uint8_t *)(iVar3 + 4) = *(uint8_t *)(puVar5 + 1);

          }

          goto LAB_00747476;

        }

        iVar3 = iVar3 + 8;

      } while (iVar3 != iVar4 + -8);

    }

    local_8 = 0xff;

    local_6 = 0;

    local_4 = 0x11;

    local_3 = 0;

    local_2 = 0;

    local_1 = 0;

    if ((iVar1 == 0) ||

       ((uint)(*(int *)(unaff_ESI + 0xc) - iVar1 >> 3) <= (uint)(iVar4 - iVar1 >> 3))) {

      FUN_00445fa0(iVar4,&local_8);

    }

    else {

      FUN_0045f220(puVar2);

      *(int *)(unaff_ESI + 8) = iVar4 + 8;

    }

    iVar4 = *(int *)(unaff_ESI + 8);

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x10) = 0;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x14) = 0;

    *(uint32_t /* width from decompiler */ *)(iVar4 + -0x10) = *puVar5;

    *(uint32_t /* width from decompiler */ *)(iVar4 + -0xc) = puVar5[1];

LAB_00747476:

    puVar5 = puVar5 + 2;

  } while( true );

}
