// =============================================================================
// FUN_0044e010 — clean twin alias
// Canonical: StdTree_LeftRotate_Isnil2D_Inferred
// See: StdTree_LeftRotate_Isnil2D_Inferred.cpp
// WQ9K-I dual seal 2026-08-05
// =============================================================================

#include <cstdint>

struct StdTreeNode_Isnil2D {
  StdTreeNode_Isnil2D *left;
  StdTreeNode_Isnil2D *parent;
  StdTreeNode_Isnil2D *right;
};

struct StdTreeMapShell_Isnil2D {
  void *pad0;
  StdTreeNode_Isnil2D *myhead;
};

extern "C" void __thiscall StdTree_LeftRotate_Isnil2D_Inferred(
    StdTreeNode_Isnil2D *x, StdTreeMapShell_Isnil2D *map);

extern "C" void __thiscall FUN_0044e010(StdTreeNode_Isnil2D *x,
                                        StdTreeMapShell_Isnil2D *map)
{
  StdTree_LeftRotate_Isnil2D_Inferred(x, map);
}
