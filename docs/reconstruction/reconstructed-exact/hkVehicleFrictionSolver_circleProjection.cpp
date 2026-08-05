// =============================================================================
// hkVehicleFrictionSolver_circleProjection
// -----------------------------------------------------------------------------
// Stable ID: aa_006c3f90
// Address:   0x006c3f90  (autoassault.exe, image base 0x400000)
// System:    physics-havok-vehicle (deferred priority; library friction helper)
// Generated: 2026-07-23 from raw capture
// Refined:   2026-07-23 — readability pass on offsets/locals; control flow unchanged
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

/*
 * Behavioral notes (refined):
 * - Projects / clamps a 2D friction force pair onto a unit circle when the
 *   scaled force magnitude would exceed 1 (g_flOne).
 * - param_1: friction-solver wheel/contact state block (float fields at fixed offsets).
 * - param_2: output side-channel; writes projected slip/force magnitude at +0x08.
 * - scaleTable (unaff_ESI): decompiler residue — scale/lookup table not recovered as
 *   a formal parameter; treated as external float* (register-arg / global table).
 * - g_flOne: shared float constant 1.0f (DAT_*).
 * - Runtime / differential verification: OPEN (physics deferred).
 *
 * Field map on param_1 (from decompile uses only):
 *   +0x60, +0x68  — axis/scale terms for final magnitude normalize
 *   +0x74, +0x7c  — delta scaling for longitudinal / lateral residual
 *   +0x80, +0x84  — force pair (lat/long or equivalent); rewritten on project
 *   +0x88, +0x8c  — force scale factors applied after circle blend
 *   +0x90, +0x94  — input scale multipliers for the pre-check magnitude
 *   +0x98         — residual (force@+0x80 - projected); zeroed if under circle
 */

// External constants / helpers (image symbols; not redefined here)
extern float g_flOne;
// SQRT is decompiler spelling of sqrtf / fsched sqrt

void __thiscall hkVehicleFrictionSolver_circleProjection(int param_1, int param_2)
{
  float forceY;       /* fVar1 — starts as (+0x94)*(+0x84) */
  float tNext;        /* fVar2 — table step for forceY */
  float forceX;       /* fVar3 — starts as (+0x90)*(+0x80); reused as blend weights */
  float scaledX;      /* fVar4 */
  float mag2;         /* fVar5 — squared magnitude / blended Y */
  float tNextX;       /* fVar6 */
  int step;           /* iVar7 — table walk 0..0x10 */
  float *scaleTable;  /* unaff_ESI — unrecovered table pointer */
  float prevMag2;     /* local_c */
  float prevY;        /* local_8 */
  float prevX;        /* local_4 */

  forceY = *(float *)(param_1 + 0x94) * *(float *)(param_1 + 0x84);
  forceX = *(float *)(param_1 + 0x90) * *(float *)(param_1 + 0x80);

  if (g_flOne <= forceY * forceY + forceX * forceX) {
    /* Outside or on unit circle: walk scale table (max 16 steps) until mag2 > 1. */
    forceY = forceY * scaleTable[0x11];
    step = 0;
    prevY = 0.0f;
    prevX = 0.0f;
    prevMag2 = 0.0f;
    scaledX = forceX * *scaleTable;
    mag2 = forceY * forceY + scaledX * scaledX;

    while ((mag2 <= g_flOne && (step = step + 1, step < 0x10))) {
      tNext = forceY * scaleTable[0x10];
      tNextX = forceX * scaleTable[step];
      prevY = forceY;
      prevX = scaledX;
      prevMag2 = mag2;
      forceY = tNext;
      scaledX = tNextX;
      mag2 = tNext * tNext + tNextX * tNextX;
    }

    /* Linear blend weights between previous (under) and current (over) radii. */
    forceX = g_flOne / ((SQRT(mag2) - g_flOne) - (SQRT(prevMag2) - g_flOne));
    tNext = -(forceX * (SQRT(prevMag2) - g_flOne));
    forceX = (SQRT(mag2) - g_flOne) * forceX;

    mag2 = (tNext * forceY + prevY * forceX) * *(float *)(param_1 + 0x8c);
    forceX = (forceX * prevX + tNext * scaledX) * *(float *)(param_1 + 0x88);

    forceY = *(float *)(param_1 + 0x84);
    *(float *)(param_1 + 0x84) = mag2;
    *(float *)(param_1 + 0x98) = *(float *)(param_1 + 0x80) - forceX;
    *(float *)(param_1 + 0x80) = forceX;

    forceX = *(float *)(param_1 + 0x7c) * *(float *)(param_1 + 0x98) * *(float *)(param_1 + 0x88);
    forceY = (forceY - mag2) * *(float *)(param_1 + 0x74) * *(float *)(param_1 + 0x8c);
    *(float *)(param_2 + 8) =
        SQRT((forceX * forceX + forceY * forceY) *
             (g_flOne /
              (*(float *)(param_1 + 0x68) * *(float *)(param_1 + 0x68) +
               *(float *)(param_1 + 0x60) * *(float *)(param_1 + 0x60))));
    return;
  }

  /* Inside unit circle → clear residual and exit (no projection). */
  *(uint32_t /* width from decompiler */ *)(param_1 + 0x98) = 0;
  return;
}
