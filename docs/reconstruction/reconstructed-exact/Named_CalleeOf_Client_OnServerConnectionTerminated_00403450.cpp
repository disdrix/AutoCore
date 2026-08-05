// =============================================================================
// Named alias → same body as FUN_00403450 (MbcsString_ConvertFromWide)
// -----------------------------------------------------------------------------
// Stable ID: aa_00403450
// Address:   0x00403450  (autoassault.exe, image base 0x400000)
// Note: historical xref alias; prefer MbcsString_ConvertFromWide / FUN_00403450.
// Dual: 2026-07-29 OWN-ONLY W16-L — see reviews/A|B_aa_00403450_MbcsString_ConvertFromWide.md
// =============================================================================

#include <windows.h>
#include <stdlib.h>

extern void FUN_004048e0(unsigned int hr);
extern void FUN_004048c0(void);

void __thiscall Named_CalleeOf_Client_OnServerConnectionTerminated_00403450(
    void **this_obj, LPCWSTR wide, UINT code_page)
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
