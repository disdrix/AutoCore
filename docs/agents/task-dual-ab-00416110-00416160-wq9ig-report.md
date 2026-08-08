# Dual A/B report — WQ9I-G OWN-ONLY (`0x00416110`, `0x00416160`)

**Date:** 2026-08-05  
**Agent:** OWN-ONLY dual **WQ9I-G**  
**Scope:** VAs `0x00416110`, `0x00416160` only. Dual A/B + trio raw/annotated/clean + function records.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / VERIFICATION_MATRIX / NAMING_REGISTRY / other parent ledgers.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `analyze_function_complete` + `disassemble_function` + callers/xrefs + `get_assembly_context`. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-08-04_wq009_depth6_partition_map.md` → **WQ9I-G**.  
**Work item:** WQ-009 depth-6 residual dual seal (`00416xxx` residual neighborhood).  
**Terminal:** **false** (no runtime Confirmed).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00416110` Class_00a9bbe8_CompleteDtor_Inferred | **accept-with-gaps** — stack-arg complete dtor / SEH / vptr `0x00a9bbe8` / ret4 sealed; product class English open |
| `aa_00416160` XformState_AssignSelectiveByFlags_Inferred | **accept-with-gaps** — thiscall selective transform assign / flag gates / offsets / gen++ / ret4 sealed; product type English open |

Path A (fidelity): both **accept-with-gaps**.  
Path B (adversarial): thiscall-on-dtor, full-memcpy assign, phySkeleton-only, CxImage-from-adjacent-string, and same-type-for-both-VAs all **falsified**.  
Runtime Confirmed: **not claimed** (no Launcher).

**Note:** The two OWN VAs are **different types** (vptr class vs transform POD). Paired only by partition neighborhood, not by object identity.

---

## VA `0x00416110` — sealed facts

1. **Body:** `0x00416110`–`0x00416147` exclusive (**55 B** / `0x37`); pad `CC`.
2. **ABI:** Stack `obj*` (not ECX thiscall); SEH handler `0x009bc0a8`; **`ret 4`** (`C2 04 00`).
3. **Semantics:** MSVC-style **complete destructor** — `*obj = &PTR_LAB_00a9bbe8` only; no free, no field teardown.
4. **Classification:** leaf / complete dtor.
5. **Xrefs (1 UNCONDITIONAL_CALL):** `0x004160f4` in `FUN_004160f0` — scalar-deleting (`push this; call`; optional `operator_delete` on flag bit0).
6. **Callees:** none.
7. **Vtable `0x00a9bbe8`:** slot0 `0x00416150` set+8; slot1 `0x0044f660` get+8; slot2 `0x005ffc80` empty; slot3 `0x004320b0` sd-dtor style. Ctor twin `FUN_0078bc20` installs same vptr.
8. **Name:** `Class_00a9bbe8_CompleteDtor_Inferred` (Ghidra `FUN_00416110`). Product demangle open → `_Inferred`.
9. **Decompile ≡ raw store CF**; SEH/stack/`ret 4` sealed via **bytes** + sole caller (decompiler elides SEH).

### Gaps

