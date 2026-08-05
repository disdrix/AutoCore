// =============================================================================
// Phys_StackDesc_ResetFlag0_Float1000
// -----------------------------------------------------------------------------
// Stable ID: aa_0065eb10
// Address:   0x0065eb10  (autoassault.exe, image base 0x400000)
// System:    physics / Havok stack or CCS descriptor
// Generated: 2026-07-29 W25-O dual A/B seal (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Reset a short stack/CCS-style descriptor in place:
//     *desc       = 0          (flag / type byte)
//     *(float*)(desc+4) = 1000.0f   (DAT_00a0f520)
//   Used as post-ctor stack-descriptor teardown (wheels via FUN_0064fe40) and
//   as hkDefaultChassis vtbl+0x18 optional CCS reset (when arg non-null).
//   Does not free or touch a heap component instance by itself.
//
// ABI: __fastcall — ECX = desc*; plain ret.
//      Bytes leave EAX = ECX (return-this); Ghidra decompile shows void.
//
// CALLERS (2):
//   FUN_0064fe40              0x0064fe40
//   hkDefaultChassis_vtbl_0x18 0x0064feb0
//
// SEALED: 19-byte leaf; movss load of DAT_00a0f520; no callees.
// =============================================================================

#include <cstdint>

// Image global @ 0x00a0f520 — Confirmed read_memory: 00 00 7a 44 = 1000.0f
// Same pool constant used as drive-torque clamp ceiling elsewhere.
extern "C" float DAT_00a0f520;  // = 1000.0f

// Minimal view of the descriptor this unit touches (product typedef Open).
struct PhysStackDesc8 {
  uint8_t flag;      // +0  cleared to 0
  uint8_t pad[3];    // +1..+3  not written by this unit
  float   value;     // +4  set to 1000.0f
};

// MSVC fastcall/thiscall: ECX = desc. Decompiler void; EAX ends as ECX.
void __fastcall Phys_StackDesc_ResetFlag0_Float1000(PhysStackDesc8* desc)
{
  const float kDefault = DAT_00a0f520;  // 1000.0f

  desc->flag = 0;
  desc->value = kDefault;
}
