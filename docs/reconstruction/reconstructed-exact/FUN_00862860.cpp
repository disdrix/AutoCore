// =============================================================================
// FUN_00862860  (scaffold alias → Client_ItemMatchesActiveHardpointMode_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00862860
// Address:   0x00862860  (autoassault.exe, image base 0x400000)
// Body:      0x00862860–0x008629a1 (322 bytes)
// System:    inventory-transfer / hardpoint equip UI
// Dual seal: 2026-07-29 W18-O
// Canonical clean: Client_ItemMatchesActiveHardpointMode_Inferred.cpp
// Exactness: Decompiler-shaped CF preserved.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

extern "C" int FUN_0040da70();

// unaff_ESI = uiHost* (real; call sites set ESI). param_1 = item* in ECX.
bool __fastcall FUN_00862860(int* param_1)
{
    std::uint8_t bVar1;
    short sVar2;
    int iVar3;
    int* unaff_ESI;

    if (param_1 != nullptr) {
        switch (*reinterpret_cast<std::uint32_t*>(param_1[0x2a] + 0x38)) {
        case 6:
            sVar2 = *reinterpret_cast<short*>(
                *reinterpret_cast<int*>(param_1[0x2a] + 0x3c) + 0x3f4);
            if (sVar2 == 10) {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 9;
            }
            if (sVar2 == 0xb) {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 8;
            }
            break;
        case 10:
            iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
            return iVar3 == 1;
        case 0xc:
            (**(void(**)())(*param_1 + 0x1e0))();
            iVar3 = FUN_0040da70();
            if (*reinterpret_cast<char*>(iVar3 + 0x3f4) == '\t') {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 7;
            }
            bVar1 = *reinterpret_cast<std::uint8_t*>(iVar3 + 0x536);
            if ((bVar1 & 2) != 0) {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 4;
            }
            if ((bVar1 & 0x10) != 0) {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 5;
            }
            if ((bVar1 & 4) != 0) {
                iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
                return iVar3 == 6;
            }
            break;
        case 0xe:
            iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
            return iVar3 == 0xd;
        case 0x10:
            iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
            return iVar3 == 2;
        case 0x1c:
            iVar3 = (**(int(**)())(*unaff_ESI + 0x3cc))();
            return iVar3 == 3;
        }
    }
    return false;
}
