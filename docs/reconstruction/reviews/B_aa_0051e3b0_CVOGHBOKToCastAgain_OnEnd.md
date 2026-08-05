# Review B (skeptical / adversarial): `aa_0051e3b0` CVOGHBOKToCastAgain_OnEnd

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051e3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` (strengthened `2026-07-29`) |
| **Counterpart** | `reviews/A_aa_0051e3b0_CVOGHBOKToCastAgain_OnEnd.md` |
| **Residual** | `reviews/a_0051e3b0.md` |
| **Verdict** | **accept** on CF/ABI; empty-stub English open only |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Leaves casting stuck | **Falsified** — `push 0` → `skill+0x628=0` |
| 2 | Meaningful cleanup via `FUN_005081f0` | **Falsified** — single-byte `C3` RET |
| 3 | Sets casting 1 | **Falsified** — OnStart only (`push 1`) |
| 4 | Erases category cooldown map | **Falsified** — no map ops in body |
| 5 | `unaff_SI` is a real third formal | **Falsified** — only one stack push |
| 6 | Gate is skill pointer | **Falsified** — gate `+0x18` owner; skill is `+0x24` |
| 7 | Direct call sites exist | **Falsified** — sole xref is vtbl DATA `0x009ce1d8` |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Clear casting (`+0x628`) | **High** | Stuck casting UI / LocalCastValidate gate |
| Empty trailing stub | **High** | Inventing teardown AutoCore does not need |
| Category map on end | **High** (absent) | Stale CD is **ctor map** concern, not OnEnd body |
| Virtual dispatch only | **High** | Miss abort path if only searching CALL sites |

---

## 3. Cross-check against machine

```
if HB+0x18: SetIsCastingFlag(HB+0x24, 0);  // ret 4 callee; false → flag only
tail jmp FUN_005081f0;                    // C3 ret, ECX=this
Clean ≡ raw ≡ bytes. No category erase.
```

---

## 4. Surviving contract for AutoCore

```
OKToCastAgain_OnEnd:
  clear skill+0x628 when type-8 HB ends (owner still attached)
  do NOT expect category map erase here (map from ctor may outlive HB)
  do NOT implement real work behind FUN_005081f0 (no-op)
  invoke via HB vtbl+0x14 (remove/abort/dtor helper paths)
```

---

## 5. Open questions

1. Product English for empty stub (optional rename only).
2. Sibling: which remove/abort helpers always vcall +0x14 (enumerate outside this VA).

**Verdict:** **accept** on CF/ABI; cleanup identity sealed as no-op
