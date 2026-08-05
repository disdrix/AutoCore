// =============================================================================
// FUN_0096f510  (twin of RefCountedPtr3Flags_Dtor_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f510
// Address:   0x0096f510–0x0096f522 exclusive (18 B / 0x12)
// Module:    autoassault.exe (image base 0x400000)
// Wave:      W37-H 2026-08-04
// Canonical: RefCountedPtr3Flags_Dtor_Inferred
// =============================================================================

#include <cstdint>

struct RefCountedPtr3Flags {
  void*   ptr;
  uint8_t flag0;
  uint8_t flag1;
  uint8_t flag2;
};

struct RefCountedPayload_VtblRef4 {
  void**  vtbl;
  int32_t refcount;
};

extern "C" void __fastcall FUN_0096f510(RefCountedPtr3Flags* handle /*ECX*/)
{
  auto* payload = reinterpret_cast<RefCountedPayload_VtblRef4*>(handle->ptr);
  if (payload == nullptr) {
    return;
  }

  payload->refcount -= 1;
  if (payload->refcount != 0) {
    return;
  }

  using ReleaseFn = void(__fastcall*)(RefCountedPayload_VtblRef4* self);
  auto release = reinterpret_cast<ReleaseFn>(payload->vtbl[2]);
  release(payload);
}
