# Review A (reconstruction fidelity): `aa_0054a640` SkillElementFactory_RegisterCatalog

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054a640` |
| **VA** | `0x0054a640`–`0x0054b2bf` |
| **Canonical name** | `SkillElementFactory_RegisterCatalog` (INFERRED; Ghidra `FUN_0054a640`) |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (skill element type catalog) |
| **Counterpart** | `reviews/B_aa_0054a640_SkillElementFactory_RegisterCatalog_Inferred.md` |
| **System** | `skills-abilities` |
| **Parent chain** | `ResolveSkillTargets` → `SkillDefMap_EnsureInitialized` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**One-shot registration of skill-element type factories** into a type→instance map (insert helper **`FUN_0054eb20`**).

Sole caller: `SkillDefMap_EnsureInitialized` (`0x0054b2c0`), after aux-map clear (`FUN_0054a1a0`).

Pattern (repeated ~0x00..0x22+):

```
obj = operator_new(0x6c0 | 0x6d0 | 0x6e0 | 0x6f0)
if obj:
    base_ctor = FUN_00618100() or FUN_00578830() or FUN_0054f250()
    *obj = &PTR_FUN_00xxxxxx   // distinct vtable per type id
key = typeId (0,1,2,...)
FUN_0054eb20(local_pair, {key, obj})
```

SEH scope ids advance per registration (`local_c = 0,1,2,...`). Alloc sizes cluster **`0x6c0` / `0x6d0` / `0x6e0` / `0x6f0`**. Base ctors alternate **`FUN_00618100`** vs **`FUN_00578830`** (and one **`FUN_0054f250`**).

**Not** cast execution — pure catalog bootstrap so later skill-element materialization can vtable-dispatch by type id.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw / annotated / clean | `raw/aa_0054a640_*`, `reconstructed-exact/FUN_0054a640.cpp` |
| Function record | `functions/aa_0054a640_FUN_0054a640.md` |
| Live Ghidra | `batch_decompile` (truncated body long), `get_function_by_address` body `0054a640–0054b2bf` |
| Parent dual | `A_aa_0054b2c0_SkillDefMap_EnsureInitialized` — “sub-init `0054a640`” |
| Insert helper | `FUN_0054eb20` (map insert pair) |

---

## 3. Signature (sealed)

```c
void SkillElementFactory_RegisterCatalog(void);  // no args; SEH frame; ret after locals
```

---

## 4. Control flow (sealed pattern)

```
SEH setup
for typeId in 0 .. N:   // sequential integer keys
    p = operator_new(size_for_type)
    if p == null: instance = null
    else:
        base_ctor(p)           // 618100 / 578830 / 54f250
        *p = vtable_for_type   // PTR_FUN_009d**** family
    pair = { typeId, instance }
    FUN_0054eb20(tmp, &pair)
restore ExceptionList; return
```

Exact `N` and each vtable→product element name: **open** (body is long mechanical unrolling; CF pattern High).

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| EnsureInitialized-only caller | **Confirmed** | callers |
| Integer type-id keys 0,1,2,… | **Confirmed** | sequential `local_28 = id` |
| Per-type vtable stamp after base ctor | **Confirmed** | `*puVar1 = &PTR_FUN_...` |
| Insert via `FUN_0054eb20` | **Confirmed** | every arm |
| Alloc size classes 0x6c0–0x6f0 | **Confirmed** | decompile |
| Product element class names | **Open** | vtables not named here |
| Count of types | **Medium** | long function; count from full listing residual |

---

## 6. Gaps

1. Map each `PTR_FUN_009d****` → product skill-element class name.
2. Dual of `FUN_0054eb20` insert helper.
3. Why two base ctors (`618100` vs `578830`).
4. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps**
