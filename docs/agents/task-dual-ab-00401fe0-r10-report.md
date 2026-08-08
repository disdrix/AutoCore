# Dual A/B report — R10-004 OWN-ONLY (`0x00401fe0`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-004**  
**Scope:** VA `0x00401fe0` (`aa_00401fe0`) only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs/callees. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-05_r10_residual_partition_map.md` → **R10-004**.  
**Work item:** Residual dual seal — Mission null-dialog nested; structural isnil2D tree **node construct** (string+byte).  
**Hint retired:** `Named_CalleeOf_*Nam_00401fe0` chain plate.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00401fe0` StdTree_NodeCtor_StringByte_Isnil2D_Inferred | **accept-with-gaps** — hybrid ABI RET0xC / links+string+byte / color@+0x2c / isnil0@+0x2d / sole buynode caller sealed; product demangle open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): mission-product / Val24-isnil29-merge / BuyHead-merge / thiscall-ECX-node / pure-fastcall-complete / alloc-inside / set-without-byte claims **falsified**; chain-of-caller scaffold **retired**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00401fe0` — sealed facts

1. **Body:** `0x00401fe0`–`0x0040203a` exclusive (**90 B** / `0x5A`); terminal **`C2 0C 00`**; pad `CC` before `FUN_00402040` @ `0x00402040`.
2. **ABI:** hybrid **`__usercall`** — **ECX=parent**, **EDX=right**, **EDI=value***, stack **node / left / color**; **RET 0xC**; EAX = node*. **Not** pure thiscall / pure fastcall.
3. **Semantics:** MSVC-style **tree node construct** (no allocation):
   - SEH frame (`LAB_009bc7ed`).
   - Links: left@+0, parent@+4, right@+8.
   - Value: `FUN_00402040` at **node+0x0c** — `basic_string` + mapped **byte** @+0x28 (EDI source).
   - color@**+0x2c** from stack arg; isnil hard **0** @**+0x2d**.
4. **Caller (1):** dualed buynode `FUN_00401f40` @ `0x00401f94` after `operator_new(0x30)`.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Callees:** `FUN_00402040` `BasicStringFlag_CopyCtor_EdiSrc_Inferred` (dualed MEGA-080).
7. **Family:** dualed isnil2D Lrot `0044e010`, Rrot `0042a840`, Buynode StringByte `00401f40`, BuyHead `00409780`, ConstructEmpty `00406190`. Contrast Val24 isnil29 NodeCtor `00409880`/`004098d0` — **do not merge**.
8. **Name:** `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` (Ghidra `FUN_00401fe0`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw CF**; RET 0xC + hybrid ABI sealed via `disassemble_function` + `read_memory` (decompiler arity/CC incomplete, not CF conflict).
10. **Partition parent** `0x00401d30` is wave score parent (StringFlag construct twin context); **live structural caller** is `0x00401f40`.

### Gaps

- Product / MSVC demangle for host map (`string→byte`-shaped) under null-dialog chain.  
- Insert `FUN_00401db0` / insert-or-find `FUN_00401c50` undualed (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.md` |
| Annotated | `docs/reconstruction/raw/aa_00401fe0_FUN_00401fe0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_NodeCtor_StringByte_Isnil2D_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00401fe0.cpp` |
| Retired scaffold | `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Named_CalleeOf_Nam_00401fe0.cpp` |
| Function | `docs/reconstruction/functions/aa_00401fe0_FUN_00401fe0.md` |
| Function named | `docs/reconstruction/functions/aa_00401fe0_StdTree_NodeCtor_StringByte_Isnil2D_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_00980160  [caller of insert-or-find; residual]
  └─ FUN_00401c50  string-key insert-or-find (isnil@+0x2d)
       └─ FUN_00401db0  insert + rebalance  ["map/set<T> too long"]
            └─ FUN_00401f40  StdTree_Buynode_StringByte_Isnil2D_Inferred  [dualed MEGA-079]
                  ├─ operator_new(0x30)
                  └─ FUN_00401fe0  StdTree_NodeCtor_StringByte_Isnil2D_Inferred  [OWN R10-004]
                        └─ FUN_00402040  BasicStringFlag_CopyCtor_EdiSrc_Inferred  [dualed MEGA-080]

StdTree_BuyHeadNode_Isnil2D_Inferred (0x00409780)  [dualed]
  └─ head shell only — do not merge

StdTree_NodeCtor_Val24_Isnil29_* (0x00409880 / 0x004098d0)  [dualed]
  └─ different value shape / isnil offset — do not merge
```

Partition host "missions-progression" names the **host chain**, not this leaf's product role.

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00401fe0-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00401fe0` | Port as **`_Tree` node construct** for isnil@**+0x2d** nodes (size **0x30**, **string+byte** @+0x0c/+0x28). Hybrid: ECX parent, EDX right, EDI value*, stack node/left/color, **RET 0xC**. No alloc. |
| Distinct from | Val24 isnil29 NodeCtor `00409880`/`004098d0`; BuyHead `00409780` (no value). |
| Pair with | dualed buynode `00401f40`; dualed value `00402040`; residual insert `00401db0`; residual insert-or-find `00401c50`; dualed isnil2D rotates `0044e010`/`0042a840`. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md` / `NAMING_REGISTRY.md` / coverage ledgers — **not touched** by this agent.
- Name to register: `StdTree_NodeCtor_StringByte_Isnil2D_Inferred` @ `0x00401fe0` / `aa_00401fe0`.
- Verdict: **accept-with-gaps**; Terminal **false**.

---

## Process

- OWN VA only (`0x00401fe0`); no Launcher; no parent ledger edits.
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + callee decompile. **No** `disassemble_bytes`.
- Dual A (fidelity) + B (adversarial) both filed.
- Scaffold raw body preserved; re-verify **appended** only.
- Clean source uses meaningful name; machine ABI corrections (hybrid RET 0xC; EDI value; isnil hard 0).
- Odd behavior preserved: isnil forced 0 regardless of color; no allocation; value byte is 1-wide.
- `_Inferred` where English unproven. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
