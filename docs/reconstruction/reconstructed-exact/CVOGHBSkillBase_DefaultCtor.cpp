// =============================================================================
// CVOGHBSkillBase_DefaultCtor  (was FUN_00578830)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578830
// Address:   0x00578830  (autoassault.exe, image base 0x400000)
// Body:      0x00578830–0x005788c8 (152 bytes)
// System:    skills-abilities / heartbeat
// Generated: 2026-07-29 W23-S dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED
//
// RTTI Confirmed: COL@0x00aaede0 → type_info@0x00af8cec ".?AVCVOGHBSkillBase@@"
// Vtable: PTR_FUN_009d3fdc (same as full CVOGHBSkillBase_ctor @ 0x005788d0)
// Dual: reviews/A|B_aa_00578830_CVOGHBSkillBase_DefaultCtor.md
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void  CVOGHBBase_ctor(void* self);
// SkillRuntime_PartialCtor — ECX = skill blob at this+0x24
extern void  FUN_0054f3c0(void /*thiscall ECX*/);
extern void  CVOGHBBase_AttachOwnerObject(void* hb, void* owner);
extern std::uint32_t DAT_009d3f88; // + DAT_009d3f8c/90/94 — invalid TFID sentinel
extern void* PTR_FUN_009d3fdc;

// Empty/default CVOGHBSkillBase shell used by skill-element factories before
// subclass vtbl overwrite. No skill blob copy, no ValidateTarget, no period.
std::uint32_t* __thiscall CVOGHBSkillBase_DefaultCtor(std::uint32_t* self)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t*>(0x009a51f8); /* LAB_009a51f8 */
  local_c = ExceptionList;
  ExceptionList = &local_c;

  CVOGHBBase_ctor(self);
  local_4 = 0;
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d3fdc);

  // Bytes: lea ecx,[esi+0x24]; call FUN_0054f3c0
  FUN_0054f3c0(); /* ECX = self+0x24 skill-runtime partial default */

  self[0x1ac] = 0; // +0x6b0
  self[0x1ad] = 0; // +0x6b4
  self[0x1ae] = 0; // +0x6b8
  self[0x1a2] = 0; // +0x688
  self[0x1a8] = 0; // +0x6a0

  CVOGHBBase_AttachOwnerObject(self, nullptr);

  // this+0x678.. ← invalid TFID sentinel {FFFFFFFF,FFFFFFFF,0,0}
  self[0x19e] = DAT_009d3f88;
  self[0x19f] = *(&DAT_009d3f88 + 1); /* DAT_009d3f8c */
  self[0x1a0] = *(&DAT_009d3f88 + 2); /* DAT_009d3f90 */
  self[0x1a1] = *(&DAT_009d3f88 + 3); /* DAT_009d3f94 */

  ExceptionList = local_c;
  return self;
}

// Scaffold alias
std::uint32_t* __fastcall FUN_00578830(std::uint32_t* param_1)
{
  return CVOGHBSkillBase_DefaultCtor(param_1);
}
