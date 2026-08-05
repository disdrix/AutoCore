// =============================================================================
// FUN_00605bc0
// -----------------------------------------------------------------------------
// Stable ID: aa_00605bc0
// Address:   0x00605bc0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00605bc0 @ 0x00605bc0
// Stable ID: aa_00605bc0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×1.
//  - Notable callees: FUN_00605bc0, Object_GetRootRaceId.
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

void __thiscall FUN_00605bc0(int param_1,int param_2)



{

  uint32_t /* width from decompiler */ *puVar1;

  uint32_t /* width from decompiler */ uVar2;

  uint32_t /* width from decompiler */ uVar3;

  uint32_t /* width from decompiler */ uVar4;

  int iVar5;

  RACE_ID_INFERRED RVar6;

  

  iVar5 = *(int *)(*(int *)(param_2 + 4) + 4);

  uVar2 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x88 + param_2);

  uVar3 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x8c + param_2);

  uVar4 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x90 + param_2);

  puVar1 = (uint32_t /* width from decompiler */ *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1);

  *puVar1 = *(uint32_t /* width from decompiler */ *)(iVar5 + 0x84 + param_2);

  puVar1[1] = uVar2;

  puVar1[2] = uVar3;

  puVar1[3] = uVar4;

  *(uint8_t *)(param_1 + 0xb0) = *(uint8_t *)(param_2 + 0xb0);

  *(uint32_t /* width from decompiler */ *)(param_1 + 0xb4) = *(uint32_t /* width from decompiler */ *)(param_2 + 0xb4);

  RVar6 = Object_GetRootRaceId((void *)(*(int *)(*(int *)(param_2 + 4) + 4) + 4 + param_2));

  *(RACE_ID_INFERRED *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x14 + param_1) = RVar6;

  if (*(char *)(param_2 + 0xb0) == '\x05') {

    iVar5 = DAT_00af48c4 + 1;

    *(int *)(param_2 + 0xb4) = DAT_00af48c4;

    DAT_00af48c4 = iVar5;

  }

  return;

}
