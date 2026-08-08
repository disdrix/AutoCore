// =============================================================================
// CWndVehicle_CompleteDtor  (aa_00834520)
// -----------------------------------------------------------------------------
// Address:   0x00834520  (autoassault.exe, image base 0x400000)
// Body:      0x00834520–0x008345b1 inclusive (146 B / 0x92)
// Wave:      WQ9J-B OWN-ONLY dual 2026-08-05
// System:    CWndVehicle / MSVC complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + full-body read_memory. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for CWndVehicle (RTTI .?AVCWndVehicle@@).
//   Installs primary vtbl PTR_FUN_00a6fbcc, notifies nested object at +0x2A8,
//   runs derived teardown helper FUN_00833d50 (EDI=this), then base
//   CNDUIWndBuffered complete FUN_0078ca80. Does NOT free this.
//
// ABI:
//   ECX = this. SEH LAB_009b4563. Bare RET (C3). void.
//
// CALLEES:
//   FUN_0076c4d0     — RDTSC stamp on nested+0x10
//   FUN_00833d50     — EDI=this vehicle UI teardown (+0x50C / nested / +0x508)
//   FUN_0078ca80     — CNDUIWndBuffered complete (→ FUN_007b5be0)
//
// PEERS:
//   Scalar: CWndVehicle_ScalarDeletingDtor @ 0x004160d0 (vtbl[0]; WQ9I-F)
//   Ctor:   FUN_008345c0 (installs same vtbl after CNDUIWndBuffered_Ctor)
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_00a6fbcc;   // CWndVehicle primary vtbl
extern uint32_t PTR_LAB_00a9f4d8;   // stack binder vtbl for nested notify

extern "C" void __fastcall FUN_0076c4d0(void* nested_plus_0x10);
extern "C" void FUN_00833d50(void); // machine: EDI = CWndVehicle* this
extern "C" void __fastcall FUN_0078ca80(void* self);

// Complete dtor only — does not free self.
extern "C" void __fastcall CWndVehicle_CompleteDtor(uint32_t* self)
{
  // SEH: PUSH -1; PUSH LAB_009b4563; FS:[0] link; SUB ESP,0xC; PUSH ESI/EDI
  // (frame omitted as structural; EH state local_4 tracked below in spirit)

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a6fbcc); // *this = vtbl

  void* nested = reinterpret_cast<void*>(self[0xAA]); // +0x2A8
  if (nested != nullptr) {
    *reinterpret_cast<uint8_t*>(reinterpret_cast<char*>(nested) + 0x48) = 1;
    // LEA ECX,[nested+0x10]; copy dword (nested+0x40) → (nested+0x44)
    uint32_t* sub = reinterpret_cast<uint32_t*>(
        reinterpret_cast<char*>(nested) + 0x10);
    sub[0x0D] = sub[0x0C]; // +0x34 = +0x30 relative to nested+0x10
    FUN_0076c4d0(reinterpret_cast<char*>(nested) + 0x10);

    // Stack binder { &PTR_LAB_00a9f4d8, nested }; iface = *(nested+8)
    struct {
      void* vtbl;
      void* obj;
    } binder = { &PTR_LAB_00a9f4d8, nested };
    void* iface = *reinterpret_cast<void**>(
        reinterpret_cast<char*>(nested) + 8);
    void** vtbl = *reinterpret_cast<void***>(iface);
    // thiscall ECX=iface: CALL [vtbl+0x20](&binder); CALL [vtbl+0x10](0)
    reinterpret_cast<void(__thiscall*)(void*, void*)>(vtbl[0x20 / 4])(
        iface, &binder);
    reinterpret_cast<void(__thiscall*)(void*, int)>(vtbl[0x10 / 4])(iface, 0);
  }

  // EDI still = self from entry; helper consumes EDI not ECX.
  FUN_00833d50();

  FUN_0078ca80(self); // base CNDUIWndBuffered complete
}

// Ghidra twin name
extern "C" void __fastcall FUN_00834520(uint32_t* self)
{
  CWndVehicle_CompleteDtor(self);
}
