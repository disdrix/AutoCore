// =============================================================================
// stoChunkStream_ReadBytes_Inferred  (Ghidra: FUN_00435f30)
// -----------------------------------------------------------------------------
// Stable ID: aa_00435f30
// Address:   0x00435f30 – 0x00435fdd  (autoassault.exe, image base 0x400000)
// System:    sto-chunk / asset serialize stream helper
// Generated: 2026-07-29 W18-Q OWN-ONLY dual (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Bulk byte read from the stoChunk stream shell (host often reader+0x14).
 * ABI: __thiscall; stack dest*, byteCount; ret 8.
 * Returns 0 on success, 0xFFFFFFFF if FUN_00435df0 refill fails.
 * Direct-IO path uses interface vtbl +4 then +0x14 (see review A/B).
 * Decompiler residual: second vtbl arg may appear as unaff_EBX; bytes use dest.
 */

#include <stdint.h>

typedef uint32_t (*stream_vtbl_fn)(void *a, void *b);

uint32_t __thiscall stoChunkStream_ReadBytes_Inferred(
    uint32_t *param_1 /* this stream shell */,
    uint32_t *param_2 /* dest */,
    uint32_t param_3 /* byte count */)
{
  int iVar1;
  uint32_t uVar2;
  int iVar3;
  uint32_t uVar4;
  uint32_t unaff_EBX; /* decompiler artifact on direct path; asm uses dest */
  uint32_t *puVar5;

  iVar3 = (int)param_1[1]; /* cursor +4 */
  iVar1 = (int)param_1[3]; /* avail  +0xC */
  if (iVar1 < (int)(iVar3 + param_3)) {
    if ((int)param_1[4] /* maxChunk +0x10 */ < (int)param_3) {
      if (iVar3 < iVar1) {
        uVar2 = (uint32_t)(iVar1 - iVar3);
        puVar5 = (uint32_t *)(iVar3 + 0x18 + (int)param_1);
        for (uVar4 = uVar2 >> 2; uVar4 != 0; uVar4 = uVar4 - 1) {
          *param_2 = *puVar5;
          puVar5 = puVar5 + 1;
          param_2 = param_2 + 1;
        }
        for (uVar4 = uVar2 & 3; uVar4 != 0; uVar4 = uVar4 - 1) {
          *(uint8_t *)param_2 = *(uint8_t *)puVar5;
          puVar5 = (uint32_t *)((int)puVar5 + 1);
          param_2 = (uint32_t *)((int)param_2 + 1);
        }
        param_1[1] = param_1[1] + uVar2;
        param_3 = param_3 - uVar2;
      }
      /* vtbl+4(base+cursor, 0); vtbl+0x14(dest, rem) — dest advanced in asm */
      (*(stream_vtbl_fn *)(*(int *)*param_1 + 4))(
          (void *)(param_1[2] + param_1[1]), (void *)0);
      (*(stream_vtbl_fn *)(*(int *)*param_1 + 0x14))((void *)(uintptr_t)unaff_EBX,
                                                     (void *)(uintptr_t)param_3);
      param_1[1] = param_1[1] + param_3;
      return 0;
    }
    iVar3 = FUN_00435df0(param_1[2] + iVar3);
    if (iVar3 < 0) {
      return 0xffffffff;
    }
  }
  puVar5 = (uint32_t *)((int)param_1 + (int)param_1[1] + 0x18);
  for (uVar2 = param_3 >> 2; uVar2 != 0; uVar2 = uVar2 - 1) {
    *param_2 = *puVar5;
    puVar5 = puVar5 + 1;
    param_2 = param_2 + 1;
  }
  for (uVar2 = param_3 & 3; uVar2 != 0; uVar2 = uVar2 - 1) {
    *(uint8_t *)param_2 = *(uint8_t *)puVar5;
    puVar5 = (uint32_t *)((int)puVar5 + 1);
    param_2 = (uint32_t *)((int)param_2 + 1);
  }
  param_1[1] = param_1[1] + param_3;
  return 0;
}

/* Ghidra leave-name alias */
uint32_t __thiscall FUN_00435f30(uint32_t *param_1, uint32_t *param_2, uint32_t param_3)
{
  return stoChunkStream_ReadBytes_Inferred(param_1, param_2, param_3);
}

/* external */
int __thiscall FUN_00435df0(uint32_t base_plus_cursor);
