// =============================================================================
// FUN_00979290  /  ClientSpecialEvent_Respawn_TeardownAirlift
// -----------------------------------------------------------------------------
// Stable ID: aa_00979290
// Address:   0x00979290 – 0x009792ff  (112 B; autoassault.exe, image base 0x400000)
// System:    client special-event / respawn (INC airlift)
// Generated: 2026-07-29 W23-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Airlift teardown mid-sequence / dtor helper (EDI = event this).
// See also: ClientSpecialEvent_Respawn_TeardownAirlift.cpp (named twin).
// =============================================================================

#include <cstdint>

extern "C" int FUN_004bb010(int tfid_blob /* + ECX ctx */);
extern "C" void FUN_00560e90(uint32_t phys /*, staged flag */);
extern "C" void Vehicle_ActivateEnterWorld(void /* ECX = obj */);

// Decompiler form: unaff_EDI = ClientSpecialEvent_Respawn* this
extern "C" void FUN_00979290(void)
{
    int iVar1;
    int iVar2;
    int unaff_EDI; // EDI = this (caller-established)

    if (*(char*)(unaff_EDI + 0x38) != '\0') {
        // bytes: mov ecx, [DAT_00b04830]; lea eax,[edi+0x28]; push eax; call FUN_004bb010
        iVar2 = FUN_004bb010(unaff_EDI + 0x28);
        if (iVar2 != 0) {
            (**(code**)(*(int*)(*(int*)(*(int*)(iVar2 + 4) + 4) + 4 + iVar2) + 0x1bc))(0);
            iVar1 = *(int*)(iVar2 + 8);
            *(uint32_t*)(iVar1 + 0x28) = *(uint32_t*)(unaff_EDI + 0x68);
            // staged stack byte 1 before call — CONCAT31 is decompiler noise
            FUN_00560e90(*(uint32_t*)(iVar2 + 8));
            if (*(char*)(unaff_EDI + 4) == '\0') {
                // bytes: mov ecx, esi; call Vehicle_ActivateEnterWorld @ 0x00503f30
                Vehicle_ActivateEnterWorld();
            }
        }
        *(uint8_t*)(unaff_EDI + 0x38) = 0;
    }
    return;
}
