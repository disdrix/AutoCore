// =============================================================================
// Skill_ApplyBoundStatusMotionTable_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d0d60
// Address:   0x005d0d60 – 0x005d126d  (autoassault.exe, image base 0x400000)
// System:    skills / status-motion
// Ghidra:    FUN_005d0d60
// Dual seal: W22-A 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving; tree walk + phys side effects preserved.
// =============================================================================

// PURPOSE: Look up skillId in bound controller's status/motion table (stride 0x18).
// On hit: write end-time at ctl+0x30; optional impulse/handbrake/heading; set
// entity status flags; dispatch entity vtbl+0x64 by mode byte 1..4.

extern unsigned int g_dwClientTickMs;
extern float g_flMsToSeconds_Inferred; // 0.001
extern float _DAT_00aaa5dc;            // 4294967296.0f unsigned bias
extern float _DAT_009da864;            // ~1.192e-7f horiz epsilon
extern float g_flOne;                  // 1.0f
extern float g_abInferredDefaultAimPos[]; // 4 floats

extern void CVOGSpawnPoint_SetObjectActiveState(void *spawn, char *state, int a3);
extern void CVOGPhysics_ApplyImpulseVector(float *v4);
extern void __thiscall VehicleEntity_SetHandbrake(void *veh /*ECX from site*/, int on);
extern void FUN_0040d040(float *angVel4); // CVOGPhysics_SetAngularVelocity
extern void FUN_00404dc0(void *basis);    // CVOGPhysics_SetRotation
extern char *FUN_00404e00(char *out);
extern float *FUN_00404c90(void);
extern void FUN_004e8dc0(float *dir4, void *outBasis28);
extern float ABS(float);
extern float SQRT(float);

// __thiscall; RET 4
void __thiscall Skill_ApplyBoundStatusMotionTable_Inferred(int ctl, int skillId)
{
    char cVar1;
    int iVar2;
    int *piVar3;
    int *piVar4;
    int *piVar5;
    char *pcVar6;
    float *pfVar7;
    int *piVar8;
    unsigned int uVar9;
    float fVar10;
    char local_41;
    int local_40;
    int *local_3c;
    int local_38;
    float local_34;
    float local_30;
    float local_2c;
    float local_28;
    float local_24;
    unsigned char auStack_20[28];

    iVar2 = *(int *)(ctl + 0x18);
    if (iVar2 == 0) {
        return;
    }

    local_38 = ctl;
    if ((*(char *)(ctl + 0x21) != '\0') &&
        (*(char *)(*(int *)(iVar2 + 0xa4) + 0x7e) == '\0')) {
        local_41 = 1;
        CVOGSpawnPoint_SetObjectActiveState((void *)iVar2, &local_41, 0);
    }

    // entity = *(ctl+0x64); walk MI chain to table sentinel at +0x520
    piVar3 = *(int **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(ctl + 100) + 4) + 4) + 0xac
                                        + *(int *)(ctl + 100)) + 0x3c) + 0x520);
    piVar8 = (int *)*piVar3;
    local_3c = 0;
    local_41 = 0;

    if (piVar8 == piVar3) {
        return;
    }

    do {
        if (local_41 != 0) {
            goto LAB_apply;
        }
        uVar9 = 0;
        local_40 = 0;
        while (1) {
            if ((piVar8[5] == 0) ||
                ((unsigned int)((piVar8[6] - piVar8[5]) / 0x18) <= uVar9)) {
                goto LAB_next_node;
            }
            local_3c = (int *)(piVar8[5] + local_40);
            if (*local_3c == skillId) {
                break;
            }
            uVar9 = uVar9 + 1;
            local_40 = local_40 + 0x18;
        }
        local_41 = 1;

    LAB_next_node:
        // red-black / tree successor using node+0x21 flags (decompiler structure)
        if (*(char *)((int)piVar8 + 0x21) == '\0') {
            piVar4 = (int *)piVar8[2];
            if (*(char *)((int)piVar4 + 0x21) == '\0') {
                cVar1 = *(char *)(*piVar4 + 0x21);
                piVar8 = piVar4;
                piVar4 = (int *)*piVar4;
                while (cVar1 == '\0') {
                    cVar1 = *(char *)(*piVar4 + 0x21);
                    piVar8 = piVar4;
                    piVar4 = (int *)*piVar4;
                }
            } else {
                cVar1 = *(char *)(piVar8[1] + 0x21);
                piVar5 = (int *)piVar8[1];
                piVar4 = piVar8;
                while ((piVar8 = piVar5, cVar1 == '\0' && (piVar4 == (int *)piVar8[2]))) {
                    cVar1 = *(char *)(piVar8[1] + 0x21);
                    piVar5 = (int *)piVar8[1];
                    piVar4 = piVar8;
                }
            }
        }
        ctl = local_38;
    } while (piVar8 != piVar3);

    if (local_41 == 0) {
        return;
    }

