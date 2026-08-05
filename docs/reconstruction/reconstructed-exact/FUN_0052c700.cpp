// =============================================================================
// FUN_0052c700 — character mission staging map upsert
// -----------------------------------------------------------------------------
// Stable ID: aa_0052c700
// Address:   0x0052c700  (autoassault.exe, image base 0x400000)
// System:    missions-progression
// Generated: 2026-07-23 scaffold; refined 2026-07-29 dual seal
// Exactness: Behavior-preserving rewrite of decompiler CF + assembly corrections.
//            Not modernization. Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================
//
// PURPOSE:
//   Upsert a 12-dword staging payload into Character map @ +0x508, keyed by
//   mission id. Used by RecvNpcMissionDialog (8 item COIDs), CheckMissionPrerequisites
//   (NPC/AutoAssign prep), and lookup/create helper FUN_0052dac0.
//
// ASSEMBLY CORRECTIONS vs raw decompile:
//   - Map object this = character+0x508 (not character).
//   - Returns payload* (node+0x18), not void.
//   - Always writes payload[+0x28] = key (dword index 10).
//
// 12-DWORD PAYLOAD @ node+0x18:
//   [0..7]  item COID[8] or 0xFFFFFFFF
//   [8]     Mission.NPC (def+0x88) on award path; else often -1
//   [9]     Mission.AutoAssign (def+0xfc) on award path; else often -1
//   [10]    forced = missionKey by this function
//   [11]    0 / consumer flag
//
// MAP:
//   char+0x508 header, +0x50c end sentinel, +0x510 size (sibling clear).
//   node+0x10 key, +0x18 payload[12], +0x49 isnil.
// =============================================================================

// Callees (roles High; product names open):
//   FUN_00538a40 — map lower_bound / find
//   FUN_00539cb0 — map insert

uint32_t *__thiscall FUN_0052c700(int character, uint32_t missionKey, uint32_t *payload12)
{
  uint32_t savedKey;
  int *it;
  int i;
  uint32_t *src;
  uint32_t *dst;
  int out_it[2];
  uint32_t insert_pair[1 + 12]; /* key + 12-dword value; stack shape from asm */

  /* this for tree ops = character + 0x508 (asm LEA EBX,[ESI+0x508]) */
  FUN_00538a40(out_it, &missionKey); /* ECX = map @ character+0x508 */
  savedKey = missionKey;
  i = 0xc;

  if (out_it[0] == *(int *)(character + 0x50c)) {
    /* miss: copy key + 12 dwords, insert */
    insert_pair[0] = missionKey;
    src = payload12;
    dst = &insert_pair[1];
    for (; i != 0; i = i + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
    FUN_00539cb0(out_it, insert_pair); /* ECX = map */
  }
  else {
    /* hit: overwrite existing payload at node+0x18 */
    src = payload12;
    dst = (uint32_t *)(out_it[0] + 0x18);
    for (; i != 0; i = i + -1) {
      *dst = *src;
      src = src + 1;
      dst = dst + 1;
    }
  }

  it = (int *)FUN_00538a40(/*out*/(int *)&payload12, &missionKey); /* re-find; ECX=map */
  /* asm: EAX = *out; ADD EAX,0x18; MOV [EAX+0x28], key; return EAX */
  dst = (uint32_t *)(*it + 0x18);
  dst[10] = savedKey; /* payload +0x28 */
  return dst;
}
