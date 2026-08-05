// =============================================================================
// FUN_004979a0
// -----------------------------------------------------------------------------
// Stable ID: aa_004979a0
// Address:   0x004979a0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004979a0 @ 0x004979a0
// Stable ID: aa_004979a0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×3, return×3, do×1, while×1.
//  - Notable callees: CONCAT31, FUN_00497900, FUN_004979a0.
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

uint32_t /* width from decompiler */ __thiscall FUN_004979a0(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  int local_8;

  int local_4;

  

  local_8 = 0;

  local_4 = 0;

  if (*(int *)(param_1 + 0x10) < 1) {

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x10) = 0;

    return 1;

  }

  puVar2 = (uint32_t /* width from decompiler */ *)(param_1 + 0x14);

  puVar3 = puVar2;

  do {

    piVar1 = (int *)*puVar3;

    if (*piVar1 == param_2) {

      if (piVar1 != (int *)0x0) {

        FUN_00497900();

                    /* WARNING: Subroutine does not return */

        operator_delete(piVar1);

      }

      *puVar3 = 0;

    }

    else {

      local_8 = local_8 + 1;

      *puVar2 = piVar1;

      puVar2 = puVar2 + 1;

    }

    local_4 = local_4 + 1;

    puVar3 = puVar3 + 1;

  } while (local_4 < *(int *)(param_1 + 0x10));

  *(int *)(param_1 + 0x10) = local_8;

  return CONCAT31((int3)((uint)local_4 >> 8),1);

}
