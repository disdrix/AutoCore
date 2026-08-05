// =============================================================================
// FUN_0093d880 — Ghidra-name twin of Client_ApplyVehicleSwitch_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0093d880
// Address:   0x0093d880–0x0093da25 (422 B)
// Prefer:    Client_ApplyVehicleSwitch_Inferred.cpp for named stage commentary
// Dual A/B:  SEALED accept-with-gaps W26-S 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Nested (not owned here)
std::uint32_t __thiscall FUN_005252f0(void *character, void *newVehicle, void **outOld,
                                      std::uint32_t argA, std::uint32_t argB);
void FUN_007fca10(void);
void FUN_009147a0(void);
void FUN_008801b0(int *p);
void FUN_0085e970(void);
void __thiscall FUN_007fef20(void *client, int dialogIndex, char a, char b);
void Vehicle_EnsureRegenerationHeartbeat(void *vehicle);
void Vehicle_RecalcCombatPools(void *vehicle);
void Client_RefreshOpenMissionUiWindows(void *client);

/// Entry: client in EAX; stack arg = newVehicle*; RET 4; returns 1.
std::uint32_t FUN_0093d880(std::uint32_t param_1 /* newVehicle* */)
{
    int iVar1;
    int *piVar2;
    char cVar3;
    int in_EAX; // client*
    int *piVar4;
    void *outOld_local;

    piVar4 = nullptr;
    iVar1 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250);
    // vehicle vbase vfunc +0x1c8
    (**(void (**)())(
        *reinterpret_cast<int *>(
            *reinterpret_cast<int *>(
                *reinterpret_cast<int *>(iVar1 + 4) + 4) + 4 + iVar1) + 0x1c8))();

    iVar1 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250);
    if (iVar1 != 0) {
        piVar4 = reinterpret_cast<int *>(iVar1 + 0x40);
    }
    piVar2 = *reinterpret_cast<int **>(in_EAX + 0x1078);
    *reinterpret_cast<std::uint8_t *>(in_EAX + 0x30b4) = 1;
    *reinterpret_cast<std::uint8_t *>(in_EAX + 0x30b5) = 0;
    if (*reinterpret_cast<int **>(in_EAX + 0x309c) != nullptr) {
        (**(void (**)(int))(**reinterpret_cast<int **>(in_EAX + 0x309c) + 4))(0);
    }
    (**(void (**)(int))(*piVar4 + 0x1c))(0);
    if (piVar2 != nullptr) {
        cVar3 = (**(char (**)())(*piVar2 + 0xd0))();
        if (cVar3 != '\0') {
            FUN_007fca10();
        }
    }
    iVar1 = *reinterpret_cast<int *>(in_EAX + 0xf38);
    if (*reinterpret_cast<int **>(iVar1 + 0xc70) != nullptr) {
        (**(void (**)(int, int))(**reinterpret_cast<int **>(iVar1 + 0xc70) + 0x18))(1, 1);
    }
    if (*reinterpret_cast<int **>(iVar1 + 0xc74) != nullptr) {
        (**(void (**)(int, int))(**reinterpret_cast<int **>(iVar1 + 0xc74) + 0x18))(1, 1);
    }
    *reinterpret_cast<std::uint32_t *>(iVar1 + 0xc70) = 0;
    *reinterpret_cast<std::uint32_t *>(iVar1 + 0xc74) = 0;

    FUN_005252f0(
        *reinterpret_cast<void **>(in_EAX + 0xe98),
        reinterpret_cast<void *>(param_1),
        &outOld_local,
        0xFFFFFFFFu,
        0xFFFFFFFFu);

    FUN_009147a0();
    piVar2[0x145] = *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250);
    FUN_008801b0(piVar2);

    iVar1 = *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0x1040) + 0x50c);
    if ((iVar1 != 0) && (*reinterpret_cast<int *>(iVar1 + 0x580) != 0)) {
        FUN_0085e970();
    }
    FUN_007fef20(reinterpret_cast<void *>(in_EAX), 0x12, 1, 0);

    *reinterpret_cast<std::uint8_t *>(
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250) + 0x105) =
        *reinterpret_cast<std::uint8_t *>(in_EAX + 0x9c4);
    *reinterpret_cast<std::uint8_t *>(
        *reinterpret_cast<int *>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250) + 0x106) =
        *reinterpret_cast<std::uint8_t *>(in_EAX + 0x9c4);

    Vehicle_EnsureRegenerationHeartbeat(
        *reinterpret_cast<void **>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250));
    Vehicle_RecalcCombatPools(
        *reinterpret_cast<void **>(*reinterpret_cast<int *>(in_EAX + 0xe98) + 0x250));
    Client_RefreshOpenMissionUiWindows(reinterpret_cast<void *>(in_EAX));
    return 1;
}
