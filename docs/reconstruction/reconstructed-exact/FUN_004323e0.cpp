// =============================================================================
// FUN_004323e0  (alias plate → CxImage_Create)
// -----------------------------------------------------------------------------
// Stable ID: aa_004323e0
// Address:   0x004323e0  (autoassault.exe, image base 0x400000)
// Prefer:    reconstructed-exact/CxImage_Create.cpp
// Dual A/B:  2026-07-29 W22-Q
// =============================================================================

// Canonical clean plate lives in CxImage_Create.cpp.
// This file retained as Ghidra-name alias for path stability.

#include <cstdint>

// Retail ABI: EBX=this, EAX=height, stack (width,bpp,type), RET 12.
// See CxImage_Create for full CF + offsets.

int32_t* FUN_004323e0(int32_t width, uint32_t bpp, uint32_t type);
// implementation: CxImage_Create (named plate)
