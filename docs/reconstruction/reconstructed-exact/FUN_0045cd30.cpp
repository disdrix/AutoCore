// =============================================================================
// FUN_0045cd30  — twin of StdVector_InsertN_Pod28
// -----------------------------------------------------------------------------
// Stable ID: aa_0045cd30
// Address:   0x0045cd30  (autoassault.exe, image base 0x400000)
// Wave:      W34-P 2026-07-29
// Canonical: StdVector_InsertN_Pod28
// See:       reconstructed-exact/StdVector_InsertN_Pod28.cpp
// =============================================================================

// Ghidra inventory name retained. Prefer the named clean unit for porting.
// ABI sealed: ECX=count, EDX=vec*, stack (where, value*), RET 8.
// Stride 0x1c POD insert-n; max 0x9249249; 1.5× grow; trivial 7-dword helpers.

void __fastcall FUN_0045cd30(unsigned int count, int vec, int where_and_value_stack_formals);
// Implementation: StdVector_InsertN_Pod28.cpp
