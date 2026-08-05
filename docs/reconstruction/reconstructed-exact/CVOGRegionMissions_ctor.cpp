// =============================================================================
// CVOGRegionMissions_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct the 0x10 region-missions wrapper: four hash tables and
//           populate from preload vector or DB cold load of mission defs.
//
// Address:  0x0060b870  (autoassault.exe, image base 0x400000)
// Body:     0x0060b870–0x0060bb77 (0x308 bytes)
// Stable:   aa_0060b870
// System:   missions-progression
// Ghidra:   FUN_0060b870
// Product:  .../libVOG/VOGRegionMissions.cpp  ("Out-o-memory... missions!")
//
// ABI:      __fastcall  CVOGRegionMissions* CVOGRegionMissions_ctor(this)
//           ECX = this (0x10); returns this in EAX; SEH frame
//
// Does NOT: allocate the 0x10 block or store at owner+0xf18 — callers do
//           operator_new(0x10) then this ctor (e.g. Mission_EnsureRegionMissions).
//
// Exactness: CF mirrors raw + read_memory; names cleaned where sealed.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W17-B seal).
// =============================================================================

/* Layout of this (0x10):
     +0x00  CNDHash*  primary mission-id table     (new 0x34 + FUN_0053b0b0(8))
     +0x04  CNDHash*  objective-id table           (new 0x34 + FUN_0053b1b0(8))
     +0x08  hash*     extended index A (0x38)      (vtbl PTR_FUN_009df688)
     +0x0C  hash*     extended index B (0x38)      (same shape)
*/

typedef struct CVOGRegionMissions {
  void *pMissionById;       /* +0x00 */
  void *pObjectiveById;     /* +0x04 */
  void *pIndexA;            /* +0x08 — key def[+0x88] when != -1 */
  void *pIndexB;            /* +0x0C — key byte def[+0x86] */
} CVOGRegionMissions;

/* External callees (not owned here) */
void *operator_new(unsigned size);
void *FUN_0053b0b0(int maskBits);              /* CNDHash-style ctor, bits=8 */
void *FUN_0053b1b0(int maskBits);              /* objective-hash ctor variant */
void FUN_0053c360(void *hash, unsigned key, void *value, int soft);
void FUN_0053c460(void *hash, unsigned key, void *value, int soft);
void FUN_0060c010(void *hash, unsigned key, void *value);
void *FUN_005480d0(void *dbRow, int flag);
int  FUN_007e1d80(void);                       /* DB enter */
void FUN_007c0350(int *outCount, void **outRows);
void FUN_007b7df0(void);                       /* DB leave */
void FUN_007a4480(int level, char const *msg);
void vog_LogMessage(char const *file, int line, int level, char const *msg);
void CoTaskMemFree(void *p);
void _CxxThrowException(void *pExceptionObject, void *pThrowInfo);

extern void *DAT_00b0434c;   /* preload mission-def* vector begin */
extern void *DAT_00b04350;   /* preload vector end */
extern void *ExceptionList;
extern void *LAB_009a8327;
extern void *PTR_FUN_009df688;
extern void *DAT_00acc430;

