// =============================================================================
// FUN_0047e040
// -----------------------------------------------------------------------------
// Stable ID: aa_0047e040
// Address:   0x0047e040  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0047e040 @ 0x0047e040
// Stable ID: aa_0047e040
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~87 non-empty decompiler lines.
//  - Control keywords: if×5, while×3, do×2, for×1, return×1.
//  - Notable callees: FUN_0047dcd0×3, FUN_0047dda0, FUN_0047dfc0, FUN_0047e040.
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

void FUN_0047e040(int *param_1)



{

  byte bVar1;

  int iVar2;

  uint32_t /* width from decompiler */ uVar3;

  int iVar4;

  byte bVar5;

  int iVar6;

  int iVar7;

  int iVar8;

  int unaff_ESI;

  

  iVar2 = *param_1;

  iVar7 = ((int *)param_1[2])[3];

  iVar8 = *(int *)param_1[2];

  iVar6 = -1;

  iVar4 = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x1448) = 0;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0x144c) = 0x23d;

  if (0 < iVar7) {

    do {

      if (*(short *)(iVar2 + iVar4 * 4) == 0) {

        *(uint16_t *)(iVar2 + 2 + iVar4 * 4) = 0;

      }

      else {

        *(int *)(unaff_ESI + 0x1448) = *(int *)(unaff_ESI + 0x1448) + 1;

        *(int *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x1448) * 4) = iVar4;

        *(uint8_t *)(iVar4 + 0x1450 + unaff_ESI) = 0;

        iVar6 = iVar4;

      }

      iVar4 = iVar4 + 1;

    } while (iVar4 < iVar7);

  }

  iVar4 = *(int *)(unaff_ESI + 0x1448);

  while (iVar4 < 2) {

    if (iVar6 < 2) {

      iVar4 = iVar6 + 1;

      iVar6 = iVar4;

    }

    else {

      iVar4 = 0;

    }

    *(int *)(unaff_ESI + 0x1448) = *(int *)(unaff_ESI + 0x1448) + 1;

    *(int *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x1448) * 4) = iVar4;

    *(uint16_t *)(iVar2 + iVar4 * 4) = 1;

    *(uint8_t *)(unaff_ESI + 0x1450 + iVar4) = 0;

    *(int *)(unaff_ESI + 0x16a0) = *(int *)(unaff_ESI + 0x16a0) + -1;

    if (iVar8 != 0) {

      *(int *)(unaff_ESI + 0x16a4) =

           *(int *)(unaff_ESI + 0x16a4) - (uint)*(ushort *)(iVar8 + 2 + iVar4 * 4);

    }

    iVar4 = *(int *)(unaff_ESI + 0x1448);

  }

  param_1[1] = iVar6;

  for (iVar8 = *(int *)(unaff_ESI + 0x1448) / 2; 0 < iVar8; iVar8 = iVar8 + -1) {

    FUN_0047dcd0(iVar8);

  }

  do {

    uVar3 = *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x1448) * 4);

    iVar8 = *(int *)(unaff_ESI + 0xb58);

    *(int *)(unaff_ESI + 0x1448) = *(int *)(unaff_ESI + 0x1448) + -1;

    *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb58) = uVar3;

    FUN_0047dcd0(1);

    iVar6 = *(int *)(unaff_ESI + 0xb58);

    *(int *)(unaff_ESI + 0x144c) = *(int *)(unaff_ESI + 0x144c) + -1;

    *(int *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x144c) * 4) = iVar8;

    *(int *)(unaff_ESI + 0x144c) = *(int *)(unaff_ESI + 0x144c) + -1;

    *(int *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x144c) * 4) = iVar6;

    *(short *)(iVar2 + iVar7 * 4) = *(short *)(iVar2 + iVar6 * 4) + *(short *)(iVar2 + iVar8 * 4);

    bVar5 = *(byte *)(unaff_ESI + 0x1450 + iVar6);

    bVar1 = *(byte *)(unaff_ESI + 0x1450 + iVar8);

    if (bVar5 <= bVar1) {

      bVar5 = bVar1;

    }

    *(byte *)(unaff_ESI + 0x1450 + iVar7) = bVar5 + 1;

    *(short *)(iVar2 + 2 + iVar6 * 4) = (short)iVar7;

    *(short *)(iVar2 + 2 + iVar8 * 4) = (short)iVar7;

    *(int *)(unaff_ESI + 0xb58) = iVar7;

    iVar7 = iVar7 + 1;

    FUN_0047dcd0(1);

  } while (1 < *(int *)(unaff_ESI + 0x1448));

  *(int *)(unaff_ESI + 0x144c) = *(int *)(unaff_ESI + 0x144c) + -1;

  *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb54 + *(int *)(unaff_ESI + 0x144c) * 4) =

       *(uint32_t /* width from decompiler */ *)(unaff_ESI + 0xb58);

  FUN_0047dda0();

  FUN_0047dfc0();

  return;

}
