// =============================================================================
// FUN_00720a40 / CSoundManager_Ctor (inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00720a40
// Address:   0x00720a40  (autoassault.exe, image base 0x400000)
// Body:      0x00720a40–0x00720b44  (ret 4)
// System:    client audio / CSoundManager
// Generated: 2026-07-29 W16-N dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler/machine CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (static image body sealed).
// =============================================================================
//
// PURPOSE:
//   In-place init of CSoundManager storage. Sole caller:
//     CSoundManager_GetInstance (0x00720d40) → FUN_00720a40(&DAT_00d20070) once.
//
//   - Zero/flag many early fields
//   - this+0x20 / +0x24 = DAT_00aaa668 (−1.0f)
//   - Zero 0x32 dwords at +0x90 (fills through +0x157)
//   - InitializeCriticalSection at +0x158 and +0x170
//   - Header flags: [0]=1, [1]=0, +4/+8 = 0
//   - Return this
// =============================================================================

#include <stdint.h>
#include <windows.h>

// Shared float constant (image 0x00aaa668): bits 0xbf800000 == -1.0f
extern "C" float DAT_00aaa668;
// MSVC EH symbols present in image; not reimplemented here.
extern "C" void *ExceptionList;
extern "C" void LAB_009abdd9(void);

extern "C" uint8_t * __stdcall FUN_00720a40(uint8_t *param_1)
{
  float uVar1;
  int iVar2;
  uint32_t *puVar3;
  void *local_c;
  uint8_t *puStack_8;
  uint32_t uStack_4;

  // SEH frame (faithful to decomp / prologue bytes)
  uVar1 = DAT_00aaa668;                 // -1.0f
  uStack_4 = 0xffffffff;
  puStack_8 = (uint8_t *)&LAB_009abdd9;
  local_c = ExceptionList;
  ExceptionList = &local_c;

  *(uint32_t *)(param_1 + 0xc) = 0;
  param_1[0x10] = 1;
  param_1[0x11] = 0;
  param_1[0x12] = 0;
  param_1[0x13] = 0;
  param_1[0x14] = 0;
  param_1[0x15] = 0;
  param_1[0x16] = 0;
  param_1[0x17] = 0;
  param_1[0x19] = 1;
  *(uint32_t *)(param_1 + 0x1c) = 0;              // 0.0f bits
  *(float *)(param_1 + 0x20) = uVar1;             // -1.0f
  *(float *)(param_1 + 0x24) = uVar1;             // -1.0f
  *(uint32_t *)(param_1 + 0x28) = 0;
  *(uint32_t *)(param_1 + 0x30) = 0;
  *(uint32_t *)(param_1 + 0x34) = 0;
  *(uint32_t *)(param_1 + 0x38) = 0;
  *(uint32_t *)(param_1 + 0x3c) = 0;
  *(uint32_t *)(param_1 + 0x44) = 0;
  *(uint32_t *)(param_1 + 0x48) = 0;
  *(uint32_t *)(param_1 + 0x4c) = 0;
  *(uint32_t *)(param_1 + 0x54) = 0;
  *(uint32_t *)(param_1 + 0x58) = 0;
  *(uint32_t *)(param_1 + 0x5c) = 0;
  *(uint32_t *)(param_1 + 0x64) = 0;              // decomp "100"
  *(uint32_t *)(param_1 + 0x68) = 0;
  *(uint32_t *)(param_1 + 0x6c) = 0;
  *(uint32_t *)(param_1 + 0x74) = 0;
  *(uint32_t *)(param_1 + 0x78) = 0;
  *(uint32_t *)(param_1 + 0x7c) = 0;
  *(uint32_t *)(param_1 + 0x188) = 0;
  *(uint32_t *)(param_1 + 0x80) = 0;
  *(uint32_t *)(param_1 + 0x84) = 0;
  *(uint32_t *)(param_1 + 0x88) = 0;
  *(uint32_t *)(param_1 + 0x8c) = 0;

  // 0x32 dwords from +0x90 → ends at +0x158 (first CRITICAL_SECTION)
  puVar3 = (uint32_t *)(param_1 + 0x90);
  for (iVar2 = 0x32; iVar2 != 0; iVar2 = iVar2 + -1) {
    *puVar3 = 0;
    puVar3 = puVar3 + 1;
  }

  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x158));
  InitializeCriticalSection((LPCRITICAL_SECTION)(param_1 + 0x170));

  param_1[1] = 0;
  *param_1 = 1;
  *(uint32_t *)(param_1 + 4) = 0;
  *(uint32_t *)(param_1 + 8) = 0;

  ExceptionList = local_c;
  return param_1;
}
