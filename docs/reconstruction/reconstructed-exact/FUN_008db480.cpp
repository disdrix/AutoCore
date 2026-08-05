// =============================================================================
// FUN_008db480
// -----------------------------------------------------------------------------
// Stable ID: aa_008db480
// Address:   0x008db480  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008db480 @ 0x008db480
// Stable ID: aa_008db480
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~95 non-empty decompiler lines.
//  - Control keywords: if×4, return×2.
//  - Notable callees: FUN_008db480.
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

void FUN_008db480(void)



{

  uint32_t /* width from decompiler */ uVar1;

  char cVar2;

  int *piVar3;

  int *piVar4;

  int iVar5;

  int iVar6;

  uint32_t /* width from decompiler */ *puVar7;

  int iVar8;

  int *unaff_ESI;

  uint32_t /* width from decompiler */ uStack_50;

  uint8_t **ppuStack_4c;

  uint8_t **ppuStack_48;

  uint32_t /* width from decompiler */ uStack_44;

  uint8_t *puStack_40;

  uint32_t /* width from decompiler */ uStack_3c;

  uint32_t /* width from decompiler */ uStack_38;

  uint8_t *puStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint8_t *puStack_2c;

  int *piStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  int aiStack_c [3];

  

  if (unaff_ESI[0x16b] != 0) {

    cVar2 = (**(code **)(*unaff_ESI + 0x3d8))();

    if (cVar2 != '\0') {

      if ((char)unaff_ESI[0x146] == '\0') {

        (**(code **)(*(int *)unaff_ESI[0x16b] + 4))();

        return;

      }

      iVar8 = unaff_ESI[0x16b];

      unaff_ESI[0x145] = 0;

      uVar1 = DAT_00aaa85c;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 0x254) = DAT_00aaa85c;

      *(uint32_t /* width from decompiler */ *)(iVar8 + 600) = uVar1;

      aiStack_c[0] = (int)((float)DAT_00d1e81c * (float)(int)(float)((int *)unaff_ESI[0x16b])[0x96]

                          * DAT_00aaa678);

      (**(code **)(*(int *)unaff_ESI[0x16b] + 300))();

      if ((int *)unaff_ESI[0x168] == (int *)0x0) {

        uStack_24 = 1;

        piStack_28 = aiStack_c;

        puStack_2c = (uint8_t *)0x8db5e7;

        puVar7 = (uint32_t /* width from decompiler */ *)(**(code **)(*unaff_ESI + 0x120))();

        iVar8 = unaff_ESI[0x16b];

        *(uint32_t /* width from decompiler */ *)(iVar8 + 0x160) = *puVar7;

        iVar5 = puVar7[1];

      }

      else {

        uStack_24 = 0;

        piStack_28 = (int *)0x1;

        puStack_2c = &stack0xffffffec;

        uStack_30 = 0x8db56a;

        piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x168] + 0x120))();

        uStack_30 = 1;

        puStack_34 = &stack0xffffffe8;

        uStack_38 = 0x8db581;

        piVar4 = (int *)(**(code **)(*(int *)unaff_ESI[0x168] + 0x140))();

        uStack_38 = 0;

        *(int *)(unaff_ESI[0x16b] + 0x160) = *piVar4 / 2 + *piVar3;

        piVar3 = (int *)unaff_ESI[0x168];

        uStack_3c = 1;

        puStack_40 = &stack0xffffffe0;

        uStack_44 = 0x8db5ae;

        iVar5 = (**(code **)(*piVar3 + 0x120))();

        uStack_44 = 1;

        ppuStack_48 = &puStack_34;

        ppuStack_4c = (uint8_t **)0x8db5c1;

        iVar6 = (**(code **)(*piVar3 + 0x140))();

        iVar8 = unaff_ESI[0x16b];

        iVar5 = *(int *)(iVar6 + 4) / 2 + *(int *)(iVar5 + 4);

      }

      *(int *)(iVar8 + 0x164) = iVar5;

      ppuStack_48 = (uint8_t **)0x1;

      ppuStack_4c = &puStack_34;

      uStack_50 = 0x8db613;

      piVar3 = (int *)(**(code **)(*(int *)unaff_ESI[0x16b] + 0x140))();

      *(int *)(unaff_ESI[0x16b] + 0x168) = *(int *)(unaff_ESI[0x16b] + 0x160) - *piVar3 / 2;

      piVar3 = (int *)unaff_ESI[0x16b];

      uStack_50 = 1;

      iVar8 = (**(code **)(*piVar3 + 0x140))(&uStack_3c);

      piVar3[0x5b] = piVar3[0x59] - *(int *)(iVar8 + 4) / 2;

      ppuStack_4c = (uint8_t **)0x0;

      ppuStack_48 = (uint8_t **)0x0;

      (**(code **)(*(int *)unaff_ESI[0x16b] + 0x110))(&ppuStack_4c);

      uStack_50 = 0;

      ppuStack_4c = (uint8_t **)0x0;

      (**(code **)(*(int *)unaff_ESI[0x16b] + 300))(&uStack_50);

      (**(code **)(*(int *)unaff_ESI[0x16b] + 0xcc))(1);

      (**(code **)(*(int *)unaff_ESI[0x16b] + 0xfc))(0,0x3f99999a);

      (**(code **)(*(int *)unaff_ESI[0x16b] + 0x34c))();

    }

  }

  return;

}
