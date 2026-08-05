# Review A (reconstruction fidelity): `aa_004cf3b0` Object_ScaleCombatPoolsByLevelTable_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cf3b0` |
| **VA** | `0x004cf3b0` |
| **Canonical name** | `Object_ScaleCombatPoolsByLevelTable_Inferred` (Ghidra `FUN_004cf3b0`) |
| **Ghidra name** | `FUN_004cf3b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (OWN-ONLY dual) |
| **Counterpart** | `reviews/B_aa_004cf3b0_Object_ScaleCombatPoolsByLevelTable_Inferred.md` |
| **System** | `vehicle-combat-pools` / combat pool rescale |
| **Verdict** | **accept-with-gaps** — gate + TFID early-out + pool vfuncs + level table role sealed; decompiler index operands residual |
| **Dual status** | **Present (first full dual)** |

---

## 1. Purpose

**Rescale an object’s combat-pool max (and current)** using the global float level table **`DAT_009cc390`**, sharing the same vfunc family as `Vehicle_RecalcCombatPools` (`+0x23c` / `+0x244` / `+0x248` / `+0x240`).

Callers (live):

| Caller | Use |
|---|---|
| `Vehicle_RecalcCombatPools` (`0x00501f60`) | Optional kill-XP path: `FUN_004cf3b0(comp, 0, *(char+0xe818))` |
| `FUN_004d28c0` | On level transition: for each listed object `FUN_004cf3b0(obj, oldLevel, newLevel)` (levels clamped ≤0xF in parent) |
| `FUN_00566490` (spawn AI) | After create: `FUN_004cf3b0(spawned, 0, *(char+0xe818))` when kill-XP weapon allows |

High-level CF (live decompile + callers):

```
// Rough shape — prefer live body; table index wiring has decompiler noise (see §3)
void Object_ScaleCombatPoolsByLevelTable_Inferred(Object *obj, int levelA, int levelB)
// plus unaff_ESI float ratio for current-pool fill (caller register)

if (obj->vtbl[+0x210](0) != 0) return;          // already scaled / blocked

iface = obj->vtbl[+0x1d8]();
if (iface) {
  // if TFID at iface+0x228.. valid-ish:
  //   resolved = Object_ResolveFromTFID(&tfid)
  //   if resolved && resolved->vtbl[+0x1dc](): return   // owned/linked skip
}

obj->vtbl[+0x23c]();                             // pre-hook
// read pool value(s) via +0x244 family
// set max via +0x248( ROUND( scale_from_table(levelA, levelB) * max ) )
// set current via +0x240( ROUND( max * ratio_ESI ) )
```

**Level table** (`read_memory` @ `0x009cc390`, first 16 floats):

| Index | Bits | Float |
|---|---|---|
| 0 | `00000000` | **0.0** |
| 1 | `00000000` | **0.0** |
| 2 | `3e800000` | **0.25** |
| 3 | `3f000000` | **0.5** |
| 4 | `3f400000` | **0.75** |
| 5 | `3f800000` | **1.0** |
| … | … | steps of **0.25** upward (`1.25…3.5` observed in first 16) |

Decompile formula shape (with known operand caveats):

```
newMax = ROUND( (table[levelB] + 1.0f) * ( oldMax / (table[levelA] + 1.0f) ) )
```

When `levelA == 0` and `table[0]==0`: `newMax ≈ ROUND((table[levelB]+1) * oldMax)` — matches vehicle/spawn call pattern `(obj, 0, charLevelField)`.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Function record / raw / annotated / clean | `aa_004cf3b0_*`, `FUN_004cf3b0.cpp` |
| Live decompile | Ghidra `batch_decompile` / `decompile_function` `0x004cf3b0` |
| Entry + body bytes | `read_memory` 200 B @ `0x004cf3b0` |
| Table | `read_memory` 64 B @ `0x009cc390` |
| Callers | `get_function_callers`: `004d28c0`, `00566490`, `Vehicle_RecalcCombatPools` |
| Callees | `Object_ResolveFromTFID`; indirect pool vfuncs |
| Parent duals | `A_aa_00501f60_Vehicle_RecalcCombatPools` |

**Not performed:** full SSE formula re-lift instruction-by-instruction beyond entry/table; dual of `004d28c0`; runtime; bit-exact; Launcher.

---

## 3. Decompiler hazards (owned residual)

1. **Signature under-arity:** Ghidra shows `(int *param_1, int param_2)` but callers pass **three** stack values `(obj, levelA, levelB)`. Third level participates in table scale; `unaff_ESI` is a **float fill ratio** for `+0x240`, not a bitcast of level.
2. **Table index ` (int)param_1 * 4 `:** nonsense for object pointer — decompiler confused object with level index. Prefer caller-level indices + assembly residual; do **not** port `table[(int)obj]`.
3. **`+0x210(0)` gate:** early exit when nonzero — English (“already applied” / “dead” / other) **Open**.

Despite hazards, **role**, **gates**, **TFID early-out**, **pool vfunc set**, and **table base/constants** are sealed High for structural ports.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Combat-pool rescale helper (not drive/input) | **High** | callers + vfunc family vs RecalcCombatPools |
| Gate `vtbl+0x210(0)==0` required to proceed | **Confirmed** | decompile |
| TFID resolve early return path | **Confirmed** | `Object_ResolveFromTFID` + `+0x1dc` |
| Uses `DAT_009cc390` level floats | **Confirmed** | decompile + `read_memory` |
| Table values 0,0,0.25,0.5,… | **Confirmed** | bytes |
| Set max `+0x248` / current `+0x240` | **Confirmed** | decompile |
| Callers: equip recalc, level change, spawn | **Confirmed** | xrefs |
| Exact 3-arg / ESI ABI English | **Probable** | callers High; decompiler residual |
| Precise SSE order ≡ decompile text | **Medium** | body uses CVTSI2SS/DIVSS; full re-lift residual |
| Product name | **Open** | `_Inferred` |

---

## 5. Control flow checklist

| Stage | Match |
|---|---|
| `+0x210(0)` hard gate | **Yes** |
| Optional TFID owner skip | **Yes** |
| Pre-hook `+0x23c` | **Yes** |
| Scale max via table + `+0x248` | **Yes** |
| Scale current via ratio + `+0x240` | **Yes** |
| No mission dialog / UI select | **Yes** |

---

## 6. Gaps

1. Fix table-index operands in clean/raw vs live (decompiler bug) — residual strengthen.
2. Product name; `+0x210` / `+0x1dc` English.
3. Whether ESI ratio is always current/max from parent or sometimes 1.0.
4. Dual `004d28c0` level-transition owner.
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — combat-pool level-table rescale role and gates sealed; operand-level decompiler defects documented, not silently ported.
