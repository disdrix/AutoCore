# Dual A/B report — W18-M OWN-ONLY

**Date:** 2026-07-29  
**Agent:** W18-M  
**Workspace:** `C:\Users\josh\Documents\GitHub\AutoCore`  
**Module:** `autoassault.exe` base `0x400000`  
**OWN VAs:** `0x007227e0`, `0x0040d9c0`  
**Excluded:** Launcher; parent ledger edits (`COVERAGE_LEDGER`, `WORK_QUEUE`, `RESUME`, `ACTIVE_WORK`, `CHANGE_LOG`, partition map).  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + basic pcode (007227e0) + `analyze_function_complete` + `get_assembly_context`. **No** `disassemble_bytes`.

---

## Verdicts

| Unit | VA | Inferred name | Verdict |
|------|-----|---------------|---------|
| `aa_007227e0` | `0x007227e0`–`0x00722821` | `Audio_LinearGainToMilliBels` | **accept-with-gaps** |
| `aa_0040d9c0` | `0x0040d9c0`–`0x0040da23` | `OwnedPtrTable_Clear` | **accept-with-gaps** |

Three-rep: **not required** for either (decompile ≡ force_decompile). For `0x007227e0`, dual text agrees but **main expression is wrong** — sealed from FPU bytes instead.

---

## `aa_007227e0` — Audio_LinearGainToMilliBels

### Sealed facts

1. **ABI:** `__stdcall` float arg; **`RET 4`**; return **ST0**; **leaf**.
2. **Clamps:** `x<=0 → −10000.f` (`DAT_00aaa5d8`); `x>=1 → 0.f` (`g_flZero`).
3. **Main path:** `1/x` then **`FLDLG2` + `FYL2X` + `FMUL −2000.0`** → **`2000 * log10(x)`** (millibels of amplitude gain).
4. **Decompiler rejected:** `0.30103 * (1/x) * (−2000)` is linear and incorrect.
5. **Constants:** `_DAT_00aaa5d0 = −2000.0` (double); `g_flOne=1`; `g_flZero=0`.
6. **Callers (22 xrefs):** include `Client_PlayNamedInterfaceSound`; often `FSTP [obj+0x1b0]`.
7. **Dual decompile identical** (text); body hex sealed in raw append.

### Gaps

- Studio symbol (name **INFERRED**).
- Product English for destination field `+0x1b0`.
- Runtime ST0 capture for sample inputs.

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_007227e0_FUN_007227e0.md` |
| Annotated | `docs/reconstruction/raw/aa_007227e0_FUN_007227e0.annotated.md` |
| Function record | `docs/reconstruction/functions/aa_007227e0_FUN_007227e0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007227e0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/Audio_LinearGainToMilliBels.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_007227e0_Audio_LinearGainToMilliBels.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007227e0_Audio_LinearGainToMilliBels.md` |

---

## `aa_0040d9c0` — OwnedPtrTable_Clear

### Sealed facts

1. **ABI:** this in **ESI**; plain **RET**; no stack args.
2. **Callee:** `operator_delete` only (**returns** — ignore Ghidra noreturn).
3. **Algorithm:** spin `+0x10`→0 (null `+0x0C` on final tick); delete each `data[i]`; delete buffer; zero `+0x08`/`+0x04`.
4. **Layout:** `+4 data`, `+8 count`, `+0x0C cached`, `+0x10 liveCount`.
5. **Thunk:** `0x0040fd50` JMP; **wrapper:** `FUN_0040d910` SEH shell.
6. **Xrefs:** 19; named include `NDResourceCache_LookupOrCreate`.
7. **Dual decompile identical**; body hex sealed in raw append.

### Gaps

- Studio / RTTI type name.
- Whether elements need a virtual dtor (body never calls one).
- Semantic of live-count spin vs assign-zero.

### Files

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0040d9c0_FUN_0040d9c0.md` |
| Annotated | `docs/reconstruction/raw/aa_0040d9c0_FUN_0040d9c0.annotated.md` |
| Function record | `docs/reconstruction/functions/aa_0040d9c0_FUN_0040d9c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_0040d9c0.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/OwnedPtrTable_Clear.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0040d9c0_OwnedPtrTable_Clear.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0040d9c0_OwnedPtrTable_Clear.md` |

---

## AutoCore impact (brief)

- **Audio gain ports:** use `2000*log10` with clamps; never the decompiler linear product.
- **Container teardown:** ESI this; free elements then buffer; do not invent capacity semantics at `+0x0C`.
