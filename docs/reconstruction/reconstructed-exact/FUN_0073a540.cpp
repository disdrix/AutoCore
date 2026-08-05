// =============================================================================
// FUN_0073a540
// -----------------------------------------------------------------------------
// Stable ID: aa_0073a540
// Address:   0x0073a540  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073a540 @ 0x0073a540
// Stable ID: aa_0073a540
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_00464a50, FUN_0073a540.
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

void __thiscall FUN_0073a540(int param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  

  FUN_00464a50();

  if (param_2 < 4) {

    if (*(int *)(param_1 + 0x110) != *(int *)(param_1 + 0xdc)) {

      fVar1 = *(float *)(param_1 + 0x1bc);

      *(float *)(param_1 + 0xf0) = *(float *)(param_1 + 0x1ac) * fVar1;

      *(float *)(param_1 + 0xf4) = *(float *)(param_1 + 0x1b0) * fVar1;

      *(float *)(param_1 + 0xf8) = *(float *)(param_1 + 0x1b4) * fVar1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x100) = *(uint32_t /* width from decompiler */ *)(param_1 + 400);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x104) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x194);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x108) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x198);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1c8);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x110) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

    }

    if ((param_1 != *(int *)(&DAT_00d1a584 + param_2 * 4)) ||

       (*(int *)(param_1 + 0x110) != *(int *)(&DAT_00d1a594 + param_2 * 4))) {

      if (*(int *)(DAT_00d1f05c + 4) != 0) {

        piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

        (**(code **)(*piVar2 + 0x50))

                  (piVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x19c + param_2 * 4),param_1 + 0xf0,0xffffffff);

      }

      *(int *)(&DAT_00d1a584 + param_2 * 4) = param_1;

      *(uint32_t /* width from decompiler */ *)(&DAT_00d1a594 + param_2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x110);

    }

  }

  return;

}
