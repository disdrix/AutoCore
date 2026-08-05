// =============================================================================
// CVOGHBBase_EndOrDestroy_SoftMarkEpilogue
// -----------------------------------------------------------------------------
// Stable ID: aa_0050846f
// Address:   0x0050846f  (autoassault.exe, image base 0x400000)
// System:    heartbeat / CVOGHBBase
// Ghidra:    FUN_0050846f
// Generated: 2026-07-29 W21-B dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + complete body bytes.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

// PURPOSE:
//   Soft-tail of CVOGHBBase_EndOrDestroy (parent 0x005083f0 → hard fragment
//   0x0050843d). Always reached after optional hard list-unlink:
//     1) this+0x20 = 1  (soft-ended mark)
//     2) this+0x18 = 0  (clear owner link; EBX held 0 by parent)
//     3) restore ExceptionList from [ebp-0xc]
//     4) standard frame teardown + RET 8 (parent stack cleanup)
//
// ABI: not a normal callable with prologue. Live-in:
//   ESI = CVOGHBBase* this
//   EBX = clear value for +0x18 (0)
//   EBP = parent SEH frame
// Callees: none. Callers: FUN_0050843d only (4 jump sites).
//
// Supersedes seed alias Named_CalleeOf_*_CVOGHBMissionPatro_0050846f.

#include <cstdint>

// Process-wide SEH head (MSVC fs:[0]); Ghidra names it ExceptionList.
extern void *ExceptionList;

// Fragment entry — mirrors Ghidra function symbol for xref alignment.
// Prefer this named plate for product docs.

void CVOGHBBase_EndOrDestroy_SoftMarkEpilogue(void)
{
  // --- live-in from parent (no prologue) ---
  // uint8_t  *this_hb = (uint8_t *)esi;
  // uint32_t  clear   = (uint32_t)ebx;   // 0
  // uint32_t *frame   = (uint32_t *)ebp;

  // Byte-sealed stores @ 0x0050846f:
  //   C6 46 20 01    mov byte ptr [esi+0x20], 1
  //   89 5E 18       mov dword ptr [esi+0x18], ebx
  // Register form kept explicit so clean matches raw residual shape.

  register uint32_t unaff_EBX; // ebx — clear value
  register int      unaff_EBP; // ebp — parent frame
  register int      unaff_ESI; // esi — this

  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(uint32_t *)(unaff_ESI + 0x18) = unaff_EBX;
  ExceptionList = *(void **)(unaff_EBP - 0xc);

  // Epilogue bytes (not emitted as C): pop edi/esi; mov fs:[0],ecx;
  // pop ebx; mov esp,ebp; pop ebp; ret 8
  return;
}
