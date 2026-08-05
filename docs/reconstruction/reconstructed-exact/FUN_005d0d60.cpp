// =============================================================================
// FUN_005d0d60 / Skill_ApplyBoundStatusMotionTable_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_005d0d60
// Address:   0x005d0d60 – 0x005d126d  (autoassault.exe, image base 0x400000)
// System:    skills / status-motion
// Dual seal: W22-A 2026-07-29
// Prefer:    Skill_ApplyBoundStatusMotionTable_Inferred.cpp
// Exactness: Faithful decompiler CF; uint8_t/float instead of bare undefined*.
// =============================================================================

extern unsigned int g_dwClientTickMs;
extern float g_flMsToSeconds_Inferred;
extern float _DAT_00aaa5dc;
extern float _DAT_009da864;
extern float g_flOne;
extern float g_abInferredDefaultAimPos[];

extern void CVOGSpawnPoint_SetObjectActiveState(void *spawn, char *state, int a3);
extern void CVOGPhysics_ApplyImpulseVector(float *v4);
extern void VehicleEntity_SetHandbrake(int on);
extern void FUN_0040d040(float *angVel4);
extern void FUN_00404dc0(void *basis);
extern char *FUN_00404e00(char *out);
extern float *FUN_00404c90(void);
extern void FUN_004e8dc0(float *dir4, void *outBasis28);
extern float ABS(float);
extern float SQRT(float);

void __thiscall FUN_005d0d60(int param_1, int param_2)
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
    uint8_t auStack_20[28];

    iVar2 = *(int *)(param_1 + 0x18);
    if (iVar2 != 0) {
        local_38 = param_1;
        if ((*(char *)(param_1 + 0x21) != '\0') &&
            (*(char *)(*(int *)(iVar2 + 0xa4) + 0x7e) == '\0')) {
            local_41 = '\x01';
            CVOGSpawnPoint_SetObjectActiveState((void *)iVar2, &local_41, 0);
        }
        piVar3 = *(int **)(*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 4) + 4) +
                                            0xac + *(int *)(param_1 + 100)) + 0x3c) + 0x520);
        piVar8 = (int *)*piVar3;
        local_3c = (int *)0x0;
        local_41 = '\0';
        if (piVar8 != piVar3) {
            do {
                if (local_41 != '\0')
                    goto LAB_005d0e90;
                uVar9 = 0;
                local_40 = 0;
                while (true) {
                    if ((piVar8[5] == 0) ||
                        ((unsigned int)((piVar8[6] - piVar8[5]) / 0x18) <= uVar9))
                        goto LAB_005d0e33;
                    local_3c = (int *)(piVar8[5] + local_40);
                    if (*local_3c == param_2)
                        break;
                    uVar9 = uVar9 + 1;
                    local_40 = local_40 + 0x18;
                }
                local_41 = '\x01';
            LAB_005d0e33:
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
                        while ((piVar8 = piVar5, cVar1 == '\0' &&
                                (piVar4 == (int *)piVar8[2]))) {
                            cVar1 = *(char *)(piVar8[1] + 0x21);
                            piVar5 = (int *)piVar8[1];
                            piVar4 = piVar8;
                        }
                    }
                }
                param_1 = local_38;
            } while (piVar8 != piVar3);
            if (local_41 != '\0') {
            LAB_005d0e90:
                local_34 = (float)(unsigned int)*(unsigned short *)(local_3c + 1);
                fVar10 = (float)(int)g_dwClientTickMs;
                if ((int)g_dwClientTickMs < 0) {
                    fVar10 = fVar10 + _DAT_00aaa5dc;
                }
                *(float *)(param_1 + 0x30) =
                    (fVar10 + (float)(int)local_34) * g_flMsToSeconds_Inferred;
                if ((short)local_3c[1] != 0) {
                    if (*(char *)((int)local_3c + 10) != '\0') {
                        *(uint8_t *)(*(int *)(param_1 + 100) + 0x305) = 1;
                        iVar2 = *(int *)(param_1 + 100);
                        if ((*(char *)(iVar2 + 0x304) != '\0') && (*(int *)(iVar2 + 8) != 0)) {
                            *(uint8_t *)(iVar2 + 0x304) = 0;
                            local_2c = *(float *)(*(int *)(*(int *)(*(int *)(param_1 + 100) + 8) +
                                                           0x3c) +
                                                  0x44);
                            local_30 = 0.0f;
                            local_28 = 0.0f;
                            local_24 = 0.0f;
                            CVOGPhysics_ApplyImpulseVector(&local_30);
                        }
                        if (*(int *)(*(int *)(param_1 + 100) + 0x250) != 0) {
                            VehicleEntity_SetHandbrake(1);
                        }
                        iVar2 = *(int *)(param_1 + 100);
                        piVar3 =
                            *(int **)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xa4 + iVar2);
                        if ((((piVar3 != (int *)0x0) &&
                              (*(int *)(*(int *)(*(int *)(*(int *)(*(int *)(iVar2 + 4) + 4) + 0xac +
                                                         iVar2) +
                                                0x3c) +
                                        0x4e8) != 1)) &&
                             (*(int *)(iVar2 + 8) != 0)) &&
                            ((local_34 = (float)(**(int (**)())(*piVar3 + 0x1c8))(),
                              local_34 != 0.0f && (*(int *)((int)local_34 + 8) != 0)))) {
                            iVar2 = *(int *)(param_1 + 100);
                            pcVar6 = FUN_00404e00(&local_41);
                            if (*pcVar6 != '\0') {
                                iVar2 = *(int *)(*(int *)(iVar2 + 8) + 0x3c);
                                local_30 = ABS(*(float *)(iVar2 + 0x50) -
                                               g_abInferredDefaultAimPos[0]);
                                local_2c = ABS(*(float *)(iVar2 + 0x54) -
                                               g_abInferredDefaultAimPos[1]);
                                local_28 = ABS(*(float *)(iVar2 + 0x58) -
                                               g_abInferredDefaultAimPos[2]);
                                local_24 = ABS(*(float *)(iVar2 + 0x5c) -
                                               g_abInferredDefaultAimPos[3]);
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
                                pfVar7 =
                                    (float *)(**(int (**)())(*(int *)(*(int *)(*(int *)(*(int *)(
                                                                                 param_1 + 100) +
                                                                             4) +
                                                                     4) +
                                                             4 + *(int *)(param_1 + 100)) +
                                                    0x1a0))();
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
                                    local_34 = fVar10;
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
                    *(uint8_t *)(*(int *)(param_1 + 100) + 0x306) = 1;
                }
                switch (*(uint8_t *)((int)local_3c + 0xb)) {
                case 1:
                    (**(int (**)())(**(int **)(param_1 + 100) + 100))(3, 0x3dcccccd, 1,
                                                                      0xbf800000);
                    return;
                case 2:
                    (**(int (**)())(**(int **)(param_1 + 100) + 100))(4, 0x3dcccccd, 1,
                                                                      0xbf800000);
                    return;
                case 3:
                    (**(int (**)())(**(int **)(param_1 + 100) + 100))(0x10, 0x3dcccccd, 1,
                                                                      0xbf800000);
                    return;
                case 4:
                    (**(int (**)())(**(int **)(param_1 + 100) + 100))(0x11, 0x3dcccccd, 1,
                                                                      0xbf800000);
                }
            }
        }
    }
    return;
}
