# Review B (skeptical / adversarial): `aa_00723120` CSoundManager_AllocPlayInstance_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00723120` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00723120_CSoundManager_AllocPlayInstance_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is mission-complete audio table grant | Alias confusion from scaffold name | **Falsified** — pure `new`+ctor+push; no mission/reward |
| 2 | Ctor receives `this` as first stack arg | Decompiler `FUN_0071e570(param_2,...)` without `pvVar1` | **Falsified as stack-this** — ctor uses **`in_EAX`** = result of `operator_new` |
| 3 | Same path as `FUN_007258a0` | | **Falsified** — parent uses this when `entry+0x10C`; proximity queue is `007258a0` |
| 4 | Always succeeds / returns instance | void; no success code | **Sealed** — void; no return of ptr |
| 5 | Size is 0x154 like FX def records | | **Falsified** — **0x150** only |
| 6 | English name PDB-proven | | **Not sealed** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| `new(0x150)` + ctor + push | **High** | Leak / wrong object |
| EAX this handoff | **High** | Port “missing this” |
| Role = alternate FX play attach | **High** | Wrong play branch |
| Full arg map | **Medium** | Bad TFID/pos |
| Null-new behavior | **Medium** | Crash vs skip |

---

## 3. Cross-check against raw

```text
// raw ≡ live (reg-recovered this)
pv = operator_new(0x150);
if (pv) FUN_0071e570(/*EAX=pv*/, name, tfid*, ...);
FUN_004406e0(/* push ESI=pv into vector */);
return;
```

---

## 4. Surviving contract for AutoCore

```
AllocPlayInstance(entryParams...):
  inst = new PlayInstance[0x150]
  if inst: construct from name/TFID/pos/type
  push inst onto pending play list
  // no return value
```

**Port tests:**

* Must not call proximity radius gates (those are `007258a0`).
* Instance size 0x150, not 0x154 def stride.

---

## 5. Open questions

1. Who owns/free the 0x150 instances.
2. Dual seal of `FUN_0071e570` field map.

**Verdict:** **accept-with-gaps**
