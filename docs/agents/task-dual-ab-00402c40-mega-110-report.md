# Dual A/B report — MEGA-110 OWN-ONLY (`0x00402c40`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **MEGA-110**  
**Scope:** VA `0x00402c40` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers; other VAs.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` / `get_function_callees` + `get_xrefs_to` + `read_memory` + `search_strings`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Work item:** MEGA residual dual seal — TraversalLock set (fastcall); partition parent `0x0091b8d0` Client_UpdateNpcInteractIcons.  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00402c40` CNDHash_TraversalLock_Set_Inferred | **accept** — CF/ABI/RET0/flag+0x1d/soft force-set/strings/30 xrefs sealed |

Path A (fidelity): **accept**.  
Path B (adversarial): VOG_DEBUG_STOP identity / hard-abort / List_TraversalLock merge / unlock / stack-hash RET4 / owner-this / early-out-on-locked claims **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00402c40` — sealed facts

1. **Body:** `0x00402c40`–`0x00402c69` inclusive (**42 B** / `0x2A`); pad `CC` before `0x00402c70`.
2. **ABI:** **ECX** = CNDHash*; no stack args; void; **bare RET**.
3. **Semantics:** soft **TraversalLock set** at **`hash+0x1d`**:
   - If already non-zero: `FUN_007a4480(0, "HashError:TraversalLock, already locked for traversal")` then `FUN_007a4480(0, "VOG_DEBUG_STOP")`.
   - Always `*(uint8_t*)(hash+0x1d) = 1`.
   - Does **not** throw, EnterCS, or walk nodes.
4. **Strings:** `0x00a27cd0` HashError TraversalLock; `0x00a15844` VOG_DEBUG_STOP.
5. **Callees:** `FUN_007a4480` only (×2).
6. **Callers:** **21** functions; **30** UNCONDITIONAL_CALL xrefs (incl. partition parent `Client_UpdateNpcInteractIcons` @ `0x0091bb79` with ECX=hash from `client+0x548`).
7. **Pair evidence:** after set, same hash fed to dualed `CNDHash_TraverseToNext` (`0x00411900`); unlock often **inline** `+0x1d=0` (e.g. `FUN_004bae00`).
8. **Name:** `CNDHash_TraversalLock_Set_Inferred` (Ghidra `FUN_00402c40`). Product method English open → `_Inferred`. Scaffold `Named_VOG_DEBUG_STOP_*` **retired**.
9. **Decompile ≡ raw CF**; ABI sealed via `disassemble_function` + `read_memory` + call-site context.

### Gaps

- Product/PDB CNDHash method English.  
- Shared unlock helper (if any) — many sites inline.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00402c40_FUN_00402c40.md` |
| Annotated | `docs/reconstruction/raw/aa_00402c40_FUN_00402c40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_TraversalLock_Set_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00402c40.cpp` |
| Function | `docs/reconstruction/functions/aa_00402c40_FUN_00402c40.md` |
| Function named | `docs/reconstruction/functions/aa_00402c40_CNDHash_TraversalLock_Set_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
Client_UpdateNpcInteractIcons  0x0091b8d0  [partition parent]
  hash = *(DAT_00d1b6d8 + 0x548)
  ├─ FUN_00402c40  CNDHash_TraversalLock_Set_Inferred  [OWN MEGA-110]
  ├─ FUN_00411900  CNDHash_TraverseToNext              [dualed elsewhere]
  └─ … walk NPC interact icons …
       unlock often: *(hash+0x1d)=0 inline

FUN_004bae00  pick/list residual
  ECX = hash from this+4 / this+8
  ├─ FUN_00402c40  [OWN MEGA-110]
  ├─ FUN_004bc530  walk payload
  └─ *(hash+0x1d)=0  inline unlock

List_TraversalLock  0x004294f0  [DISTINCT — CS list family, flag +0x28]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00402c40-mega-110-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00402c40` | Port as **CNDHash TraversalLock soft-set**: if flag@**+0x1d** already set, debug-log HashError + VOG_DEBUG_STOP, then **always** set flag=1. **ECX=hash**, bare RET, void. Do **not** throw. Keep distinct from `List_TraversalLock` (`+0x28`/CS) and from VOG_DEBUG_STOP-named stubs. Pair with `CNDHash_TraverseToNext` (`00411900`); unlock is frequently a direct `flag=0` store. |

---

## Parent merge handoff (not done here)

Per OWN-ONLY rules, parent should lockstep for this VA:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history (retire `Named_VOG_DEBUG_STOP_00402c40`)  
- `systems/*` interaction-activation / hash residual tables  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN VA).

---

## Process

- OWN VA only (`0x00402c40`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + disassemble_function + call-site context + strings. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed.  
- Scaffold raw body preserved; re-verify **appended** only.  
- Clean source uses meaningful name; twin `FUN_00402c40.cpp` retained.  
- Odd behavior preserved: soft re-lock continues and forces flag=1.  
- `_Inferred` for product method English. Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
