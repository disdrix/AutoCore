// =============================================================================
// Vehicle_UpdateWeaponHardpoints3_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004f9030
// Address:   0x004f9030  (autoassault.exe, image base 0x400000)
// Body:      0x004f9030 – 0x004f9563
// System:    vehicle / combat weapon hardpoints
// Generated: 2026-07-23 scaffold FUN_004f9030; refined 2026-07-29 W19-A dual A/B
// Exactness: Behavior-preserving rewrite of decompiler CF + entry/epilogue seal.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes (dual A/B sealed 2026-07-29 W19-A):
 * - thiscall/fastcall: vehicle* in ECX (saved to ESI). Near RET; 0 stack args.
 * - Phase 1: if MI-relative lock/control at +0xb0 has (byte+0xb4 & 0x13) != 0,
 *   walk 3 pointers at this+0x260; for each non-null hardpoint:
 *     Weapon_SetFireFlagPair(slot, 0);  slot+0xC9 = 0.
 * - Phase 2: for slotIdx 0..2:
 *     load aim vec3 from plant(+0x3c via +0xac chain)+0x4e8 + slotIdx*12
 *     transform (FUN_004e9370) using vehicle pos/orient (local vs this+8 nested)
 *     mode = 3-bit field in plant+0x50c at shift slotIdx*3
 *     yaw = (mode < 0 || mode > 1) ? *(this+0x158) : 0
 *     Quat_FromAxisAngle: ECX=out(local_80), axis=DAT_00af18b0 (+Y), angle=yaw
 *     quat-mul vehicle orient; FUN_004e8830 → local_6c
 *     if mode==2 && this+0x3a0: vtbl apply on that iface
 *     if hardpoint[slotIdx] && hardpoint+8: set pos/orient vtbls, Weapon_FireHelper,
 *       optional matrix materialize (Math_Matrix4x4_Set16) when this+0x105 and attach chain
 *
 * Named callees use prior dual structural names where sealed; unresolved stay FUN_*.
 * Widths: uint32_t / float / uint8_t (no bare undefined4).
 */

#include <cstdint>

// Ghidra-style vtbl call surface (documentation reconstruction; not linkable retail).
typedef void (*code)(void);

// Ghidra FUN names retained for unresolved helpers; sealed duals use structural aliases.
extern "C" void FUN_0056a260(uint32_t value /* stack; this=ECX hardpoint */); // Weapon_SetFireFlagPair
extern "C" void FUN_004e9370(...);
extern "C" void FUN_00567ce0(...); // Quat_FromAxisAngle_Inferred (ECX=out)
extern "C" void FUN_004e8830(...);
extern "C" void FUN_0056d160(...); // Weapon_FireHelper_Inferred
extern "C" void FUN_004e88a0(...);
extern "C" void FUN_0076eb00(...);
extern "C" void FUN_0076f5f0(...);
extern "C" void FUN_0043f210(...); // Math_Matrix4x4_Set16
extern "C" void FUN_0099b8a0(...);
extern "C" void FUN_0040cf90(...);

extern float DAT_00af18b0[4];     // bytes: (0, 1.0f, 0, 0) +Y
extern uint32_t DAT_00b041b0[];   // BSS fallback fire-helper host

