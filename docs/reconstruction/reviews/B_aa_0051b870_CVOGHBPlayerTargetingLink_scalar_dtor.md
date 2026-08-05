# Review B (skeptical / adversarial): `aa_0051b870` CVOGHBPlayerTargetingLink_scalar_dtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051b870` |
| **VA** | `0x0051b870` |
| **Canonical name** | `CVOGHBPlayerTargetingLink_scalar_dtor` (**Inferred**) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Skeptical / adversarial (Path B) |
| **Counterpart** | `reviews/A_aa_0051b870_CVOGHBPlayerTargetingLink_scalar_dtor.md` |
| **System** | `heartbeat` / targeting link |
| **Live tools** | Independent decompile + `read_memory` + base dtor / ctor dual cross-check |
| **Verdict** | **accept-with-gaps** — accept CF; name remains **Inferred** |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | This is OnHeartBeat / tick | **Falsified** — no period math; pure dtor + optional delete |
| 2 | Always frees memory | **Falsified** — only when `flags & 1` |
| 3 | Completely independent of base HB dtor | **Falsified** — calls `FUN_00512060` body (shared demote + detach) |
| 4 | Product mangled name proven | **Not proven** — no string; class High via RTTI/ctor dual only |
| 5 | Vector deleting dtor (`flags & 2`) | **Falsified** — only bit 0 tested |
| 6 | Body is a thunk with no work | **Falsified** — real call + conditional delete + `ret 4` |
| 7 | Same entry as `0x0051b850` | **Falsified** — distinct 18 B clear-selected-target leaf |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Scalar-deleting dtor CF | **High** | Leak or double-free in port |
| Base dtor always runs | **High** | Owner-list detach skipped |
| `flags & 1` gate | **High** | Stack delete when stack-allocated |
| Vtbl[0] of derived | **High** | Wrong dispatch |
| Product mangled symbol | **Tentative** | Registry polish only |
| Class name | **High** | Via ctor/RTTI duals |

---

## 3. Cross-check vs base scalar dtor `FUN_00512070`

Identical control shape:

```
dtor_body(this);
if (flags & 1) operator_delete(this);
return this;
```

Only the near-call target / identity differs in Ghidra naming; derived entry is this VA at derived vtbl[0]. **Agree** with A.

---

## 4. What is safe to claim

| Safe | Unsafe |
|---|---|
| MSVC scalar-deleting dtor pattern | Exact `??_G` spelling without PDB |
| Calls base demote+detach | Extra field cleanup beyond base |
| Vtbl slot 0 of PlayerTargetingLink | Also implements OnStart/OnEnd |

---

## 5. CF challenge of Review A

- Body CF: **agree High**
- Inferred name acceptable with gaps: **agree**
- Not OnHeartBeat: **agree**

**Verdict:** **accept-with-gaps**
