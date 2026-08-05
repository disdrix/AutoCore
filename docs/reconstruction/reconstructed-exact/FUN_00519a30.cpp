// =============================================================================
// FUN_00519a30 / VehiclePaintColor_EnsureTableLoaded_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00519a30
// Address:   0x00519a30 – 0x00519d1a  (autoassault.exe, image base 0x400000)
// System:    vehicle paint / tint
// Generated: 2026-07-29 (W16-D dual seal; replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Rebuild global vehicle paint-color CNDHash (DAT_00b042ac family) from
//   DB/XML vColorBiomek / vColorHuman / vColorMutant row sets via FUN_007c9230.
//   Lazy-called when DAT_00b042b8 < 1 (see VehiclePaintColor_LookupById @ 0x00519d20).
//
// ABI: __cdecl void; SEH frame LAB_009a36a5.
//
// Row: 0x0C = { IDColor, intRGBColor, intWorth }  (from loader plate strings)
// Payload: 0x10 block; Lookup returns *(uint32*)payload (== intRGBColor).
//
// Decompiler notes preserved:
//  - operator_delete "noreturn" = SEH artifact
//  - ExceptionList = local_20 on exit is decompiler mis-bind; real restore is SEH slot

#include <stdint.h>

/* externs — retail symbols / prior duals */
extern void *ExceptionList;
extern uint8_t DAT_00b042ac[];          /* paint color CNDHash object */
extern uint32_t DAT_00b042b4;           /* hash mask (hash+0x08) */
extern uint32_t *DAT_00b042bc;          /* bucket table (hash+0x10) */
extern void *DAT_00b0469c;              /* DBReader* global */

void FUN_0051d1d0(void *hash, uint8_t power);           /* CNDHash_Recreate */
uint32_t FUN_0051e3d0(void *hash, uint32_t key, void *payload, char flag);
void FUN_0051d430(void *map, void *outIt, int *key);    /* map insert (thiscall) */
uint32_t FUN_007e1d80(void *dbReader);                  /* PrepareDataConnection */
uint32_t FUN_007b7df0(void *dbReader);                  /* ReleaseDataConnection */
void FUN_007c9230(void *dbReader, void *vec0, void *vec1, void *vec2);
void *operator_new(unsigned size);
void operator_delete(void *p);

