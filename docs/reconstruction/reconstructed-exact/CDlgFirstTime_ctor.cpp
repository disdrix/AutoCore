// =============================================================================
// CDlgFirstTime_ctor
// -----------------------------------------------------------------------------
// Stable ID: aa_008dd590
// Address:   0x008dd590  (autoassault.exe, image base 0x400000)
// Body:      0x008dd590–0x008dd66a
// System:    client-ui / first-time-tips
// Generated: 2026-07-29 dual A/B (force_decompile + callers + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================
//
// PURPOSE:
//   Construct CDlgFirstTime (first-time tip dialog). Size 0x5B0 (both callers
//   operator_new(0x5b0)). Base dialog → class vtbl PTR_FUN_00a3d8b4 → zero
//   tip/widget slots → empty list head at +0x54c → defaults → bulk zero →
//   load "i_d_first.xml". Returns this. No network I/O in this body.
//
// CALLEES:
//   FUN_0087b890(this, 0)     base dialog/window ctor (vtbl PTR_FUN_00a58c6c)
//   FUN_0040fb90()            operator_new(0xc) circular empty list/set head
//   FUN_008dc1f0()            bulk zero tip-specific fields (ECX=this)
//   FUN_008dc970(this, path)  NDUIWindow_ReloadInterface + layout hooks
//
// CALLERS:
//   Client_MaybeShowFirstTimeTip (0x00801760) → client+0x1164
//   FUN_008c40a0 (0x008c40a0) → DAT_00d1b9a4
//
// VTABLE: PTR_FUN_00a3d8b4 @ 0x00a3d8b4
//   slot0 = FUN_0040fd30 (scalar deleting dtor → FUN_008dd500)
//

#include <cstdint>

extern "C" void* ExceptionList;
extern "C" std::uint8_t LAB_009b709b[];
extern "C" void* PTR_FUN_00a3d8b4[];

extern "C" std::uint32_t* FUN_0087b890(std::uint32_t* self, std::uint32_t param);
extern "C" std::uint32_t FUN_0040fb90(void);
extern "C" void FUN_008dc1f0(/* ECX = this */);
extern "C" void FUN_008dc970(std::uint32_t* self, const char* path);

// CONCAT31(hi3, lo): decompiler SEH state helper
static inline std::uint32_t CONCAT31(std::uint32_t hi3, std::uint8_t lo)
{
  return (hi3 << 8) | lo;
}

std::uint32_t* CDlgFirstTime_ctor(std::uint32_t* param_1)
{
  std::uint32_t uVar1;
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009b709b[0];
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_0087b890(param_1, 0);
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_00a3d8b4);
  param_1[0x14e] = 0; // +0x538
  param_1[0x14f] = 0; // +0x53c
  param_1[0x150] = 0; // +0x540
  param_1[0x151] = 0; // +0x544

  // local_4 low = 2, high cleared (decompiler local_4._0_1_ / ._1_3_)
  local_4 = 2;

  uVar1 = FUN_0040fb90();
  param_1[0x153] = uVar1; // +0x54c list head
  param_1[0x154] = 0;     // +0x550

  local_4 = CONCAT31(local_4 >> 8, 3);

  param_1[0x13f] = 0x0f;                         // +0x4fc
  param_1[0x140] = 1;                            // +0x500
  param_1[0x14b] = 0xffffffff;                   // +0x52c
  param_1[0x14c] = 0;                            // +0x530
  *reinterpret_cast<std::uint8_t*>(param_1 + 0x146) = 0; // +0x518
  *reinterpret_cast<std::uint8_t*>(
      reinterpret_cast<char*>(param_1) + 0x519) = 0;
  param_1[0x143] = 0; // +0x50c
  param_1[0x144] = 0; // +0x510
  param_1[0x145] = 0; // +0x514

  FUN_008dc1f0();
  FUN_008dc970(param_1, "i_d_first.xml");

  ExceptionList = local_c;
  return param_1;
}
