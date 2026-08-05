// =============================================================================
// Math_ComposeOptionalTRSMatrix_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0076f970
// Address:   0x0076f970  (autoassault.exe, image base 0x400000)
// Body:      0x0076f970–0x0076fc93  (0x323 bytes; cdecl ret)
// System:    math / graphics transforms
// Twin file: FUN_0076f970.cpp
// Generated: 2026-07-29 W18-P dual seal
// Exactness: Behavior-preserving. Not modernization.
// =============================================================================

#include <stdint.h>
#include <string.h>

// Identity 4x4 at DAT_00afdf70 (diag 1.0f).
// Callees:
//   FUN_00412d80(dest, A, dest)  — dest = A * dest
//   FUN_0076eb00(outMat, quat)   — quat → rotation matrix
//   FUN_0076e6b0(outQuat, quat)  — quat inverse/conjugate

// ABI (machine + GfxNode call site 0x00972e50):
//   EAX = optional float3* tA
//   ECX = optional float3* tB
//   stack cdecl (5 args, caller cleans 0x14):
//     dest mat4*
//     rOuter quat*   (nullable → skip R and Rinv stages)
//     scale float3*  (nullable)
//     rInner quat*   (nullable)
//     translation float3* (nullable → base is identity)
//   return EAX = dest

// Compose left-multiply order when all present:
//   dest  = T(translation)                        // or I
//   dest  = T(+tB) * dest
//   dest  = R(rInner) * dest
//   dest  = T(-tB) * dest
//   dest  = T(+tA) * dest
//   dest  = R(rOuter) * dest
//   dest  = S(scale) * dest
//   dest  = Rinv(rOuter) * dest
//   dest  = T(-tA) * dest
//
// GfxNode common path (tA=tB=0@0x00D1A6C0, rOuter=identity):
//   dest = S(node+0x9C) * R(node+0x80) * T(node+0x90)

extern "C" void FUN_00412d80(float *dest, float *a, float *b);
extern "C" void FUN_0076eb00(float *outMat, const float *quat);
extern "C" float *FUN_0076e6b0(float *outQuat, const float *quat);

static const float kIdentity4x4[16] = {
    1.f, 0.f, 0.f, 0.f,
    0.f, 1.f, 0.f, 0.f,
    0.f, 0.f, 1.f, 0.f,
    0.f, 0.f, 0.f, 1.f,
};

static void Mat4CopyIdentity(float *m)
{
    memcpy(m, kIdentity4x4, sizeof(kIdentity4x4));
}

static void Mat4Translation(float *m, const float *t)
{
    Mat4CopyIdentity(m);
    m[12] = t[0];
    m[13] = t[1];
    m[14] = t[2];
}

static void Mat4TranslationNeg(float *m, const float *t)
{
    Mat4CopyIdentity(m);
    m[12] = -t[0];
    m[13] = -t[1];
    m[14] = -t[2];
}

static void Mat4ScaleDiag(float *m, const float *s)
{
    Mat4CopyIdentity(m);
    m[0] = s[0];
    m[5] = s[1];
    m[10] = s[2];
}

// ECX = tB, stack formals as listed; tA in EAX (not expressible portably — documented).
extern "C" float *Math_ComposeOptionalTRSMatrix_Inferred(
    float *tB,           // ECX
    float *dest,         // stack
    float *rOuter,       // stack quat[4] or null
    float *scale,        // stack float3 or null
    float *rInner,       // stack quat[4] or null
    float *translation,  // stack float3 or null
    float *tA            // EAX — pass explicitly in this reconstruction
)
{
    float mat_tA[16], mat_tA_neg[16];
    float mat_tB[16], mat_tB_neg[16];
    float mat_rOuter[16], mat_rOuterInv[16];
    float mat_rInner[16];
    float mat_scale[16];
    float mat_base[16];
    float quatInv[4];

    float *p_tA = 0, *p_tA_neg = 0;
    float *p_tB = 0, *p_tB_neg = 0;
    float *p_rOuter = 0, *p_rOuterInv = 0;
    float *p_rInner = 0;
    float *p_scale = 0;
    float *p_base;

    if (tA != 0) {
        Mat4Translation(mat_tA, tA);
        Mat4TranslationNeg(mat_tA_neg, tA);
        p_tA = mat_tA;
        p_tA_neg = mat_tA_neg;
    }
    if (rOuter != 0) {
        FUN_0076eb00(mat_rOuter, rOuter);
        FUN_0076e6b0(quatInv, rOuter);
        FUN_0076eb00(mat_rOuterInv, quatInv);
        p_rOuter = mat_rOuter;
        p_rOuterInv = mat_rOuterInv;
    }
    if (scale != 0) {
        Mat4ScaleDiag(mat_scale, scale);
        p_scale = mat_scale;
    }
    if (tB != 0) {
        Mat4Translation(mat_tB, tB);
        Mat4TranslationNeg(mat_tB_neg, tB);
        p_tB = mat_tB;
        p_tB_neg = mat_tB_neg;
    }
    if (rInner != 0) {
        FUN_0076eb00(mat_rInner, rInner);
        p_rInner = mat_rInner;
    }
    if (translation != 0) {
        Mat4Translation(mat_base, translation);
        p_base = mat_base;
    } else {
        p_base = (float *)kIdentity4x4;
    }

    memcpy(dest, p_base, 16 * sizeof(float));

    if (p_tB)       FUN_00412d80(dest, p_tB, dest);
    if (p_rInner)   FUN_00412d80(dest, p_rInner, dest);
    if (p_tB_neg)   FUN_00412d80(dest, p_tB_neg, dest);
    if (p_tA)       FUN_00412d80(dest, p_tA, dest);
    if (p_rOuter)   FUN_00412d80(dest, p_rOuter, dest);
    if (p_scale)    FUN_00412d80(dest, p_scale, dest);
    if (p_rOuterInv)FUN_00412d80(dest, p_rOuterInv, dest);
    if (p_tA_neg)   FUN_00412d80(dest, p_tA_neg, dest);

    return dest;
}
