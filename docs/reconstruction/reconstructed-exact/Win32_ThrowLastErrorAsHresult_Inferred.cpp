// =============================================================================
// Win32_ThrowLastErrorAsHresult_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Noreturn helper — GetLastError, pack positive codes as
//           HRESULT_FROM_WIN32 ((err & 0xffff) | 0x80070000), throw via
//           Cxx_ThrowException_Param (FUN_004048e0 / ThrowInfo DAT_00acc3fc).
//
// Address:  0x004048c0  (autoassault.exe, image base 0x400000)
// Body:     0x004048c0–0x004048d9 (26 bytes)
// Stable:   aa_004048c0
// System:   crt-com / Win32 last-error → C++ throw
// Ghidra:   FUN_004048c0
//
// ABI:      no formals; does not return.
// Callees:  GetLastError (IAT [0x009c6230]); FUN_004048e0
// Callers:  MbcsString_ConvertFromWide (0x00403450) + six other Win32 fail sites
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W22-G seal).
// =============================================================================

/* Win32_ThrowLastErrorAsHresult_Inferred — last-error → HRESULT throw.

   Algorithm:
     1. err = GetLastError()
     2. if ((int)err > 0) err = (err & 0xffff) | 0x80070000
     3. FUN_004048e0(err)  // noreturn _CxxThrowException

   Used when a Win32 API has already failed (return 0 / false) and the code
   wants a C++ exception carrying the last error as a FACILITY_WIN32 HRESULT.
   Distinct from FUN_004048e0 alone (caller already holds the throw value). */

#include <stdint.h>
#include <windows.h>

/* FUN_004048e0 — sealed Cxx_ThrowException_Param_Inferred */
extern void FUN_004048e0(uint32_t code); /* noreturn */

__declspec(noreturn) void Win32_ThrowLastErrorAsHresult_Inferred(void)
{
  DWORD err = GetLastError();
  if ((int)err > 0) {
    err = (err & 0xffffu) | 0x80070000u;
  }
  FUN_004048e0((uint32_t)err);
}
