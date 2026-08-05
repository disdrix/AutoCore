// =============================================================================
// ListTrackedCtx_ClearDestroyAndReset_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00497c80
// Address:   0x00497c80–0x00497cf0 inclusive (113 B / 0x71)
// Module:    autoassault.exe (image base 0x400000)
// System:    Palantir env child / list-tracked ctx (object size 0xC8)
// Wave:      W33-R 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
//            Decompiler loop-break/non-return artifact corrected from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Destroy all non-null entries in the +0x14 pointer bank (count @+0x10),
//   zero the bank, zero +4/+8/+0xC, reset the +0xB8 2D buffer to 0×0 (free
//   if present), set flag@+0 = 1, return 1.
//
// RELATED:
//   Ctor: ListTrackedCtx_Ctor_Inferred (0x00497920, W32-P)
//   Entry dtor helper: FUN_00497900 (eh_vector_dtor 0x28×0xD0 @ entry+0x20)
//   Apply defaults: PalantirEnv_ApplyDefaultScalars_Inferred (0x0048f2d0)
//
// ABI: __thiscall; ECX=self; bare ret; returns 1 in AL.
// =============================================================================

#include <cstdint>

extern "C" void __fastcall FUN_00497900(void* entry);
extern "C" void operator_delete(void* p);
extern "C" std::uint32_t FUN_00788db0(void* dst, unsigned n);
extern "C" bool __thiscall FUN_007874b0(void* grid, int dim0, int dim1);

// Ghidra: FUN_00497c80
extern "C" std::uint8_t __thiscall ListTrackedCtx_ClearDestroyAndReset_Inferred(
    std::uint8_t* self)
{
    // Drain bank: count @ +0x10, pointers @ +0x14 (0xA0 bytes / 40 slots)
    while (*reinterpret_cast<int*>(self + 0x10) >= 1) {
        int next = *reinterpret_cast<int*>(self + 0x10) - 1;
        *reinterpret_cast<int*>(self + 0x10) = next;
        void* entry = *reinterpret_cast<void**>(self + next * 4 + 0x14);
        if (entry != nullptr) {
            FUN_00497900(entry); // thiscall ECX=entry
            operator_delete(entry);
        }
    }

    FUN_00788db0(self + 0x14, 0xA0);
    *reinterpret_cast<std::uint32_t*>(self + 0x04) = 0;
    *reinterpret_cast<std::uint32_t*>(self + 0x08) = 0;
    FUN_007874b0(self + 0xB8, 0, 0); // thiscall ECX=self+0xB8
    *reinterpret_cast<std::uint32_t*>(self + 0x0C) = 0;
    *self = 1;
    return 1;
}

// Ghidra twin name
extern "C" std::uint8_t __thiscall FUN_00497c80(std::uint8_t* self)
{
    return ListTrackedCtx_ClearDestroyAndReset_Inferred(self);
}
