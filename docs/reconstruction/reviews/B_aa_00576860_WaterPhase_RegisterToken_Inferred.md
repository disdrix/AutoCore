# Review B (skeptical / adversarial): `aa_00576860` WaterPhase_RegisterToken_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00576860` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W32-S) |
| **Counterpart** | `reviews/A_aa_00576860_WaterPhase_RegisterToken_Inferred.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | This constructs the 0x20 water object | **Falsified** — only `new(4)` token; water object is `0x005769c0` |
| 2 | Decompiler full story of `FUN_00746400(iVar2)` free call | **Incomplete** — bytes force `ECX=[DAT_00d1f620]` thiscall |
| 3 | Only success is return 1 | **Falsified** — parent accepts any `hr >= 0` (0 and 1 both ok) |
| 4 | Body is water-exclusive algorithm | **Partially overstated** — CF twin of distort `FUN_00576d70`; water is call-site binding |
| 5 | Name Drive_NDRiver_fx callee | **Reject** — env-method phase registration, not FX load |
| 6 | Always leaks token on find-hit | **Open/possible** — if found, newly allocated token may not free (not proven here; gap) |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Register / find-or-append role | **High** | Wrong phase bootstrap |
| Return -1 fail vs >=0 ok | **High** | False fail log / missed fail |
| Global host this-arg | **High** | Wrong container |
| Token leak on hit | **Medium/open** | Memory policy |
| Product demangle | **Low** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Surviving contract for AutoCore

```
// Port as free function after water vcall(+0x20):
hr = WaterPhase_RegisterToken();
if (hr < 0) log water fail;
// Must: new(4)+token vtbl; registry host DAT_00d1f620
// Must NOT: treat as water object ctor; do not require return==1 only
// Note: may allocate a throwaway token each call even if already registered
```

---

## 4. Verdict

Adversarial pass confirms A on helper role, ABI, return policy, and decompiler gap fix for host ECX. Notes possible token leak and twin CF with distort. Product residual → **accept-with-gaps**.
