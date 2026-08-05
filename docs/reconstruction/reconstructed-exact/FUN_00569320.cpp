// =============================================================================
// FUN_00569320  (alias scaffold → StdMap_InsertOrFindByIntKey_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00569320
// Address:   0x00569320  (autoassault.exe, image base 0x400000)
// Canonical: StdMap_InsertOrFindByIntKey_Inferred
// System:    container / ordered map
// Generated: 2026-07-29 dual A/B W19-J (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// See StdMap_InsertOrFindByIntKey_Inferred.cpp for named clean source.

#include <cstdint>

void *__thiscall FUN_005690a0(void *map, void *outIt, char addLeft, void *parent, int *pKey);
void FUN_00537770(void);

void __thiscall FUN_00569320(int param_1, uint32_t *param_2, int *param_3)
{
    uint32_t uVar1;
    bool bVar2;
    int *piVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;

    piVar3 = param_3;
    puVar5 = *(uint32_t **)(param_1 + 4);
    bVar2 = true;
    if (*(char *)((int)puVar5[1] + 0x49) == '\0') {
        puVar4 = (uint32_t *)puVar5[1];
        do {
            puVar5 = puVar4;
            bVar2 = *param_3 < (int)puVar5[3];
            if (bVar2) {
                puVar4 = (uint32_t *)*puVar5;
            } else {
                puVar4 = (uint32_t *)puVar5[2];
            }
        } while (*(char *)((int)puVar4 + 0x49) == '\0');
    }
    param_3 = (int *)puVar5;
    if (bVar2) {
        if (puVar5 == (uint32_t *)**(int **)(param_1 + 4)) {
            puVar5 = (uint32_t *)FUN_005690a0(
                (void *)param_1, &param_3, 1, puVar5, piVar3);
            uVar1 = *puVar5;
            *(uint8_t *)(param_2 + 1) = 1;
            *param_2 = uVar1;
            return;
        }
        FUN_00537770();
    }
    if (param_3[3] < *piVar3) {
        puVar5 = (uint32_t *)FUN_005690a0(
            (void *)param_1, &param_3, (char)bVar2, puVar5, piVar3);
        *param_2 = *puVar5;
        *(uint8_t *)(param_2 + 1) = 1;
        return;
    }
    *(uint8_t *)(param_2 + 1) = 0;
    *param_2 = (uint32_t)param_3;
    return;
}
