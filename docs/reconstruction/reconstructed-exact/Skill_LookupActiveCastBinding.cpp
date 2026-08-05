// READABILITY (auto CF):
//  - Body size: ~28 non-empty decompiler lines.
//  - Control keywords: if×1, return×2.
//  - Notable callees: FUN_00518c20×2, FUN_0051c150, g_abTfidInvalid_9CDF88.
//  - Return sites: 2.
//  - Residual 2026-07-29: out=TFID16 sealed; A15870 is NOT the map; multi-arg
//    FUN_00518c20 call sites are decompiler noise (unary leave-FUN getter).

// =============================================================================
// Skill_LookupActiveCastBinding
// -----------------------------------------------------------------------------
// Stable ID: aa_00518cf0
// Address:   0x00518cf0  (autoassault.exe, image base 0x400000)
// System:    skills-abilities
// Generated: 2026-07-23 from raw capture; residual strengthen 2026-07-29
// Exactness: Behavior-preserving rewrite of decompiler control flow. Not modernization.
// Bit-for-bit vs retail EXE: DEFERRED (loaded image may differ slightly).
// Dual A/B:  reviews/A_aa_00518cf0_Skill_LookupActiveCastBinding.md
//            reviews/B_aa_00518cf0_Skill_LookupActiveCastBinding.md
// Scratch:   reviews/a_00518cf0.md
// =============================================================================

/*
 * Behavioral notes:
 * - Read-only active-cast binding lookup by skill id.
 * - Entry ECX = mapOwner (mov esi,ecx); product type OPEN (leave-FUN sibling).
 * - Stack formals: pOutTfid @ +4, nSkillId @ +8; both arms ret 8 (__stdcall).
 * - Map shell: FUN_00518c20 (lazy owner+0x68; leave-FUN — product name withheld).
 * - Find: FUN_0051c150 (key @ node+0x10); end = *(map+4); exact match.
 * - Hit: copy node+0x18..+0x24 (TFID16) → pOutTfid.
 * - Miss: copy g_abTfidInvalid_9CDF88 (0x009cdf88) = (-1,-1,0,0).
 * - g_abTfidInvalid_A15870 (0x00a15870) is a twin invalid constant used by
 *   callers for compares; this body does not fill from it and it is not the map.
 * - Cast-again HB / sticky-list policy lives in callers, not this VA.
 *
 * Readability pass:
 * - Control flow and call order preserved from authoritative raw.
 * - Comments document recovered CF where decompiler noise mis-attributes args.
 */

/* Skill_LookupActiveCastBinding(outTfid, skillId)  // + ECX mapOwner; ret 8

   Fills 16-byte TFID from active-cast map for skillId, or invalid sentinel
   g_abTfidInvalid_9CDF88 if unbound. */

void Skill_LookupActiveCastBinding(void *pOutTfid, int nSkillId)
{
  int pMap;
  int *piVar1;
  int pMapIt;
  int *pTmp;

  piVar1 = &nSkillId;
  pTmp = &pMapIt;
  // NOISE: unary FUN_00518c20(mapOwner=ECX/ESI) — stack args belong to find.
  FUN_00518c20(pTmp, piVar1);
  // Recovered: FUN_0051c150(pMap, &pMapIt, &nSkillId).
  FUN_0051c150(pTmp, piVar1);
  pMap = FUN_00518c20();
  if (pMapIt != *(int *)(pMap + 4)) {
    *(uint32_t /* width from decompiler */ *)pOutTfid =
        *(uint32_t /* width from decompiler */ *)(pMapIt + 0x18);
    *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 4) =
        *(uint32_t /* width from decompiler */ *)(pMapIt + 0x1c);
    *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 8) =
        *(uint32_t /* width from decompiler */ *)(pMapIt + 0x20);
    *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 0xc) =
        *(uint32_t /* width from decompiler */ *)(pMapIt + 0x24);
    return;
  }
  *(uint32_t /* width from decompiler */ *)pOutTfid =
      g_abTfidInvalid_9CDF88._0_4_;
  *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 4) =
      g_abTfidInvalid_9CDF88._4_4_;
  *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 8) =
      g_abTfidInvalid_9CDF88._8_4_;
  *(uint32_t /* width from decompiler */ *)((int)pOutTfid + 0xc) =
      g_abTfidInvalid_9CDF88._12_4_;
  return;
}
