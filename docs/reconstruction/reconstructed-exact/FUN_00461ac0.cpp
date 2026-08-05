// =============================================================================
// FUN_00461ac0  — twin of RcElem28_CopyCtor_EsiEdi
// -----------------------------------------------------------------------------
// Stable ID: aa_00461ac0
// Address:   0x00461ac0–0x00461b11 exclusive (81 B)
// Wave:      W35-N OWN-ONLY 2026-07-29
// Canonical: RcElem28_CopyCtor_EsiEdi
// See:       reconstructed-exact/RcElem28_CopyCtor_EsiEdi.cpp
// =============================================================================

#include <cstdint>

// Implementation: RcElem28_CopyCtor_EsiEdi.cpp
// ABI: ESI=src RcElem28*, EDI=dst RcElem28*; EAX=dst; plain RET.
// Ghidra decompile shows void with unaff_ESI/unaff_EDI — register contract.

extern "C" void* RcElem28_CopyCtor_EsiEdi(const void* src, void* dst);

extern "C" void FUN_00461ac0(void)
{
    // Call sites set ESI/EDI before CALL; this symbol is a name anchor only.
    (void)RcElem28_CopyCtor_EsiEdi;
}
