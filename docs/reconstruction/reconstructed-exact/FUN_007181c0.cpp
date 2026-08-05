// =============================================================================
// FUN_007181c0  /  _com_raise_error
// -----------------------------------------------------------------------------
// Stable ID: aa_007181c0
// Address:   0x007181c0  (autoassault.exe, image base 0x400000)
// System:    crt-com / MSVC COM support (_com_raise_error)
// Generated: 2026-07-29 (W16-P OWN dual; live decompile + read_memory)
// Exactness: Behavior-preserving rewrite of decompiler + sealed bytes. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
// Non-returning MSVC COM raise leaf. Constructs a stack _com_error from
// (HRESULT, IErrorInfo*, fAddRef=false) and throws it via _CxxThrowException
// with ThrowInfo DAT_00acc2c0. Target of PTR_FUN_00af8b20 used by
// _com_issue_error / _com_issue_errorex.
//
// ABI: __stdcall; two stack args; ret 8. Does not return after throw.

// READABILITY:
//  - Body size: 44 bytes (007181c0–007181eb) + CC pad.
//  - Callees: _com_error::_com_error @ 0x007181f0; _CxxThrowException @ 0x006a3d60.
//  - Return sites: epilogue present but dead after throw.

/*
 * Behavioral notes:
 * - fAddRef hardcoded false (push 0) — no AddRef on the IErrorInfo* in ctor.
 * - ThrowInfo.pmfnUnwind = 0x007182e0 (_com_error dtor).
 * - Library identity: _com_raise_error (call-graph + PTR; Ghidra left FUN_ name).
 * - Runtime / differential verification: OPEN.
 */

// DAT_00acc2c0 — ThrowInfo for _com_error (attributes=0, unwind=0x007182e0,
//                pCatchableTypeArray=0x00acc2b8)

void FUN_007181c0(long param_1, IErrorInfo *param_2)
{
  _com_error local_14[16];

  _com_error::_com_error(local_14, param_1, param_2, false);
  /* WARNING: Subroutine does not return */
  _CxxThrowException(local_14, (ThrowInfo *)&DAT_00acc2c0);
}
