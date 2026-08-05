# Review A (reconstruction fidelity): `aa_00985010` AssPackManager_CompactPackFile_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00985010` |
| **VA** | `0x00985010`–`0x0098538d` exclusive (**893 B**) |
| **Canonical name** | `AssPackManager_CompactPackFile_Inferred` |
| **Ghidra name** | `FUN_00985010` |
| **Review date** | `2026-07-29` (W32-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W32-E) |
| **Counterpart** | `reviews/B_aa_00985010_AssPackManager_CompactPackFile_Inferred.md` |
| **System** | assets / assPackManager packer |
| **Evidence pass** | Live decompile + analyze_function_complete + entry/mid/epilogue `read_memory` + bulk xrefs + string reads |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Offline **pack compact** for a `.glm` file:

1. Rewrite path with extension `"glm"`.
2. Construct pack host A; **open source** via `FUN_00984ee0(..., flag=1)`.
3. Construct pack host B; stage `"_pk_"`; **open** `"_pack_tmp.glm"` via `FUN_00984ee0(..., flag=0)`.
4. For each source list entry: join `"_pk_"+"/"+name`, extract/write into temp pack, chmod/unlink intermediate; optional progress printf.
5. Close/flush; unlink original; **`MoveFileA("_pack_tmp.glm", original)`**; dtor hosts; return 0.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00985010_FUN_00985010.md` (+ W32-E append) |
| Annotated | `docs/reconstruction/raw/aa_00985010_FUN_00985010.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_CompactPackFile_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00985010.cpp` |
| Function records | `functions/aa_00985010_FUN_00985010.md` + named |
| Live | decompile stage order; entry `sub esp,0x250`; open sites EBX/ECX/flag; epi `add esp,0x25c; ret`; strings at `00aa618c`/`00aa6194`/`00aa61bc` |
| Xrefs | **0** callers (bulk + get_xrefs_to) |

---

## 3. Signature (sealed)

```c
// ECX=path; stack mode, quiet; C3; returns 0
uint32_t AssPackManager_CompactPackFile_Inferred(
    const char* packPath /*ecx*/, int mode, char quiet);
```

| Slot | Source | Conf |
|---|---|---|
| packPath | ECX → `FUN_0076b190` | **High** |
| mode | stack; `==3` → MOVSX id from node+0x20 | **High** |
| quiet | stack char; gates printf | **High** |
| return | XOR/path to EAX=0 before ret | **High** |
| cleanup | bare `C3` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes for stages)

| Stage | Match | Conf |
|---|---|---|
| dual host ctor + dual open (1 then 0) | **Yes** | **High** |
| `_pk_` + `_pack_tmp.glm` | **Yes** (strings) | **High** |
| per-entry compact loop | **Yes** | **High** |
| MoveFileA replace | **Yes** | **High** |
| Product packer English | strings | **High** |
| Nested extract/write plates | residual | **Med** |
| Static invocation | none | **Open** |

---

## 5. Gaps / open

1. Static call graph empty — invocation path unknown.
2. Nested `FUN_00984d30` / `FUN_00984910` / list node product types.
3. Full meaning of `mode` values other than 3.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
