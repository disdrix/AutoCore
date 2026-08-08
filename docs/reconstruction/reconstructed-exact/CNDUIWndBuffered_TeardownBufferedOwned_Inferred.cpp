// =============================================================================
// CNDUIWndBuffered_TeardownBufferedOwned_Inferred  (FUN_0078c3d0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0078c3d0
// Address:   0x0078c3d0  (autoassault.exe, image base 0x400000)
// Body:      0x0078c3d0–0x0078c47e inclusive (175 B / 0xAF)
// System:    CNDUIWndBuffered buffered-owned nested teardown
// Generated: 2026-08-05 WQ9L-D2 dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + full-body read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Helper called from CNDUIWndBuffered_CompleteDtor (and installed in related
//   vtable slots). When this+0x2A4 is non-null:
//     1) Unregister + scalar-delete owned object at +0x2AC
//     2) Optionally same for owned object at +0x49C
//     3) Scalar-delete primary owned at +0x2A4
//     4) Refcount-release COM-like pointer at (*(HostBase+4))+0x3C
//   Does NOT free nested HostBase at +0x2A8 (parent complete dtor does that).
//
// ABI:
//   ECX = CNDUIWndBuffered* this. No stack formals. Bare RET (C3). void.
//
// CALLEES:
//   FUN_0074e260 ×2 — thiscall unregister(host_aux, key_from_child+0x8C)
//   vtbl[0](1)     — scalar-deleting dtor of owned children (≤3)
//   vtbl[+8]()     — destroy when refcount hits 0
//
// CALLERS:
//   CNDUIWndBuffered_CompleteDtor FUN_0078ca80 @ 0x0078cab2
//   DATA vtable slots: 00a9a32c, 00a6ff84, 00a6755c, 00a66d24
//
// PEERS:
//   Parent complete: CNDUIWndBuffered_CompleteDtor @ 0x0078ca80 (dualed)
//   Ctor:            CNDUIWndBuffered_Ctor_Inferred @ 0x0078caf0
//   HostBase:        FUN_007560d0 @ nested +0x2A8
//   RTTI:            .?AVCNDUIWndBuffered@@
//
// ODD BEHAVIOR (preserve):
//   +0x2AC null store is interleaved after CMP of +0x49C (before JZ).
//   +0x2A4 null store is after reload of +0x2A8 into EAX.
//   Gate is +0x2A4 only — if null, entire body is a no-op.
// =============================================================================

#include <cstdint>

// Unregister key from HostBase aux registry (scaffold dual open).
// ABI sealed by call sites: ECX = host_aux, stack = key (often from child+0x8C).
extern "C" void __thiscall FUN_0074e260(void *host_aux, void *key);

// Machine: ECX = CNDUIWndBuffered* self.
extern "C" void __fastcall CNDUIWndBuffered_TeardownBufferedOwned_Inferred(void *self)
{
  // PUSH ESI; PUSH EDI; MOV ESI,ECX; XOR EDI,EDI
  auto *base = reinterpret_cast<uint8_t *>(self);

  if (*reinterpret_cast<void **>(base + 0x2A4) == nullptr) {
    // JZ epilogue — bare POP EDI; POP ESI; RET
    return;
  }

  // --- +0x2AC: unregister then scalar-delete ---
  void *child_2ac = *reinterpret_cast<void **>(base + 0x2AC);
  void *host = *reinterpret_cast<void **>(base + 0x2A8);
  void *key = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(child_2ac) + 0x8C);
  void *host_aux = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(host) + 4);
  FUN_0074e260(host_aux, key);

  if (child_2ac != nullptr) {
    void **vtbl = *reinterpret_cast<void ***>(child_2ac);
    reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0])(child_2ac, 1);
  }

  // Bytes: load +0x49C, CMP, then store null to +0x2AC (interleaved)
  void *child_49c = *reinterpret_cast<void **>(base + 0x49C);
  *reinterpret_cast<void **>(base + 0x2AC) = nullptr;

  // --- +0x49C: optional same ---
  if (child_49c != nullptr) {
    host = *reinterpret_cast<void **>(base + 0x2A8);
    key = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(child_49c) + 0x8C);
    host_aux = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(host) + 4);
    FUN_0074e260(host_aux, key);

    // Re-load for null check (bytes re-read [ESI+0x49C])
    child_49c = *reinterpret_cast<void **>(base + 0x49C);
    if (child_49c != nullptr) {
      void **vtbl = *reinterpret_cast<void ***>(child_49c);
      reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0])(child_49c, 1);
    }
    *reinterpret_cast<void **>(base + 0x49C) = nullptr;
  }

  // --- +0x2A4: scalar-delete gate object ---
  void *child_2a4 = *reinterpret_cast<void **>(base + 0x2A4);
  if (child_2a4 != nullptr) {
    void **vtbl = *reinterpret_cast<void ***>(child_2a4);
    reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0])(child_2a4, 1);
  }
  host = *reinterpret_cast<void **>(base + 0x2A8);
  *reinterpret_cast<void **>(base + 0x2A4) = nullptr;

  // --- HostBase+4 aux: refcount-release slot +0x3C ---
  host_aux = *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(host) + 4);
  int *refobj = *reinterpret_cast<int **>(reinterpret_cast<uint8_t *>(host_aux) + 0x3C);
  if (refobj != nullptr) {
    refobj[1] = refobj[1] - 1; // ADD dword ptr [ECX+4], -1
    if (refobj[1] == 0) {
      void **vtbl = *reinterpret_cast<void ***>(refobj);
      reinterpret_cast<void (*)()>(vtbl[2])(); // CALL [EDX+8] — vtbl index 2
    }
  }
  *reinterpret_cast<void **>(reinterpret_cast<uint8_t *>(host_aux) + 0x3C) = nullptr;
  // POP EDI; POP ESI; RET
}

// Ghidra twin name
extern "C" void __fastcall FUN_0078c3d0(void *self)
{
  CNDUIWndBuffered_TeardownBufferedOwned_Inferred(self);
}
