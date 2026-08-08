// =============================================================================
// FUN_00406190  (scaffold twin → StdTree_ConstructEmpty_Isnil2D_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406190
// Address:   0x00406190  (autoassault.exe, image base 0x400000)
// Body:      0x00406190–0x004061e9 inclusive (90 B / 0x5A)
// System:    MSVC std::_Tree empty construct (isnil@+0x2d)
// Generated: 2026-08-05 WQ9K-D dual seal
// Exactness: Behavior-preserving; meaningful names. Not modernization.
// Terminal:  false
// =============================================================================

#include <cstdint>

// See StdTree_ConstructEmpty_Isnil2D_Inferred.cpp for full plate + types.

struct NodeIsnil2D_Size0x30;
struct TreeShellIsnil2D;

extern "C" TreeShellIsnil2D* __stdcall StdTree_ConstructEmpty_Isnil2D_Inferred(
    TreeShellIsnil2D* shell);

extern "C" TreeShellIsnil2D* __stdcall FUN_00406190(TreeShellIsnil2D* shell)
{
  return StdTree_ConstructEmpty_Isnil2D_Inferred(shell);
}
