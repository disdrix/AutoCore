// READABILITY (auto CF):
//  - Body size: ~42 non-empty decompiler lines.
//  - Control keywords: if×6, return×2.
//  - Notable callees: FUN_005b3300×2, CVOGHBList_ctor, FUN_00507ee0, GetTickCount, InitializeCriticalSectionAndSpinCount.
//  - Return sites: 2.

// =============================================================================
// CVOGHBList_ctor
// -----------------------------------------------------------------------------
// Purpose:  Construct map-owned heartbeat list: critical section, empty active + pending
//           buffers, zero counts.
//
// Address:  0x00507d10  (autoassault.exe, image base 0x400000)
// Stable:   aa_00507d10
// System:   heartbeat / timed-actions
//
// Layout: +0x04 CRITICAL_SECTION; +0x1c active buf; +0x20 active count;
//   +0x28 pending buf; +0x2c pending count; +0x30 pending capacity.
//
// Exactness: CF mirrors raw; names cleaned; no invented clamps.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Human-refined plate: 2026-07-23 (AI managers readability)
// =============================================================================

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */
uint32_t /* width from decompiler */ * __fastcall CVOGHBList_ctor(uint32_t /* width from decompiler */ *param_1)
{
  void *pvVar1;
  uint uVar2;
  int iVar3;
  
  *param_1 = &PTR_FUN_009cda94;
  param_1[9] = 0x80000000;
  param_1[7] = 0;
  param_1[8] = 0;
  param_1[0xc] = 0x80000000;
  param_1[10] = 0;
  param_1[0xb] = 0;
  uVar2 = param_1[9] & 0x7fffffff;
  if (uVar2 < 1000) {
    iVar3 = uVar2 * 2;
    if (uVar2 == 500 || iVar3 < 1000) {
      iVar3 = 1000;
    }
    FUN_005b3300(param_1 + 7,iVar3,4);
  }
  uVar2 = param_1[0xc] & 0x7fffffff;
  if (uVar2 < 100) {
    iVar3 = uVar2 * 2;
    if (uVar2 == 0x32 || iVar3 < 100) {
      iVar3 = 100;
    }
    FUN_005b3300(param_1 + 10,iVar3,4);
  }
  _DAT_00b041c0 = _DAT_00b041c0 + 1;
  g_dwClientTickMs = GetTickCount();
  InitializeCriticalSectionAndSpinCount((LPCRITICAL_SECTION)(param_1 + 1),4000);
  if ((DAT_00b041c8 == 0) && (DAT_00b041c4 != '\0')) {
    pvVar1 = operator_new(0x34);
    if (pvVar1 != (void *)0x0) {
      DAT_00b041c8 = FUN_00507ee0(4);
      return param_1;
    }
    DAT_00b041c8 = 0;
  }
  return param_1;
}
