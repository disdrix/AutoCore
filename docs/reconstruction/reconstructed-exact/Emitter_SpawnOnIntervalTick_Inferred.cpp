// =============================================================================
// Emitter_SpawnOnIntervalTick_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Emitter interval spawn tick: accumulate rate, countdown spawn timer
//           by dt; when expired, spawn burst group(s) into active list with
//           motion setup, then reschedule random interval [base, base+range].
//
// Address:  0x005bc120–0x005bc3bc  (autoassault.exe, image base 0x400000)
// Body:     669 bytes / 0x29D
// Stable:   aa_005bc120
// System:   client::fx / emitter
// Ghidra:   FUN_005bc120
//
// ABI:      __thiscall — ECX = emitter*; stack float* dt, uint32_t motionCtx; ret 8
// Exactness: CF ≡ raw ≡ decompile (W26-I 2026-07-29). Nested FUN_* this models
//            follow decompiler; some callee this assignments may need machine fix
//            in follow-up (not OWN here).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W26-I seal).
// =============================================================================

#include <cstdint>

// Nested callees (not OWN for this dual) — Ghidra names retained.
extern "C" int FUN_005be390(int *emitter, int groupIndex);
extern "C" int FUN_006759b0(int list, uint32_t hint, int *nodeRef);
extern "C" void FUN_005bdd50(int flag);
extern "C" void FUN_004b3260(uint32_t motionCtx);
extern "C" void FUN_004b2b90(int a, int b);
extern "C" void FUN_004b1100(uint32_t motionCtx, int a, int b);
extern "C" uint32_t FUN_005b81e0(void);
extern "C" void FUN_004b0be0(int other);
extern "C" void *CVOGReaction_RandomUnitScalar(void);
extern "C" void FUN_004b18f0(uint32_t motionCtx);

// DAT_00aaa638 = float ~1/65535 (bytes 80 00 80 37)
extern "C" float DAT_00aaa638;

