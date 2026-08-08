// =============================================================================
// FUN_004cb2c0  — clean twin of StdTree_Min_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004cb2c0
// Address:   0x004cb2c0  (autoassault.exe, image base 0x400000)
// Body:      0x004cb2c0 – 0x004cb2da inclusive (27 B / 0x1b)
// System:    MSVC std::_Tree min / leftmost (isnil @ +0x21)
// Generated: 2026-08-05 R13-002 dual seal (replaces 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite from body bytes (read_memory).
//            Ghidra decompile is void — NOT authoritative for return (EAX).
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime Confirmed: NOT claimed.
// =============================================================================

#include <cstdint>

// See StdTree_Min_Isnil21_Inferred.cpp for full plate + purpose.
// This twin keeps the Ghidra symbol as the primary export for path matching.

struct StdTreeNode_Isnil21_Twin {
  StdTreeNode_Isnil21_Twin *left;    // +0x00
  StdTreeNode_Isnil21_Twin *parent;  // +0x04
  StdTreeNode_Isnil21_Twin *right;   // +0x08
};

// Stack arg; EAX out; bare RET
extern "C" StdTreeNode_Isnil21_Twin *FUN_004cb2c0(
    StdTreeNode_Isnil21_Twin *param_1)
{
  StdTreeNode_Isnil21_Twin *left =
      *reinterpret_cast<StdTreeNode_Isnil21_Twin **>(param_1);

  if (*reinterpret_cast<char *>(reinterpret_cast<std::uintptr_t>(left) + 0x21) !=
      0) {
    return param_1;
  }

  do {
    param_1 = left;
    left = *reinterpret_cast<StdTreeNode_Isnil21_Twin **>(param_1);
  } while (*reinterpret_cast<char *>(
               reinterpret_cast<std::uintptr_t>(left) + 0x21) == 0);

  return param_1;
}
