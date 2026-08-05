// =============================================================================
// FUN_00578270  (clean twin of Object_ResolveTargetViaReaction_Inferred)
// -----------------------------------------------------------------------------
// Stable ID: aa_00578270
// Address:   0x00578270  (autoassault.exe, image base 0x400000)
// Body:      0x00578270–0x00578298 (40 B)
// System:    object / reaction / targeting
// Generated: 2026-07-29 W28-F dual seal (supersedes 2026-07-23 scaffold)
// Exactness: Behavior-preserving rewrite; return + reaction-this from bytes.
// Bit-for-bit vs retail EXE: DEFERRED.
// =============================================================================

void *CVOGReaction_ResolveObjectTarget(void *reaction,
                                       uint8_t flag,
                                       uint32_t id0,
                                       uint32_t id1);

void *__fastcall FUN_00578270(int param_1)
{
  void *reaction;
  uint8_t flag;
  uint32_t id0;
  uint32_t id1;

  reaction = *(void **)(*(int *)(param_1 + 0x688) + 0xe4e8);
  flag = *(uint8_t *)(param_1 + 0x660);
  id0 = *(uint32_t *)(param_1 + 0x658);
  id1 = *(uint32_t *)(param_1 + 0x65c);

  return CVOGReaction_ResolveObjectTarget(reaction, flag, id0, id1);
}
