# Review B (skeptical / adversarial): `aa_004205e0` OleDb_WalkActiveBindings_Vtbl10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004205e0` |
| **VA** | `0x004205e0` |
| **Canonical name** | `OleDb_WalkActiveBindings_Vtbl10_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004205e0_OleDb_WalkActiveBindings_Vtbl10_Inferred.md` |
| **System** | COM / OLE DB accessor bind |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Stack-passed “this” / stdcall formals | Entry uses `ESI+8`; epilogue plain `ret` (`c3`) | **Falsified stack-this** |
| 2 | Invokes every binding regardless of flag | Flag byte at `entry+4` gates the vcall | **Falsified always-call** |
| 3 | Accumulates last hr only / never early-outs | Explicit `hr < 0` return inside loop | **Falsified no-early-out** |
| 4 | Many unrelated callers | Callers API returns only `FUN_0041c000` | **Falsified multi-caller** |
| 5 | Named callees in import table | Callees API empty; only indirect vtbl+0x10 | **Confirmed indirect-only** |

---

## 2. Live ≡ raw

Live `decompile_function` @ `0x004205e0` (autoassault.exe, 2026-07-29) matches `raw/aa_004205e0_FUN_004205e0.md` (`unaff_ESI`, stride-8 walk, vtbl+0x10). `read_memory` entry matches `mov ecx,[esi+8]` / count load.

---

## 3. Surviving contract

```
// ESI = bind context
// for each active binding entry (flag@+4): hr = iface->vtbl[0x10/4](...)
// return first negative hr, else last hr (0 default)
```

**Verdict:** **accept-with-gaps.** Adversarial pass does not overturn structural CF; product method/type names remain `_Inferred`.
