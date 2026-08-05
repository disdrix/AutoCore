// =============================================================================
// Named scaffold alias → Dword_FillN_ReturnEnd_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004e2f70
// Address:   0x004e2f70
// Canonical: reconstructed-exact/Dword_FillN_ReturnEnd_Inferred.cpp
// Dual:      reviews/A_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md
//            reviews/B_aa_004e2f70_Dword_FillN_ReturnEnd_Inferred.md
// Note:      Prior under-name (CVOGSectorMap_AddCharacter seed). Prefer canonical.
//            Multi-caller generic dword fill-n — not map-exclusive.
// =============================================================================

#include <stdint.h>

uint32_t * Named_CalleeOf_Named_CalleeOf_CVOGSectorMap_AddCharacter_004e2f70(
    uint32_t *dst, int count, uint32_t *pValue)
{
  uint32_t *p;
  int n;

  p = dst;
  for (n = count; n != 0; n = n + -1) {
    *p = *pValue;
    p = p + 1;
  }
  return dst + count;
}
