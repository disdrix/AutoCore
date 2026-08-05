// READABILITY (auto CF):
//  - Body size: ~41 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_004e2ca0, FUN_004e3610.
//  - Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP".
//  - Return sites: 3.

// =============================================================================
// Named_VOG_DEBUG_STOP_004e3610
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3610
// Address:   0x004e3610  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes:
 * String-driven rename evidence: "VOG_DEBUG_STOP"
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ __thiscall Named_VOG_DEBUG_STOP_004e3610(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  uint32_t /* width from decompiler */ *puVar1;

  

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = 0;

  }

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:remove, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  puVar1 = (uint32_t /* width from decompiler */ *)FUN_004e2ca0(param_2);

  if (puVar1 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = puVar1[2];

    }

    puVar1[2] = 0;

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x14)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = puVar1[5];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar1[6] + 0x14) = puVar1[5];

    }

    if (puVar1 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = puVar1[6];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar1[5] + 0x18) = puVar1[6];

    }

    *puVar1 = &PTR_FUN_009cc1f0;

    if ((void *)puVar1[2] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)puVar1[2]);

    }

    puVar1[2] = 0;

    *puVar1 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar1;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    return 0;

  }

  return 0x80004005;

}
