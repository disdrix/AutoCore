# Review A (reconstruction fidelity): `aa_00971480` AssPreloader_DrainSuccessResultsAndTally_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00971480` |
| **VA** | `0x00971480`–`0x00971637` (**439 B**) |
| **Canonical name** | `AssPreloader_DrainSuccessResultsAndTally_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_00971480` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-B) |
| **Counterpart** | `reviews/B_aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` |
| **System** | assPreloader / client asset preload |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (439 B) + `analyze_function_complete` + callers/xrefs; nested family duals W21-N / W31-K / W32-K / W36-E |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra decompile + `read_memory` only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Drain AssPreloader success results vector (`host+0x4c`): tally newly cached assets by extension bucket, or log/drop already-loaded duplicates; optional tree dump.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00971480_FUN_00971480.md` (+ W37-B live seal) |
| Annotated | `docs/reconstruction/raw/aa_00971480_FUN_00971480.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPreloader_DrainSuccessResultsAndTally_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00971480.cpp` |
| Function record | `docs/reconstruction/functions/aa_00971480_FUN_00971480.md` |
| Named record | `docs/reconstruction/functions/aa_00971480_AssPreloader_DrainSuccessResultsAndTally_Inferred.md` |
| Nested | `HashMap_FindIterator` `0044e8c0` (W21-N); callers W31-K / W36-E; worker loop W32-K host map |
| Strings | `PRELOAD: preloaded already loaded asset %s`; `assPreloader.cpp` lines `0xd3` / `0xe8` |

---

## 3. Signature (sealed)

```c
// stack host*; RET 0x4; void — NOT thiscall
void AssPreloader_DrainSuccessResultsAndTally_Inferred(void* host /*stack*/);
```

| Slot | Source | Conf |
|---|---|---|
| host | Stack `[ebp+8]` → EBX | **High** |
| RET | **`C2 04 00`** | **High** |
| body | **439 B** / `0x1B7` | **High** |

Full hex: raw W37-B append (439 B).

---

## 4. Control flow (clean ≡ bytes / decompile)

| Stage | Match | Conf |
|---|---|---|
| SEH + `ESI=host+0x4c` pop loop (`0043e750`) | **Yes** | **High** |
| Cache find via `0044e8c0` on `host+0x110` | **Yes** | **High** |
| Branch: end/null → tally; else → already-loaded log + delete | **Yes** | **High** |
| Tally: time + tree `@+0x10` + bucket `00970910` + size `vt[+0x1c]` → `+0xe8` / `+0xfc` | **Yes** | **High** |
| Dump gate `DAT_00d1f618` walk `@+0x14` then clear | **Yes** | **High** |
| RET 4 | **Yes** | **High** |

---

## 5. Gaps

- Pair first-dword product type (key vs asset*) residual.  
- Nested product plates for `0043e750` / `00970910` / `0043d570` / `00457cc0`.  
- `DAT_00d1f618` product English.  
- Runtime / bit-exact.

---

## Verdict

439 B worker sealed via bytes + family strings + caller duals. Method English **Inferred**. **accept-with-gaps**.
