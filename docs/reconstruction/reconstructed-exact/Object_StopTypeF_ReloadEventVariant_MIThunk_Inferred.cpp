// =============================================================================
// Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred  (FUN_00581500)
// -----------------------------------------------------------------------------
// Stable ID: aa_00581500
// Address:   0x00581500–0x00581517  (24 B / 0x18; pad CC after)
// System:    client-fx / type-0xF stop + event-variant reload (MI public entry)
// Generated: 2026-07-29 W29-O dual seal
// Exactness: Behavior-preserving rewrite from read_memory bytes (decompiler elides adjust).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   MSVC multi-inheritance / vb this-adjustor public entry for
//   Object_StopTypeF_ReloadEventVariant_Inferred (0x00514d80, W28-H).
//   Adjusts ECX via pointer at this-0x8C and vb dword at +4, then calls impl.
//   Epilogue ret 4 matches virtual ABI (one stack dword cleaned; impl uses plain ret).

// ABI (image-sealed):
//   __thiscall  ECX = subobject this
//   stack: 1 dword (ignored by this unit / cleaned)
//   ret 4
//   void

#include <stdint.h>

// External (sealed W28-H):
// void __thiscall Object_StopTypeF_ReloadEventVariant_Inferred(void *self);

void __thiscall Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(void *self_sub)
{
  void *vb_or_base = *(void **)((char *)self_sub - 0x8C);
  int delta = *(int *)((char *)vb_or_base + 4);
  void *self_obj = (char *)self_sub + delta - 0x8C;
  Object_StopTypeF_ReloadEventVariant_Inferred(self_obj);
}
