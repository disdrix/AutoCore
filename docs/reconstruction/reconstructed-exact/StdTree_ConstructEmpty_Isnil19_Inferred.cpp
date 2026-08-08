// =============================================================================
// StdTree_ConstructEmpty_Isnil19_Inferred  (FUN_0040b3b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_0040b3b0
// Address:   0x0040b3b0–0x0040b40a exclusive (90 B / 0x5A)
// System:    MSVC std::_Tree empty construct — isnil@+0x19 / node 0x1c
// Generated: 2026-08-05 R13-017 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Construct an empty tree/map shell: buy isnil19 head (0x1c), install as
//   _Myhead, force isnil=1, self-link L/P/R, zero _Mysize.
//
// ABI: __stdcall; 1 stack arg (shell*); RET 0x4; EAX = shell*.
// Head buy: residual FUN_0040bfc0 (operator_new(0x1c); color@+0x18=1; isnil@+0x19=0).
// Caller (1): MissionTracker_FillTrackedTargetSlots_Inferred (0x0092b2a0) @ 0x0092b319
//   LEA EAX,[ESP+0x38]; PUSH EAX; CALL — stack-local shell.
// Partition system inventory-transfer is host-queue only; unit is generic STL.
//
// Dual: reviews/A|B_aa_0040b3b0_StdTree_ConstructEmpty_Isnil19_Inferred.md
// Report: docs/agents/task-dual-ab-0040b3b0-r13-report.md

#include <cstdint>

struct NodeIsnil19_Size0x1c {
  NodeIsnil19_Size0x1c* left;     // +0x00
  NodeIsnil19_Size0x1c* parent;   // +0x04
  NodeIsnil19_Size0x1c* right;    // +0x08
  // +0x0C .. +0x17 value region (Val12) — not written by this unit
  std::uint8_t color;             // +0x18 (set by residual buyhead)
  std::uint8_t isnil;             // +0x19
  // pad to 0x1c
};

struct TreeShellIsnil19 {
  // +0x00: allocator/comp region (untouched by this unit)
  NodeIsnil19_Size0x1c* myhead;   // +0x04
  std::uint32_t mysize;           // +0x08
};

// Residual buyhead @ 0x0040bfc0 — NOT dualled in R13-017 OWN.
// operator_new(0x1c); L/P/R=0; color@+0x18=1; isnil@+0x19=0; bare return EAX.
extern "C" NodeIsnil19_Size0x1c* StdTree_BuyHeadNode_Isnil19_Size0x1c_Inferred(void);

// __stdcall RET 0x4
extern "C" TreeShellIsnil19* __stdcall StdTree_ConstructEmpty_Isnil19_Inferred(
    TreeShellIsnil19* shell)
{
  // SEH frame omitted in plate (present in retail: ExceptionList / LAB_009bda98).
  NodeIsnil19_Size0x1c* head = StdTree_BuyHeadNode_Isnil19_Size0x1c_Inferred();
  shell->myhead = head;
  head->isnil = 1;
  head->parent = head;
  head->left = head;
  head->right = head;
  shell->mysize = 0;
  return shell;
}

// Scaffold alias
extern "C" TreeShellIsnil19* __stdcall FUN_0040b3b0(TreeShellIsnil19* shell)
{
  return StdTree_ConstructEmpty_Isnil19_Inferred(shell);
}
