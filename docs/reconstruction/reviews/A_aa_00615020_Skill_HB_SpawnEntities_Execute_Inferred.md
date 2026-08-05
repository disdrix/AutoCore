# Review A (reconstruction fidelity): `aa_00615020` Skill_HB_SpawnEntities_Execute_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00615020` |
| **VA** | `0x00615020` |
| **Canonical name** | `FUN_00615020` |
| **Inferred name** | `Skill_HB_SpawnEntities_Execute_Inferred` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_00615020_Skill_HB_SpawnEntities_Execute_Inferred.md` |
| **System** | skills / HB spawn |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Execute multi-entity **spawn skill effect**: place creature or template instances around the caster (or mount) with terrain height, orientation modes, arm a `0x6d0` skill HB per spawn (`Enqueue` + `Start`), and optionally cull surplus matches. Bound as **vtbl+0x2c** on subclass constructed by `FUN_00614dc0` (`PTR_FUN_009d0ec4`).

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra MCP `decompile_function` @ `0x00615020` |
| Entry / epilogue bytes | `read_memory` @ `0x00615020` (128) + `@ 0x00615e40` |
| Function meta | body `00615020`–`00615e59`; analyze_function_complete |
| HB subclass ctor | `decompile_function` @ `0x00614dc0` |
| Float constants | `read_memory` on `009cc4a8`, `00a110d8`, `00a0f524`, `00aaa668`, `00aaaaa0`, `00aaa7ac`, `009e1cb4` |
| Vtbl slot | `read_memory` @ `0x009d0ee0` → `0x00615020` at `009d0ef0` |
| Raw / annotated / clean | `aa_00615020` three-rep + `Skill_HB_SpawnEntities_Execute_Inferred.cpp` |
| Function record | `docs/reconstruction/functions/aa_00615020_FUN_00615020.md` |

---

## 3. ABI (sealed)

```c
int __thiscall FUN_00615020(
    void *this,           // ECX
    int *pCaster,         // CVOGClonedObjectBase* → RTTI CVOGCreature
    int pSkillDef,
    int pMapWorld,        // +0x7e gate; +0xe4ec HB list
    undefined4 a4, undefined4 a5, undefined4 a6);
// epilogue: ret 0x18
```

Returns: **1** gate fail; **0** invalid creature/template; else **spawn success count**.

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body range / large SEH worker | **High** | meta + epilogue |
| `__thiscall` + 6 stack args | **High** | ECX save; `c2 18 00` |
| Gate `map+0x7e` + creature RTTI | **High** | decompile open |
| Pose from mount `+0x250` else self | **High** | dual branch |
| Spawn count `skill+0xde` (min 1) | **High** | |
| Offset mode `skill+0x160` 0 vs directed | **High** | |
| Terrain cast + **50.0** Y bias | **High** | mem `00a0f524` |
| Disk random × **10.0** via `1/32768` | **High** | mem constants |
| Orient modes 1/2/3 from `skill+0x168` | **High** | int cast of float |
| Creature vs template via `skill+0x22` | **High** | strings on both fails |
| HB `new(0x6d0)` + `FUN_00614dc0` + Enqueue/Start | **High** | same list slot pattern as other skills |
| Cull when `skill+0x16c == 100.0` | **High** | mem `00aaa7ac` |
| Vtbl+0x2c of `00614dc0` subclass | **High** | |
| Product English class name | **Tentative** | `_Inferred` |
| Template branch typed cleanly | **Tentative** | decompiler reuses locals |

---

## 5. Control flow: clean plate ≡ raw stages

| Stage | Match |
|---|---|
| RTTI + map gate → return 1 | **Yes** |
| Pose snapshot | **Yes** |
| RNG table + count loop | **Yes** |
| Offset / terrain / orient | **Yes** |
| Creature vs template | **Yes** |
| HB construct + Enqueue/Start | **Yes** |
| Optional cull | **Yes** |
| delete[] RNG; return count | **Yes** |

Clean `Skill_HB_SpawnEntities_Execute_Inferred.cpp` is a **stage plate** (not full 450-line expansion); full CF remains in raw + `FUN_00615020.cpp` scaffold.

---

## 6. Call graph (this unit)

**Callees:** see function record (RNG, math, terrain, spawn factories, HB list, resolve TFID, error log).

**Callers:** virtual dispatch only (DATA xref at `0x009d0ef0`).

---

## 7. Gaps / residual

1. Product name of `PTR_FUN_009d0ec4` class.
2. Precise contract of virtual at `this+0x1c` (gate).
3. Full enum of `skill+0x16c` special values.
4. Retype template branch without `local_12c` pollution.
5. Runtime / bit-exact open.

**Verdict:** **accept-with-gaps** — ABI, gates, spawn pipeline, constants, and HB arming sealed; product naming + polluted template locals residual.
