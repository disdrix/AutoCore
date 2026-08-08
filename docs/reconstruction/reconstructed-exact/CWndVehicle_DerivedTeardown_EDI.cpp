// =============================================================================
// CWndVehicle_DerivedTeardown_EDI  (FUN_00833d50)
// -----------------------------------------------------------------------------
// Stable ID: aa_00833d50
// Address:   0x00833d50  (autoassault.exe, image base 0x400000)
// Body:      0x00833d50 – 0x00833df7 exclusive (167 B / 0xA7)
// System:    CWndVehicle / UI derived member teardown (EDI=this)
// Generated: 2026-08-05 WQ9K-E dual seal (raw 2026-07-23 re-verified live)
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Nested/derived teardown helper for CWndVehicle. Clears selection slot
//   +0x50C, re-notifies nested host @+0x2A8 (same plate as complete dtor),
//   scalar-deletes vehicle object host @+0x508 (optional child @host+0x258
//   + Vehicle_SetWheelset(0)), nulls +0x508. Does NOT free CWndVehicle this
//   and does NOT call base UI dtor (complete path owns that).
//
// ABI:
//   Machine: EDI = CWndVehicle* this. No stack formals. Bare RET (C3). void.
//   Not standard ECX thiscall at entry — callers preserve this in EDI.
//
// CALLEES:
//   FUN_0076c4d0          — RDTSC stamp on nested+0x10
//   nested iface vcalls   — [vtbl+0x20](&binder), [vtbl+0x10](0)
//   scalar-deleting dtors — vtbl[0](1) on host+0x258 child and on host
//   Vehicle_SetWheelset   — 0x004fea90 (ECX=host, push 0)
//
// CALLERS:
//   CWndVehicle_CompleteDtor @ 0x00834520 (site 0x0083458d)
//   FUN_00833e30, FUN_0083ac90, FUN_0084b210, FUN_0088d980 (Drive_Loading)
//
// PEERS:
//   Complete: CWndVehicle_CompleteDtor @ 0x00834520 (WQ9J-B)
//   Scalar:   CWndVehicle_ScalarDeletingDtor @ 0x004160d0 (WQ9I-F)
//   Base:     FUN_0078ca80 (CNDUIWndBuffered complete; WQ9K-F)
//
// ODD BEHAVIOR (preserve):
//   Complete dtor already notifies nested@+0x2A8; this helper re-notifies
//   the same nested when non-null (double-notify sealed).
// =============================================================================

#include <cstdint>

extern uint32_t PTR_LAB_00a9f4d8; // stack binder vtbl for nested notify

extern "C" void __fastcall FUN_0076c4d0(void *nested_plus_0x10);
extern "C" void __thiscall Vehicle_SetWheelset(void *vehicle_host, int wheelset);

// Machine signature: EDI = this. Port may rewrite to thiscall if EDI is set.
extern "C" void CWndVehicle_DerivedTeardown_EDI(void /* EDI = CWndVehicle* this */)
{
  // Register this is in EDI at entry (unaff_EDI in decompile).
  // For a portable reconstruction we take it as an explicit parameter
  // only if the compiler is told to use EDI; retail consumes EDI.
  // The following uses a local alias matching machine offsets.
}

// Explicit this-parameter form for ports (callers must pass the same object
// that retail left in EDI). Prefer this form over inventing ECX thiscall
// without adjusting call sites.
extern "C" void CWndVehicle_DerivedTeardown(
    uint32_t *self) // CWndVehicle*
{
  void *nested = reinterpret_cast<void *>(self[0x2A8 / 4]);
  self[0x50C / 4] = 0;

  if (nested != nullptr) {
    *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(nested) + 0x48) = 1;
    uint32_t *sub = reinterpret_cast<uint32_t *>(
        reinterpret_cast<char *>(nested) + 0x10);
    sub[0x0D] = sub[0x0C]; // (nested+0x44) = (nested+0x40)
    FUN_0076c4d0(reinterpret_cast<char *>(nested) + 0x10);

    struct {
      void *vtbl;
      void *obj;
    } binder = { &PTR_LAB_00a9f4d8, nested };
    void *iface = *reinterpret_cast<void **>(
        reinterpret_cast<char *>(nested) + 8);
    void **vtbl = *reinterpret_cast<void ***>(iface);
    reinterpret_cast<void(__thiscall *)(void *, void *)>(vtbl[0x20 / 4])(
        iface, &binder);
    reinterpret_cast<void(__thiscall *)(void *, int)>(vtbl[0x10 / 4])(iface, 0);
  }

  void *host = reinterpret_cast<void *>(self[0x508 / 4]);
  if (host != nullptr) {
    // child = *(host + 0x258)
    void *child = *reinterpret_cast<void **>(
        reinterpret_cast<char *>(host) + 0x258);
    if (child != nullptr) {
      // MSVC scalar-deleting dtor via adjustor / complete-object locator path:
      // LEA ECX, [child + *(child+4).offset + 4]; PUSH 1; CALL [EAX]
      int *child_int = reinterpret_cast<int *>(child);
      int *cd = reinterpret_cast<int *>(child_int[1]);
      int adj = cd[1];
      void **sd_vtbl = *reinterpret_cast<void ***>(
          reinterpret_cast<char *>(child) + adj + 4);
      reinterpret_cast<void(__thiscall *)(void *, int)>(sd_vtbl[0])( 
          reinterpret_cast<char *>(child) + adj + 4, 1);
      Vehicle_SetWheelset(host, 0);
    }

    host = reinterpret_cast<void *>(self[0x508 / 4]);
    if (host != nullptr) {
      int *h = reinterpret_cast<int *>(host);
      int *cd = reinterpret_cast<int *>(h[1]);
      int adj = cd[1];
      void **sd_vtbl = *reinterpret_cast<void ***>(
          reinterpret_cast<char *>(host) + adj + 4);
      reinterpret_cast<void(__thiscall *)(void *, int)>(sd_vtbl[0])(
          reinterpret_cast<char *>(host) + adj + 4, 1);
    }
    self[0x508 / 4] = 0;
  }
}

// Ghidra twin — retail entry uses EDI=this (no formal).
extern "C" void FUN_00833d50(void)
{
  // Porting note: load EDI as this before calling CWndVehicle_DerivedTeardown.
  // CWndVehicle_DerivedTeardown(/* EDI */);
}
