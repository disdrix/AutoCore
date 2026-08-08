# Annotated low-level: CVOGObject_EvalChildDeliverObjectiveInteract_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_004d3ba0` |
| VA | `0x004d3ba0`–`0x004d3ee2` (**835 B** / `0x343`) |
| Ghidra name | `FUN_004d3ba0` |
| Canonical name | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` |
| System | interaction-activation (child of object interact aggregate) |
| Date | 2026-08-05 (MEGA-069 OWN dual refresh) |
| Prior scaffold | `Named_VOG_DEBUG_STOP_004d3ba0` (**retired** — string is TraversalLock diagnostic only) |

## Machine-level notes

- **ABI:** `__thiscall` + 2 stack args; **`RET 8`**. ECX = host object (parent `this`/EDI); used solely as `this+0xe4e8` for `CVOGReaction_ResolveObjectTarget`.
- **Args:** stack0 = child reaction (type `0x25` payload, pair-vector `@+0x1d8`); stack1 = character (`+0x540` object hash, `+0x530` lookup hash, `+0x55c` key hash).
- **Return AL:** interact state **0 / 4 / 5 / 8** (max over matching world objects).
- **Sole caller:** `CVOGObject_EvalInteractStateFromChildren` (`0x004d7640`) on child type **`0x25`**, max-aggregated with sibling `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` (`0x004d2e50`) and peer `CVOGObject_EvalOfferableMissionInteractState` (`0x004d5aa0`) when current state `< 6`.
- Prefer assembly over decompiler for ABI/return (decompiler drops this, invents `return uVar7 & 0xffffff00`, marks delete noreturn).
- Sibling contrast: `004d2e50` is stdcall with **unused** ECX and return set {0,3,6,7}; this unit **uses** ECX and returns {0,4,5,8}.

## Control-flow outline

```text
SEH + best = 0
if child pair-vec [+0x1d8,+0x1dc) empty → return 0
resolve first pair → vcall+0x124 fill list
if list empty or object type != 0x12 → dtor list; return 0
TraversalLock character+0x540
for each hash object:
  lookup character+0x530 by object key
  match continent (entry+0x20|obj+0x88) vs NPC MI+0x34
  match region   (entry+0x24|obj+0xfc) vs char[+0xa4]+0xfc
  require action-count obj+0x130 > 0; last action from +0x13c
  if action+0x138 == 0: best = max(best, 4); continue
  for each req in [action+0x158, +0x15c):
    if GetType()==3 and req+0x18 != NPC.MI+0x34: continent_ok = false
    entry = CNDHash_LookupByKey(char+0x55c, action+0x10)
    if !entry or !req.vcall+0xc(char, entry): pred_ok = false
  if !continent_ok or !pred_ok: best = max(best, 5)
  else: best = max(best, 8)
unlock; free list; return best
```

## Pseudocode (annotated; ABI-corrected)

```c
/* __thiscall + 2 stack; RET 8; AL in {0,4,5,8} */
char CVOGObject_EvalChildDeliverObjectiveInteract_Inferred(
    void *this_host,          /* ECX — owns +0xe4e8 reaction mgr */
    int child_reaction,       /* stack0 — type 0x25 child */
    int character)            /* stack1 — player/character */
{
  byte best = 0;
  /* SEH LAB_009a2059 */
  list = FUN_0040fb90();      /* local resolved-target list */
  begin = *(child_reaction + 0x1d8);
  end   = *(child_reaction + 0x1dc);
  if (begin == 0 || (end - begin) >> 3 == 0) {
    FUN_00403430(list);
    return 0;
  }
  if (begin == 0 || (end - begin) >> 3 == 0)
    begin = FUN_004e0eb0();   /* empty fallback (dead after prior gate) */
  target = CVOGReaction_ResolveObjectTarget(
      *(this_host + 0xe4e8), begin[0], begin[1]);
  if (target == 0) { FUN_00403430(list); return 0; }
  target->vtbl[+0x124](&list);   /* fill local list; size in list.count */
  if (list.count == 0) { FUN_00403430(list); return 0; }
  npc_obj = list.head->payload;  /* *list + 8 */
  if (*(npc_obj->mi /* +0xa8 */ + 0x38) != 0x12) {
    FUN_00403430(list); return 0;
  }
  /* TraversalLock character+0x540; walk; score 4/5/8 as above */
  /* unlock; free list nodes; return best */
}
```

## Open questions

- Product English for states **4** / **5** / **8** on deliver icons (in-progress / blocked / ready).
- Exact type of `this_host` (large `+0xe4e8` — CVOGObject vs client/world owner).
- Product names for child pair-vector `@+0x1d8` and action/req structs.
- Runtime / bit-exact / differential (open; no Launcher).
