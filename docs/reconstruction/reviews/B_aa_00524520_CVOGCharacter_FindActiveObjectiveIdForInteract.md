# Review B (skeptical / adversarial): `aa_00524520` CVOGCharacter_FindActiveObjectiveIdForInteract

| Field | Value |
|---|---|
| **Stable ID** | `aa_00524520` |
| **VA** | `0x00524520` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (dual residual refresh — byte-level +0x40 walker) |
| **Counterpart** | `reviews/A_aa_00524520_CVOGCharacter_FindActiveObjectiveIdForInteract.md` |
| **System** | `interaction-activation` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | `FUN_00524520` is a boolean “isInteractable” helper | Caller truthy tests exist, but body stores `*(obj+0x10)` and IfInteractable does `mov [esp+0x1c], eax` as packet `@+0x18` | **Falsified** — returns **objective id** or 0 |
| 2 | Alias `Named_VOG_DEBUG_STOP` is the real name | Only linked via assert strings on lock misuse | **Falsified** — assert noise |
| 3 | Same as `Client_FindObjectiveMatchingTarget` | Different return (id vs def\*), eval slot (+0x40 vs +0x38), no pending `+0x55c` | **Falsified** |
| 4 | Hash `+0x548` is active **missions** | Missions hash is `+0x540`; objectives use `+0x548` | **Survives** as active **objectives** (**High**) |
| 5 | `FUN_0059d9c0(param_1,param_2)` means this=character | Bytes: `mov ecx, edi` (objInst) before call; helper reads `this+0x158` | **Falsified** — **this = objective** |
| 6 | Match uses evaluator `vtable+0x38` | Bytes: `call dword ptr [eax+0x40]` | **Falsified for this path** — **+0x40** |
| 7 | Helper only gets world (high-pcode undercount) | Bytes: `push world; push ebx(character); mov ecx,edi; call` + helper `ret 8` | **Falsified** — **two** stack args |
| 8 | Eval args are `(world, character)` order | Helper: `mov ebx,[esp+0x18]` world, `mov ebp,[esp+0x14]` char; then `push ebx; push ebp; call [eax+0x40]` → **(char, world)** | **Sealed** — character first |
| 9 | Empty active hash needs pending gate | No `+0x55c`; empty → unlock return 0 | **Survives** |
| 10 | Multiple matches pick “best” | Loop breaks on first non-zero | **Falsified** — **first hash-order only** |
| 11 | Character this is unrecoverable ambient ECX | IfInteractable: `mov ecx, [esi+0xe98]` before `push edi; call` | **Falsified for primary path** — **`client+0xE98`** |
| 12 | Packet `@+0x18` is not this return | Allow path: `mov [esp+0x1c], eax` with opcode at `[esp+4]` | **Falsified** — **is** this return |
| 13 | Type-4 miss uses −1 like SendUseObject | EAX remains 0 into allow path | **Falsified** — wires **0** |
| 14 | Clean arity invents helper args | Byte pushes match clean `(obj, char, world)` | **Survives** — clean correct |
| 15 | All 10 xrefs use `client+0xE98` | Only IfInteractable decoded to that load | **Open** for non-primary sites |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Null → 0; unlock always; `ret 4` | **High** | Hang / leak lock / stack imbalance |
| Active-obj walk `+0x548` / lock `+0x1d` | **High** | Wrong mission state |
| Return id `@+0x10` | **High** | Wire wrong objective |
| Eval slot `+0x40` via `0059d9c0` | **High** | Never match / wrong req class |
| Helper args `(char, world)` on eval | **High** | Eval sees swapped pointers |
| First-match only | **High** | Multi-obj wrong id |
| Distinct from `00525bd0` / `005245d0` | **High** | Port merges break paths |
| IfInteractable character `client+0xE98` | **High** | Wrong hash / crash |
| Packet `@+0x18` = return | **High** | Server gets wrong objective hint |
| Other call-site ECX | **Probable / Open** | UI paths may use different character |
| `+0x40` semantics per req type | **Tentative** | Silent no-match |
| Runtime hash order | **Open** | Non-deterministic “first” id |

---

## 3. Cross-check: high-pcode vs bytes

| Source | Helper CALL arity | Notes |
|---|---|---|
| Ghidra high pcode CALL @ `005245aa` | ECX + `stack[4]` only | **Undercounts** — misses second push |
| Bytes @ `005245a2` | `push world; push ebx; mov ecx,edi; call` | **Authoritative** |
| Helper `ret 8` | Two stack args | Confirms bytes |
| Eval CALLIND | `stack[4]=char`, `stack[8]=world` after helper prolog | Matches push order |

**Port rule:** Prefer **read_memory / bytes** over high-pcode CALL input lists for thiscall multi-arg helpers in this binary.

Sibling `005245d0` is a **clone** with `FUN_0059da10` / **`+0x44`** — same return shape (id). Strengthens “id finder family,” not “bool interact.”

`FUN_0059d9c0` sole caller = this unit (xref). Not a free-floating false positive.

---

## 4. Surviving contract for AutoCore

```
// Client interact objective id (IfInteractable path)
uint32 FindActiveObjectiveIdForInteract(Character* ch, Object* worldObj) {
  if (!worldObj) return 0;
  // Walk ch->activeObjectivesHash (+0x548), lock +0x1d
  // For each objective instance (node payload +8):
  //   if MatchTargetEvaluators_Slot40(obj, ch, worldObj):  // any eval vtbl+0x40(ch, world)
  //     return *(uint32*)(obj + 0x10);  // first hit
  // return 0;
}

// IfInteractable (primary):
//   ch = *(client + 0xE98);
//   id = FindActiveObjectiveIdForInteract(ch, target);
//   allow if id != 0 OR cloneType(target) == 4;
//   packet.IDObjective @ +0x18 = id;  // 0 on type-4 miss, never -1 on this path

// Port rules:
//  - Do NOT treat as bool-only; zero is a real id-field value.
//  - Do NOT use pending (+0x55c) gate from FindObjectiveMatchingTarget.
//  - Do NOT call evaluator +0x38 here; that is unconditional SendUseObject path.
//  - Do NOT assume −1 on miss (IfInteractable wires 0).
//  - Sibling +0x44 walker is a different product question (pick/hover).
//  - Eval slot is +0x40 with args (character, world), this = evaluator*.
```

---

## 5. What would overturn this dual

1. Bytes showing ECX into `0059d9c0` is **not** the objective payload (would invert helper this) — **contradicted** by `mov ecx, edi` after payload load.
2. Evidence `+0x548` payloads are **not** objective instances with id at `+0x10`.
3. Wire capture showing IfInteractable `@+0x18` ≠ this return — **contradicted** by `mov [esp+0x1c], eax`.
4. Evidence `client+0xE98` is not a character bearing `+0x548` (would reopen primary this, not the walk body).

Until then, body + primary caller claims stand at **High**.

---

## 6. Open questions

1. ECX load at remaining xrefs (tooltip `FUN_00524520()` with no visible arg is the weakest).
2. Implementers of evaluator `+0x40` vs `+0x38` vs `+0x44`.
3. Multi-match hash order (insertion vs mission order).
4. Exact product type of `client+0xE98` (offset sealed; name open).

**Verdict:** Prior bool/name/arity confusions are **dead**. Body and **IfInteractable wire path** are solid. Remaining risk is **non-primary call-site this** and **eval-slot semantics**, not the +0x40 walker loop. **accept-with-gaps.**
