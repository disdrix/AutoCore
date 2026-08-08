# Dual A/B report — WQ9H-D OWN-ONLY (`0x004063a0`, `0x00406420`)

**Date:** 2026-08-04  
**Agent:** OWN-ONLY dual **WQ9H-D**  
**Scope:** VAs `0x004063a0`, `0x00406420` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth5_partition_map.md` → **WQ9H-D**.  
**Work item:** WQ-009 depth-5 residual dual seal (CNDHash freelist/ctor/dtor/recreate stamp family — this agent: **ctor + dtor** for vtbl `00a2c2b0` / stamp `00a2c2e4`).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004063a0` CNDHash_Ctor_00a2c2b0 | **accept-with-gaps** — ctor CF/ABI(CL+stack)/field map/vtbl/alloc handoff sealed; product English open |
| `aa_00406420` CNDHash_Dtor_00a2c2b0 | **accept-with-gaps** — dtor CF/thiscall/lock soft-assert/destroy+freelist order sealed; freelist helper dual + product open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): no CF rejects; thiscall-merge-with-skill-ctor, lock-throws, VOG_DEBUG_STOP-as-identity, freelist-at-byte-+8, stamp-family-merge all **rejected**.  
Runtime Confirmed: **not claimed** (no Launcher).

---

## VA `0x004063a0` — sealed facts

1. **Body:** `0x004063a0`–`0x0040641c` inclusive (**125 B** / `0x7D`); `CC` pad then dtor.
2. **ABI (machine):** **CL = log2**; **stack = CNDHash\***; **EAX = this**; **`ret 4`**. **Not** standard thiscall (this not in ECX). Ghidra `__thiscall(byte, this*)` is role-swap fiction.
3. **Semantics:** MSVC-style host **CNDHash constructor** (sizeof **0x34**):
   - Install vtbl **`PTR_FUN_00a2c2b0`**.
   - `*(+8) = 1 << log2` (provisional **COUNT**).
   - Zero `+4,+0xc,+0x10,+0x14,+0x18,+0x20,+0x28,+0x2c,+0x30`; `+0x1c`=log2; `+0x1d`=0 lock; **`+0x24` not written**.
   - `CNDHash_AllocBucketTable_00a2c2e4` with **ESI=this** → stamp sentinels **`00a2c2e4`**, COUNT→MASK.
4. **Callers (1):** `FUN_0093e7e0` @ `0x0093e8eb` — `operator_new(0x34)`; **`MOV CL,2`**; `PUSH` block; store result at host **`+0x3084`**.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `CNDHash_Ctor_00a2c2b0` (Ghidra `FUN_004063a0`). Reject `Named_CalleeOf_Named_CalleeOf_Mission_createNDUIDialogs_004063a0`.
7. **Decompile ≡ raw CF**; ABI/vtbl sealed via `read_memory` + `disassemble_function` + caller context.

### Gaps

