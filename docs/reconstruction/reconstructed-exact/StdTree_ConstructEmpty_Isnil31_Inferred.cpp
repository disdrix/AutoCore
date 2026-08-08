// =============================================================================
// StdTree_ConstructEmpty_Isnil31_Inferred  (FUN_00405f20)
// -----------------------------------------------------------------------------
// Stable ID: aa_00405f20
// Address:   0x00405f20–0x00405f7a exclusive (90 B / 0x5A)
// System:    MSVC std::_Tree empty construct — isnil@+0x31 / node 0x38
// Generated: 2026-08-04 WQ9K-C dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct an empty tree/map shell: buy isnil31 head (0x38), install as
//   _Myhead, force isnil=1, self-link L/P/R, zero _Mysize.
//
// ABI: __stdcall; 1 stack arg (shell*); RET 0x4; EAX = shell*.
// Head buy: StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred (0x00409180) dualed WQ9J-F.
// Caller (1): Client ctor FUN_009495c0 @ 0x00949d37 (subobject client+0xF14).
// Reject Named_CalleeOf_*Client_Constructor* scaffold as product name.
//
// Dual: reviews/A|B_aa_00405f20_StdTree_ConstructEmpty_Isnil31_Inferred.md

#include <cstdint>

struct NodeIsnil31_Size0x38 {
  NodeIsnil31_Size0x38* left;     // +0x00
  NodeIsnil31_Size0x38* parent;   // +0x04
  NodeIsnil31_Size0x38* right;    // +0x08
  // +0x0C .. +0x2F value region (Val36) — not written by buyhead/this unit
  std::uint8_t color;             // +0x30
  std::uint8_t isnil;             // +0x31
  // pad to 0x38
};

struct TreeShellIsnil31 {
  // +0x00: allocator/comp region (untouched by this unit)
  NodeIsnil31_Size0x38* myhead;   // +0x04
  std::uint32_t mysize;           // +0x08
};

// Dualed WQ9J-F. Live VA 0x00409180. bare RET; EAX = node*.
extern "C" NodeIsnil31_Size0x38* StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred(void);

// __stdcall RET 0x4
extern "C" TreeShellIsnil31* __stdcall StdTree_ConstructEmpty_Isnil31_Inferred(
    TreeShellIsnil31* shell)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bdb18).
  NodeIsnil31_Size0x38* head = StdTree_BuyHeadNode_Isnil31_Size0x38_Inferred();
  shell->myhead = head;
  head->isnil = 1;
  head->parent = head;
  head->left = head;
  head->right = head;
  shell->mysize = 0;
  return shell;
}

// Scaffold alias
extern "C" TreeShellIsnil31* __stdcall FUN_00405f20(TreeShellIsnil31* shell)
{
  return StdTree_ConstructEmpty_Isnil31_Inferred(shell);
}
