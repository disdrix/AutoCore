// =============================================================================
// FUN_00541aa0  (clean twin → Client_LoadSkillsFX)
// -----------------------------------------------------------------------------
// Stable ID: aa_00541aa0
// Address:   0x00541aa0  (autoassault.exe, image base 0x400000)
// Named plate: reconstructed-exact/Client_LoadSkillsFX.cpp
// Dual A/B: 2026-07-29 W23-F — accept-with-gaps
// Note: decompiler omitted thiscall; clean named plate restores ECX host.
// =============================================================================

#include <cstdint>

void *FUN_0054b480(void);
void *__fastcall FUN_004a1620(void *catalogHost);
uint32_t __thiscall FUN_00545890(void *hash, uint32_t key, void *value, char flag);
void *operator_new(uint32_t size);

void __thiscall FUN_00541aa0(void *host)
{
    char cVar1;
    int *piVar2;
    int iVar3;
    char *pcVar4;
    int *piVar5;
    int *piVar6;

    iVar3 = (int)FUN_0054b480();
    piVar6 = (int *)**(int **)(iVar3 + 4);
    if (piVar6 != *(int **)(iVar3 + 4)) {
        do {
            pcVar4 = (char *)((int)piVar6 + 0x5b6);
            do {
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');
            if (pcVar4 != (char *)((int)piVar6 + 0x5b7)) {
                piVar5 = (int *)operator_new(0xc);
                if (piVar5 == (int *)0x0) {
                    piVar5 = (int *)0x0;
                } else {
                    FUN_004a1620((void *)((char *)piVar5 + 4));
                }
                *piVar5 = piVar6[3];
                FUN_00545890(
                    *(void **)((char *)host + 0xf0c),
                    (uint32_t)piVar6[3],
                    piVar5,
                    0);
            }
            if (*(char *)((int)piVar6 + 0x641) == '\0') {
                piVar5 = (int *)piVar6[2];
                if (*(char *)((int)piVar5 + 0x641) == '\0') {
                    cVar1 = *(char *)(*piVar5 + 0x641);
                    piVar6 = piVar5;
                    piVar5 = (int *)*piVar5;
                    while (cVar1 == '\0') {
                        cVar1 = *(char *)(*piVar5 + 0x641);
                        piVar6 = piVar5;
                        piVar5 = (int *)*piVar5;
                    }
                } else {
                    cVar1 = *(char *)(piVar6[1] + 0x641);
                    piVar2 = (int *)piVar6[1];
                    piVar5 = piVar6;
                    while ((piVar6 = piVar2, cVar1 == '\0' &&
                            (piVar5 == (int *)piVar6[2]))) {
                        cVar1 = *(char *)(piVar6[1] + 0x641);
                        piVar2 = (int *)piVar6[1];
                        piVar5 = piVar6;
                    }
                }
            }
        } while (piVar6 != *(int **)(iVar3 + 4));
    }
    return;
}