CVOGRegionMissions *__fastcall CVOGRegionMissions_ctor(CVOGRegionMissions *this)
{
  int iVar1;
  int usePreload;
  int iVar3;
  unsigned *puVar4;
  int iVar5;
  void *local_18;     /* db row array */
  int local_14;       /* count */
  unsigned *local_10;
  void *pvStack_c;
  unsigned char *puStack_8;
  unsigned uStack_4;

  /* SEH prolog (exact frame setup omitted as raw MSVC boilerplate) */
  uStack_4 = 0xffffffff;
  puStack_8 = (unsigned char *)&LAB_009a8327;
  pvStack_c = ExceptionList;
  local_14 = 0;
  local_18 = (void *)0x0;
  usePreload = 0;

  if ((DAT_00b0434c == 0) ||
      (iVar3 = ((int)DAT_00b04350 - (int)DAT_00b0434c) >> 2, iVar3 == 0)) {
    ExceptionList = &pvStack_c;
    local_10 = (unsigned *)FUN_007e1d80();
    if ((int)local_10 < 0) {
      FUN_007a4480(0, "VOG_DEBUG_STOP");
      /* WARNING: Subroutine does not return */
      _CxxThrowException(&local_10, (void *)&DAT_00acc430);
    }
    FUN_007c0350(&local_14, &local_18);
    FUN_007b7df0();
  }
  else {
    usePreload = 1;
    ExceptionList = &pvStack_c;
    local_14 = iVar3;
  }

  /* this[0] primary mission-id hash */
  local_10 = (unsigned *)operator_new(0x34);
  uStack_4 = 0;
  if (local_10 == (unsigned *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)FUN_0053b0b0(8);
  }
  uStack_4 = 0xffffffff;
  this->pMissionById = (void *)iVar3;

  /* this[1] objective hash */
  local_10 = (unsigned *)operator_new(0x34);
  uStack_4 = 1;
  if (local_10 == (unsigned *)0x0) {
    iVar3 = 0;
  }
  else {
    iVar3 = (int)FUN_0053b1b0(8);
  }
  uStack_4 = 0xffffffff;
  this->pObjectiveById = (void *)iVar3;

  /* this[2] extended index A */
  puVar4 = (unsigned *)operator_new(0x38);
  uStack_4 = 2;
  local_10 = puVar4;
  if (puVar4 == (unsigned *)0x0) {
    puVar4 = (unsigned *)0x0;
  }
  else {
    FUN_0053b0b0(8);
    *(void **)puVar4 = &PTR_FUN_009df688;
    puVar4[0xd] = 0; /* +0x34 */
  }
  uStack_4 = 0xffffffff;
  this->pIndexA = (void *)puVar4;

  /* this[3] extended index B */
  puVar4 = (unsigned *)operator_new(0x38);
  uStack_4 = 3;
  local_10 = puVar4;
  if (puVar4 == (unsigned *)0x0) {
    puVar4 = (unsigned *)0x0;
  }
  else {
    FUN_0053b0b0(8);
    *(void **)puVar4 = &PTR_FUN_009df688;
    puVar4[0xd] = 0;
  }
  uStack_4 = 0xffffffff;
  this->pIndexB = (void *)puVar4;

  if ((((this->pMissionById == 0) || (this->pObjectiveById == 0)) ||
       (this->pIndexA == 0)) || (puVar4 == (unsigned *)0x0)) {
    vog_LogMessage(
        "C:\\vog\\1_code\\vog_14_117_branch\\libVOG\\VOGRegionMissions.cpp",
        0x33, 3, "Out-o-memory... missions!");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }

  if (local_14 != 0) {
    iVar3 = 0;
    if (0 < local_14) {
      do {
        iVar5 = 0;
        if (usePreload) {
          puVar4 = *(unsigned **)((char *)DAT_00b0434c + iVar3 * 4);
        }
        else {
          local_10 = (unsigned *)operator_new(0x170);
          uStack_4 = 4;
          if (local_10 == (unsigned *)0x0) {
            uStack_4 = 0xffffffff;
            puVar4 = (unsigned *)0x0;
          }
          else {
            puVar4 = (unsigned *)FUN_005480d0(
                *(void **)((char *)local_18 + iVar3 * 4), 1);
            uStack_4 = 0xffffffff;
          }
        }

        /* primary: this[0], key = *def */
        FUN_0053c360(this->pMissionById, *puVar4, puVar4, 0);

        /* index A: this[2], key = def[+0x88] if != -1 */
        if (puVar4[0x22] != (unsigned)-1) {
          FUN_0060c010(this->pIndexA, puVar4[0x22], puVar4);
        }

        /* index B: this[3], key = byte def[+0x86] */
        FUN_0060c010(this->pIndexB,
                     *(unsigned char *)((char *)puVar4 + 0x86), puVar4);

        /* objectives: this[1], count at def[+0x130], table at def[+0x13c] */
        if (*(char *)(puVar4 + 0x4c) != '\0') {
          do {
            iVar1 = *(int *)(puVar4[0x4f] + iVar5 * 4);
            FUN_0053c460(this->pObjectiveById,
                         *(unsigned *)(iVar1 + 0x10), (void *)iVar1, 0);
            iVar5 = iVar5 + 1;
          } while (iVar5 < (int)(unsigned)*(unsigned char *)(puVar4 + 0x4c));
        }

        if (!usePreload) {
          iVar5 = 0;
          if (*(char *)(puVar4 + 0x4c) != '\0') {
            do {
              CoTaskMemFree(
                  *(void **)(*(int *)(*(int *)((char *)local_18 + iVar3 * 4) +
                                      0x134) +
                             iVar5 * 4));
              iVar5 = iVar5 + 1;
            } while (iVar5 <
                     (int)(unsigned)*(unsigned char *)(puVar4 + 0x4c));
          }
          CoTaskMemFree(
              *(void **)(*(int *)((char *)local_18 + iVar3 * 4) + 0x134));
          CoTaskMemFree(*(void **)((char *)local_18 + iVar3 * 4));
        }
        iVar3 = iVar3 + 1;
      } while (iVar3 < local_14);
    }
    if (!usePreload) {
      CoTaskMemFree(local_18);
    }
  }

  ExceptionList = pvStack_c;
  return this;
}
