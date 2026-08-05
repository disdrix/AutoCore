# Dual A/B report — W26-G OWN `aa_0043c730` + `aa_004b6a80`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W26-G  
**Scope:** VAs `0x0043c730`, `0x004b6a80` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_0043c730` GuardedVector_CopyAssign | **accept-with-gaps** — EAX/EDI ABI + self/empty/fit/grow CF sealed; nested helper free residual |
| `aa_004b6a80` NDSpecialFX_List1e0_AnyFlag10 | **accept** — leaf list probe CF/ABI/offsets + type-4 re-enter role sealed |

---

## VA `0x0043c730` — sealed facts

1. **Body:** `0x0043c730`–`0x0043c7d6` (**167 B**; pad `CC` after last RET).
2. **ABI:** custom — **EAX=source**, **EDI=dest**; no stack formals; frame `SUB/ADD ESP,8`; plain `RET`.
3. **Semantics:** Self-assign no-op; empty source clears dest (`FUN_0040d9c0`, ESI=dest); else `source.size <= dest.size` → fit (`FUN_0043ce90`+`FUN_0043c8c0`) else grow (`FUN_0043ce90`+`FUN_0043cec0`).
4. **Layout:** `+0x04` slots, `+0x08` capacity, `+0x0c` begin, `+0x10` size (ring/vector header under GuardedVector CS at `+0x14`).
5. **Classification:** worker — callees `FUN_0040d9c0`, `FUN_0043ce90`, `FUN_0043c8c0`, `FUN_0043cec0`.
6. **Callers (1):** `FUN_0043c5f0` / `GuardedVector_AssignTo` only (xref `0x0043c62c`).
7. **Name:** `GuardedVector_CopyAssign` (Ghidra `FUN_0043c730`; **Inferred** from parent dual).
8. **Decompile ≡ bytes** for CF (live 2026-07-29 ≡ raw 2026-07-23).

### Gaps

- Product/PDB class English.  
- Nested fit/grow free arithmetic (`0043c8c0` / `0043cec0` / `0043cf40`) — not OWN.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_0043c730_GuardedVector_CopyAssign.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_0043c730_GuardedVector_CopyAssign.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0043c730_FUN_0043c730.md` |
| Annotated | `docs/reconstruction/raw/aa_0043c730_FUN_0043c730.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/GuardedVector_CopyAssign.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0043c730.cpp` |
| Function | `docs/reconstruction/functions/aa_0043c730_FUN_0043c730.md` |
| Function named | `docs/reconstruction/functions/aa_0043c730_GuardedVector_CopyAssign.md` |
| Scratch | `docs/reconstruction/tmp/a_0043c730.md` |

---

## VA `0x004b6a80` — sealed facts

1. **Body:** `0x004b6a80`–`0x004b6aa7` (**40 B**; pad `CC` after last RET).
2. **ABI:** **ECX=host**; no stack formals; plain `RET`; **AL** = 0|1.
3. **Semantics:** Walk circular list sentinel at `host+0x1e0`; for each node payload (`node[2]`), if `*(byte*)(payload+0x989) & 0x10` → return 1; else 0.
4. **Classification:** **leaf** (0 callees).
5. **Callers (2):** `FUN_004b8ed0` (`NDSpecialFX_HostTick_Inferred`) case 4 re-enter; `FUN_004ba0a0` case 4 keep-active.
6. **Name:** `NDSpecialFX_List1e0_AnyFlag10` (Ghidra `FUN_004b6a80`; **Inferred** structural).
7. **Decompile ≡ bytes** for full body (live 2026-07-29 ≡ raw 2026-07-23).  
   Full hex: `8b89e00100008b013bc1567414b210908b7008849689090000750a8b003bc175ef32c05ec3b0015ec3`

### Gaps

- Product English for flag `+0x989` bit `0x10` / list element type.  
- Runtime golden.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b6a80_FUN_004b6a80.md` |
| Annotated | `docs/reconstruction/raw/aa_004b6a80_FUN_004b6a80.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_List1e0_AnyFlag10.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b6a80.cpp` |
| Function | `docs/reconstruction/functions/aa_004b6a80_FUN_004b6a80.md` |
| Function named | `docs/reconstruction/functions/aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` |
| Scratch | `docs/reconstruction/tmp/a_004b6a80.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `0043c730` | Factory-list snapshots under `GuardedVector_AssignTo` must use the same ring header (`+0x04/+0x08/+0x0c/+0x10`) assign rules: self no-op, empty clears dest, fit vs grow. Do not invent a plain `memcpy` vector assign without ring begin/size. Nested free helpers remain residual. |
| `004b6a80` | Type-4 NDSpecialFX host tick must consult residual list `+0x1e0` flag `+0x989 bit 0x10` before deactivate. Closes open residual from W24-C HostTick dual for this probe. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers/callees).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Scaffold raw bodies preserved; re-verify **appended** only.  
- No invented product names without evidence; `_Inferred` structural names only.  
- Avoided bare `undefined4` in clean (used `uint32_t` / explicit structs).
