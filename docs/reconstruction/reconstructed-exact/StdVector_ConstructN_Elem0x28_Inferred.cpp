// =============================================================================
// StdVector_ConstructN_Elem0x28_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409d40
// Address:   0x00409d40  (autoassault.exe, image base 0x400000)
// Body:      0x00409d40–0x00409da2 (98 B / 0x62); plain ret; pad/SEH after
// System:    util / container (std::vector construct-N, POD stride 0x28)
// Generated: 2026-08-04 WQ9H-B dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-04).
// Ghidra:    FUN_00409d40
// =============================================================================
//
// PURPOSE:
//   Construct `count` copies of a 0x28-byte POD template at `dest`, advancing
//   destination by 0x28 each iteration (uninitialized_fill / construct-N core).
//
// ABI (sealed from read_memory — decompiler drops ECX formal + dest step):
//   ECX        = const T* value  (template)
//   stack arg0 = T* dest
//   stack arg1 = int count
//   return     = void; plain ret (C3) — caller cleans stack
//
// CALLEE:
//   FUN_00409f30: EAX=dst, EDX=src; copy 10 dwords (0x28 B); null-dst no-op.
//
// PARENTS:
//   FUN_00406e50 Ufill: after this, returns dest + count*0x28.
//   FUN_00406220 push_back fast: construct 1 at end when capacity remains.
//
// SIBLINGS:
//   0x00409db0 ConstructN elem 0xC; 0x00406e50 Ufill wrapper for this unit.
// =============================================================================

#include <cstdint>

struct Pod0x28 {
  uint32_t d[10]; // 0x28 bytes
};

// PodCopy leaf residual (10 dwords); EAX=dst, EDX=src
extern "C" void FUN_00409f30(/*EAX*/ Pod0x28* dst, /*EDX*/ const Pod0x28* src);

// Custom: ECX = value*. Documented register contract.
extern "C" void StdVector_ConstructN_Elem0x28_Inferred(
    const Pod0x28* value /*ECX*/,
    Pod0x28* dest,
    int count)
{
  // SEH frame present in binary (LAB_009bc630); omitted from clean CF body.

  for (; count != 0; --count) {
    // Bytes: mov edx,ebx; mov eax,esi; call FUN_00409f30
    FUN_00409f30(dest, value);
    // Bytes: add esi,0x28
    dest = reinterpret_cast<Pod0x28*>(reinterpret_cast<char*>(dest) + 0x28);
  }
}
