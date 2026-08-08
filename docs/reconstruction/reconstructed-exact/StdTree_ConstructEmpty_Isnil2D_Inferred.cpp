// =============================================================================
// StdTree_ConstructEmpty_Isnil2D_Inferred  (FUN_00406190)
// -----------------------------------------------------------------------------
// Stable ID: aa_00406190
// Address:   0x00406190–0x004061e9 inclusive (90 B / 0x5A); exclusive 0x004061ea
// System:    MSVC std::_Tree empty construct — isnil@+0x2d / node 0x30
// Generated: 2026-08-05 WQ9K-D dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// Terminal:  false
// =============================================================================
//
// PURPOSE:
//   Construct an empty tree/map shell: buy isnil2D head (0x30), install as
//   _Myhead, force isnil=1 @+0x2d, self-link L/P/R, zero _Mysize.
//
// ABI: __stdcall; 1 stack arg (shell*); RET 0x4; EAX = shell*.
// Head buy: StdTree_BuyHeadNode_Isnil2D_Inferred (0x00409780) dualed WQ9J-G.
// Caller (1): FUN_00404e40 @ 0x00404e76 — host+0x0C subobject empty map/set.
// Contrast: isnil31 construct 0x00405f20; isnil29 BuyHead 0x00408a30 — do not merge.
//
// Dual: reviews/A|B_aa_00406190_StdTree_ConstructEmpty_Isnil2D_Inferred.md

#include <cstdint>

struct NodeIsnil2D_Size0x30 {
  NodeIsnil2D_Size0x30* left;     // +0x00
  NodeIsnil2D_Size0x30* parent;   // +0x04
  NodeIsnil2D_Size0x30* right;    // +0x08
  // +0x0C .. +0x2B value region (Val32) — not written by buyhead/this unit
  std::uint8_t color;             // +0x2c (set black by buyhead)
  std::uint8_t isnil;             // +0x2d
  // pad to 0x30
};

struct TreeShellIsnil2D {
  // +0x00: allocator/comp region (untouched by this unit)
  NodeIsnil2D_Size0x30* myhead;   // +0x04
  std::uint32_t mysize;           // +0x08
};

// Dualed WQ9J-G. Live VA 0x00409780. bare RET; EAX = node*.
extern "C" NodeIsnil2D_Size0x30* StdTree_BuyHeadNode_Isnil2D_Inferred(void);

// __stdcall RET 0x4
extern "C" TreeShellIsnil2D* __stdcall StdTree_ConstructEmpty_Isnil2D_Inferred(
    TreeShellIsnil2D* shell)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bd1a8).
  NodeIsnil2D_Size0x30* head = StdTree_BuyHeadNode_Isnil2D_Inferred();
  shell->myhead = head;
  head->isnil = 1;
  head->parent = head;
  head->left = head;
  head->right = head;
  shell->mysize = 0;
  return shell;
}

// Scaffold alias
extern "C" TreeShellIsnil2D* __stdcall FUN_00406190(TreeShellIsnil2D* shell)
{
  return StdTree_ConstructEmpty_Isnil2D_Inferred(shell);
}
