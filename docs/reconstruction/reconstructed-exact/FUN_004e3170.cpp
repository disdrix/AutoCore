// =============================================================================
// FUN_004e3170
// -----------------------------------------------------------------------------
// Stable ID: aa_004e3170
// Address:   0x004e3170  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_004e3170 @ 0x004e3170
// Stable ID: aa_004e3170
// Embedded strings (evidence for future rename):
//   - "HashError:remove, already locked for traversal"
//   - "VOG_DEBUG_STOP"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~54 non-empty decompiler lines.
//  - Control keywords: if×9, return×3, for×1.
//  - Notable callees: FUN_007a4480×2, FUN_004e2360, FUN_004e23d0, FUN_004e3170.
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

uint32_t /* width from decompiler */ __thiscall FUN_004e3170(int param_1,uint param_2,uint32_t /* width from decompiler */ param_3,uint32_t /* width from decompiler */ *param_4)



{

  int iVar1;

  uint32_t /* width from decompiler */ *puVar2;

  uint32_t /* width from decompiler */ *puVar3;

  

  puVar2 = param_4;

  if (param_4 != (uint32_t /* width from decompiler */ *)0x0) {

    *param_4 = 0;

  }

  if (*(char *)(param_1 + 0x1d) != '\0') {

    FUN_007a4480(0,"HashError:remove, already locked for traversal");

    FUN_007a4480(0,"VOG_DEBUG_STOP");

  }

  iVar1 = *(int *)(*(int *)(param_1 + 0x10) + (*(uint *)(param_1 + 8) & param_2) * 4);

  puVar3 = (uint32_t /* width from decompiler */ *)FUN_004e23d0(param_2,param_3,&param_4);

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    if (param_4 == (uint32_t /* width from decompiler */ *)0x0) {

      *(uint32_t /* width from decompiler */ *)(iVar1 + 4) = puVar3[4];

    }

    else {

      param_4[4] = puVar3[4];

    }

  }

  FUN_004e2360();

  if (puVar3 != (uint32_t /* width from decompiler */ *)0x0) {

    if (puVar2 != (uint32_t /* width from decompiler */ *)0x0) {

      *puVar2 = puVar3[3];

    }

    puVar3[3] = 0;

    if (puVar3 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x14)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x14) = puVar3[8];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar3[9] + 0x20) = puVar3[8];

    }

    if (puVar3 == *(uint32_t /* width from decompiler */ **)(param_1 + 0x18)) {

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x18) = puVar3[9];

    }

    else {

      *(uint32_t /* width from decompiler */ *)(puVar3[8] + 0x24) = puVar3[9];

    }

    *puVar3 = &PTR_FUN_009cc208;

    if ((void *)puVar3[3] != (void *)0x0) {

                    /* WARNING: Subroutine does not return */

      operator_delete((void *)puVar3[3]);

    }

    puVar3[3] = 0;

    *puVar3 = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20);

    *(uint32_t /* width from decompiler */ **)(param_1 + 0x20) = puVar3;

    *(int *)(param_1 + 0xc) = *(int *)(param_1 + 0xc) + -1;

    return 0;

  }

  return 0x80004005;

}
