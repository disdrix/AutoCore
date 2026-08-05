// =============================================================================
// FUN_004baa30  /  StdMap_EraseIterator_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004baa30
// Address:   0x004baa30 – 0x004bace5  (autoassault.exe, image base 0x400000)
// System:    CRT / MSVC STL _Tree erase
// Generated: 2026-07-29 W23-I dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: MSVC map/set single-iterator erase (nil throw + rebalance + delete).
// See also: StdMap_EraseIterator_Inferred.cpp (named twin).
// =============================================================================

#include <cstdint>

extern "C" void FUN_00673070();
extern "C" int FUN_004e12a0(int n);
extern "C" int FUN_00421b70(int n);
extern "C" void FUN_004e22d0(int n);
extern "C" void FUN_006753b0(int n);
extern "C" void operator_delete(void* p);

// Decompiler form (param_2 often out-it shadow; param_3 = node*).
// ABI: __thiscall; ret 8. Epilogue size-- missed by noreturn analysis.
extern "C" void __thiscall FUN_004baa30(int param_1, uint32_t param_2, int* param_3)
{
    (void)param_2;
    // SEH elided

    if (*(char*)((int)param_3 + 0x15) != '\0') {
        // throw "invalid map/set<T> iterator" — noreturn
        return;
    }

    FUN_00673070();

    int* piVar6 = (int*)*param_3;
    if (*(char*)((int)piVar6 + 0x15) == '\0') {
        if (*(char*)(param_3[2] + 0x15) == '\0') {
            piVar6 = (int*)param_3[2];
        }
    } else {
        piVar6 = (int*)param_3[2];
    }
    int* piVar5 = (int*)param_3[1];
    if (*(char*)((int)piVar6 + 0x15) == '\0') {
        piVar6[1] = (int)piVar5;
    }

    if (*(int**)(*(int*)(param_1 + 4) + 4) == param_3) {
        *(int**)(*(int*)(param_1 + 4) + 4) = piVar6;
    } else if ((int*)*piVar5 == param_3) {
        *piVar5 = (int)piVar6;
    } else {
        piVar5[2] = (int)piVar6;
    }

    uint32_t* puVar1 = *(uint32_t**)(param_1 + 4);
    if ((int*)*puVar1 == param_3) {
        int* piVar3 = piVar5;
        if (*(char*)((int)piVar6 + 0x15) == '\0') {
            piVar3 = (int*)FUN_004e12a0((int)piVar6);
        }
        *puVar1 = (uint32_t)piVar3;
    }

    int iVar2 = *(int*)(param_1 + 4);
    if (*(int**)(iVar2 + 8) == param_3) {
        if (*(char*)((int)piVar6 + 0x15) == '\0') {
            uint32_t uVar4 = FUN_00421b70((int)piVar6);
            *(uint32_t*)(iVar2 + 8) = uVar4;
        } else {
            *(int**)(iVar2 + 8) = piVar5;
        }
    }

    if ((char)param_3[5] == '\x01') {
        if (piVar6 != *(int**)(*(int*)(param_1 + 4) + 4)) {
            do {
                int* piVar3 = piVar5;
                if ((char)piVar6[5] != '\x01')
                    break;
                piVar5 = (int*)*piVar3;
                if (piVar6 == piVar5) {
                    piVar5 = (int*)piVar3[2];
                    if ((char)piVar5[5] == '\0') {
                        *(uint8_t*)(piVar5 + 5) = 1;
                        *(uint8_t*)(piVar3 + 5) = 0;
                        FUN_004e22d0((int)piVar3);
                        piVar5 = (int*)piVar3[2];
                    }
                    if (*(char*)((int)piVar5 + 0x15) == '\0') {
                        if ((*(char*)(*piVar5 + 0x14) != '\x01') ||
                            (*(char*)(piVar5[2] + 0x14) != '\x01')) {
                            if (*(char*)(piVar5[2] + 0x14) == '\x01') {
                                *(uint8_t*)(*piVar5 + 0x14) = 1;
                                *(uint8_t*)(piVar5 + 5) = 0;
                                FUN_006753b0((int)piVar5);
                                piVar5 = (int*)piVar3[2];
                            }
                            *(char*)(piVar5 + 5) = (char)piVar3[5];
                            *(uint8_t*)(piVar3 + 5) = 1;
                            *(uint8_t*)(piVar5[2] + 0x14) = 1;
                            FUN_004e22d0((int)piVar3);
                            break;
                        }
                        *(uint8_t*)(piVar5 + 5) = 0;
                    }
                } else {
                    if ((char)piVar5[5] == '\0') {
                        *(uint8_t*)(piVar5 + 5) = 1;
                        *(uint8_t*)(piVar3 + 5) = 0;
                        FUN_006753b0((int)piVar3);
                        piVar5 = (int*)*piVar3;
                    }
                    if (*(char*)((int)piVar5 + 0x15) == '\0') {
                        if ((*(char*)(piVar5[2] + 0x14) == '\x01') &&
                            (*(char*)(*piVar5 + 0x14) == '\x01')) {
                            *(uint8_t*)(piVar5 + 5) = 0;
                        } else {
                            if (*(char*)(*piVar5 + 0x14) == '\x01') {
                                *(uint8_t*)(piVar5[2] + 0x14) = 1;
                                *(uint8_t*)(piVar5 + 5) = 0;
                                FUN_004e22d0((int)piVar5);
                                piVar5 = (int*)*piVar3;
                            }
                            *(char*)(piVar5 + 5) = (char)piVar3[5];
                            *(uint8_t*)(piVar3 + 5) = 1;
                            *(uint8_t*)(*piVar5 + 0x14) = 1;
                            FUN_006753b0((int)piVar3);
                            break;
                        }
                    }
                }
                piVar5 = (int*)piVar3[1];
                piVar6 = piVar3;
            } while (piVar3 != *(int**)(*(int*)(param_1 + 4) + 4));
        }
        *(uint8_t*)(piVar6 + 5) = 1;
    }

    operator_delete(param_3);

    // Sealed epilogue (Ghidra truncated):
    if (*(int*)(param_1 + 8) > 0)
        *(int*)(param_1 + 8) -= 1;
    // *out_it write + ret 8 — see annotated / raw seal
}
