// =============================================================================
// FUN_0073a670
// -----------------------------------------------------------------------------
// Stable ID: aa_0073a670
// Address:   0x0073a670  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_0073a670 @ 0x0073a670
// Stable ID: aa_0073a670
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~36 non-empty decompiler lines.
//  - Control keywords: if×2, return×1.
//  - Notable callees: FUN_00464a50, FUN_0073a670.
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

void __fastcall FUN_0073a670(int param_1)



{

  int *piVar1;

  int iVar2;

  float fVar3;

  float fVar4;

  float fVar5;

  

  FUN_00464a50();

  piVar1 = (int *)*DAT_00d1f044;

  if (*(int *)(param_1 + 0x180) != *(int *)(param_1 + 0xdc)) {

    fVar5 = *(float *)(param_1 + 0x1bc);

    fVar3 = *(float *)(param_1 + 0x1ac) * fVar5;

    fVar4 = *(float *)(param_1 + 0x1b0) * fVar5;

    fVar5 = *(float *)(param_1 + 0x1b4) * fVar5;

    *(float *)(param_1 + 0x11c) = fVar3;

    *(float *)(param_1 + 0x120) = fVar4;

    *(float *)(param_1 + 0x124) = fVar5;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x128) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8);

    *(float *)(param_1 + 300) = fVar3;

    *(float *)(param_1 + 0x130) = fVar4;

    *(float *)(param_1 + 0x134) = fVar5;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x138) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1b8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x158) = *(uint32_t /* width from decompiler */ *)(param_1 + 400);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x194);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x160) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x198);

    (**(code **)(*piVar1 + 0xcc))(piVar1,*(uint32_t /* width from decompiler */ *)(param_1 + 0x114),param_1 + 0x118);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x180) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

  }

  iVar2 = DAT_00d1f630;

  if (*(int *)(DAT_00d1f630 + 0x38) < 8) {

    *(uint32_t /* width from decompiler */ *)(DAT_00d1f630 + 0x3c + *(int *)(DAT_00d1f630 + 0x38) * 4) =

         *(uint32_t /* width from decompiler */ *)(param_1 + 0x114);

    *(int *)(iVar2 + 0x38) = *(int *)(iVar2 + 0x38) + 1;

  }

  return;

}
