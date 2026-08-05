// =============================================================================
// FUN_0043d770
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d770
// Address:   0x0043d770–0x0043d7c7 exclusive (87 B / 0x57)
// Named:     StdMap_EraseEq_UintKey_Isnil15_Inferred
// Wave:      W38-O 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Erase-by-key with count on isnil@+0x15 uint-key ordered map.
//   See StdMap_EraseEq_UintKey_Isnil15_Inferred.cpp for full notes.
//
// ABI: EAX=map*, ECX=const uint32_t* key, plain RET, returns count.
//
// =============================================================================

#include <cstdint>

struct TreeNodeIsnil15 {
  TreeNodeIsnil15* left;
  TreeNodeIsnil15* parent;
  TreeNodeIsnil15* right;
  uint32_t         key;
};

struct StdMapIsnil15 {
  void*            pad0;
  TreeNodeIsnil15* head;
  uint32_t         size;
};

extern "C" void __fastcall FUN_0043dc20(
    StdMapIsnil15* map, const uint32_t* key, TreeNodeIsnil15** out_pair);
extern "C" void __fastcall FUN_0046f100(void*, TreeNodeIsnil15** it);
extern "C" TreeNodeIsnil15** FUN_00439050(
    TreeNodeIsnil15** out_it, TreeNodeIsnil15* begin, TreeNodeIsnil15* end);

// Ghidra symbol — register formals map@EAX, key@ECX.
extern "C" int FUN_0043d770(void /*EAX=map, ECX=key**/)
{
  // Portable stand-in: real entry receives map in EAX and key* in ECX.
  // Ports must bind those registers; body CF below matches retail.

  StdMapIsnil15* map = nullptr;          // EAX
  const uint32_t* key = nullptr;         // ECX
  TreeNodeIsnil15* pair[2];
  int count = 0;

  FUN_0043dc20(map, key, pair);
  TreeNodeIsnil15* it = pair[0];
  TreeNodeIsnil15* end_it = pair[1];
  while (it != end_it) {
    count += 1;
    FUN_0046f100(nullptr, &it);
  }
  FUN_00439050(pair, pair[0], pair[1]); // EDI=map in retail
  return count;
}
