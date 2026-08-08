// =============================================================================
// FUN_0042a840  (alias of StdTree_Rrotate_Isnil2D_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0042a840
// Address:   0x0042a840–0x0042a88f inclusive (80 B / 0x50)
// Dual A/B:  2026-08-05 WQ9K-J
// See:       StdTree_Rrotate_Isnil2D_Inferred.cpp
// =============================================================================

#include <cstdint>

// __thiscall on node (ECX = x); stack tree; RET 4
extern "C" void __thiscall FUN_0042a840(
    std::int32_t* x /*ECX*/,
    std::int32_t tree /*stack*/)
{
  std::int32_t y = *x;
  *x = *reinterpret_cast<std::int32_t*>(y + 8);
  if (*reinterpret_cast<char*>(
          *reinterpret_cast<std::int32_t*>(y + 8) + 0x2d) == '\0') {
    *reinterpret_cast<std::int32_t**>(
        *reinterpret_cast<std::int32_t*>(y + 8) + 4) = x;
  }
  *reinterpret_cast<std::int32_t*>(y + 4) = x[1];

  if (x == *reinterpret_cast<std::int32_t**>(
          *reinterpret_cast<std::int32_t*>(tree + 4) + 4)) {
    *reinterpret_cast<std::int32_t*>(
        *reinterpret_cast<std::int32_t*>(tree + 4) + 4) = y;
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
