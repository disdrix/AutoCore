// =============================================================================
// FUN_005df500
// -----------------------------------------------------------------------------
// Stable ID: aa_005df500
// Address:   0x005df500  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005df500 @ 0x005df500
// Stable ID: aa_005df500
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×5, return×1.
//  - Notable callees: FUN_005a4e60, FUN_005de900, FUN_005dec90, FUN_005ded20, FUN_005df250, FUN_005df500.
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

uint32_t /* width from decompiler */ FUN_005df500(void)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *pvVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  int iVar5;

  

  if (DAT_00bc56a4 == '\0') {

    pvVar2 = operator_new(0x4340);

    if (pvVar2 == (void *)0x0) {

      uVar3 = 0;

    }

    else {

      uVar3 = FUN_005de900();

    }

    FUN_005a4e60(uVar3);

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(8,0x13);

    *(uint16_t *)(puVar4 + 1) = 8;

    *(uint16_t *)((int)puVar4 + 6) = 1;

    *puVar4 = &PTR_LAB_009dbaf0;

    puVar1 = DAT_00d030f0;

    if ((DAT_00d030f0 != (uint32_t /* width from decompiler */ *)0x0) &&

       (*(short *)((int)DAT_00d030f0 + 6) = *(short *)((int)DAT_00d030f0 + 6) + -1,

       *(short *)((int)puVar1 + 6) == 0)) {

      (**(code **)*puVar1)(1);

    }

    DAT_00d030f0 = puVar4;

    iVar5 = (**(code **)(*DAT_00b05060 + 0x10))(0x20,0x13);

    *(uint16_t *)(iVar5 + 4) = 0x20;

    puVar4 = (uint32_t /* width from decompiler */ *)FUN_005ded20();

    puVar1 = DAT_00d030e0;

    if ((DAT_00d030e0 != (uint32_t /* width from decompiler */ *)0x0) &&

       (*(short *)((int)DAT_00d030e0 + 6) = *(short *)((int)DAT_00d030e0 + 6) + -1,

       *(short *)((int)puVar1 + 6) == 0)) {

      (**(code **)*puVar1)(1);

    }

    DAT_00d030e0 = puVar4;

    puVar4 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x20,0x13);

    *(uint16_t *)(puVar4 + 1) = 0x20;

    *(uint16_t *)((int)puVar4 + 6) = 1;

    *puVar4 = &PTR_FUN_00a9ac2c;

    puVar4[2] = 0;

    puVar4[3] = 0;

    puVar4[4] = 0x80000000;

    puVar4[5] = 0;

    puVar4[6] = 0;

    puVar4[7] = 0x80000000;

    puVar1 = DAT_00bc56d0;

    if ((DAT_00bc56d0 != (uint32_t /* width from decompiler */ *)0x0) &&

       (*(short *)((int)DAT_00bc56d0 + 6) = *(short *)((int)DAT_00bc56d0 + 6) + -1,

       *(short *)((int)puVar1 + 6) == 0)) {

      (**(code **)*puVar1)(1);

    }

    DAT_00bc56d0 = puVar4;

    FUN_005df250();

    (**(code **)(*DAT_00bc56a0 + 4))();

    DAT_00bc56a4 = '\x01';

    FUN_005dec90();

  }

  return 0;

}
