// =============================================================================
// UI_QuickBar_CreateSlotButton
// -----------------------------------------------------------------------------
// Purpose:  In-place ctor for a QuickBar slot-button NDUI widget.
//           Base ctor → derived vtbl → field defaults → load XML skin.
//
// Address:  0x00825bf0  (autoassault.exe, image base 0x400000)
// Stable:   aa_00825bf0
// System:   skills-abilities
//
// String evidence: "i_d_qb_2d_btn_quickbar.xml"
// Object size:     0x554 (operator_new at sole caller FUN_008a16b0)
//
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// Dual A/B:  accept-with-gaps (2026-07-29)
// Source:    Prefer over FUN_00825bf0.cpp; FUN_* left intact as raw scaffold twin.
// =============================================================================

/*
 * Behavioral notes (sealed):
 * - FUN_00792d20(this): base NDUI ctor (vtbl PTR_FUN_00a98f44).
 * - *this = PTR_FUN_00a75004: derived vtable.
 * - +0x508 = DAT_00aaabc4 = 0.88f (default DOWN_SIZE_RATIO).
 * - +0x514 = 0.1f from shared pool g_flMultiKillCountBlend @ 0x00a0f730
 *   (pool name is NOT multi-kill product semantics).
 * - +0x500 = 0xFFFFFFFF index sentinel (callers stamp 0/1).
 * - +0x4fc = 0 selected/active; +0x540..+0x550 zero ( +0x548 → label child* after XML ).
 * - NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml").
 * - No packet / no cast / no page-select.
 * - Callers: FUN_008a16b0 @ 0x008a19d2, 0x008a1b1c only.
 */

#include <cstdint>

// External / unresolved retail symbols (names from Ghidra / registry)
extern "C" void FUN_00792d20(void *self);
extern "C" void NDUIWindow_ReloadInterface(const char *xml_name);
extern float g_flMultiKillCountBlend;          // VA 0x00a0f730 = 0.1f (shared pool)
extern float DAT_00aaabc4;                     // VA 0x00aaabc4 = 0.88f
extern void *PTR_FUN_00a75004;                 // derived vtable
extern void *LAB_009b42b0;                     // SEH handler (MSVC frame)
extern void *ExceptionList;

// this: pre-allocated object of size 0x554; returns this
void *UI_QuickBar_CreateSlotButton(void *this_)
{
  auto *self = reinterpret_cast<std::uint32_t *>(this_);

  // SEH frame (decomp surface; not re-emitted for host builds)
  // local_4 / puStack_8 / ExceptionList chain → LAB_009b42b0

  FUN_00792d20(this_);

  // +0x508 = 0.88f default DOWN_SIZE_RATIO
  *reinterpret_cast<float *>(reinterpret_cast<char *>(self) + 0x508) = DAT_00aaabc4;
  self[0x144] = 0; // +0x510
  self[0x143] = 0; // +0x50c

  const float fl_point_one = g_flMultiKillCountBlend; // 0.1f

  *reinterpret_cast<void **>(self) = &PTR_FUN_00a75004;

  *(reinterpret_cast<std::uint8_t *>(self) + 0x4fd) = 0;
  *(reinterpret_cast<std::uint8_t *>(self) + 0x4fe) = 0;

  self[0x150] = 0; // +0x540
  self[0x151] = 0; // +0x544
  self[0x152] = 0; // +0x548 (label child* after XML load)
  self[0x153] = 0; // +0x54c
  self[0x154] = 0; // +0x550

  *(reinterpret_cast<std::uint8_t *>(self) + 0x4fc) = 0; // selected/active
  *(reinterpret_cast<std::uint8_t *>(self) + 0x490) = 0;
  *(reinterpret_cast<std::uint8_t *>(self) + 0xbf) = 0;
  *(reinterpret_cast<std::uint8_t *>(self) + 0xc7) = 0;

  self[0x140] = 0xffffffffu; // +0x500 index sentinel
  *reinterpret_cast<float *>(reinterpret_cast<char *>(self) + 0x514) = fl_point_one;

  NDUIWindow_ReloadInterface("i_d_qb_2d_btn_quickbar.xml");

  return this_;
}
