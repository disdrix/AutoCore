// =============================================================================
// ObjectMotion_IntegrateStep_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b1100
// Address:   0x004b1100 – 0x004b18e5  (autoassault.exe, image base 0x400000)
// System:    client object motion / reaction entity pose
// Generated: 2026-07-29 W24-C dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b1100.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   One-step integrate of a motion slot's world position/orientation:
//     - free path: nested basis prep, flag-gated force helpers, heightfield Y pad
//     - attach chase path when def+0x3e3 bit3 + host+0xc
//     - path-sample path when host path pointer non-null
//     - post mode 2 (delta basis) / mode 4 (copy host facing)
//     - optional host linear velocity accumulate
//
// ABI:
//   __thiscall (ECX = motion slot); 3 stack args; ret 0xC (C2 0C 00); void.
//
// RELATED (sealed peers):
//   FUN_004e8590 = Math_QuatInverseRotateDelta_Inferred (W23-O)
//   FUN_004cd220 = CVOGMap_SampleHeightfieldY (family)
// =============================================================================

#include <cstdint>

// Contract sketch — full residual in FUN_004b1100.cpp
//
// void ObjectMotion_IntegrateStep_Inferred(
//     int* slot, int enable_hf_y, uint32_t ctx, float dt)
// {
//   float *pos = (float*)&slot[0x5e];
//   float snap[3] = { pos[0], pos[1], pos[2] };
//   int* host = (int*)slot[0];
//   int  def  = slot[1];
//   if (*(void**)host == nullptr) {
//     // optional nested quat prep → inverse-rotate + forward peer
//     // attach chase OR force-bit helpers
//     // optional heightfield Y clamp when enable_hf_y
//   } else {
//     // path sample by slot[0x6a]; optional look-ahead bias
//   }
//   if (host[0x984/4] == 2) store_unit_delta(pos - snap);
//   else if (== 4) copy host facing +0x844;
//   // optional host velocity * dt
// }

// Prefer linking against the decompiler mirror for residual CF:
//   docs/reconstruction/reconstructed-exact/FUN_004b1100.cpp
