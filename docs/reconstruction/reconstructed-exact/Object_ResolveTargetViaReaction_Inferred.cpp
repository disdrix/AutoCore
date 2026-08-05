// =============================================================================
// Object_ResolveTargetViaReaction_Inferred
// -----------------------------------------------------------------------------
// Purpose:  Thin host wrapper — load stored target ids/flag from host, resolve
//           via CVOGReaction_ResolveObjectTarget on the reaction object hanging
//           off host+0x688, return looked-up object pointer (or null).
//
// Address:  0x00578270  (autoassault.exe, image base 0x400000)
// Body:     0x00578270–0x00578298 (40 bytes / 0x28)
// Stable:   aa_00578270
// System:   object / reaction / targeting
// Ghidra:   FUN_00578270
//
// ABI:      ECX = host object
//           returns void* in EAX (passthrough from callee)
//           plain ret (C3)
//
// Exactness: CF mirrors raw + read_memory; return + reaction-this sealed from bytes.
// Bit-for-bit / runtime / differential: DEFERRED / OPEN.
// Dual A/B: accept-with-gaps (2026-07-29 W28-F seal).
// =============================================================================

/* Object_ResolveTargetViaReaction_Inferred — host → reaction resolve.

   Parameters:
     host (ECX): object with target ids at +0x658/+0x65c, flag +0x660,
                 subsystem ptr +0x688 (reaction at +0xe4e8)

   Algorithm:
     reaction = *(*(host+0x688) + 0xe4e8)
     return CVOGReaction_ResolveObjectTarget(reaction,
                                             *(uint8_t*)(host+0x660),
                                             *(uint32_t*)(host+0x658),
                                             *(uint32_t*)(host+0x65c))

   Returns: resolved object pointer, or 0 */

void *CVOGReaction_ResolveObjectTarget(void *reaction /*this*/,
                                       uint8_t flag,
                                       uint32_t id0,
                                       uint32_t id1);

void *__fastcall Object_ResolveTargetViaReaction_Inferred(int host /*ECX*/)
{
  void *reaction;
  uint8_t flag;
  uint32_t id0;
  uint32_t id1;

  reaction = *(void **)(*(int *)(host + 0x688) + 0xe4e8);
  flag = *(uint8_t *)(host + 0x660);
  id0 = *(uint32_t *)(host + 0x658);
  id1 = *(uint32_t *)(host + 0x65c);

  return CVOGReaction_ResolveObjectTarget(reaction, flag, id0, id1);
}
