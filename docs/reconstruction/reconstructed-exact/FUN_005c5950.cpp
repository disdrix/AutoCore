// =============================================================================
// FUN_005c5950
// -----------------------------------------------------------------------------
// Stable ID: aa_005c5950
// Address:   0x005c5950  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c5950 @ 0x005c5950
// Stable ID: aa_005c5950
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~61 non-empty decompiler lines.
//  - Control keywords: if×6, return×3, goto×2.
//  - Notable callees: CONCAT22, FUN_005c5950, FUN_005c5cd0, FUN_005c6170.
//  - Return sites: 3.

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

uint32_t /* width from decompiler */ __thiscall FUN_005c5950(int param_1,float param_2)



{

  int iVar1;

  uint16_t uVar2;

  int *piVar3;

  uint16_t *puVar4;

  uint32_t /* width from decompiler */ uVar5;

  uint8_t local_34 [4];

  float local_30;

  float local_2c;

  uint32_t /* width from decompiler */ local_28;

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  float local_1c;

  uint32_t /* width from decompiler */ local_18;

  uint32_t /* width from decompiler */ local_14;

  uint32_t /* width from decompiler */ local_10;

  uint32_t /* width from decompiler */ local_c;

  uint32_t /* width from decompiler */ local_8;

  uint32_t /* width from decompiler */ local_4;

  

  piVar3 = (int *)FUN_005c5cd0(local_34,&param_2);

  iVar1 = *piVar3;

  if (iVar1 != *(int *)(param_1 + 0xc)) {

    return CONCAT22((short)((uint)iVar1 >> 0x10),*(uint16_t *)(iVar1 + 0x10));

  }

  local_28 = 0;

  local_24 = 0;

  local_20 = 0;

  local_1c = g_flOne;

  local_18 = 0;

  local_14 = 0;

  local_10 = 0;

  local_c = 0;

  local_8 = 0;

  local_4 = 0;

  if (0.0 <= param_2) {

    if (g_flOne < param_2) {

      local_30 = g_flOne;

      goto LAB_005c59e3;

    }

    if (0.0 <= param_2) {

      local_30 = param_2;

      goto LAB_005c59e3;

    }

  }

  local_30 = 0.0;

LAB_005c59e3:

  local_2c = 0.0;

  if (0.0 <= param_2) {

    local_2c = param_2;

  }

  piVar3 = (int *)(**(code **)(**(int **)(param_1 + 4) + 0x30))(&local_30);

  if (piVar3 != (int *)0x0) {

    puVar4 = (uint16_t *)FUN_005c6170(&stack0x00000000);

    uVar2 = (**(code **)(*piVar3 + 4))();

    *puVar4 = uVar2;

    uVar5 = (**(code **)(*piVar3 + 4))();

    return uVar5;

  }

  return 0;

}
