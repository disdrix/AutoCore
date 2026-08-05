// =============================================================================
// FUN_00552f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00552f50
// Address:   0x00552f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00552f50 @ 0x00552f50
// Stable ID: aa_00552f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×3, return×2.
//  - Notable callees: FUN_00552f50.
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

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



uint __thiscall FUN_00552f50(int param_1,int param_2)



{

  float fVar1;

  byte bVar2;

  byte bVar3;

  int iVar4;

  uint uVar5;

  

  if (param_2 != 0) {

    bVar2 = *(byte *)(param_1 + 0x5f4);

    fVar1 = *(float *)(param_1 + 4);

    bVar3 = *(byte *)(param_1 + 0x5fb);

    iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x27c))();

    if ((int)((float)(int)(iVar4 - (uint)bVar3) * fVar1 + _DAT_00aaac14) < (int)(uint)bVar2) {

      fVar1 = *(float *)(param_1 + 4);

      bVar2 = *(byte *)(param_1 + 0x5fb);

      iVar4 = (**(code **)(*(int *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2) + 0x27c))();

      uVar5 = (uint)((float)(int)(iVar4 - (uint)bVar2) * fVar1 + _DAT_00aaac14);

    }

    else {

      uVar5 = (uint)*(byte *)(param_1 + 0x5f4);

    }

    if (-1 < (int)uVar5) {

      return uVar5;

    }

  }

  return 0;

}