void __fastcall Vehicle_UpdateWeaponHardpoints3_Inferred(int param_1 /* ECX = vehicle */)
{
    float fVar1;
    float fVar2;
    float fVar3;
    float fVar4;
    char cVar5;
    float *pfVar6;
    uint32_t *puVar7;
    int iVar8;
    uint8_t bVar9;
    int iVar10;
    uint32_t uVar11;
    uint32_t uVar12;
    int local_e8;
    int local_e4;
    float local_e0;
    float local_dc;
    float local_d8;
    float local_d4;
    int local_c4;
    float local_c0;
    float local_bc;
    float local_b8;
    uint32_t uStack_a4;
    uint32_t uStack_a0;
    uint32_t uStack_9c;
    uint32_t uStack_98;
    uint32_t uStack_94;
    uint32_t uStack_90;
    uint8_t local_8c[12];
    float local_80;
    float local_7c;
    float local_78;
    float local_74;
    uint8_t auStack_70[4];
    uint8_t local_6c[16];
    uint32_t local_5c;
    uint32_t local_58;
    uint32_t local_54;
    uint32_t auStack_50[2];
    uint32_t uStack_48;
    uint32_t uStack_44;
    uint32_t uStack_34;
    uint32_t uStack_30;
    uint32_t uStack_28;
    uint32_t uStack_24;
    uint32_t uStack_20;
    uint32_t uStack_1c;
    uint32_t uStack_18;
    uint32_t uStack_14;

    iVar10 = *(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xb0 + param_1);
    if ((iVar10 != 0) && ((*(uint8_t *)(iVar10 + 0xb4) & 0x13) != 0)) {
        iVar10 = 0;
        local_e8 = 3;
        do {
            iVar8 = *(int *)(iVar10 + *(int *)(param_1 + 0x260));
            if (iVar8 != 0) {
                FUN_0056a260(0);                         /* Weapon_SetFireFlagPair(slot, 0) */
                *(uint8_t *)(iVar8 + 0xc9) = 0;
            }
            iVar10 = iVar10 + 4;
            local_e8 = local_e8 + -1;
        } while (local_e8 != 0);
    }

    local_e8 = 0;
    bVar9 = 0;
    local_e4 = 0;
    local_c4 = 3;
    do {
        iVar10 = *(int *)(param_1 + 4);
        local_5c = *(uint32_t *)
                    (*(int *)(*(int *)(*(int *)(iVar10 + 4) + 0xac + param_1) + 0x3c) + 0x4e8 + local_e4
                    );
        local_58 = *(uint32_t *)
                    (*(int *)(*(int *)(*(int *)(iVar10 + 4) + 0xac + param_1) + 0x3c) + 0x4ec + local_e4
                    );
        local_54 = *(uint32_t *)
                    (*(int *)(*(int *)(*(int *)(iVar10 + 4) + 0xac + param_1) + 0x3c) + 0x4f0 + local_e4
                    );
        iVar10 = *(int *)(param_1 + 8);
        if (iVar10 == 0) {
            iVar8 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1;
            iVar10 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1;
        }
        else {
            iVar8 = *(int *)(iVar10 + 0x3c) + 0x30;
            iVar10 = *(int *)(iVar10 + 0x3c) + 0xb0;
        }
        FUN_004e9370(iVar10, iVar8, &local_5c, local_8c);
        uVar11 = 7 << (bVar9 & 0x1f);
        cVar5 = (char)((int)(*(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +
                                                        param_1) + 0x3c) + 0x50c) & uVar11) >>
                      (bVar9 & 0x1f));
        if ((cVar5 < '\0') || ('\x01' < cVar5)) {
            uVar12 = *(uint32_t *)(param_1 + 0x158);
        }
        else {
            uVar12 = 0;
        }
        /* Quat_FromAxisAngle: ECX = &local_80 (out); axis = +Y; angle = uVar12 bits as float */
        FUN_00567ce0(&DAT_00af18b0, uVar12);
        if (*(int *)(param_1 + 8) == 0) {
            pfVar6 = (float *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0x94 + param_1);
        }
        else {
            pfVar6 = (float *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x30);
        }
        fVar1 = *pfVar6;
        fVar2 = pfVar6[1];
        fVar3 = pfVar6[2];
        fVar4 = pfVar6[3];
        local_b8 = local_78 * fVar4 + (local_7c * fVar1 - fVar2 * local_80);
        local_e0 = local_74 * fVar1 + fVar4 * local_80 + (local_78 * fVar2 - local_7c * fVar3);
        local_dc = local_74 * fVar2 + local_7c * fVar4 + (fVar3 * local_80 - local_78 * fVar1);
        local_d8 = local_74 * fVar3 + local_b8;
        local_d4 = local_74 * fVar4 - (local_80 * fVar1 + local_78 * fVar3 + local_7c * fVar2);
        local_c0 = local_e0;
        local_bc = local_dc;
        FUN_004e8830(&local_e0, local_6c);
        if (((char)((int)(*(uint32_t *)(*(int *)(*(int *)(*(int *)(*(int *)(param_1 + 4) + 4) + 0xac +
                                                     param_1) + 0x3c) + 0x50c) & uVar11) >>
                   (bVar9 & 0x1f)) == '\x02') && (*(int *)(param_1 + 0x3a0) != 0)) {
            (**(code **)(**(int **)(param_1 + 0x3a0) + 0x18))(local_8c);
            (**(code **)(**(int **)(param_1 + 0x3a0) + 0x14))(auStack_70);
        }
        iVar10 = *(int *)(local_e8 + *(int *)(param_1 + 0x260));
        if ((iVar10 != 0) && (*(int **)(iVar10 + 8) != (int *)0x0)) {
            (**(code **)(**(int **)(iVar10 + 8) + 0x18))(local_8c);
            (**(code **)(**(int **)(iVar10 + 8) + 0x14))(auStack_70);
            if (*(int *)(param_1 + 8) == 0) {
                puVar7 = (uint32_t *)&DAT_00b041b0;
            }
            else {
                puVar7 = (uint32_t *)(*(int *)(*(int *)(param_1 + 8) + 0x3c) + 0x40);
            }
            FUN_0056d160(puVar7, 1);                     /* Weapon_FireHelper */
            if (((*(char *)(param_1 + 0x105) != '\0') && (*(int *)(iVar10 + 0xc0) != 0)) &&
               (*(int *)(*(int *)(iVar10 + 0xc0) + 0x18) != 0)) {
                if (*(int *)(param_1 + 8) == 0) {
                    iVar8 = *(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1;
                }
                else {
                    iVar8 = *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
                }
                FUN_004e88a0(iVar8, local_8c);
                FUN_0076eb00(auStack_50, local_6c);
                uStack_98 = auStack_50[0];
                uStack_90 = uStack_48;
                uStack_94 = 0;
                FUN_0076f5f0(&uStack_98, &uStack_98);
                uStack_a4 = uStack_30;
                uStack_9c = uStack_28;
                uStack_a0 = 0;
                FUN_0076f5f0(&uStack_a4, &uStack_a4);
                FUN_0043f210(uStack_98, uStack_94, uStack_90, uStack_44, 0, 0x3f800000, 0, uStack_34,
                             uStack_a4, uStack_a0, uStack_9c, uStack_24, uStack_20, uStack_1c,
                             uStack_18, uStack_14);       /* Math_Matrix4x4_Set16 */
                FUN_0099b8a0(auStack_50);
                uVar12 = 3;
                (**(code **)(**(int **)(*(int *)(iVar10 + 0xc0) + 0x18) + 0x10))(3, local_8c);
                FUN_0040cf90(uVar12);
                (**(code **)(**(int **)(*(int *)(iVar10 + 0xc0) + 0x18) + 0x14))(auStack_70);
            }
        }
        local_e4 = local_e4 + 0xc;
        local_e8 = local_e8 + 4;
        bVar9 = bVar9 + 3;
        local_c4 = local_c4 + -1;
    } while (local_c4 != 0);
    return;
}
