// =============================================================================
// FUN_00519280 — twin of MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred
// Stable ID: aa_00519280 | VA: 0x00519280
// See: MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred.cpp
// =============================================================================

#include <cstdint>

struct Float4 { float x, y, z, w; };

struct Float4VecHost {
  std::uint32_t pad0;
  Float4 *begin;
  Float4 *end;
  Float4 *capacity;
};

extern float g_flOne;
extern "C" void FUN_0051def0();
extern "C" void FUN_0096f840(const char *name, Float4 *v);
extern "C" void FUN_009700f0(const char *name, Float4 *v);
extern "C" void FUN_0051d4a0_push(Float4 *end, int n, Float4 *src);
extern "C" void FUN_00608720(Float4 *dst, int n, Float4 *src);

static void PushFloat4(Float4VecHost *dst, Float4 *value)
{
  Float4 *begin = dst->begin;
  if (begin == nullptr ||
      ((std::uint32_t)((char *)dst->capacity - (char *)begin) >> 4) <=
          ((std::uint32_t)((char *)dst->end - (char *)begin) >> 4)) {
    FUN_0051d4a0_push(dst->end, 1, value);
  } else {
    Float4 *end = dst->end;
    FUN_00608720(end, 1, value);
    dst->end = (Float4 *)((char *)end + 0x10);
  }
}

extern "C" void FUN_00519280(void *src, Float4VecHost *dst,
                             float r, float g, float b, float a)
{
  Float4 local = {0.f, 0.f, 0.f, g_flOne};
  FUN_0051def0();
  local = {0.f, 0.f, 0.f, g_flOne};
  Float4 caller = {r, g, b, a};

  int n = 0;
  void **b = *(void ***)((char *)src + 0xC0);
  if (b != nullptr) {
    void **e = *(void ***)((char *)src + 0xC4);
    n = (int)(((char *)e - (char *)b) >> 2);
  }

  for (int i = 0; i < n; ++i) {
    FUN_0096f840("MatDiffuse", &local);
    PushFloat4(dst, &local);
    FUN_0096f840("MatAmbient", &local);
    PushFloat4(dst, &local);
    FUN_0096f840("MatEmissive", &local);
    PushFloat4(dst, &local);
    FUN_009700f0("MatDiffuse", &caller);
    FUN_009700f0("MatAmbient", &caller);
    FUN_009700f0("MatEmissive", &caller);
  }
}
