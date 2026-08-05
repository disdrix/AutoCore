// =============================================================================
// FUN_004962b0 / EquipGfxHost_ClearListIfFlag_Inferred
// -----------------------------------------------------------------------------
// Stable ID: aa_004962b0
// Address:   0x004962b0  (autoassault.exe, image base 0x400000)
// System:    inventory-transfer / client gfx host
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual A/B (bytes-faithful)
// Exactness: Behavior-preserving rewrite of machine CF. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// =============================================================================

// PURPOSE:
//   If host+0x53 (u8) is non-zero, clear the dword vector at host+0xA8 via
//   FUN_004367f0(this=host+0xA8, count=0, fill=0). Else no-op.
//   Shared leaf for equip/create/destroy gfx-host flush (e.g. parent 0x0092f120).
//
// ABI: __fastcall / __thiscall shape — ECX=host, no stack args, plain ret.
// NOTE: Ghidra decompile elides `add ecx, 0xA8`; assembly is authoritative.

// READABILITY:
//  - Body: 22 bytes (004962b0–004962c5).
//  - Callee: FUN_004367f0 (vector resize, ret 8).

// External: dword-vector resize (begin@+4, end@+8, element stride 4).
// Declared with the two stack args the call site actually pushes.
void __thiscall FUN_004367f0(void *vec, unsigned count, unsigned fill);

/*
 * Behavioral notes:
 * - Flag polarity: non-zero → clear vector; zero → return.
 * - Does not equip/unequip items or touch network state.
 * - Callers typically null-check *(obj+0xE898) before ECX=host.
 */

void __fastcall FUN_004962b0(void *host)
{
  if (*(char *)((char *)host + 0x53) == 0) {
    return;
  }

  FUN_004367f0((char *)host + 0xA8, /*count*/ 0, /*fill*/ 0);
}
