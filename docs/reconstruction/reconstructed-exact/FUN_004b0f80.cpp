// =============================================================================
// FUN_004b0f80  (twin of ObjectMotion_AdvanceStage_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0f80
// Address:   0x004b0f80 – 0x004b10fe  (autoassault.exe, image base 0x400000)
// System:    client object motion / reaction stage chain
// Generated: 2026-07-29 W27-E dual seal (decompile + read_memory)
// Exactness: Line-faithful decompiler mirror. Prefer named twin for ports.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

#include <cstdint>

extern float DAT_00aaa638; // 0x00aaa638 = 80 00 80 37 ≈ 1/65535

// Callees (Ghidra names / sealed peers)
uint32_t FUN_004e9530(void *out28, int *vec3);
void Client_GetMissionCompleteAudioTable(int name, uint32_t key);
// CSoundManager_TryQueueMissionCompleteSound_Inferred
uint32_t __thiscall FUN_00725a70(void *self_or_name, uint32_t key);
void FUN_004b7e50(int a, int b, int name, int x, int y, int z);
void FUN_004b6980(void); // NDSpecialFX_FlushStagedMultiHits_Inferred
int CVOGReaction_RandomUnitScalar(void);

// thiscall; ret 4; returns AL 0|1 (as uint)
uint32_t __thiscall FUN_004b0f80(int *param_1, char param_2)
{
  char cVar1;
  uint16_t uVar2;
  int *piVar3;
  char *pcVar4;
  uint32_t uVar5;
  int iVar6;
  uint8_t local_20[28];

  if (*(int *)(*param_1 + 4) == 0) {
    pcVar4 = (char *)(param_1[1] + 0x1ea);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if (pcVar4 != (char *)(param_1[1] + 0x1eb)) {
      uVar5 = FUN_004e9530(local_20, param_1 + 0x5e);
      iVar6 = param_1[1] + 0x1ea;
      Client_GetMissionCompleteAudioTable(iVar6, uVar5);
      FUN_00725a70((void *)iVar6, uVar5);
    }
  }
  else {
    iVar6 = param_1[1];
    pcVar4 = (char *)(iVar6 + 0x1ea);
    do {
      cVar1 = *pcVar4;
      pcVar4 = pcVar4 + 1;
    } while (cVar1 != '\0');
    if ((pcVar4 != (char *)(iVar6 + 0x1eb)) && (*(char *)(iVar6 + 0x2ee) == '\0')) {
      FUN_004b7e50(0, 0, param_1[1] + 0x1ea, param_1[0x5e], param_1[0x5f], param_1[0x60]);
      *(uint8_t *)(param_1[1] + 0x2ee) = 1;
    }
    if ((*(uint8_t *)(param_1[1] + 0x2ef) & 1) != 0) {
      FUN_004b6980();
    }
  }
  piVar3 = *(int **)(param_1[1] + 0x2f4);
  param_1[1] = (int)piVar3;
  if (((param_2 != '\0') && (piVar3 == (int *)(*param_1 + 0x14))) &&
      (*(char *)(*param_1 + 0x7fb) == '\0')) {
    return (uint32_t)piVar3 & 0xffffff00;
  }
  iVar6 = *piVar3;
  param_1[0x5c] = iVar6;
  if ((*(uint8_t *)(param_1[1] + 0x1e4) & 4) != 0) {
    iVar6 = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(iVar6 + 0xc)) {
      *(uint32_t *)(iVar6 + 0xc) = 0;
    }
    uVar2 = *(uint16_t *)(*(int *)(iVar6 + 8) + *(int *)(iVar6 + 0xc) * 2);
    *(int *)(iVar6 + 0xc) = *(int *)(iVar6 + 0xc) + 1;
    iVar6 = param_1[1];
    param_1[0x5c] =
        (int)((float)uVar2 * *(float *)(iVar6 + 4) * DAT_00aaa638 + (float)param_1[0x5c]);
  }
  param_1[0x5d] = param_1[0x5c];
  return ((uint32_t)iVar6 & 0xffffff00) | 1;
}
