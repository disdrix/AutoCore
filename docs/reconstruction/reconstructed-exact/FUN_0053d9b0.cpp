// =============================================================================
// FUN_0053d9b0
// -----------------------------------------------------------------------------
// Stable ID: aa_0053d9b0
// Address:   0x0053d9b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0053d9b0 @ 0x0053d9b0
// Stable ID: aa_0053d9b0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~49 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_0053d9b0, SQRT.
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

void __fastcall FUN_0053d9b0(int *param_1)



{

  float fVar1;

  float fVar2;

  float fVar3;

  float fStack_7c;

  float fStack_78;

  float fStack_74;

  uint8_t auStack_70 [4];

  float fStack_6c;

  float fStack_68;

  float fStack_64;

  float afStack_50 [6];

  uint32_t /* width from decompiler */ uStack_38;

  uint32_t /* width from decompiler */ uStack_34;

  uint32_t /* width from decompiler */ uStack_30;

  uint32_t /* width from decompiler */ uStack_2c;

  float fStack_28;

  uint32_t /* width from decompiler */ uStack_24;

  uint32_t /* width from decompiler */ uStack_20;

  uint32_t /* width from decompiler */ uStack_1c;

  uint32_t /* width from decompiler */ uStack_18;

  uint32_t /* width from decompiler */ uStack_14;

  

  (**(code **)(*param_1 + 0xc))();

  if (param_1[2] != 0) {

    afStack_50[3] = 0.0;

    afStack_50[2] = 0.0;

    afStack_50[1] = 0.0;

    uStack_34 = 0;

    uStack_38 = 0;

    afStack_50[4] = 0.0;

    uStack_24 = 0;

    uStack_2c = 0;

    uStack_30 = 0;

    afStack_50[0] = g_flOne;

    afStack_50[5] = g_flOne;

    fStack_28 = g_flOne;

    uStack_14 = 0;

    uStack_18 = 0;

    uStack_1c = 0;

    uStack_20 = 0;

    (**(code **)(**(int **)(param_1[2] + 0xc) + 0x18))(afStack_50,0x3dcccccd,auStack_70);

    fVar3 = (fStack_64 - fStack_74) * DAT_00a0f298;

    fVar2 = (fStack_68 - fStack_78) * DAT_00a0f298;

    fVar1 = (fStack_6c - fStack_7c) * DAT_00a0f298;

    param_1[0xd] = (int)SQRT(fVar1 * fVar1 + fVar2 * fVar2 + fVar3 * fVar3);

  }

  return;

}
