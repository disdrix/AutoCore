// =============================================================================
// FUN_0073a8d0
// -----------------------------------------------------------------------------
// Stable ID: aa_0073a8d0
// Address:   0x0073a8d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073a8d0 @ 0x0073a8d0
// Stable ID: aa_0073a8d0
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~31 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_0073a8d0.
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

void __thiscall FUN_0073a8d0(int param_1,int param_2)



{

  float fVar1;

  int *piVar2;

  

  if (param_2 < 1) {

    if (*(int *)(param_1 + 0x110) != *(int *)(param_1 + 0xdc)) {

      fVar1 = *(float *)(param_1 + 0x214);

      *(float *)(param_1 + 0xf0) = *(float *)(param_1 + 500) * fVar1;

      *(float *)(param_1 + 0xf4) = *(float *)(param_1 + 0x1f8) * fVar1;

      *(float *)(param_1 + 0xf8) = *(float *)(param_1 + 0x1fc) * fVar1;

      fVar1 = *(float *)(param_1 + 0x214);

      *(uint32_t /* width from decompiler */ *)(param_1 + 0xfc) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x200);

      *(float *)(param_1 + 0x100) = fVar1 * *(float *)(param_1 + 0x204);

      *(float *)(param_1 + 0x104) = *(float *)(param_1 + 0x208) * fVar1;

      *(float *)(param_1 + 0x108) = *(float *)(param_1 + 0x20c) * fVar1;

      *(uint32_t /* width from decompiler */ *)(param_1 + 0x10c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x210);

      *(int *)(param_1 + 0x110) = *(int *)(param_1 + 0xdc);

    }

    if ((param_1 != *(int *)(&DAT_00d1a57c + param_2 * 4)) ||

       (*(int *)(param_1 + 0x110) != *(int *)(&DAT_00d1a580 + param_2 * 4))) {

      if (*(int *)(DAT_00d1f05c + 4) != 0) {

        piVar2 = *(int **)(*(int *)(DAT_00d1f05c + 4) + 0xc);

        (**(code **)(*piVar2 + 0x50))

                  (piVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x1f0 + param_2 * 4),param_1 + 0xf0,0xffffffff);

      }

      *(int *)(&DAT_00d1a57c + param_2 * 4) = param_1;

      *(uint32_t /* width from decompiler */ *)(&DAT_00d1a580 + param_2 * 4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x110);

    }

  }

  return;

}
