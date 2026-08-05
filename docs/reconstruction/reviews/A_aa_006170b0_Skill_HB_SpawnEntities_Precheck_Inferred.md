# Review A (reconstruction fidelity): `aa_006170b0` Skill_HB_SpawnEntities_Precheck_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_006170b0` |
| **VA** | `0x006170b0`–`0x00617399` |
| **Canonical name** | `Skill_HB_SpawnEntities_Precheck_Inferred` |
| **Prior scaffold** | `FUN_006170b0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_006170b0_Skill_HB_SpawnEntities_Precheck_Inferred.md` |
| **System** | `skills-abilities` / HB spawn |
| **Agent** | W20-N OWN-ONLY |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Virtual **precheck** (vtbl **+0x1c**) for the HB multi-spawn skill effect class constructed by `FUN_00614dc0` (`PTR_FUN_009d0ec4`). Sibling **Execute** is vtbl **+0x2c** (`Skill_HB_SpawnEntities_Execute_Inferred` @ `0x00615020`).

Pipeline:

1. `dynamic_cast` object → `CVOGCreature` (fail → **2**).
2. If skill float `+0x16c == 100.0f` → **0** (pass).
3. If float `== 0.0f` and plant vtbl+0x210 path → compare cap `FUN_004c2e60` vs net summon count `FUN_004c3f10(0)` → fail **0x10**.
4. Histogram summon types from creature TFID vector A; if count of skill key `+0x14c` ≥ `u8 +0xda` → fail **8**.
5. Else **0**.

Maps to `Skill_FormatFailureMessage` cases 2 / 8 / 0x10.

**Not** the spawn Execute path; not FormatFailure itself.

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw | `docs/reconstruction/raw/aa_006170b0_FUN_006170b0.md` (+ v2026-07-29) |
| Annotated | `docs/reconstruction/raw/aa_006170b0_FUN_006170b0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_HB_SpawnEntities_Precheck_Inferred.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_006170b0.cpp` |
| Function record | `docs/reconstruction/functions/aa_006170b0_FUN_006170b0.md` |
| Live decompile | Ghidra `0x006170b0` (2026-07-29) — **≡ raw CF** |
| Machine | `read_memory` entry/mid/tail; `C2 08 00` epilogues; `B8 08…` / `33 C0` |
| Constants | `DAT_00aaa7ac` = 100.0f; `g_flZero` = 0.0f |
| Sibling dual | `A\|B_aa_00615020_Skill_HB_SpawnEntities_Execute_Inferred` |
| Failure table | `aa_0054fa20` FormatFailure cases 8 / 0x10 |

**Not performed:** `disassemble_bytes`, Launcher, runtime, ledgers; **no ownership** of callees.

---

## 3. Signature / layout

```c
// two stack args; ret 8
uint32_t Skill_HB_SpawnEntities_Precheck_Inferred(
    void *pObject,    // stack0
    void *pSkillDef); // stack1
```

| Skill offset | Role |
|---|---|
| `+0x22` | remap-key flag |
| `+0xda` | u8 max of specific summon type |
| `+0x14c` | u32 histogram key |
| `+0x16c` | float gate (100 skip / 0 total-cap) |

| Creature offset | Role |
|---|---|
| `+0x1bc / +0x1c0` | TFID vector A begin/end (elem 0x10) — via `FUN_004c3f10` |

---

## 4. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Precheck role (vtbl+0x1c vs Execute +0x2c) | **High** | vtbl + CF |
| ABI `ret 8`; returns 0/2/8/0x10 | **Confirmed** | bytes |
| RTTI creature gate → 2 | **Confirmed** | |
| 100.0f skip / 0.0f total-cap | **Confirmed** | float constants |
| Histogram + key threshold → 8 | **Confirmed** | CF + FormatFailure string |
| Total cap path → 0x10 | **High** | pair with `004c3f10`/`004c2e60` duals |
| Clean ≡ raw CF + sealed returns | **Confirmed** | |
| Product class English name | **Open** | `_Inferred` |
| Runtime / bit-exact | **Open** | |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Cast fail → 2 | **Yes** |
| float 100 → 0 | **Yes** |
| float 0 + cap fail → 0x10 | **Yes** |
| Build histogram map | **Yes** |
| Key thr → 8 else 0 | **Yes** |
| Map teardown both arms | **Yes** |
| Returns after delete (not noreturn) | **Yes** (bytes/clean) |

---

## 6. Gaps

- Product name of `PTR_FUN_009d0ec4` subclass.
- Exact product meaning of key at `obj[0x2a]+0x34`.
- Optional remap chain (`+0x22`) full type graph (owned callees elsewhere).
- Runtime golden vs live skill cast UI.
