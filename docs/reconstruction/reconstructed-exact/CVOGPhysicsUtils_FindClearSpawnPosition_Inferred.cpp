// =============================================================================
// CVOGPhysicsUtils_FindClearSpawnPosition_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e9720
// Address:   0x004e9720–0x004e9a9b  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 R13-027 OWN-ONLY dual (live Ghidra re-verify)
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly corrections.
// Bit-for-bit vs retail EXE: DEFERRED. Runtime Confirmed: NOT claimed.
// Parent:    0x005eb790 VOGPhysics_QueryCollect_Ctor_Inferred
// =============================================================================

// PURPOSE:
//   Probe for a collision-clear spawn/placement float4 using a temporary sphere
//   shape + query-collect object. Success when a collect pass returns zero hits.
//   Used by CVOGSpawnPoint_CreateCreature / CreateTemplateVehicle (fail strings
//   "Couldn't find a spawn position…"). Product method English open → _Inferred.

// READABILITY:
//   - Assembly corrections: host param live; height thiscall on host; RNG @ 007a4330.
//   - SEH / ExceptionList framing omitted as non-semantic.
//   - FUN_* residual callees retained where not dual-sealed this wave.

#include <cstdint>

// Residual callees (not dualled this OWN wave)
extern "C" void *FUN_006c7fa0(void *self /*ECX*/, float radius); // PhysicsShape_Sphere_CtorFromRadius_Inferred
extern "C" void  FUN_005eb8d0(void *params /*ECX*/);
extern "C" int  *FUN_005eb790(void *self /*ECX*/, void *params); // VOGPhysics_QueryCollect_Ctor_Inferred
extern "C" void  FUN_0055ff20(void *phys /*ECX*/, int *query);
extern "C" void  FUN_00560020(void *phys /*ECX*/, int *query);
extern "C" void  FUN_005eb130(void *query /*ECX*/, float *pose);
extern "C" void *FUN_007a4330(void); // random ushort source (decomp may rename)
extern "C" long double FUN_004cd220(void *host /*ECX*/, float x, float z);
extern "C" void  FUN_004eacc0(void *hit_triad /*ECX*/);

// Globals sealed via read_memory
static float const &DAT_00a0f298 = *reinterpret_cast<float *>(0x00a0f298); // 0.5f
static float const &DAT_00a0f2a0 = *reinterpret_cast<float *>(0x00a0f2a0); // 1.0f
static float const &DAT_00a0f518 = *reinterpret_cast<float *>(0x00a0f518); // 0.0f
static float const &DAT_009cc4a8 = *reinterpret_cast<float *>(0x009cc4a8); // ~1/32768
static float const &DAT_00aaa664 = *reinterpret_cast<float *>(0x00aaa664); // ~1e-4
static void       *const PTR_FUN_009ccbb4 = reinterpret_cast<void *>(0x009ccbb4);
extern "C" void  **DAT_00b05060;

static void copy_float4(float *dst, float const *src) {
  dst[0] = src[0];
  dst[1] = src[1];
  dst[2] = src[2];
  dst[3] = src[3];
}

static void release_if_zero_refcount(void *obj) {
  auto *base = reinterpret_cast<int *>(obj);
  auto *rc = reinterpret_cast<int16_t *>(reinterpret_cast<char *>(obj) + 6);
  *rc = static_cast<int16_t>(*rc - 1);
  if (*rc == 0) {
    auto **vtbl = reinterpret_cast<void **>(*base);
    auto *dtor = reinterpret_cast<void (__thiscall *)(void *, int)>(vtbl[0]);
    dtor(obj, 1);
  }
}

