// =============================================================================
// CVOGHB_TargetingLink_complete_dtor_Inferred  (was FUN_00512060)
// -----------------------------------------------------------------------------
// Stable ID: aa_00512060
// Address:   0x00512060 – 0x0051206a  (autoassault.exe, image base 0x400000)
// System:    heartbeat / combat-target (targeting-link HB)
// Generated: 2026-07-29 W20-A OWN dual A/B seal
//            three-rep: raw 2026-07-23 ≡ live decompile ≡ read_memory
// Exactness: Behavior-preserving rewrite of decompiler control flow + byte-sealed ABI.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// Class:     CVOGHB_TargetingLink family (Inferred; vtbl PTR_FUN_009cdfb0)
// =============================================================================
//
// PURPOSE
// MSVC complete object destructor for base targeting-link heartbeat:
//   1) *this = PTR_FUN_009cdfb0  (family vtbl)
//   2) tail-jmp FUN_00508390    (base CVOGHBBase dtor: vtbl→009cdab0 + optional detach)
//
// ABI: __thiscall / __fastcall shape — this in ECX; bare ret via tail.
// Body bytes: c7 01 b0 df 9c 00 e9 25 63 ff ff
//
// CALLERS (not owned):
//   - FUN_00512070 CVOGHB_TargetingLink_scalar_dtor_Inferred (CALL)
//   - thunk_FUN_00512060 @ 0x0051b890 (JMP) — derived scalar path
//
// NOT THIS VA:
//   - Scalar deleting wrapper 0x00512070
//   - Derived PlayerTargetingLink scalar 0x0051b870
//   - Base detach body FUN_00508390 / FUN_005085b0
//

#include <cstdint>

// Family vtbl for targeting-link base (ctor dual installs same).
extern "C" void *PTR_FUN_009cdfb0[];

// Base CVOGHBBase complete path (not owned): set vtbl 009cdab0 + conditional list detach.
extern void __fastcall FUN_00508390(void *thisHb /* ECX */);

void __fastcall CVOGHB_TargetingLink_complete_dtor_Inferred(void *thisHb /* ECX */)
{
  // c7 01 b0 df 9c 00
  *reinterpret_cast<void **>(thisHb) = PTR_FUN_009cdfb0;

  // e9 …  — tail jmp FUN_00508390 (decompiler shows call+return)
  FUN_00508390(thisHb);
}

// Ghidra alias
extern "C" void __fastcall FUN_00512060(void *param_1)
{
  CVOGHB_TargetingLink_complete_dtor_Inferred(param_1);
}
