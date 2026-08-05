# Review B (skeptical / adversarial): `aa_0051a700` Skill_ClearCastBindingAndMaybeRestartCd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051a700` |
| **VA** | `0x0051a700` |
| **Canonical name** | `Skill_ClearCastBindingAndMaybeRestartCd` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (dual residual strengthen `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_0051a700_Skill_ClearCastBindingAndMaybeRestartCd.md` |
| **Residual scratch** | `reviews/a_0051a700.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always restarts CD / cast-again | Body: `skill==0` or `+0x61c==0` → no call | **Falsified** |
| 2 | Restart only when erase succeeds | Restart arm is **after** erase `if`; no dependence on match | **Falsified** as erase-coupled |
| 3 | Full TFID16 must match to erase | Only `+0x18`, `+0x1c`, `byte(+0x20)` compared; no `+0x24` / arg4 | **Falsified** full-equality |
| 4 | Decomp formals `(pSkill, nSkillId, nTfidLo…)` | Call sites + stack offsets: arg0=skillId key; arg1–3=TFID partial | **Falsified** names |
| 5 | `FUN_00518c20` is multi-arg map API | Unary leave-FUN; pushes feed find/erase | **Agree noise** with A / `aa_00518c20` |
| 6 | Same as `Skill_SiblingCastClear` | Sibling walks `host+0xB0` HB list; this mutates **map** `+0x68` | **Falsified** merge |
| 7 | Same as Lookup (read-only) | Erase + optional HB start | **Falsified** |
| 8 | `+0x61c` gate same polarity as Apply/RequestCast | Those start when `+0x61c==0`; Clear starts when `!=0` | **Falsified** same-gate claim — polarity **inverted** |
| 9 | `vtbl+0x234()` takes no args | Bytes: `push skillId` before `call [edx+0x234]` | **Falsified** decomp zero-arg |
| 10 | StartCastAgain 3–4 stack formals from decomp | Sibling `RET 0x8`; here `push 0; push skill` only | **Falsified** arity |
| 11 | Validates range / spends power | No such callees or fields | **Falsified** |
| 12 | arg4/`bGlobal` gates global TFID | Never read in body bytes | **Falsified** as body gate |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ABI `RET 0x14` / 5 stack formals | **Confirmed** | Hook/stack corruption |
| skillId key find + partial TFID erase gate | **Confirmed** | Stuck bind / wrong wipe |
| Erase = `FUN_0051cb40` after match | **Confirmed** | Map corruption |
| Restart independent of erase | **Confirmed** | Miss CD restart when mismatch |
| `+0x61c != 0` → StartCastAgain charge **0** | **Confirmed** | Double-CD or no reenable |
| `vtbl+0x234(skillId)` returns skill runtime | **High** | Wrong object for `+0x61c` / HB |
| Map shell `FUN_00518c20` / `+0x68` | **Confirmed** (sibling) | Wrong subsystem |
| Map owner product type | **Open** | Port to wrong object |
| Product meaning of `+0x61c` | **Open** | Invert client CD policy vs server |
| arg4 call-site semantics outside body | **Open** | ABI keep-alive only |

---

## 3. Cross-check against raw / PE

```
raw/clean CF: get map → find skillId → if hit+partial TFID: erase → resolve skill → maybe StartCastAgain(0).
PE body 0x0051a700..0x0051a786: same CF; epilogue C2 14 00.
Decompiler noise: multi-arg FUN_00518c20; zero-arg vtbl+0x234; 4-arg StartCastAgain; misnamed formals.
Sibling seals: Map_ExactFindByIntKey @ 0x0051a717; StartCastAgain @ 0x0051a77c charge 0.
```

### Polarity trap (`skill+0x61c`)

Do **not** merge Clear's gate with optimistic cast / ApplyStatus:

| Path | Gate before StartCastAgain | Charge |
|---|---|---|
| RequestCast / QuickBar / Stance | often `+0x61c == 0` (+ bind free) | skill+0x14 etc. |
| ApplyStatusEffectLocal (sim) | `+0x61c == 0` | packet delay |
| **ClearCastBinding (this VA)** | **`+0x61c != 0`** | **0** |

Calling both Apply restart and Clear restart without understanding the bit will double type-8 HBs (StartCastAgain itself has **no** dedup — sibling dual).

### Partial TFID trap

Lookup copies **full** TFID16 from `node+0x18…+0x24`. Clear **erases** only if the first 9 value bytes match args (2 dwords + 1 byte) — same partial pattern as `Skill_SiblingCastClear` / Apply cancel compare. Mismatched pad/`+0x24` alone does **not** block erase; arg4 is not consulted.

---

## 4. Surviving contract for AutoCore

```
ClearCastBindingAndMaybeRestartCd(owner, skillId, tfidPartial):
  // client-local cast bookkeeping (not server authority)
  map = lazy ActiveCastBindingMap shell (FUN_00518c20 @ owner+0x68)
  it  = map.exact_find(skillId)              // FUN_0051c150; key node+0x10
  if it != end
     and it.value.tfid0 == tfid0
     and it.value.tfid1 == tfid1
     and (u8)it.value.tfid2 == (u8)tfid2:   // partial; not full TFID16
        map.erase(it)                        // FUN_0051cb40

  skill = owner.vtbl+0x234(skillId)
  if skill && skill.byte_0x61c != 0:
     StartCastAgainHeartbeat(owner, skill, chargeMs=0)  // type-8; no in-unit dedup

Pair:
  LookupActiveCastBinding  — read-only TFID16 query
  SiblingCastClear         — host+0xB0 HB list stop (not this map)
```

Port note: server must own real CD; this is **client/sim** bind clear + optional optimistic restart.

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| `RET 0x14` / 5 stack formals | **Agree Confirmed** (PE) |
| skillId + partial TFID formals | **Agree High** |
| arg4 unused in body | **Agree Falsified-as-gate** |
| Map via leave-FUN `FUN_00518c20` | **Agree Confirmed** |
| Find via `FUN_0051c150` | **Agree Confirmed** |
| Erase via `FUN_0051cb40` | **Agree Confirmed** |
| Restart outside erase gate | **Agree Confirmed** |
| `+0x61c != 0` + charge 0 | **Agree Confirmed** |
| Inverted polarity vs Apply/Request | **Agree** — do not unify gates |
| vtbl+0x234 takes skillId | **Agree Confirmed** |
| accept-with-gaps | **Agree** |
| Map owner product sealed | **Reject** — still Open |

---

## 6. Open questions

1. Seal map **owner** type with `FUN_00518c20` / category-map twin residual.
2. Name or leave-FUN `FUN_0051cb40` / erase iterator packaging.
3. Product name for `vtbl+0x234` and durable semantics of `skill+0x61c` (defer vs “restart pending”).
4. Full caller inventory via live xrefs (this pass: ApplyStatus + FUN_00578ce0 from artifacts; Ghidra MCP down).
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — agree with A residual seals; block full-TFID erase, always-restart, same-polarity-`+0x61c`, and map/list merge over-claims.
