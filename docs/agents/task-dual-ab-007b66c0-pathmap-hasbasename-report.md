# Dual A/B report — `aa_007b66c0` PathMap_HasBasename (`FUN_007b66c0`)

**Date:** 2026-07-29  
**Agent:** W17-M OWN-ONLY  
**Scope:** OWN ONLY VA `0x007b66c0`. Dual A/B + artifacts.  
**Excluded:** Ledgers; WORK_QUEUE / RESUME / ACTIVE_WORK / CHANGE_LOG; parent call-site map ownership.  
**Ghidra:** `decompile_function` + `force_decompile` + `read_memory` + callees/callers/xrefs. No `disassemble_bytes`. No Launcher.

---

## Verdict

| Unit | Verdict |
|------|---------|
| `aa_007b66c0` `FUN_007b66c0` (PathMap_HasBasename INFERRED descriptive) | **accept** — flag-gated basename token lookup sealed |

---

## Sealed facts

1. **ABI:** path C-string in **EAX**; context object on stack; epilogue **`RET 4`**; return **bool in AL** (0/1).

2. **Body range:** `0x007b66c0`–`0x007b6728` (**104 B**). Dual decompile reps **identical** → no third-rep.

3. **Algorithm (exact):**
   - If `(*(u8*)(ctx+4) & 2) == 0` → return 0.
   - `strrchr(path,'\\')` and `strrchr(path,'/')` (IAT `0x009c662c`).
   - Basename = char after later separator, or full path if none.
   - `FUN_00989e00(this=0x00d1eac8, &token, basename)`.
   - `hit = (*(ctx+0xc))->vtbl+0x14(&token)`; return `hit ? 1 : 0`.

4. **Callees:** `strrchr`, `FUN_00989e00`, virtual map lookup `+0x14`.

5. **Call surface:** inventory **19** xrefs — interface/XML path loaders (`NDUIWindow_LoadInterfaceFile`, `NDXml_LoadDocumentFromPath`, …).

6. **Not** filesystem exists check (sibling `PathFileExistsA` paths live in callers).

7. **Bytes ≡ decompile** (body hex in raw append / Review A).

8. **Name:** keep `FUN_007b66c0` / `aa_007b66c0`. Descriptive INFERRED only: PathMap_HasBasename. Deprecate legacy CVOGCreature scaffold alias.

---

## Gaps

1. Product type of `ctx` / map object / method `+0x14`.  
2. Flag bit-2 product English.  
3. Token type from string pool intern.  
4. Runtime hit/miss capture.  
5. Bit-exact image diff.

---

## Dual A/B

| Review | Path | Verdict |
|---|---|---|
| A (fidelity) | `docs/reconstruction/reviews/A_aa_007b66c0_PathMap_HasBasename.md` | **accept** |
| B (adversarial) | `docs/reconstruction/reviews/B_aa_007b66c0_PathMap_HasBasename.md` | **accept** |

Three-rep: **not required**.

---

## Files

| Kind | Path |
|------|------|
| Review A | `docs/reconstruction/reviews/A_aa_007b66c0_PathMap_HasBasename.md` |
| Review B | `docs/reconstruction/reviews/B_aa_007b66c0_PathMap_HasBasename.md` |
| Function record | `docs/reconstruction/functions/aa_007b66c0_FUN_007b66c0.md` |
| Clean | `docs/reconstruction/reconstructed-exact/FUN_007b66c0.cpp` |
| Raw (+ v2026-07-29 append) | `docs/reconstruction/raw/aa_007b66c0_FUN_007b66c0.md` |
| Annotated | `docs/reconstruction/raw/aa_007b66c0_FUN_007b66c0.annotated.md` |
| This report | `docs/agents/task-dual-ab-007b66c0-pathmap-hasbasename-report.md` |

---

## AutoCore impact

- Port as **token/map membership** after basename extract, not `File.Exists`.
- Honor flag **bit mask 2** exactly.
- Preserve last-separator basename (`\` vs `/` later-wins).
- Do not invent retail C++ name without new evidence.
