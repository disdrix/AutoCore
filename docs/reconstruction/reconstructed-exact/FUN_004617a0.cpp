// =============================================================================
// FUN_004617a0  — twin of StdVector_InsertN_RcElem28
// -----------------------------------------------------------------------------
// Stable ID: aa_004617a0
// Address:   0x004617a0  (autoassault.exe, image base 0x400000)
// Wave:      W34-P 2026-07-29
// Canonical: StdVector_InsertN_RcElem28
// See:       reconstructed-exact/StdVector_InsertN_RcElem28.cpp
// =============================================================================

// Ghidra inventory name retained. Prefer the named clean unit for porting.
// ABI sealed: ECX=value*, stack (vec*, where, count), RET 0xC.
// Stride 0x1c refcounted-elem insert-n; resource @+0x10 AddRef/Release; 1.5× grow.

void FUN_004617a0(int vec, int where, unsigned int count /* + ECX value* */);
// Implementation: StdVector_InsertN_RcElem28.cpp
