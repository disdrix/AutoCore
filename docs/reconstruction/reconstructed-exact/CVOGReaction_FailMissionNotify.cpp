// READABILITY (auto CF):
//  - Body size: ~15 non-empty decompiler lines.
//  - Control keywords: return×2, if×1.
//  - Notable callees: FUN_0040dbf0 (→ FUN_004073a0 grow/insert).
//  - Return sites: 2.

// =============================================================================
// CVOGReaction_FailMissionNotify  (historical name)
// Sealed product role: Vector_PushDword
// -----------------------------------------------------------------------------
// Stable ID: aa_004149d0
// Address:   0x004149d0  (autoassault.exe, image base 0x400000)
// System:    container util (cross-cutting; missions-progression is one user)
// Generated: 2026-07-23 from raw capture; residual strengthen 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual:      reviews/A|B_aa_004149d0 — accept (pure Vector_PushDword)
// =============================================================================

/*
 * Behavioral notes:
 * - Pure growable dword-vector push. Does NOT fail missions, show UI, send
 *   packets, or write dirty bits. Callers own element meaning and follow-on work.
 * - Layout: begin@this+4, end@this+8, cap@this+0xc (stride 4).
 * - Convention: __thiscall ECX=vec, stack arg = uint32_t*, RET 4.
 * - Fast path when capacity remains; else FUN_0040dbf0 → FUN_004073a0.
 * - Multi-caller generic (40 functions / 51 sites): end-quest ids (FailMission
 *   char+0x560), journal Active/New stack temps, freelist slab pointers, medals, …
 *
 * Readability pass:
 * - undefinedN widths preserved as fixed-width integers where decompiler width is known.
 * - Control flow and call order preserved from authoritative raw + image.
 */

void __thiscall CVOGReaction_FailMissionNotify(int param_1,uint32_t /* width from decompiler */ *param_2)
{
  int iVar1;
  uint32_t /* width from decompiler */ *puVar2;

  iVar1 = *(int *)(param_1 + 4);
  if ((iVar1 != 0) &&
     ((uint)(*(int *)(param_1 + 8) - iVar1 >> 2) < (uint)(*(int *)(param_1 + 0xc) - iVar1 >> 2))) {
    puVar2 = *(uint32_t /* width from decompiler */ **)(param_1 + 8);
    *puVar2 = *param_2;
    *(uint32_t /* width from decompiler */ **)(param_1 + 8) = puVar2 + 1;
    return;
  }
  FUN_0040dbf0(&param_2,*(uint32_t /* width from decompiler */ *)(param_1 + 8),param_2);
  return;
}
