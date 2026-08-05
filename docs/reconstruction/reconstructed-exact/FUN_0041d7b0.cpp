// =============================================================================
// FUN_0041d7b0 / ComPtr_ReleaseIfNonNull
// -----------------------------------------------------------------------------
// Stable ID: aa_0041d7b0
// Address:   0x0041d7b0  (autoassault.exe, image base 0x400000)
// Body:      0x0041d7b0-0x0041d7bc (13 bytes)
// System:    COM / OLE DB plumbing
// Generated: 2026-07-29 dual seal (OWN-ONLY W16-J); prior scaffold 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Bytes:     8b 00 85 c0 74 06 8b 08 50 ff 51 08 c3
//            mov eax,[eax]; test eax,eax; jz ret;
//            mov ecx,[eax]; push eax; call [ecx+8]; ret
// =============================================================================

// PURPOSE: If *slot != null, call IUnknown::Release on *slot (vtbl+8).
// ABI: EAX = IUnknown**. void, no stack args.
// Does NOT null *slot after Release.
// Paired with aa_00437cd0 (ComPtr_ClearSlot) around QI/bind scopes.
// Also used from many SEH Unwind@* thunks for local com_ptr cleanup.

/*
 * Behavioral notes:
 * - Live decompile 2026-07-29 ≡ raw 2026-07-23.
 * - vtbl+8 = IUnknown::Release (slot index 2 after QueryInterface @ +0 / +4).
 * - Callers: OleDb accessor release (00422de0/00423170), QI helpers, Unwind paths.
 */

// Register ABI: pointer in EAX (decompiler in_EAX).
void FUN_0041d7b0(void)
{
  int *piVar1;
  int *in_EAX;

  piVar1 = (int *)*in_EAX;
  if (piVar1 != (int *)0x0) {
    (**(code **)(*piVar1 + 8))(piVar1);
  }
  return;
}
