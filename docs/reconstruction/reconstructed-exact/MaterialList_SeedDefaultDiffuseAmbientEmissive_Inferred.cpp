// =============================================================================
// MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred
//   (Ghidra: FUN_00519280)
// -----------------------------------------------------------------------------
// Stable ID: aa_00519280
// Address:   0x00519280  (autoassault.exe, image base 0x400000)
// System:    client-fx / material color bank seed
// Generated: 2026-08-04 WQ9R-E dual seal (live Ghidra decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Walk material-pointer vector at src+0xC0/0xC4. For each entry, bind
//   MatDiffuse / MatAmbient / MatEmissive to default float4 {0,0,0,1},
//   append that float4 into dst growable bank (stride 0x10), then apply
//   caller-supplied float4 (stack) to the three effect params via 009700f0.
//
// CALLERS:
//   FUN_0051b2a0 — when host float4 bank empty; src=*(vtbl+0x1CC() +8);
//                  dst = host + 0x51 dwords (vector begin @ host+0x148).
//   FUN_004c5480 — similar secondary bank path.
//
// ABI:
//   Stack: src*, dstVecHost*, float r,g,b,a (float4 at &stack+0x0C for 009700f0).
//   Body 0x00519280..0x005194f0 exclusive (624 B). ADD ESP,0x14; RET.
//
// CONSTANTS:
//   g_flOne @ 0x00A0F2A0 = 1.0f (read_memory 00 00 80 3F).
// =============================================================================

#include <cstdint>

struct Float4 {
  float x, y, z, w;
};

struct PtrRange {
  // src+0xC0 begin, src+0xC4 end of void* elements
  void **begin;
  void **end;
};

struct Float4VecHost {
  // addressed so begin/end/cap live at +4/+8/+0xC (host+0x148 family)
  std::uint32_t pad0;
  Float4 *begin;     // +4
  Float4 *end;       // +8
  Float4 *capacity;  // +0xC
};

extern float g_flOne; // DAT @ 0x00A0F2A0

// Callees (not dualed here):
extern "C" void FUN_0051def0(/* residual this + count; see gaps */);
extern "C" void FUN_0096f840(const char *paramName, Float4 *value);
extern "C" void FUN_009700f0(const char *paramName, Float4 *value);
extern "C" void __thiscall FUN_0051d4a0(void *thisVec, /*end*/ void *end,
                                       int count, Float4 *src);
// Live decomp of grow path uses thiscall-ish on dst; signature simplified:
extern "C" void FUN_0051d4a0_push(Float4 *end, int count, Float4 *src);
extern "C" void FUN_00608720(Float4 *dst, int count, Float4 *src);

static int MaterialPtrCount(void *src)
{
  void **b = *reinterpret_cast<void ***>(reinterpret_cast<char *>(src) + 0xC0);
  if (b == nullptr) return 0;
  void **e = *reinterpret_cast<void ***>(reinterpret_cast<char *>(src) + 0xC4);
  return static_cast<int>((reinterpret_cast<char *>(e) - reinterpret_cast<char *>(b)) >> 2);
}

static void PushFloat4(Float4VecHost *dst, Float4 *value)
{
  Float4 *begin = dst->begin;
  if (begin == nullptr ||
      (static_cast<std::uint32_t>(
           reinterpret_cast<char *>(dst->capacity) - reinterpret_cast<char *>(begin)) >> 4) <=
          (static_cast<std::uint32_t>(
               reinterpret_cast<char *>(dst->end) - reinterpret_cast<char *>(begin)) >> 4)) {
    FUN_0051d4a0_push(dst->end, 1, value);
  } else {
    Float4 *end = dst->end;
    FUN_00608720(end, 1, value);
    dst->end = reinterpret_cast<Float4 *>(reinterpret_cast<char *>(end) + 0x10);
  }
}

extern "C" void MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred(
    void *srcMaterialOwner,
    Float4VecHost *dstVecHost,
    float colorR, float colorG, float colorB, float colorA)
{
  Float4 local{};
  local.x = 0.f;
  local.y = 0.f;
  local.z = 0.f;
  local.w = g_flOne; // 1.0f

  // Head helper: vector resize (FUN_0051def0). Decompiler drops ECX/target.
  FUN_0051def0();

  local.x = 0.f;
  local.y = 0.f;
  local.z = 0.f;
  local.w = g_flOne;

  Float4 callerColor{colorR, colorG, colorB, colorA};

  int n = MaterialPtrCount(srcMaterialOwner);
  for (int i = 0; i < n; ++i) {
    FUN_0096f840("MatDiffuse", &local);
    PushFloat4(dstVecHost, &local);

    FUN_0096f840("MatAmbient", &local);
    PushFloat4(dstVecHost, &local);

    FUN_0096f840("MatEmissive", &local);
    PushFloat4(dstVecHost, &local);

    // Apply caller float4 to effect params (stack float4)
    FUN_009700f0("MatDiffuse", &callerColor);
    FUN_009700f0("MatAmbient", &callerColor);
    FUN_009700f0("MatEmissive", &callerColor);
  }
}

extern "C" void FUN_00519280(void *src, Float4VecHost *dst,
                             float r, float g, float b, float a)
{
  MaterialList_SeedDefaultDiffuseAmbientEmissive_Inferred(src, dst, r, g, b, a);
}
