// =============================================================================
// RefCountedPtr3Flags_Dtor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0096f510
// Address:   0x0096f510–0x0096f522 exclusive (18 B / 0x12)
// Module:    autoassault.exe (image base 0x400000)
// System:    shared util — refcounted handle + 3 flag bytes dtor/release
// Wave:      W37-H 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Release the payload held by a RefCountedPtr3Flags handle:
//     load *handle; if null return;
//     --payload.refcount (+4); if remaining, return;
//     else tail-jump to vtbl[+8] Release (FF 60 08), which returns to caller.
//   Does NOT clear *handle. Does NOT touch handle flag bytes +4/+5/+6.
//
// ABI:
//   ECX = handle* (only the pointer field is used; flags ignored).
//   Bare RET (C3). Void. No stack formals.
//
// PAYLOAD LAYOUT (distinct from RefCountedPtr / 0096efd0):
//   +0x00  vtbl*
//   +0x04  refcount (int)
//
// PEER CTOR: RefCountedPtr3Flags_DefaultCtor_Inferred @ 0x0096f530 (W35-G).
//   Vector-ctor pairs size 8: ctor=0096f530, dtor=this (e.g. FUN_00457720).
//
// BYTES:
//   8B 09 85 C9 74 0B 83 41 04 FF 75 05 8B 01 FF 60 08 C3
//
// =============================================================================

#include <cstdint>

struct RefCountedPtr3Flags {
  void*   ptr;    // +0x00
  uint8_t flag0;  // +0x04  (not touched by dtor)
  uint8_t flag1;  // +0x05
  uint8_t flag2;  // +0x06
  // +0x07 pad
};

struct RefCountedPayload_VtblRef4 {
  void**  vtbl;     // +0x00
  int32_t refcount; // +0x04
};

// Ghidra: FUN_0096f510 — decompiler treats JMP [vtbl+8] as CALL (harmless for CF)
extern "C" void __fastcall RefCountedPtr3Flags_Dtor_Inferred(
    RefCountedPtr3Flags* handle /*ECX*/)
{
  auto* payload = reinterpret_cast<RefCountedPayload_VtblRef4*>(handle->ptr);
  if (payload == nullptr) {
    return;
  }

  payload->refcount -= 1;
  if (payload->refcount != 0) {
    return;
  }

  // Retail: mov eax,[ecx]; jmp dword ptr [eax+8]  — tail Release
  using ReleaseFn = void(__fastcall*)(RefCountedPayload_VtblRef4* self);
  auto release = reinterpret_cast<ReleaseFn>(payload->vtbl[2]); // +8
  release(payload);
}
