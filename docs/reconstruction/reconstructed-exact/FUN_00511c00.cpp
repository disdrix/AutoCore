// =============================================================================
// FUN_00511c00  — twin of StdTree_EraseAndRebalance_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00511c00
// Address:   0x00511c00  (autoassault.exe, image base 0x400000)
// Body:      0x00511c00 – 0x00511ed3 exclusive (723 B / 0x2D3)
// System:    MSVC std::_Tree erase + RB rebalance (isnil@+0x21)
// Generated: 2026-08-05 R12-015 dual seal
// Exactness: Behavior-preserving; see named clean for full layout comments.
// Bit-for-bit vs retail EXE: DEFERRED
// =============================================================================

#include <cstdint>

// Forward to named reconstruction (same body).
void __thiscall StdTree_EraseAndRebalance_Isnil21_Inferred(void *map, void **outIt,
                                                           void *node);

void __thiscall FUN_00511c00(void *map /*ECX*/, void **outIt, void *node) {
  StdTree_EraseAndRebalance_Isnil21_Inferred(map, outIt, node);
}

// Retail CF summary (authoritative details in named .cpp + raw re-verify):
// 1. SEH frame LAB_009a31f2
// 2. if node->isnil(+0x21) throw "invalid map/set<T> iterator" / DAT_00acc34c
// 3. FUN_004e12c0 successor prep
// 4. unlink + min FUN_004cb2c0 + max FUN_00421a60; two-child splice live
// 5. if color black: L FUN_0050e9f0 / R FUN_005a27f0
// 6. free heap @ +0x14 if set; zero +0x14/+0x18/+0x1c; delete node
// 7. size-- if size>0; *outIt = succ; ret 8
