# Review A (reconstruction fidelity): `aa_00574900` ConvoyRoster_Lock_NoOp_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00574900` |
| **VA** | `0x00574900` |
| **Body span** | `0x00574900` – `0x00574900` inclusive (**1** byte; exclusive end `0x00574901`) |
| **Canonical name** | `ConvoyRoster_Lock_NoOp_Inferred` |
| **Prior / alias** | `FUN_00574900`; `Named_CalleeOf_CVOGCombat_OnDeathAwardKillXp_00574900` |
| **Review date** | `2026-07-29` (OWN-ONLY dual A/B **create** — live Ghidra) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00574900_ConvoyRoster_Lock_NoOp_Inferred.md` |
| **System** | missions-progression / kill-XP convoy |
| **Dual status** | **Present (create)** |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

**Empty enter-guard hook** before convoy kill-XP bookkeeping. Single-byte `RET` (`c3`) no-op in this retail image.

**Sole caller:** `CVOGCombat_OnDeathAwardKillXp` @ `0x004dab28`, immediately before `FUN_00574e60` (eligible-member count) and the 4-slot award loop that ends with `FUN_00574910` (`0x00574910`). Placement is a classic **lock / unlock sandwich** around roster iteration; body performs **no** work (stripped critical section, debug hook, or future guard).

Name is **Inferred** from call-graph placement (not string/RTTI). Machine fact: pure no-op.

---

## 2. Inspected artifacts

| Artifact | Path / source | This pass |
|---|---|---|
| Live decompile | `decompile_function` / `batch_decompile` `0x00574900` | empty `return` ≡ raw |
| Live bytes | `read_memory` @ `0x00574900` | **`c3`** then `cc` padding |
| Live disasm | `disassemble_function` | single `RET` |
| Body meta | `get_function_by_address` | `00574900`–`00574900` |
| Callers | `get_function_callers` / `get_xrefs_to` | **1** CALL — OnDeathAwardKillXp |
| Raw / annotated / clean | `raw/aa_00574900_*`, `reconstructed-exact/FUN_00574900.cpp` | ≡ |
| Pair unlock | `aa_00574910` | sandwich peer |
| Count helper | `aa_00574e60` | between lock and unlock |

**Not performed:** Launcher, runtime, Ghidra rename, ledgers.

---

## 3. Machine proof

```text
0x00574900:  c3    ret
0x00574901+: cc…  int3 padding (not in body)
```

**Live decompile:**

```c
void FUN_00574900(void)
{
  return;
}
```

ABI: pure `ret` (not `ret N`) — **zero** stack args; if callers pass ECX (thiscall shape), body **ignores** it.

---

## 4. Confidence table

| Claim | Confidence | Evidence |
|---|---|---|
| Body is pure `ret` (1 byte `c3`) | **High** | read_memory + disasm + decompile |
| No stores / callees / stack args | **High** | empty body |
| Exactly **1** caller | **High** | xrefs sealed |
| Call site = convoy XP arm enter | **High** | OnDeathAward decompile order: Lock → Count → loop → Unlock |
| Product “lock” English | **Tentative / Inferred** | placement only |
| Runtime | **Open** | policy |

---

## 5. Control flow / clean fidelity

| Stage | Match |
|---|---|
| Empty return only | **Yes** (clean ≡ raw ≡ live) |

Clean scaffold is behavior-correct (no-op). No modernization risk.

---

## 6. Residual disposition

| Topic | Disposition |
|---|---|
| Machine no-op | **Sealed High** |
| Single OnDeathAward caller | **Sealed High** |
| Sandwich with `00574910` / surrounds `00574e60` | **Sealed High** (static order) |
| Historical lock semantics | **Tentative** |
| Product name | **Open / Inferred** |

**Verdict:** **accept-with-gaps** — body + exclusive caller sealed; name intent open.
