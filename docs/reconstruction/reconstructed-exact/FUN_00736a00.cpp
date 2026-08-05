// =============================================================================
// FUN_00736a00
// -----------------------------------------------------------------------------
// Stable ID: aa_00736a00
// Address:   0x00736a00  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00736a00 @ 0x00736a00
// Stable ID: aa_00736a00
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~52 non-empty decompiler lines.
//  - Control keywords: if×6, return×1.
//  - Notable callees: FUN_004653e0, FUN_00736a00.
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

void __thiscall FUN_00736a00(int param_1,int param_2)



{

  int *piVar1;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  float fVar2;

  

  if ((*(char *)(param_1 + 0x1c8) != '\0') && (*(char *)(param_1 + 0x1d0) == '\0')) {

    FUN_004653e0();

    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x200) = in_XMM0_Da;

    *(uint8_t *)(param_1 + 0x1d0) = 1;

  }

  if (*(int *)(param_1 + 0xc4) != *(int *)(param_1 + 8)) {

    *(int *)(param_1 + 0xdc) = *(int *)(param_1 + 0xdc) + 1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa0);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1dc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xa8);

    *(int *)(param_1 + 8) = *(int *)(param_1 + 0xc4);

  }

  if (param_2 < 8) {

    if (*(int *)(param_1 + 0x130) != *(int *)(param_1 + 0xdc)) {

      fVar2 = g_flOne / *(float *)(param_1 + 0x134);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xf0) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d4);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xf4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xf8) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1dc);

      *(float *)(param_1 + 0x100) = *(float *)(param_1 + 0x1e0) * fVar2;

      *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x1e4) * fVar2;

      *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x1e8) * fVar2;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

      *(float *)(param_1 + 0x110) = *(float *)(param_1 + 0x1f0) * fVar2;

      *(float *)(param_1 + 0x114) = *(float *)(param_1 + 500) * fVar2;

      *(float *)(param_1 + 0x118) = *(float *)(param_1 + 0x1f8) * fVar2;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x11c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x200);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x124) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20c);

      *(float *)(param_1 + 0x120) = *(float *)(param_1 + 0x214) * *(float *)(param_1 + 0x134);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x210);

      *(uint32_t /* width from decompiler */ *)(param_1 + 300) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x204);

      *(int *)(param_1 + 0x130) = *(int *)(param_1 + 0xdc);

    }

    if ((param_1 != *(int *)(&DAT_00d1a5bc + param_2 * 4)) ||

       (*(int *)(param_1 + 0x130) != *(int *)(&DAT_00d1a5dc + param_2 * 4))) {

      if (*(int *)(DAT_00d1f05c + 4) != 0) {

        piVar1 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

        (**(code **)(*piVar1 + 0x50))

                  (piVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1a8 + param_2 * 4),param_1 + 0xf0,0xffffffff);

      }

      *(int *)(&DAT_00d1a5bc + param_2 * 4) = param_1;

      *(uint32_t /* width from decompiler */ *)(&DAT_00d1a5dc + param_2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x130);

    }

  }

  return;

}
