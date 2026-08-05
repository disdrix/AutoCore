// =============================================================================
// FUN_00822cb0
// -----------------------------------------------------------------------------
// Stable ID: aa_00822cb0
// Address:   0x00822cb0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00822cb0 @ 0x00822cb0
// Stable ID: aa_00822cb0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~116 non-empty decompiler lines.
//  - Control keywords: if×12, goto×4, return×2.
//  - Notable callees: CONCAT13×2, FUN_00822cb0.
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

void FUN_00822cb0(char param_1)



{

  char cVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int *piVar4;

  char unaff_BL;

  int *unaff_ESI;

  int iStack_30;

  int iStack_2c;

  undefined3 *puStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint8_t auStack_14 [4];

  uint8_t auStack_10 [8];

  uint8_t auStack_8 [4];

  undefined3 uStack_4;

  byte bStack_1;

  

  if ((param_1 == '\0') && ((char)unaff_ESI[0x13f] == unaff_BL)) {

    return;

  }

  piVar4 = (int *)unaff_ESI[0x206];

  if (unaff_BL == '\0') {

    if (piVar4 != (int *)0x0) {

      uStack_20 = 1;

      uStack_24 = 0x822dbd;

      cVar1 = (**(code **)(*piVar4 + 0xf0))();

      if (cVar1 == '\0') {

LAB_00822dea:

        uStack_24 = 1;

        puStack_28 = (undefined3 *)0x822dfa;

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_ESI[0x206] + 0x164))();

        uStack_4 = (undefined3)*puVar3;

        _uStack_4 = CONCAT13(*(byte *)((int)unaff_ESI + 0x4fd) >> 1,uStack_4);

        puStack_28 = &uStack_4;

        iStack_2c = 1;

        iStack_30 = 0x822e21;

        (**(code **)(*(int *)unaff_ESI[0x206] + 0x15c))();

      }

      else {

        uStack_24 = 0x822dcf;

        iVar2 = (**(code **)(*(int *)unaff_ESI[0x206] + 0xe8))();

        if (iVar2 == 0) goto LAB_00822dea;

        *(uint *)(unaff_ESI[0x206] + 0xfc) = (uint)(*(byte *)((int)unaff_ESI + 0x4fd) >> 1);

      }

      uStack_24 = 0x822e2f;

      (**(code **)(*(int *)unaff_ESI[0x206] + 0x34c))();

    }

    if ((int *)unaff_ESI[0x205] != (int *)0x0) {

      uStack_20 = 1;

      uStack_24 = 0;

      puStack_28 = (undefined3 *)0x822e45;

      (**(code **)(*(int *)unaff_ESI[0x205] + 0x3c8))();

    }

    if ((char)unaff_ESI[0x13f] == '\0') goto LAB_00822e9c;

    uStack_20 = 0;

    uStack_24 = 1;

    puStack_28 = (undefined3 *)auStack_8;

    iStack_2c = 0x822e61;

    iVar2 = (**(code **)(*unaff_ESI + 0x120))();

    iVar2 = *(int *)(iVar2 + 4) + unaff_ESI[0x204];

    iStack_2c = 0;

    iStack_30 = 1;

    piVar4 = (int *)(**(code **)(*unaff_ESI + 0x120))(&stack0xffffffe4);

    iStack_30 = unaff_ESI[0x203] + *piVar4;

  }

  else {

    if (piVar4 != (int *)0x0) {

      uStack_20 = 1;

      uStack_24 = 0x822ce3;

      cVar1 = (**(code **)(*piVar4 + 0xf0))();

      if (cVar1 == '\0') {

LAB_00822d0e:

        uStack_24 = 1;

        puStack_28 = (undefined3 *)0x822d1e;

        puVar3 = (uint32_t /* width from decompiler */ *)(**(code **)(*(int *)unaff_ESI[0x206] + 0x164))();

        uStack_4 = (undefined3)*puVar3;

        _uStack_4 = CONCAT13(*(uint8_t *)((int)unaff_ESI + 0x4fd),uStack_4);

        puStack_28 = &uStack_4;

        iStack_2c = 1;

        iStack_30 = 0x822d43;

        (**(code **)(*(int *)unaff_ESI[0x206] + 0x15c))();

      }

      else {

        uStack_24 = 0x822cf5;

        iVar2 = (**(code **)(*(int *)unaff_ESI[0x206] + 0xe8))();

        if (iVar2 == 0) goto LAB_00822d0e;

        *(uint *)(unaff_ESI[0x206] + 0xfc) = (uint)*(byte *)((int)unaff_ESI + 0x4fd);

      }

      uStack_24 = 0x822d51;

      (**(code **)(*(int *)unaff_ESI[0x206] + 0x34c))();

    }

    if ((int *)unaff_ESI[0x205] != (int *)0x0) {

      uStack_20 = 1;

      uStack_24 = 1;

      puStack_28 = (undefined3 *)0x822d67;

      (**(code **)(*(int *)unaff_ESI[0x205] + 0x3c8))();

    }

    if ((char)unaff_ESI[0x13f] == unaff_BL) goto LAB_00822e9c;

    uStack_20 = 0;

    uStack_24 = 1;

    puStack_28 = (undefined3 *)auStack_10;

    iStack_2c = 0x822d86;

    iVar2 = (**(code **)(*unaff_ESI + 0x120))();

    iVar2 = *(int *)(iVar2 + 4) - unaff_ESI[0x204];

    iStack_2c = 0;

    iStack_30 = 1;

    piVar4 = (int *)(**(code **)(*unaff_ESI + 0x120))(auStack_14);

    iStack_30 = *piVar4 - unaff_ESI[0x203];

  }

  iStack_2c = iVar2;

  (**(code **)(*unaff_ESI + 0x110))(&iStack_30);

LAB_00822e9c:

  *(char *)(unaff_ESI + 0x13f) = unaff_BL;

  return;

}
