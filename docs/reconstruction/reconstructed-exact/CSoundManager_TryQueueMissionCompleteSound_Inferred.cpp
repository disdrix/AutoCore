// =============================================================================
// CSoundManager_TryQueueMissionCompleteSound_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00725a70
// Address:   0x00725a70 – 0x00725bcd (0x15d bytes)
// Module:    autoassault.exe (image base 0x400000)
// System:    client audio / CSoundManager / mission-complete SFX
// Generated: 2026-07-29 W18-R dual A/B (OWN-ONLY)
// Exactness: Behavior-preserving rewrite of decompiler CF + read_memory field seal.
// Bit-for-bit vs retail EXE: DEFERRED (not run).
// =============================================================================

// PURPOSE:
//   thiscall on CSoundManager: if audio enabled and worldPos is zero-length OR
//   within fixed XZ radius (dist2 <= 10000), resolve a sound path, allocate a
//   ~0x160 queue slot, fill hardcoded mission-complete fields (type 0x32, TFID
//   unset, radius-like 100, param 20), and push onto manager list at +0x310.
//
//   Sibling of CSoundManager_TryQueueProximitySound_Inferred (0x007258a0) which
//   uses per-descriptor radius and copies descriptor fields.
//
// ABI: __thiscall; ret 8; returns 1 on queued, 0 on gate/resolve fail.
// Caller: FUN_004b0f80 (mission complete audio + Client_GetMissionCompleteAudioTable).

#include <cstdint>
#include <cstring>

// Externs (names from dual A/B seals / prior reviews)
extern float g_flZero;                 // 0x00a0f518 = 0.0f
extern float g_flOne;                  // 0x00a0f2a0 = 1.0f
extern float DAT_00aaa880;             // 0x00aaa880 = 10000.0f
extern float DAT_00aaa6e8;             // 0x00aaa6e8 = 20.0f
extern float DAT_00aaa7ac;             // 0x00aaa7ac = 100.0f
extern char  DAT_00d1a614;             // resolve flag byte (image-zero default)

extern char *FUN_007249c0(void *pathOrKey, char flag);  // ResolveSoundPath (simplified)
extern int   FUN_00480460();                             // freelist pop (slot size 0x160)
extern char *FUN_00480170();                             // SoundQueueSlot_InitTailFields
extern void  FUN_00480350(void *list_at_manager_plus_310);
extern float SQRT(float);
extern float ABS(float);

uint32_t __thiscall CSoundManager_TryQueueMissionCompleteSound_Inferred(
    int this_mgr,
    void *path_or_key,
    float *world_pos)
{
  float dx, dz;
  char *src;
  int popped;
  char *slot;

  // Gate: master enable at +0x258 (600)
  if (*(char *)(this_mgr + 600) == '\0') {
    return 0;
  }

  // Gate: fixed XZ proximity. Fail only when pos non-zero AND dist2 > 10000.
  if ((g_flZero < SQRT(world_pos[2] * world_pos[2] +
                       world_pos[1] * world_pos[1] +
                       world_pos[0] * world_pos[0])) &&
      (dx = *(float *)(this_mgr + 0x220) - world_pos[0],
       dz = *(float *)(this_mgr + 0x228) - world_pos[2],
       DAT_00aaa880 < ABS(dx * dx + dz * dz))) {
    return 0;
  }

  src = FUN_007249c0(path_or_key, DAT_00d1a614);
  if (src == nullptr) {
    return 0;
  }

  popped = FUN_00480460();
  if (popped == 0) {
    slot = nullptr;
  } else {
    slot = FUN_00480170();
  }

  // Note: retail strncpy even if slot null is decompiler-visible; treat as
  // "pop always succeeds in practice" residual — do not port blindly.
  std::strncpy(slot, src, 0x104);

  // TFID unset
  *(uint32_t *)(slot + 0x120) = 0xFFFFFFFFu;
  *(uint32_t *)(slot + 0x124) = 0xFFFFFFFFu;
  slot[0x128] = 0;
  slot[0x10b] = 0;
  slot[0x131] = 0;

  // type = 0x32 (50)
  *(uint32_t *)(slot + 0x104) = 0x32u;

  // float zeros (byte-seal via movss, not single-byte stores)
  *(float *)(slot + 0x150) = 0.0f;
  *(float *)(slot + 0x118) = 0.0f;
  *(float *)(slot + 0x154) = 0.0f;

  // hardcoded params (read_memory sealed)
  *(float *)(slot + 0x110) = DAT_00aaa6e8;  // 20.0f  (NOT g_nInferredThreatDefault)
  *(float *)(slot + 0x11c) = g_flOne;       // 1.0f
  *(float *)(slot + 0x114) = DAT_00aaa7ac;  // 100.0f

  FUN_00480350(reinterpret_cast<void *>(this_mgr + 0x310));
  return 1;
}

// Scaffold alias
uint32_t __thiscall FUN_00725a70(int this_mgr, void *path_or_key, float *world_pos)
{
  return CSoundManager_TryQueueMissionCompleteSound_Inferred(this_mgr, path_or_key, world_pos);
}
