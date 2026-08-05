// =============================================================================
// FUN_004c5fe0
// -----------------------------------------------------------------------------
// Stable ID: aa_004c5fe0
// Address:   0x004c5fe0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004c5fe0 @ 0x004c5fe0
// Stable ID: aa_004c5fe0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGSpawnPoint_SetObjectActiveState×2, FUN_004c55e0, FUN_004c5fe0.
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

void __fastcall FUN_004c5fe0(uint param_1)



{

  int iVar1;

  float10 fVar2;

  uint32_t /* width from decompiler */ uStack_4;

  

  uStack_4 = param_1 & 0xffffff;

  if (*(char *)(*(int *)(*(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x458 + param_1) + 0x7e) == '\0'

     ) {

    fVar2 = (float10)FUN_004c55e0();

    if ((float10)g_flZero != fVar2) {

      iVar1 = 0;

      if (param_1 != 0x500) {

        iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4) + -0x4fc + param_1;

      }

      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);

    }

  }

  if ((*(int *)(param_1 - 0x2a8) != 0) && (*(int *)(*(int *)(param_1 - 0x2a8) + 0xe0) != 0)) {

    iVar1 = *(int *)(*(int *)(param_1 - 0x4fc) + 4);

    if (*(char *)(*(int *)(iVar1 + -0x458 + param_1) + 0x7e) != '\0') {

      if (param_1 == 0x500) {

        iVar1 = 0;

      }

      else {

        iVar1 = iVar1 + param_1 + -0x4fc;

      }

      CVOGSpawnPoint_SetObjectActiveState(iVar1,(int)&uStack_4 + 3,0);

    }

    (**(code **)(**(int **)(param_1 - 0x2a8) + 0x44))();

  }

  return;

}
