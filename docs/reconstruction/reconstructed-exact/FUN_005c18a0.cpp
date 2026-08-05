// =============================================================================
// FUN_005c18a0
// -----------------------------------------------------------------------------
// Stable ID: aa_005c18a0
// Address:   0x005c18a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005c18a0 @ 0x005c18a0
// Stable ID: aa_005c18a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~32 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: CVOGTerrainChunk_BuildVertexBuffer, FUN_005bfb80, FUN_005c18a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_005c18a0(int param_1,uint32_t /* width from decompiler */ param_2)



{

  int *piVar1;

  int *piVar2;

  

  if (*(int *)(param_1 + 0xe0) != *(int *)(param_1 + 0xd8)) {

    if (*(char *)(param_1 + 0xe8) != '\0') {

      *(uint *)(param_1 + 0xbc) = *(uint *)(param_1 + 0xbc) | 1;

      piVar2 = *(int **)(param_1 + 0x14);

      if (piVar2 != (int *)0x0) {

        piVar1 = piVar2 + 1;

        *piVar1 = *piVar1 + -1;

        if (*piVar1 == 0) {

          (**(code **)(*piVar2 + 8))();

        }

        *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = 0;

      }

      *(uint8_t *)(param_1 + 0xe8) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = 0;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

    }

    if (*(int *)(param_1 + 0xd8) != 0) {

      CVOGTerrainChunk_BuildVertexBuffer(param_2,*(int *)(param_1 + 0xd8),0);

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xd8);

  }

  if (*(int *)(param_1 + 0xe4) != *(int *)(param_1 + 0xdc)) {

    FUN_005bfb80(param_2,*(int *)(param_1 + 0xdc));

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

  }

  return 1;

}
