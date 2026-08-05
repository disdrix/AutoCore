# Review B (skeptical / adversarial): `aa_005769c0` WaterPhase_Ctor_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005769c0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-S) |
| **Counterpart** | `reviews/A_aa_005769c0_WaterPhase_Ctor_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is water **init** / registration | **Falsified** — field ctor only; registration is `0x00576860` |
| 2 | Zeros entire 0x20 object | **Falsified** — `+0x08` never written |
| 3 | Bare `ret` / no stack args | **Falsified** — `RET 4`; view formal |
| 4 | Name must be Drive_NDRiver_fx callee | **Reject** — NDRiver is env-method tail string; this is water phase object |
| 5 | Product demangle known | **Overstated** — inferred from caller/strings only |
| 6 | Decompiler `void` means no return value | **Understated** — EAX holds this for factory assignment |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete ctor / layout | **High** | Mis-sized object / missing fields |
| ABI RET 4 | **High** | Stack imbalance |
| Water singleton role | **High** | Wrong lifetime binding |
| +0x08 policy | **High** (bytes) | False zero-init assumption |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Surviving contract for AutoCore

```
// Port as complete ctor of 0x20 water object:
water = WaterPhase_Ctor(raw_0x20, view); // view from env+0xC0
// Must: install vtbl 009d3b04; view@+4; zero +0xC..+0x1C
// Must NOT: write +0x08; do not register token here; do not vcall here
// After return: owner DAT_00b0480c=env; vcall(+0x20); then RegisterToken
```

---

## 4. Verdict

Adversarial pass confirms A on ctor role, ABI, and layout hole. Rejects NDRiver-callee naming and full-zero myths. Product residual → **accept-with-gaps**.