void __thiscall Emitter_SpawnOnIntervalTick_Inferred(int *emitter /* ECX */,
                                                     float *dt,
                                                     uint32_t motionCtx)
{
    float fVar1;
    float fVar2;
    char cVar3;
    uint16_t uVar4;
    int16_t sVar5;
    int *piVar6;
    char *pcVar7;
    int iVar8;
    uint32_t uVar9;
    int iVar10;
    int local_10;
    int local_c;
    int local_4;

    emitter[0x24a] = static_cast<int>(
        static_cast<float>(emitter[0x24c]) * *dt + static_cast<float>(emitter[0x24a]));
    fVar1 = static_cast<float>(emitter[0x201]);
    fVar2 = *dt;
    emitter[0x201] = static_cast<int>(fVar1 - fVar2);
    if (0.0f < fVar1 - fVar2) {
        return;
    }

    local_10 = 1;
    if (((*reinterpret_cast<uint8_t *>(emitter + 0x263) & 0x80) != 0) &&
        (iVar10 = emitter[3], iVar10 != 0)) {
        if (*reinterpret_cast<int *>(iVar10 + 4) == 0) {
            local_10 = 0;
        } else {
            local_10 =
                (*reinterpret_cast<int *>(iVar10 + 8) - *reinterpret_cast<int *>(iVar10 + 4)) / 0xc;
        }
    }

    piVar6 = emitter + 5;
    do {
        *reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(piVar6) + 0x2ee) = 0;
        piVar6 = reinterpret_cast<int *>(piVar6[0xbd]);
    } while (piVar6 != emitter + 5);

    if (piVar6[0xd1] == 0) {
        pcVar7 = reinterpret_cast<char *>(piVar6) + 0x1ea;
        do {
            cVar3 = *pcVar7;
            pcVar7 = pcVar7 + 1;
        } while (cVar3 != '\0');
        if (pcVar7 == reinterpret_cast<char *>(piVar6) + 0x1eb) {
            goto LAB_005bc36a;
        }
    }

    dt = reinterpret_cast<float *>(0);
    if (0 < local_10) {
        do {
            local_c = emitter[0x25f];
            if (local_c == 0) {
                local_c = 0x7fffffff;
            LAB_005bc228:
                sVar5 = 0;
                if (0 < static_cast<int16_t>(emitter[0x239])) {
                    do {
                        if (local_c <= emitter[0x28a]) {
                            break;
                        }
                        iVar8 = FUN_005be390(emitter, reinterpret_cast<int>(dt));
                        iVar10 = emitter[0x289];
                        local_4 = iVar8;
                        local_4 = FUN_006759b0(iVar10, *reinterpret_cast<uint32_t *>(iVar10 + 4),
                                               &local_4);
                        FUN_005bdd50(1);
                        *reinterpret_cast<int *>(iVar10 + 4) = local_4;
                        **reinterpret_cast<int **>(local_4 + 4) = local_4;
                        FUN_004b3260(motionCtx);
                        FUN_004b2b90(1, 0);
                        FUN_004b1100(motionCtx, 1, 0);
                        if (*emitter != 0) {
                            uVar9 = FUN_005b81e0();
                            *reinterpret_cast<uint32_t *>(iVar8 + 0x1a8) = uVar9;
                        }
                        if ((*reinterpret_cast<uint8_t *>(reinterpret_cast<char *>(emitter) + 0x98d) &
                             4) != 0) {
                            iVar10 = FUN_005be390(emitter, reinterpret_cast<int>(dt));
                            FUN_004b0be0(iVar8);
                            *reinterpret_cast<int *>(iVar8 + 8) = iVar10;
                            iVar8 = reinterpret_cast<int>(CVOGReaction_RandomUnitScalar());
                            if (0xfffff < *reinterpret_cast<int *>(iVar8 + 0xc)) {
                                *reinterpret_cast<uint32_t *>(iVar8 + 0xc) = 0;
                            }
                            uVar4 = *reinterpret_cast<uint16_t *>(
                                *reinterpret_cast<int *>(iVar8 + 8) +
                                *reinterpret_cast<int *>(iVar8 + 0xc) * 2);
                            *reinterpret_cast<int *>(iVar8 + 0xc) =
                                *reinterpret_cast<int *>(iVar8 + 0xc) + 1;
                            *reinterpret_cast<int *>(iVar10 + 0x80) = emitter
                                [static_cast<int>(static_cast<uint64_t>(uVar4) %
                                                  static_cast<uint64_t>(emitter[0x255])) +
                                 0x256];
                            FUN_004b18f0(motionCtx);
                        }
                        sVar5 = static_cast<int16_t>(sVar5 + 1);
                    } while (sVar5 < static_cast<int16_t>(emitter[0x239]));
                }
            } else if (emitter[0x28a] < local_c) {
                goto LAB_005bc228;
            }
            dt = reinterpret_cast<float *>(reinterpret_cast<uintptr_t>(dt) + 1);
        } while (static_cast<int>(reinterpret_cast<uintptr_t>(dt)) < local_10);
    }

LAB_005bc36a:
    iVar10 = reinterpret_cast<int>(CVOGReaction_RandomUnitScalar());
    if (0xfffff < *reinterpret_cast<int *>(iVar10 + 0xc)) {
        *reinterpret_cast<uint32_t *>(iVar10 + 0xc) = 0;
    }
    uVar4 = *reinterpret_cast<uint16_t *>(*reinterpret_cast<int *>(iVar10 + 8) +
                                          *reinterpret_cast<int *>(iVar10 + 0xc) * 2);
    *reinterpret_cast<int *>(iVar10 + 0xc) = *reinterpret_cast<int *>(iVar10 + 0xc) + 1;
    emitter[0x201] = static_cast<int>(static_cast<float>(uVar4) *
                                          static_cast<float>(emitter[0x238]) * DAT_00aaa638 +
                                      static_cast<float>(emitter[0x237]));
}
