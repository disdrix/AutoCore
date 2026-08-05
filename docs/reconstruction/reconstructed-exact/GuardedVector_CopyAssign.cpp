// =============================================================================
// GuardedVector_CopyAssign
// -----------------------------------------------------------------------------
// Stable ID: aa_0043c730
// Address:   0x0043c730–0x0043c7d6  (autoassault.exe, image base 0x400000)
// System:    STL / guarded container (unlocked assign body)
// Generated: 2026-07-23 scaffold as FUN_0043c730; dual A/B seal 2026-07-29 (W26-G)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

/*
 * Behavioral notes:
 * - Unlocked copy-assign for the vector/ring header shared with GuardedVector_AssignTo.
 * - Retail ABI: EAX=source, EDI=dest; no stack formals; frame SUB/ADD ESP,8; plain RET.
 * - Self-assign no-op. Empty source clears dest via FUN_0040d9c0 (ESI=dest).
 * - source.size <= dest.size → FUN_0043ce90 + FUN_0043c8c0 (fit path).
 * - else → FUN_0043ce90 + FUN_0043cec0 (grow path).
 * - Nested helpers not dualed here; offsets +0x0c begin, +0x10 size sealed.
 * - Name GuardedVector_* is structural (W25-R parent); product/PDB open.
 */

#include <cstdint>

// Header fragment used by this unit (CS at +0x14 lives in parent wrapper only).
struct GuardedVectorHeader {
  uint32_t _unk00;
  void*    slots;      // +0x04
  uint32_t capacity;   // +0x08
  int32_t  begin;      // +0x0c  ring head index
  uint32_t size;       // +0x10
};

// Unowned callees (register/stack conventions internal to helpers).
extern "C" void FUN_0040d9c0(void);   // clear; retail ESI=dest
extern "C" void FUN_0043ce90(void);
extern "C" int* FUN_0043c8c0(int* out, uint32_t a, int b, uint32_t dest, int dest_end);
extern "C" void FUN_0043cec0(uint32_t a, uint32_t b, uint32_t c, uint32_t d,
                             uint32_t e, uint32_t f, uint32_t g);

// Retail: EAX=source, EDI=dest. Clean models explicit pointers.
void GuardedVector_CopyAssign(GuardedVectorHeader* source /*EAX*/,
                              GuardedVectorHeader* dest /*EDI*/)
{
  if (dest == source) {
    return;
  }

  if (source->size == 0) {
    // Retail: MOV ESI, EDI; CALL FUN_0040d9c0
    FUN_0040d9c0();
    return;
  }

  const uint32_t dest_size = dest->size;
  const int32_t src_begin = source->begin;

  if (source->size <= dest_size) {
    FUN_0043ce90();
    uint32_t local_8 = 0;
    uint32_t local_4 = 0;
    FUN_0043c8c0(reinterpret_cast<int*>(&local_8), local_8, static_cast<int>(local_4),
                 reinterpret_cast<uint32_t>(dest),
                 static_cast<int>(dest->size) + dest->begin);
    return;
  }

  FUN_0043ce90();
  FUN_0043cec0(reinterpret_cast<uint32_t>(dest), reinterpret_cast<uint32_t>(dest),
               static_cast<uint32_t>(dest->size + dest->begin),
               reinterpret_cast<uint32_t>(source),
               static_cast<uint32_t>(src_begin + static_cast<int32_t>(dest_size)),
               reinterpret_cast<uint32_t>(source),
               static_cast<uint32_t>(source->size + source->begin));
}
