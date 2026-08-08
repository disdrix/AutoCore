# Review A (reconstruction fidelity): `aa_004d2e50` CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d2e50` |
| **VA** | `0x004d2e50`–`0x004d319e` inclusive (**847 B** / `0x34F`) |
| **Canonical name** | `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` |
| **Ghidra name** | `FUN_004d2e50` |
| **Review date** | `2026-08-05` (MEGA-068 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004d2e50_CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.md` |
| **System** | interaction-activation (child of object interact aggregate) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_assembly_context` + `get_function_by_address` + `get_function_signature`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Evaluate **interact-state codes** for a **child reaction** against a **character**, focusing on **active** and **completed** mission membership carried on the child:

| Return (AL) | Meaning (inferred from CF + parent plate) |
|---|---|
| **0** | No match / empty vectors / no qualifying mission |
| **3** | At least one completed mission on child list still “live” under requirements |
| **6** | Qualifying incomplete/active mission, `mission[+0x169]==0` |
| **7** | Same path, `mission[+0x169]!=0` |

Sole consumer: dualed parent **`CVOGObject_EvalInteractStateFromChildren`** (`0x004d7640`) on child type **`0x25`**, max-aggregated with `FUN_004d3ba0` and `CVOGObject_EvalOfferableMissionInteractState` when current state `< 6`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-068 append) | `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.md` |
| Annotated | `docs/reconstruction/raw/aa_004d2e50_FUN_004d2e50.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004d2e50.cpp` |
| Function records | `docs/reconstruction/functions/aa_004d2e50_FUN_004d2e50.md` + named |
| Live | decompile ≡ raw CF; body `004d2e50–004d319e`; RET 8 ×3; 2 CALL xrefs; parent type-0x25 sites |

---

## 3. Signature (sealed)

```c
// stack child, character; RET 8; AL state code
char __stdcall CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred(
    void *child_reaction,
    void *character);
```

| Slot | Source | Conf |
|---|---|---|
| child_reaction | stack `[ESP+4]`; parent `PUSH ESI` | **High** |
| character | stack `[ESP+8]`; parent `PUSH EBP` | **High** |
| cleanup | **`RET 8`** @ `0x004d3077` / `0x004d3174` / `0x004d319c` | **High** |
| ECX | set by parent, **unused** in body | **High** |
| return AL | `0` / `3` / `6` / `7` | **High** |

**Note:** Ghidra signature display `undefined FUN_004d2e50(void)` is wrong; locals list + disassembly seal two stack params. `analyze_function_complete` warns return type undefined — AL sealed via `MOV AL,0` / `MOV AL,3` / `SETNE+ADD 6`.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| Gate child vec `[+0x244,+0x248)` | **Yes** | **High** |
| Per-id region hash via `FUN_0053fff0` | **Yes** | **High** |
| Active `short[+0xac]==-1` → CheckReq → 6/7 | **Yes** | **High** |
| HasCompleted → completed hash `@char+0x538` → flag → 3 | **Yes** | **High** |
| Else gate byte vec `[+0x234,+0x238)` | **Yes** | **High** |
| TraversalLock `@char+0x540` + filter `byte[+0x86]` | **Yes** | **High** |
| Incomplete match → unlock + `FUN_00547920` → 6/7 | **Yes** | **High** |
| Fallthrough 0 | **Yes** | **High** |
| Product English for code **3** / field names | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| External callers | `CVOGObject_EvalInteractStateFromChildren` only |
| Xrefs | 2 UNCONDITIONAL_CALL (`0x004d7823`, `0x004d7830`) |
| Site role | type-`0x25` max-aggregate under state `< 6` |
| Callees | `FUN_0053fff0`, `HasCompletedMission`, `CheckMissionRequirements`, `FUN_00547920`, `FUN_00402c40`, `FUN_007a4480` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole parent is object interact aggregate | **Yes** |
| Returns interact codes 0/3/6/7 (not void / not bool-only) | **Yes** |
| Active (`+0xac==-1`) + completed (`HasCompletedMission`) paths | **Yes** |
| Child-owned mission / filter vectors | **Yes** |
| PDB / plate product English | **No** |
| `VOG_DEBUG_STOP` is purpose | **No** (diagnostic only) |

**Decision:** promote **`CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred`**.  
**Reject:** `Named_VOG_DEBUG_STOP_*`, `Mission_VOG_DEBUG_STOP_*`, any `Named_CalleeOf_*` scaffold.

---

## 7. Gaps / open

1. Product icon English for return **3** vs **6/7**.
2. Child field names for `+0x244` / `+0x234` vectors.
3. Full semantics of `FUN_00547920` pre-return.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