LAB_apply:
    local_34 = (float)(unsigned int)*(unsigned short *)(local_3c + 1);
    fVar10 = (float)(int)g_dwClientTickMs;
    if ((int)g_dwClientTickMs < 0) {
        fVar10 = fVar10 + _DAT_00aaa5dc;
    }
    *(float *)(ctl + 0x30) = (fVar10 + (float)(int)local_34) * g_flMsToSeconds_Inferred;

    if ((short)local_3c[1] != 0) {
        if (*(char *)((int)local_3c + 10) != '\0') {
            *(unsigned char *)(*(int *)(ctl + 100) + 0x305) = 1;
            iVar2 = *(int *)(ctl + 100);
            if ((*(char *)(iVar2 + 0x304) != '\0') && (*(int *)(iVar2 + 8) != 0)) {
                *(unsigned char *)(iVar2 + 0x304) = 0;
                // final impulse vector: (0, physY@+0x44, 0, 0)
                local_2c = *(float *)(*(int *)(*(int *)(*(int *)(ctl + 100) + 8) + 0x3c) + 0x44);
                local_30 = 0.0f;
                local_28 = 0.0f;
                local_24 = 0.0f;
                CVOGPhysics_ApplyImpulseVector(&local_30);
            }
            if (*(int *)(*(int *)(ctl + 100) + 0x250) != 0) {
                VehicleEntity_SetHandbrake((void *)*(int *)(*(int *)(ctl + 100) + 0x250), 1);
            }
            iVar2 = *(int *)(ctl + 100);
            piVar3 = *(int **)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2);
            if ((((piVar3 != 0) &&
                  (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac + iVar2) +
                                    0x3c) + 0x4e8) != 1)) &&
                 (*(int *)(iVar2 + 8) != 0)) &&
                ((local_34 = (float)(**(int (**)())(*piVar3 + 0x1c8))(), local_34 != 0.0f &&
                  (*(int *)((int)local_34 + 8) != 0)))) {
                iVar2 = *(int *)(ctl + 100);
                pcVar6 = FUN_00404e00(&local_41);
                if (*pcVar6 != '\0') {
                    iVar2 = *(int *)(*(int *)(iVar2 + 8) + 0x3c);
                    local_30 = ABS(*(float *)(iVar2 + 0x50) - g_abInferredDefaultAimPos[0]);
                    local_2c = ABS(*(float *)(iVar2 + 0x54) - g_abInferredDefaultAimPos[1]);
                    local_28 = ABS(*(float *)(iVar2 + 0x58) - g_abInferredDefaultAimPos[2]);
                    local_24 = ABS(*(float *)(iVar2 + 0x5c) - g_abInferredDefaultAimPos[3]);
                    if ((g_flMsToSeconds_Inferred < local_28 ||
                         g_flMsToSeconds_Inferred < local_2c) ||
                        g_flMsToSeconds_Inferred < local_30) {
                        FUN_0040d040(g_abInferredDefaultAimPos);
                    }
                    pfVar7 = FUN_00404c90();
                    local_30 = *pfVar7;
                    local_2c = pfVar7[1];
                    local_28 = pfVar7[2];
                    local_24 = pfVar7[3];
                    pfVar7 = (float *)(**(int (**)())(*(int *)(*(int *)(*(int *)(*(int *)(ctl + 100) +
                                                                             4) + 4) + 4 +
                                                               *(int *)(ctl + 100)) + 0x1a0))();
                    local_30 = local_30 - *pfVar7;
                    local_28 = local_28 - pfVar7[2];
                    local_34 = local_30 * local_30 + local_28 * local_28;
                    if (SQRT(local_34) <= _DAT_009da864) {
                        return;
                    }
                    if (local_34 == 0.0f) {
                        fVar10 = 0.0f;
                    } else {
                        fVar10 = g_flOne / SQRT(local_34);
                    }
                    local_30 = fVar10 * local_30;
                    local_2c = fVar10 * 0.0f;
                    local_28 = local_28 * fVar10;
                    local_24 = (local_24 - pfVar7[3]) * fVar10;
                    FUN_004e8dc0(&local_30, auStack_20);
                    FUN_00404dc0(auStack_20);
                }
            }
        }
        *(unsigned char *)(*(int *)(ctl + 100) + 0x306) = 1;
    }

    switch (*(unsigned char *)((int)local_3c + 0xb)) {
    case 1:
        (**(int (**)())(**(int **)(ctl + 100) + 100))(3, 0x3dcccccd, 1, 0xbf800000);
        return;
    case 2:
        (**(int (**)())(**(int **)(ctl + 100) + 100))(4, 0x3dcccccd, 1, 0xbf800000);
        return;
    case 3:
        (**(int (**)())(**(int **)(ctl + 100) + 100))(0x10, 0x3dcccccd, 1, 0xbf800000);
        return;
    case 4:
        (**(int (**)())(**(int **)(ctl + 100) + 100))(0x11, 0x3dcccccd, 1, 0xbf800000);
        break;
    }
}

void __thiscall FUN_005d0d60(int param_1, int param_2)
{
    Skill_ApplyBoundStatusMotionTable_Inferred(param_1, param_2);
}
