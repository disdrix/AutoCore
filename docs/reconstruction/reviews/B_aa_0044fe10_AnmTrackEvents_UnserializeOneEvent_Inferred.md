# Review B (skeptical / adversarial): `aa_0044fe10` AnmTrackEvents_UnserializeOneEvent_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044fe10` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W36-G) |
| **Counterpart** | `reviews/A_aa_0044fe10_AnmTrackEvents_UnserializeOneEvent_Inferred.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Pure cdecl with only stack `param_1` | **Partial falsify** — **EDI** is live register formal (chunk reader); decompiler omits it |
| 2 | Decompiler `void` / missing return | **Falsified** — returns status in EAX (vcall result or −1) |
| 3 | First `FUN_0044fee0` is dead | **Falsified** — result moved to ESI as bag for `FUN_0046c1b0` |
| 4 | Factory takes key on stack | **Open/weak** — decompile shows `(uVar1)`; bytes only `FF 51 0C` thiscall on node; do not hard-require key arg |
| 5 | Scaffold name is sufficient plate | **Careful** — caller product path validates **anmTrackEvents** role; keep structural `_Inferred` with that prefix, not bare `Named_CalleeOf_*` alone |
| 6 | NestedHash bag is animation-specific static | **Context** — bag is generic NestedHash0x10 (W35-E); product is the **caller** + factory table, not the once-get itself |
| 7 | Multiple callers | **Falsified** — single xref `FUN_00987750` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Stack out-param + EDI formal | **High** | Wrong ABI |
| NestedHash sentinel miss | **High** | Wrong bag semantics |
| anmTrackEvents product role | **High** | Naming only if wrong |
| Factory key argument | **Medium** | Minor call-site shape |
| Event class English | **Low** | Naming |
| Runtime | **Open** | Matrix |

---

## 3. Cross-check against raw + bytes + xrefs

- Full 86 B hex ends `83c408 c3` (both paths).
- `8B F7` before key-read seals EDI→ESI.
- `3B 48 08` seals sentinel at bag+8 (matches NestedHash shell layout W34-E/W35-E).
- Caller decompile: loop `FUN_0044fe10(&local_48)` with error `"anmTrackEvents: Error Reading event!"`.
- Xref tools: single site `0x00987987`.

---

## 4. Surviving contract for AutoCore

```
// Port as per-event unserialize (not a free NestedHash API):
uint32_t UnserializeOneTrackEvent(void **out_event, StoChunkReader *reader /* EDI */) {
  uint32_t key = ReadFourCCKey(reader);
  void *bag = NestedHash0x10_StaticOnceGet_d1fcc0();
  void *node = NestedHashLookup(bag, key); // FUN_0046c1b0
  void *obj = (node == bag->sentinel) ? null : node->factory();
  *out_event = obj;
  if (!obj) return 0xffffffff;
  return obj->Unserialize(reader); // vtbl[+4], EDI on stack
}
// Pair with W35-E once-get. Do not invent event class names without vtbl evidence.
```

---

## 5. Verdict

Adversarial pass confirms A on ABI (stack out + EDI), NestedHash path, fail −1, sole anmTrackEvents caller. Residual factory-arg detail + class English do not block. **accept**.
