# Review B (skeptical / adversarial): `aa_005245d0` CVOGCharacter_FindActiveObjectiveIdForPick

| Field | Value |
|---|---|
| **Stable ID** | `aa_005245d0` |
| **VA** | `0x005245d0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005245d0_CVOGCharacter_FindActiveObjectiveIdForPick.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `FUN_005245d0` is a boolean “isPickable / isInteractable” | Callers only truth-test, but body stores `*(obj+0x10)` after match | **Falsified** — returns **objective id** or 0 (same family as sibling) |
| 2 | Alias via `VOG_DEBUG_STOP` / Named_VOG_DEBUG_STOP is the real name | Only assert strings on lock misuse | **Falsified** — assert noise |
| 3 | Same function as sibling `00524520` | Same walk; **different** match helper (`0059da10` vs `0059d9c0`) and eval slot (**+0x44** vs **+0x40**) | **Falsified** — sibling pair, not aliases |
| 4 | Same as `Client_FindObjectiveMatchingTarget` | Different return (id vs def\*), different slot (+0x44 vs +0x38), no pending `+0x55c` | **Falsified** |
| 5 | Hash `+0x548` is active **missions** | Missions hash is `+0x540`; objectives use `+0x548` | **Survives** as active **objectives** (**High**) |
| 6 | `FUN_0059da10(param_1,param_2)` means this=character | thiscall: helper reads `this+0x158` evaluator range on **objective** layout; ECX set from payload | **Falsified** — **this = objective instance** |
| 7 | Match uses evaluator `vtable+0x40` (interact sibling) | Helper calls `*(*eval + 0x44)` | **Falsified for this path** — **+0x44** |
| 8 | Name `…ForInteractAlt` is accurate | Scaffold name only; product bias is pick/hover select vs IfInteractable | **Partially falsified** — prefer **ForPick** (**Probable**) |
| 9 | Multiple matching objectives pick “best” | Loop breaks on first non-zero match | **Falsified** — **first hash-order hit only** |
| 10 | Empty active hash needs pending gate | No `+0x55c` check; empty → unlock return 0 | **Survives** — intentional |
| 11 | Hover path always interacts on match | `FUN_00925820`: this unit → select only; sibling → select + IfInteractable | **Falsified as “always interact”** — product split at call site |
| 12 | Character is always local player in ECX | Sites decompile without ECX setup shown | **Open / Probable** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null → 0; unlock always | **High** | Hang / leak lock |
| Active-obj walk `+0x548` / lock `+0x1d` | **High** | Wrong mission state |
| Return id `@+0x10` | **High** | Wrong gate / wrong id downstream |
| Eval slot `+0x44` via `0059da10` | **High** | Merge with +0x40 path → silent miss/hit |
| First-match only | **High** | Multi-obj pick wrong id |
| Distinct from `00524520` / `00525bd0` | **High** | Port merges break pick vs interact vs UseObject |
| Name ForPick | **Probable** | Cosmetic; keep FUN_* if retail found |
| Character this at call sites | **Probable** | Wrong this → empty hash / crash |
| `+0x44` semantics per req type | **Tentative** | Silent no-match on exotic objectives |
| Runtime hash order stability | **Open** | Non-deterministic “first” id |

---

## 3. Cross-check against raw (minimal)

Live decompile 2026-07-29 matches raw `aa_005245d0` body:

* Early `param_2 == 0 → 0`
* Lock `*( *(param_1+0x548) + 0x1d )`
* `do { … FUN_0059da10(param_1,param_2); } while (cVar1==0)` then `uVar2 = *(iVar4+0x10)`
* Unlock + return

Byte-for-byte CF twin of sibling except callee address / slot. That strengthens “id finder family,” not “bool pick.”

Xref count = **3** (complete analysis) — closed set for static call-site dual.

---

## 4. Surviving contract for AutoCore

```
// Client pick/hover objective id (+0x44 evaluator path)
uint32 FindActiveObjectiveIdForPick(Character* ch, Object* worldObj) {
  if (!worldObj) return 0;
  // Walk ch->activeObjectivesHash (+0x548), lock +0x1d
  // For each objective instance (node payload +8):
  //   if any evaluator MatchPickTarget (vtable +0x44)(?, worldObj):
  //     return objectiveId at instance+0x10;  // first hit
  // return 0;
}

// Port rules:
//  - Do NOT treat as bool-only; zero is “no matching objective.”
//  - Do NOT use pending (+0x55c) gate from FindObjectiveMatchingTarget.
//  - Do NOT call evaluator +0x40 or +0x38 here; those are other paths.
//  - Do NOT merge with FindActiveObjectiveIdForInteract (sibling +0x40).
//  - Call-site product: pick may OR with sibling; hover may select without send.
```

---

## 5. What would overturn this dual

1. Disassembly proof that ECX into `0059da10` is **not** the objective payload.
2. Evidence `+0x548` payloads are **not** objective instances with id at `+0x10`.
3. Evidence `FUN_0059da10` calls a slot other than **+0x44** (would invert contrast with sibling).

Until then, body claims stand at **High**.

---

## 6. Open questions

1. Character ECX load at each of the 3 xrefs.
2. Implementers of evaluator `+0x44` vs `+0x40` vs `+0x38`.
3. Whether any caller ever consumes the **numeric id** (not just truthiness) from this unit specifically.

**Verdict:** **accept-with-gaps** — body High; name Probable; eval implementers open.
