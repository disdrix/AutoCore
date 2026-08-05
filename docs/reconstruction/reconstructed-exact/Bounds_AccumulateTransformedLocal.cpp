// =============================================================================
// Bounds_AccumulateTransformedLocal  (FUN_0074c9c0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0074c9c0
// Address:   0x0074c9c0  (autoassault.exe, image base 0x400000)
// Body:      0x0074c9c0 – 0x0074ce55
// System:    graphics / bounds accumulation
// Generated: 2026-07-29 W21-O dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of sealed CF. Not modernization.
// Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   If local volume gate (+0x2c) is clear: fetch transform matrix from xformRef
//   (FUN_0044b5c0), project local sphere center (FUN_0076f6e0), scale radius by
//   relative object scales, merge sphere into ECX dest, expand dest AABB by the
//   eight transformed local-AABB corners, clear dest gate, write XZ metric @+0x10.
//
// ABI (machine)
//   ECX     = BoundsVolume* dest          (accumulator)
//   stack0  = ObjectLike*   xformRef      (often &DAT_00d1eb60)
//   stack1  = BoundsVolume* local
//   stack2  = ObjectLike*   scaleSrc
//   cleanup = ret 12
//
// CONSTANTS
//   DAT_00a0f298 = 0.5f  (sphere merge mid-factor)
//

#include <cmath>
#include <cstdint>

extern "C" void *FUN_0044b5c0(/*ECX*/ void *xformRef, void *outMatrix);
// Math_Mat4TransformPoint3_Project: EAX=in xyz*, ESI=matrix*, EBX=out xyz*
extern "C" void FUN_0076f6e0(void);
extern float DAT_00a0f298; // 0.5f @ 0x00a0f298

struct BoundsVolume {
  float c[3];     // +0x00 center
  float radius;   // +0x0c
  float xzExtent; // +0x10
  float aabbMin[3]; // +0x14  (decomp float indices 5..7)
  float aabbMax[3]; // +0x20  (decomp float indices 8..10)
  std::uint8_t gate; // +0x2c
};

// Object with scale triple @ +0x9c and mode flag @ +0xb8
using ObjectLike = std::uint8_t;

static float *scale_xyz(ObjectLike *o)
{
  return reinterpret_cast<float *>(o + 0x9c);
}

static std::uint8_t scale_flag(ObjectLike *o)
{
  return o[0xb8];
}

static float len3(float x, float y, float z)
{
  return std::sqrt(x * x + y * y + z * z);
}

// Call FUN_0076f6e0 with sealed register convention.
static void project_point(float *matrix, const float *in, float *out)
{
#if defined(_MSC_VER) && defined(_M_IX86)
  __asm {
    mov eax, in
    mov esi, matrix
    mov ebx, out
    call FUN_0076f6e0
  }
#else
  (void)matrix;
  out[0] = in[0];
  out[1] = in[1];
  out[2] = in[2];
#endif
}

extern "C" void Bounds_AccumulateTransformedLocal(
    BoundsVolume *dest /*ECX*/,
    ObjectLike *xformRef /*stack0*/,
    BoundsVolume *local /*stack1*/,
    ObjectLike *scaleSrc /*stack2*/)
{
  // Early-out: local[+0x2c] != 0
  if (local->gate != 0) {
    return;
  }

  alignas(16) std::uint8_t matrixLocal[76];
  // Retail: ECX=xformRef, push &matrixLocal, call FUN_0044b5c0 (also uses scaleSrc in EDI)
  FUN_0044b5c0(xformRef, matrixLocal);
  float *matrix = reinterpret_cast<float *>(matrixLocal);

  float inPt[3] = { local->c[0], local->c[1], local->c[2] };
  float worldC[3];
  project_point(matrix, inPt, worldC);

  float worldR;
  if (scale_flag(scaleSrc) == 0 && scale_flag(xformRef) == 0) {
    worldR = (scale_xyz(scaleSrc)[0] / scale_xyz(xformRef)[0]) * local->radius;
  } else {
    float *ss = scale_xyz(scaleSrc);
    float *sr = scale_xyz(xformRef);
    worldR = len3(ss[0], ss[1], ss[2]) *
             (local->radius / len3(sr[0], sr[1], sr[2]));
  }

  // --- sphere merge into dest ---
  if (dest->radius == 0.0f) {
    dest->c[0] = worldC[0];
    dest->c[1] = worldC[1];
    dest->c[2] = worldC[2];
    dest->radius = worldR;
  } else {
    float dx = worldC[0] - dest->c[0];
    float dy = worldC[1] - dest->c[1];
    float dz = worldC[2] - dest->c[2];
    float dist = len3(dx, dy, dz);
    float rMerge = (dest->radius + dist + worldR) * DAT_00a0f298; // 0.5f
    if (dest->radius < rMerge) {
      if (worldR < rMerge) {
        if (dist > 0.0f) {
          float t = (rMerge - dest->radius) / dist;
          dest->c[0] += dx * t;
          dest->c[1] += dy * t;
          dest->c[2] += dz * t;
        }
        dest->radius = rMerge;
      } else {
        dest->c[0] = worldC[0];
        dest->c[1] = worldC[1];
        dest->c[2] = worldC[2];
        dest->radius = worldR;
      }
    }
  }

  // Sphere window used as clamp partner during AABB expand
  float winMin[3] = {
      worldC[0] - worldR, worldC[1] - worldR, worldC[2] - worldR};
  float winMax[3] = {
      worldC[0] + worldR, worldC[1] + worldR, worldC[2] + worldR};

  // local AABB extents: +0x14 min, +0x20 max (float* bases)
  float *ext[2] = { local->aabbMin, local->aabbMax };

  for (unsigned i = 0; i < 8; ++i) {
    float cornerIn[3];
    cornerIn[0] = ext[i & 1][0];
    cornerIn[1] = ext[(i >> 1) & 1][1];
    cornerIn[2] = ext[(i >> 2) & 1][2];

    float cornerOut[3];
    project_point(matrix, cornerIn, cornerOut);

    // Per-axis: dest.min = min(dest.min, max(corner, winMin))
    //           dest.max = max(dest.max, min(corner, winMax))
    // Select order matches decompile min/max pointer dance (raw).
    for (int a = 0; a < 3; ++a) {
      float loCand = cornerOut[a];
      if (loCand <= winMin[a]) {
        loCand = winMin[a];
      }
      if (!(dest->aabbMin[a] <= loCand && loCand != dest->aabbMin[a])) {
        // dest.min already smaller or equal — keep unless loCand is strictly preferred
      }
      // Decompile uses: pf = &corner; if (corner <= winMin) pf=&winMin;
      //   if (destMin <= *pf && *pf != destMin) pf=&destMin; destMin=*pf;
      // Equivalent float min:
      float vMin = cornerOut[a] > winMin[a] ? cornerOut[a] : winMin[a];
      if (vMin < dest->aabbMin[a]) {
        dest->aabbMin[a] = vMin;
      }

      float vMax = cornerOut[a] < winMax[a] ? cornerOut[a] : winMax[a];
      if (vMax > dest->aabbMax[a]) {
        dest->aabbMax[a] = vMax;
      }
    }
  }

  dest->gate = 0;
  float ex = dest->aabbMax[0] - dest->c[0];
  float ez = dest->aabbMax[2] - dest->c[2];
  dest->xzExtent = std::fabs(std::sqrt(ex * ex + ez * ez));
}