- Product / PDB English for class behind vtbl `00a2c2b0`.  
- Full dual of sole caller `FUN_0093e7e0` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_004063a0_CNDHash_Ctor_00a2c2b0.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_004063a0_FUN_004063a0.md` |
| Annotated | `docs/reconstruction/raw/aa_004063a0_FUN_004063a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Ctor_00a2c2b0.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004063a0.cpp` |
| Function | `docs/reconstruction/functions/aa_004063a0_FUN_004063a0.md` |
| Function named | `docs/reconstruction/functions/aa_004063a0_CNDHash_Ctor_00a2c2b0.md` |

---

## VA `0x00406420` — sealed facts

1. **Body:** `0x00406420`–`0x0040649a` inclusive (**123 B** / `0x7B`); `CC` pad after bare `ret`.
2. **ABI:** **`__thiscall`**; **ECX = CNDHash\***; **void**; bare **`ret`** (`C3`). Entry `MOV ESI,ECX`.
3. **Semantics:** host **CNDHash destructor**:
   - Re-stamp vtbl **`00a2c2b0`**.
   - If lock `@+0x1d` ≠ 0: log **`HashError:Destructor, already locked for traversal`** + **`VOG_DEBUG_STOP`** (**non-fatal**, continues).
   - `CNDHash_DestroyBucketTable_00a2c2e4` with **EAX=this**.
   - Freelist slab-vector dtor `FUN_00416e80(this+0x20)` (decompiler `param_1+8` = dword → +0x20).
4. **Callers (1):** `FUN_00406520` (scalar deleting; vtbl[`00a2c2b0`][0]) @ `0x00406523` — then optional `operator_delete` if flags&1.
5. **Xrefs:** 1 UNCONDITIONAL_CALL.
6. **Name:** `CNDHash_Dtor_00a2c2b0` (Ghidra `FUN_00406420`). Reject scaffold `Named_VOG_DEBUG_STOP_00406420`.
7. **Decompile ≡ raw CF**; free/destroy order sealed via `read_memory` + disasm.

### Gaps

- Product / PDB English.  
- Full dual of freelist vector `FUN_00416e80` + scalar wrapper `FUN_00406520` (not OWN).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00406420_CNDHash_Dtor_00a2c2b0.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00406420_CNDHash_Dtor_00a2c2b0.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00406420_FUN_00406420.md` |
| Annotated | `docs/reconstruction/raw/aa_00406420_FUN_00406420.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CNDHash_Dtor_00a2c2b0.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00406420.cpp` |
| Function | `docs/reconstruction/functions/aa_00406420_FUN_00406420.md` |
| Function named | `docs/reconstruction/functions/aa_00406420_CNDHash_Dtor_00a2c2b0.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_0093e7e0  (host init; new(0x34); log2=2 → host+0x3084)
  └─ CNDHash_Ctor_00a2c2b0 (0x004063a0)                    [OWN WQ9H-D]
        └─ CNDHash_AllocBucketTable_00a2c2e4 (0x00406f20)  [sealed WQ9G-J]

vtbl[00a2c2b0][0] = FUN_00406520  (scalar deleting)
  └─ CNDHash_Dtor_00a2c2b0 (0x00406420)                    [OWN WQ9H-D]
        ├─ CNDHash_DestroyBucketTable_00a2c2e4 (0x00406fc0)[sealed WQ9G-J]
        │     └─ FUN_004085e0 freelist release             [WQ9H-A residual]
        └─ FUN_00416e80 (this+0x20) freelist vector dtor   [residual]

FUN_004195d0  (Recreate; not OWN — WQ9H-E)
  ├─ DestroyBucketTable / seed / AllocBucketTable
  └─ (uses same stamp family; pairs with this ctor/dtor)
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-004063a0-00406420-wq9hd-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004063a0` | Port as **CNDHash ctor** for vtbl **`00a2c2b0`**. **CL=log2, stack this, ret 4** — do **not** use skill-style thiscall. Size **0x34**. Pair with alloc `00406f20` (ESI). Production log2 **2** at sole site. Preserve **+0x24 unwritten**. |
| `00406420` | Port as **complete dtor** twin. **ECX thiscall**; soft lock log (no throw); destroy via **EAX** `00406fc0`; freelist vector at **+0x20** via `00416e80`. Pair with scalar deleting `00406520`. |
| Pair with | sealed alloc/destroy `00406f20`/`00406fc0`; freelist `004085e0`; Recreate `004195d0` when dualed (WQ9H-E); other stamp-family ctor/dtor twins. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- `systems/skills-abilities.md` residual table **or** container/CNDHash residual table (general CNDHash, not skill-specific)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x004063a0`, `0x00406420`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful stamp-qualified names.  
- Odd behavior preserved: +0x24 skip; lock soft-assert; inverted ctor ABI.  
- Stamp-suffix naming (product English unproven); Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
