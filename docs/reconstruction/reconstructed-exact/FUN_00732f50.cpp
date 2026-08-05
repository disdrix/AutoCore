// =============================================================================
// FUN_00732f50
// -----------------------------------------------------------------------------
// Stable ID: aa_00732f50
// Address:   0x00732f50  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00732f50 @ 0x00732f50
// Stable ID: aa_00732f50
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×4, for×2, return×1.
//  - Notable callees: FUN_00732f50, memmove.
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

void __fastcall FUN_00732f50(int param_1)



{

  uint32_t /* width from decompiler */ *puVar1;

  void *_Src;

  void *pvVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  if (*(int **)(param_1 + 0x5c) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x5c) + 0xc))();

  }

  if (*(int **)(param_1 + 0x58) != (int *)0x0) {

    (**(code **)(**(int **)(param_1 + 0x58) + 0xc))();

  }

  puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x30);

  for (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x2c); puVar3 != puVar1; puVar3 = puVar3 + 1) {

    (**(code **)(*(int *)*puVar3 + 0xc))();

  }

  if (*(int *)(param_1 + 0x58) != 0) {

    puVar1 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x40);

    for (puVar3 = *(uint32_t /* width from decompiler */ **)(param_1 + 0x3c); puVar3 != puVar1; puVar3 = puVar3 + 1) {

      (**(code **)(*(int *)*puVar3 + 0xc))();

    }

  }

  *(uint8_t *)(param_1 + 0x68) = 0;

  *(uint8_t *)(param_1 + 0x69) = 0;

  pvVar2 = *(void **)(param_1 + 0x4c);

  if (((pvVar2 != (void *)0x0) &&

      (_Src = *(void **)(param_1 + 0x50), (int)_Src - (int)pvVar2 >> 2 != 0)) && (pvVar2 != _Src)) {

    pvVar2 = memmove(pvVar2,_Src,0);

    *(void **)(param_1 + 0x50) = pvVar2;

  }

  return;

}
