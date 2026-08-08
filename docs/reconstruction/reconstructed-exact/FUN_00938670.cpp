// =============================================================================
// FUN_00938670  (machine twin of Client_Interact_OpenCVOGStore_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00938670
// Address:   0x00938670  (autoassault.exe, image base 0x400000)
// System:    interaction-activation
// Generated: 2026-08-05 MEGA-027 — keep Ghidra symbol twin in sync with named clean
// Exactness: Behavior-preserving rewrite of decompiler control flow + ABI seal.
// Canonical: Client_Interact_OpenCVOGStore_Inferred.cpp
// =============================================================================

// PURPOSE: See Client_Interact_OpenCVOGStore_Inferred.cpp
// ABI: ESI=client live-in; stack TFID 4×u32; RET 0x10; body 0x16D bytes.

#include <cstdint>

struct TypeDescriptor;

extern "C" {
void __thiscall VehicleEntity_SetFlag_109(void* entity, uint8_t value);
void __thiscall VehicleEntity_SetHandbrake(void* entity, int value);
void __thiscall VehicleEntity_SetLongitudinalInput(void* entity, int value);
void* Object_ResolveFromTFID(void* objMgr, uint32_t* tfid);
void* __cdecl __RTDynamicCast(void* obj, uint32_t vfDelta,
    TypeDescriptor* src, TypeDescriptor* dst, uint32_t isRef);
void __thiscall FUN_007fef20(void* client, int dialogIndex, int openFlag, int extra);
}

extern TypeDescriptor CVOGClonedObjectBase_RTTI; // 0x00af8e10
extern TypeDescriptor CVOGStore_RTTI;            // 0x00afe0c8

// Retail calling convention: ESI this + stdcall 0x10. Port as explicit client*.
void FUN_00938670(void* client /*ESI*/,
    uint32_t param_1, uint32_t param_2, uint32_t param_3, uint32_t param_4)
{
    char cVar1;
    void* pvVar2;
    int iVar3;
    uint32_t* puVar4;
    uint32_t uVar5;
    uint32_t auStack_18[6];

    if (*reinterpret_cast<int*>(
            *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(client) + 0xe98) + 0x250) != 0) {
        void* entity = *reinterpret_cast<void**>(
            *reinterpret_cast<uint8_t**>(reinterpret_cast<uint8_t*>(client) + 0xe98) + 0x250);
        VehicleEntity_SetFlag_109(entity, 1);
        VehicleEntity_SetHandbrake(entity, 1);
        VehicleEntity_SetLongitudinalInput(entity, 0);
    }

    void* world = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(client) + 0xe04);
    void* objMgr = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(world) + 0xe4e8);
    uint32_t tfid[4] = { param_1, param_2, param_3, param_4 };
    pvVar2 = Object_ResolveFromTFID(objMgr, tfid);
    iVar3 = reinterpret_cast<int>(__RTDynamicCast(pvVar2, 0,
        &CVOGClonedObjectBase_RTTI, &CVOGStore_RTTI, 0));
    if (iVar3 == 0) {
        return;
    }

    if (*reinterpret_cast<char*>(iVar3 + 0x4e5) == '\0') {
        void* host = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(client) + 0x105c);
        auto** vtbl = *reinterpret_cast<void***>(host);
        using Fn = char(__thiscall*)(void*);
        cVar1 = reinterpret_cast<Fn>(vtbl[0x3d8 / 4])(host);
        if ((cVar1 != '\0') &&
            (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0x588) == iVar3)) {
            return;
        }
        if (*reinterpret_cast<char*>(iVar3 + 0x4e5) == '\0') {
            goto LAB_00938742;
        }
    }

    {
        void* host = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(client) + 0x1060);
        auto** vtbl = *reinterpret_cast<void***>(host);
        using Fn = char(__thiscall*)(void*);
        cVar1 = reinterpret_cast<Fn>(vtbl[0x3d8 / 4])(host);
        if ((cVar1 != '\0') &&
            (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(host) + 0x5a0) == iVar3)) {
            return;
        }
    }

LAB_00938742:
    auStack_18[0] = 0x2024;
    auStack_18[2] = param_1;
    auStack_18[3] = param_2;
    auStack_18[4] = param_3;
    auStack_18[5] = param_4;
    if (*reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(client) + 0xc78) != 0) {
        void* comm = *reinterpret_cast<void**>(reinterpret_cast<uint8_t*>(client) + 0xc78);
        auto** vtbl = *reinterpret_cast<void***>(comm);
        using SendFn = void(__thiscall*)(void*, int, void*, int, int);
        reinterpret_cast<SendFn>(vtbl[0x18 / 4])(comm, -1, auStack_18, 0x18, 0);
    }

    if (*reinterpret_cast<char*>(iVar3 + 0x4e5) == '\0') {
        puVar4 = reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(client) + 0x105c) + 0x528);
        uVar5 = 0xb;
    } else {
        puVar4 = reinterpret_cast<uint32_t*>(
            *reinterpret_cast<int*>(reinterpret_cast<uint8_t*>(client) + 0x1060) + 0x548);
        uVar5 = 0xc;
    }
    puVar4[0] = param_1;
    puVar4[1] = param_2;
    puVar4[2] = param_3;
    puVar4[3] = param_4;
    FUN_007fef20(client, static_cast<int>(uVar5), 1, 0);
}
