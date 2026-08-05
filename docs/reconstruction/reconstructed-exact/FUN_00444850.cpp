// =============================================================================
// FUN_00444850  (scaffold twin of FourCCFnPtrMap_TryInsert_DAT_00d21958)
// -----------------------------------------------------------------------------
// Stable ID: aa_00444850
// Address:   0x00444850
// Wave:      W35-H — prefer FourCCFnPtrMap_TryInsert_DAT_00d21958.cpp
// =============================================================================

#include <cstdint>

extern uint8_t DAT_00d21958[];
void* FUN_00458510(void* out /*stack*/, /*eax*/ void* map, /*ebx*/ void* key);

// EAX=tag, ECX=handler (register formals)
void FUN_00444850(/*eax*/ uint32_t tag, /*ecx*/ void* handler)
{
  struct { uint32_t tag; void* handler; } key{tag, handler};
  uint8_t out[8]{};
  (void)FUN_00458510(out, &DAT_00d21958, &key);
}
