// =============================================================================
// operator_delete
// -----------------------------------------------------------------------------
// Stable ID: aa_00489822
// Address:   0x00489822  (autoassault.exe, image base 0x400000)
// Body:      0x00489822–0x00489827 inclusive (6 bytes)
// System:    shared CRT import thunk (client::crt)
// Generated: 2026-08-05 R10-001 OWN dual (refresh of 2026-07-23 scaffold)
// Exactness: Behavior-preserving reconstruction of IAT thunk. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (IAT target is runtime-bound).
// Dual:      A/B accept — docs/reconstruction/reviews/{A,B}_aa_00489822_operator_delete.md
// =============================================================================

/*
 * Behavioral notes:
 * - Body is a single MSVC import thunk: JMP dword ptr [IAT].
 * - Bytes: FF 25 94 66 9C 00  =>  JMP [0x009C6694].
 * - Ghidra decompile is misleading (recursive self-call, jumptable, noreturn).
 * - True semantics: transfer to CRT scalar operator delete; free returns to caller.
 * - Sibling operator_delete[] lives at 0x0048981c (IAT 0x009C6698) — do not merge.
 * - Parent residual seed 0x005725a0 is inventory-transfer ranking only; this VA is CRT-wide.
 * - Runtime / differential of the CRT free implementation: OPEN (out of this thunk).
 */

#include <stddef.h>

/* IAT slot bound by the loader to the CRT scalar operator delete export. */
extern void (__cdecl *const __imp_operator_delete)(void *block);
/* At VA 0x009C6694 in autoassault.exe. */

/* Image-local import thunk at 0x00489822.
 * Machine: FF 25 94 66 9C 00
 * ABI:     void __cdecl operator_delete(void *block)
 */
void __cdecl operator_delete(void *block)
{
  /* Tail transfer through IAT — not a CALL; no stack frame; CRT returns to original caller. */
  __imp_operator_delete(block);
}