bool __cdecl CVOGPhysicsUtils_FindClearSpawnPosition_Inferred(
    void *host,
    float *in_pos,
    float scatter_radius,
    float sphere_radius,
    float *out_pos,
    uint32_t query_cookie,
    unsigned char max_attempts,
    unsigned char keep_last_on_fail)
{
  // alloc sphere 0x10 / tag 0x22
  auto *alloc_vtbl = *reinterpret_cast<void ***>(DAT_00b05060);
  auto *alloc_fn = reinterpret_cast<void *(__thiscall *)(void *, int, int)>(
      alloc_vtbl[0x10 / 4]);
  void *shape_mem = alloc_fn(DAT_00b05060, 0x10, 0x22);
  *reinterpret_cast<uint16_t *>(reinterpret_cast<char *>(shape_mem) + 4) = 0x10;
  void *shape = FUN_006c7fa0(shape_mem, sphere_radius);

  alignas(16) unsigned char params_block[0x40] = {};
  // layout residual: cookie/shape/pose filled around FUN_005eb8d0 + stores
  FUN_005eb8d0(params_block);
  // assembly: store cookie, shape*, copy in float4 into params pose
  *reinterpret_cast<uint32_t *>(params_block + 0x04) = query_cookie; // offset residual
  *reinterpret_cast<void **>(params_block + 0x00) = shape;           // offset residual

  void *qmem = alloc_fn(DAT_00b05060, 0xD0, 0x2C);
  *reinterpret_cast<uint16_t *>(reinterpret_cast<char *>(qmem) + 4) = 0xD0;
  int *query = FUN_005eb790(qmem, params_block); // parent dual 0x005eb790

  release_if_zero_refcount(shape);

  void *phys = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 0xE4A4);
  FUN_0055ff20(phys, query);

  // hit triad on stack: vtbl, flag, buf*, count, cap
  alignas(16) unsigned char hit_buf[264];
  void *hit[5];
  hit[0] = PTR_FUN_009ccbb4;
  *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(&hit[0]) + 4) = 0; // flag@+4 residual
  hit[2] = hit_buf;
  hit[3] = nullptr; // count = 0
  hit[4] = reinterpret_cast<void *>(0x80000010);

  copy_float4(out_pos, in_pos);
  out_pos[1] = out_pos[1] + sphere_radius + DAT_00a0f298;

  bool still_blocked = true;
  do {
    FUN_005eb130(query, out_pos);
    auto **qvt = reinterpret_cast<void **>(*query);
    auto *collect = reinterpret_cast<void (__thiscall *)(void *, void *)>(qvt[0x30 / 4]);
    collect(query, hit);

    int count = static_cast<int>(reinterpret_cast<intptr_t>(hit[3]));
    if (count == 0) {
      max_attempts = 0;
      still_blocked = false;
    } else {
      hit[3] = nullptr;
      // clear flag
      auto *rng = FUN_007a4330();
      if (*reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) > 0xFFFFF)
        *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) = 0;
      int idx = *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC);
      uint16_t u_z = *reinterpret_cast<uint16_t *>(
          *reinterpret_cast<char **>(reinterpret_cast<char *>(rng) + 8) + idx * 2);
      *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) = idx + 1;

      rng = FUN_007a4330();
      if (*reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) > 0xFFFFF)
        *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) = 0;
      idx = *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC);
      uint16_t u_x = *reinterpret_cast<uint16_t *>(
          *reinterpret_cast<char **>(reinterpret_cast<char *>(rng) + 8) + idx * 2);
      *reinterpret_cast<int *>(reinterpret_cast<char *>(rng) + 0xC) = idx + 1;

      copy_float4(out_pos, in_pos);
      float scale = DAT_009cc4a8;
      float one = DAT_00a0f2a0;
      out_pos[1] = out_pos[1] + scatter_radius * DAT_00aaa664;
      out_pos[0] = out_pos[0] + ((float)u_x * scale - one) * scatter_radius;
      out_pos[2] = out_pos[2] + ((float)u_z * scale - one) * scatter_radius;
      out_pos[3] = out_pos[3] + scatter_radius * DAT_00a0f518;

      long double h = FUN_004cd220(host, out_pos[0], out_pos[2]);
      out_pos[1] = (float)(h + (long double)sphere_radius + (long double)DAT_00a0f298);
    }

    unsigned char prev = max_attempts;
    max_attempts = static_cast<unsigned char>(max_attempts - 1);
    if (prev == 0)
      break;
  } while (true);

  if (still_blocked && keep_last_on_fail == 0)
    copy_float4(out_pos, in_pos);

  phys = *reinterpret_cast<void **>(reinterpret_cast<char *>(host) + 0xE4A4);
  FUN_00560020(phys, query);
  release_if_zero_refcount(query);
  FUN_004eacc0(hit);

  // free shape heap when capacity high-bit clear (residual free path)
  return !still_blocked;
}
