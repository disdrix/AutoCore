// =============================================================================
// Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00569560
// -----------------------------------------------------------------------------
// Stable ID: aa_00569560
// NOTE: Prefer StdMap_InsertWithHint_IntKey_Inferred — this alias is a legacy
//       multi-hop xref-seed name (not product identity).
// Address:   0x00569560  (autoassault.exe, image base 0x400000)
// System:    container / MSVC ordered map hinted insert
// Generated: 2026-07-29 W21-G dual seal (refresh of 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Canonical: StdMap_InsertWithHint_IntKey_Inferred.cpp
// =============================================================================

#include <cstdint>

void *__thiscall FUN_005690a0(void *map, void *outIt, char addLeft, void *parent, int *pKey);
void FUN_00537770(void);
void FUN_00568200(void);
void *__thiscall FUN_00569320(int map, uint8_t *outPair, int *pKey);

static inline int SBORROW4(int a, int b)
{
    int r = a - b;
    return (((a ^ b) & (a ^ r)) >> 31) & 1;
}

uint32_t *__thiscall Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_CVO_00569560(
    int param_1,
    uint32_t *param_2,
    int *param_3,
    int *param_4)
{
    int *piVar1;
    int iVar2;
    int iVar3;
    int iVar4;
    uint32_t *puVar5;
    uint8_t local_8[8];

    if (*(int *)(param_1 + 8) == 0) {
        FUN_005690a0((void *)(intptr_t)param_1, param_2, 1, *(void **)(param_1 + 4), param_4);
        return param_2;
    }
    piVar1 = *(int **)(param_1 + 4);
    if (param_3 == (int *)*piVar1) {
        if (*param_4 < param_3[3]) {
            FUN_005690a0((void *)(intptr_t)param_1, param_2, 1, param_3, param_4);
            return param_2;
        }
    } else if (param_3 == piVar1) {
        if (*(int *)(piVar1[2] + 0xc) < *param_4) {
            FUN_005690a0((void *)(intptr_t)param_1, param_2, 0, (void *)(intptr_t)piVar1[2], param_4);
            return param_2;
        }
    } else {
        iVar2 = *param_4;
        iVar3 = param_3[3];
        iVar4 = iVar3 - iVar2;
        if (iVar2 < iVar3) {
            FUN_00537770();
            if (param_3[3] < iVar2) {
                if (*(char *)(param_3[2] + 0x49) != '\0') {
                    FUN_005690a0((void *)(intptr_t)param_1, param_2, 0, param_3, param_4);
                    return param_2;
                }
                FUN_005690a0((void *)(intptr_t)param_1, param_2, 1, param_3, param_4);
                return param_2;
            }
            iVar3 = param_3[3];
            iVar4 = iVar3 - iVar2;
        }
        if (SBORROW4(iVar3, iVar2) != (iVar4 < 0)) {
            FUN_00568200();
            if ((param_3 == *(int **)(param_1 + 4)) || (iVar2 < param_3[3])) {
                if (*(char *)(param_3[2] + 0x49) != '\0') {
                    FUN_005690a0((void *)(intptr_t)param_1, param_2, 0, param_3, param_4);
                    return param_2;
                }
                FUN_005690a0((void *)(intptr_t)param_1, param_2, 1, param_3, param_4);
                return param_2;
            }
        }
    }
    puVar5 = (uint32_t *)FUN_00569320(param_1, local_8, param_4);
    *param_2 = *puVar5;
    return param_2;
}
