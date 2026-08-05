# Review B (skeptical / adversarial): `aa_004ff350` Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ff350` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004ff350_Vehicle_ForEachEquippedItem_CastOrClearGfx_Inferred.md` |
| **Verdict** | **accept-with-gaps** on dual clear/cast walk; **reject** claims that all slots get status hooks, that param_2 is a rich enum, or that slot product names are sealed |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | Always casts skills | `param_2==0` → clear path only | **Falsified** |
| 2 | Status hooks on every slot | Only +0x26c and +0x270 call `004fe380` | **Falsified** |
| 3 | Turret gets status hooks | Turret arm is clear/cast only | **Falsified** |
| 4 | Hardpoints only | Self + five more slots | **Falsified narrow scope** |
| 5 | `param_2` is multi-value mode enum | Body only tests zero vs non-zero | **Overclaim risk** — treat as bool |
| 6 | Slot offsets product-named in unit | No strings; layout residual | **Hold tentative English** |
| 7 | Drive-control axis writer | Equip/gfx/skill side effects only | **Falsified** as drive axis unit |
| 8 | Bit-exact complete | Runtime open | **Fail** |

---

## 2. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Zero vs non-zero branch | **High** | Wrong enter-world skill/gfx side effects |
| Slot enumeration CF | **High** | Miss equip reaction on enter |
| Status-hooks subset | **High** | Double-apply or skip PP/armor hooks |
| Product slot names | **Tentative** | Bad layout docs |
| MI adjust meaning | **Probable** CF | Wrong this for callees |

---

## 3. Surviving contract

```
On enter-world cast path (doCast=1) or clear path (0):
  walk hardpoints + self + equip slots;
  clear gfx OR cast equip skills per flag;
  status hooks only for +0x26c / +0x270.

Do NOT invent axis thr/steer writes here.
```

**Verdict:** **accept-with-gaps**
