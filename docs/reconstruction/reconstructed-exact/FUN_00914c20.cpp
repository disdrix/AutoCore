// =============================================================================
// FUN_00914c20  (Ghidra twin of Client_Vehicle_StopHbAndZeroLongitudinal_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00914c20
// Address:   0x00914c20  (autoassault.exe, image base 0x400000)
// System:    input-drive-control
// Named:     Client_Vehicle_StopHbAndZeroLongitudinal_Inferred
// Dual:      MEGA-098 2026-08-05 — accept-with-gaps
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern std::uint8_t  DAT_00d1a860;
extern std::uint8_t* DAT_00d1b6d8;

void __fastcall CVOGHBBase_Stop(void* hb);
void __thiscall VehicleEntity_SetLongitudinalInput(void* vehicle, float longitudinal);

// Retail entry: host in EAX (callers MOV EAX,EDI). Documented formal for ports.
void FUN_00914c20(void* host /* EAX */)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(host);

    if ((DAT_00d1a860 != 0) && (*(int*)(base + 0xc70) != 0)) {
        *(std::uint8_t*)(base + 0xa35) = 0;
        CVOGHBBase_Stop(*(void**)(base + 0xc70));
        if ((DAT_00d1b6d8 != 0) && (*(int*)(DAT_00d1b6d8 + 0x250) != 0)) {
            VehicleEntity_SetLongitudinalInput(*(void**)(DAT_00d1b6d8 + 0x250), 0.0f);
        }
    }
}
