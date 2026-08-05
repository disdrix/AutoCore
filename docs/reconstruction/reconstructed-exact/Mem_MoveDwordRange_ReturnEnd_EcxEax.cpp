// =============================================================================
// Mem_MoveDwordRange_ReturnEnd_EcxEax
// -----------------------------------------------------------------------------
// Stable ID: aa_0040c7c0
// Address:   0x0040c7c0  (autoassault.exe, image base 0x400000)
// Body:      0x0040c7c0–0x0040c7e2 (35 bytes through ret 4)
// System:    stl-helpers / POD relocate
// Generated: 2026-07-29 W22-T dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Move dword-aligned half-open range [srcBegin, srcEnd) into dest via memmove.
//   Size = ((srcEnd - srcBegin) >> 2) * 4. Return dest + size.
//
// ABI (custom — NOT pure thiscall object method):
//   ECX      = srcBegin
//   EAX (in) = srcEnd (exclusive pointer-as-int)
//   stack    = dest  (one arg; ret 4)
//   EAX out  = dest + size
//
// Algorithm twin: Mem_MoveDwordRange_ReturnEnd (0x004e2e80) — same math, stack stdcall ret 0xC.
// CALLEE: memmove (IAT @ 0x009c652c)
// Ghidra: FUN_0040c7c0

#include <cstring>
#include <cstddef>
#include <cstdint>

// Portable semantic equivalent (normal C++ calling convention):
void *Mem_MoveDwordRange_ReturnEnd_EcxEax(void *srcBegin, int srcEnd, void *dest)
{
  size_t size =
      (static_cast<size_t>(srcEnd - reinterpret_cast<int>(srcBegin)) >> 2) * 4;
  void *p = memmove(dest, srcBegin, size);
  return reinterpret_cast<void *>(reinterpret_cast<int>(p) + static_cast<int>(size));
}

// Retail call shape (for hooks only):
//   mov ecx, srcBegin
//   mov eax, srcEnd
//   push dest
//   call FUN_0040c7c0   ; ret 4
