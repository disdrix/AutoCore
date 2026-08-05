# Review B (skeptical / adversarial): `aa_005d4440` CVOGObject_SwitchHBAIByCode

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d4440` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_005d4440_CVOGObject_SwitchHBAIByCode.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always uses only `CVOGHBAI_CreateByAICode` | Factory-only mental model | **Falsified** — codes 6/7 construct Default / WalkingTurreted directly |
| 2 | Code 7 is factory case “6” | Off-by-one table | **Falsified** — 7 is Base_Default here; factory dual’s case 6 is WalkingTurreted |
| 3 | No early out when already on code | Always rebuild | **Falsified** — vtbl+0x18 compare then return |
| 4 | Silent replace without destroying old | Leak claim | **Falsified** on several paths — scalar delete `(*vtbl)(1)` |
| 5 | Pure function (no side locks / pose) | Leaf switch | **Falsified** — lock 0x10, optional pose stash when `this+8≠0` |
| 6 | `this+0x40` means “fully ready phys” | Confuse with CVOGPhysics+0x40 | **Falsified** — here boolean `param_2==7` on AI object layout |
| 7 | Name string-proven | Symbol inflation | **Not sealed** — Probable from structure |
| 8 | `FUN_0055dfb0` always required | Skip gate | **Falsified** — only special→normal entry; other paths free |
| 9 | Epilogue pose restore always sees original curCode in `iStack_5c` | Blind trust decomp temps | **Not sealed** — some paths overwrite `iStack_5c`; residual Medium |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Same-code early out | **High** | Spurious rebuild |
| 6/7 special family | **High** | Wrong AI class |
| CreateByAICode for normal codes | **High** | Wrong subclass |
| AI pointer at obj+0x3c | **High** | Corrupt wrong field |
| obj+0x40 = (code==7) | **High** | Flag polarity |
| Link vtbl +0x78/+0x7c English | **Low–Med** | Doc only |
| iStack_5c epilogue correctness | **Medium** | Pose restore wrong cur |

---

## 3. Cross-check against raw

```text
// raw aa_005d4440 ≡ live decompile 2026-07-29
cur = AI(+0x3c)->vtbl[+0x18]()
if cur == newCode: return
special(c) = (c==6 || c==7)
if normal(new) && special(cur) && !FUN_0055dfb0(): return
// lock; optional code-7 pose
// replace AI (CreateByAICode / Default / WalkingTurreted / link hooks)
// obj+0x14 = AI+0x60; obj+0x40 = (newCode==7)
// unlock; optional pose restore
```

Factory dual `aa_005d3d10` codes 1..6 + default align with this unit’s normal vs 6/7 split.

---

## 4. Surviving contract for AutoCore

```
SwitchHBAIByCode(obj, newCode):
  if obj.ai.getCode() == newCode: return
  // block entering normal AI from 6/7 without default AI available
  // construct/install matching HBAI subclass
  // destroy or relink previous AI
  // publish AI+0x60 at obj+0x14; flag obj+0x40 when Default(7)

// Do NOT:
//   treat as physics fully-ready flag
//   assume CreateByAICode covers 6/7
//   skip same-code fast path
```

**Port tests:**

* Same code → zero alloc.
* 6 ↔ 7 ↔ normal transitions exercise special ctors.
* `obj+0x3c` always ends as live AI (or documented destroy path).
* `obj+0x40` true iff final code is 7.

---

## 5. Open questions

1. Confirm `iStack_5c` live range through all branches (asm seal if pose restore misbehaves).
2. Dual `FUN_0055dfb0`.
3. English for link vfuncs +0x78/+0x7c.
4. Runtime AICode transition matrix.

**Verdict:** **accept-with-gaps** — family split and early-out attacks **fail**; residual decomp temp + product names open.
