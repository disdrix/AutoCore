# Dual A/B report — W32-N OWN `aa_0043ecf0` + `aa_0043e7f0`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W32-N  
**Scope:** VAs `0x0043ecf0`, `0x0043e7f0` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` / `batch_decompile` + `read_memory` + `get_function_by_address` + `analyze_function_complete` (+ callers/callees/xrefs). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.  
**Partition:** wave32.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043ecf0` PodU32U8_CopyIfNonNull | **accept** — EAX/ECX leaf store + 5-byte write + sole-caller seal (15 B) |
| `aa_0043e7f0` GuardedVector_PushBackLocked_Stride2_U32U8 | **accept** — EDI/stack ABI + optional CS + nested Stride2 U32U8 push sealed (94 B) |

---

## VA `0x0043ecf0` — sealed facts

1. **Body:** `0x0043ecf0`–`0x0043ecfe` (**15 B** / `0x0F`; pad `CC` then next unit).
2. **ABI:** **EAX=dest** (null-checked), **ECX=src** (`const PodU32U8*`); plain **`RET`**. Register dual (decompiler `__fastcall` + phantom `in_EAX`).
3. **Semantics:** Null-safe POD store:
   - If `EAX == 0` → return (no write).
   - Else copy **dword** from `[ECX]` then **byte** from `[ECX+4]` to dest.
   - Write width **5 B**; 8-byte slot trailing 3 B unwritten.
4. **Twin:** `FUN_0043ece0` bit-identical except second field: dword (`8B/89`) vs byte (`8A/88`).
5. **Classification:** **leaf** — no callees.
6. **Callers (1):** `FUN_0043e9e0` @ `0x0043ea3f` (`GuardedVector_PushBack_Stride2_U32U8`, W31-J).
7. **Name:** `PodU32U8_CopyIfNonNull` (Ghidra `FUN_0043ecf0`; **Inferred** structural; store helper residual from W31-J).
8. **Decompile ≡ raw CF**; **bytes win** on dual-register ABI. Full hex: `85c0740a8b1189108a4904884804c3`.

### Gaps

- Product/PDB element English.  
- Runtime / bit-exact.  
- Slot padding residual (by design).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043ecf0_PodU32U8_CopyIfNonNull.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043ecf0_PodU32U8_CopyIfNonNull.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043ecf0_FUN_0043ecf0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PodU32U8_CopyIfNonNull.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043ecf0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043ecf0_FUN_0043ecf0.md` |
| Function named | `docs/reconstruction/functions/aa_0043ecf0_PodU32U8_CopyIfNonNull.md` |
| Scratch | `docs/reconstruction/tmp/a_0043ecf0.md` |

---

## VA `0x0043e7f0` — sealed facts

1. **Body:** `0x0043e7f0`–`0x0043e84d` (**94 B** / `0x5E`; pad `CC CC` then next unit).
2. **ABI:** **EDI=container** (`unaff_EDI`); stack **1** formal (`const PodU32U8* value`); **`RET 0x4`**. Not thiscall.
3. **Semantics:** Optional CS wrapper around `GuardedVector_PushBack_Stride2_U32U8` (`FUN_0043e9e0`):  
   - If `container+0x2c != 0` → `EnterCriticalSection(container+0x14)`.  
   - `EAX = EDI`; call PushBack_Stride2_U32U8(value*).  
   - If locked → LeaveCS. SEH `LAB_009be0c8` (state −1→0 around push).
4. **Layout:** CS `+0x14`, lock-enable `char +0x2c` (family: PushBackLocked / AssignTo / Resize wrappers).
5. **Classification:** worker — callees EnterCS, `FUN_0043e9e0`, LeaveCS.
6. **Callers (8 xrefs / 6 fns):** `NDResourceCache_LookupOrCreate` @ `0075dda5`; `FUN_00970b20` @ `00970b49`; `FUN_00970b60` @ `00970b89`; `FUN_0075de80` @ `0075df71`/`0075e140`/`0075e1b4`; `FUN_0075d3c0` @ `0075d446`; `FUN_00970e50` @ `00970f3f`.
7. **Name:** `GuardedVector_PushBackLocked_Stride2_U32U8` (Ghidra `FUN_0043e7f0`; **Inferred** structural; bit-twin of W30-D `GuardedVector_PushBackLocked` with nested W31-J body).
8. **Decompile ≡ raw CF**; **bytes win** on EDI formal / leave-path alias. Full hex in raw W32-N append. Twin of `0043c4f0` differs only in nested `E8` rel32 (`0043e9e0` vs `0043c830`).

### Gaps

- Product/PDB class English.  
- Runtime / bit-exact under contended CS.  
- Nested push internals free is W31-J (not re-owned).

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043e7f0_GuardedVector_PushBackLocked_Stride2_U32U8.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_0043e7f0_GuardedVector_PushBackLocked_Stride2_U32U8.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043e7f0_FUN_0043e7f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0043e7f0_FUN_0043e7f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_PushBackLocked_Stride2_U32U8.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043e7f0.cpp` |
| Function | `docs/reconstruction/functions/aa_0043e7f0_FUN_0043e7f0.md` |
| Function named | `docs/reconstruction/functions/aa_0043e7f0_GuardedVector_PushBackLocked_Stride2_U32U8.md` |
| Scratch | `docs/reconstruction/tmp/a_0043e7f0.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043ecf0` | Null-safe **u32+u8** store: **EAX=dest**, **ECX=src**, plain **RET**. Do **not** substitute twin `0043ece0` (u32×2). Null dest → skip write; push caller still `size++`. |
| `0043e7f0` | Locked stride-2 U32U8 push: **EDI=container**, stack `value*`, **RET 4**. Optional CS at `+0x14` gated by `+0x2c`, then unlocked `GuardedVector_PushBack_Stride2_U32U8` (EAX contract). Do not invent thiscall. Do not swap nested body with dword `PushBackLocked` (`0043c4f0` → `0043c830`). |

Shared: closes W31-J residuals (store helper free + CS wrapper free). Together they complete the locked U32U8 push path: wrapper → unlocked stride-2 push → PodU32U8 store.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + read_memory + function/xref helpers. **No** `disassemble_bytes`.  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only (`PodU32U8_*` / `GuardedVector_*` family from W28–W31 duals).  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit POD + header structs).