- Product / RTTI class English.  
- Virtual sd-dtor @ `0x004320b0` undualed.  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416110_Class_00a9bbe8_CompleteDtor_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416110_Class_00a9bbe8_CompleteDtor_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416110_FUN_00416110.md` |
| Annotated | `docs/reconstruction/raw/aa_00416110_FUN_00416110.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_00a9bbe8_CompleteDtor_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416110.cpp` |
| Function | `docs/reconstruction/functions/aa_00416110_FUN_00416110.md` |
| Function named | `docs/reconstruction/functions/aa_00416110_Class_00a9bbe8_CompleteDtor_Inferred.md` |

---

## VA `0x00416160` — sealed facts

1. **Body:** `0x00416160`–`0x0041623A` exclusive (**218 B** / `0xDA`); pad `CC` to `FUN_00416240`.
2. **ABI:** **thiscall** — **ECX** = dest*; stack = src*; **`ret 4`**.
3. **Semantics:** Selective transform-state assign:
   - Always: mid `@+0x80..+0xA7` (10 dwords), byte `@+0xB8`, flags `@+0xBC` from **src**.
   - `!(flags&1)` → copy 16 dwords `@+0x00` (4×4).
   - `!(flags&2)` → copy 16 dwords `@+0x40` (4×4).
   - `!(flags&4)` → copy 3 dwords `@+0xA8`.
   - Always: `*(dest+0xB4) += 1` (generation).
4. **Full-copy wrapper:** `FUN_00416240` zeros `@+0xBC` then calls this.
5. **Classification:** leaf / worker util.
6. **Xrefs (16):** multi-system (`FUN_00416240`, `FUN_00833160`×2, `FUN_0096b000`×2, env/vehicle/UI paths, JMP adjustor `0x00464853` = `add ecx,0x10; jmp`).
7. **Callees:** none.
8. **Name:** `XformState_AssignSelectiveByFlags_Inferred` (Ghidra `FUN_00416160`). Scaffold phySkeleton alias is caller-graph only → superseded by shared-util name.
9. **Decompile ≡ raw ≡ bytes** for CF/offsets/flag policy.

### Gaps

- Product type / field English (matrix labels, mid block).  
- Flag bit product semantics (behavior sealed: set → skip).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00416160_XformState_AssignSelectiveByFlags_Inferred.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00416160_XformState_AssignSelectiveByFlags_Inferred.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_00416160_FUN_00416160.md` |
| Annotated | `docs/reconstruction/raw/aa_00416160_FUN_00416160.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/XformState_AssignSelectiveByFlags_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00416160.cpp` |
| Function | `docs/reconstruction/functions/aa_00416160_FUN_00416160.md` |
| Function named | `docs/reconstruction/functions/aa_00416160_XformState_AssignSelectiveByFlags_Inferred.md` |

---

## Chain context (not dualled; evidence only)

```text
FUN_004160f0  scalar-deleting dtor
  └─ Class_00a9bbe8_CompleteDtor_Inferred (0x00416110)  [OWN WQ9I-G]
       *obj = vftable 0x00a9bbe8

FUN_0078bc20  ctor twin (same vptr install)               [not OWN]

FUN_00416240  full assign wrapper
  ├─ *(this+0xBC) = 0
  └─ XformState_AssignSelectiveByFlags_Inferred (0x00416160)  [OWN WQ9I-G]
       selective matrix/mid/tail copy + gen++

0x00464850  MI adjustor: this+0x10 → 00416160            [not OWN]
```

---

## Report

| Kind | Path |
|------|------|
| This report | `docs/agents/task-dual-ab-00416110-00416160-wq9ig-report.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00416110` | Port as **complete dtor**: stack `obj*`, **ret 4**, install vftable `0x00a9bbe8`. **Not** ECX thiscall. No free of `this` (wrapper deletes). Preserve SEH if matching retail EH. |
| `00416160` | Port as **selective transform assign**: ECX=dest, stack=src*, **ret 4**. Do **not** blind-memcpy whole object. Honor flags bits 0/1/2 skip; always bump gen `@+0xB4`. Pair with full-assign `00416240` (clear flags first). |
| Pair with | sd-dtor `004160f0`; ctor `0078bc20`; full-assign `00416240`; adjustor `+0x10` thunk — when dualed. |
| Naming caution | **Do not** merge the two OWN VAs into one type. **Do not** treat `00416160` as phySkeleton-private. Adjacent .rdata CxImage string is **not** class RTTI for `00416110`. |

---

## Parent merge handoff (not done here)

Per partition map, parent should lockstep for both VAs:

- `VERIFICATION_MATRIX.md`  
- `NAMING_REGISTRY.md` + rename-history  
- systems note (util / math — not skill domain)  
- WORK_QUEUE / RESUME / CHANGE_LOG / progress.json / COVERAGE_LEDGER  

**Terminal:** false (runtime open; dual seal complete for OWN pair).

---

## Process

- OWN VAs only (`0x00416110`, `0x00416160`); no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + disassemble_function + callers/xrefs + assembly_context. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- Clean sources use meaningful names (not Ghidra blank paste).  
- Odd behavior preserved: SEH on trivial dtor; dest generation not copied from src; flag bits skip not copy.  
- `_Inferred` where English unproven; Terminal **false**.

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`
