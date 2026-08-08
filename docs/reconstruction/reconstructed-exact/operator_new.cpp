// =============================================================================
// operator_new
// -----------------------------------------------------------------------------
// Stable ID: aa_00489892
// Address:   0x00489892  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer (parent dual context); unit = CRT IAT thunk
// Generated: 2026-08-05 R10-002 dual re-verify
// Exactness: Behavior-preserving model of 6-byte IAT trampoline. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (IAT target is CRT DLL / bound address).
// =============================================================================

/*
 * Behavioral notes:
 * - Body is a single instruction: JMP dword ptr [PTR_operator_new_009c6664].
 * - PE/CRT import name: operator_new (Confirmed). Not an _Inferred product invent.
 * - Decompiler models the JMP as a recursive call; bytes win.
 * - Do not reimplement as AutoAssault game logic — use host CRT / new.
 * - Sibling IAT thunks: operator_delete[] 0x0048981c, operator_delete 0x00489822,
 *   operator_new[] 0x00489834. Secondary same-named thunk 0x00685b20 is not this VA.
 *
 * Assembly (authoritative):
 *   00489892  FF 25 64 66 9C 00   JMP dword ptr [0x009c6664]
 */

// IAT pointer (image slot; runtime may be bound to MSVCR operator new).
extern void * (__cdecl *PTR_operator_new_009c6664)(unsigned int size_bytes);

void * __cdecl operator_new(unsigned int size_bytes)
{
  return PTR_operator_new_009c6664(size_bytes);
}
