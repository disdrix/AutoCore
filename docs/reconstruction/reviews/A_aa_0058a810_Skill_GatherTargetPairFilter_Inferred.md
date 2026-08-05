# Review A (reconstruction fidelity): `aa_0058a810` Skill_GatherTargetPairFilter_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0058a810` |
| **VA** | `0x0058a810` |
| **Canonical name** | `Skill_GatherTargetPairFilter_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_0058a810_Skill_GatherTargetPairFilter_Inferred.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** under `_Inferred` name — mode CF sealed with Gather dual |

---

## 1. Purpose

Pass-2 **pair accept filter** for `Skill_GatherTargetsInArea`. Given candidate entity, caster, gather mode, and type filters, returns **1** accept / **0** reject and on accept writes a **float4 position/frame** into an out scratch (`param_8`). Encodes relationship classes (hostile/ally/self/crew/dead/etc.) used by multi-target skill gather and interact pick. **Not** cast validation (`Skill_ValidateTargetForSkill`) and **not** broadphase (`GetObjectsInArea`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0058a810_FUN_0058a810.md` |
| Annotated | `docs/reconstruction/raw/aa_0058a810_FUN_0058a810.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0058a810.cpp` |
| Function record | `docs/reconstruction/functions/aa_0058a810_FUN_0058a810.md` |
| Live decompile | Ghidra `batch_decompile` `0x0058a810` — **≡ raw** |
| Callers | `get_function_callers` → **sole** `Skill_GatherTargetsInArea` @ `0x0058d330` |
| Parent dual | `A/B_aa_0058d330_Skill_GatherTargetsInArea` + residual `a_0058d330.md` |
| Types | clonebase `+0x38`: Vehicle=`0xe`, Creature=`0x12`, Character=`0x14` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Sole caller GatherTargetsInArea | **Confirmed** | callers list |
| Return bool-ish (0/1) + out float4 | **High** | body |
| Mode **8** early accept (copy entity`[0x20..0x23]`) | **High** | first branch |
| Reject null / candidate==caster | **High** | |
| Reject `vtbl+0x198()!=0` unless mode **10** | **High** | dead-like gate |
| TFID dedupe vs outList base (`entity+0x58`) | **High** | primary-slot only, not full scan |
| filterB / flag bit10 / filterA type gates | **High** | body + residual table |
| Veh/Cre/Char remap position via vtbl `+0x1d4/+0x1d8/+0x1dc` | **High** | |
| Mode table CF (0/1/2/3/4/9/0xb/…) | **High** | sealed with parent dual |
| Mode English names | **INFERRED** | no PDB |
| Product C++ name | **Inferred** | no string → `_Inferred` |
| filterA exact match bypassed for Veh/Cre/Char | **High** | residual + body |

---

## 4. Control flow (sealed)

```
GatherTargetPairFilter(candidate, caster, outListBase, mode, filterA, filterB, filterC, outFrame):
  if mode==8:
    *outFrame = candidate.localFrame[0x20..]; return 1
  if !candidate or candidate==caster: return 0
  if candidate.IsDeadLike(+0x198) and mode!=10: return 0
  if TFID(candidate+0x58)==TFID(outListBase): return 0   // primary dedupe
  if !filterB and FUN_005134e0(): return 0
  if (flags>>10)&1 and mode!=3 and !filterC: return 0
  type = clonebase+0x38
  // position resolve by type 0xe/0x12/0x14 else filterA type gate
  write outFrame
  switch mode:
    2:  return caster.vtbl+0x298(candidate) != 0   // hostile
    1:  return caster.vtbl+0x298(candidate) == 0   // ally
    0xb: same vehicle/plant crew (+0x210 / FUN_005749d0)
    0:  related-owner via +0x214
    3:  type in {0xe,0x12,0x14}
    4:  same related TFID
    9:  type==3 or hostile
    default: return 1 after commons
```

Full table: parent residual `reviews/a_0058d330.md` §Pass-2.

---

## 5. Signature

```c
// Name INFERRED — sole consumer Skill_GatherTargetsInArea
uint8_t Skill_GatherTargetPairFilter_Inferred(
    int *candidate,      // param_1 entity
    int *caster,         // param_2
    void *outListBase,   // param_3 TFID dedupe base
    int gatherMode,      // param_4
    int filterA,         // param_5 type filter (-1 = soft)
    char filterB,        // param_6
    char filterC,        // param_7
    int *outFrame4);     // param_8 float4/out pos
```

---

## 6. Gaps / open

1. Retail enum symbol names for modes (CF sealed).
2. Product method name / containing class.
3. English for `FUN_005134e0` / `FUN_005130e0` / vtbl slots.
4. Runtime / bit-exact.
5. Whether any indirect call sites exist outside Gather (none found via callers tool).

**Verdict:** **accept-with-gaps** — sole-caller pair filter + mode CF sealed with Gather dual; `_Inferred` name.

---

## Checklist

| Check | Result |
|---|---|
| Sole caller | **Pass** |
| Live decompile ≡ raw | **Pass** |
| Mode 8 early / 10 dead-like / 1 vs 2 polarity | **Pass** |
| Cross-link Gather dual | **Pass** |
| Product name | **Open** (`_Inferred`) |
| Verdict | **accept-with-gaps** |
