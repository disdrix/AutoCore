// =============================================================================
// CNDHash_TraversalLock
// -----------------------------------------------------------------------------
// Stable ID: aa_00411e10
// Address:   0x00411e10–0x00411e35  (autoassault.exe @ 0x400000; 38 B / 0x26)
// System:    interaction-activation / shared CNDHash
// Dual A/B:  2026-08-05 MEGA-113
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Set CNDHash TraversalLock flag at hash+0x1d. If already locked, log
//   HashError + VOG_DEBUG_STOP, then still write flag=1 (soft double-lock).
//
// ABI
//   Custom register: ESI = CNDHash*
//   No stack args. Bare RET (C3). Void. NOT __thiscall.
//
// STRINGS
//   "HashError:TraversalLock, already locked for traversal" @ 0x00a27cd0
//   "VOG_DEBUG_STOP" @ 0x00a15844
//
// CALLEE
//   FUN_007a4480 (cdecl debug log) ×2
//
// CALLERS (sample)
//   Client_UpdateNpcInteractIcons @ 0x0091b8d0 (ESI=[client+0xe8f4])
//   NDUIWindow_ReloadInterface @ 0x00792980 (ESI=[obj+0x4c0])
//   FUN_0088c340 (ESI=[char+0x538] mission hash)
//   + UI/object hash walkers (16 UNCONDITIONAL_CALL xrefs total)
//
// UNLOCK
//   Caller-owned inline clear of *(hash+0x1d)=0 (no companion unlock VA).
//
// ODD BEHAVIOR (preserve)
//   Double-lock logs but does NOT early-return — flag always set to 1.
//   Contrast List_TraversalLock (0x004294f0) which returns without re-lock.
//
// Rejected aliases
//   Named_VOG_DEBUG_STOP_00411e10 (scaffold misname from VOG string)
//   Named_CalleeOf_* scaffolds
// =============================================================================

#include <cstdint>

extern void FUN_007a4480(int level, const char *msg); // vog log

// Register ABI: ESI = hash*. Parameter models that register for readability.
// Call sites must place hash* in ESI before CALL.
void CNDHash_TraversalLock(int hashEsi)
{
  if (*reinterpret_cast<char *>(hashEsi + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<std::uint8_t *>(hashEsi + 0x1d) = 1;
}
