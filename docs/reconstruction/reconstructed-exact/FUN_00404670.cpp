// =============================================================================
// FUN_00404670 / UiToast_ConstructN_0x98
// -----------------------------------------------------------------------------
// Stable ID: aa_00404670
// Address:   0x00404670  (autoassault.exe, image base 0x400000)
// System:    missions-progression / UI toast vector helpers
// Generated: 2026-07-29 dual seal (W16-S); raw capture 2026-07-23
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   Count-based POD construct for UI toast elements of stride 0x98.
//   For each of `count` slots: call UiToast_PodCopyElement_0x98 (FUN_00404710),
//   then advance destination by 0x98. Source template pointer does not advance.
//
//   Callers:
//     - Client_UiToastQueue_Push (0x0040c5c0) fast path: count=1 at current end
//     - FUN_00404130 fill-n wrapper: ConstructN then return dst + count*0x98
//
// ABI: free function, cdecl (ret). Used formals (dst, count, src).
//      Parents may push phantom trailing dwords (thiscall noise); unused by body.
// SEH: ExceptionList frame via LAB_009bc750.
// Callee: FUN_00404710 — stdcall POD copy 0x26 dwords (0x98 bytes) if dst != NULL.

// READABILITY:
//  - Control keywords: for×1, return×1.
//  - Notable callees: FUN_00404710.
//  - Stride constant: 0x98.

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory (2026-07-29).
 * - No heap, no growth, no toast formatting — pure multi-element POD stamp.
 * - Runtime / differential verification: OPEN.
 */

// ExceptionList / SEH symbols are process TLS; kept as decompiler names.
extern void *ExceptionList;
extern void LAB_009bc750; // SEH handler address used in frame setup

void FUN_00404710(void *dst, const void *src); // UiToast_PodCopyElement_0x98

void FUN_00404670(int param_1 /* dst */, int param_2 /* count */,
                  unsigned /* width from decompiler */ param_3 /* src */)
{
  void *local_10;
  unsigned char *puStack_c;
  unsigned local_8;

  puStack_c = (unsigned char *)&LAB_009bc750;
  local_10 = ExceptionList;
  local_8 = 0;
  ExceptionList = &local_10;

  for (; param_2 != 0; param_2 = param_2 + -1) {
    FUN_00404710((void *)param_1, (const void *)param_3);
    param_1 = param_1 + 0x98;
  }

  ExceptionList = local_10;
  return;
}
