// =============================================================================
// FUN_0096f0e0  (twin of EffTexture_CreateOrAssignSlot_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f0e0
// Address:   0x0096f0e0–0x0096f15c exclusive (124 B / 0x7C)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W37-H 2026-08-04
// Canonical: EffTexture_CreateOrAssignSlot_Inferred
// =============================================================================

#include <cstdint>

struct EffTexturePayload {
  uint32_t opaque0;
  void*    iface;
  int32_t  refcount;
};

using VMethod = void(__fastcall*)(void* self);

extern "C" EffTexturePayload* __cdecl FUN_0096e9f0(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);
extern "C" void vog_LogMessage(const char* file, int line, int severity, const char* msg);

extern "C" int32_t __thiscall FUN_0096f0e0(
    EffTexturePayload** slot /*ECX*/,
    uint32_t p0,
    uint32_t p1,
    uint32_t p2,
    uint32_t p3,
    uint32_t p4,
    uint32_t p5)
{
  (void)p1;

  EffTexturePayload* neu = FUN_0096e9f0(p0, p2, p3, p4, p5);
  if (neu == nullptr) {
    vog_LogMessage(
        "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTexture.cpp",
        0x57,
        3,
        "Failed to create instance of texture.");
    return -1;
  }

  neu->refcount += 1;
  if (neu->refcount == 1) {
    void* sub = &neu->iface;
    VMethod* vtbl = *reinterpret_cast<VMethod**>(sub);
    vtbl[1](sub);
  }

  EffTexturePayload* old = *slot;
  if (old != nullptr) {
    old->refcount -= 1;
    if (old->refcount == 0) {
      void* sub = &old->iface;
      VMethod* vtbl = *reinterpret_cast<VMethod**>(sub);
      vtbl[2](sub);
    }
  }

  *slot = neu;
  return 0;
}
