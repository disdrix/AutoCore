// =============================================================================
// Client_Vehicle_StopHbAndZeroLongitudinal_Inferred
// -----------------------------------------------------------------------------
// Purpose:  When mode flag DAT_00d1a860 is set and client host has a non-null
//           heartbeat object at +0xc70: clear latch +0xa35, CVOGHBBase_Stop
//           that HB, and if local vehicle exists SetLongitudinalInput(0).
//
// Address:  0x00914c20  (autoassault.exe, image base 0x400000)
// Body:     0x00914c20–0x00914c59 inclusive (58 B / 0x3A); pad CC after RET
// Stable:   aa_00914c20
// System:   input-drive-control
// Ghidra:   FUN_00914c20
//
// ABI:      No stack args. Client/host in EAX at entry (register-carried).
//           Callers: MOV EAX,EDI ; CALL. Bare RET.
//           Stop: thiscall ECX=*(host+0xc70).
//           SetLong: thiscall ECX=vehicle, stack imm 0 (+0.0f bits).
//
// Does NOT: SetHandbrake / SetSteer / PushDriveAxes / vehicle+0x101 gate /
//           HB list Dequeue (Stop only dormant+OnEnd).
//
// Contrast: Client_Vehicle_EngageHbAndPushAxes_Inferred @ 0x00915670
//           (HB=1 + Push; optional Stop when DAT_00d1a860==0).
//
// Callers (2 UNCONDITIONAL_CALL):
//   FUN_00914c60 @ 0x00914ca5
//   Client_InteractWorldClickHub (FUN_00925820) @ 0x00925984
//   (Hub also inlines equivalent early CF; this unit is the shared leaf.)
//
// Callees:
//   CVOGHBBase_Stop                     0x005081d0  aa_005081d0
//   VehicleEntity_SetLongitudinalInput  0x004f5650  aa_004f5650
//
// Exactness: CF ≡ live decompile + disassemble_function + read_memory 2026-08-05.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B MEGA-098: accept-with-gaps.
// =============================================================================

#include <cstdint>

extern std::uint8_t  DAT_00d1a860;
extern std::uint8_t* DAT_00d1b6d8;

void __fastcall CVOGHBBase_Stop(void* /*ECX*/ hb);
void __thiscall VehicleEntity_SetLongitudinalInput(void* /*ECX*/ vehicle, float longitudinal);

// Retail: host pointer arrives in EAX (not ECX). Documented as first formal for
// readability; call convention at sites is register-carried EAX.
void Client_Vehicle_StopHbAndZeroLongitudinal_Inferred(void* host /* EAX */)
{
    auto* const base = reinterpret_cast<std::uint8_t*>(host);

    // cmp byte [DAT_00d1a860], 0 / jz exit
    // mov ecx, [eax+0xc70] / test ecx,ecx / jz exit
    if (DAT_00d1a860 != 0 &&
        *reinterpret_cast<void**>(base + 0xc70) != nullptr)
    {
        // mov byte ptr [eax+0xa35], 0
        base[0xa35] = 0;

        // mov ecx, [eax+0xc70] ; call CVOGHBBase_Stop
        CVOGHBBase_Stop(*reinterpret_cast<void**>(base + 0xc70));

        // mov eax, [DAT_00d1b6d8] / test / jz exit
        // mov ecx, [eax+0x250] / test / jz exit
        // push 0 ; call VehicleEntity_SetLongitudinalInput
        if (DAT_00d1b6d8 != nullptr)
        {
            void* vehicle = *reinterpret_cast<void**>(DAT_00d1b6d8 + 0x250);
            if (vehicle != nullptr)
            {
                VehicleEntity_SetLongitudinalInput(vehicle, 0.0f);
            }
        }
    }
    // ret
}
