// =============================================================================
// CVOGRegionMissions_ResyncMissionObjectives_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Look up a mission def by id in the region-missions primary hash,
//           cold-load catalog rows, and if the matching row's objective set
//           differs, strip + re-insert objective hash nodes (and always
//           materialize via FUN_00546e40).
//
// Address:  0x0060bb80  (autoassault.exe, image base 0x400000)
// Body:     0x0060bb80-0x0060be1e (exclusive end; ret 4)
// Stable:   aa_0060bb80
// System:   missions-progression
// Ghidra:   FUN_0060bb80
// Canonical: CVOGRegionMissions_ResyncMissionObjectives_Inferred
// Product:  sibling of CVOGRegionMissions_ctor in VOGRegionMissions.cpp
//
// ABI:      uint8_t __thiscall (CVOGRegionMissions *this, uint missionId)
//           ECX = this; ret 4; AL = status (0 = miss/no-op)
//
// Layout (from ctor dual aa_0060b870):
//   +0x00  CNDHash* pMissionById
//   +0x04  CNDHash* pObjectiveById
//   +0x08  index A
//   +0x0C  index B
//
// Exactness: CF mirrors live decompile + entry/epilogue read_memory.
//            DB helper stack recovery is lossy in decompiler (noted).
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W24-L).
// =============================================================================

#include <stdint.h>
#include <windows.h>

typedef struct CVOGRegionMissions {
  void *pMissionById;   /* +0x00 */
  void *pObjectiveById; /* +0x04 */
  void *pIndexA;        /* +0x08 */
  void *pIndexB;        /* +0x0C */
} CVOGRegionMissions;

void *CNDHash_LookupByKey(void *hash, uint32_t key);
int  FUN_007e1d80(void);
void FUN_007c0350(int *a, void **b);
void FUN_007b7df0(void);
void FUN_007a4480(int level, char const *msg);
void FUN_00537d30(void);
void FUN_00546e40(void *row /* + residual args */);
int  FUN_0053c460(void *hash, uint32_t key, void *value, char soft); /* CNDHash_Insert */
void CoTaskMemFree(void *p);

extern void *PTR_FUN_009cf02c; /* hash node vtbl; method0 = 0x00537d10 */

uint8_t __thiscall CVOGRegionMissions_ResyncMissionObjectives_Inferred(
    CVOGRegionMissions *self, uint32_t missionId)
{
  void *missionDef;
  uint32_t *savedSelf;
  void *rowArray;          /* decompiler: unaff_EBX */
  int rowCount;            /* decompiler: iStack_c */
  int i;
  uint32_t flags;
  uint8_t status;
  int matchKey;            /* decompiler: local_4 — catalog match key residual */

  if (self->pMissionById == 0 ||
      (savedSelf = (uint32_t *)self,
       missionDef = CNDHash_LookupByKey(self->pMissionById, missionId),
       missionDef == 0)) {
    return 0;
  }

  FUN_007e1d80();
  FUN_007c0350(&matchKey, (void **)&rowArray); /* out-param pairing residual */
  FUN_007b7df0();

  flags = 0;
  status = 0;
  i = 0;
  /* rowCount / rowArray filled by DB helpers — decompiler stack lossy */
  if (rowCount > 0) {
    do {
      int *row = *(int **)((char *)rowArray + i * 4);
      if (*row == matchKey) {
        uint8_t nObj = *(uint8_t *)((char *)missionDef + 0x130);
        flags = ((uint32_t)nObj << 24) | (flags & 0xffff0000);

        if (*(uint8_t *)(row + 0x4c) == nObj) {
          uint32_t n = nObj;
          if (n != 0) {
            int *catObjs = (int *)row[0x4d];
            int delta = *(int *)((char *)missionDef + 0x13c) - (int)catObjs;
            do {
              if (*(int *)(*(int *)catObjs + 4) !=
                  *(int *)(*(int *)(delta + (int)catObjs) + 0x10)) {
                flags = (flags & 0xffff0000) | 0x100;
              }
              catObjs += 1;
              n -= 1;
            } while (n != 0);
            if ((char)(flags >> 8) != 0) {
              nObj = (uint8_t)(flags >> 24);
              goto mismatch;
            }
          }
        } else {
          flags = 0x100;
        mismatch:
          flags = (1u << 16) | (flags & 0xffff);
          {
            int j = 0;
            if (nObj != 0) {
              do {
                /* objective hash at *(region + 4) — decompiler iStack_10+4 */
                void *objHash = self->pObjectiveById;
                uint32_t key =
                    *(uint32_t *)(*(int *)(*(int *)((char *)missionDef + 0x13c) +
                                           j * 4) +
                                  0x10);
                if (*(char *)((char *)objHash + 0x1d) != 0) {
                  FUN_007a4480(0, "HashError:remove, already locked for traversal");
                  FUN_007a4480(0, "VOG_DEBUG_STOP");
                }
                /* inline bucket unlink by key + freelist push (vtbl 009cf02c) */
                /* ... body matches raw remove loop ... */
                FUN_00537d30();
                j += 1;
              } while (j < (int)nObj);
            }
          }
        }

        FUN_00546e40(row);

        if (((char)(flags >> 8) != 0) &&
            (*(char *)((char *)missionDef + 0x130) != 0)) {
          int j = 0;
          do {
            int obj = *(int *)(*(int *)((char *)missionDef + 0x13c) + j * 4);
            FUN_0053c460(self->pObjectiveById, *(uint32_t *)(obj + 0x10),
                         (void *)obj, 0);
            j += 1;
          } while (j < (int)*(uint8_t *)((char *)missionDef + 0x130));
        }
      }

      /* free catalog row objective table + row (uses def count for loop bound) */
      {
        int j = 0;
        if (*(char *)((char *)missionDef + 0x130) != 0) {
          do {
            CoTaskMemFree(
                *(void **)(*(int *)((char *)row + 0x134) + j * 4));
            j += 1;
          } while (j < (int)*(uint8_t *)((char *)missionDef + 0x130));
        }
        CoTaskMemFree(*(void **)((char *)row + 0x134));
        CoTaskMemFree(row);
      }
      status = (uint8_t)(flags >> 16);
      i += 1;
    } while (i < rowCount);
  }

  CoTaskMemFree(rowArray);
  return status;
}

/* Ghidra scaffold alias */
uint8_t __thiscall FUN_0060bb80(uint32_t *param_1, uint32_t param_2)
{
  return CVOGRegionMissions_ResyncMissionObjectives_Inferred(
      (CVOGRegionMissions *)param_1, param_2);
}
