// =============================================================================
// StdVector_ConstructN_Elem12_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00409db0
// Address:   0x00409db0  (autoassault.exe, image base 0x400000)
// Body:      0x00409db0–0x00409e12 inclusive (99 B / 0x63); plain ret; pad after
// System:    util / container (std::vector construct-N, POD stride 0x0C)
// Generated: 2026-08-05 WQ9I-A dual seal (raw + live decompile + read_memory)
// Exactness: Behavior-preserving reconstruction of decompiler CF + byte ABI.
//            Not modernization. Not bit-for-bit vs retail EXE (DEFERRED).
// Dual A/B: accept-with-gaps (2026-08-05).
// Ghidra:    FUN_00409db0
// =============================================================================
//
// PURPOSE:
//   Construct `count` copies of a 0x0C-byte POD template at `dest`, advancing
//   destination by 0x0C each iteration (uninitialized_fill / construct-N core).
//
// ABI (sealed from read_memory — decompiler drops ECX formal + dest step):
//   ECX        = const T* value  (template)
//   stack arg0 = T* dest
//   stack arg1 = int count
//   return     = void; plain ret (C3) — caller cleans stack
//
// CALLEE:
//   FUN_00409f50: EAX=dst, ECX=src; copy 3 dwords (0x0C B); null-dst no-op.
//
// PARENTS:
//   FUN_00406ee0 Ufill: after this, returns dest + count*0x0C.
//   FUN_004062a0 push_back fast: construct 1 at end when capacity remains.
//
// SIBLINGS:
//   0x00409d40 ConstructN elem 0x28; 0x00406ee0 Ufill wrapper for this unit.
// =============================================================================

#include <cstdint>

struct Pod0x0C {
  uint32_t d[3]; // 0x0C bytes
};

// PodCopy leaf residual (3 dwords); EAX=dst, ECX=src
extern "C" void FUN_00409f50(/*EAX*/ Pod0x0C* dst, /*ECX*/ const Pod0x0C* src);

// Custom: ECX = value*. Documented register contract.
extern "C" void StdVector_ConstructN_Elem12_Inferred(
    const Pod0x0C* value /*ECX*/,
    Pod0x0C* dest,
    int count)
{
  // SEH frame present in binary (LAB_009bc620); omitted from clean CF body.

  for (; count != 0; --count) {
    // Bytes: mov ecx,ebx; mov eax,esi; call FUN_00409f50
    FUN_00409f50(dest, value);
    // Bytes: add esi,0x0C
    dest = reinterpret_cast<Pod0x0C*>(reinterpret_cast<char*>(dest) + 0x0C);
  }
}
