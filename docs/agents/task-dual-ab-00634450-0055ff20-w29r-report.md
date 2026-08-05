# Dual A/B report — W29-R OWN `aa_00634450` + `aa_0055ff20`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W29-R  
**Scope:** VAs `0x00634450`, `0x0055ff20` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `read_memory` + `get_function_by_address` (+ callers/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave29_partition_map.md` → W29-R  

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00634450` PhysHost_ReconcileLinkPairs_Inferred | **accept** — dual worklist + SortedDiffWalk host reconcile CF/ABI sealed |
| `aa_0055ff20` PhysMgr_AttachBody_Inferred | **accept** — manager body attach CF/ABI + serial/vector/refcount sealed |

---

## VA `0x00634450` — sealed facts

1. **Body:** `0x00634450`–`0x0063453f` (**240 B**); next fn at `0x00634540`.
2. **ABI:** **thiscall**; ECX = host; stack = query param; void; **`ret 4`**.
3. **Gate:** `*(host+8) != 0` (manager).
4. **Worklists:** dual `FUN_0062d960` from `*(mgr+0x238)`; dual `LocalWorklist_Release` (`0055f4c0`).
5. **Query:** `*(mgr+0xc4)->vtbl+0x14` with null-safe `host+0x1c`, stack param, flag **1**.
6. **Reconcile:** if either list non-empty → CanonAndSort ×2 → SortedDiffWalk (**machine ECX = `*(mgr+0x138)`**, pred `*(mgr+0xd0)?+8:0`) → compact `host+0x3c` via `FUN_005fff20`.
7. **Callers (8):** `FUN_00580c00`, `FUN_00580dd0`, `FUN_005eb0e0`, `FUN_005eb130`, `FUN_005eb2b0`, `FUN_005eb320`, `FUN_005eb8e0`, `FUN_005eb9e0`.
8. **Name:** `PhysHost_ReconcileLinkPairs_Inferred` (Ghidra `FUN_00634450`).
9. **Decompile ≡ bytes** for CF; clean documents residuals (`uVar2=1`, omitted SortedDiffWalk this).

### Gaps

- Product English for host / manager / vtbl+0x14.  
- Exact stack out mapping for second list (decompiler residual).  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00634450_FUN_00634450.md` |
| Annotated | `docs/reconstruction/raw/aa_00634450_FUN_00634450.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysHost_ReconcileLinkPairs_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00634450.cpp` |
| Function | `docs/reconstruction/functions/aa_00634450_FUN_00634450.md` |
| Function named | `docs/reconstruction/functions/aa_00634450_PhysHost_ReconcileLinkPairs_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_00634450.md` |

---

## VA `0x0055ff20` — sealed facts

1. **Body:** `0x0055ff20`–`0x00560017` (**248 B**); pad `CC` after `ret 4`.
2. **ABI:** **thiscall**; ECX = manager; stack = body*; returns body*; **`ret 4`**.
3. **Owner/serial:** `body[+8]=manager`; `body[+0x20]=mgr[+0x130]++`.
4. **Links:** worklist init `*(mgr+0x234)`; body `vtbl+0x18`; mgr `[+0xc4] vtbl+4`; optional CanonAndSort + SortedDiffWalk(**new vs empty**, ECX=`*(mgr+0x138)`).
5. **Bookkeeping:** short ref `body+6` ++; body vector at `mgr+0x120` grow via `FUN_005b3370(...,4)` when `count == (cap & 0x7fffffff)`; push; `FUN_0062a4d0` notify; `LocalWorklist_Release`.
6. **Callers (7 / 8 xrefs):** `FUN_004ca9f0`, `FUN_004e9720`, `FUN_004ea350`, `FUN_005625c0`, `FUN_005dd080`×2, `FUN_00932060`, `hkVehicleFramework_preUpdate`.
7. **Twin:** detach `FUN_00560020` (W29-S).
8. **Name:** `PhysMgr_AttachBody_Inferred` (Ghidra `FUN_0055ff20`).
9. **Decompile ≡ bytes** for CF; clean adds machine SortedDiffWalk this + grow mask.

### Gaps

- Product English for manager / body classes.  
- Full body layout beyond sealed offsets.  
- Runtime / bit-exact — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0055ff20_PhysMgr_AttachBody_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0055ff20_PhysMgr_AttachBody_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.md` |
| Annotated | `docs/reconstruction/raw/aa_0055ff20_FUN_0055ff20.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PhysMgr_AttachBody_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0055ff20.cpp` |
| Function | `docs/reconstruction/functions/aa_0055ff20_FUN_0055ff20.md` |
| Function named | `docs/reconstruction/functions/aa_0055ff20_PhysMgr_AttachBody_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_0055ff20.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00634450` | Pose/AABB write paths must reconcile host links via dual worklist + SortedDiffWalk — **not** `WorldObj_BindLinks` (`0055fa40`) and **not** simple `Phys_CommitPairListStorage` (`006297e0`). Preserve **`ret 4`**, flag `1` query, and SortedDiffWalk **this = `*(mgr+0x138)`**. |
| `0055ff20` | Body registration must stamp owner + serial, attach-side SortedDiffWalk (**left=new, right empty**), bump short ref, push manager body vector with **`0x7fffffff` cap mask**, notify, release. **Do not** invert sides vs detach twin `00560020`. Preserve **`ret 4`** and body return. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + get_function_by_address (+ callers/xrefs). **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` suffix used.
