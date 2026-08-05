// =============================================================================
// FUN_0079bb20
// -----------------------------------------------------------------------------
// Stable ID: aa_0079bb20
// Address:   0x0079bb20  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0079bb20 @ 0x0079bb20
// Stable ID: aa_0079bb20
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~84 non-empty decompiler lines.
//  - Control keywords: if×9, do×3, while×3, goto×2, return×2.
//  - Notable callees: FUN_00797d70, FUN_0079bb20.
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

void FUN_0079bb20(void)



{

  void *pvVar1;

  char cVar2;

  int iVar3;

  uint *puVar4;

  byte *pbVar5;

  uint8_t *puVar6;

  int iVar7;

  int *unaff_ESI;

  uint auStack_c [3];

  

  if ((char)unaff_ESI[0x122] != '\0') {

    unaff_ESI[0x8a] = 0;

    goto LAB_0079bc81;

  }

  cVar2 = (**(code **)(*unaff_ESI + 0xf8))();

  if (cVar2 != '\0') {

    iVar3 = 0;

    pbVar5 = (byte *)((int)unaff_ESI + 0x22b);

    do {

      auStack_c[iVar3] = (uint)*pbVar5;

      iVar3 = iVar3 + 1;

      pbVar5 = pbVar5 + 4;

    } while (iVar3 < 3);

  }

  if (*(char *)((int)unaff_ESI + 0xca) == '\0') {

    iVar3 = unaff_ESI[300];

    iVar7 = unaff_ESI[0x130];

LAB_0079bc27:

    unaff_ESI[0x8a] = iVar3;

    unaff_ESI[0x8b] = iVar7;

  }

  else if (*(char *)((int)unaff_ESI + 0x489) == '\0') {

    if (*(char *)((int)unaff_ESI + 0x48d) == '\0') {

      if (*(char *)((int)unaff_ESI + 0x48e) != '\0') {

        iVar3 = unaff_ESI[299];

        iVar7 = unaff_ESI[0x12f];

        goto LAB_0079bc27;

      }

      if ((char)unaff_ESI[0x123] == '\0') {

        unaff_ESI[0x8a] = unaff_ESI[0x127];

        unaff_ESI[0x8b] = unaff_ESI[0x128];

      }

      else {

        unaff_ESI[0x8a] = unaff_ESI[0x129];

        unaff_ESI[0x8b] = unaff_ESI[0x12d];

      }

    }

    else {

      unaff_ESI[0x8a] = unaff_ESI[0x12a];

      unaff_ESI[0x8b] = unaff_ESI[0x12e];

    }

  }

  else {

    unaff_ESI[0x8a] = unaff_ESI[0x127];

    unaff_ESI[0x8b] = unaff_ESI[0x128];

  }

  cVar2 = (**(code **)(*unaff_ESI + 0xf8))();

  if (cVar2 != '\0') {

    puVar4 = (uint *)(unaff_ESI + 0x3e);

    iVar3 = 3;

    do {

      *puVar4 = (uint)*(byte *)((int)puVar4 + 0x133);

      puVar4 = puVar4 + 1;

      iVar3 = iVar3 + -1;

    } while (iVar3 != 0);

    iVar3 = 0;

    puVar6 = (uint8_t *)((int)unaff_ESI + 0x22b);

    do {

      *puVar6 = (char)auStack_c[iVar3];

      iVar3 = iVar3 + 1;

      puVar6 = puVar6 + 4;

    } while (iVar3 < 3);

  }

LAB_0079bc81:

  pvVar1 = (void *)unaff_ESI[0xa3];

  if (pvVar1 != (void *)0x0) {

    FUN_00797d70(pvVar1);

                    /* WARNING: Subroutine does not return */

    operator_delete(pvVar1);

  }

  unaff_ESI[0xa3] = 0;

  return;

}
