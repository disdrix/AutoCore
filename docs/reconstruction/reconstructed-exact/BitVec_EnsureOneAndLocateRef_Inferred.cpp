// =============================================================================
// BitVec_EnsureOneAndLocateRef_Inferred  (FUN_004363b0)
// -----------------------------------------------------------------------------
// Stable ID: aa_004363b0
// Address:   0x004363b0  (autoassault.exe, image base 0x400000)
// System:    packed bit-vector storage
// Generated: 2026-08-04 W38-C (sealed from decompile + read_memory + sole caller)
// Exactness: Behavior-preserving rewrite. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE: Ensure capacity for one bit via FUN_004364b0, then write a bit
// reference {bit_in_dword, dword*} to *out and return out.
//
// ABI (custom):
//   EAX = host*          (begin of dword words at host+8)
//   EDI = out*           (two dwords)
//   stack: bitAdd, dwordPos*, param3
//   returns out* in EAX; RET 0x0C
//
// Reject scaffold Named_CalleeOf_Named_gfxBody_* as product name (caller plate only).

#include <cstdint>

struct BitRef {
  uint32_t bit;      // 0..31
  uint32_t* word;    // address of containing dword
};

struct BitVecHost {
  // layout unknown except:
  // +8: uint32_t* begin  (dword-packed bits)
  uint8_t _pad[8];
  uint32_t* begin;
};

// Not OWN — ensure/insert; EAX register count = 1 at call site
extern "C" void __thiscall FUN_004364b0(BitVecHost* host, int bitAdd, uint32_t* dwordPos, uint32_t param3);

// FUN_004363b0 — register formals modeled as explicit params for clarity
extern "C" BitRef* BitVec_EnsureOneAndLocateRef_Inferred(
    BitVecHost* host,       // EAX
    int bitAdd,             // stack0
    uint32_t* dwordPos,     // stack1
    uint32_t param3,        // stack2
    BitRef* out)            // EDI
{
  uint32_t* old_begin = host->begin;

  // retail: mov eax,1; mov ecx,host; call FUN_004364b0
  // FUN_004364b0 uses in_EAX as bit count (=1)
  FUN_004364b0(host, bitAdd, dwordPos, param3);

  uint32_t* begin = host->begin;
  uint32_t bitIndex =
      (static_cast<uint32_t>(reinterpret_cast<int>(dwordPos) - reinterpret_cast<int>(old_begin)) >> 2) * 32u
      + static_cast<uint32_t>(bitAdd);

  out->bit = bitIndex & 31u;
  out->word = begin + (bitIndex >> 5);
  return out;
}

extern "C" BitRef* FUN_004363b0(
    BitVecHost* host, int bitAdd, uint32_t* dwordPos, uint32_t param3, BitRef* out)
{
  return BitVec_EnsureOneAndLocateRef_Inferred(host, bitAdd, dwordPos, param3, out);
}
