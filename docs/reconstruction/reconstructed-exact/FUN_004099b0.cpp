// =============================================================================
// FUN_004099b0  — scaffold twin of StdTree_NodeCtor_Val16_Isnil21_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004099b0
// Address:   0x004099b0  (autoassault.exe, image base 0x400000)
// Body:      0x004099b0–0x004099f3 exclusive (67 B / 0x43)
// Agent:     WQ9I-C OWN-ONLY dual 2026-08-05
// Exactness: Forwards to named clean source. Not modernization.
// Terminal:  false
// =============================================================================

#include <cstdint>

struct NodeIsnil21;

extern "C" NodeIsnil21 *__thiscall StdTree_NodeCtor_Val16_Isnil21_Inferred(
    NodeIsnil21 *self,
    NodeIsnil21 *left,
    NodeIsnil21 *parent,
    NodeIsnil21 *right,
    const std::uint32_t *value4,
    std::uint8_t color);

extern "C" NodeIsnil21 *__thiscall FUN_004099b0(
    NodeIsnil21 *self,
    NodeIsnil21 *left,
    NodeIsnil21 *parent,
    NodeIsnil21 *right,
    const std::uint32_t *value4,
    std::uint8_t color)
{
  return StdTree_NodeCtor_Val16_Isnil21_Inferred(
      self, left, parent, right, value4, color);
}
