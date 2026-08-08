// =============================================================================
// Object_CopyTfid16At228_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_0040aff0
// Address:   0x0040aff0  (autoassault.exe, image base 0x400000)
// System:    identity / TFID
// Ghidra:    FUN_0040aff0
// Dual:      2026-08-04 WQ9R-B OWN-ONLY (WQ-009 residual)
//
// Purpose: Copy the 16-byte TFID identity blob stored at this+0x228 into the
//          caller-provided TFID_16 out buffer. Leaf; no mutation of source.
//
// ABI:     __thiscall
//          ECX = object* (layout has TFID_16 at +0x228)
//          stack: TFID_16 *out
//          ret 4
//          EAX = out (entry pointer preserved)
//
// Exactness: Behavior-preserving rewrite of decompiler CF + live read_memory.
// Bit-for-bit vs retail EXE: DEFERRED.
// Runtime / differential: OPEN.
// =============================================================================

#include <cstdint>

struct TFID_16 {
  std::uint32_t dwCoidLo;
  std::uint32_t dwCoidHi;
  std::uint32_t uGlobalAndPad; // bGlobal + pads (product field names residual)
  std::uint32_t uPadTail;
};

// Returns out (EAX) for chain convenience; product may be void.
TFID_16 *__thiscall Object_CopyTfid16At228_Inferred(void *thisObj, TFID_16 *out)
{
  // Bytes: add ecx, 0x228; then four dword moves to *out
  const auto *src = reinterpret_cast<const std::uint32_t *>(
      reinterpret_cast<const char *>(thisObj) + 0x228);
  out->dwCoidLo = src[0];
  out->dwCoidHi = src[1];
  out->uGlobalAndPad = src[2];
  out->uPadTail = src[3];
  return out;
}
