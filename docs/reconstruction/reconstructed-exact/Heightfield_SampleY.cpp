// =============================================================================
// Heightfield_SampleY
// -----------------------------------------------------------------------------
// Stable ID: aa_005a58c0
// Address:   0x005a58c0  (autoassault.exe, image base 0x400000)
// System:    world-terrain
// Generated: 2026-07-29 dual A/B (live Ghidra decompile + read_memory body)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual:      reviews/A_aa_005a58c0_Heightfield_SampleY.md
//            reviews/B_aa_005a58c0_Heightfield_SampleY.md
// =============================================================================
//
// PURPOSE:
//   Heightfield bilinear Y sample at world (X, Z).
//   this = Heightfield* (not CVOGMap*). Callers load map+0xe4e0 or use
//   CVOGMap_SampleHeightfieldY (0x004cd220) null gate (tail JMP here).
//
// ABI (body-sealed):
//   __thiscall ECX = hf
//   stack: float worldX, float worldZ
//   RET 8; return float10 in ST0
//
// Layout (this):
//   +0x0C int   dimX
//   +0x10 int   dimZ
//   +0x30 float scaleX   (world → grid)
//   +0x34 float heightScale (raw / scale → Y)
//   +0x38 float scaleZ
//
// Callee: FUN_005a5810 — bilinear at (cellX, cellZ, fracX, fracZ); not dualed here.
// =============================================================================

// Forward: bilinear corner sample (FUN_005a5810 @ 0x005a5810)
float10 __thiscall Heightfield_BilinearSample_FUN_005a5810(
    void *hf, int cellX, int cellZ, float fracX, float fracZ);

static int clamp_cell_index(int truncVal, int dimMinus2)
{
  // Body: max(0, trunc) via SETLE idiom, then min with (dim - 2)
  int t;
  if (truncVal <= 0) {
    t = 0;
  } else {
    t = truncVal;
  }
  if (t < dimMinus2) {
    return t;
  }
  return dimMinus2;
}

float10 __thiscall Heightfield_SampleY(void *hf, float worldX, float worldZ)
{
  float scaleX = *(float *)((char *)hf + 0x30);
  float scaleZ = *(float *)((char *)hf + 0x38);
  float gx = scaleX * worldX;
  float gz = scaleZ * worldZ;

  // CVTTSS2SI — trunc toward zero
  int truncX = (int)gx; // SSE trunc semantics for in-range values
  int truncZ = (int)gz;

  int dimX = *(int *)((char *)hf + 0x0c);
  int dimZ = *(int *)((char *)hf + 0x10);
  int cellX = clamp_cell_index(truncX, dimX - 2);
  int cellZ = clamp_cell_index(truncZ, dimZ - 2);

  float fracX = gx - (float)cellX;
  float fracZ = gz - (float)cellZ;

  float10 raw =
      Heightfield_BilinearSample_FUN_005a5810(hf, cellX, cellZ, fracX, fracZ);

  float heightScale = *(float *)((char *)hf + 0x34);
  return raw / (float10)heightScale;
}
