// =============================================================================
// GuardedVector_ClearAndSwap
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c660
// Address:   0x0043c660–0x0043c6e8  (autoassault.exe, image base 0x400000)
// Ghidra:    FUN_0043c660
// System:    STL / guarded ring-deque container
// Dual:      W29-A 2026-07-29
// Exactness: Behavior-preserving. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// Retail ABI: ESI = container A, EDI = container B (optional CS).
// Clear A via GuardedVector_Resize(0), then swap ring headers with B under
// optional critical section on B (+0x14 CS, +0x2c flag).
// Name structural (GuardedVector_* family); product/PDB open.
// =============================================================================

#include <cstdint>
#include <windows.h>

struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;     // +0x04
  int32_t  capacity;  // +0x08
  int32_t  begin;     // +0x0c
  int32_t  size;      // +0x10
  // Extended on EDI (lock owner):
  // CRITICAL_SECTION cs; // +0x14
  // ...
  // char lock_flag;      // +0x2c
};

struct GuardedVectorLocked : GuardedVectorHeader {
  CRITICAL_SECTION cs;     // +0x14
  uint8_t _pad[0x2c - 0x14 - sizeof(CRITICAL_SECTION)];
  // If CRITICAL_SECTION size differs, flag is still at absolute +0x2c on object.
};

// Sealed W28-D: EAX=container, ECX=new_size.
extern "C" void GuardedVector_Resize(uint32_t new_size /*ECX*/,
                                     GuardedVectorHeader* container /*EAX*/);

// Retail: ESI=A, EDI=B; plain RET after SEH frame ADD ESP,0x10.
void GuardedVector_ClearAndSwap(GuardedVectorHeader* a /*ESI*/,
                                GuardedVectorHeader* b /*EDI*/)
{
  // Flag/CS live on B at absolute +0x2c / +0x14 (not part of swapped header).
  char* b_bytes = reinterpret_cast<char*>(b);
  const bool locked = b_bytes[0x2c] != 0;
  CRITICAL_SECTION* cs = reinterpret_cast<CRITICAL_SECTION*>(b_bytes + 0x14);

  if (locked) {
    EnterCriticalSection(cs);
  }

  GuardedVector_Resize(/*new_size*/ 0, a);

  uint32_t t;
  t = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x04);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x04) =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x04);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x04) = t;

  t = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x08);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x08) =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x08);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x08) = t;

  t = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x0c);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x0c) =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x0c);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x0c) = t;

  t = *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x10);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(a) + 0x10) =
      *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x10);
  *reinterpret_cast<uint32_t*>(reinterpret_cast<char*>(b) + 0x10) = t;

  if (locked) {
    LeaveCriticalSection(cs);
  }
}
