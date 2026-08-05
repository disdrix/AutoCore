// =============================================================================
// FUN_00404c90 — Object_GetWorldPositionPtr (inferred role name)
// -----------------------------------------------------------------------------
// Stable ID: aa_00404c90
// Address:   0x00404c90  (autoassault.exe, image base 0x400000)
// Body:      00404c90 – 00404cad
// System:    shared-object-pose
// Generated: 2026-07-23 scaffold; dual-review refine 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Twin:      FUN_00404a20 @ 0x00404a20 (orientation / quat pointer)
// =============================================================================

// PURPOSE:
//   Leaf getter: return pointer to world position floats for entity `this` (ECX).
//   Path A (physics attached): *(this+8) != 0 → *(*(this+8)+0x3c) + 0xb0  (rb world pos).
//   Path B (fallback):         *(*(this+4)+4) + this + 0x84               (embedded pose).
//   No callees, no stores. Callers load XYZ from the returned address.
//
// READABILITY:
//  - Body size: ~7 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Callees: none.
//  - Return sites: 2.
//
// Reviews:
//  - docs/reconstruction/reviews/A_aa_00404c90_Object_GetWorldPositionPtr.md
//  - docs/reconstruction/reviews/B_aa_00404c90_Object_GetWorldPositionPtr.md

/*
 * Behavioral notes:
 * - Derived from Ghidra decompile + read_memory body bytes (2026-07-29 dual).
 * - Product symbol name open; role High from physics/verified rigid-body map and consumers.
 * - Runtime / differential verification: OPEN.
 *
 * Readability pass:
 * - Control flow and offsets preserved from authoritative raw.
 */

int __fastcall FUN_00404c90(int param_1)
{
  if (*(int *)(param_1 + 8) != 0) {
    return *(int *)(*(int *)(param_1 + 8) + 0x3c) + 0xb0;
  }
  return *(int *)(*(int *)(param_1 + 4) + 4) + 0x84 + param_1;
}
