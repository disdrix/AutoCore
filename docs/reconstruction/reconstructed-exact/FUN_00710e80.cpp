// =============================================================================
// FUN_00710e80
// -----------------------------------------------------------------------------
// Stable ID: aa_00710e80
// Address:   0x00710e80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00710e80 @ 0x00710e80
// Stable ID: aa_00710e80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~27 non-empty decompiler lines.
//  - Control keywords: return×5, if×4.
//  - Notable callees: FUN_00710e80, FUN_00712850, FUN_00712c50.
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

uint32_t /* width from decompiler */ FUN_00710e80(int *param_1)



{

  int iVar1;

  short sVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if ((param_1 == (int *)0x0) || (*param_1 != 0xface)) {

    return 0x17d4;

  }

  iVar1 = param_1[4];

  puVar3 = (uint32_t /* width from decompiler */ *)(*(code *)PTR_calloc_00af8a48)(1,0x20);

  *(uint32_t /* width from decompiler */ **)(iVar1 + 0x4c) = puVar3;

  if (puVar3 == (uint32_t /* width from decompiler */ *)0x0) {

    return 6000;

  }

  sVar2 = FUN_00712c50(puVar3 + 1,0xa0,0x45fa0000);

  if (sVar2 != 0) {

    return 6000;

  }

  sVar2 = FUN_00712850(puVar3 + 2);

  if (sVar2 != 0) {

    return 6000;

  }

  *puVar3 = param_1;

  *(uint8_t *)((int)puVar3 + 0x1e) = 0;

  *(uint16_t *)(puVar3 + 5) = 0;

  return 0;

}
