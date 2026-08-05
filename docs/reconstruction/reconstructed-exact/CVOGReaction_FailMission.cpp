// READABILITY (auto CF):
//  - Body size: ~26 non-empty decompiler lines / ~0x8A image bytes.
//  - Control keywords: if×3, return×3, while×1.
//  - Notable callees: CVOGReaction_FailMissionNotify, FUN_007a4480.
//  - Strings: "Player %I64d failed mission %d" @ 0x009cfa28.
//  - Return sites: 3 (AL bool-like; RET 4).

// =============================================================================
// CVOGReaction_FailMission
// -----------------------------------------------------------------------------
// Purpose:  Mark an active mission as failed for the character: lookup missionId
//           in the active-missions hash (char+0x540), log failure, push id onto
//           the end-quest vector (char+0x560), and set dirty bit 0x10.
//
// Address:  0x0052da30  (autoassault.exe, image base 0x400000)
// Stable:   aa_0052da30
// System:   missions-progression
//
// Convention: MSVC __thiscall (this in ECX); stack missionId; RET 4; AL 0|1
// Exactness: Behavior-preserving rewrite of decompiler control flow.
//            Not modernization. Bit-for-bit / runtime / diff: DEFERRED.
//
// Dual residual body pass 2 (2026-07-29): Notify ECX = this+0x560 sealed (asm LEA
//   + image); Notify body = u32 vector push (not teardown). Full 11 CALL xrefs:
//   drain YES = Recv 0080b111, HB 00650c62, orphan 00886402; drain NO = Patrol,
//   Kill_Precheck, FUN_0060e800×2, orphans 0060caa2/0060ec36/00612970/0057f44c.
//   Scratch: tmp/a_0052da30.md  (OWN body only — not Recv dual)
//
// Callers (Ghidra xrefs, 11 sites):
//   Client_RecvFailMission call 0x0080b111 — S2C 0x20B2 + FUN_005307e0 drain
//   FUN_006508d0 call 0x00650c62 — mission HB fail + FUN_005307e0
//   orphan 0x00886402 — DAT_00d1b6d8 + FUN_005307e0
//   CVOGHBMissionPatrol_Fn3 call 0x00650f11 — no drain
//   CVOGObjectiveRequirement_Kill_Precheck call 0x00613df2 — no drain
//   FUN_0060e800 calls 0x0060e82f / 0x0060e9c3 — no drain (masks AL)
//   orphans 0x0060caa2 / 0x0060ec36 / 0x00612970 / 0x0057f44c — no drain
// Abandon UI: C2S 0x20B2 from Client_UiModalDispatch case 0x4e46 (not a direct caller).
//
// Open questions:
//   - Dual of FUN_005307e0 end-quest teardown.
//   - Readers of dirty bit 0x10 on +0x634.
//   - Orphan host function recovery.
//   - Runtime / differential equivalence vs retail.
// =============================================================================

uint32_t /* bool-like AL 0/1 */ __thiscall CVOGReaction_FailMission(int param_1, uint param_2)
{
  uint uVar1;
  int iVar2;

  uVar1 = param_2;
  iVar2 = *(int *)(*(int *)(*(int *)(*(int *)(param_1 + 0x540) + 0x10) +
                           (*(uint *)(*(int *)(param_1 + 0x540) + 8) & param_2) * 4) + 4);
  if (iVar2 != 0) {
    while (param_2 != *(uint *)(iVar2 + 0x10)) {
      iVar2 = *(int *)(iVar2 + 0xc);
      if (iVar2 == 0) {
        return 0;
      }
    }
    if ((iVar2 != 0) && (*(int *)(iVar2 + 8) != 0)) {
      iVar2 = *(int *)(*(int *)(param_1 + 4) + 4);
      FUN_007a4480(0, "Player %I64d failed mission %d",
                   *(uint32_t *)(iVar2 + 0x164 + param_1),
                   *(uint32_t *)(iVar2 + 0x168 + param_1), param_2);
      param_2 = uVar1;
      // Asm: LEA ECX,[param_1+0x560]; PUSH &param_2; CALL Notify (vector push)
      CVOGReaction_FailMissionNotify(&param_2);
      *(uint *)(param_1 + 0x634) = *(uint *)(param_1 + 0x634) | 0x10;
      return 1;
    }
  }
  return 0;
}
