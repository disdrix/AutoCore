// =============================================================================
// FUN_004d3420
// -----------------------------------------------------------------------------
// Stable ID: aa_004d3420
// Address:   0x004d3420  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004d3420 @ 0x004d3420
// Stable ID: aa_004d3420
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~45 non-empty decompiler lines.
//  - Control keywords: if×6, return×5, for×1.
//  - Notable callees: FUN_004b7470, FUN_004d3420, FUN_0058ede0, FUN_00590450, GetTickCount.
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

void __thiscall FUN_004d3420(int param_1,float param_2)



{

  uint uVar1;

  

  *(int *)(param_1 + 0x88) = *(int *)(param_1 + 0x88) + 1;

  *(float *)(param_1 + 0x90) = param_2 + *(float *)(param_1 + 0x90);

  DAT_00b0421c = GetTickCount();

  if ((*(int *)(param_1 + 0xe874) != 0) &&

     (*(int *)(param_1 + 0xe878) - *(int *)(param_1 + 0xe874) >> 2 != 0)) {

    for (uVar1 = 0;

        (*(int *)(param_1 + 0xe874) != 0 &&

        (uVar1 < (uint)(*(int *)(param_1 + 0xe878) - *(int *)(param_1 + 0xe874) >> 2)));

        uVar1 = uVar1 + 1) {

      FUN_00590450();

    }

    if (*(void **)(param_1 + 0xe874) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0xe874));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe874) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe878) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe87c) = 0;

  }

  if ((*(int *)(param_1 + 0xe884) != 0) &&

     (*(int *)(param_1 + 0xe888) - *(int *)(param_1 + 0xe884) >> 2 != 0)) {

    FUN_0058ede0(param_1 + 0xe880,*(int *)(param_1 + 0xe898) + 0x98);

    FUN_004b7470(param_1 + 0xe880);

    if ((*(int *)(param_1 + 0xe884) != 0) &&

       (*(int *)(param_1 + 0xe888) - *(int *)(param_1 + 0xe884) >> 2 != 0)) {

      if (*(char *)((uint32_t /* width from decompiler */ *)**(int **)(param_1 + 0xe884) + 0xc) != '\0') {

                    /* WARNING: Subroutine does not return */

        operator_delete(*(void **)**(int **)(param_1 + 0xe884));

      }

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)**(uint32_t /* width from decompiler */ **)(param_1 + 0xe884));

    }

    if (*(void **)(param_1 + 0xe884) != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete(*(void **)(param_1 + 0xe884));

    }

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe884) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe888) = 0;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0xe88c) = 0;

  }

  return;

}
