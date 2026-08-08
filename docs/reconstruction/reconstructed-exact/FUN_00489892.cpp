// =============================================================================
// FUN_00489892  (scaffold twin → operator_new)
// -----------------------------------------------------------------------------
// Stable ID: aa_00489892
// Address:   0x00489892  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (parent dual context); unit = CRT IAT thunk
// Generated: 2026-08-05 R10-002 (canonical clean: operator_new.cpp)
// Exactness: Behavior-preserving model of 6-byte IAT trampoline.
// =============================================================================

// Canonical name: operator_new
// See: docs/reconstruction/reconstructed-exact/operator_new.cpp

extern void * (__cdecl *PTR_operator_new_009c6664)(unsigned int size_bytes);

void * __cdecl FUN_00489892(unsigned int size_bytes)
{
  return PTR_operator_new_009c6664(size_bytes);
}
