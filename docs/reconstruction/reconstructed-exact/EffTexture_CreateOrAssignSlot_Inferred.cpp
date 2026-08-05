// =============================================================================
// EffTexture_CreateOrAssignSlot_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f0e0
// Address:   0x0096f0e0–0x0096f15c exclusive (124 B / 0x7C)
// Module:    autoassault.exe (image base 0x400000)
// System:    palantir graphics Effects — effTexture create/assign
// Wave:      W37-H 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Create a new effect-texture instance via FUN_0096e9f0 and assign it into
//   a single-pointer slot (this). On create failure, log
//   effTexture.cpp:0x57 "Failed to create instance of texture." and return -1.
//   On success: acquire new (inc ref @+8; if first, virtual method vtbl[+4]
//   on subobject +4), release prior *slot the same way (dec +8; if zero,
//   virtual vtbl[+8] on +4), store new, return 0.
//
// ABI:
//   ECX = slot* (pointer to payload*). Six stack dwords. RET 0x18.
//   Returns 0 success / 0xffffffff fail.
//   Ghidra thiscall formals match; one stack dword is loaded then unused (dead).
//   Factory FUN_0096e9f0 formals under-declared in Ghidra (five pushes observed).
//
// PAYLOAD LAYOUT (shared with RefCountedPtr / 0096efd0 family):
//   +0x00  (opaque)
//   +0x04  interface / vtbl-bearing subobject (this-adjust for methods)
//   +0x08  refcount (int)
//   NOT the RefCountedPtr3Flags payload (+0 vtbl / +4 ref).
//
// STRINGS (read_memory):
//   0x00a9ed50  "C:\\vog\\1_code\\palantir\\palantir\\graphics\\Effects\\effTexture.cpp"
//   0x00a9ed24  "Failed to create instance of texture."
//
// BYTES: see raw W37-H append (124 B).
//
// =============================================================================

#include <cstdint>

struct EffTexturePayload {
  uint32_t opaque0;   // +0x00
  void*    iface;     // +0x04  → vtbl*
  int32_t  refcount;  // +0x08
};

using VMethod = void(__fastcall*)(void* self /*ECX*/);

// Ghidra: FUN_0096e9f0 — formals incomplete; treat as opaque factory.
extern "C" EffTexturePayload* __cdecl FUN_0096e9f0(
    uint32_t a0, uint32_t a1, uint32_t a2, uint32_t a3, uint32_t a4);

extern "C" void vog_LogMessage(const char* file, int line, int severity, const char* msg);

// Ghidra: FUN_0096f0e0
extern "C" int32_t __thiscall EffTexture_CreateOrAssignSlot_Inferred(
    EffTexturePayload** slot /*ECX*/,
    uint32_t p0,
    uint32_t p1, // loaded then unused in body (dead)
    uint32_t p2,
    uint32_t p3,
    uint32_t p4,
    uint32_t p5)
{
  (void)p1; // dead load into EBX in retail body

  // Decompiler forwards p0,p2,p3,p4,p5 (skips unused p1) to factory.
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
    vtbl[1](sub); // vtbl[+4] — first-acquire / AddRef-style
  }

  EffTexturePayload* old = *slot;
  if (old != nullptr) {
    old->refcount -= 1;
    if (old->refcount == 0) {
      void* sub = &old->iface;
      VMethod* vtbl = *reinterpret_cast<VMethod**>(sub);
      vtbl[2](sub); // vtbl[+8] — final Release
    }
  }

  *slot = neu;
  return 0;
}
