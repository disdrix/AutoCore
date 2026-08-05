// =============================================================================
// FUN_00437cd0 / ComPtr_ClearSlot
// -----------------------------------------------------------------------------
// Stable ID: aa_00437cd0
// Address:   0x00437cd0  (autoassault.exe, image base 0x400000)
// Body:      0x00437cd0-0x00437cd6 (7 bytes)
// System:    COM / OLE DB plumbing
// Generated: 2026-07-29 dual seal (OWN-ONLY W16-J); prior scaffold 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Bytes:     c7 00 00 00 00 00 c3  =  mov dword ptr [eax], 0 ; ret
// =============================================================================

// PURPOSE: Clear a COM interface pointer slot (*slot = 0). No Release.
// ABI: EAX = IUnknown** (or void**). void, no stack args.
// Paired with aa_0041d7b0 (ComPtr_ReleaseIfNonNull) around QI/bind scopes.

/*
 * Behavioral notes:
 * - Live decompile 2026-07-29 ≡ raw 2026-07-23.
 * - Callers: OleDb accessor release (00422de0/00423170), QI helpers (00422d10/…),
 *   and other COM/OLE DB bind paths under DbLoad plumbing.
 * - Does NOT call Release — only stores 0 through the pointer in EAX.
 */

// Register ABI: pointer in EAX (decompiler in_EAX).
void FUN_00437cd0(void)
{
  uint32_t *in_EAX;

  *in_EAX = 0;
  return;
}
