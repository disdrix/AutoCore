// =============================================================================
// SkillStaging_ZeroPayloadFields_Inferred  (FUN_0054cc10)
// -----------------------------------------------------------------------------
// Stable ID: aa_0054cc10
// Address:   0x0054cc10–0x0054d43f  (autoassault.exe, image base 0x400000)
// Body:      2096 B / 0x830; terminal bare RET (C3); next leaf 0x0054d440
// System:    skills-abilities
// Generated: 2026-08-05 R13-038 dual seal (raw 2026-07-23 + live re-verify)
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED.
//
// PURPOSE:
//   Zero skill-staging / skill-template payload fields this+0x28 through this+0x534
//   inclusive (324 / 0x144 dwords; span 0x510 bytes). Retail uses XORPS xmm0 +
//   interleaved MOVSS/MOV dword stores; compact form below is state-equivalent.
//
//   Does NOT touch this+0x00..this+0x27 (header left intact by this leaf alone).
//
// ABI: thiscall (ECX=self); 0 stack args; bare RET; void
// Reachability: 1 CALL @ 0x0054a2d1 in SkillDef_InstallLoadedRecord (0x0054a290)
//   call site: LEA ECX,[ESP+0x1a0] then CALL — stack staging buffer of size 0x538
//   (caller then REP STOSD 0x14e dwords over the full buffer).
//
// Partition parent dual (adjacency): 0x0054cbb0 PossessCreature DefaultFactory
// Semantic caller dual: 0x0054a290 SkillDef_InstallLoadedRecord (not OWN here)
// =============================================================================

#include <stdint.h>

void __fastcall SkillStaging_ZeroPayloadFields_Inferred(void *self)
{
  uint32_t *p;
  int i;

  /* retail head (bytes): 0F 57 C0  8B C1  F3 0F 11 40 2C  F3 0F 11 40 30
   *                      33 C9  89 48 28  89 48 34  …  F3 0F 11 80 34 05 00 00  C3
   * Store order at head is +0x2c, +0x30, +0x28, +0x34, … — independent; final
   * state is every dword in [+0x28, +0x534] zeroed. */

  p = (uint32_t *)((char *)self + 0x28);
  for (i = 0; i < 0x144; i++) {
    p[i] = 0;
  }
}
