// =============================================================================
// CWndWaypointIcon_CompleteDtor  (aa_00832fa0)
// -----------------------------------------------------------------------------
// Address:   0x00832fa0  (autoassault.exe, image base 0x400000)
// Body:      0x00832fa0–0x0083300f inclusive (112 B / 0x70)
// Wave:      WQ9J-B OWN-ONLY dual 2026-08-05
// System:    CWndWaypointIcon / MSVC complete destructor
// Exactness: Behavior-preserving rewrite from decompile + disassemble_function
//            + full-body read_memory. Ignore Ghidra false-noreturn on
//            operator_delete (bytes fall through after ADD ESP,4).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC complete-object destructor for CWndWaypointIcon
//   (RTTI .?AVCWndWaypointIcon@@). Installs primary vtbl PTR_FUN_00a7000c,
//   frees owned heap block at +0x488 (after FUN_0096efd0 release helper),
//   nulls the field, then base UI-window complete FUN_007b5be0.
//   Does NOT free this.
//
// ABI:
//   ECX = this. SEH LAB_009b33be. Bare RET (C3). void.
//
// CALLEES:
//   FUN_0096efd0     — thiscall release on owned block
//   operator_delete  — cdecl free of owned block
//   FUN_007b5be0     — base window complete (PTR_FUN_00a960ac)
//
// PEERS:
//   Scalar: FUN_00416350 / Class_00a7000c_ScalarDeletingDtor_Inferred (WQ9I-H)
//           product rename residual → CWndWaypointIcon_ScalarDeletingDtor
//   Vtbl[0] @ 0x00a7000c = 0x00416350
// =============================================================================

#include <cstdint>

extern uint32_t PTR_FUN_00a7000c; // CWndWaypointIcon primary vtbl

extern "C" void __fastcall FUN_0096efd0(void* owned);
extern "C" void __cdecl operator_delete(void* p);
extern "C" void __fastcall FUN_007b5be0(void* self);

// Complete dtor only — does not free self.
extern "C" void __fastcall CWndWaypointIcon_CompleteDtor(uint32_t* self)
{
  // SEH: PUSH -1; PUSH LAB_009b33be; FS:[0] link; PUSH ECX; PUSH ESI/EDI
  // (frame omitted as structural)

  self[0] = reinterpret_cast<uint32_t>(&PTR_FUN_00a7000c); // *this = vtbl

  void* owned = reinterpret_cast<void*>(self[0x122]); // +0x488
  if (owned != nullptr) {
    FUN_0096efd0(owned);
    operator_delete(owned); // ADD ESP,4 — continues (not noreturn)
  }
  self[0x122] = 0; // always null +0x488

  FUN_007b5be0(self); // base CNDUIWnd-family complete
}

// Ghidra twin name
extern "C" void __fastcall FUN_00832fa0(uint32_t* self)
{
  CWndWaypointIcon_CompleteDtor(self);
}
