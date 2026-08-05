# OWN-ONLY dual agent report — W25-M

**Date:** 2026-07-29  
**Agent:** W25-M OWN-ONLY  
**Scope:** OWN ONLY VAs `0x005ffc90`, `0x004cbfc0`. Dual A/B + artifacts.  
**Excluded:** Launcher; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG / COVERAGE_LEDGER / progress / inventory / other parent ledgers.  
**Ghidra:** `decompile_function` + `analyze_function_complete` + `read_memory` (+ callee decompiles). **No** `disassemble_bytes`.  
**Image:** `autoassault.exe` base `0x400000`.

---

## Verdict per VA

| Unit | Verdict |
|------|---------|
| `aa_005ffc90` hkAnalogDI_CopyStringByKey | **accept** — thiscall table@+8, key lookup → strncpy → strlen / miss→0, ret 0xc sealed |
| `aa_004cbfc0` Vector_InsertN_0x10 | **accept** — MSVC vector insert stride 0x10, layout +4/+8/+0xc, 1.5× grow, throw string, ret 0xc sealed |

---

## `aa_005ffc90` — hkAnalogDI_CopyStringByKey

### Sealed facts

1. **Body:** `0x005ffc90`–`0x005ffce5` (85 B).
2. **ABI:** **thiscall** ECX=`hkAnalogDI*`; stack `key`, `dst`, `maxlen`; **`ret 0xc`**; EAX = strlen(src) or **0**.
3. **Table:** `this+8` open-address hash (`FUN_00650290` / `FUN_0065ad10` / `FUN_0065acb0`).
4. **Hit path:** value string* → `FUN_00638040` (strncpy) → `FUN_00638060` (strlen src).
5. **Miss path:** EAX=0; dst not written.
6. **Caller (1):** `hkAnalogDI_vtbl1` `0x005ffd80` @ `0x005ffd97` (flag `*(byte*)(this+5)&0x80`).
7. **Name:** `hkAnalogDI_CopyStringByKey` (Ghidra `FUN_005ffc90`).
8. **Decompile gap sealed:** free-function surface hides thiscall — bytes restore it.

### Gaps

1. Product English for key domain.  
2. Full hash-table object layout beyond fields used here.  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| Review B | `docs/reconstruction/reviews/B_aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| Function record | `docs/reconstruction/functions/aa_005ffc90_hkAnalogDI_CopyStringByKey.md` |
| Scaffold record | `docs/reconstruction/functions/aa_005ffc90_FUN_005ffc90.md` |
| Clean | `docs/reconstruction/reconstructed-exact/hkAnalogDI_CopyStringByKey.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_005ffc90.cpp` |
| Raw | `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.md` |
| Annotated | `docs/reconstruction/raw/aa_005ffc90_FUN_005ffc90.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_005ffc90.md` |

---

## `aa_004cbfc0` — Vector_InsertN_0x10

### Sealed facts

1. **Body:** `0x004cbfc0`–`0x004cc21c` (~0x25C B).
2. **ABI:** **thiscall** ECX=vector*; stack `insertAt`, `count`, `value*`; **`ret 0xc`**; void.
3. **Layout:** begin `+4`, end `+8`, capacity end `+0xc`; element **0x10** (`>>4` / `*0x10`).
4. **Value:** 4-dword stack snapshot of `*value`.
5. **Grow:** `cap + (cap>>1)` with forced fit; `operator_new(new_cap*0x10)`; POD relocate via `FUN_005dd920` / fill `FUN_00608720`.
6. **Overflow:** `FUN_004cb1d0` throws **`"vector<T> too long"`**.
7. **Callers:** `FUN_006061e0` (CVOGHBWakeupSkill_ctor ×2), `FUN_004cc470`, `FUN_005de1b0`, `FUN_005dcc40`.
8. **Name:** `Vector_InsertN_0x10` (Ghidra `FUN_004cbfc0`).

### Gaps

1. Product element type English (often TFID-sized at sites).  
2. Named duals for shift helpers (`004cb2e0` / `0051b6e0` / `0041d5a0`).  
3. Runtime / bit-exact / differential — open.

### Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A | `docs/reconstruction/reviews/A_aa_004cbfc0_Vector_InsertN_0x10.md` | **accept** |
| B | `docs/reconstruction/reviews/B_aa_004cbfc0_Vector_InsertN_0x10.md` | **accept** |

### Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_004cbfc0_Vector_InsertN_0x10.md` |
| Review B | `docs/reconstruction/reviews/B_aa_004cbfc0_Vector_InsertN_0x10.md` |
| Function record | `docs/reconstruction/functions/aa_004cbfc0_Vector_InsertN_0x10.md` |
| Scaffold record | `docs/reconstruction/functions/aa_004cbfc0_FUN_004cbfc0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Vector_InsertN_0x10.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_004cbfc0.cpp` |
| Raw | `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.md` |
| Annotated | `docs/reconstruction/raw/aa_004cbfc0_FUN_004cbfc0.annotated.md` |
| Scratch | `docs/reconstruction/tmp/a_004cbfc0.md` |

Absolute root: `C:\Users\josh\Documents\GitHub\AutoCore\`

---

## AutoCore impact

### hkAnalogDI_CopyStringByKey (`0x005ffc90`)

- Client/Havok DI path: when porting analog DI vtbl slot 1, implement flag gate then **key→string table @ +8** copy.
- Return is **source strlen**, not bytes written; miss returns **0** without mutating dst.

### Vector_InsertN_0x10 (`0x004cbfc0`)

- Shared 16-byte vector insert — preserve **+4/+8/+0xc** layout (leading +0 unused by this unit), **0x10** stride, **1.5×** grow, max **0x0fffffff** elements.
- Used by HB wake-up skill construction and other POD-16 vectors; do not assume TFID exclusively without per-site evidence.

---

## Process

- OWN VAs only; no Launcher; no parent ledger edits.  
- Seal tools: decompile + analyze_function_complete + read_memory (+ callee decompiles).  
- Dual A (fidelity) + B (adversarial) both filed per VA.  
- Existing 2026-07-23 scaffolds preserved via append (raw) / replace (annotated/clean/function) to sealed state.
