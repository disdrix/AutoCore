# Dual A/B report — W23-H OWN `aa_004b7150` + `aa_00595230`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-H  
**Scope:** VAs `0x004b7150`, `0x00595230` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callers/callees / `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_004b7150` NDSpecialFX_DeactivateClear_Inferred | **accept** — deactivate/clear CF + thiscall plain ret + layout gates + multi-hit/sound linkage sealed |
| `aa_00595230` CVOGObject_Tick | **accept-with-gaps** — tick phase CF + thiscall/`ret 8` + JustCreated mode-0 linkage sealed; nested pose math / full flags residual |

---

## VA `0x004b7150` — sealed facts

1. **Body:** `0x004b7150`–`0x004b7320` (464 B / `0x1D0`).
2. **ABI:** **`__thiscall`/`__fastcall`** (ECX = SpecialFX host*); **plain `ret`** (`C3`).
3. **Semantics:** Host **deactivate/clear** — not spawn.
4. **Flush:** if `host+0x3c != 0` → `FUN_004b6980` (`NDSpecialFX_FlushStagedMultiHits_Inferred`).
5. **Children list `+0x204`:** optional phys detach when `child+0x90e & 0x80`; then mark all `+0x90e |= 1`, `FUN_00590f00`, clear `child+0x14`.
6. **Sounds list `+0x1f8`:** `FUN_00720d40` + `FUN_007203b0` (MarkStopByName) when size `+0x1fc != 0`.
7. **Callers (4):** `FUN_004b8ed0`, `FUN_004fcc40`, `FUN_00516930`, `FUN_005a8ec0`.
8. **Name:** `NDSpecialFX_DeactivateClear_Inferred` (Ghidra `FUN_004b7150`).
9. **Decompile ≡ entry/exit bytes** for ABI; CF sealed.

### Gaps

- Product / PDB English name.  
- Product types of list payloads.  
- Nested callee duals (`FUN_004b6e00`, `FUN_00590f00`, `FUN_0058e300`).  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_004b7150_FUN_004b7150.md` |
| Annotated | `docs/reconstruction/raw/aa_004b7150_FUN_004b7150.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/NDSpecialFX_DeactivateClear_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004b7150.cpp` |
| Function | `docs/reconstruction/functions/aa_004b7150_FUN_004b7150.md` |
| Function named | `docs/reconstruction/functions/aa_004b7150_NDSpecialFX_DeactivateClear_Inferred.md` |
| Scratch | `docs/reconstruction/tmp/a_004b7150.md` |

---

## VA `0x00595230` — sealed facts

1. **Body:** `0x00595230`–`0x005960fc` (3788 B / `0xECC`).
2. **ABI:** **`__thiscall`** (ECX = CVOGObject*); stack `float dt` + `uint32_t ctx`; **`ret 8`**.
3. **Root phases:** profiler `"Time etc.."` then conditional `"Update Parent Pos"`.
4. **Timers:** `+0x788` phase/reaction; `+0x790` lifetime when `+0x90e & 0x10`.
5. **Just-created:** if `+0x90e & 8` → `FUN_005911b0(0)`; return early if 0 (W22-H sealed callee).
6. **Pose:** gfx body `+0x914` quat→basis (factor **2.0** @ `0x00a10e74`) or parent physics helpers.
7. **Constants:** `DAT_00aaa638` ≈ **1/65535**; `DAT_009d51d8` = **1e-6** zero-geo threshold.
8. **Caller (1):** `FUN_004b8ed0` @ `0x004b909d` (FX owned-object walk).
9. **Name:** `CVOGObject_Tick` (Ghidra `FUN_00595230`).
10. **Decompile ≡ entry/exit bytes** for ABI; phase map sealed from strings + CF.

### Gaps

- Exhaustive soft-flag bit dictionary `@+0x90c..+0x911`.  
- Product meaning of second stack formal.  
- Line-level dual of nested pose formulas.  
- Product/PDB English name.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00595230_CVOGObject_Tick.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00595230_CVOGObject_Tick.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00595230_FUN_00595230.md` |
| Annotated | `docs/reconstruction/raw/aa_00595230_FUN_00595230.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGObject_Tick.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00595230.cpp` |
| Function | `docs/reconstruction/functions/aa_00595230_FUN_00595230.md` |
| Function named | `docs/reconstruction/functions/aa_00595230_CVOGObject_Tick.md` |
| Scratch | `docs/reconstruction/tmp/a_00595230.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `004b7150` | FX teardown helper — honor `+0x3c` flush before list clear; mark destroy bit rather than free children here; stop sounds on `+0x1f8`. |
| `00595230` | Client object tick — preserve `ret 8` and JustCreated mode-0 abort; do not treat as server physics step; nested pose math needs further duals before bit-exact port. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callers).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
