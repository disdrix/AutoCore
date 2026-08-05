# Dual A/B report — `aa_007a4480` NDError_Log

**Date:** 2026-07-29  
**Scope:** OWN ONLY VA `0x007a4480`. Dual A/B + artifacts. Seal VOG_DEBUG_STOP / error helper.  
**Excluded:** Ledgers; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG; parent call-site map.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + basic pcode + complete analysis. No `disassemble_bytes`.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007a4480` NDError_Log (`FUN_007a4480`) | **accept** — flag-gated varargs logger sealed; **not** a hard stop |

---

## Sealed facts

1. **ABI:** `__cdecl` **varargs**. Stack `[esp+4]=enable` (byte), `[esp+8]=fmt`, `[esp+0xC]=first va`. Plain **`RET`** after `ADD ESP,0x800`. **void** return.

2. **Body range:** `0x007a4480`–`0x007a44d0` (~81 B). Dual decompile reps **identical** → no third-rep.

3. **Algorithm (exact):**
   - Allocate `char local[0x800]`.
   - If `enable != 1` **or** `fmt == NULL` → free frame and return (**no callees**).
   - Else `_vsnprintf(local, 0x800, fmt, &va)` then  
     `vog_LogMessage("C:\\vog\\1_code\\vog_14_117_branch\\libND\\NDError.cpp", 0x65, 3, local)`.

4. **Fixed stamp (`read_memory` @ `0x00a97124`):** source path `...\libND\NDError.cpp`; **line 101** (`0x65`); **level 3**.

5. **Callees:** `_vsnprintf` via IAT `0x009c64b4`; `vog_LogMessage`.

6. **`VOG_DEBUG_STOP` is not this function:** it is a **format/message string** at many call sites. With **`enable = 0`** (the common pattern) the body is a **pure no-op**.

7. **Not hard-stop:** no `DebugBreak`, `abort`, exception, or process exit in this VA.

8. **Name:** `NDError_Log` (**INFERRED** from baked path). Deprecate informal “VOG_DEBUG_STOP helper” as product name. Keep stable id `aa_007a4480` / Ghidra `FUN_007a4480`.

9. **Call surface:** ~**1921** xrefs (inventory) — shared diagnostic sink; per-site enable provenance is **parent residual**.

10. **Bytes ≡ decompile** (body hex in raw append / Review A).

---

## Gaps

1. Product English for log **level `3`**.  
2. Exhaustive list of `enable == 1` sites (not OWN).  
3. Runtime live log capture / bit-exact image diff.  
4. Sibling code after `CC` pad @ `0x007a44e0` (separate unit).  
5. CRT `_vsnprintf` truncation/NUL edge cases vs port `string.Format`.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_007a4480_NDError_Log.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_007a4480_NDError_Log.md` | **accept** |

Three-rep: **not required** (decompile A ≡ force decompile B; bytes/pcode agree).

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007a4480_NDError_Log.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007a4480_NDError_Log.md` |
| Function record | `docs/reconstruction/functions/aa_007a4480_FUN_007a4480.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007a4480.cpp` |
| Named clean | `docs/reconstruction/reconstructed-exact/NDError_Log.cpp` |
| Alias clean | `docs/reconstruction/reconstructed-exact/Named_NDError_007a4480.cpp` |
| Raw (+ v2026-07-29 append) | `docs/reconstruction/raw/aa_007a4480_FUN_007a4480.md` |
| Annotated | `docs/reconstruction/raw/aa_007a4480_FUN_007a4480.annotated.md` |
| This report | `docs/agents/task-dual-ab-007a4480-nderror-log-report.md` |

---

## AutoCore impact

- Do **not** implement `FUN_007a4480(0,"VOG_DEBUG_STOP")` as assert-fail / crash / server stop.
- Port logger only when `enable == 1`; exact compare, not C truthiness.
- Preserve 2048-byte format cap if matching truncation.
- Shared sink: avoid inventing per-domain “VOG_DEBUG_STOP” functions for this VA.
