// =============================================================================
// FUN_00581500  (alias → Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00581500
// Address:   0x00581500–0x00581517  (24 B / 0x18)
// Dual A/B:  2026-07-29 accept (W29-O)
// Authoritative named clean: Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred.cpp
// =============================================================================

#include <stdint.h>

void __thiscall FUN_00581500(void *self_sub)
{
  void *vb_or_base = *(void **)((char *)self_sub - 0x8C);
  int delta = *(int *)((char *)vb_or_base + 4);
  void *self_obj = (char *)self_sub + delta - 0x8C;
  Object_StopTypeF_ReloadEventVariant_Inferred(self_obj);
}
