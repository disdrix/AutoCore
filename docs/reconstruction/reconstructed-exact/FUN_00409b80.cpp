// =============================================================================
// FUN_00409b80  (alias of StdTree_DestroyStringAt0C_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00409b80
// Address:   0x00409b80–0x00409bc0 inclusive (65 B / 0x41)
// Wave:      2026-08-05 WQ9K-A OWN dual A/B seal
// Exactness: Behavior-preserving; ABI from machine bytes (stdcall RET 4).
// Bit-for-bit / runtime / diff: OPEN
// =============================================================================

#include <cstdint>
#include <string>

extern "C" void __stdcall FUN_00409b80(void *node)
{
  auto *str = reinterpret_cast<std::string *>(static_cast<char *>(node) + 0x0c);
  str->~basic_string();
}

// Named clean: StdTree_DestroyStringAt0C_Inferred.cpp
