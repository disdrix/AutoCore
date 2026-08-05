# Dual A/B report — W23-R OWN `aa_005cc460` + `aa_00578550`

**Date:** 2026-07-29  
**Agent:** OWN-ONLY dual W23-R  
**Scope:** VAs `0x005cc460`, `0x00578550` only. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / parent ledger.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ `get_function_by_address`). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_005cc460` Object_IsLevelLessThan6 | **accept** — stdcall/`ret 4` + null-safe MI GetLevel (vtbl+`0x27c`) + threshold **&lt; 6** sealed |
| `aa_00578550` CVOGHBBase_AppendRemainingText | **accept-with-gaps** — thiscall/`ret 0x10` + enable/counter gates + day/hr/min/sec cascade sealed; quantize leaf formulas residual |

---

## VA `0x005cc460` — sealed facts

1. **Body:** `0x005cc460`–`0x005cc488` (40 B / `0x28`).
2. **ABI:** **stdcall** (`ret 4` / `C2 04 00`); stack `obj*`; AL = bool.
3. **Semantics:** null-safe **IsLevelLessThan6** via MI this-adjust + **vtbl+0x27c** (GetLevel).
4. **Compare:** `level < 6` → 1; else 0 (including null).
5. **Callees:** indirect GetLevel only (leaf otherwise).
6. **Caller (1 named):** `CVOGHBAICreatureBase_DoVehiclePursue` @ `0x005cfb60` (xref `0x005cff6c`).
7. **Correction:** prior pursue plate “heading” label is **wrong** — pure level predicate.
8. **Name:** `Object_IsLevelLessThan6` (Ghidra `FUN_005cc460`).
9. **Decompile ≡ bytes** for CF + ABI.

### Gaps

- Product / PDB English name.  
- Design rationale for threshold 6.  
- Runtime / bit-exact.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005cc460_Object_IsLevelLessThan6.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005cc460_Object_IsLevelLessThan6.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.md` |
| Annotated | `docs/reconstruction/raw/aa_005cc460_FUN_005cc460.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Object_IsLevelLessThan6.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_005cc460.cpp` |
| Function | `docs/reconstruction/functions/aa_005cc460_FUN_005cc460.md` |
| Function named | `docs/reconstruction/functions/aa_005cc460_Object_IsLevelLessThan6.md` |
| Scratch | `docs/reconstruction/tmp/a_005cc460.md` |

---

## VA `0x00578550` — sealed facts

1. **Body:** `0x00578550`–`0x005786ee` (414 B / `0x19E`).
2. **ABI:** **`__thiscall`** (ECX = `CVOGHBBase*`); stack `(char* dest, unused, unused, char enable)`; **`ret 0x10`**; AL = 1 appended / 0 skip.
3. **Gates:** `enable != 0` **and** `nPeriodCounter (+0x10) != -1000`.
4. **Core:** `CVOGHBBase_GetRemainingSeconds` → unit cascade → localize unit + `"Remaining"` → `sprintf` → **append** onto dest.
5. **Thresholds (seconds):** `86400` days / `3600` hrs / `60` min / else sec.
6. **Scales:** `1/86400` @ `0x009d3fc0`, `1/3600` @ `0x009d3fbc`, `1/60` @ `0x00aaa9ec`.
7. **Quantize:** days → `FUN_00578140`; hrs/min → `FUN_00412c60`; sec → `%.0f`.
8. **Units:** `"days"` / `"hrs"` / `"min"` / `"sec"` string keys + loc.
9. **Thunk:** `FUN_005786f0` always passes enable=1.
10. **Name:** `CVOGHBBase_AppendRemainingText` (Ghidra `FUN_00578550`).
11. **Decompile ≡ entry/exit bytes** for ABI + gates; cascade sealed via float/string VAs.

### Gaps

- Product / PDB English name.  
- Semantic of two body-dead stack formals.  
- Exact quantize leaf formulas (`FUN_00412c60` / `FUN_00578140`).  
- Runtime / bit-exact tooltip golden.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_00578550_CVOGHBBase_AppendRemainingText.md` | **accept-with-gaps** |
| B | `docs/reconstruction/reviews/B_aa_00578550_CVOGHBBase_AppendRemainingText.md` | **accept-with-gaps** |

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_00578550_FUN_00578550.md` |
| Annotated | `docs/reconstruction/raw/aa_00578550_FUN_00578550.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/CVOGHBBase_AppendRemainingText.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00578550.cpp` |
| Function | `docs/reconstruction/functions/aa_00578550_FUN_00578550.md` |
| Function named | `docs/reconstruction/functions/aa_00578550_CVOGHBBase_AppendRemainingText.md` |
| Scratch | `docs/reconstruction/tmp/a_00578550.md` |

---

## AutoCore impact

| Unit | Port note |
|------|-----------|
| `005cc460` | Low-level pursue gate only — treat as **level &lt; 6** bool; do **not** interpret as heading/angle; preserve stdcall. |
| `00578550` | Client tooltip append — honor enable + **counter==-1000** skip; unit cascade thresholds exclusive at 86400/3600/60; **append** not strcpy; quantize leaves need further dual before pixel-perfect UI. |

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ get_function_by_address).  
- Dual A (fidelity) + B (adversarial) both filed per VA.
