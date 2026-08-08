// =============================================================================
// FUN_004192f0  →  StdTree_Rrotate_Isnil29_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004192f0
// Address:   0x004192f0  (autoassault.exe, image base 0x400000)
// System:    MSVC std::_Tree right-rotate (isnil@+0x29)
// Generated: 2026-08-04 WQ9D-D dual (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite of decompiler control flow.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Prefer named clean: StdTree_Rrotate_Isnil29_Inferred.cpp

#include <cstdint>

// Node: left@0 parent@4 right@8 isnil@+0x29
// Tree: this+4 header; root = *(header+4)

// __thiscall: ECX = tree*, stack = node* x; void; RET 4
void __thiscall StdTree_Rrotate_Isnil29_Inferred(std::int32_t tree, std::int32_t* x)
{
  std::int32_t y = *x;
  *x = *reinterpret_cast<std::int32_t*>(y + 8);
  if (*reinterpret_cast<char*>(*reinterpret_cast<std::int32_t*>(y + 8) + 0x29) == '\0') {
    *reinterpret_cast<std::int32_t**>(*reinterpret_cast<std::int32_t*>(y + 8) + 4) = x;
  }
  *reinterpret_cast<std::int32_t*>(y + 4) = x[1];
  if (x == *reinterpret_cast<std::int32_t**>(*reinterpret_cast<std::int32_t*>(tree + 4) + 4)) {
    *reinterpret_cast<std::int32_t*>(*reinterpret_cast<std::int32_t*>(tree + 4) + 4) = y;
    *reinterpret_cast<std::int32_t**>(y + 8) = x;
    x[1] = y;
    return;
  }
  std::int32_t* parent = reinterpret_cast<std::int32_t*>(x[1]);
  if (x == reinterpret_cast<std::int32_t*>(parent[2])) {
    parent[2] = y;
    *reinterpret_cast<std::int32_t**>(y + 8) = x;
    x[1] = y;
    return;
  }
  *parent = y;
  *reinterpret_cast<std::int32_t**>(y + 8) = x;
  x[1] = y;
}

void __thiscall FUN_004192f0(std::int32_t param_1, std::int32_t* param_2)
{
  StdTree_Rrotate_Isnil29_Inferred(param_1, param_2);
}
