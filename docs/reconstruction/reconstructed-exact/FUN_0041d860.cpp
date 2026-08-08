// =============================================================================
// FUN_0041d860  (scaffold twin of StdTree_Buynode_CharKey_Isnil21_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d860
// Address:   0x0041d860–0x0041d8e5 inclusive (134 B / 0x86)
// System:    skills-abilities / MSVC std::_Tree node buy — char key, isnil@+0x21
// Generated: 2026-08-05 R13-023 dual seal (scaffold 2026-07-23)
// Exactness: Behavior-preserving rewrite of decompiler CF + sealed bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
// Canonical named unit:
//   docs/reconstruction/reconstructed-exact/StdTree_Buynode_CharKey_Isnil21_Inferred.cpp

#include <cstdint>

// Forward to named clean implementation (same translation unit expectations).
extern "C" void* __thiscall FUN_0041c140(void* self, const void* src_payload);
extern "C" void* operator_new(std::size_t size);

extern "C" void* __stdcall FUN_0041d860(
    void* left,
    void* parent,
    void* right,
    const unsigned char* value,
    unsigned char color)
{
  // SEH frame omitted (retail: ExceptionList / LAB_009bd7d1).
  unsigned char* node = static_cast<unsigned char*>(operator_new(0x24));
  if (node != nullptr) {
    *reinterpret_cast<void**>(node + 0x00) = left;
    *reinterpret_cast<void**>(node + 0x04) = parent;
    *reinterpret_cast<void**>(node + 0x08) = right;
    node[0x0C] = value[0];  // char key
    FUN_0041c140(node + 0x10, value + 4);
    node[0x20] = color;
    node[0x21] = 0;  // isnil
  }
  return node;
}
