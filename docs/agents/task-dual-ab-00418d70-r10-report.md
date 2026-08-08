# Dual A/B report — R10-025 OWN-ONLY (`0x00418d70`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **R10-025**  
**Scope:** VA `0x00418d70` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `force_decompile` + `analyze_function_complete` + `get_function_callers` + `get_function_xrefs` + `read_memory` (body + parent site). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** Residual dual wave R10 — partition row R10-025 / skills-abilities residual under dualed parent `0x005755b0` (VehicleCrew_InsertMember_Inferred).  
**Inventory name:** `FUN_00418d70` → sealed as **`StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred`**.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00418d70` StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred | **accept-with-gaps** — CF/ABI/thiscall-ECX/stack-val/stride-8/fast-POD-copy/slow-grow/callers sealed; product element English + grow dual + orphans + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG misname / crew-only / wrong ABI-stride / always-realloc / ConstructN-fast / bare-RET claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00418d70` — sealed facts

1. **Body:** `0x00418d70`–`0x00418dc6` exclusive (**86 B** / `0x56`); pad `CC`.
2. **ABI:** **`__thiscall`**; **ECX** = vector host*; stack `const T*` value (8-byte POD pointer); void; dual **`RET 4`**.
3. **Layout:** host `begin@+4`, `end@+8`, `capEnd@+0xC`; size/cap via `(ptr-begin)>>3`.
4. **Semantics:** MSVC-style **vector::push_back** for **8-byte** elements:
   - Fast: if begin non-null and size < capacity → copy two dwords at end; end += 8.
   - Slow: `CALL 00418e10` insert-one/rebind at end (undualed).
5. **Callees:** `FUN_00418e10` only.
6. **Callers / xrefs (13):**  
   - Parent `FUN_005755b0` @ `0x0057567e` — `LEA ECX,[ESI+0x1F4]` COID vector  
   - `FUN_004d4040` ×2, `FUN_004deb20`, `FUN_004dfcc0`, `FUN_005acef0`, `FUN_005ea300`, `FUN_006082e0` ×2, `FUN_0080af70`  
   - Orphans `00564eab`, `00564f4b`, `005ad471`
7. **Name:** `StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred` (Ghidra `FUN_00418d70`).  
   **Rejected:** `Named_CalleeOf_Named_VOG_DEBUG_STOP_00418d70` (parent `"VOG_DEBUG_STOP"` false path only).
8. **Live decompile ≡ scaffold raw body** — re-verify **appended**; clean follows sealed CF/ABI under `_Inferred` name.

### Gaps

- Product element English (COID pair vs generic pair<u32,u32>).  
- Dual seal of grow/insert `00418e10` / `00418e60`.  
- Orphan site plates.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00418d70_FUN_00418d70.md` |
| Annotated | `docs/reconstruction/raw/aa_00418d70_FUN_00418d70.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00418d70.cpp` |
| Function | `docs/reconstruction/functions/aa_00418d70_FUN_00418d70.md` |
| Function named | `docs/reconstruction/functions/aa_00418d70_StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_005755b0  VehicleCrew_InsertMember_Inferred  [parent dual; not OWN]
  ├─ FUN_005749d0  VehicleCrew_ContainsMember_Inferred
  ├─ FUN_00520330  back-link leaf
  └─ FUN_00418d70  StdVector_PushBack_Elem8_EcxVec_StackVal_Inferred [OWN R10-025]
       └─ FUN_00418e10  insert-one/rebind grow   [shared residual undualed]
            └─ FUN_00418e60  reallocate / insertN [shared residual]

Multi-domain peers also call 00418d70 (8 named + orphans) — keep generic util name.
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00418d70-r10-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00418d70` | Port as **vector push_back elem 8**. **`__thiscall`** ECX=vec, stack `const T*`, **`RET 4`**. Fast path raw 2×u32 copy when spare capacity; else grow via `00418e10`. Host triad at **+4/+8/+0xC**. Do **not** use VOG_DEBUG_STOP plate. Do **not** lock to crew-only. Do **not** merge with Elem12 (`004062a0`) / Elem0x28 (`00406220`) register-ABI twins. |
| Pair with | parent crew insert `005755b0`; grow residual `00418e10`; other multi-domain consumers. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` skills-abilities residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Not written by this agent.**

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00418d70`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + force_decompile + analyze_function_complete + read_memory + callers/xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean sources under `_Inferred` name; twin keeps `FUN_00418d70`.  
- Rejected parent-string Named_CalleeOf plate.  
- Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
