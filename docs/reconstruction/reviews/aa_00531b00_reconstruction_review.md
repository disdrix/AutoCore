# Reconstruction review: `aa_00531b00` CVOGMission_AddActiveObjective

| Field | Value |
|---|---|
| **Stable ID** | `aa_00531b00` |
| **VA** | `0x00531b00` |
| **Canonical name** | `CVOGMission_AddActiveObjective` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.md` | Authoritative decompile |
| Annotated low-level | `docs/reconstruction/raw/aa_00531b00_CVOGMission_AddActiveObjective.annotated.md` | Scaffold copy |
| Exact C++ | `docs/reconstruction/reconstructed-exact/CVOGMission_AddActiveObjective.cpp` | Clean scaffold |
| Function record | `docs/reconstruction/functions/aa_00531b00_CVOGMission_AddActiveObjective.md` | Partial scaffold |
| System map | `docs/reconstruction/systems/missions-progression.md` | “Push objective active” |
| Caller | `raw/aa_005327c0_CVOGReaction_GiveMission.md` | Call site (arity tension) |

**Primary claims (clean ≡ low-level):**

1. Always call `FUN_0053c460(*(param_2+0x10), param_2, 0)` first  
2. If objective vector `[+0x158,+0x15c)` non-empty: alloc `0x14` node, store `param_2` at node[0], `FUN_0053c760`, on failure `operator_delete` (noreturn warning), virtual calls at vtable `+0x28` per vector element, then `*(param_1+0x634) |= 0x10`  
3. Void return  

**Not re-authored.** No live re-decompile.

---

## 2. Evidence used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw | Ground truth |
| Annotated | Annotated | No CF delta |
| Clean | `.cpp` | Fidelity (`undefined4` → `uint32_t` on FUN args) |
| GiveMission call | Sibling raw | Cross-check call shape |
| System map | missions-progression | Role claim |

No runtime / CE. Insert helpers not recovered.

---

## 3. Confirmed points

### 3.1 Clean ≡ raw

| Stage | Raw | Clean | Match |
|---|---|---|---|
| Leading `FUN_0053c460` | Present | Present | **Yes** |
| Vector empty check (`end-begin>>2`) | Present | Present | **Yes** |
| `operator_new(0x14)` zero-init 5 ints | Present | Present | **Yes** |
| `*piVar1 = param_2` | Present | Present | **Yes** |
| `FUN_0053c760` + delete on nonzero | Present | Present | **Yes** |
| Virtual loop vtable `+0x28` | Present | Present | **Yes** |
| Dirty flag `param_1+0x634 \|= 0x10` | Present | Present | **Yes** |
| Early return if vector empty (no dirty) | Present | Present | **Yes** |

### 3.2 Signature surface

```c
void __thiscall CVOGMission_AddActiveObjective(int param_1, int param_2)
```

Preserved in clean. Parameter roles left generic (as raw).

### 3.3 Function record honesty

Partial scaffold — consistent.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Plate “hash (+0x548)” | Doc | Body never references `+0x548`; insert likely inside `FUN_0053c460` / `FUN_0053c760`. Clean correctly does not invent that store. |
| GiveMission single-arg call vs two-param signature | Cross-unit | Faithfulness: clean keeps this unit’s two-param form; does not fix callers |
| Noreturn delete path | Residual | Warning preserved; actual control-flow after delete unknown |
| Null `operator_new` then `*piVar1 = param_2` | Hazard | Raw/clean both write through possibly null — crash-parity preserved |

**No clean CF revision required** for raw fidelity.

---

## 5. Residual uncertainty

1. Who is `param_1` (character?) vs `param_2` (objective def?).  
2. What `FUN_0053c460` / `FUN_0053c760` insert into.  
3. Vector at `+0x158/+0x15c` element type and vtable `+0x28` method.  
4. Dirty bit `0x10` at `+0x634` consumers.  
5. Call convention mismatch with GiveMission.  
6. No runtime.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:** Clean reproduces the decompiled activation sequence, vector walk, dirty flag, and helper calls without modernization.

**Gaps:** Helper semantics, parameter roles, plate hash claim not in body, caller arity tension.

**Not needs-revision:** Clean ≡ raw for this unit’s filed body.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Dirty flag `+0x634\|=0x10` | **Pass** |
| No invented +0x548 store | **Pass** |
| Helpers sealed | **Open** |
| Verdict | **accept-with-gaps** |
