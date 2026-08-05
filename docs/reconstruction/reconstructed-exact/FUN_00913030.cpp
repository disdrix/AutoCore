// =============================================================================
// FUN_00913030
// -----------------------------------------------------------------------------
// Stable ID: aa_00913030
// Address:   0x00913030  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00913030 @ 0x00913030
// Stable ID: aa_00913030
// Embedded strings (evidence for future rename):
//   - "new_charcter_create"
//   - "new_charcter_create_skybox"
//   - "new_charcter_create_ai.anm"
//   - "new_charcter_create_human"
//   - "new_charcter_create_human_skybox"
//   - "new_charcter_create_human_ai.anm"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~134 non-empty decompiler lines.
//  - Control keywords: if×16, goto×4, return×2, switch×1, for×1.
//  - Notable callees: FUN_00912b20×8, FUN_0076c4d0×4, FUN_005866d0×2, FUN_00755db0×2, FUN_00755e80×2, FUN_00755f10×2, FUN_0048e9e0, FUN_007a4480.
//  - Strings: "new_charcter_create"; "new_charcter_create_skybox"; "new_charcter_create_ai.anm"; "new_charcter_create_human".
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



void FUN_00913030(void)



{

  int *piVar1;

  uint32_t /* width from decompiler */ uVar2;

  char cVar3;

  int iVar4;

  int iVar5;

  int unaff_EBX;

  int *unaff_EDI;

  char *pcVar6;

  

  iVar4 = unaff_EDI[700];

  if ((iVar4 != 0) && (iVar4 == unaff_EDI[unaff_EBX + 0x2a5])) {

    return;

  }

  if (iVar4 != 0) {

    (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0xfc))();

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(unaff_EDI[700] + 4) + 4) + 4 + unaff_EDI[700]) +

                        0x1cc))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 8);

    iVar4 = (**(code **)(*unaff_EDI + 0x1a8))();

    *(uint8_t *)(iVar4 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

    FUN_0076c4d0();

    cVar3 = (**(code **)(**(int **)(iVar4 + 8) + 8))(uVar2);

    if (cVar3 != '\0') {

      FUN_00755db0(uVar2);

      FUN_00755e80(uVar2);

    }

  }

  iVar4 = unaff_EDI[0x2bd];

  if (iVar4 != 0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1cc))();

    uVar2 = *(uint32_t /* width from decompiler */ *)(iVar4 + 8);

    iVar4 = (**(code **)(*unaff_EDI + 0x1a8))();

    *(uint8_t *)(iVar4 + 0x48) = 1;

    *(uint32_t /* width from decompiler */ *)(iVar4 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar4 + 0x40);

    FUN_0076c4d0();

    cVar3 = (**(code **)(**(int **)(iVar4 + 8) + 8))(uVar2);

    if (cVar3 != '\0') {

      FUN_00755db0(uVar2);

      FUN_00755e80(uVar2);

    }

  }

  piVar1 = unaff_EDI + unaff_EBX + 0x2a5;

  if (unaff_EDI[unaff_EBX + 0x2a5] != 0) goto LAB_0091325d;

  switch(unaff_EBX) {

  case 0:

    FUN_00912b20("new_charcter_create");

    FUN_00912b20("new_charcter_create_skybox");

    if (*piVar1 != 0) {

      pcVar6 = "new_charcter_create_ai.anm";

LAB_009131e9:

      FUN_005866d0(pcVar6,0);

    }

    break;

  case 1:

    FUN_00912b20("new_charcter_create_human");

    FUN_00912b20("new_charcter_create_human_skybox");

    if (*piVar1 != 0) {

      pcVar6 = "new_charcter_create_human_ai.anm";

      goto LAB_009131e9;

    }

    break;

  case 2:

    FUN_00912b20("new_charcter_create_mutant");

    FUN_00912b20("new_charcter_create_mutant_skybox");

    if (*piVar1 != 0) {

      pcVar6 = "new_charcter_create_mutant_ai.anm";

      goto LAB_009131e9;

    }

    break;

  case 3:

    FUN_00912b20("new_charcter_create_biomek");

    FUN_00912b20("new_charcter_create_biomek_skybox");

    if (*piVar1 != 0) {

      pcVar6 = "new_charcter_create_biomek_ai.anm";

      goto LAB_009131e9;

    }

  }

  if (unaff_EDI[unaff_EBX + 0x2a9] != 0) {

    iVar4 = FUN_005866d0("sky_box.anm",0);

    if (iVar4 == -1) {

      FUN_007a4480(0,"invalid skybox for background: %d. skipping timescale.\n");

    }

    else {

      iVar4 = *(int *)(unaff_EDI[unaff_EBX + 0x2a9] + 0x2c + iVar4 * 4);

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x3c) = DAT_00aaaadc;

      *(float *)(iVar4 + 0x34) = *(float *)(iVar4 + 0x40) - *(float *)(iVar4 + 0x44) * _DAT_00aaaad8

      ;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x50) = 0;

      *(uint32_t /* width from decompiler */ *)(iVar4 + 0x68) = 0;

    }

  }

LAB_0091325d:

  unaff_EDI[700] = *piVar1;

  iVar4 = unaff_EDI[unaff_EBX + 0x2a9];

  unaff_EDI[0x2bd] = iVar4;

  iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1cc))();

  *(uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe894) + 0x94) = *(uint32_t /* width from decompiler */ *)(iVar4 + 8);

  FUN_0048e9e0();

  iVar4 = unaff_EDI[700];

  if (iVar4 != 0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1cc))();

    iVar4 = *(int *)(iVar4 + 8);

    iVar5 = (**(code **)(*unaff_EDI + 0x1a8))();

    if (iVar4 != 0) {

      *(uint8_t *)(iVar5 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(iVar5 + 8) + 4))(iVar4);

      FUN_00755f10(iVar4);

    }

    (**(code **)(*(int *)(*(int *)(*(int *)(unaff_EDI[700] + 4) + 4) + 4 + unaff_EDI[700]) + 0x100))

              ();

  }

  iVar4 = unaff_EDI[0x2bd];

  if (iVar4 != 0) {

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(iVar4 + 4) + 4) + 4 + iVar4) + 0x1cc))();

    iVar4 = *(int *)(iVar4 + 8);

    iVar5 = (**(code **)(*unaff_EDI + 0x1a8))();

    if (iVar4 != 0) {

      *(uint8_t *)(iVar5 + 0x48) = 1;

      *(uint32_t /* width from decompiler */ *)(iVar5 + 0x44) = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x40);

      FUN_0076c4d0();

      (**(code **)(**(int **)(iVar5 + 8) + 4))(iVar4);

      FUN_00755f10(iVar4);

    }

  }

  (**(code **)(*(int *)(*(int *)(*(int *)(unaff_EDI[700] + 4) + 4) + 4 + unaff_EDI[700]) + 0x1cc))()

  ;

  FUN_009100f0();

  return;

}
