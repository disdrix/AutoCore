// =============================================================================
// FUN_008d76f0
// -----------------------------------------------------------------------------
// Stable ID: aa_008d76f0
// Address:   0x008d76f0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_008d76f0 @ 0x008d76f0
// Stable ID: aa_008d76f0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004e8320, FUN_004f5c30, FUN_008d76f0.
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

void FUN_008d76f0(void)



{

  int *piVar1;

  int iVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int unaff_EBX;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint32_t /* width from decompiler */ uStack_10;

  uint8_t auStack_c [12];

  

  piVar1 = *(int **)(unaff_EBX + 0x548);

  if (piVar1 != (int *)0x0) {

    (**(code **)(*piVar1 + 0x44))();

    uStack_18 = *(uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x3c) + 0x4f4);

    uStack_14 = *(uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x3c) + 0x4f8);

    uStack_10 = *(uint32_t /* width from decompiler */ *)

                 (*(int *)(*(int *)(*(int *)(piVar1[1] + 4) + 0xac + (int)piVar1) + 0x3c) + 0x4fc);

    if ((int *)piVar1[0x12] == (int *)0x0) {

      puVar4 = &DAT_00afdfec;

    }

    else {

      iVar2 = (**(code **)(*(int *)piVar1[0x12] + 0xc))();

      puVar4 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x80);

    }

    if ((int *)piVar1[0x12] == (int *)0x0) {

      puVar3 = &DAT_00d1a6c0;

    }

    else {

      iVar2 = (**(code **)(*(int *)piVar1[0x12] + 0xc))();

      puVar3 = (uint32_t /* width from decompiler */ *)(iVar2 + 0x90);

    }

    FUN_004e8320(puVar3,puVar4,&uStack_18,auStack_c);

    (**(code **)(*(int *)piVar1[0xe8] + 0x18))(auStack_c);

    piVar1 = (int *)piVar1[0xe8];

    if (piVar1 != (int *)0x0) {

      iVar2 = (**(code **)(**(int **)(*(int *)(unaff_EBX + 0x548) + 0x48) + 0xc))();

      (**(code **)(*piVar1 + 0x14))(iVar2 + 0x80);

    }

    FUN_004f5c30();

  }

  return;

}
