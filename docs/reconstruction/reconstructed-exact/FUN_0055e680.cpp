// =============================================================================
// FUN_0055e680
// -----------------------------------------------------------------------------
// Stable ID: aa_0055e680
// Address:   0x0055e680  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0055e680 @ 0x0055e680
// Stable ID: aa_0055e680
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~38 non-empty decompiler lines.
//  - Control keywords: if×3, return×1.
//  - Notable callees: FUN_006cb060×3, FUN_0055e680, FUN_0062acc0, FUN_0062b380.
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

uint16_t __fastcall FUN_0055e680(uint32_t /* width from decompiler */ param_1)



{

  short *psVar1;

  uint16_t uVar2;

  int iVar3;

  uint32_t /* width from decompiler */ *puVar4;

  uint32_t /* width from decompiler */ *puVar5;

  uint32_t /* width from decompiler */ *puVar6;

  

  iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,0x1d);

  *(uint16_t *)(iVar3 + 4) = 0xc;

  puVar4 = (uint32_t /* width from decompiler */ *)FUN_0062b380(param_1);

  iVar3 = (**(code **)(*DAT_00b05060 + 0x10))(0xc,0x1d);

  *(uint16_t *)(iVar3 + 4) = 0xc;

  puVar5 = (uint32_t /* width from decompiler */ *)FUN_0062acc0(param_1);

  puVar6 = (uint32_t /* width from decompiler */ *)(**(code **)(*DAT_00b05060 + 0x10))(0x10,4);

  *(uint16_t *)(puVar6 + 1) = 0x10;

  *(uint16_t *)((int)puVar6 + 6) = 1;

  *puVar6 = &PTR_FUN_009d27ec;

  puVar6[2] = &PTR_LAB_009d27c0;

  FUN_006cb060(puVar4,1);

  FUN_006cb060(puVar5,2);

  FUN_006cb060(puVar6,3);

  psVar1 = (short *)((int)puVar4 + 6);

  *psVar1 = *psVar1 + -1;

  uVar2 = *(uint16_t *)((int)puVar4 + 6);

  if (*psVar1 == 0) {

    uVar2 = (**(code **)*puVar4)(1);

  }

  *(short *)((int)puVar5 + 6) = *(short *)((int)puVar5 + 6) + -1;

  if (*(short *)((int)puVar5 + 6) == 0) {

    uVar2 = (**(code **)*puVar5)(1);

  }

  *(short *)((int)puVar6 + 6) = *(short *)((int)puVar6 + 6) + -1;

  if (*(short *)((int)puVar6 + 6) == 0) {

    uVar2 = (**(code **)*puVar6)(1);

  }

  return uVar2;

}
