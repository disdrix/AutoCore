# Review A (reconstruction fidelity): `aa_0056bab0` WeaponFx_OnHitApplyOrStage_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056bab0` |
| **VA** | `0x0056bab0` |
| **Canonical name (Ghidra)** | `FUN_0056bab0` |
| **Proposed name** | `WeaponFx_OnHitApplyOrStage_Inferred` (**High** role; product name absent) |
| **Prior scaffold alias** | (weapon FX event — wave15 residual) |
| **Review date** | `2026-07-29` (OWN-ONLY dual A — live Ghidra) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live decompile) |
| **Counterpart** | `reviews/B_aa_0056bab0_WeaponFx_OnHitApplyOrStage_Inferred.md` |
| **System** | `combat` / weapon FX hit → multi-target or stage |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Weapon/FX hit event:** play/select FX entries via catalog helpers, then either **stage a single multi-hit entry** or **directly call multi-target apply**.

Primary live caller of multi-target path when FX session flag at staged entry `+0xc` is clear; when set, uses `NDSpecialFX_StageTargetEntries_Inferred` (`004b67d0`) instead (matches stage dual notes).

### Control flow (summary)

1. Optional early FX play: if `param_5 != 0` and FX master present (`+0xac` path / `FUN_004eb3b0` / `+0x88`): pick catalog id `0x15` else `0x14` via `FUN_004ec010`, play `FUN_0056a9e0`.
2. Branch on `param_5`:
   * **0:** softer path — catalog `0xc` optional; remap target id when differs from host `+0xb0`.
   * **nonzero:** require FX master; catalog `0xe` optional play; pick catalog `0x6` if target type `==0xe` else `0x5`; play via `0056a9e0`.
3. If `param_2 != param_3` (distinct objects — attacker vs target **Probable**):
   * Resolve target root: use `param_2+0xac` if non-null else `param_2`.
   * If selected FX node `+0xc != 0`: `FUN_004b67d0(param_4, 1, root+0x160)` — **stage** single TFID at identity transform.
   * Else: `FUN_004da2e0(param_4, 1, root, 1, 1, 0, DAT_009d2f68..74, 0)` — **apply** multi-hit immediately (count=1). Masks read as `0xFFFFFFFF` pairs (**High** `read_memory` @ `009d2f68`).

**Not** the apply primitive itself (`004d78e0`), not deferred queue, not kill XP.

---

## 2. Inspected artifacts

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `batch_decompile` @ `0x0056bab0` |
| Callers | `get_function_callers` → `00812a60` only |
| Multi-hit dual | `A_aa_004da2e0_*` |
| Stage dual | `A_aa_004b67d0_*` |
| Constants | `read_memory` `DAT_009d2f68` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact` for `aa_0056bab0` |
| Function record | `docs/reconstruction/functions/aa_0056bab0_FUN_0056bab0.md` |

**This pass:** live decompile; callers; dual cross-check; constant. **Not performed:** Launcher, runtime, bit-exact, ledgers.

---

## 3. Signature

```c
// thiscall — ECX = weapon/FX host object
void __thiscall WeaponFx_OnHitApplyOrStage_Inferred(
    void *weapon_fx,     // this
    uint obj_a,          // param_2 — often attacker-side object*
    uint obj_b,          // param_3 — often target-side object*
    undefined4 hit_pack, // param_4 — host/entries arg to stage or multi-hit
    int mode);           // param_5 — selects FX catalog branch
```

---

## 4. Callers / callees

| Callee | Role |
|---|---|
| `FUN_004eb3b0` | Ensure FX master from def |
| `FUN_004ec010` | Catalog lookup by type id |
| `FUN_0056a9e0` | Play/bind FX entry |
| `FUN_004b67d0` | Stage multi-hit entry (flag `+0xc`) |
| `FUN_004da2e0` | Direct multi-target apply |

| Caller | Role |
|---|---|
| `0x00812a60` | Weapon/net FX event dispatch (**Probable**) |

---

## 5. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Optional catalog FX plays | Yes |
| Mode branch on `param_5` | Yes |
| Stage vs multi-hit on `fx+0xc` | Yes |
| Count=1 single-root apply | Yes |

---

## 6. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Weapon FX hit → stage or multi-hit | **High** | callees sealed |
| `fx+0xc` selects stage vs apply | **High** | body |
| Catalog ids 0x5/6/0xc/0xe/0x14/0x15 | **High** CF | product names open |
| `param_2`/`param_3` attacker/target | **Probable** | inequality gate |
| Product function name | **Tentative** | `_Inferred` |

---

## 7. Gaps / open

1. Retail weapon class / packet that calls `00812a60`.
2. Full semantics of catalog type ids.
3. Siblings `0056c860` / `0056e000` still undualed (related residual).
4. Runtime / bit-exact not run.

**Verdict:** **accept-with-gaps** — stage/apply CF High; catalog product names open.
