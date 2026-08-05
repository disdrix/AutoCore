// =============================================================================
// Com_BstrHolder_Release
// -----------------------------------------------------------------------------
// Purpose:  Interlocked-release a 12-byte BSTR holder. When the refcount hits
//           zero: SysFreeString the BSTR, operator_delete[] the secondary
//           buffer, operator_delete the holder itself, return 0. When still
//           live: return the current refcount at +8.
//
// Address:  0x00419e20  (autoassault.exe, image base 0x400000)
// Body:     0x00419e20–0x00419e60 (64 bytes through final ret)
// Stable:   aa_00419e20
// System:   crt-com / MSVC BSTR smart-holder
// Ghidra:   FUN_00419e20
//
// ABI:      ESI-this; no stack formals; ret (C3)
// Layout:   +0 BSTR, +4 secondary*, +8 LONG refcount (size 0xC)
// Sibling:  Com_BstrHolder_CreateFromOleStr_Inferred @ 0x00419ca0
//
// Exactness: CF mirrors raw + read_memory bytes; names cleaned / INFERRED.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept (2026-07-29 W22-L seal).
// =============================================================================

/* Com_BstrHolder_Release

   Algorithm:
     1. newCount = InterlockedDecrement(&self->refcount)  // +8
     2. if newCount != 0: return self->refcount (re-read +8)
     3. if self == 0: return 0
     4. if self->bstr: SysFreeString
     5. if self->secondary: operator_delete[]
     6. operator_delete(self)
     7. return 0

   Note: decompiler falsely marks operator_delete as non-returning; bytes continue
   to xor eax,eax / pop edi / ret.

   Callers: FUN_00419db0 (slot release+null), FUN_00419ed0, FUN_00419f60,
            FUN_007b87c0..FUN_007b8de0 (COM/XML skill-DB helpers). */

#include <stdint.h>
#include <windows.h> /* BSTR, LONG, SysFreeString, InterlockedDecrement */

typedef struct ComBstrHolder {
  BSTR bstr;       /* +0 */
  void *secondary; /* +4 — array-deleted */
  LONG refcount;   /* +8 */
} ComBstrHolder;

/* Register convention: holder in ESI (MSVC regpass). Modeled as formal for
   readability; clean ports may use an explicit this pointer. */
LONG Com_BstrHolder_Release(ComBstrHolder *self /* ESI */)
{
  LONG newCount;

  newCount = InterlockedDecrement(&self->refcount);
  if (newCount != 0) {
    return self->refcount;
  }

  if (self != 0) {
    if (self->bstr != 0) {
      SysFreeString(self->bstr);
    }
    if (self->secondary != 0) {
      operator delete[](self->secondary);
    }
    operator delete(self);
  }
  return 0;
}
