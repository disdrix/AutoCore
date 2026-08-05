// =============================================================================
// FUN_00736c30
// -----------------------------------------------------------------------------
// Stable ID: aa_00736c30
// Address:   0x00736c30  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for FUN_00736c30 @ 0x00736c30
// Stable ID: aa_00736c30
// No high-value strings recovered; name via xrefs/callers in follow-up.
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~59 non-empty decompiler lines.
//  - Control keywords: if×4, return×1.
//  - Notable callees: FUN_004653e0, FUN_00736c30.
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

void __fastcall FUN_00736c30(int param_1)



{

  float fVar1;

  int *piVar2;

  int iVar3;

  uint32_t /* width from decompiler */ in_XMM0_Da;

  float fVar4;

  float fVar5;

  float fVar6;

  

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

  piVar2 = (int *)*DAT_00d1f044;

  if (*(int *)(param_1 + 0x1a4) != *(int *)(param_1 + 0xdc)) {

    fVar6 = *(float *)(param_1 + 0x214);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x170) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d4);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x174) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1d8);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x178) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1dc);

    fVar4 = *(float *)(param_1 + 0x1e0) * fVar6;

    fVar5 = *(float *)(param_1 + 0x1e4) * fVar6;

    fVar6 = *(float *)(param_1 + 0x1e8) * fVar6;

    *(float *)(param_1 + 0x140) = fVar4;

    *(float *)(param_1 + 0x144) = fVar5;

    *(float *)(param_1 + 0x148) = fVar6;

    fVar1 = *(float *)(param_1 + 0x214);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x14c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

    *(float *)(param_1 + 0x160) = *(float *)(param_1 + 0x1f0) * fVar1;

    *(float *)(param_1 + 0x164) = *(float *)(param_1 + 500) * fVar1;

    *(float *)(param_1 + 0x168) = *(float *)(param_1 + 0x1f8) * fVar1;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x16c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1fc);

    *(float *)(param_1 + 0x150) = fVar4;

    *(float *)(param_1 + 0x154) = fVar5;

    *(float *)(param_1 + 0x158) = fVar6;

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x15c) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x1ec);

    *(uint32_t /* width from decompiler */ *)(param_1 + 400) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x208);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x198) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x210);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x188) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x200);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x194) = *(uint32_t /* width from decompiler */ *)(param_1 + 0x20c);

    (**(code **)(*piVar2 + 0xcc))(piVar2,*(uint32_t /* width from decompiler */ *)(param_1 + 0x138),param_1 + 0x13c);

    *(uint32_t /* width from decompiler */ *)(param_1 + 0x1a4) = *(uint32_t /* width from decompiler */ *)(param_1 + 0xdc);

  }

  iVar3 = DAT_00d1f630;

  if (*(int *)(DAT_00d1f630 + 0x38) < 8) {

    *(uint32_t /* width from decompiler */ *)(DAT_00d1f630 + 0x3c + *(int *)(DAT_00d1f630 + 0x38) * 4) =

         *(uint32_t /* width from decompiler */ *)(param_1 + 0x138);

    *(int *)(iVar3 + 0x38) = *(int *)(iVar3 + 0x38) + 1;

  }

  return;

}
