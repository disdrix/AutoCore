# Review B (skeptical / adversarial): `aa_00496f70` Class_009c7a1c_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00496f70` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W29-G) |
| **Counterpart** | `reviews/A_aa_00496f70_Class_009c7a1c_Ctor.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This is a scalar-deleting ctor / factory | **Falsified** — no `operator_new` inside; factory is caller `FUN_004cda90`; returns this; `ret 4` for one formal |
| 2 | No stack formals (`__fastcall` only) | **Falsified** — epilogue `C2 04 00`; decompile + sole caller pass parent |
| 3 | Same role as complete dtor | **Falsified** — ctor init path; dtor twin is `0x004970b0` |
| 4 | List head written at `this+0` | **Falsified** — `LEA EDI,[ESI+0x0C]`; head at `+0x10` |
| 5 | Palantir-desktop legacy name is product | **Falsified** — narrow multi-hop callee seed; vtbl suffix is structural name |
| 6 | Product type known | **Overstated** — structural Class_009c7a1c only |
| 7 | `FUN_00457c60` is thiscall on list | **Weak/false** — factory; no this use; returns node* |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Complete ctor for PTR_FUN_009c7a1c | **High** | Wrong lifecycle pairing |
| ABI ret 4 + context arg | **High** | Stack corruption on port |
| List @ +0x0C / head @ +0x10 | **High** | Double-free / leak vs dtor |
| Size 0xC8 | **High** | Truncated object |
| Product English | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against factory caller

```
// FUN_004cda90 (sole caller):
pv = operator_new(0xC8);
if pv: u = FUN_00496f70(parent);  // this=pv, stack=parent
*(parent+0xE898) = u;
```

Matches `ret 4`, return-this, and layout extent ≤ `+0xC4`.

---

## 4. Surviving contract for AutoCore

```
obj = operator_new(0xC8);
Class_009c7a1c_Ctor(obj, parent_ctx);
// vtbl, list sentinel, zeros, flags/floats
// Destroy with Class_009c7a1c_CompleteDtor (not this VA)
// Scalar delete via FUN_004975e0 only when flags require free
```

---

## 5. Verdict

Adversarial pass confirms A on ABI, list placement, and twin pairing. Product name residual → **accept-with-gaps**.
