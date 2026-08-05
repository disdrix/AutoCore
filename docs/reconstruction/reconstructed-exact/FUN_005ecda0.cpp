// =============================================================================
// FUN_005ecda0
// -----------------------------------------------------------------------------
// Stable ID: aa_005ecda0
// Address:   0x005ecda0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005ecda0 @ 0x005ecda0
// Stable ID: aa_005ecda0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~34 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_005ecba0×2, FUN_005ec550, FUN_005ecda0.
//  - Return sites: 5.

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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint32_t /* width from decompiler */ __thiscall FUN_005ecda0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  uint32_t /* width from decompiler */ uVar1;

  float *pfVar2;

  float fVar3;

  uint8_t local_2c [12];

  float local_20;

  float local_1c;

  float local_18;

  float local_10;

  float local_c;

  float local_8;

  

  if (*(int *)(param_1 + 0xc) == 1) {

    return 1;

  }

  if (*(int *)(param_1 + 0xc) != 2) {

    return 5;

  }

  uVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x10);

  FUN_005ecba0(&local_20,uVar1);

  FUN_005ecba0(&local_10,*(uint32_t /* width from decompiler */ *)(param_1 + 0x14));

  pfVar2 = (float *)FUN_005ec550(local_2c,uVar1,param_2);

  fVar3 = local_8 * (pfVar2[1] * local_20 - *pfVar2 * local_1c) +

          local_c * (*pfVar2 * local_18 - pfVar2[2] * local_20) +

          (pfVar2[2] * local_1c - pfVar2[1] * local_18) * local_10;

  if (fVar3 < (float)_DAT_009dcfb0) {

    return 2;

  }

  if (_DAT_009dcfa8 < (double)fVar3) {

    return 3;

  }

  return 4;

}
