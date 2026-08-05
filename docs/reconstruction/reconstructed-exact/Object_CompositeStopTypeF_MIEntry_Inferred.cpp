// =============================================================================
// Object_CompositeStopTypeF_MIEntry_Inferred  (FUN_005d49e0)
// -----------------------------------------------------------------------------
// Stable ID: aa_005d49e0
// Address:   0x005d49e0–0x005d4a01  (34 B / 0x22; pad CC after)
// System:    object stop / type-0xF reload (composite MI public entry)
// Generated: 2026-07-29 W30-K dual seal
// Exactness: Behavior-preserving rewrite from read_memory bytes (decompiler
//            elides both this-adjust LEAs and ret 4).
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Public multi-inheritance entry that sequences two stop helpers with fixed
//   this adjustments:
//     1) FUN_0053d4b0(this - 0x90, param)  — optional nested stop if field set
//     2) Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(this - 0x10, param)
//   Reached only via MI JMP adjustors (4 sites); sole CODE CALL of 00581500.

// ABI (image-sealed):
//   __thiscall  ECX = this_entry
//   stack: 1 dword param (forwarded)
//   ret 4
//   void

#include <stdint.h>

// External:
// void __thiscall FUN_0053d4b0(void *self_adj, uint32_t param); // 0x0053d4b0
// void __thiscall Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred(void *self_sub); // 0x00581500 W29-O
//   (callee also ret 4; param cleaned by that callee's epilogue)

void __thiscall Object_CompositeStopTypeF_MIEntry_Inferred(void *self, uint32_t param)
{
  FUN_0053d4b0((char *)self - 0x90, param);
  Object_StopTypeF_ReloadEventVariant_MIThunk_Inferred((char *)self - 0x10 /*, param */);
}
