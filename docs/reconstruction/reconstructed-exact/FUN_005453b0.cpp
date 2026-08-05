// =============================================================================
// FUN_005453b0
// -----------------------------------------------------------------------------
// Stable ID: aa_005453b0
// Address:   0x005453b0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_005453b0 @ 0x005453b0
// Stable ID: aa_005453b0
// Embedded strings (evidence for future rename):
//   - "HashError:remove, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~44 non-empty decompiler lines.
//  - Control keywords: if×7, return×3, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_004e2ca0, FUN_00544020, FUN_005453b0.
//  - Strings: "HashError:remove, already locked for traversal"; "VOG_DEBUG_STOP".
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

uint32_t /* width from decompiler */ __thiscall FUN_005453b0(int param_1,uint32_t /* width from decompiler */ param_2,uint32_t /* width from decompiler */ *param_3)



{

  void *pvVar1;

  uint32_t /* width from decompiler */ *puVar2;

  

  if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_3 = 0;

  }

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:remove, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  puVar2 = (uint32_t /* width from decompiler */ *)FUN_004e2ca0(param_2);

  if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_3 != (uint32_t /* width from decompiler */ *)0x0) {

      *param_3 = puVar2[2];

    }

    puVar2[2] = 0;

    if (puVar2 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x14)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = puVar2[5];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar2[6] + 0x14) = puVar2[5];

    }

    if (puVar2 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = puVar2[6];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar2[5] + 0x18) = puVar2[6];

    }

    pvVar1 = (void *)puVar2[2];

    *puVar2 = &PTR_FUN_009d016c;

    if (pvVar1 != (void *)0x0) {

      FUN_00544020();

                    /* WARNING: Subroutine does not return */

      operator_delete(pvVar1);

    }

    puVar2[2] = 0;

    *puVar2 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar2;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    return 0;

  }

  return 0x80004005;

}
