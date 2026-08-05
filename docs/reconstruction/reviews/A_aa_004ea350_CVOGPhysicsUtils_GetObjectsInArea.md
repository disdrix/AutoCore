# Review A (reconstruction fidelity): `aa_004ea350` CVOGPhysicsUtils_GetObjectsInArea

| Field | Value |
|---|---|
| **Stable ID** | `aa_004ea350` |
| **VA** | `0x004ea350` |
| **Canonical name** | `CVOGPhysicsUtils_GetObjectsInArea` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity |
| **Counterpart** | `reviews/B_aa_004ea350_CVOGPhysicsUtils_GetObjectsInArea.md` |
| **System** | skills-abilities / physics util / AI targeting |
| **Verdict** | **accept-with-gaps** — product name + multi-mode broadphase sealed |

---

## 1. Purpose

`CVOGPhysicsUtils::GetObjectsInArea` — spatial **broadphase query** that collects nearby game objects into an intrusive result list. Used by `Skill_GatherTargetsInArea`, `CVOGHBAIBase_FindTargetToAttack`, and combat helpers. Modes branch on an integer path selector; default path is an **AABB** query (profiler string). Query **filter flags** (last arg from gather) gate which physics objects pass.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_004ea350_FUN_004ea350.md` |
| Annotated | `docs/reconstruction/raw/aa_004ea350_FUN_004ea350.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_004ea350.cpp` |
| Function record | `docs/reconstruction/functions/aa_004ea350_FUN_004ea350.md` |
| Live decompile | Ghidra `batch_decompile` `0x004ea350` |
| Product string | `"CVOGPhysicsUtils::GetObjectsInArea::aabb"` @ `0x009ccbe8` |
| String xref | `get_xrefs_to` / bulk → **`004ea38f` DATA** (default AABB path profile enter) |
| Callers | GatherTargetsInArea; `CVOGHBAIBase_FindTargetToAttack`; `FUN_00556450`; `FUN_0056d600`; `FUN_0056db30`; `FUN_00638cd0`; `FUN_004b9300` |
| Gather residual | `reviews/a_0058d330.md` query flag ladder (1 / 0x11 / 10) |
| AI consumer | `CVOGHBAIBase_FindTargetToAttack` dual (radius from profile) |

**Not performed:** full mode-1/mode-2 product English beyond CF; runtime golden.

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Product family `CVOGPhysicsUtils::GetObjectsInArea` | **Confirmed** | AABB path string + xref into body |
| Default path is AABB around center±radius | **High** | builds min/max from `param_2` ± `param_3`; string `::aabb` |
| `param_2` = center float4-ish; `param_3` = extent/radius | **High** | body |
| Mode `param_5 == 1` special path (box/list via `FUN_00581220` / `FUN_0055ff20`) | **High** CF | English name open |
| Mode `param_5 == 2` sphere-ish path (`FUN_006c7fa0(param_3)` + `FUN_005ebec0`) | **High** CF | English open |
| Else → default AABB + profile string | **High** | |
| Last arg (`param_6`) used as query filter to `FUN_006c6c50` | **High** | gather flags 1 / 0x11 / 0x0a |
| Result is linked list of object handles (intrusive, `FUN_0058d9c0` sentinel) | **High** | |
| Decompiler shows `operator_delete` non-return on list teardown | **Partial** | SEH / unwind noise — result still produced for callers before free paths |
| Debug fail when AABB world null: `VOG_DEBUG_STOP` | **High** | string in body |
| Not the pair filter (that is `0x0058a810`) | **High** | |

---

## 4. Control flow

```
GetObjectsInArea(worldOrCtx, center, radius, queryCtx, mode, filterFlags):
  if mode==1:  // alternate broadphase A
    expand AABB from center±radius
    query via FUN_00581220 path; collect into list; dedupe type-10
  elif mode==2: // alternate broadphase B (sphere-ish)
    FUN_006c7fa0(radius); shape query; collect
  else:        // default AABB
    profile "CVOGPhysicsUtils::GetObjectsInArea::aabb"
    expand AABB center±radius
    vtbl query on world+0xe4a4 ...
    if world list dead: VOG_DEBUG_STOP; return 0
    for each hit: filter via FUN_006c6c50(..., filterFlags); resolve object; append
  return list head / status
```

### 4.1 GatherTargets query flags (consumer CF — High)

| gatherMode | flags passed (last arg) |
|---:|---:|
| default | `1` |
| 1 or 2 | `0x11` |
| 7 | `10` (`0x0a`) |

---

## 5. Signature (decompiler-derived)

```c
// Product: CVOGPhysicsUtils::GetObjectsInArea
undefined4 CVOGPhysicsUtils_GetObjectsInArea(
    int worldOrMap,          // param_1; default path uses +0xe4a4
    float *center,           // param_2 [x,y,z,w]
    float radiusOrExtent,    // param_3
    undefined4 queryCtx,     // param_4
    int mode,                // param_5: 1 / 2 / else AABB
    undefined4 filterFlags); // param_6
```

---

## 6. Gaps / open

1. English names for mode 1 / mode 2 (sphere vs OBB vs alternate world).
2. Exact return object (list pointer vs status) at all exits — decomp messy on delete paths.
3. Full filter bit meanings in `FUN_006c6c50`.
4. Runtime / bit-exact.
5. Whether `param_1` is always sector map vs physics scene.

**Verdict:** **accept-with-gaps** — **name + AABB default + multi-mode broadphase role sealed**.

---

## Checklist

| Check | Result |
|---|---|
| String xref `::aabb` | **Pass** |
| Mode 1/2/else CF | **Pass** |
| Gather/AI callers | **Pass** |
| Center±radius AABB | **Pass** |
| Mode English complete | **Open** |
| Verdict | **accept-with-gaps** |
