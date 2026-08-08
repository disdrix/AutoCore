# Dual A/B report — MEGA-029 OWN-ONLY (`0x004bc530`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-029**  
**Scope:** VA `0x004bc530` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context` + `read_memory`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA-029 residual dual seal — CNDHash TraverseToNext (list-next@+0x20 / payload@+0xc); parent shell `FUN_004bae00` TraversalLock walk.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004bc530` CNDHash_TraverseToNext_ListNext20 | **accept-with-gaps** — CF/ABI/RET4/string-role/layout sealed; stamp English + runtime open |

Path A (fidelity): **accept-with-gaps**.  
Path B (adversarial): VOG_DEBUG_STOP product-id / twin-merge / fatal-unlock / return-node / lock-mutation / cdecl claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004bc530` — sealed facts

1. **Body:** `0x004bc530`–`0x004bc57d` inclusive (**78 B** / `0x4E`).
2. **ABI:** **ECX** = hash this; stack `int* cursor`; **EAX** = payload or 0; **`RET 4`** ×2 exits.
3. **Semantics:** CNDHash **TraverseToNext** under held TraversalLock:
   - If `*(this+0x1d)==0` → log `"HashError:TraverseToNext, not locked for traversal"` + `"VOG_DEBUG_STOP"`; **fall-through continues**.
   - Cursor 0 → seed from list head `*(this+0x14)`.
   - Else → advance via **`*(cursor+0x20)`**.
   - Non-null node → return **`*(node+0xc)`** payload; else 0.
   - No lock set/clear; no membership mutation.
4. **Strings:** TraverseToNext error @ `0x00a27c9c`; VOG_DEBUG_STOP @ `0x00a15844`.
5. **Callees:** `FUN_007a4480` only (cdecl; `ADD ESP,0x10`).
6. **Callers:** sole `FUN_004bae00` — 2 UNCONDITIONAL_CALL @ `0x004bae24` (hash `[ESI+4]`) / `0x004bae4e` (hash `[ESI+8]`); parent clears `+0x1d` after return.
7. **Lock companion:** `FUN_00402c40` sets `+0x1d=1` (`HashError:TraversalLock, already locked…`).
8. **Twin:** dualed `CNDHash_TraverseToNext` `0x00411900` — next@**+0x14** / payload@**+8** — **do not merge**.
9. **Name:** `CNDHash_TraverseToNext_ListNext20` (Ghidra `FUN_004bc530`). Reject `Named_VOG_DEBUG_STOP_004bc530`.
10. **Decompile ≡ raw CF**; ABI/offsets sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Exact COList / stamp English for this 0x28-node family instance.  
- Parent shell `FUN_004bae00` residual (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004bc530_CNDHash_TraverseToNext_ListNext20.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004bc530_FUN_004bc530.md` |
| Annotated | `docs/reconstruction/raw/aa_004bc530_FUN_004bc530.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraverseToNext_ListNext20.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004bc530.cpp` |
| Retired misname | `docs/reconstruction/reconstructed-exact/Named_VOG_DEBUG_STOP_004bc530.cpp` |
| Function | `docs/reconstruction/functions/aa_004bc530_FUN_004bc530.md` |
| Function named | `docs/reconstruction/functions/aa_004bc530_CNDHash_TraverseToNext_ListNext20.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004bae00  dual-hash TraversalLock walk shell  [residual]
  ├─ branch A (flag this+0xc): hash @ this+4
  │     FUN_00402c40  TraversalLock
  │     FUN_004bc530  CNDHash_TraverseToNext_ListNext20  [OWN MEGA-029]
  │     clear hash+0x1d
  └─ branch B (flag this+0xd): hash @ this+8
        FUN_00402c40
        FUN_004bc530  [OWN MEGA-029]
        clear hash+0x1d

Twin (do not merge):
  FUN_00411900  CNDHash_TraverseToNext  [dualed; next+0x14 / payload+8]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004bc530-mega-029-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004bc530` | Port as **CNDHash TraverseToNext** for **list-next@+0x20 / payload@+0xc** nodes. **ECX=hash**, stack=cursor*, **RET 4**. Log-if-unlocked is **non-fatal**. Do **not** set/clear lock here. |
| Keep distinct from | skill-family twin `00411900` (next+0x14 / payload+8); TraversalLock `00402c40`; parent shell `004bae00`. |
| Pair with | parent lock/unlock shell; same-region CNDHash Alloc/Ctor/Free stamp twins when dualled. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/*` residual tables (CNDHash container — not interaction-specific leaf)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x004bc530`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + string bytes. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful layout-disambiguated name; machine ABI corrections (thiscall RET 4; non-fatal unlock log).  
- Odd behavior preserved: unlocked path continues; returns payload not node; no lock mutation in leaf.  
- Retired `Named_VOG_DEBUG_STOP_004bc530` scaffold plate. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
