# Review A (reconstruction fidelity): `aa_004d3ba0` CVOGObject_EvalChildDeliverObjectiveInteract_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004d3ba0` |
| **VA** | `0x004d3ba0`–`0x004d3ee2` inclusive (**835 B** / `0x343`) |
| **Canonical name** | `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` |
| **Ghidra name** | `FUN_004d3ba0` |
| **Prior scaffold** | `Named_VOG_DEBUG_STOP_004d3ba0` (**retired**) |
| **Review date** | `2026-08-05` (MEGA-069 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md` |
| **System** | interaction-activation (child of object interact aggregate) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Evaluate **deliver/use interact-state codes** for a **type-`0x25` child reaction** against a **character**, by resolving the child's target pair, requiring NPC object type **0x12**, then scanning the character's world-object hash for continent/region-matched objects and scoring their action requirements:

| Return (AL) | Meaning (inferred from CF + parent plate) |
|---|---|
| **0** | Empty child vector / resolve fail / non-0x12 / no match |
| **4** | Matching action present but `action+0x138 == 0` |
| **5** | Matching action; type-3 deliver continent or predicate fails |
| **8** | Matching action; all requirements pass (or empty req vector) |

Sole consumer: dualed parent **`CVOGObject_EvalInteractStateFromChildren`** (`0x004d7640`) on child type **`0x25`**, max-aggregated with sibling `CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred` (`0x004d2e50`) and peer `CVOGObject_EvalOfferableMissionInteractState` (`0x004d5aa0`) when current state `< 6`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ MEGA-069 append) | `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004d3ba0.cpp` |
| Function records | `docs/reconstruction/functions/aa_004d3ba0_FUN_004d3ba0.md` + named |
| Live | decompile ≡ raw CF; body `004d3ba0–004d3ee2`; RET 8 ×2; 2 CALL xrefs; parent type-0x25 sites |

---

## 3. Signature (sealed)

```c
// ECX=host; stack child, character; RET 8; AL state code
char __thiscall CVOGObject_EvalChildDeliverObjectiveInteract_Inferred(
    void *this_host,
    void *child_reaction,
    void *character);
```

| Slot | Source | Conf |
|---|---|---|
| this_host | **ECX** → ESI; `this+0xe4e8` → ResolveObjectTarget | **High** |
| child_reaction | stack `[ESP+4]`; parent `PUSH ESI` | **High** |
| character | stack `[ESP+8]`; parent `PUSH EBP` | **High** |
| cleanup | **`RET 8`** @ `0x004d3c71` / `0x004d3ee0` | **High** |
| return AL | `0` / `4` / `5` / `8` | **High** |

**Note:** Ghidra signature display `undefined FUN_004d3ba0(void)` / decompiler `uint (int,int)` both wrong. `analyze_function_complete` warns return type undefined — AL sealed via `XOR AL,AL` early and `MOV AL,[ESP+0x0f]` epilog.

**Contrast sibling `004d2e50`:** parent also does `MOV ECX,EDI` before that CALL, but sibling body never uses ECX. **This** body uses ECX → true thiscall.

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| SEH + best=0 | **Yes** | **High** |
| Child pair-vec gate `[+0x1d8,+0x1dc)` size>>3 | **Yes** | **High** |
| ResolveObjectTarget(this+0xe4e8, pair) | **Yes** | **High** |
| Vcall +0x124 fill list; type 0x12 gate | **Yes** | **High** |
| TraversalLock `@char+0x540` | **Yes** | **High** |
| Bucket lookup `@char+0x530`; continent/region filters | **Yes** | **High** |
| Action last-slot `@obj+0x13c`; score 4 / 5 / 8 | **Yes** | **High** |
| Type-3 req continent vs NPC MI+0x34 | **Yes** | **High** |
| CNDHash_LookupByKey + vcall +0xc predicate | **Yes** | **High** |
| Epilog MOV AL,best; RET 8 | **Yes** | **High** |
| Product English for 4/5/8 icons | open | **Inferred** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | **worker** |
| External callers | `CVOGObject_EvalInteractStateFromChildren` only |
| Xrefs | 2 UNCONDITIONAL_CALL (`0x004d7806`, `0x004d7813`) |
| Site role | type-`0x25` max-aggregate (always first among 0x25 helpers) |
| Callees | `FUN_0040fb90`, `FUN_004e0eb0`, `CVOGReaction_ResolveObjectTarget`, `FUN_007a4480`, `CNDHash_LookupByKey`, `FUN_00403430`, `operator_delete`, vcalls `+0x124/+0x50/+0xc` |

---

## 6. Naming gate

| Evidence | Present? |
|---|---|
| Sole parent is object interact aggregate | **Yes** |
| Type-0x25 deliver/use branch (parent plate) | **Yes** |
| Returns interact codes 0/4/5/8 (not void / not bool-only) | **Yes** |
| Type-3 requirement + deliver-style continent match | **Yes** |
| World-object hash scan (not child mission-id vec) | **Yes** |
| PDB / plate product English | **No** |
| `VOG_DEBUG_STOP` is purpose | **No** (diagnostic only) |

**Decision:** promote **`CVOGObject_EvalChildDeliverObjectiveInteract_Inferred`**.  
**Reject:** `Named_VOG_DEBUG_STOP_*`, any `Named_CalleeOf_*` scaffold, merge with `004d2e50` / `004d5aa0` / `004d3ef0`.

---

## 7. Gaps / open

1. Product icon English for return **4** vs **5** vs **8**.
2. Exact class of `this_host` (`+0xe4e8` owner).
3. Child pair-vector / action / requirement field English.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
