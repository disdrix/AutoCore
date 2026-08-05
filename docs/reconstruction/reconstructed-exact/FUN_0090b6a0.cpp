// =============================================================================
// FUN_0090b6a0
// -----------------------------------------------------------------------------
// Stable ID: aa_0090b6a0
// Address:   0x0090b6a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0090b6a0 @ 0x0090b6a0
// Stable ID: aa_0090b6a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~70 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0090b6a0, FUN_0097ae30, FUN_0097af80.
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

void FUN_0090b6a0(int param_1,int param_2,int param_3,int param_4)



{

  int iVar1;

  int *piVar2;

  int *unaff_ESI;

  int *piStack_3c;

  uint8_t *puStack_38;

  int iStack_34;

  uint8_t *puStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  int *piStack_28;

  int iStack_20;

  int iStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  uint8_t auStack_8 [8];

  

  if ((-1 < unaff_ESI[0x150]) && (unaff_ESI[0x150] < 5)) {

    if (unaff_ESI[0x140] != 0) {

      FUN_0097ae30();

      FUN_0097af80();

    }

    unaff_ESI[0x143] = param_3;

    uStack_14 = 1;

    unaff_ESI[0x145] = param_1;

    unaff_ESI[0x146] = param_2;

    unaff_ESI[0x144] = param_4;

    unaff_ESI[0x141] = 0;

    uStack_18 = 0x90b71b;

    (**(code **)(*unaff_ESI + 0xcc))();

    uStack_18 = 1;

    iStack_1c = 0x90b72b;

    (**(code **)(*(int *)unaff_ESI[0x140] + 0xcc))();

    iStack_1c = 0x40200000;

    iStack_20 = 1;

    (**(code **)(*(int *)unaff_ESI[0x13f] + 0xfc))();

    if ((int *)unaff_ESI[0x13f] != (int *)0x0) {

      piStack_28 = unaff_ESI + 0x147;

      uStack_2c = 0x90b75e;

      (**(code **)(*(int *)unaff_ESI[0x13f] + 0x130))();

      uStack_2c = 1;

      puStack_30 = auStack_8;

      iStack_34 = 0x90b773;

      iVar1 = (**(code **)(*(int *)unaff_ESI[0x13f] + 0x140))();

      iVar1 = *(int *)(iVar1 + 4);

      iStack_34 = 1;

      puStack_38 = &stack0xffffffdc;

      piStack_3c = (int *)0x90b794;

      piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x13f] + 0x140))();

      iStack_20 = param_1 - *piVar2 / 2;

      piStack_3c = &iStack_20;

      iStack_1c = param_2 - iVar1 / 2;

      (**(code **)(*(int *)unaff_ESI[0x13f] + 0x110))();

      if ((int *)unaff_ESI[0x140] != (int *)0x0) {

        iStack_20 = unaff_ESI[0x14a];

        piStack_3c = (int *)&stack0xffffffdc;

        (**(code **)(*(int *)unaff_ESI[0x140] + 300))();

        iVar1 = (**(code **)(*(int *)unaff_ESI[0x140] + 0x140))(&iStack_20,1);

        iVar1 = *(int *)(iVar1 + 4);

        piVar2 = (int *)(**(code **)(*(int *)unaff_ESI[0x140] + 0x140))(&piStack_3c,1);

        puStack_38 = (uint8_t *)(param_1 - *piVar2 / 2);

        iStack_34 = param_2 - iVar1 / 2;

        (**(code **)(*(int *)unaff_ESI[0x140] + 0x110))(&puStack_38);

      }

    }

    unaff_ESI[0x142] =

         (unaff_ESI[0x144] - unaff_ESI[0x146]) * (unaff_ESI[0x144] - unaff_ESI[0x146]) +

         (unaff_ESI[0x143] - unaff_ESI[0x145]) * (unaff_ESI[0x143] - unaff_ESI[0x145]);

  }

  return;

}
