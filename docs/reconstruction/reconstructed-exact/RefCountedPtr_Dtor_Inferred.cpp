// =============================================================================
// RefCountedPtr_Dtor_Inferred  (FUN_0096efd0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0096efd0
// Address:   0x0096efd0–0x0096f03a  (autoassault.exe, image base 0x400000)
// Body size: 107 bytes (0x6B); pad CC×5; next @ 0x0096f040
// System:    shared util — refcounted handle destructor
// Generated: 2026-07-23 scaffold as FUN_0096efd0; dual A/B seal 2026-08-04 (W38-P)
// Exactness: Behavior-preserving rewrite of decompiler + full-body bytes.
//            Not modernization. Bit-for-bit vs retail: DEFERRED.
// =============================================================================
//
// PURPOSE
//   Destroy / release a 4-byte refcounted handle:
//     if (payload) { --payload->refcount@+8; if 0: (payload+4)->vtbl[2](); *this=0; }
//   Peer of RefCountedPtr_DefaultCtor_Inferred (0x0096ef70, W25-N).
//
// PAYLOAD CONTRACT
//   +0  unknown
//   +4  iface* (release method at vtbl+8; call this = payload+4)
//   +8  int32 refcount
//
// ABI
//   ECX = handle*  (__thiscall / __fastcall)
//   no stack formals; ret (C3)
//   MSVC SEH (LAB_009ac21a): try = release+null; cleanup = release-without-null
//
// CALLERS: 100+ xrefs (real CODE + Unwind@ EH registrations)
//

#include <cstdint>

struct RefCountedPayload {
  void*   field0;   // +0
  void*   iface;    // +4  — points at subobject whose vtbl[2] is release
  int32_t refcount; // +8
};

// Happy-path semantics. SEH cleanup twin (release without null) only matters if
// the try body is interrupted; after a completed try *self is already null.
void RefCountedPtr_Dtor_Inferred(RefCountedPayload** self /*ECX*/)
{
  RefCountedPayload* p = *self;
  if (p == nullptr) {
    return;
  }

  p->refcount -= 1;
  if (p->refcount == 0) {
    // retail: lea ecx, [p+4]; mov eax, [ecx]; call [eax+8]
    void* iface = reinterpret_cast<void*>(reinterpret_cast<char*>(p) + 4);
    void** vtbl = *reinterpret_cast<void***>(iface);
    using ReleaseFn = void(__fastcall*)(void* /*ECX*/);
    reinterpret_cast<ReleaseFn>(vtbl[2])(iface);
  }
  *self = nullptr;
}

// Legacy Ghidra name — see FUN_0096efd0.cpp
// void FUN_0096efd0(int* param_1);
