// =============================================================================
// ObjectMotion_AdvanceStage_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004b0f80
// Address:   0x004b0f80 – 0x004b10fe  (autoassault.exe, image base 0x400000)
// Body size: 383 B / 0x17F
// System:    client object motion / reaction stage chain
// Generated: 2026-07-29 W27-E dual seal (decompile + read_memory)
// Exactness: Behavior-preserving CF reconstruction. Twin FUN_004b0f80.cpp is the
//            line-faithful decompiler mirror.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Advance a motion/reaction slot to the next linked stage node and reload
//   primary duration. Optional side effects on the *current* stage before the
//   pointer advances:
//     - host+4 == 0 and stage name non-empty → mission-complete audio path
//       (Client_GetMissionCompleteAudioTable + CSoundManager_TryQueue…)
//     - host+4 != 0 → one-shot FUN_004b7e50 spawn + optional multi-hit flush
//   mode==1 (duration end): if next stage is host end-sentinel (+0x14) and
//   host+0x7fb==0, return 0 so SlotTick removes the slot.
//
// ABI:
//   __thiscall (ECX = slot); stack formal (char mode); epilogue ret 4 (C2 04 00).
//   Return AL 0|1.
//
// CONSTANTS (read_memory Confirmed):
//   DAT_00aaa638 @ 0x00aaa638 = 80 00 80 37 ≈ 1/65535 (ushort → unit)
//
// RELATED (sealed peers):
//   FUN_004b4620 = ObjectMotion_SlotTick_Inferred (sole caller; W26-H)
//   FUN_00725a70 = CSoundManager_TryQueueMissionCompleteSound_Inferred (W18-R)
//   FUN_004b6980 = NDSpecialFX_FlushStagedMultiHits_Inferred
// =============================================================================

#include <cstdint>

extern float DAT_00aaa638; // ≈ 1/65535

uint32_t FUN_004e9530(void *out28, int *vec3);
void Client_GetMissionCompleteAudioTable(int name, uint32_t key);
uint32_t __thiscall FUN_00725a70(void *name, uint32_t key);
void FUN_004b7e50(int a, int b, int name, int x, int y, int z);
void FUN_004b6980(void);
int CVOGReaction_RandomUnitScalar(void);

// mode: 0 = soft (radius rebind); 1 = hard (primary duration expired)
// return: 0 = stage chain ended (remove slot); 1 = advanced / duration reloaded
uint8_t __thiscall ObjectMotion_AdvanceStage_Inferred(int *slot, char mode)
{
  char ch;
  uint16_t u16;
  int *next;
  char *p;
  uint32_t key;
  int tmp;
  uint8_t local_20[28];

  if (*(int *)(*slot + 4) == 0) {
    p = (char *)(slot[1] + 0x1ea);
    do {
      ch = *p;
      p = p + 1;
    } while (ch != '\0');
    if (p != (char *)(slot[1] + 0x1eb)) {
      key = FUN_004e9530(local_20, slot + 0x5e);
      tmp = slot[1] + 0x1ea;
      Client_GetMissionCompleteAudioTable(tmp, key);
      FUN_00725a70((void *)tmp, key);
    }
  } else {
    tmp = slot[1];
    p = (char *)(tmp + 0x1ea);
    do {
      ch = *p;
      p = p + 1;
    } while (ch != '\0');
    if ((p != (char *)(tmp + 0x1eb)) && (*(char *)(tmp + 0x2ee) == '\0')) {
      FUN_004b7e50(0, 0, slot[1] + 0x1ea, slot[0x5e], slot[0x5f], slot[0x60]);
      *(uint8_t *)(slot[1] + 0x2ee) = 1;
    }
    if ((*(uint8_t *)(slot[1] + 0x2ef) & 1) != 0) {
      FUN_004b6980();
    }
  }

  next = *(int **)(slot[1] + 0x2f4);
  slot[1] = (int)next;
  if ((mode != '\0') && (next == (int *)(*slot + 0x14)) &&
      (*(char *)(*slot + 0x7fb) == '\0')) {
    return 0;
  }

  tmp = *next;
  slot[0x5c] = tmp;
  if ((*(uint8_t *)(slot[1] + 0x1e4) & 4) != 0) {
    tmp = CVOGReaction_RandomUnitScalar();
    if (0xfffff < *(int *)(tmp + 0xc)) {
      *(uint32_t *)(tmp + 0xc) = 0;
    }
    u16 = *(uint16_t *)(*(int *)(tmp + 8) + *(int *)(tmp + 0xc) * 2);
    *(int *)(tmp + 0xc) = *(int *)(tmp + 0xc) + 1;
    tmp = slot[1];
    slot[0x5c] =
        (int)((float)u16 * *(float *)(tmp + 4) * DAT_00aaa638 + (float)slot[0x5c]);
  }
  slot[0x5d] = slot[0x5c];
  return 1;
}
