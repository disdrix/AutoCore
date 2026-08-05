// =============================================================================
// _com_error_ScalarDeletingDtor
// -----------------------------------------------------------------------------
// Stable ID: aa_00718250
// Address:   0x00718250  (autoassault.exe, image base 0x400000)
// System:    crt-com / MSVC COM support (comdef / _com_error)
// Ghidra:    FUN_00718250
// Generated: 2026-07-29 W25-P OWN-ONLY dual seal
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// ROLE (Confirmed library shape):
//   MSVC `scalar deleting destructor` for `_com_error`.
//   Vftable PTR_FUN_00a14034 slot0 = this function.
//
// ABI:
//   __thiscall  ECX = _com_error*
//   stack arg0  = uint flags; bit0 ⇒ operator_delete(this)
//   returns this in EAX
//   ret 4
//
// Evidence:
//   decompile_function @ 0x00718250
//   read_memory body hex:
//     558bec51894dfc8b4dfce8810000008b450883e001740c8b4dfc51e8b215d7ff83c4048b45fc8be55dc20400
//   Relative call +0x81 from 0x0071825f → 0x007182e0 (~_com_error)
//   DATA xref 0x00a14034 → 0x00718250
//
// Not game domain. Port: N/A for server; client may keep CRT COM.

#include <cstdint>

struct _com_error;

// Sealed sibling aa_007182e0 — virtual body dtor (Release / LocalFree; no operator_delete)
void __thiscall _com_error_dtor(_com_error *self);
void operator_delete(void *p);

_com_error *__thiscall _com_error_ScalarDeletingDtor(_com_error *self /* this */, uint32_t flags)
{
  _com_error_dtor(self);
  if ((flags & 1u) != 0u) {
    operator_delete(self);
  }
  return self;
}