void FUN_00519a30(void)
{
  uint32_t *puVar1;
  int iVar2;
  uint32_t uVar3;
  uint32_t *puVar4;
  uint32_t uVar5;
  void *pvStack_50;
  int iStack_4c;
  uint32_t local_48;
  uint32_t local_44;
  void *local_40;
  int local_3c;
  uint32_t local_38;
  uint32_t local_34;
  void *local_30;
  int local_2c;
  uint8_t local_28[4];
  uint32_t local_24;
  void *local_20;
  uint32_t local_1c;
  void *pvStack_14;
  uint8_t *puStack_10;
  uint32_t local_c;

  local_c = 0xffffffff;
  puStack_10 = (uint8_t *)0x009a36a5; /* LAB_009a36a5 */
  pvStack_14 = ExceptionList;
  ExceptionList = &pvStack_14;

  /* ECX = &DAT_00b042ac; push 4 — recreate hash with 2^4 buckets */
  FUN_0051d1d0((void *)DAT_00b042ac, 4);

  uVar3 = 0;
  local_24 = 0;
  local_20 = (void *)0x0;
  local_1c = 0;
  local_44 = 0;
  local_40 = (void *)0x0;
  local_3c = 0;
  local_34 = 0;
  local_30 = (void *)0x0;
  local_2c = 0;
  local_c = 2;

  FUN_007e1d80(DAT_00b0469c);
  FUN_007c9230(DAT_00b0469c, local_28, &local_48, &local_38);
  FUN_007b7df0(DAT_00b0469c);

  /* Phase 1: vector at local_30 — always insert */
  puVar4 = (uint32_t *)((int)local_30 + 8);
  for (uVar5 = 0;
       (local_30 != (void *)0x0 &&
        (uVar5 < (uint32_t)((local_2c - (int)local_30) / 0xc)));
       uVar5 = uVar5 + 1) {
    puVar1 = (uint32_t *)operator_new(0x10);
    *puVar1 = puVar4[-1];       /* intRGBColor */
    puVar1[1] = *puVar4;        /* intWorth → payload+4 */
    FUN_0051e3d0((void *)DAT_00b042ac, puVar4[-2], puVar1, 0); /* key=IDColor */
    FUN_0051d430(/*map this*/, /*out*/, /*key*/);
    puVar4 = puVar4 + 3;
  }

  /* Phase 2: vector pvStack_50 — lookup; miss insert RGB+Worth@+8; hit update +8 */
  puVar4 = (uint32_t *)((int)pvStack_50 + 8);
  uVar5 = 0;
  do {
    if ((pvStack_50 == (void *)0x0) ||
        ((uint32_t)((iStack_4c - (int)pvStack_50) / 0xc) <= uVar5)) {
      /* Phase 3: vector local_40 — lookup; miss insert RGB+Worth@+0xC; hit update +0xC */
      puVar4 = (uint32_t *)((int)local_40 + 8);
      do {
        if (local_40 == (void *)0x0) {
          local_40 = (void *)0x0;
          local_3c = 0;
          local_38 = 0;
          if (pvStack_50 != (void *)0x0) {
            /* WARNING: decompiler marks noreturn — SEH artifact */
            operator_delete(pvStack_50);
          }
          local_48 = 0;
          if (local_30 != (void *)0x0) {
            operator_delete(local_30);
          }
          /* Real code restores ExceptionList from SEH frame, not local_20 */
          ExceptionList = pvStack_14;
          return;
        }
        if ((uint32_t)((local_3c - (int)local_40) / 0xc) <= uVar3) {
          operator_delete(local_40);
        }
        iVar2 = *(int *)(*(int *)((uint8_t *)DAT_00b042bc +
                                  (puVar4[-2] & DAT_00b042b4) * 4) + 4);
        if (iVar2 == 0) {
LAB_00519c56:
          iVar2 = 0;
        } else {
          do {
            if (puVar4[-2] == *(uint32_t *)(iVar2 + 0x10)) {
              if (iVar2 == 0) goto LAB_00519c56;
              iVar2 = *(int *)(iVar2 + 8); /* payload* */
              goto LAB_00519c5d;
            }
            iVar2 = *(int *)(iVar2 + 0xc);
          } while (iVar2 != 0);
          iVar2 = 0;
        }
LAB_00519c5d:
        if (iVar2 == 0) {
          puVar1 = (uint32_t *)operator_new(0x10);
          *puVar1 = puVar4[-1];
          puVar1[3] = *puVar4; /* Worth → +0xC */
          FUN_0051e3d0((void *)DAT_00b042ac, puVar4[-2], puVar1, 0);
        } else {
          *(uint32_t *)(iVar2 + 0xc) = *puVar4;
        }
        FUN_0051d430(/*map this*/, /*out*/, /*key*/);
        uVar3 = uVar3 + 1;
        puVar4 = puVar4 + 3;
      } while (1);
    }

    iVar2 = *(int *)(*(int *)((uint8_t *)DAT_00b042bc +
                              (puVar4[-2] & DAT_00b042b4) * 4) + 4);
    if (iVar2 == 0) {
LAB_00519b95:
      iVar2 = 0;
    } else {
      do {
        if (puVar4[-2] == *(uint32_t *)(iVar2 + 0x10)) {
          if (iVar2 == 0) goto LAB_00519b95;
          iVar2 = *(int *)(iVar2 + 8);
          goto LAB_00519b9c;
        }
        iVar2 = *(int *)(iVar2 + 0xc);
      } while (iVar2 != 0);
      iVar2 = 0;
    }
LAB_00519b9c:
    if (iVar2 == 0) {
      puVar1 = (uint32_t *)operator_new(0x10);
      *puVar1 = puVar4[-1];
      puVar1[2] = *puVar4; /* Worth → +8 */
      FUN_0051e3d0((void *)DAT_00b042ac, puVar4[-2], puVar1, 0);
    } else {
      *(uint32_t *)(iVar2 + 8) = *puVar4;
    }
    FUN_0051d430(/*map this*/, /*out*/, /*key*/);
    uVar5 = uVar5 + 1;
    puVar4 = puVar4 + 3;
  } while (1);
}
