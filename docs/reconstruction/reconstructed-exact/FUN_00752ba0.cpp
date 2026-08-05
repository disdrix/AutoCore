// =============================================================================
// FUN_00752ba0
// -----------------------------------------------------------------------------
// Stable ID: aa_00752ba0
// Address:   0x00752ba0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00752ba0 @ 0x00752ba0
// Stable ID: aa_00752ba0
// Embedded strings (evidence for future rename):
//   - "AlphaTestEnable"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~121 non-empty decompiler lines.
//  - Control keywords: if×15, for×4, return×2, goto×2, do×1, while×1.
//  - Notable callees: FUN_00445050×2, FUN_00752ba0, _aligned_malloc, strstr.
//  - Strings: "AlphaTestEnable".
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

uint32_t /* width from decompiler */ FUN_00752ba0(void)



{

  int iVar1;

  char cVar2;

  uint32_t /* width from decompiler */ *in_EAX;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  char *pcVar6;

  uint uVar7;

  int unaff_EBX;

  uint uVar8;

  int *piVar9;

  int iVar10;

  uint8_t local_2c [4];

  char *pcStack_28;

  

  iVar10 = *(int *)(unaff_EBX + 8);

  if (iVar10 == 0) {

    return 0xffffffff;

  }

  puVar4 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0x40);

  if ((puVar4 == (uint32_t /* width from decompiler */ *)0x0) || (*(int *)(iVar10 + 0x44) - (int)puVar4 >> 2 == 0)) {

    puVar4 = *(uint32_t /* width from decompiler */ **)(iVar10 + 0x50);

    if ((puVar4 == (uint32_t /* width from decompiler */ *)0x0) || (*(int *)(iVar10 + 0x54) - (int)puVar4 >> 2 == 0)) {

      cVar2 = FUN_00445050();

      if (cVar2 == '\0') {

        uVar3 = **(uint32_t /* width from decompiler */ **)(iVar10 + 0x90);

      }

      else {

        cVar2 = FUN_00445050();

        if (cVar2 == '\0') {

          *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = **(uint32_t /* width from decompiler */ **)(iVar10 + 0xa0);

          goto LAB_00752c2c;

        }

        uVar3 = *(uint32_t /* width from decompiler */ *)(iVar10 + 0x30);

      }

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = uVar3;

    }

    else {

      *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = *puVar4;

    }

  }

  else {

    *(uint32_t /* width from decompiler */ *)(unaff_EBX + 0x14) = *puVar4;

  }

LAB_00752c2c:

  if (*(int *)(iVar10 + 0x18) < 1) {

    uVar8 = 0;

  }

  else {

    uVar8 = (uint)*(ushort *)(*(int *)(iVar10 + 0x10) + -4 + *(int *)(iVar10 + 0x18) * 8) +

            (uint)*(ushort *)(*(int *)(iVar10 + 0x10) + -2 + *(int *)(iVar10 + 0x18) * 8);

    if (uVar8 != 0) {

      puVar4 = _aligned_malloc(uVar8,0x10);

      goto LAB_00752c5d;

    }

  }

  puVar4 = (uint32_t /* width from decompiler */ *)0x0;

LAB_00752c5d:

  *(uint32_t /* width from decompiler */ **)(unaff_EBX + 0xc) = puVar4;

  if (in_EAX == (uint32_t /* width from decompiler */ *)0x0) {

    in_EAX = *(uint32_t /* width from decompiler */ **)(*(int *)(unaff_EBX + 8) + 0x1c);

    for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar4 = *in_EAX;

      in_EAX = in_EAX + 1;

      puVar4 = puVar4 + 1;

    }

  }

  else {

    for (uVar7 = uVar8 >> 2; uVar7 != 0; uVar7 = uVar7 - 1) {

      *puVar4 = *in_EAX;

      in_EAX = in_EAX + 1;

      puVar4 = puVar4 + 1;

    }

  }

  for (uVar8 = uVar8 & 3; uVar8 != 0; uVar8 = uVar8 - 1) {

    *(uint8_t *)puVar4 = *(uint8_t *)in_EAX;

    in_EAX = (uint32_t /* width from decompiler */ *)((int)in_EAX + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  iVar10 = 0;

  if (0 < *(int *)(*(int *)(unaff_EBX + 8) + 0x14)) {

    do {

      if (-1 < iVar10) {

        iVar5 = *(int *)(unaff_EBX + 8);

        if (*(int *)(iVar5 + 0xc) == 0) {

          iVar5 = -0x7789f794;

        }

        else {

          iVar5 = (**(code **)(**(int **)(iVar5 + 0xc) + 0x10))

                            (*(int **)(iVar5 + 0xc),

                             *(uint32_t /* width from decompiler */ *)(*(int *)(iVar5 + 0x10) + iVar10 * 8),local_2c);

        }

        if (((-1 < (int)((-1 < iVar5) - 1)) && (pcStack_28 != (char *)0x0)) &&

           (pcVar6 = strstr(pcStack_28,"AlphaTestEnable"), pcVar6 != (char *)0x0)) {

          *(uint *)(unaff_EBX + 0x10) =

               (uint)*(ushort *)(*(int *)(*(int *)(unaff_EBX + 8) + 0x10) + 4 + iVar10 * 8) +

               *(int *)(unaff_EBX + 0xc);

        }

      }

      iVar10 = iVar10 + 1;

    } while (iVar10 < *(int *)(*(int *)(unaff_EBX + 8) + 0x14));

  }

  iVar5 = *(int *)(*(int *)(unaff_EBX + 8) + 0x18);

  for (; iVar10 < iVar5; iVar10 = iVar10 + 1) {

    piVar9 = (int *)((uint)*(ushort *)(*(int *)(*(int *)(unaff_EBX + 8) + 0x10) + 4 + iVar10 * 8) +

                    *(int *)(unaff_EBX + 0xc));

    iVar1 = piVar9[1];

    if (iVar1 != 0) {

      *(int *)(iVar1 + 8) = *(int *)(iVar1 + 8) + 1;

      if (*(int *)(iVar1 + 8) == 1) {

        (**(code **)(*(int *)(iVar1 + 4) + 4))();

      }

      piVar9 = (int *)*piVar9;

      if (piVar9 != (int *)0x0) {

        (**(code **)(*piVar9 + 4))(piVar9);

      }

    }

  }

  return 0;

}
