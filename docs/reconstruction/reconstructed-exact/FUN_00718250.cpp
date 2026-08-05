// =============================================================================
// FUN_00718250 — _com_error_ScalarDeletingDtor (scaffold)
// -----------------------------------------------------------------------------
// Stable ID: aa_00718250
// Address:   0x00718250  (autoassault.exe, image base 0x400000)
// System:    crt-com / MSVC _com_error
// Generated: 2026-07-29 W25-P OWN-ONLY dual seal
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE: MSVC scalar deleting destructor for _com_error.
//   call ~_com_error(this); if (flags & 1) operator_delete(this); return this;
// Stable ID: aa_00718250
// Named twin: reconstructed-exact/_com_error_ScalarDeletingDtor.cpp
// Dual: reviews/A_aa_00718250__com_error_ScalarDeletingDtor.md + B_*

/*
 * Behavioral notes:
 * - Live decompile + read_memory 2026-07-29: body 0x00718250–0x0071827b (43 B).
 * - Epilogue C2 04 00 (ret 4). Callees: 0x007182e0, operator_delete.
 * - Vftable slot0 @ 0x00a14034 → this VA.
 * - Decompiler "does not return" on operator_delete is residual; EAX=this still returned.
 */

#include <cstdint>

struct _com_error;

// Body dtor sealed as sibling aa_007182e0
void __thiscall _com_error_dtor(_com_error *self);
void operator_delete(void *p);

_com_error *__thiscall FUN_00718250(_com_error *param_1, uint32_t param_2)
{
  _com_error_dtor(param_1);
  if ((param_2 & 1) != 0) {
    operator_delete(param_1);
  }
  return param_1;
}
