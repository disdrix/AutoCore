# Review B (skeptical / adversarial): `aa_0060d630` CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress

| Field | Value |
|---|---|
| **Stable ID** | `aa_0060d630` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-08-04` (WQ7R-H) |
| **Counterpart** | `reviews/A_aa_0060d630_CVOGObjectiveRequirement_UseItem_ApplyObjectUseProgress.md` |
| **Scratch** | `tmp/a_0060d630.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This is Collect/Deliver apply | RTTI + vtable are **UseItem**; Collect is separate class | **Falsified** |
| 2 | This is InitActive | InitActive is `0x0060d540` (ends `0060d62f`); different CF (no progress +=) | **Falsified** |
| 3 | OnComplete does give/remove | OnComplete `0x0060cfd0` is empty stub dual | **Falsified** |
| 4 | Always GiveMission | Only if re-eval success **and** `req+0x4c != -1` | **Overstated** |
| 5 | Multiple callers | Sole `FUN_0060df70` | **Sealed sole** |
| 6 | Progress uses different slot than Eval | Eval `@+0x08` same formula; int* decomp `param_1+2` ≡ byte+8 | **Sealed same** |
| 7 | `unaff_EBX` is trustworthy as-is | Decompiler unaffiliated — destroy path needs image re-bind | **Attack holds (gap)** |
| 8 | Client give is server-authoritative | Client-side give helper; authority open | **Gap** |
| 9 | Name needs `_Inferred` | Class RTTI High; method role from caller+CF High enough for product method English | **Name accepted** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| UseItem class identity | **High** | Wrong system map |
| GiveMission call site | **High** | Miss residual grant chain |
| Progress += 1 semantics | **High** | Wrong UseItem slot model |
| Destroy target identity | **Probable** | Wrong object teardown |
| Flag dictionary @+0x1c.. | **Tentative** | Wrong remove policy |
| Full UseItem event ABI | **Tentative** | Mis-wire AutoCore object use |
| Runtime | **Open** | Silent client desync |

---

## 3. Surviving contract for AutoCore

```
// Client-only optimistic path — do not treat as sole authority
ApplyObjectUseProgress(req, charCtx, progress, worldObj) -> 0|1
  require local player (+0x7e)
  require !Eval(req, charCtx, progress)
  require host payload charCtx+0x250 / +0x2b0
  maybe GiveByCbid(req+0x28)
  progress.slot[req+8] += 1.0f
  done = Eval(...)
  maybe remove inv / destroy worldObj
  maybe RemoveInventoryItem(req+0x2c)
  if done:
    if req+0x4c != -1: GiveMission(req+0x4c)
    maybe GiveByCbid(req+0x48)
  return 1
```

---

## 4. Gaps that block full accept

1. Seal EBX/worldObj mid-body without `disassemble_bytes` (prefer targeted `read_memory` of movs — done partial at entry only).
2. Event 9/10 product dictionary.
3. Runtime capture with Launcher approval.

**Verdict:** **accept-with-gaps**.
