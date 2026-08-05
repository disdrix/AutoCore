// =============================================================================
// Named_Failed_load_map_file
// -----------------------------------------------------------------------------
// Stable ID: aa_008bb9e0
// Address:   0x008bb9e0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Named_Failed_load_map_file @ 0x008bb9e0
// Stable ID: aa_008bb9e0
// Embedded strings (evidence for future rename):
//   - "Failed to load map file."
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~129 non-empty decompiler lines.
//  - Control keywords: if×15, goto×4, return×4, while×1, for×1.
//  - Notable callees: FUN_00720d40×2, FUN_004ce020, FUN_004e0ad0, FUN_005abba0, FUN_00691630, FUN_00720670, FUN_00720da0, FUN_00791f30.
//  - Strings: "Failed to load map file.".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "Failed to load map file."
 * Domain alias of FUN_008bb9e0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void __thiscall Named_Failed_load_map_file(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  char cVar1;

  int iVar2;

  HWND pHVar3;

  int iVar4;

  int iVar5;

  uint32_t /* width from decompiler */ *puVar6;

  uint32_t /* width from decompiler */ *puVar7;

  float fVar8;

  uint32_t /* width from decompiler */ auStack_e0 [44];

  uint32_t /* width from decompiler */ uStack_30;

  undefined *puStack_2c;

  char *pcStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  undefined *puStack_1c;

  

  if (DAT_00d1b644 == 0) goto LAB_008bba51;

  cVar1 = *(char *)(DAT_00d1b644 + 0x80);

  if (cVar1 != '\0') {

    iVar2 = param_1[0x145];

    if (iVar2 < 0) {

      param_1[0x145] = 10;

      puStack_1c = &DAT_00d1af90;

      uStack_20 = 0x8bba29;

      FUN_004ce020();

      puStack_1c = (undefined *)0x8bba39;

      FUN_005abba0();

      puStack_1c = (undefined *)0x8bba40;

      FUN_008bb520();

      *(uint8_t *)(param_1 + 0x144) = 1;

      puStack_1c = (undefined *)0x8bba51;

      (**(code **)(*param_1 + 0x448))();

    }

    else if (iVar2 < 1) {

      *(uint8_t *)(DAT_00d1b644 + 0x80) = 0;

      param_1[0x145] = -1;

      puStack_1c = (undefined *)0x8bba8f;

      iVar2 = FUN_00931fa0();

      if (iVar2 == 0) {

        puStack_1c = (undefined *)0x0;

        uStack_20 = 1;

        uStack_24 = 0xffffffff;

        pcStack_28 = "Failed to load map file.";

        puStack_2c = &DAT_00d1a840;

        uStack_30 = 0x8bbb86;

        FUN_007fdfb0();

        return;

      }

      if (iVar2 == 2) {

        param_1[0x145] = 8;

        *(char *)(DAT_00d1b644 + 0x80) = cVar1;

        return;

      }

      iVar5 = 0;

      iVar2 = 0;

      while( true ) {

        iVar4 = 0;

        if (*(int *)(DAT_00d1b644 + 0xe908) != 0) {

          iVar4 = (*(int *)(DAT_00d1b644 + 0xe90c) - *(int *)(DAT_00d1b644 + 0xe908)) / 200;

        }

        if (iVar4 <= iVar5) break;

        puVar6 = (uint32_t /* width from decompiler */ *)(*(int *)(DAT_00d1b644 + 0xe908) + iVar2);

        puVar7 = auStack_e0;

        for (iVar4 = 0x32; iVar4 != 0; iVar4 = iVar4 + -1) {

          *puVar7 = *puVar6;

          puVar6 = puVar6 + 1;

          puVar7 = puVar7 + 1;

        }

        FUN_00720d40();

        FUN_00720670();

        iVar5 = iVar5 + 1;

        iVar2 = iVar2 + 200;

      }

      puStack_1c = (undefined *)0x8bbb16;

      FUN_00691630();

      if ((DAT_00d1b644 != 0) && (DAT_00d1b644 != -0x98)) {

        puStack_1c = (undefined *)(DAT_00d1b644 + 0xb4);

        uStack_20 = 0x8bbb34;

        uStack_20 = FUN_00720d40();

        uStack_24 = 0x8bbb3a;

        FUN_00720da0();

      }

      puStack_1c = (undefined *)0x8bbb46;

      (**(code **)(*param_1 + 0x448))();

    }

    else {

      param_1[0x145] = iVar2 + -1;

    }

    goto LAB_008bba51;

  }

  if (*(char *)(DAT_00d1b644 + 0x81) == '\0') goto LAB_008bba51;

  if (*(char *)(DAT_00d1b628 + 5) == '\0') {

    puStack_1c = (undefined *)0x8bbbaf;

    pHVar3 = GetForegroundWindow();

    if (pHVar3 == DAT_00d1d9c8) goto LAB_008bbbbd;

  }

  else {

LAB_008bbbbd:

    puStack_1c = (undefined *)param_2;

    uStack_20 = 0x8bbbc7;

    FUN_004e0ad0();

  }

  iVar2 = *(int *)(*(int *)(DAT_00d1b644 + 0xe64c) + 0xc);

  if (*(int *)(DAT_00d1b644 + 0x84) < 1) {

    fVar8 = 0.0;

  }

  else {

    fVar8 = (float)(*(int *)(DAT_00d1b644 + 0x84) - iVar2) / (float)*(int *)(DAT_00d1b644 + 0x84);

  }

  if ((float)param_1[0x146] + (float)param_1[0x147] < fVar8) {

    param_1[0x147] = (int)((float)param_1[0x146] + (float)param_1[0x147]);

    puStack_1c = (undefined *)0x8bbc21;

    FUN_008bb470();

  }

  uStack_20 = 0x8bbc38;

  puStack_1c = (undefined *)fVar8;

  (**(code **)(*(int *)param_1[0x164] + 0x3ac))();

  if (iVar2 < 1) {

    puStack_1c = (undefined *)0x8bbc4a;

    FUN_009347b0();

    return;

  }

LAB_008bba51:

  puStack_1c = (undefined *)param_2;

  uStack_20 = 0x8bba5d;

  FUN_00791f30();

  return;

}
