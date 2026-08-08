# Dual A/B report — MEGA-069 OWN-ONLY (`0x004d3ba0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-069**  
**Scope:** VA `0x004d3ba0` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/callees/xrefs + `get_assembly_context` + `analyze_control_flow`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual partition — child of dualed **`CVOGObject_EvalInteractStateFromChildren`** (`0x004d7640`): child deliver/use objective interact eval (type `0x25` sibling of MEGA-068).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004d3ba0` CVOGObject_EvalChildDeliverObjectiveInteract_Inferred | **accept-with-gaps** — CF/ABI/RET8/thiscall-ECX-live/return-set/sole-parent type-0x25 sealed; product English for codes 4/5/8 + host class open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP-name / dead-ECX-stdcall-like-sibling / RET4 / bool-only / merge-with-004d2e50-004d5aa0-004d3ef0 / multi-caller / decompiler-return-mask / state-mutating claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004d3ba0` — sealed facts

1. **Body:** `0x004d3ba0`–`0x004d3ee2` inclusive (**835 B** / `0x343`); pad `CC` then `FUN_004d3ef0`.
2. **ABI:** **`__thiscall`** — **ECX live** (`MOV ESI,ECX` → `this+0xe4e8`); two stack args (child, character); **`RET 8`** (`C2 08 00`) ×2 exits (`0x004d3c71`, `0x004d3ee0`).
3. **Semantics:** child deliver/use objective interact eval:
   - Non-empty child pair-vec `@+0x1d8` (elem size 8) → `CVOGReaction_ResolveObjectTarget(this+0xe4e8, pair)`.
   - Vcall `+0x124` fills list; require object type **0x12**.
   - TraversalLock walk `character+0x540`; bucket match `character+0x530`.
   - Continent (`+0x20`/`+0x88` vs NPC MI `+0x34`) + region (`+0x24`/`+0xfc` vs `char[+0xa4]+0xfc`).
   - Last action on object; score **4** (`+0x138==0`), **5** (type-3 continent or pred fail), **8** (all reqs pass).
4. **Returns:** AL ∈ {**0**, **4**, **5**, **8**}; epilog `MOV AL,[best]; RET 8` (decompiler `return uVar7 & 0xffffff00` **false**).
5. **Callees:** `FUN_0040fb90`, `FUN_004e0eb0`, `CVOGReaction_ResolveObjectTarget` (`0x004bae70`), `FUN_007a4480`, `CNDHash_LookupByKey` (`0x005b0920`), `FUN_00403430`, `operator_delete` (`0x00489822`), vcalls `+0x124/+0x50/+0xc`.
6. **Callers:** **1** — `CVOGObject_EvalInteractStateFromChildren` @ `0x004d7640`; **2** UNCONDITIONAL_CALL xrefs @ `0x004d7806`, `0x004d7813` (type-`0x25` branch).
7. **Strings:** TraversalLock / TraverseToNext / `VOG_DEBUG_STOP` — diagnostics only (retired string-seed names).
8. **Name:** `CVOGObject_EvalChildDeliverObjectiveInteract_Inferred` (Ghidra `FUN_004d3ba0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; ABI/return sealed via `disassemble_function` + `read_memory` + parent assembly context.
10. **Classification:** worker; 237 insn; 61 BB; cyclomatic 47.

### Gaps

- Product English for return codes **4** / **5** / **8**.  
- Exact class of `this_host` (`+0xe4e8` owner).  
- Child pair-vector / action / requirement field English.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.md` |
| Annotated | `docs/reconstruction/raw/aa_004d3ba0_FUN_004d3ba0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004d3ba0.cpp` |
| Function | `docs/reconstruction/functions/aa_004d3ba0_FUN_004d3ba0.md` |
| Function named | `docs/reconstruction/functions/aa_004d3ba0_CVOGObject_EvalChildDeliverObjectiveInteract_Inferred.md` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004d3ba0.cpp` |

---

## Chain context (not dualled; evidence only)

```text
CVOGObject_EvalInteractStateFromChildren  0x004d7640  [parent dualed earlier; not OWN here]
  ├─ type 0x1e GiveMission → states 6/7
  ├─ type 0x1f active objective → state 4
  └─ type 0x25:
        ├─ FUN_004d3ba0  CVOGObject_EvalChildDeliverObjectiveInteract_Inferred  [OWN MEGA-069]
        ├─ FUN_004d2e50  CVOGObject_EvalChildActiveCompleteMissionInteract_Inferred  [dualed MEGA-068]
        └─ CVOGObject_EvalOfferableMissionInteractState  0x004d5aa0  [peer]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004d3ba0-mega-069-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004d3ba0` | Port as **child deliver/use objective interact-state helper**. **`__thiscall` RET 8**; args `(this_host, child_reaction*, character*)`. **ECX is live** (`+0xe4e8` reaction mgr) — do **not** treat as dead-ECX stdcall like sibling `004d2e50`. Returns **0/4/5/8** only. Do **not** name after `VOG_DEBUG_STOP`. |
| Pair with | Parent `CVOGObject_EvalInteractStateFromChildren` `004d7640`; sibling active/complete `004d2e50`; peer offerable `004d5aa0`; `CVOGReaction_ResolveObjectTarget` `004bae70`. |
| UI | Aggregate max with parent priority table; this helper is first of three on type-0x25 children (before 004d2e50 / 004d5aa0 gated at state `< 6`). |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` interaction-activation residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004d3ba0`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + control-flow metrics. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful `_Inferred` name; retired `Named_VOG_DEBUG_STOP_*` scaffold.  
- Odd behavior preserved: decompiler return-mask false; ECX live unlike sibling; empty-vector double-check after non-empty gate; type-3 deliver continent filter; hash lock diagnostics.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
