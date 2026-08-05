// =============================================================================
// Client_LoadSkillsFX
// -----------------------------------------------------------------------------
// Purpose:  Walk the process-global SkillDefMap; for each skill definition with
//           a non-empty string at node+0x5B6, allocate a 0xC SkillFxEntry
//           (skillId + FxMasterCatalog at +4) and insert into the host's
//           skills-FX CNDHash at host+0xF0C.
//
// Address:  0x00541aa0  (autoassault.exe, image base 0x400000)
// Body:     0x00541aa0–0x00541baf (271 bytes; plain ret)
// Stable:   aa_00541aa0
// System:   skills-abilities / client-fx
// Ghidra:   FUN_00541aa0
//
// ABI:      __thiscall
//             ECX = content host* (CloneBase load context)
//             host+0xF0C = CNDHash* for skills FX bindings
//             plain ret (C3); SEH LAB_009a3ff9
//
// Name evidence: parent FUN_00541e70 logs
//   "before LoadSkillsFX and SpecialFXMaster" then calls this, then FUN_004a6790.
//
// Exactness: CF mirrors raw + live decompile + read_memory ABI fixes.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W23-F).
// =============================================================================

#include <cstdint>

void *FUN_0054b480(void);                              // SkillDefMap_GetGlobal
void *__fastcall FUN_004a1620(void *catalogHost /*ECX*/); // FxMasterCatalog_Ctor
// CNDHash insert: this=hash, key, value*, flag
uint32_t __thiscall FUN_00545890(void *hash, uint32_t key, void *value, char flag);
void *operator_new(uint32_t size);

void __thiscall Client_LoadSkillsFX(void *host /* ECX */)
{
    char cVar1;
    int *piVar2;
    int iVar3;
    char *pcVar4;
    int *piVar5;
    int *piVar6;
    // SEH locals omitted (LAB_009a3ff9)

    iVar3 = (int)FUN_0054b480();
    piVar6 = (int *)**(int **)(iVar3 + 4);
    if (piVar6 != *(int **)(iVar3 + 4)) {
        do {
            // strlen-like scan of C-string at skill node +0x5B6
            pcVar4 = (char *)((int)piVar6 + 0x5b6);
            do {
                cVar1 = *pcVar4;
                pcVar4 = pcVar4 + 1;
            } while (cVar1 != '\0');

            // non-empty if advanced past first char + NUL scan end != start+1
            if (pcVar4 != (char *)((int)piVar6 + 0x5b7)) {
                piVar5 = (int *)operator_new(0xc);
                if (piVar5 == (int *)0x0) {
                    piVar5 = (int *)0x0;
                } else {
                    // bytes: lea ecx, [entry+4]; call FUN_004a1620
                    FUN_004a1620((void *)((char *)piVar5 + 4));
                }
                *piVar5 = piVar6[3]; // skill id @ node+0x0C
                // bytes: mov ecx, [host+0xF0C]; push entry; push skillId; call
                FUN_00545890(
                    *(void **)((char *)host + 0xf0c),
                    (uint32_t)piVar6[3],
                    piVar5,
                    0);
            }

            // in-order successor; isnil @ +0x641
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
