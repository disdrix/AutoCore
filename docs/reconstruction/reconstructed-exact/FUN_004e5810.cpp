// =============================================================================
// FUN_004e5810  (scaffold twin — prefer Object_CopyTfidVectorAtE7f8_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_004e5810
// Address:   0x004e5810  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer
// Generated: 2026-08-05 R13-026 dual (forwards to named clean)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================

#include <cstdint>

struct VectorU64Shell;

extern "C" VectorU64Shell *__thiscall Object_CopyTfidVectorAtE7f8_Inferred(
    void *self, VectorU64Shell *out);

extern "C" VectorU64Shell *__thiscall FUN_004e5810(void *self, VectorU64Shell *out)
{
  return Object_CopyTfidVectorAtE7f8_Inferred(self, out);
}
