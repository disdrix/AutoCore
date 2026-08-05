# Dual A/B report — W35-J OWN `aa_00964d00` + `aa_004447e0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W35-J  
**Scope:** VAs `0x00964d00`, `0x004447e0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs/assembly_context. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave35_partition_map.md` (W35-J).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_00964d00` PalantirSub10_DestroyOwnedPtrVecAndComUninit | **accept-with-gaps** — stdcall RET 4 + owned-ptr vec destroy + COM Release + `CoUninitialize` sealed (170 B); element product plate (`FUN_00735390`) open |
| `aa_004447e0` Palantir_ScalarDeletingDtor | **accept** — scalar deleting wrapper sealed (30 B); vtbl[0] + complete dtor handoff + `flags&1` free |

---

## VA `0x00964d00` — sealed facts

1. **Body:** `0x00964d00`–`0x00964DAA` exclusive (**170 B** / `0xAA`; pad `CC` then next @ `0x00964DB0`).
2. **ABI:** **stdcall** 1 stack arg (`self*`); **`RET 4`** (`C2 04 00`); void. SEH `LAB_009ab766`. **Not** thiscall; **not** cdecl (corrects W34-K “cdecl” note).
3. **Semantics:**
   - Walk owned-pointer vector `[begin,end)` at `self+4/+8`; stride 4.
   - Per non-null element: `FUN_00735390(elem)` then `operator_delete(elem)`.
   - If `begin != 0`: `operator_delete(begin)`.
   - Zero triad `+4/+8/+0xC`.
   - If COM at `+0x10`: **Release** via vtbl+8; null COM.
   - **`CoUninitialize`** via IAT `0x009c697c` (`PTR_CoUninitialize_009c697c`).
   - Zero triad again (MSVC residual; second free path dead).
4. **Layout (`self` = Palantir+0x10):**

| Off | Role |
|-----|------|
| +0x00 | unused in body |
| +0x04 | `void** begin` |
| +0x08 | `void** end` |
| +0x0C | `void** capEnd` |
| +0x10 | COM iface* |

5. **Classification:** worker.
6. **Callers (3):** `Palantir_CompleteDtor` @ `0x0075438a` (`ADD ESI,0x10; PUSH ESI; CALL`); Unwind `@009afcf6`, `@009afd32` (same `host+0x10`).
7. **Callees:** `FUN_00735390` (element complete dtor — **unowned**), `operator_delete`, `CoUninitialize`.
8. **Name:** `PalantirSub10_DestroyOwnedPtrVecAndComUninit` (Ghidra `FUN_00964d00`; **Inferred** structural + Palantir nest).
9. **Decompile ≢ bytes** on free/null control flow and calling convention; **bytes win**. Full hex: raw W35-J append.

### Gaps

- Element product dual (`FUN_00735390` — two strings + COM@+0x48 observed only).  
- `self+0x00` field role; matching ctor / `CoInitialize*` balance.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.md` |
| Annotated | `docs/reconstruction/raw/aa_00964d00_FUN_00964d00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PalantirSub10_DestroyOwnedPtrVecAndComUninit.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00964d00.cpp` |
| Function | `docs/reconstruction/functions/aa_00964d00_FUN_00964d00.md` |
| Function named | `docs/reconstruction/functions/aa_00964d00_PalantirSub10_DestroyOwnedPtrVecAndComUninit.md` |
| Scratch | `docs/reconstruction/tmp/a_00964d00.md` |

---

## VA `0x004447e0` — sealed facts

1. **Body:** `0x004447e0`–`0x004447FE` exclusive (**30 B** / `0x1E`; pad `CC CC` then next @ `0x00444800`).
2. **ABI:** **ECX=`Palantir* this`** (`MOV ESI,ECX`); stack **`flags:byte`**; **`RET 4`**; returns **this** in EAX.
3. **Semantics (scalar deleting dtor):**
   - `Palantir_CompleteDtor(this)` — `CALL 0x00754320` (W34-K dualed; members/nested/globals; **no** free host).
   - If `flags & 1`: `operator_delete(this)`.
   - Return `this`.
4. **Vtbl:** `PTR_FUN_00a9f76c[0] = 0x004447e0`; `[1] = 0x00754480` (Palantir::ResetDevice peer — product class sealed W34-K).
5. **Classification:** worker.
6. **Callers:** data xref only (vtbl slot); no direct code CALL sites.
7. **Callees:** `FUN_00754320`, `operator_delete`.
8. **Name:** `Palantir_ScalarDeletingDtor` (Ghidra `FUN_004447e0`; **Inferred** + vtbl[0]).
9. **Decompile ≢ bytes** on explicit ESI/this plumbing; **bytes win**. Full hex: raw W35-J append.

### Gaps

- Exact MSVC demangle plate (naming-only).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004447e0_Palantir_ScalarDeletingDtor.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004447e0_Palantir_ScalarDeletingDtor.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004447e0_FUN_004447e0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Palantir_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004447e0.cpp` |
| Function | `docs/reconstruction/functions/aa_004447e0_FUN_004447e0.md` |
| Function named | `docs/reconstruction/functions/aa_004447e0_Palantir_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_004447e0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `00964d00` | Port as **stdcall** nested tidy on **Palantir+0x10**: destroy owned-ptr vector elements via residual element complete dtor + delete; free buffer; zero triad; **Release** COM at +0x10; **`CoUninitialize`**. Do **not** use thiscall/cdecl; do **not** free the subobject itself; do **not** skip CoUninit. Element dual remains residual (`FUN_00735390`). |
| `004447e0` | Port as **scalar deleting dtor** only: `Palantir_CompleteDtor(this)` then `if (flags&1) operator_delete(this); return this`. **ECX=this**, **RET 4**. Member teardown stays in complete dtor; free-this is **only** here. |

Shared Palantir teardown chain (W34-K + W35-J):

| Piece | VA / role |
|-------|-----------|
| Scalar deleting dtor | `0x004447e0` — this dual (**accept**) |
| Complete dtor | `0x00754320` — W34-K (**accept-with-gaps**) |
| Path shell tidy helper | `0x00444810` — W34-K (**accept**) |
| Nested `+0x10` tidy | `0x00964d00` — this dual (**accept-with-gaps**) |
| Nested `+0x30` tidy | `0x0075d8e0` — still residual |
| Element of `+0x10` vec | `0x00735390` — still residual |

Closes W34-K nested residual **FUN_00964d00** and seals the scalar free wrapper **FUN_004447e0** under Palantir teardown.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence — Palantir class from W34-K vtbl peer; subobject name structural.  
- Corrected parent-wave “cdecl” mislabel for `0x00964d00` → **stdcall RET 4**.
