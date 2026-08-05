// =============================================================================
// FUN_00490af0
// -----------------------------------------------------------------------------
// Stable ID: aa_00490af0
// Address:   0x00490af0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00490af0 @ 0x00490af0
// Stable ID: aa_00490af0
// Embedded strings (evidence for future rename):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
//   - "fBlendAmount"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~64 non-empty decompiler lines.
//  - Control keywords: if×6, do×1, return×1, goto×1, while×1.
//  - Notable callees: FUN_00746270×3, FUN_00442640, FUN_00490af0, FUN_00752370, FUN_00752a00, FUN_0096f5d0, FUN_0096fdf0.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground"; "fBlendAmount".
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

void FUN_00490af0(uint32_t /* width from decompiler */ param_1,char param_2,char param_3,char param_4)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  int iVar6;

  int *piVar7;

  short local_18;

  short local_16;

  short local_14;

  short local_12;

  short local_10;

  short local_e;

  int local_c;

  uint32_t /* width from decompiler */ local_8;

  uint8_t local_4 [4];

  

  FUN_00746270(&local_18,"SkyBox");

  FUN_00746270(&local_14,"SkyBoxCloud");

  FUN_00746270(&local_10,"SkyBoxForeground");

  iVar6 = 0;

LAB_00490b40:

  do {

    iVar5 = *(int *)(local_c + 0x94);

    if (*(int *)(iVar5 + 0xc0) == 0) {

      iVar3 = 0;

    }

    else {

      iVar3 = *(int *)(iVar5 + 0xc4) - *(int *)(iVar5 + 0xc0) >> 2;

    }

    if (iVar3 <= iVar6) {

      return;

    }

    piVar7 = (int *)(*(int *)(*(int *)(iVar5 + 0xc0) + iVar6 * 4) + 0x20);

    if (((param_4 == '\0') || (iVar5 = *piVar7, *(short *)(iVar5 + 0x1c) != local_18)) ||

       (*(short *)(iVar5 + 0x1e) != local_16)) {

      if ((((param_3 != '\0') && (*(short *)(*piVar7 + 0x1c) == local_14)) &&

          (*(short *)(*piVar7 + 0x1e) == local_12)) ||

         (((param_2 != '\0' && (*(short *)(*piVar7 + 0x1c) == local_10)) &&

          (*(short *)(*piVar7 + 0x1e) == local_e)))) {

        FUN_00442640("fBlendAmount",&param_1);

      }

    }

    else {

      if (iVar5 == 0) {

        local_8 = 0xffffffff;

        puVar4 = &local_8;

      }

      else {

        puVar4 = (uint32_t /* width from decompiler */ *)FUN_00752370(local_4,"fBlendAmount");

      }

      uVar1 = *puVar4;

      cVar2 = FUN_0096fdf0();

      iVar5 = FUN_00752a00(uVar1,&param_1);

      if ((iVar5 == -1) && (cVar2 != '\0')) {

        FUN_0096f5d0();

        iVar6 = iVar6 + 1;

        goto LAB_00490b40;

      }

    }

    iVar6 = iVar6 + 1;

  } while( true );

}
