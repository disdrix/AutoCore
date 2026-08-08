// =============================================================================
// operator_delete__  (twin / Ghidra decomp encoding of operator delete[])
// -----------------------------------------------------------------------------
// Stable ID: aa_0048981c
// Address:   0x0048981c  (autoassault.exe, image base 0x400000)
// Canonical: operator_delete_array  → see operator_delete_array.cpp
// Wave:      R10-010 OWN-ONLY dual (2026-08-05) — scaffold refreshed
// Exactness: IAT thunk; CRT body external.
// =============================================================================

/*
 * Twin plate for Ghidra symbol operator_delete__.
 * Authoritative clean: reconstructed-exact/operator_delete_array.cpp
 *
 * Bytes @ 0x0048981c: FF 25 98 66 9C 00  = JMP [0x009c6698]
 */

extern "C" void __cdecl operator_delete_array(void *block);

extern "C" void __cdecl operator_delete__(void *param_1)
{
  operator_delete_array(param_1);
}
