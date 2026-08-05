// =============================================================================
// Gfx_NDParticleDistortBlendNormal_009523d0
// -----------------------------------------------------------------------------
// Stable ID: aa_009523d0
// Address:   0x009523d0  (autoassault.exe, image base 0x400000)
// System:    unknown
// Generated: 2026-07-23 from raw capture (scaffold; refine for important units)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE (auto): Scaffold unit for Gfx_NDParticleDistortBlendNormal_009523d0 @ 0x009523d0
// Stable ID: aa_009523d0
// Embedded strings (evidence for future rename):
//   - "NDParticleDistort.fx"
//   - "NDParticleDistortBlendNormal.fx"
//   - "NormalMapTexture"
//   - "DistortTexture"
// Readability: control flow preserved from Ghidra decompile; types tentative.

// READABILITY (auto CF):
//  - Body size: ~73 non-empty decompiler lines.
//  - Control keywords: if×6, return×4.
//  - Notable callees: FUN_009701d0×3, FUN_00989e00×3, FUN_0096f6e0×2, CONCAT31, FUN_0055cc70, FUN_0075de80, FUN_007a2580, FUN_007ae100.
//  - Strings: "NDParticleDistort.fx"; "NDParticleDistortBlendNormal.fx"; "NormalMapTexture"; "DistortTexture".
//  - Return sites: 4.

/*
 * Behavioral notes:
 * Plate-driven rename evidence: "NDParticleDistortBlendNormal.fx"
 * Domain alias of FUN_009523d0 (FUN_* retained)
 *
 * - Derived from Ghidra decompile; names prefer Ghidra symbols / plate comments.
 * - Remaining FUN_* / DAT_* identifiers are unresolved pending type recovery.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

uint32_t /* width from decompiler */ Gfx_NDParticleDistortBlendNormal_009523d0(void)



{

  int *piVar1;

  int iVar2;

  uint8_t local_28 [4];

  uint32_t /* width from decompiler */ local_24;

  uint32_t /* width from decompiler */ local_20;

  int *local_1c;

  uint8_t local_18;

  uint8_t local_17;

  uint8_t local_16;

  uint32_t /* width from decompiler */ local_14;

  uint8_t local_10;

  uint8_t local_f;

  uint8_t local_e;

  void *local_c;

  uint8_t *puStack_8;

  uint32_t /* width from decompiler */ local_4;

  

  local_4 = 0xffffffff;

  puStack_8 = &LAB_009b1704;

  local_c = ExceptionList;

  ExceptionList = &local_c;

  FUN_0075de80(1,0x41200000);

  FUN_007ae100();

  local_1c = (int *)0x0;

  local_18 = 0;

  local_17 = 0;

  local_16 = 0;

  local_4 = 0;

  FUN_00989e00(local_28,"NDParticleDistort.fx");

  iVar2 = FUN_009701d0(local_28);

  if (-1 < iVar2) {

    local_14 = 0;

    local_10 = 0;

    local_f = 0;

    local_e = 0;

    local_4 = CONCAT31(local_4._1_3_,2);

    FUN_00989e00(local_28,"NDParticleDistortBlendNormal.fx");

    iVar2 = FUN_009701d0(local_28);

    if (-1 < iVar2) {

      FUN_0096f6e0("NormalMapTexture",&local_24);

      FUN_0096f6e0("DistortTexture",&local_20);

      FUN_00989e00(local_28,"NDParticleDistort.fx");

      FUN_009701d0(local_28);

      FUN_007a2580(local_20,local_24);

      FUN_0055cc70();

      local_4 = 0xffffffff;

      if (local_1c == (int *)0x0) {

        ExceptionList = local_c;

        return 1;

      }

      piVar1 = local_1c + 1;

      *piVar1 = *piVar1 + -1;

      if (*piVar1 != 0) {

        ExceptionList = local_c;

        return 1;

      }

      (**(code **)(*local_1c + 8))();

      ExceptionList = local_c;

      return 1;

    }

  }

  local_4 = 0xffffffff;

  if (local_1c != (int *)0x0) {

    piVar1 = local_1c + 1;

    *piVar1 = *piVar1 + -1;

    if (*piVar1 == 0) {

      (**(code **)(*local_1c + 8))();

    }

  }

  ExceptionList = local_c;

  return 1;

}
