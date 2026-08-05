// =============================================================================
// FUN_004e8ad0 / Quat_ExtractRight_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e8ad0
// Address:   0x004e8ad0  (autoassault.exe, image base 0x400000)
// System:    physics / shared math leaf (drive, camera, AI, turret consumers)
// Generated: 2026-07-23 scaffold; dual A/B plate 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B:  reviews/A_aa_004e8ad0_Quat_ExtractRight_Inferred.md
//            reviews/B_aa_004e8ad0_Quat_ExtractRight_Inferred.md
// Verified:  physics/verified/fn_004e8ad0_basisExtract.md
// =============================================================================

// PURPOSE:
//   Unit quaternion (XYZW) → world-space RIGHT axis (+X), matrix column 0.
//   out = ( 1-2(y²+z²),  2(xy+zw),  2(xz-yw),  0 )
//   Leaf; no normalize. Sibling forward 0x004e8a40 / up 0x004e8b60.
//
//   Globals (role here; plate names may be cross-use misnomers):
//     g_flOne                    @ 0x00a0f2a0 = 1.0f
//     g_flLevelUpUiBase_Inferred @ 0x00a10e74 = 2.0f  (quat scale factor only)

// READABILITY:
//  - Body size: ~18 non-empty decompiler lines; single basic block.
//  - Control keywords: return×1.
//  - Notable callees: none (leaf).
//  - Return sites: 1.
//  - Convention: stack args (param_1 quat*, param_2 out*) — not thiscall.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile; dual A/B sealed CF + constants 2026-07-29.
 * - Remaining FUN_* / DAT_* identifiers are unresolved product names.
 * - Runtime / differential verification: OPEN unless matrix says otherwise.
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw.
 */

void FUN_004e8ad0(float *param_1, float *param_2)
{
  float fVar1;  /* y */
  float fVar2;  /* z */
  float fVar3;  /* x */
  float fVar4;  /* w */
  float fVar5;  /* 2.0 */

  fVar5 = g_flLevelUpUiBase_Inferred; /* 2.0f @ 0x00a10e74 */
  fVar1 = param_1[1];                 /* y */
  fVar2 = param_1[2];                 /* z */
  fVar3 = *param_1;                   /* x */
  fVar4 = param_1[3];                 /* w */

  /* out.x = 1 - 2*(y² + z²) */
  *param_2 = g_flOne - (fVar2 * fVar2 + fVar1 * fVar1) * g_flLevelUpUiBase_Inferred;

  /* out.z = 2*(x*z - y*w) */
  param_2[2] = (fVar2 * fVar3 - fVar1 * fVar4) * fVar5;

  /* out.y = 2*(x*y + z*w) */
  param_2[1] = (fVar3 * fVar1 + fVar2 * fVar4) * fVar5;

  param_2[3] = 0.0;
  return;
}
