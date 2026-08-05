// =============================================================================
// FUN_0073bad0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073bad0
// Address:   0x0073bad0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073bad0 @ 0x0073bad0
// Stable ID: aa_0073bad0
// Embedded strings (evidence for future rename):
//   - "%i references to font %s not released"
//   - "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~65 non-empty decompiler lines.
//  - Control keywords: if×7, while×2, return×2, do×1.
//  - Notable callees: FUN_00463e30, FUN_00464120, FUN_0073bad0, FUN_0076cec0, block, vog_LogMessage.
//  - Strings: "%i references to font %s not released"; "C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp".
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

/* WARNING: Removing unreachable block (ram,0x0073bb97) */



void __fastcall FUN_0073bad0(uint32_t /* width from decompiler */ param_1)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  void *pvVar4;

  uint32_t /* width from decompiler */ uVar5;

  int *piVar6;

  int unaff_EBX;

  int *piVar7;

  uint32_t /* width from decompiler */ local_4;

  

  piVar7 = (int *)**(int **)(unaff_EBX + 8);

  local_4 = param_1;

  if (piVar7 != *(int **)(unaff_EBX + 8)) {

    do {

      piVar1 = (int *)piVar7[0xb];

      if (1 < piVar1[1]) {

        if ((uint)piVar1[0xc] < 0x10) {

          piVar6 = piVar1 + 7;

        }

        else {

          piVar6 = (int *)piVar1[7];

        }

        uVar5 = FUN_0076cec0(&local_4,"%i references to font %s not released",piVar1[1] + -1,piVar6)

        ;

        vog_LogMessage("C:\\vog\\1_code\\palantir\\palantir\\graphics\\gfxFontFactory.cpp",0x2c,3,

                       uVar5);

        iVar2 = piVar1[1];

        while (1 < iVar2) {

          piVar6 = piVar1 + 1;

          *piVar6 = *piVar6 + -1;

          if (*piVar6 == 0) {

            (**(code **)(*piVar1 + 8))();

          }

          iVar2 = piVar1[1];

        }

      }

      piVar6 = piVar1 + 1;

      *piVar6 = *piVar6 + -1;

      if (*piVar6 == 0) {

        (**(code **)(*piVar1 + 8))();

      }

      piVar7 = (int *)*piVar7;

    } while (piVar7 != (int *)*(int *)(unaff_EBX + 8));

  }

  puVar3 = *(uint32_t /* width from decompiler */ **)(unaff_EBX + 8);

  pvVar4 = (void *)*puVar3;

  *puVar3 = puVar3;

  *(int *)(*(int *)(unaff_EBX + 8) + 4) = *(int *)(unaff_EBX + 8);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0xc) = 0;

  if (pvVar4 != *(void **)(unaff_EBX + 8)) {

    FUN_00464120();

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar4);

  }

  local_4 = *(uint32_t /* width from decompiler */ *)(unaff_EBX + 8);

  if (*(int *)(unaff_EBX + 0x14) != *(int *)(unaff_EBX + 0x18)) {

    *(int *)(unaff_EBX + 0x18) = *(int *)(unaff_EBX + 0x14);

  }

  FUN_00463e30(*(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14),9,&local_4);

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x20) = 1;

  *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x24) = 1;

  return;

}
