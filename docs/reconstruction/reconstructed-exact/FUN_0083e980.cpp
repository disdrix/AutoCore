// =============================================================================
// FUN_0083e980
// -----------------------------------------------------------------------------
// Stable ID: aa_0083e980
// Address:   0x0083e980  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0083e980 @ 0x0083e980
// Stable ID: aa_0083e980
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0083e980.
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

void __fastcall FUN_0083e980(int *param_1)



{

  int iVar1;

  int *piVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint8_t **ppuStack_40;

  int iStack_3c;

  uint32_t /* width from decompiler */ *puStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  uint8_t *puStack_28;

  uint8_t *puStack_24;

  uint8_t local_10 [16];

  

  if ((param_1[0x140] != 0) && (param_1[0x13f] != 0)) {

    puStack_24 = local_10;

    puStack_28 = (uint8_t *)0x83e9b4;

    (**(code **)(*(int *)param_1[0x140] + 0x134))();

    puStack_28 = &stack0xffffffe4;

    uStack_2c = 0x83e9ef;

    (**(code **)(*(int *)param_1[0x140] + 300))();

    iVar1 = *(int *)param_1[0x140];

    uStack_2c = 1;

    uStack_30 = 1;

    uStack_34 = 0x83ea05;

    uStack_34 = (**(code **)(*param_1 + 0x1dc))();

    puStack_38 = (uint32_t /* width from decompiler */ *)0x83ea12;

    (**(code **)(iVar1 + 0x1d8))();

    puStack_38 = (uint32_t /* width from decompiler */ *)0x83ea20;

    (**(code **)(*(int *)param_1[0x140] + 0x13c))();

    puStack_38 = &uStack_2c;

    uStack_2c = 5;

    puStack_28 = (uint8_t *)0x6;

    iStack_3c = 0x83ea43;

    (**(code **)(*(int *)param_1[0x140] + 0x110))();

    iStack_3c = 1;

    ppuStack_40 = &puStack_28;

    iVar1 = (**(code **)(*(int *)param_1[0x140] + 0x140))();

    iVar1 = *(int *)(iVar1 + 4);

    piVar2 = (int *)(**(code **)(*(int *)param_1[0x140] + 0x140))(&puStack_28,1);

    ppuStack_40 = (uint8_t **)(*piVar2 + 10);

    iStack_3c = iVar1 + 0xc;

    (**(code **)(*(int *)param_1[0x13f] + 300))(&ppuStack_40);

    iVar1 = *param_1;

    uVar3 = (**(code **)(*(int *)param_1[0x13f] + 0x140))(&uStack_34,1);

    (**(code **)(iVar1 + 0x138))(uVar3);

  }

  return;

}
