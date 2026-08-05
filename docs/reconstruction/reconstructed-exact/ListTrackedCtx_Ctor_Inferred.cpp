// =============================================================================
// ListTrackedCtx_Ctor_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_00497920
// Address:   0x00497920–0x0049799c inclusive (125 B / 0x7D)
// Module:    autoassault.exe (image base 0x400000)
// System:    Palantir env child / list-tracked ctx (object size 0xC8)
// Wave:      W32-P 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler CF + body hex.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Complete thiscall ctor for the 0xC8 list-tracked context owned by
//   PalantirEnv at +0x100. Stores parent at +0xC4, publishes DAT_00b035cc,
//   installs flag/capacity/count and zero-fills the +0x14 bank (0xA0 bytes).
//
// SOLE CALLER: PalantirEnv_Ctor_Inferred (0x00492dd0):
//   new(0xC8); if (p) ListTrackedCtx_Ctor(p, parent); env[+0x100] = p;
//
// RELATED: Ctx_ClearListTrackedOwnedAtScaledXY (0x00497a30, W31-D) uses
//   host = *(*(ctx+0xC4)+0xE898).
//
// ABI: __thiscall; stack parent; ret 4; returns this.
// =============================================================================

#include <cstdint>

// Ghidra callees (roles sealed structurally)
extern "C" void __fastcall FUN_00787520(void* sub);           // zeros 3 dwords
extern "C" std::uint32_t FUN_00788db0(void* dst, unsigned n); // memset-style zero → 1

// Process global current ctx
extern "C" void* DAT_00b035cc;

// Ghidra: FUN_00497920
extern "C" std::uint8_t* __thiscall ListTrackedCtx_Ctor_Inferred(
    std::uint8_t* self,
    void* parent)
{
    // SEH: LAB_009a0dbe (omitted in clean; present in retail)
    FUN_00787520(self + 0xB8);

    *self = 1;
    *reinterpret_cast<std::uint32_t*>(self + 0x04) = 0;
    *reinterpret_cast<std::uint32_t*>(self + 0x08) = 0;
    *reinterpret_cast<std::uint32_t*>(self + 0x0C) = 5; // capacity
    *reinterpret_cast<std::uint32_t*>(self + 0x10) = 0; // count

    FUN_00788db0(self + 0x14, 0xA0); // zero bank +0x14 .. +0xB3

    *reinterpret_cast<std::uint32_t*>(self + 0xB4) = 0;
    *reinterpret_cast<void**>(self + 0xC4) = parent;

    DAT_00b035cc = self;
    return self;
}

// Ghidra twin name
extern "C" std::uint8_t* __thiscall FUN_00497920(std::uint8_t* self, void* parent)
{
    return ListTrackedCtx_Ctor_Inferred(self, parent);
}
