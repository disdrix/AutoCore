// =============================================================================
// ClientSpecialEvent_Respawn_TeardownAirlift  /  FUN_00979290
// -----------------------------------------------------------------------------
// Stable ID: aa_00979290
// Address:   0x00979290 – 0x009792ff  (112 B; autoassault.exe, image base 0x400000)
// System:    client special-event / respawn (INC airlift)
// Generated: 2026-07-29 W23-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Teardown airlift side of ClientSpecialEvent_Respawn — resolve TFID,
//          virtual detach (vtbl+0x1bc), restore mode dword, phys refresh, optional
//          Vehicle_ActivateEnterWorld, clear +0x38 latch.
// See also: FUN_00979290.cpp (scaffold twin).
// =============================================================================

#include <cstdint>

extern "C" void* __thiscall FUN_004bb010(void* ctx, void* tfid_blob); // Object_ResolveTfIdVtbl1d4
extern "C" void FUN_00560e90(void* phys);
extern "C" void __thiscall Vehicle_ActivateEnterWorld(void* obj);

// EDI = ClientSpecialEvent_Respawn* this  (unaff_EDI in decomp)
extern "C" void ClientSpecialEvent_Respawn_TeardownAirlift(void /*EDI this*/)
{
    // Register: EDI = this (not a stack formal)
    int this_ = 0; // placeholder — caller leaves EDI = event*
    // In assembly this is EDI throughout; reconstructed with explicit param for clarity:
    // void Teardown(ClientSpecialEvent_Respawn* self) with self in EDI.

    // --- faithful register form (comments map to live bytes) ---
    // if (*(char*)(EDI+0x38) == 0) return;
    // ECX = *(DAT_00b04830);
    // push EDI+0x28; call FUN_004bb010 → ESI
    // if ESI == 0: goto clear_latch
    // MI vtbl+0x1bc(0)
    // ECX = *(ESI+8); *(ECX+0x28) = *(EDI+0x68); FUN_00560e90(...)
    // if (*(char*)(EDI+4) == 0) { ECX=ESI; Vehicle_ActivateEnterWorld(); }
    // *(char*)(EDI+0x38) = 0;
    (void)this_;
}

// Explicit-this form for ports (matches sealed CF; ABI is EDI-this):
extern "C" void ClientSpecialEvent_Respawn_TeardownAirlift_Explicit(uint8_t* self)
{
    if (*(char*)(self + 0x38) == 0)
        return;

    void* ctx = *reinterpret_cast<void**>(0x00b04830); // DAT_00b04830
    void* obj = FUN_004bb010(ctx, self + 0x28);
    if (obj != nullptr) {
        // MI: vtbl = *(*(obj+4)+4) + (obj+4); call [vtbl+0x1bc](0)
        int* mid = *reinterpret_cast<int**>(reinterpret_cast<char*>(obj) + 4);
        int* adj = reinterpret_cast<int*>(reinterpret_cast<char*>(obj) + mid[1] + 4);
        auto** vtbl = reinterpret_cast<void***>(*adj);
        using VFn = void(__thiscall*)(void*, int);
        reinterpret_cast<VFn>(vtbl[0x1bc / 4])(adj, 0);

        void* phys = *reinterpret_cast<void**>(reinterpret_cast<char*>(obj) + 8);
        *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(phys) + 0x28) =
            *reinterpret_cast<uint32_t*>(self + 0x68);
        FUN_00560e90(phys);

        if (*(char*)(self + 4) == 0)
            Vehicle_ActivateEnterWorld(obj);
    }
    *(char*)(self + 0x38) = 0;
}
