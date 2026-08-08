// =============================================================================
// Object_SetCrewHostBackLink_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00520330
// Address:   0x00520330 – 0x0052033d exclusive (autoassault.exe, base 0x400000)
// Size:      13 B; epilogue ret 4 (C2 04 00); pad CC
// System:    skills-abilities / vehicle crew back-link leaf
// Generated: 2026-08-04 WQ9E-D dual (live decompile ≡ raw 2026-07-23 + read_memory)
// Exactness: Behavior-preserving; not modernization. Bit-exact vs EXE: OPEN.
// Prior:     FUN_00520330 / Named_CalleeOf_Named_VOG_DEBUG_STOP_00520330
// =============================================================================
//
// PURPOSE: Leaf store of the vehicle-crew host pointer (or null) at object
// field +0xCB0. Used by VehicleCrew Insert/Clear and related roster writers so
// members can recover their crew host (e.g. convoy UI: *(local+0xCB0)).
//
// Bytes:  8B 44 24 04 | 89 81 B0 0C 00 00 | C2 04 00
// ABI:    __thiscall; ECX = object*; stack arg0 = host* or null; RET 4; void.
// =============================================================================

#include <cstdint>

// __thiscall
extern "C" void __thiscall Object_SetCrewHostBackLink_Inferred(
    void* self,
    void* crew_host_or_null)
{
  *reinterpret_cast<void**>(static_cast<std::uint8_t*>(self) + 0xcb0) =
      crew_host_or_null;
}
