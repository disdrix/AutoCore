// =============================================================================
// FUN_00580ed0  (Ghidra id twin of TtPhantom_castRay)
// -----------------------------------------------------------------------------
// Stable ID: aa_00580ed0
// Address:   0x00580ed0  (autoassault.exe, image base 0x400000)
// Canonical: TtPhantom_castRay
// See:       docs/reconstruction/reconstructed-exact/TtPhantom_castRay.cpp
// MEGA-101:  2026-08-05 live re-verify; RET 8; plate "TtPhantom::castRay"
// =============================================================================

// Thin twin: keep FUN_* path for address-keyed tooling. Body mirrors named unit.

extern int *DAT_00bc5644;
extern int *DAT_00bc5648;
extern int DAT_009d2878;
extern unsigned long long rdtsc(void);
extern void __thiscall FUN_005d6ae0(float *out_or_this, float *R_cols, float *v_result);

void __thiscall FUN_00580ed0(int param_1, float *param_2, int param_3)
{
  int *piVar1;
  int iVar2;
  unsigned long long uVar3;
  int *piVar4;
  float fVar5;
  float fVar6;
  float fVar7;
  int local_48;
  char local_44[4];
  float local_40;
  float local_3c;
  float local_38;
  float local_30;
  float local_2c;
  float local_28;
  float local_20;
  int local_1c;

  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)"TtPhantom::castRay";
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  local_20 = param_2[9];
  if ((*(char *)(param_2 + 8) == '\0') ||
      (local_1c = *(int *)(*(int *)(param_1 + 8) + 0xd0), local_1c == 0)) {
    local_1c = 0;
  } else {
    local_1c = local_1c + 0x10;
  }
  local_48 = *(int *)(param_1 + 0x84);
  piVar4 = *(int **)(param_1 + 0x80);
  if (-1 < local_48 + -1) {
    do {
      piVar1 = *(int **)*piVar4;
      if (piVar1 != (int *)0x0) {
        iVar2 = ((int *)*piVar4)[2];
        fVar6 = param_2[1] - *(float *)(iVar2 + 0x54);
        fVar7 = param_2[2] - *(float *)(iVar2 + 0x58);
        fVar5 = *param_2 - *(float *)(iVar2 + 0x50);
        local_40 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +
                   *(float *)(iVar2 + 0x20) * fVar5;
        local_3c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x30);
        local_38 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x40);
        fVar7 = param_2[6] - *(float *)(iVar2 + 0x58);
        fVar6 = param_2[5] - *(float *)(iVar2 + 0x54);
        fVar5 = param_2[4] - *(float *)(iVar2 + 0x50);
        local_30 = *(float *)(iVar2 + 0x28) * fVar7 + *(float *)(iVar2 + 0x24) * fVar6 +
                   *(float *)(iVar2 + 0x20) * fVar5;
        local_2c = *(float *)(iVar2 + 0x38) * fVar7 + *(float *)(iVar2 + 0x34) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x30);
        local_28 = *(float *)(iVar2 + 0x48) * fVar7 + *(float *)(iVar2 + 0x44) * fVar6 +
                   fVar5 * *(float *)(iVar2 + 0x40);
        (**(void (**)(char *, float *, int))(*piVar1 + 0x20))(local_44, &local_40, param_3);
        if (local_44[0] != '\0') {
          *(int *)(param_3 + 0x20) = *piVar4;
        }
      }
      piVar4 = piVar4 + 1;
      local_48 = local_48 + -1;
    } while (local_48 != 0);
  }
  if (*(int *)(param_3 + 0x20) != 0) {
    FUN_005d6ae0(
        (float *)param_3,
        (float *)(*(int *)(*(int *)(param_3 + 0x20) + 8) + 0x20),
        (float *)param_3);
  }
  if (DAT_00bc5644 < DAT_00bc5648) {
    *DAT_00bc5644 = (int)&DAT_009d2878;
    uVar3 = rdtsc();
    DAT_00bc5644[1] = (int)uVar3;
    DAT_00bc5644 = DAT_00bc5644 + 3;
  }
  return;
}
