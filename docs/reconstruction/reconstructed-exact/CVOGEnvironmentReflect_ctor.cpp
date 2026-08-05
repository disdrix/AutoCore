// =============================================================================
// CVOGEnvironmentReflect_ctor  (was FUN_005b35a0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005b35a0
// Address:   0x005b35a0  (autoassault.exe, image base 0x400000)
// Body:      0x005b35a0–0x005b366f exclusive (207 bytes / 0xCF)
// System:    client / VOGEnvironmentSector / fog+reflect phase
// Generated: 2026-07-29 W32-T dual seal
// Exactness: Behavior-preserving rewrite of decompiler + read_memory CF.
// Bit-for-bit vs retail EXE: DEFERRED
//
// RTTI Confirmed: COL@0x00aafff8 → type_info@0x00af3eb0 ".?AVCVOGEnvironmentReflect@@"
// Vtable: PTR_FUN_009d95a0  (vtbl[1] = Env_ApplyFogShaderAndReflect_Inferred @ 0x005b36f0)
// Dual: reviews/A|B_aa_005b35a0_CVOGEnvironmentReflect_ctor.md
// =============================================================================

#include <cstdint>

extern void* ExceptionList;
extern void* PTR_FUN_009d95a0;
extern float DAT_00a0f2a0;  // 1.0f
extern float DAT_00aaa668;  // -1.0f

// Base phase-like ctor used by several env hosts (product name open).
extern std::uint32_t* __fastcall FUN_007560d0(std::uint32_t* self);
// Default 4x4 / transform blob at ECX (product name open).
extern void __fastcall FUN_00972cc0(std::uint32_t* matrix_sub);
// Optional matrix post-step when flag bit0 set (product name open).
extern void __fastcall FUN_00972e50(std::uint32_t* matrix_sub);
// Scale/position stamp on matrix sub when floats change (product name open).
extern void __thiscall FUN_0044b440(std::uint32_t* matrix_sub, float a, float b, float c);

// Owned env phase host ctor. Sole factory:
//   PalantirEnv_InitPhases → new(0x170) + CVOGEnvironmentReflect_ctor(parent@env+0xB8)
//   → env+0xC4; FUN_005b39a0(1).
std::uint32_t* __thiscall CVOGEnvironmentReflect_ctor(std::uint32_t* self, std::uint32_t* parent)
{
  void* local_c;
  std::uint8_t* puStack_8;
  std::uint32_t local_4;

  local_4 = 0xffffffff;
  puStack_8 = reinterpret_cast<std::uint8_t*>(0x009a67ed); /* LAB_009a67ed */
  local_c = ExceptionList;
  ExceptionList = &local_c;

  FUN_007560d0(self);
  local_4 = 0;
  *self = reinterpret_cast<std::uint32_t>(&PTR_FUN_009d95a0);

  std::uint32_t* matrix = self + 0x24; /* +0x90 */
  FUN_00972cc0(matrix);

  self[0x57] = reinterpret_cast<std::uint32_t>(parent);           // +0x15C
  self[0x56] = 0;                                                 // +0x158
  self[0x58] = parent[0xE4E8 / 4];                                // +0x160 ← parent+0xE4E8
  self[0x55] = 0;                                                 // +0x154
  self[0x54] = 0;                                                 // +0x150
  self[0x59] = parent[0xE894 / 4];                                // +0x164 ← parent+0xE894

  // Bytes: push floats 1.0, -1.0, 1.0; ECX = this+0x90
  FUN_0044b440(matrix, DAT_00a0f2a0, DAT_00aaa668, DAT_00a0f2a0);

  if ((*(reinterpret_cast<std::uint8_t*>(self + 0x53)) & 1) != 0) { // +0x14C
    FUN_00972e50(matrix);
  }

  *(reinterpret_cast<std::uint8_t*>(self + 0x1e)) = 1; // +0x78
  *(reinterpret_cast<std::uint8_t*>(self + 0x20)) = 1; // +0x80

  ExceptionList = local_c;
  return self; /* ret 4 */
}

// Scaffold alias
std::uint32_t* __thiscall FUN_005b35a0(std::uint32_t* param_1, std::uint32_t* param_2)
{
  return CVOGEnvironmentReflect_ctor(param_1, param_2);
}
