// =============================================================================
// StdTree_DestroyStringAt0C_Inferred  (FUN_00409b80)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409b80
// Address:   0x00409b80–0x00409bc0 inclusive (65 B / 0x41)
//            autoassault.exe, image base 0x400000
// Wave:      2026-08-05 WQ9K-A OWN dual A/B seal
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed stdcall RET 4.
//            SEH frame present in retail (LAB_009bc656); omitted in port rewrite.
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================
// PURPOSE
//   Shared tree-node value destroy for free-subtree twins that hold a
//   std::basic_string at node+0x0c. Does not free the node itself — callers
//   invoke operator_delete after this returns.
//
//   Callers (dualed WQ9J-I):
//     StdTree_FreeSubtree_Isnil131_DestroyStr0C_Inferred (0x00409920)
//     StdTree_FreeSubtree_Isnil2d_DestroyStr0C_Inferred  (0x00409970)
//
// ABI
//   stdcall; stack node*; void; RET 4
//
// Twin / peers (do not merge)
//   Full free-subtree helpers (own walk + delete)
//   No-destroy free-subtree peers 00406c00 / 0051bbc0 / 0040d630
//   Full large-value node dtor (if any) — this is string-only
// =============================================================================

#include <cstdint>
#include <string>

// stdcall RET 4 — destroys basic_string at node+0x0c only
extern "C" void __stdcall StdTree_DestroyStringAt0C_Inferred(void *node)
{
  // Retail: SEH prolog (FS:[0], LAB_009bc656) then thiscall dtor via IAT 0x009c62f4.
  auto *str = reinterpret_cast<std::string *>(static_cast<char *>(node) + 0x0c);
  str->~basic_string();
  // Retail: SEH epilog; ADD ESP,0x0C; RET 4
}

// Ghidra placeholder twin: FUN_00409b80.cpp
