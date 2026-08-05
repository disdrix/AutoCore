// =============================================================================
// UiToast_UninitializedCopy_0x98
// -----------------------------------------------------------------------------
// Stable ID: aa_004047a0
// Address:   0x004047a0 – 0x0040480b  (autoassault.exe, image base 0x400000)
// System:    missions-progression / shared UI toast vector helpers
// Generated: 2026-07-29 W22-H dual seal (decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   MSVC-style uninitialized_copy for UI toast POD elements (stride 0x98).
//   For each element in [src_begin, src_end): PodCopyElement(dst, src); dst += 0x98.
//   Returns advanced destination end pointer.
//
// ABI:
//   cdecl (plain ret / C3). Stack: src_begin, src_end, dst [, unused_this].
//   EAX = final dst. Wrapper FUN_00404510 (thiscall) reorders vector member args.
//
// CALLEE:
//   UiToast_PodCopyElement_0x98 (FUN_00404710) — 0x26 dwords, ret 8, null-check dst.
// =============================================================================

#include <cstdint>

// Sealed leaf: docs/reconstruction/reconstructed-exact/UiToast_PodCopyElement_0x98.cpp
// (or FUN_00404710.cpp). Signature: stdcall (dst, src); ret 8.
extern "C" void __stdcall UiToast_PodCopyElement_0x98(void* dst, const void* src);

extern "C" void* UiToast_UninitializedCopy_0x98(
    void* src_begin,
    void* src_end,
    void* dst,
    void* /*unused_this_or_alloc*/ = nullptr)
{
    // SEH frame present in retail (LAB_009bd1c0); elided — no throwing work.
    for (; src_begin != src_end;
         src_begin = static_cast<char*>(src_begin) + 0x98) {
        UiToast_PodCopyElement_0x98(dst, src_begin);
        dst = static_cast<char*>(dst) + 0x98;
    }
    return dst;
}

// Ghidra name alias
extern "C" void* FUN_004047a0(void* src_begin, void* src_end, void* dst, void* unused_this = nullptr)
{
    return UiToast_UninitializedCopy_0x98(src_begin, src_end, dst, unused_this);
}
