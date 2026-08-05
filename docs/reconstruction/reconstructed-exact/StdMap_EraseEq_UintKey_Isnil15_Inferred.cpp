// =============================================================================
// StdMap_EraseEq_UintKey_Isnil15_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0043d770
// Address:   0x0043d770–0x0043d7c7 exclusive (87 B / 0x57)
// Module:    autoassault.exe (image base 0x400000)
// System:    STL / MSVC _Tree — uint-key erase-by-key with count (isnil@+0x15)
// Wave:      W38-O 2026-08-04
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Erase all nodes whose key equals *key from an ordered map/multimap and
//   return the number of nodes removed (MSVC map::erase(key) shape).
//
// ABI (bytes-sealed; decompiler omits registers):
//   EAX = map*          (head pointer at map+4; size at map+8 — via erase helper)
//   ECX = const uint32_t* key
//   plain RET (C3)
//   returns int count in EAX
//
// NODE LAYOUT (from callees FUN_0043dc20 / FUN_0046f100 / FUN_00439050):
//   +0x00  left
//   +0x04  parent
//   +0x08  right
//   +0x0C  key (uint32)
//   +0x15  isnil (char)   — NOT Val12 isnil@+0x19
//
// CALLEES:
//   FUN_0043dc20  equal_range  (ECX=map, EBX=key*, EAX=&{begin,end})
//   FUN_0046f100  tree successor (++it)  (EDX=&it)
//   FUN_00439050  erase [begin,end)      (EDI=map; stack out, begin, end)
//
// CALLERS:
//   FUN_00970fc0 AssPreloader_DrainAcRingToTree_Inferred (W37-AD) —
//   fail-flag path: EAX=host+0xDC tree, ECX=&key.
//
// BYTES (87 B):
//   83ec0c535556578bf88bd98d4424148bcfe89a0400008b6c24148b5c241833f6
//   3beb896c2410741aeb068d9b000000008d54241083c601e854190300395c2410
//   75ee53558d44241850e892b8ffff5f8bc65e5d5b83c40cc3
//
// =============================================================================

#include <cstdint>

struct TreeNodeIsnil15 {
  TreeNodeIsnil15* left;    // +0x00
  TreeNodeIsnil15* parent;  // +0x04
  TreeNodeIsnil15* right;   // +0x08
  uint32_t         key;     // +0x0C
  // … value payload …
  // char isnil @ +0x15
};

struct StdMapIsnil15 {
  void*            pad0;    // +0x00
  TreeNodeIsnil15* head;    // +0x04
  uint32_t         size;    // +0x08 (touched by full-clear erase path)
};

// Ghidra: FUN_0043dc20 — equal_range into *out_pair
extern "C" void __fastcall FUN_0043dc20(
    StdMapIsnil15* map /*ECX*/,
    /*EBX*/ const uint32_t* key,
    /*EAX*/ TreeNodeIsnil15** out_pair /* [0]=begin, [1]=end */);

// Ghidra: FUN_0046f100 — in-place tree successor
extern "C" void __fastcall FUN_0046f100(
    void* /*unused*/,
    TreeNodeIsnil15** it /*EDX*/);

// Ghidra: FUN_00439050 — erase range; map in EDI
extern "C" TreeNodeIsnil15** FUN_00439050(
    TreeNodeIsnil15** out_it,
    TreeNodeIsnil15* begin,
    TreeNodeIsnil15* end
    /*EDI=map*/);

// Ghidra: FUN_0043d770
// Register ABI: map in EAX, key* in ECX (not ECX-thiscall).
extern "C" int StdMap_EraseEq_UintKey_Isnil15_Inferred(
    /*EAX*/ StdMapIsnil15* map,
    /*ECX*/ const uint32_t* key)
{
  TreeNodeIsnil15* pair[2];
  TreeNodeIsnil15* begin;
  TreeNodeIsnil15* end_it;
  int count;

  // equal_range
  FUN_0043dc20(map, key, pair);
  begin = pair[0];
  end_it = pair[1];

  count = 0;
  {
    TreeNodeIsnil15* it = begin;
    while (it != end_it) {
      count += 1;
      FUN_0046f100(nullptr, &it);
    }
  }

  // erase [begin, end)
  // Retail keeps map in EDI across the call (set at entry from EAX).
  FUN_00439050(pair /*out scratch*/, begin, end_it /*EDI=map*/);

  return count;
}
