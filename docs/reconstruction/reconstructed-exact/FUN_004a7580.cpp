// =============================================================================
// FUN_004a7580  (clean twin → StdMap_InsertOrFindByIntKey_Isnil15_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004a7580
// Address:   0x004a7580  (autoassault.exe, image base 0x400000)
// Named plate: reconstructed-exact/StdMap_InsertOrFindByIntKey_Isnil15_Inferred.cpp
// Dual A/B: 2026-07-29 W23-F — accept
// =============================================================================

// Thin include-style twin: full CF lives in the named plate.
// Ghidra symbol retained for ledger / xref search.

#include <cstdint>

void *__thiscall FUN_004a6d80(void *map, void *outIt, char addLeft, void *parent, int *pKey);
void __fastcall FUN_005a2850(void **pNode);

void __thiscall FUN_004a7580(int param_1, uint32_t *param_2, int *param_3)
{
    uint32_t uVar1;
    bool bVar2;
    int *piVar3;
    uint32_t *puVar4;
    uint32_t *puVar5;

    piVar3 = param_3;
    puVar5 = *(uint32_t **)(param_1 + 4);
    bVar2 = true;
    if (*(char *)((int)puVar5[1] + 0x15) == '\0') {
        puVar4 = (uint32_t *)puVar5[1];
        do {
            puVar5 = puVar4;
            bVar2 = *param_3 < (int)puVar5[3];
            if (bVar2) {
                puVar4 = (uint32_t *)*puVar5;
            } else {
                puVar4 = (uint32_t *)puVar5[2];
            }
        } while (*(char *)((int)puVar4 + 0x15) == '\0');
    }
    param_3 = (int *)puVar5;
    if (bVar2) {
        if (puVar5 == (uint32_t *)**(int **)(param_1 + 4)) {
            puVar5 = (uint32_t *)FUN_004a6d80(
                (void *)param_1, &param_3, 1, puVar5, piVar3);
            uVar1 = *puVar5;
            *(uint8_t *)(param_2 + 1) = 1;
            *param_2 = uVar1;
            return;
        }
        FUN_005a2850((void **)&param_3);
    }
    if (param_3[3] < *piVar3) {
        puVar5 = (uint32_t *)FUN_004a6d80(
            (void *)param_1, &param_3, (char)bVar2, puVar5, piVar3);
        *param_2 = *puVar5;
        *(uint8_t *)(param_2 + 1) = 1;
        return;
    }
    *(uint8_t *)(param_2 + 1) = 0;
    *param_2 = (uint32_t)param_3;
    return;
}
