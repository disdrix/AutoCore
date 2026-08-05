// =============================================================================
// FUN_00403450 — MbcsString_ConvertFromWide
// -----------------------------------------------------------------------------
// Stable ID: aa_00403450
// Address:   0x00403450  (autoassault.exe, image base 0x400000)
// System:    string / locale / MBCS owned-string
// Generated: 2026-07-29 OWN-ONLY dual W16-L (faithful from live decompile)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual reviews: reviews/A_aa_00403450_MbcsString_ConvertFromWide.md
//               reviews/B_aa_00403450_MbcsString_ConvertFromWide.md
// =============================================================================
//
// PURPOSE:
//   Convert a wide C-string into an MBCS string object under an explicit code page.
//   - Null wide → *this = 0.
//   - Size budget = (lstrlenW+1)*2; if > 0x80, malloc into *this (OOM throws 0x8007000E).
//   - If size ≤ 0x80, write through existing *this (caller SSO bind, e.g. FUN_00402d50).
//   - WideCharToMultiByte; on failure FUN_004048c0 (GetLastError → throw).
//
// ABI:
//   __thiscall  ECX = MbcsString* (pData at +0)
//   stack: LPCWSTR wide, UINT codePage
//   ret 8
//
// =============================================================================

#include <windows.h>
#include <stdlib.h>

// Callees (retail):
//   void FUN_004048e0(HRESULT);  // _CxxThrowException wrapper (noreturn)
//   void FUN_004048c0(void);     // GetLastError → HRESULT throw (noreturn)

extern void FUN_004048e0(unsigned int hr);
extern void FUN_004048c0(void);

void __thiscall FUN_00403450(void **this_obj, LPCWSTR wide, UINT code_page)
{
  size_t size_bytes;
  int cch;
  void *heap;

  if (wide == (LPCWSTR)0) {
    *this_obj = 0;
    return;
  }

  cch = lstrlenW(wide);
  size_bytes = (size_t)(cch + 1) * 2;

  if (0x80 < (int)size_bytes) {
    heap = malloc(size_bytes);
    *this_obj = heap;
    if (heap == (void *)0) {
      /* WARNING: Subroutine does not return */
      FUN_004048e0(0x8007000e);
    }
  }

  cch = WideCharToMultiByte(
      code_page,
      0,
      wide,
      cch + 1,
      (LPSTR)*this_obj,
      (int)size_bytes,
      (LPCSTR)0,
      (LPBOOL)0);

  if (cch == 0) {
    FUN_004048c0();
  }
  return;
}
