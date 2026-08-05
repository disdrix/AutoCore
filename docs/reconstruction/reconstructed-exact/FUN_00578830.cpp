// =============================================================================
// FUN_00578830  (scaffold alias → CVOGHBSkillBase_DefaultCtor)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578830
// Address:   0x00578830  (autoassault.exe, image base 0x400000)
// Body:      0x00578830–0x005788c8 (152 bytes)
// System:    skills-abilities / heartbeat
// Generated: 2026-07-23 scaffold; refined 2026-07-29 W23-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
// Canonical clean: CVOGHBSkillBase_DefaultCtor.cpp
// =============================================================================

// PURPOSE: Empty CVOGHBSkillBase shell (RTTI vtbl PTR_FUN_009d3fdc); factories
//          overwrite subclass vtbl after this returns.
// READABILITY: control flow preserved from Ghidra decompile; names cleaned.

#include <cstdint>

extern void* ExceptionList;
extern void  CVOGHBBase_ctor(void* self);
extern void  FUN_0054f3c0(void);
extern void  CVOGHBBase_AttachOwnerObject(void* hb, void* owner);
extern std::uint32_t DAT_009d3f88;
extern std::uint32_t DAT_009d3f8c;
extern std::uint32_t DAT_009d3f90;
extern std::uint32_t DAT_009d3f94;
extern void* PTR_FUN_009d3fdc;
extern std::uint8_t LAB_009a51f8;

std::uint32_t* __fastcall FUN_00578830(std::uint32_t* param_1)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = &LAB_009a51f8;
  local_c = ExceptionList;
  ExceptionList = &local_c;
  CVOGHBBase_ctor(param_1);
  local_4 = 0;
  *param_1 = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d3fdc);
  FUN_0054f3c0(); /* ECX = param_1+0x24 */
  param_1[0x1ac] = 0;
  param_1[0x1ad] = 0;
  param_1[0x1ae] = 0;
  param_1[0x1a2] = 0;
  param_1[0x1a8] = 0;
  CVOGHBBase_AttachOwnerObject(param_1, nullptr);
  param_1[0x19e] = DAT_009d3f88;
  param_1[0x19f] = DAT_009d3f8c;
  param_1[0x1a0] = DAT_009d3f90;
  param_1[0x1a1] = DAT_009d3f94;
  ExceptionList = local_c;
  return param_1;
}
