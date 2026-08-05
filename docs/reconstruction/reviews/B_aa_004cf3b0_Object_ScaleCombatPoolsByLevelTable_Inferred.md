# Review B (skeptical / adversarial): `Object_ScaleCombatPoolsByLevelTable_Inferred` / `FUN_004cf3b0` @ `0x004cf3b0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf3b0` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_004cf3b0_Object_ScaleCombatPoolsByLevelTable_Inferred.md` |
| **Verdict** | **accept-with-gaps** — reject `table[(int)obj]`, “always runs”, and RecalcCombatPools identity |

---

## 1. Claims under attack

| # | Claim | Attack result |
|---|---|---|
| 1 | Index level table with object pointer (`(int)param_1`) | **Falsified as portable truth** — decompiler artifact; levels come from caller args |
| 2 | Same body as `Vehicle_RecalcCombatPools` | **Falsified** — that unit calcs max HP via `Vehicle_CalcMaxHitPoints`; this scales via **level table** |
| 3 | Always applies scale | **Falsified** — `vtbl+0x210(0)!=0` skips; TFID+`+0x1dc` can early-return |
| 4 | Two-arg only signature is complete | **Overstated** — callers pass third level; ESI ratio for current |
| 5 | Drives / steers vehicle | **Falsified** — pool vfuncs only |
| 6 | Table is integers / percents 0–100 | **Falsified** — float steps of 0.25 (`read_memory`) |
| 7 | Product name sealed | **Open** |
| 8 | Clean scaffold is bit-exact ready | **Overstated** — inherits decompiler index bug until residual fix |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Role = level-based pool rescale | **High** | Wrong system tag |
| Early gates | **Confirmed** | Double-scale / skip bugs |
| Table base `0x009cc390` values | **Confirmed** | Wrong HP multipliers |
| Not full equip recalc | **Confirmed** | Missing CalcMaxHitPoints path |
| Exact formula operands | **Medium** | Off-by-index max HP |
| ESI ratio source | **Open** | Current HP wrong after scale |

---

## 3. Surviving contract for AutoCore

```
// Structural port — do NOT use (int)obj as table index
void ScaleCombatPoolsByLevelTable(Object* obj, int levelFrom, int levelTo, float currentRatio):
  if obj.vfunc_210(0) != 0: return
  if linked_tfid_owner_blocks(): return
  obj.vfunc_23c()
  oldMax = obj.get_pool_max()           // +0x244 family
  factor = (table[levelTo] + 1.0f) / (table[levelFrom] + 1.0f)
  obj.set_pool_max(round(oldMax * factor))   // +0x248
  obj.set_pool_cur(round(get_max() * currentRatio))  // +0x240

// table = DAT_009cc390 float[]  (0,0,0.25,0.5,...)
// Callers often levelFrom=0, levelTo=character field +0xe818
```

---

## 4. Falsification notes

### 4.1 Equip path vs this helper

`Vehicle_RecalcCombatPools` may **call** this for kill-XP bonus scaling — it is a **subroutine**, not a rename of the whole equip recalc.

### 4.2 Spawn / level-up reuse

Same VA from AI spawn and level-change iterator proves **shared rescale**, not vehicle-only.

### 4.3 Decompiler `param_1` in denominator

Any port that does `table[(uintptr_t)obj]` is **wrong**. Fix indices from caller-level args / residual asm, not raw decompiler text alone.

---

## 5. Open questions

1. Clean residual patch for 3-arg + ESI + table indices.
2. English for `+0x210` / owner `+0x1dc`.
3. Runtime golden HP after level-up.

**Verdict:** **accept-with-gaps**. Sealed combat-pool level-table rescale role and gates; reject pointer-as-index and full-recalc identity.
