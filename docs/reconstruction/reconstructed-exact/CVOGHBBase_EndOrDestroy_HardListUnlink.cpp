// =============================================================================
// CVOGHBBase_EndOrDestroy_HardListUnlink
// -----------------------------------------------------------------------------
// Stable ID: aa_0050843d
// Address:   0x0050843d  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0050843d
// System:    heartbeat / CVOGHBBase
// Generated: 2026-07-29 W20-R dual A/B seal
// Exactness: Behavior-preserving; read_memory preferred over decomp unaffs.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   SEH tail of CVOGHBBase_EndOrDestroy (0x005083f0). After optional OnEnd:
//     - If flag_hard and owner-list link present, remove this HB from the
//       list manager via FUN_005085b0(listMgr, this).
//     - Always fall into FUN_0050846f soft-mark (byte this+0x20=1, clear +0x18)
//       and parent SEH epilogue (ret 8 at parent level).
//
// ABI (continuation — not a standalone thiscall):
//   ESI = CVOGHBBase* this
//   EBX = 0
//   EBP = parent frame; [ebp+0xc] = flag_hard
//   Sets [ebp-4] SEH state = 3
//
// DECOMP GAPS FIXED FROM BYTES:
//   - FUN_005085b0 is __thiscall(listMgr, hb*), not FUN_005085b0(hb only)
//   - Soft-path stores live in FUN_0050846f, not this 39-byte fragment
// =============================================================================

#include <stdint.h>

struct CVOGHBBase;
struct ListManager;

// Sealed sibling duals:
//   FUN_005085b0 — thread-safe remove-by-key on list manager
//   FUN_0050846f — soft mark + ExceptionList restore fragment
extern uint32_t __thiscall FUN_005085b0(ListManager *listMgr, CVOGHBBase *hb);
extern void FUN_0050846f(void);

// INFERRED — product English for fragment open; parent dual names EndOrDestroy.
void CVOGHBBase_EndOrDestroy_HardListUnlink(void)
{
  // Register/frame contract from parent FUN_005083f0 (documented, not locals):
  //   CVOGHBBase *self = (CVOGHBBase *)esi;
  //   int32_t flag_hard = *(char *)(ebp + 0xc);
  // Written as explicit ops for reconstruction clarity:

  // *(int32_t *)(ebp - 4) = 0; then low byte = 3  (SEH state)
  // if (flag_hard != 0) {
  //   void *owner = *(void **)((char *)self + 0x18);
  //   if (owner != 0) {
  //     ListManager *listMgr = *(ListManager **)((char *)owner + 0xb0);
  //     if (listMgr != 0) {
  //       FUN_005085b0(listMgr, self);
  //     }
  //   }
  // }
  // FUN_0050846f();  // mark dead, clear link, restore SEH / ret 8

  // Scaffold body mirrors Ghidra residual shape for xref continuity; prefer
  // annotated/read_memory CF above when porting.

  int unaff_EBX; // parent: 0
  int unaff_EBP; // parent frame
  int unaff_ESI; // this

  *(int *)(unaff_EBP + -4) = unaff_EBX;
  *(uint8_t *)(unaff_EBP + -4) = 3;
  if (((*(char *)(unaff_EBP + 0xc) != (char)unaff_EBX) &&
       (*(int *)(unaff_ESI + 0x18) != unaff_EBX)) &&
      (*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0) != unaff_EBX)) {
    // Correct ABI: ECX = listMgr @ *(owner+0xb0), arg0 = HB* (esi)
    FUN_005085b0((ListManager *)(*(int *)(*(int *)(unaff_ESI + 0x18) + 0xb0)),
                 (CVOGHBBase *)unaff_ESI);
    FUN_0050846f();
    return;
  }
  // Soft path is FUN_0050846f in-image; decompiler inlines:
  *(uint8_t *)(unaff_ESI + 0x20) = 1;
  *(int *)(unaff_ESI + 0x18) = unaff_EBX;
  // ExceptionList restore + parent ret 8 — see FUN_0050846f / parent epilogue
  return;
}
