// =============================================================================
// FUN_00950450
// -----------------------------------------------------------------------------
// Stable ID: aa_00950450
// Address:   0x00950450  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00950450 @ 0x00950450
// Stable ID: aa_00950450
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×3, return×2, do×1, while×1.
//  - Notable callees: strtok×2, FUN_0090e1b0, FUN_00950450, atof.
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

uint32_t /* width from decompiler */ __thiscall FUN_00950450(int param_1,uint32_t /* width from decompiler */ param_2,char *param_3)



{

  char *_String;

  int iVar1;

  double dVar2;

  float local_18 [4];

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  _String = strtok((char *)0x0,param_3);

  if (_String != (char *)0x0) {

    iVar1 = 0;

    do {

      dVar2 = atof(_String);

      local_18[iVar1] = (float)dVar2;

      iVar1 = iVar1 + 1;

      _String = strtok((char *)0x0,param_3);

    } while (_String != (char *)0x0);

    if (iVar1 == 3) {

      iVar1 = *(int *)(param_1 + 0xf38);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcc4) = 8;

      *(uint8_t *)(iVar1 + 0xa82) = 0;

      *(float *)(DAT_00d1b628 + 0x228) = local_18[0];

      *(float *)(DAT_00d1b628 + 0x22c) = local_18[1];

      *(float *)(DAT_00d1b628 + 0x230) = local_18[2];

      return 1;

    }

    if (iVar1 == 6) {

      iVar1 = *(int *)(param_1 + 0xf38);

      *(uint32_t /* width from decompiler */ *)(iVar1 + 0xcc4) = 8;

      *(uint8_t *)(iVar1 + 0xa82) = 0;

      *(float *)(DAT_00d1b628 + 0x228) = local_18[0];

      *(float *)(DAT_00d1b628 + 0x22c) = local_18[1];

      *(float *)(DAT_00d1b628 + 0x230) = local_18[2];

      *(float *)(DAT_00d1b628 + 0x21c) = local_18[3];

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x220) = local_8;

      *(uint32_t /* width from decompiler */ *)(DAT_00d1b628 + 0x224) = local_4;

      FUN_0090e1b0(local_18[3],local_8,local_4);

    }

  }

  return 1;

}
