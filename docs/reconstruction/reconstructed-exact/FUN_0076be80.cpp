// =============================================================================
// FUN_0076be80
// -----------------------------------------------------------------------------
// Stable ID: aa_0076be80
// Address:   0x0076be80  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0076be80 @ 0x0076be80
// Stable ID: aa_0076be80
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~40 non-empty decompiler lines.
//  - Control keywords: if×4, return×3, for×2, do×1, while×1.
//  - Notable callees: FUN_0076be80, realloc.
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

uint32_t /* width from decompiler */ __thiscall FUN_0076be80(int param_1,uint32_t /* width from decompiler */ *param_2,uint param_3)



{

  int iVar1;

  size_t _NewSize;

  void *pvVar2;

  uint uVar3;

  uint32_t /* width from decompiler */ *puVar4;

  

  if (*(char *)(param_1 + 0x15) == '\0') {

    return 0xffffffff;

  }

  _NewSize = *(size_t *)(param_1 + 0x10);

  iVar1 = *(int *)(param_1 + 8) + param_3;

  if ((int)_NewSize < iVar1) {

    if (*(char *)(param_1 + 0x14) == '\0') {

      return 0xffffffff;

    }

    do {

      _NewSize = (int)(_NewSize * 0x67 + ((int)(_NewSize * 0x67) >> 0x1f & 0x3fU)) >> 6;

    } while ((int)_NewSize < iVar1);

    *(size_t *)(param_1 + 0x10) = _NewSize;

    pvVar2 = realloc(*(void **)(param_1 + 4),_NewSize);

    *(void **)(param_1 + 4) = pvVar2;

  }

  puVar4 = (uint32_t /* width from decompiler */ *)(*(int *)(param_1 + 4) + *(int *)(param_1 + 8));

  for (uVar3 = param_3 >> 2; uVar3 != 0; uVar3 = uVar3 - 1) {

    *puVar4 = *param_2;

    param_2 = param_2 + 1;

    puVar4 = puVar4 + 1;

  }

  for (uVar3 = param_3 & 3; uVar3 != 0; uVar3 = uVar3 - 1) {

    *(uint8_t *)puVar4 = *(uint8_t *)param_2;

    param_2 = (uint32_t /* width from decompiler */ *)((int)param_2 + 1);

    puVar4 = (uint32_t /* width from decompiler */ *)((int)puVar4 + 1);

  }

  *(int *)(param_1 + 8) = *(int *)(param_1 + 8) + param_3;

  if (*(int *)(param_1 + 0xc) < *(int *)(param_1 + 8)) {

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 8);

  }

  return 0;

}
