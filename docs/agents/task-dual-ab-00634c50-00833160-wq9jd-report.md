# Dual A/B report — WQ9J-D OWN-ONLY (`0x00634c50`, `0x00833160`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9J-D**  
**Scope:** VAs `0x00634c50`, `0x00833160` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `batch_decompile` / `analyze_function_complete` + `read_memory` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth7_partition_map.md` → **WQ9J-D**.  
**Work item:** WQ-009 depth-7 residual dual seal (FieldBlock_CopyFrom callers).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00634c50` MeshHost_UploadXformPosNormAndIB16_Inferred | **accept-with-gaps** — fastcall host / VB+IB upload / FieldBlock xform temp / sole Tick caller sealed; product host English + device-wrapper types open |
| `aa_00833160` ShopVehObject_SwapSelectState_ESI_EDI_Inferred | **accept-with-gaps** — ESI/EDI ABI / select-field swap / +0x510 three-way FieldBlock / sole shopveh-list caller sealed; product class English + byte micro-order open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): full-memcpy swap, thiscall-as-CVOGObject, draw/import mesh, FieldBlock-identity, decompiler multi-write-to-0x13f as product, and shopveh plate-as-symbol **rejected/narrowed**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x00634c50` — sealed facts

1. **Body:** `0x00634c50`–`0x00634df7` inclusive / exclusive end `0x00634df8` (**424 B** / `0x1A8`).
2. **ABI:** **`__fastcall`**; ECX = mesh-upload host*; no stack args; **`RET`** (`C3`). Frame 16-byte aligned, `SUB ESP,0xF4`; `MOV EDI,ECX`.
3. **Semantics:** Gate host pos/nrm/idx pointers+counts → OR owner flags `*(owner+0xBC)|=1` → lock VB → copy owner xform via `FUN_00416240` to stack temp → resolve FVF pos(usage0)/nrm(usage3) offsets → write xformed verts by stride → unlock VB → lock IB (`0x800`) → pack u32→u16 indices → unlock IB.
4. **Classification:** worker.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `0x005952a9` in `FUN_00595230` (`CVOGObject_Tick`) — multi hosts from `this+0x1c4`, gated by `+0x90d` bit1.
6. **Name:** `MeshHost_UploadXformPosNormAndIB16_Inferred` (Ghidra `FUN_00634c50`). VB/IB unlock string evidence on callees; product host English open → `_Inferred`.
7. **Decompile ≡ scaffold CF**; prologue/epilogue sealed via `read_memory`.
8. **FieldBlock role:** single call @ `0x00634ce5` — stack temp dest, src from `FUN_00437960(owner)`.

### Gaps

- Product English for host / owner class.  
- Exact device-wrapper `this` typing for stride/unlock helpers.  
- IB flag `0x800` product enum.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.md` |
| Annotated | `docs/reconstruction/raw/aa_00634c50_FUN_00634c50.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/MeshHost_UploadXformPosNormAndIB16_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00634c50.cpp` |
| Function | `docs/reconstruction/functions/aa_00634c50_FUN_00634c50.md` |
| Function named | `docs/reconstruction/functions/aa_00634c50_MeshHost_UploadXformPosNormAndIB16_Inferred.md` |

---

## VA `0x00833160` — sealed facts

1. **Body:** `0x00833160`–`0x00833382` inclusive / exclusive end `0x00833383` (**547 B** / `0x223`).
2. **ABI:** **ESI** = objA*, **EDI** = objB* (caller-preloaded); no stack args; returns **AL** 0/1; **`RET`**.
3. **Semantics:** If EDI null → 0. Else swap select dwords/bytes; three-way nested XformState at **`+0x510`** via `FUN_00416240` + `FUN_00416160`×2; swap `+0x5E0` block and `+0x500/+0x504`; optional nested pos cross via vtbl `+0x1a0` + `FUN_0040cf90`; vtbl `+0x3bc` on both; return 1.
4. **Classification:** worker.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `0x0083ad72` in `FUN_0083ac90` (shopveh list five-slot table at host `+0x50c`).
6. **Name:** `ShopVehObject_SwapSelectState_ESI_EDI_Inferred` (Ghidra `FUN_00833160`). Scaffold shopveh plate is co-location only → `_Inferred`.
7. **Decompile ≡ overall CF**; byte-swap detail uses **assembly authority** (decompiler over-summarizes `0x13f`).
8. **FieldBlock role:** call @ `0x00833249` starts three-way swap of nested blocks at `ESI/EDI+0x510` (matches WQ9I-H caller note).

### Gaps

- Product demangle for object class.  
- English for each swapped offset.  
- Vtbl `+0x1a0` / `+0x3bc` method names.  
- Byte-swap intermediate micro-order.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00833160_FUN_00833160.md` |
| Annotated | `docs/reconstruction/raw/aa_00833160_FUN_00833160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/ShopVehObject_SwapSelectState_ESI_EDI_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00833160.cpp` |
| Function | `docs/reconstruction/functions/aa_00833160_FUN_00833160.md` |
| Function named | `docs/reconstruction/functions/aa_00833160_ShopVehObject_SwapSelectState_ESI_EDI_Inferred.md` |

---

## Chain context (FieldBlock callers — OWN sealed)

```text
FUN_00416240  FieldBlock_CopyFrom_ClearFlags0xBC_Inferred  [WQ9I-H dualed]
  ├─ FUN_00634c50  MeshHost_UploadXformPosNormAndIB16_Inferred  [OWN WQ9J-D]
  │     stack temp ← owner xform (FUN_00437960); then pos/nrm VB write + IB16
  └─ FUN_00833160  ShopVehObject_SwapSelectState_ESI_EDI_Inferred  [OWN WQ9J-D]
        three-way nested +0x510 swap with FUN_00416160 ×2

FUN_00416160  XformState_AssignSelectiveByFlags_Inferred  [WQ9I-G dualed]
  └─ used ×2 inside FUN_00833160 swap

FUN_00595230  CVOGObject_Tick
  └─ optional multi FUN_00634c50 from this+0x1c4 when +0x90d bit1

FUN_0083ac90  shopveh list reindex
  └─ FUN_00833160 with ESI/EDI from host+0x50c[5]
```

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00634c50` | Port as **mesh-host GPU buffer refresh**: lock VB → xform pos/nrm into FVF → unlock; lock IB → u16 pack → unlock. **Not** draw, **not** asset import, **not** CVOGObject-as-ECX. Pair with FieldBlock helpers for xform temp. |
| `00833160` | Port as **curated ESI/EDI object-state swap** for list slot reassignment: select offsets + three-way `+0x510` XformState + optional nested pos + vtbl refresh. **Not** full memcpy, **not** thiscall, **not** dtor. |
| Pair with | `FUN_00416240` / `FUN_00416160` (WQ9I-H/G); Tick multi-host table; shopveh list host `+0x50c`. |
| Naming caution | Scaffold shopveh / long callee-of plates are **co-location auto labels** — not sealed product IDs without RTTI/string at these VAs. |

---

## Process

- OWN VAs only (`0x00634c50`, `0x00833160`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank-line paste).  
- Odd behavior preserved: decompiler byte-swap artifact on `00833160`; IB u16 pack from u32 source.  
- `_Inferred` where English unproven; Terminal **false**.

### Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems residual table (mesh upload + shopveh list / field-block callers)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

### Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00634c50-00833160-wq9jd-report.md` |

---

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
