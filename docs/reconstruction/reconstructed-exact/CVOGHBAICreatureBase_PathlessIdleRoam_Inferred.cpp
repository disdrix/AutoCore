// =============================================================================
// CVOGHBAICreatureBase_PathlessIdleRoam_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005cd220
// Address:   0x005cd220 – 0x005cd3ad exclusive  (397 B / 0x18D)
// Module:    autoassault.exe  image base 0x400000
// System:    client creature HBAI / pathless idle roam
// Ghidra:    FUN_005cd220
// Generated: 2026-07-29 W30-S dual seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B:  accept-with-gaps (W30-S).
// =============================================================================
//
// PURPOSE:
//   Pathless idle roam step for CVOGHBAICreatureBase:
//     - Gate on owner+0x279 and per-AI cooldown vs g_dwClientTickMs.
//     - 1/3 random chance to pick a local XZ offset within table radius +0x4d4
//       (radius floor-add 3.0f when r < 3).
//     - Transform offset by object orientation (quat @ +0x28 via FUN_0053e0b0 +
//       Math_QuatTransformPoint_Inferred) and issue move via AI vtbl+0x4c.
//   Does NOT seek the player. Called from CVOGHBAICreatureBase_OnHeartBeat.
//
// ABI:
//   __thiscall  ECX = AI controller*
//   stack:      none
//   epilogue:   ret (c3)
//   return:     uint (incidental; OnHeartBeat ignores)
//
// CALLER:
//   CVOGHBAICreatureBase_OnHeartBeat @ 0x005d0310 (sites 0x005d0667, 0x005d0769)
// =============================================================================

#include <cstdint>

// Shared float pool (misnamed in Ghidra for other systems).
static float const *const kFlTwo =
    reinterpret_cast<float const *>(static_cast<uintptr_t>(0x00A10E74));       // 2.0f
static float const *const kFlRadiusFloorAdd =
    reinterpret_cast<float const *>(static_cast<uintptr_t>(0x00A1330C));       // 3.0f
static float const *const kFlU16Scale =
    reinterpret_cast<float const *>(static_cast<uintptr_t>(0x00AAA638));       // ~1/65536
static uint32_t const *const kClientTickMs =
    reinterpret_cast<uint32_t const *>(static_cast<uintptr_t>(0x00B041CC));

extern "C" int __cdecl CVOGReaction_RandomUnitScalar(void);
extern "C" void *__fastcall FUN_0053e0b0(void *object_ctx);
extern "C" void Math_QuatTransformPoint_Inferred(void *quat, void *point_io);

// Draw next ushort from RandomUnitScalar stream (wrap index at 0x100000).
static uint16_t DrawRandU16()
{
  int *st = reinterpret_cast<int *>(CVOGReaction_RandomUnitScalar());
  if (st[3] > 0xfffff) {
    st[3] = 0;
  }
  uint16_t v = *reinterpret_cast<uint16_t *>(st[2] + st[3] * 2);
  st[3] = st[3] + 1;
  return v;
}

uint32_t __thiscall CVOGHBAICreatureBase_PathlessIdleRoam_Inferred(int *self /* ECX */)
{
  uint32_t retish = static_cast<uint32_t>(self[0x19]); // owner ptr-ish
  uint8_t *owner = reinterpret_cast<uint8_t *>(self[0x19]);

  if (*reinterpret_cast<char *>(owner + 0x279) == 0) {
    return retish;
  }
  // cooldown: field[0x1d] < g_dwClientTickMs - field[0x1c]
  if (!(static_cast<uint32_t>(self[0x1d]) < (*kClientTickMs - static_cast<uint32_t>(self[0x1c])))) {
    return retish;
  }

  *reinterpret_cast<uint8_t *>(self + 0x1e) = 1; // +0x78

  uint16_t uGate = DrawRandU16();
  uint32_t u = uGate;
  retish = u / 3;
  if ((u % 3) != 0) {
    return retish;
  }

  // radius @ clonebase/AI table +0x4d4 (deep deref from owner)
  // path: *(*(*(*(owner+4)+4) + 0xac + owner) + 0x3c) + 0x4d4
  int t0 = *reinterpret_cast<int *>(owner + 4);
  int t1 = *reinterpret_cast<int *>(t0 + 4);
  int t2 = *reinterpret_cast<int *>(t1 + 0xac + reinterpret_cast<int>(owner));
  int t3 = *reinterpret_cast<int *>(t2 + 0x3c);
  float r = *reinterpret_cast<float *>(t3 + 0x4d4);
  if (r < *kFlRadiusFloorAdd) {
    r = r + *kFlRadiusFloorAdd;
  }

  float off[4];
  uint16_t uz = DrawRandU16();
  uint16_t ux = DrawRandU16();
  float scale = (*kFlTwo) * (*kFlU16Scale); // ~1/32768
  off[0] = static_cast<float>(ux) * r * scale - r;
  off[1] = 0.0f;
  off[2] = static_cast<float>(uz) * r * scale - r;
  off[3] = 0;

  uint8_t local20[28];
  void *quat = FUN_0053e0b0(/* object — ECX from retail */);
  // owner vtbl+0x1a4(off, local20)
  int *owner_vtbl_root = *reinterpret_cast<int **>(
      *reinterpret_cast<int *>(*reinterpret_cast<int *>(owner + 4) + 4) + 4
      + reinterpret_cast<int>(owner));
  using Vtbl1a4 = void *(__thiscall *)(void *ecx, float *off, void *out);
  void *packed = reinterpret_cast<Vtbl1a4>((*owner_vtbl_root) /* +0x1a4 slot */)(
      /* this from retail */, off, local20);
  // Note: staged clean keeps call shape; exact ECX for vtbl is owner multi-inherit adj.
  (void)packed;
  Math_QuatTransformPoint_Inferred(quat, local20);

  using Vtbl4c = uint32_t(__thiscall *)(void *ecx, void *dest, int zero);
  int *ai_vtbl = reinterpret_cast<int *>(self[0]);
  retish = reinterpret_cast<Vtbl4c>(ai_vtbl[0x4c / 4])(self, local20, 0);
  return retish;
}
