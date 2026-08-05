# Review A (reconstruction fidelity): `aa_004e9aa0` CVOGPhysicsUtils_FindDistanceToTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e9aa0` |
| **VA** | `0x004e9aa0` |
| **Canonical name** | `CVOGPhysicsUtils_FindDistanceToTarget` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004e9aa0_CVOGPhysicsUtils_FindDistanceToTarget.md` |
| **System** | skills-abilities / physics util |
| **Verdict** | **accept-with-gaps** — product name + role sealed; full geometry partial |

---

## 1. Purpose

`CVOGPhysicsUtils::FindDistanceToTarget` — measures distance from a source/query to a target for **skill range** and related combat/UI paths. Returns `float10`: **measured distance** (or a physics residual) on success, **`g_flZero`** on hard fail. Consumed by `Skill_RangeCheckTargetForResolveList_Inferred` (band test) and `Skill_GatherTargetsInArea` (sort / range), plus weapon/UI helpers.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004e9aa0_FUN_004e9aa0.md` |
| Annotated | `docs/reconstruction/raw/aa_004e9aa0_FUN_004e9aa0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004e9aa0.cpp` |
| Function record | `docs/reconstruction/functions/aa_004e9aa0_FUN_004e9aa0.md` |
| Live decompile | Ghidra `decompile_function` / `analyze_function_complete` `0x004e9aa0` |
| Product string | `read_memory 0x009ccbc0` → `"CVOGPhysicsUtils::FindDistanceToTarget"` |
| String xref | `get_xrefs_to 0x009ccbc0` → **`004e9aca` in this function [DATA]** |
| Sibling string | `"CVOGPhysicsUtils::GetObjectsInArea::aabb"` @ `0x009ccbe8` (adjacent) |
| Callers | RangeCheck, GatherTargetsInArea, `FUN_0056c0a0`, `FUN_0056d600`, `FUN_0056db30`, `FUN_00955eb0` |
| Callee simple | `FUN_004e8930` — XZ plane `sqrt(dx²+dz²) - rA - rB` residual |
| Math leaf | `Math_AcosClamped` (`0x0040d0a0`) on complex path |
| Consumer dual | `A_aa_0058c0a0_*` (return used as distance in band) |

**Not performed:** full PhysX sweep bit-exact, Launcher, runtime golden.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Product name `CVOGPhysicsUtils::FindDistanceToTarget` | **Confirmed** | string @ `009ccbc0` DATA xref from `004e9aca` |
| Returns `float10` distance-like measure | **High** | RangeCheck band; complex path returns `fStack_524` residual |
| Fail returns `g_flZero` | **High** | terminal path |
| Requires usable physics host (`param_4 != 0` && `param_4+8 != 0`) else zero | **High** | body gate |
| Two internal paths gated by `param_7` | **High** | simple vs complex |
| Simple path calls `FUN_004e8930` (horizontal gap minus radii) | **High** | callee decompile |
| Complex path: angle sample ring (`sin`/`cos`), PhysX-style queries, optional hit residual | **High** CF / **Partial** product physics ABI |
| Decompiler simple-path return = `param_4+0x34` (radius field) | **Partial / suspicious** | may be decomp loss; consumers treat return as distance — residual |
| Arity (decomp shows 7 formals; RangeCheck shows 4 pushes) | **Partial** | stack/register framing residual |
| Not pure Euclidean always | **High** | complex path can return collision residual; zero fail |
| LOS vs clearance English | **Inferred** | complex path is obstruction-aware, not named LOS in body |

---

## 4. Control flow (sealed spine)

```
FindDistanceToTarget(...):
  profile enter (string name)
  if no physics host: return 0
  if simple flag (param_7==0):
    r = phys+0x34
    FUN_004e8930(...)          // XZ distance minus radii helper
    return (decomp: r)         // residual: may be wrong ST0
  else:
    build angular sample ring (acos / ceil density)
    PhysX / shape queries against host
    if hit in band: return clamped residual distance
    cleanup; return 0
```

### 4.1 RangeCheck consumer (sole primary-skill path)

```
dist = FindDistanceToTarget(pos, sourceRadiusish, maxRange, physHost, ...)
if minRange <= dist <= maxRange: return dist
else return 0   // outFlags bit2 at ResolveTargetList
```

---

## 5. Signature (best-effort)

```c
// Product: CVOGPhysicsUtils::FindDistanceToTarget
// Decompiler arity may over-count; RangeCheck site shows ~4 stack args.
float10 CVOGPhysicsUtils_FindDistanceToTarget(
    float *targetPosOrFrame,  // param_1
    float param_2,            // often source/body radius or offset
    float param_3,            // often max range / outer band
    void *physHost,           // param_4; needs +8 nonzero
    /* further args: direction / flags — Partial */);
```

---

## 6. Gaps / open

1. Exact full C++ prototype / all formals vs RangeCheck arity.
2. Simple-path **return value** integrity (decomp returns `+0x34`; may be wrong).
3. Complex-path product semantics (sweep vs multi-ray vs shape cast) — CF sealed, English partial.
4. Constant table (`DAT_009ccbbc`, `DAT_00aaa668`, `DAT_00aaabc0`, `0x3dcccccd=0.1f`) English.
5. Runtime / bit-exact.

**Verdict:** **accept-with-gaps** — **name + role sealed** by string xref; geometry details remain open for port polish.

---

## Checklist

| Check | Result |
|---|---|
| String xref into body | **Pass** |
| Multi skill/combat callers | **Pass** |
| Zero fail path | **Pass** |
| RangeCheck band consumer | **Pass** |
| Full geometry English | **Open** |
| Verdict | **accept-with-gaps** |
