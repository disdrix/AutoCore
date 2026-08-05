// =============================================================================
// FUN_006562d0
// -----------------------------------------------------------------------------
// Stable ID: aa_006562d0
// Address:   0x006562d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_006562d0 @ 0x006562d0
// Stable ID: aa_006562d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~88 non-empty decompiler lines.
//  - Control keywords: return×8, switch×1.
//  - Notable callees: FUN_00641900×14, FUN_00641940×14, FUN_006561e0×4, FUN_006588b0×4, FUN_006574c0×2, FUN_00657d50×2, FUN_0066b6e0×2, FUN_006416b0.
//  - Return sites: 8.

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

void FUN_006562d0(int param_1)



{

  int iVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ *puVar3;

  float10 fVar4;

  uint8_t local_80 [16];

  uint8_t local_70 [16];

  uint8_t local_60 [16];

  uint8_t local_50 [16];

  uint8_t local_40 [16];

  uint8_t local_30 [16];

  uint8_t local_20 [28];

  

  uVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x54);

  FUN_006416b0(uVar2);

  switch(uVar2) {

  case 1:

    FUN_006561e0(param_1 + 0x10);

    iVar1 = FUN_006588b0(local_80);

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(iVar1 + 0xc));

    uVar2 = FUN_006588b0(local_70);

    FUN_00641940(uVar2,3);

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x70));

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x74));

    return;

  case 2:

    FUN_006561e0(param_1 + 0x10);

    FUN_00641940(param_1 + 0x60,3);

    return;

  case 3:

    uVar2 = FUN_00657d50();

    FUN_00641940(uVar2,3);

    uVar2 = FUN_0066b6e0();

    FUN_00641940(uVar2,3);

    return;

  case 4:

    uVar2 = FUN_006588b0(local_60);

    FUN_00641940(uVar2,3);

    uVar2 = FUN_006574c0(local_50);

    FUN_00641940(uVar2,3);

    fVar4 = (float10)FUN_006574a0();

    FUN_00641900((float)fVar4);

    fVar4 = (float10)FUN_00657490();

    FUN_00641900((float)fVar4);

    uVar2 = FUN_006574b0();

    FUN_00641900(uVar2);

    return;

  case 5:

    uVar2 = FUN_00656660(local_40);

    FUN_00641940(uVar2,3);

    uVar2 = FUN_006588b0(local_30);

    FUN_00641940(uVar2,3);

    uVar2 = FUN_006574c0(local_20);

    FUN_00641940(uVar2,3);

    fVar4 = (float10)FUN_00656640();

    FUN_00641900((float)fVar4);

    fVar4 = (float10)FUN_00656620();

    FUN_00641900((float)fVar4);

    fVar4 = (float10)FUN_00656630();

    FUN_00641900((float)fVar4);

    uVar2 = FUN_00656650();

    FUN_00641900(uVar2);

    return;

  case 6:

    FUN_006561e0(param_1 + 0x10);

    FUN_00656150(*(uint32_t /* width from decompiler */ *)(param_1 + 0x50));

    return;

  case 7:

    uVar2 = FUN_0066b6e0();

    FUN_00641940(uVar2,3);

    uVar2 = FUN_00657d50();

    FUN_00641940(uVar2,3);

    uVar2 = FUN_00656be0();

    FUN_00641940(uVar2,3);

    puVar3 = (uint32_t /* width from decompiler */ *)FUN_00656bf0();

    FUN_00641900(*puVar3);

    break;

  case 8:

    FUN_006561e0(param_1 + 0x10);

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x80));

    FUN_00641940(param_1 + 0x60,3);

    FUN_00641940(param_1 + 0x70,3);

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x84));

    FUN_00641900(*(uint32_t /* width from decompiler */ *)(param_1 + 0x88));

    return;

  }

  return;

}
