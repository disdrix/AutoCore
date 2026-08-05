// =============================================================================
// FUN_0084b660
// -----------------------------------------------------------------------------
// Stable ID: aa_0084b660
// Address:   0x0084b660  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0084b660 @ 0x0084b660
// Stable ID: aa_0084b660
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0084b660, NDUIWindow_ReloadInterface.
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

void __thiscall FUN_0084b660(int *param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int iVar2;

  uint8_t auStack_8 [8];

  

  param_1[0x148] = -1;

  param_1[0x149] = -1;

  DAT_00d1791c = 0;

  param_1[0x146] = 0;

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  NDUIWindow_ReloadInterface(param_2);

  piVar1 = (int *)(**(code **)(*param_1 + 0x120))(auStack_8,1,0);

  param_1[0x143] = *piVar1;

  param_1[0x144] = piVar1[1];

  if ((int *)param_1[0x14d] != (int *)0x0) {

    iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a8))();

    *(uint8_t *)(iVar2 + 0x78) = 0;

    iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

    if (iVar2 != 0) {

      iVar2 = (**(code **)(*(int *)param_1[0x14d] + 0x1a0))();

      *(float *)(iVar2 + 0xf0) = g_flMsToSeconds_Inferred;

      *(uint8_t *)(iVar2 + 0x48) = 1;

      *(uint8_t *)(iVar2 + 0xcc) = 1;

    }

  }

  if ((char)param_1[0x14a] != '\0') {

    *(uint8_t *)((int)param_1 + 0xc5) = 1;

    *(uint8_t *)((int)param_1 + 0xcd) = 0;

    if (param_1[0x14b] != 0) {

      *(uint8_t *)(param_1[0x14b] + 0xc4) = 1;

      *(uint8_t *)(param_1[0x14b] + 0xcd) = 0;

    }

  }

  (**(code **)(*param_1 + 0x448))();

  (**(code **)(*param_1 + 0x34c))();

  return;

}
