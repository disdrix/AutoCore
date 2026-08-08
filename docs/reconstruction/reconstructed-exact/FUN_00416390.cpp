// =============================================================================
// FUN_00416390 — scaffold twin of CriticalSection_Initialize_SehToHresult_Ecx_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00416390
// Address:   0x00416390  (autoassault.exe, image base 0x400000)
// See:       CriticalSection_Initialize_SehToHresult_Ecx_Inferred.cpp
//            (named clean; dual WQ9I-I)
// =============================================================================

#include <windows.h>

extern "C" HRESULT CriticalSection_Initialize_SehToHresult_Ecx_Inferred(
    LPCRITICAL_SECTION cs /*ECX*/);

extern "C" HRESULT FUN_00416390(LPCRITICAL_SECTION cs /*ECX*/)
{
  return CriticalSection_Initialize_SehToHresult_Ecx_Inferred(cs);
}
