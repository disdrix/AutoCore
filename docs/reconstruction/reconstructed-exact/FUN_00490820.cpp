// =============================================================================
// FUN_00490820
// -----------------------------------------------------------------------------
// Stable ID: aa_00490820
// Address:   0x00490820  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00490820 @ 0x00490820
// Stable ID: aa_00490820
// Embedded strings (evidence for future rename):
//   - "SkyBox"
//   - "SkyBoxCloud"
//   - "SkyBoxForeground"
//   - "DiffuseTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~72 non-empty decompiler lines.
//  - Control keywords: if×9, while×2, goto×2, do×1, return×1.
//  - Notable callees: FUN_00746270×3, FUN_00970140×3, FUN_00490820.
//  - Strings: "SkyBox"; "SkyBoxCloud"; "SkyBoxForeground"; "DiffuseTexture".
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

void __thiscall FUN_00490820(int param_1,char param_2,char param_3,char param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  int iVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  int iVar7;

  short local_c;

  short local_a;

  short local_8;

  short local_6;

  short local_4;

  short local_2;

  

  FUN_00746270(&local_c,"SkyBox");

  FUN_00746270(&local_8,"SkyBoxCloud");

  FUN_00746270(&local_4,"SkyBoxForeground");

  if ((*(short *)(param_1 + 0x98) < 1) &&

     (iVar5 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar5 != 0)) {

    iVar5 = **(int **)(iVar5 + 1000);

  }

  else {

    iVar5 = *(int *)(param_1 + 0x9c);

  }

  if ((*(short *)(param_1 + 0xa8) < 1) &&

     (iVar6 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar6 != 0)) {

    iVar6 = **(int **)(iVar6 + 0x3e4);

  }

  else {

    iVar6 = *(int *)(param_1 + 0xac);

  }

  iVar7 = 0;

  do {

    while( true ) {

      iVar1 = *(int *)(param_1 + 0x94);

      if (*(int *)(iVar1 + 0xc0) == 0) {

        iVar3 = 0;

      }

      else {

        iVar3 = *(int *)(iVar1 + 0xc4) - *(int *)(iVar1 + 0xc0) >> 2;

      }

      if (iVar3 <= iVar7) {

        return;

      }

      piVar4 = (int *)(*(int *)(*(int *)(iVar1 + 0xc0) + iVar7 * 4) + 0x20);

      if (((param_4 == '\0') || (*(short *)(*piVar4 + 0x1c) != local_c)) ||

         (*(short *)(*piVar4 + 0x1e) != local_a)) break;

      if (iVar6 == 0) {

LAB_004909b1:

        iVar7 = iVar7 + 1;

      }

      else {

        FUN_00970140("DiffuseTexture",iVar6);

        iVar7 = iVar7 + 1;

      }

    }

    if (((param_3 == '\0') || (*(short *)(*piVar4 + 0x1c) != local_8)) ||

       (*(short *)(*piVar4 + 0x1e) != local_6)) {

      if (((param_2 != '\0') && (*(short *)(*piVar4 + 0x1c) == local_4)) &&

         ((*(short *)(*piVar4 + 0x1e) == local_2 &&

          ((iVar1 = *(int *)(*(int *)(param_1 + 0xb8) + 0xe4f8), iVar1 != 0 &&

           (puVar2 = *(uint32_t /* width from decompiler */ **)(iVar1 + 0x3f8), puVar2 != (uint32_t /* width from decompiler */ *)0x0)))))) {

        FUN_00970140("DiffuseTexture",*puVar2);

      }

      goto LAB_004909b1;

    }

    if (iVar5 == 0) goto LAB_004909b1;

    FUN_00970140("DiffuseTexture",iVar5);

    iVar7 = iVar7 + 1;

  } while( true );

}
