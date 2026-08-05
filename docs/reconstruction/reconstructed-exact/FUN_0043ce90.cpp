// =============================================================================
// FUN_0043ce90  (twin of GuardedVector_RingCopyRange)
// -----------------------------------------------------------------------------
// Stable ID: aa_0043ce90
// Address:   0x0043ce90 – 0x0043cebe  (autoassault.exe, image base 0x400000)
// System:    STL / guarded container (unlocked assign helpers)
// Dual:      W27-B 2026-07-29 (decompile_function + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// =============================================================================

#include <cstdint>

// Unowned ring-copy body. Retail formals recovered only partially by decompiler.
extern "C" void FUN_0043d390(int* outPair,
                             int srcContainer, uint32_t srcIdx,
                             int srcEndContainer, uint32_t srcEndIdx,
                             int dstContainer, uint32_t dstIdx);

// Retail: parent pushes 6 stack args + ESI=&outPair[2].
// Body reshapes stack, CALL FUN_0043d390, MOV EAX,ESI, ADD ESP,0x24, RET.
// Decompiler collapses body to a single call; return is ESI in EAX.
extern "C" void* FUN_0043ce90(void)
{
  // Host builds cannot invoke this without the retail stack layout.
  // Semantic equivalent used by GuardedVector_CopyAssign:
  //   FUN_0043d390(out, ...); return out;
  return nullptr;
}

// Explicit port form (arguments match FUN_0043d390 decompiler signature).
extern "C" void* FUN_0043ce90_port(int* outPair,
                                   int srcContainer, uint32_t srcIdx,
                                   int srcEndContainer, uint32_t srcEndIdx,
                                   int dstContainer, uint32_t dstIdx)
{
  FUN_0043d390(outPair, srcContainer, srcIdx, srcEndContainer, srcEndIdx,
               dstContainer, dstIdx);
  return outPair;
}
