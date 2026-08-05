// =============================================================================
// FUN_00480ca0  (scaffold alias → StdVector_PushBack12_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00480ca0
// Address:   0x00480ca0  (autoassault.exe, image base 0x400000)
// Body:      0x00480ca0–0x00480d17 (120 bytes)
// System:    container / std::vector<Element12> push
// Dual seal: 2026-07-29 W18-O
// Canonical clean: StdVector_PushBack12_Inferred.cpp
// Exactness: Decompiler-shaped control flow; ABI notes in plate.
// Bit-for-bit / runtime / diff: DEFERRED.
// =============================================================================

#include <cstdint>

// Decompiler surface (register names noisy). Prefer StdVector_PushBack12_Inferred.
// Real ABI: EAX=vector*, EBX=const Element12* (12 bytes).

extern "C" void FUN_0042acc0(...);
extern "C" void FUN_0042a710(...);

void __fastcall FUN_00480ca0(std::uint32_t param_1)
{
    int iVar1;
    int in_EAX;              // vector* (EAX)
    std::uint32_t unaff_EBX; // Element12* (EBX) — decompiler type weak
    std::uint32_t local_4;

    iVar1 = *reinterpret_cast<int*>(in_EAX + 4);
    local_4 = param_1;
    if ((iVar1 != 0) &&
        (static_cast<unsigned>((*reinterpret_cast<int*>(in_EAX + 8) - iVar1) / 0xc) <
         static_cast<unsigned>((*reinterpret_cast<int*>(in_EAX + 0xc) - iVar1) / 0xc))) {
        iVar1 = *reinterpret_cast<int*>(in_EAX + 8);
        FUN_0042acc0(param_1); // real: count=1, dest=end, src=EBX
        *reinterpret_cast<int*>(in_EAX + 8) = iVar1 + 0xc;
        return;
    }
    FUN_0042a710(&local_4, *reinterpret_cast<std::uint32_t*>(in_EAX + 8), unaff_EBX);
    return;
}
