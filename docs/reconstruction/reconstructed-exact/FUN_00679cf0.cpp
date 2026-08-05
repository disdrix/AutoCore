// =============================================================================
// FUN_00679cf0
// -----------------------------------------------------------------------------
// Stable ID: aa_00679cf0
// Address:   0x00679cf0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00679cf0 @ 0x00679cf0
// Stable ID: aa_00679cf0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~37 non-empty decompiler lines.
//  - Control keywords: for×4, return×2, if×1.
//  - Notable callees: FUN_00679cf0, acmStreamConvert.
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

uint32_t /* width from decompiler */ __thiscall

FUN_00679cf0(int param_1,uint32_t /* width from decompiler */ *param_2,uint32_t /* width from decompiler */ *param_3,uint param_4,uint32_t /* width from decompiler */ *param_5)



{

  int iVar1;

  uint uVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x420);

  for (uVar2 = param_4 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {

    *puVar4 = *param_2;

    param_2 = param_2 + 1;

    puVar4 = puVar4 + 1;

  }

  for (param_4 = param_4 & 3; param_4 != 0; param_4 = param_4 - 1) {

    *(uint8_t *)puVar4 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  iVar1 = acmStreamConvert(*(uint32_t /* width from decompiler */ *)(param_1 + 0x3a8),param_1 + 0x3ac,4);

  if (iVar1 != 0) {

    return 0xffffffff;

  }

  uVar2 = *(uint *)(param_1 + 0x41c);

  puVar4 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x424);

  for (uVar3 = uVar2 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *param_3 = *puVar4;

    puVar4 = puVar4 + 1;

    param_3 = param_3 + 1;

  }

  for (uVar2 = uVar2 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {

    *(uint8_t *)param_3 = *(uint8_t *)puVar4;

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

    param_3 = (uint32_t /* width from decompiler */ *)((int)param_3 + 1);

  }

  *param_5 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x41c);

  return 0;

}
