// =============================================================================
// CNDUIWndBuffered_CompleteDtor  (aa_0078ca80)
// -----------------------------------------------------------------------------
// Address:   0x0078ca80  (autoassault.exe, image base 0x400000)
// Body:      0x0078ca80–0x0078caef inclusive (112 B / 0x70)
// Wave:      WQ9K-F OWN-ONLY dual 2026-08-05
// System:    CNDUIWndBuffered / MSVC complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + full-body read_memory + RTTI COL. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for CNDUIWndBuffered
//   (RTTI .?AVCNDUIWndBuffered@@). Installs primary vtbl PTR_FUN_00a99f74,
//   runs shared teardown helpers, scalar-deletes nested HostBase at +0x2A8,
//   then base CNDUIWindow complete FUN_007b5be0. Does NOT free this.
//
// ABI:
//   ECX = this. SEH LAB_009b3fee. Bare RET (C3). void.
//
// CALLEES:
//   FUN_007a8580     — shared UI teardown helper
//   FUN_0078c3d0     — buffered-window helper (thiscall)
//   nested vtbl[0](1)— scalar-deleting dtor of HostBase @ +0x2A8
//   FUN_007b5be0     — CNDUIWindow complete
//
// PEERS:
//   Scalar: FUN_004293f0 (vtbl[0] of PTR_FUN_00a99f74)
//   Ctor:   CNDUIWndBuffered_Ctor_Inferred @ 0x0078caf0 (W34-T)
//   Derived caller: CWndVehicle_CompleteDtor @ 0x00834520 (WQ9J-B)
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_00a99f74; // CNDUIWndBuffered primary vtbl

extern "C" void __fastcall FUN_007a8580(void* self);
extern "C" void __fastcall FUN_0078c3d0(void* self);
extern "C" void __fastcall FUN_007b5be0(void* self);

// Complete dtor only — does not free self.
extern "C" void __fastcall CNDUIWndBuffered_CompleteDtor(uint32_t* self)
{
  // SEH: PUSH -1; PUSH LAB_009b3fee; FS:[0] link; PUSH ECX; PUSH ESI
  // ESI = this (entry MOV ESI,ECX)

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a99f74); // *this = vtbl
  // EH state = 0

  FUN_007a8580(self);
  FUN_0078c3d0(self);

  void* nested = reinterpret_cast<void*>(self[0xAA]); // +0x2A8
  if (nested != nullptr) {
    // Scalar-deleting dtor: CALL [*(nested)](1) with ECX=nested
    void** vtbl = *reinterpret_cast<void***>(nested);
    reinterpret_cast<void(__thiscall*)(void*, int)>(vtbl[0])(nested, 1);
  }
  self[0xAA] = 0; // always null

  // EH state = -1
  FUN_007b5be0(self); // base CNDUIWindow complete
}

// Ghidra twin name
extern "C" void __fastcall FUN_0078ca80(uint32_t* self)
{
  CNDUIWndBuffered_CompleteDtor(self);
}
