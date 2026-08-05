# Review B (skeptical / adversarial): `Client_FindObjectiveMatchingTarget` @ `0x00525bd0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_00525bd0` |
| **VA** | `0x00525bd0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh) |
| **Counterpart** | `reviews/A_aa_00525bd0_Client_FindObjectiveMatchingTarget.md` |
| **Scratch** | `reviews/a_00525bd0.md` |
| **System** | `missions-progression` / UseObject consumer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Walks **pending** hash `+0x55c` for matches | Body only **reads count** at `*(+0x55c)+0xc`; walk uses `+0x548` | **Falsified** — pending is gate-only |
| 2 | Returns mission / objective **id** | Return is hash payload `node+8`; id is at def`+0x10` in **caller** | **Falsified** — returns **def\*** |
| 3 | MatchTarget is vtable **`+0x20`** (action) or **`+0x40`** (interact) | Call uses `*(vtbl+0x38)`; interact id-finder uses **`+0x40`** via `0059d9c0` | **Falsified for this path** — **`+0x38`** |
| 4 | Always finds something if pending nonempty | Exhaust active list without match → unlock return 0 | **Falsified** |
| 5 | Same function as `FindActiveObjectiveIdForInteract` (`00524520`) | Different return (def\* vs id), different slot (+0x38 vs +0x40), pending gate only here | **Falsified** — parallel family |
| 6 | Multiple matches pick “best” objective | First non-zero MatchTarget unlocks and returns | **Falsified** — **first hash-order hit only** |
| 7 | No lock on early pending-empty path | Gate returns before lock | **Survives** — correct; no unlock needed |
| 8 | UseItem `FUN_0060d460` is fully the MatchTarget body for this walker | Helper is JMP target of UseItem slot; ABI from `0060df70` is **(char, worldObj)**; this walker passes **(key, char)** | **Partially falsified as “sealed key matcher”** — helper proven for **object** path; **not** proven under this call ABI |
| 9 | Pending gate is redundant with active walk | Distinct containers; empty pending skips work even if active hash nonempty | **Survives as written CF**; product staleness **Open** |
| 10 | Character is always local player in ECX | Sole caller decompiles without ECX setup | **Open / Probable** |
| 11 | Miss and “no UseObject” are identical | Caller still sends `0x2072` with IDObjective **−1** | **Falsified as product deny** — miss is −1 field, not send abort |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Active-obj walk `+0x548` + lock `+0x1d` | **High** | Hang / wrong objective on use |
| Pending count gate `+0x55c` | **High** (CF) / **Medium** (product if count stale) | False-neg UseObject objective bind |
| Match slot `vtable+0x38` (key, char) | **High** | Never matches / wrong class |
| Returns def\*; caller id `@+0x10` or −1 | **High** | Wire wrong IDObjective |
| First-match only | **High** | Multi-obj use binds wrong def |
| Distinct from `00524520` / `+0x40` path | **High** | Port merges break IfInteractable vs SendUseObject sentinels |
| Sole caller SendUseObject | **High** | Missed alternate binder |
| Character this at call site | **Probable** | Wrong this → empty/wrong hash |
| UseItem `0060d460` as key MatchTarget | **Tentative** | Silent no-match or AV on UseItem-only actives |
| Kill/Patrol/`+0x38` implementer map | **Open** | Exotic objectives never bind |
| Runtime hash order | **Open** | Non-deterministic “first” def |

---

## 3. Cross-check against raw (minimal)

Live decompile 2026-07-29 matches raw `aa_00525bd0` body:

* `*( *(param_1+0x55c)+0xc ) < 1 → return 0`
* Lock `*( *(param_1+0x548)+0x1d )`
* Linked list via `+0x14` / payload `+8`
* Inner eval loop: `*(vtbl+0x38)(param_2, param_1)`
* Unlock on hit and on fall-through

Caller live `0x00916740`:

* `FindObjectiveMatchingTarget( *( *(target+0xa8)+0x34 ) )`
* `local_8 = (ret==0) ? 0xffffffff : *(ret+0x10)`
* Opcode `0x2072`, size `0x20`

Sibling contrast live `0x00524520` / `0x0059d9c0` confirms **different** match slot (**`+0x40`**) and **id** return — strengthens “not aliases.”

UseItem thunk live: `0060d7f0` → `E9 …` → `0060d460`. Adversarial note: naming the UseItem slot “MatchTarget for FindObjective” without ABI proof is the main prior overclaim.

---

## 4. Surviving contract for AutoCore

```
// SendUseObject objective def lookup (not IfInteractable id finder)
ObjectiveDef* FindObjectiveMatchingTarget(Character* ch, uint32_t targetKey) {
  if (pendingObjectivesCount(ch) < 1) return nullptr;   // *(ch+0x55c)+0xc
  lock(ch->activeObjectivesHash /* +0x548 */);
  for (def : activeObjectives in hash order) {
    for (eval : def->evaluators /* +0x158 .. +0x15c */) {
      if (eval->vtbl[0x38/4](targetKey, ch)) { unlock; return def; }
    }
  }
  unlock; return nullptr;
}

// Port rules:
//  - Return def*; caller maps to id @ +0x10 or -1 (never invent 0 miss for this path).
//  - Do NOT drop pending gate.
//  - Do NOT use evaluator +0x40/+0x44 here.
//  - Do NOT merge with FindActiveObjectiveIdForInteract.
//  - Do NOT assume UseItem FUN_0060d460 is a pure key compare under this ABI.
```

---

## 5. What would overturn this dual

1. Disassembly/xref proof of a second production caller with different ABI.
2. Evidence hash payload at `node+8` is **not** an objective def with id at `+0x10`.
3. Evidence MatchTarget call passes world object, not key (would invert SendUseObject key extraction story).
4. Proof pending count is **not** at `*(char+0x55c)+0xc` (would reopen gate).

Until then, walker body claims stand at **High**.

---

## 6. Open questions

1. Character ECX provenance at `SendUseObject` (and any future callers).
2. Full `vtable+0x38` implementer catalog under **(key, character)** — especially whether UseItem ever successfully matches via this walker.
3. Pending-count staleness vs active hash in live play.
4. Wire dump of `0x2072` IDObjective for multi-objective characters.
5. Relationship of clonebase `+0x34` key domain to requirement criteria fields (e.g. UseItem `req+0x18`).

**Verdict:** Safe static contract for UseObject def\* lookup; leave MatchTarget implementer surface and runtime open. **accept-with-gaps.**
