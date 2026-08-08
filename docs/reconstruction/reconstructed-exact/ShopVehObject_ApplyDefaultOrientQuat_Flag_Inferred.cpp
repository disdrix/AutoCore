// =============================================================================
// ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred  (FUN_0083a880)
// -----------------------------------------------------------------------------
// Stable ID: aa_0083a880
// Address:   0x0083a880 – 0x0083a94d inclusive (206 B / 0xCE); pad CC after RET 4
// System:    shopveh list UI — default orientation seed / apply on slot object
// Generated: 2026-08-05 WQ9L-J dual seal (decompile + read_memory + assembly_context)
// Exactness: Behavior-preserving rewrite from body bytes / call-site context.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: Apply the shopveh default display quaternion (DAT_00aaa97c..988,
// normalized via dualed Math_QuatNormalize) to a slot object.
//
//   flag == 0 (reindex refresh / post-swap): seed cached orient block at
//             obj+0x5e0..+0x5ec and set obj+0x5dc = 1, then re-normalize.
//   flag != 0 (post-bind from FUN_0083ab90): write quat into XformState at
//             obj+0x510 via FUN_0040d1a0 (stores at obj+0x590), run
//             FUN_00833490, optional nested vtbl+0x44, then FUN_00833390.
//
// Object layout (partial; shared with dualed ShopVehObject_SwapSelectState):
//   +0x508  nested* (optional)
//   +0x510  XformState (FUN_0040d1a0 this-ptr; quat lives at this+0x80 → +0x590)
//   +0x5dc  uint8  orient-seed flag
//   +0x5e0  float[4] cached orient quat
//
// ABI (bytes): EAX = obj*; stack uint8 flag; void; RET 4 (stdcall 1 arg).

#include <cstdint>

// Dualed
extern "C" float *Math_QuatNormalize(float *out, float *in); // FUN_0076e5e0

// Residual helpers
extern "C" void __thiscall FUN_0040d1a0(void *xform_this, const float *quat4);
extern "C" void FUN_00833490(/* ESI = obj */);
extern "C" void FUN_00833390(/* EAX = nested */);

// Default display quat components (image .data, little-endian floats).
// Memory order: 00aaa97c, 00aaa980, 00aaa984, 00aaa988.
// Stack local fill order matches decompiler (988,984,980,97c).
extern "C" float DAT_00aaa97c;
extern "C" float DAT_00aaa980;
extern "C" float DAT_00aaa984;
extern "C" float DAT_00aaa988;

// Portable reconstruction; product uses EAX + stack flag + RET 4.
extern "C" void ShopVehObject_ApplyDefaultOrientQuat_Flag_Inferred(
    void *obj, uint8_t flag)
{
  if (obj == nullptr) {
    return;
  }

  auto *base = reinterpret_cast<uint8_t *>(obj);

  float local[4] = {
      DAT_00aaa988,
      DAT_00aaa984,
      DAT_00aaa980,
      DAT_00aaa97c,
  };
  Math_QuatNormalize(local, local);

  if (flag != 0) {
    // thiscall: ECX = obj+0x510, stack &local
    FUN_0040d1a0(base + 0x510, local);
    FUN_00833490(/* ESI = obj */);

    void *nested = *reinterpret_cast<void **>(base + 0x508);
    if (nested != nullptr) {
      auto **vtbl = *reinterpret_cast<void ***>(nested);
      using VFn = void(__thiscall *)(void *);
      reinterpret_cast<VFn>(vtbl[0x44 / 4])(nested);
    }
    // FUN_00833390 expects nested in EAX
    FUN_00833390(/* EAX = nested */);
    return;
  }

  // flag == 0: seed cached block used by select-state swap
  float *dst = reinterpret_cast<float *>(base + 0x5e0);
  dst[0] = local[0];
  dst[1] = local[1];
  dst[2] = local[2];
  dst[3] = local[3];
  base[0x5dc] = 1;
  Math_QuatNormalize(dst, dst);
}
