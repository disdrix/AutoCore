# Review B (skeptical / adversarial): `aa_005d3b30` CVOGHBAIBase_ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_005d3b30` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-23` |
| **Counterpart** | `reviews/A_aa_005d3b30_CVOGHBAIBase_ctor.md` |
| **Verdict** | **accept-with-gaps** on CF; layout names open |

---

## 1. Claims under attack

| # | Claim | Attack |
|---|---|---|
| 1 | Leaves garbage targets | **Falsified — zeros key ptrs** |
| 2 | No vtable | **Falsified — base vtbl** |
| 3 | Finished exact layout | **Overstated — many anonymous slots** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Base vtbl | High | Wrong virtuals |
| Zero target slots | High | Stale target crash |
| g_flOne defaults | Tentative | Wrong default ranges |

---

## 3. Cross-check against raw

```
*this=baseVtbl; zero slots; g_flOne scales;
copy param_2 owner block (partial clear).
Clean ≡ raw.
```

---

## 4. Surviving contract for AutoCore

```
HBAIBase_ctor(this, ownerCtx, ...):
  install base vtbl; clear targets; default floats; seed owner context
  subclasses chain this then replace vtbl
```

---

## 5. Open questions

1. Publish offset table for HBAIBase.
2. Confirm param_2 layout vs owner dual-base.

**Verdict:** **accept-with-gaps** on CF; layout names open
