// =============================================================================
// FUN_00411e10 — twin of CNDHash_TraversalLock
// -----------------------------------------------------------------------------
// Stable ID: aa_00411e10
// Address:   0x00411e10–0x00411e35  (autoassault.exe @ 0x400000; 38 B)
// System:    interaction-activation / shared CNDHash
// Dual A/B:  2026-08-05 MEGA-113
// Canonical: CNDHash_TraversalLock  (see CNDHash_TraversalLock.cpp)
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// Ghidra symbol retained as twin entry for address-keyed tooling.
// Prefer CNDHash_TraversalLock for ports.
// =============================================================================

#include <cstdint>

extern void FUN_007a4480(int level, const char *msg);

// custom ESI = CNDHash*; bare ret
void FUN_00411e10(int hashEsi)
{
  if (*reinterpret_cast<char *>(hashEsi + 0x1d) != 0) {
    FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal");
    FUN_007a4480(0, "VOG_DEBUG_STOP");
  }
  *reinterpret_cast<std::uint8_t *>(hashEsi + 0x1d) = 1;
}
