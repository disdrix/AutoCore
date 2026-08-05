# Dual A/B report — W33-A OWN `aa_0040d6d0` + `aa_0040d870`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W33-A  
**Scope:** VAs `0x0040d6d0`, `0x0040d870` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs. **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** `docs/reconstruction/reviews/WAVE_2026-07-29_wave33_partition_map.md` (W33-A).

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0040d6d0` StdTree_Tidy_FreeHead_Bare_Val12 | **accept-with-gaps** — full erase + free head + null sealed by bytes (false-noreturn decompile truncated); product T + bare/SEH twin rationale residual |
| `aa_0040d870` Class_009c7948_ScalarDeletingDtor | **accept-with-gaps** — scalar ABI/CF/vtbl[0]/complete-then-flags&1 sealed; product class + vtbl[1..2] open |

---

## VA `0x0040d6d0` — sealed facts

1. **Body:** `0x0040d6d0`–`0x0040d6fe` exclusive (**46 B** / `0x2E`; pad `CC`).
2. **ABI:** **ECX=`tree`/map facade** (`head@+4`, `size@+8`); bare **`RET`** (`C3`); void. **No SEH**.
3. **Semantics:** MSVC-style **`_Tree` tidy / free head** (bare twin of W32-B `0x0040d7c0`):
   - **`FUN_0040d700(this, &out, *head, head)`** — full-range erase (W32-C `StdTree_EraseRange_Val12`).
   - **`operator_delete(head)`** — free header (cdecl; `ADD ESP,4`).
   - Null **head** and **size**.
4. **Classification:** worker.
5. **Callers:** Unwind `@009bda70` (`MOV ECX,[EBP-10h]; JMP 0040d6d0`).
6. **Callees:** `FUN_0040d700`, `operator_delete`.
7. **Name:** `StdTree_Tidy_FreeHead_Bare_Val12` (Ghidra `FUN_0040d6d0`; **Inferred**). Peer SEH tidy: `StdTree_Tidy_FreeHead_Val12` @ `0x0040d7c0`.
8. **Decompile ≢ bytes** on epilogue (false noreturn); **bytes win**.  
   Full hex: raw W33-A append (46 B).

### Gaps

- Product/MSVC demangle for map T.  
- Bare vs SEH twin path selection beyond unwind xref.  
- Nested erase-range value-dtor policy (W32-C owned).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d6d0_FUN_0040d6d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Tidy_FreeHead_Bare_Val12.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d6d0.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d6d0_FUN_0040d6d0.md` |
| Function named | `docs/reconstruction/functions/aa_0040d6d0_StdTree_Tidy_FreeHead_Bare_Val12.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d6d0.md` |

---

## VA `0x0040d870` — sealed facts

1. **Body:** `0x0040d870`–`0x0040d88e` exclusive (**30 B** / `0x1E`; pad `CC`).
2. **ABI:** **ECX=`this`**; stack **`flags`**; **`RET 4`** (`C2 04 00`); returns **this** in EAX.
3. **Semantics:** MSVC **scalar-deleting destructor** (vtbl[0] of `PTR_FUN_009c7948`):
   - **`FUN_0040d890(this)`** — derived complete (`Class_009c7948_CompleteDtor`, W32-C).
   - If **`(flags & 1)`**: `operator_delete(this)`.
   - Return `this`.
4. **Classification:** worker.
5. **Callers:** DATA only — `PTR_FUN_009c7948[0]` @ `0x009c7948`.
6. **Callees:** `FUN_0040d890`, `operator_delete`.
7. **Name:** `Class_009c7948_ScalarDeletingDtor` (Ghidra `FUN_0040d870`; **Inferred**). Peer base-family scalar: `Class_009c7938_ScalarDeletingDtor` @ `0x0040d590`.
8. **Vtbl** `0x009c7948`: [0]=`0x0040d870`, [1]=`0x0074d470`, [2]=`0x0074d440` (`read_memory`).  
   Full hex: raw W33-A append (30 B).

### Gaps

- Product/MSVC demangle for derived class.  
- Vtbl slots [1]/[2].  
- Complete nested map (owned W32-C).  
- Runtime / bit-exact / differential.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d870_FUN_0040d870.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Class_009c7948_ScalarDeletingDtor.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0040d870.cpp` |
| Function | `docs/reconstruction/functions/aa_0040d870_FUN_0040d870.md` |
| Function named | `docs/reconstruction/functions/aa_0040d870_Class_009c7948_ScalarDeletingDtor.md` |
| Scratch | `docs/reconstruction/tmp/a_0040d870.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0040d6d0` | Port as **bare tidy**: full-range erase → free header → null head+size. **ECX=tree**, bare RET. Do **not** free the facade/`this`. Do **not** invent SEH here (peer `0040d7c0` has SEH). |
| `0040d870` | Port as **derived scalar-deleting dtor only**. Call complete `Class_009c7948_CompleteDtor`, free host iff `flags&1`, return this, **RET 4**. |
| Pair with | EraseRange `0040d700` (W32-C), SEH tidy `0040d7c0` (W32-B), derived complete `0040d890` (W32-C), base complete `0040d820` (W31-A), base scalar `0040d590` (W31-E), clear `0040d5b0` (W30-P). |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory + xrefs. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product plates; structural `_Inferred` names only.  
- Avoided bare `undefined4` in clean (`uint32_t` / explicit structs).  
- Closes wave33 partition W33-A high-mention nested callees: tidy bare (`FUN_0040d6d0` called from erase-range callers list) and derived scalar (`FUN_0040d870` = vtbl[0] of `009c7948`).
