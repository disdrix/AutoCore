# Review A (reconstruction fidelity): `aa_0076b190` Fs_Path_EnsureExtension_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b190` |
| **VA** | `0x0076b190`–`0x0076b208` exclusive (**120 B**) |
| **Canonical name** | `Fs_Path_EnsureExtension_Inferred` |
| **Ghidra name** | `FUN_0076b190` |
| **Review date** | `2026-07-29` (W33-P dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-P) |
| **Counterpart** | `reviews/B_aa_0076b190_Fs_Path_EnsureExtension_Inferred.md` |
| **System** | fs / path helpers |
| **Evidence pass** | Live decompile + analyze_function_complete + full-body `read_memory` + caller site reads + string `00aa61bc` |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Path **ensure-extension**:

1. Split `path` into drive/dir/fname/ext (`FUN_0076af70`).
2. If **ext empty**, copy **ESI** (default extension, no leading `.`) into ext.
3. Recompose into `out` (`FUN_0076aba0`).

Call sites set ESI=`"glm"` (`0x00aa61bc`) — CompactPackFile and pack open helper.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0076b190_FUN_0076b190.md` (+ W33-P append, full hex) |
| Annotated | `docs/reconstruction/raw/aa_0076b190_FUN_0076b190.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_Path_EnsureExtension_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_0076b190.cpp` |
| Function records | `functions/aa_0076b190_FUN_0076b190.md` + named |
| Live | `sub esp,0x304`; empty-ext branch; nested split/make; `add esp,0x310; ret` |
| Call sites | Compact `0098503d`: `mov esi,00aa61bc; call; add esp,8`; `0071a9ee` same imm |
| String | `00aa61bc` = `"glm\0"` |

---

## 3. Signature (sealed)

```c
void Fs_Path_EnsureExtension_Inferred(
    const char* path, char* out /* ESI=defaultExt */);
```

| Slot | Source | Conf |
|---|---|---|
| path | stack arg0 | **High** |
| out | stack arg1 | **High** |
| defaultExt | ESI | **High** |
| return | void | **High** |
| cleanup | bare `C3`; caller cleans stack | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes for stages)

| Stage | Match | Conf |
|---|---|---|
| split → 3×256 locals + drive | **Yes** | **High** |
| empty ext ← ESI copy | **Yes** | **High** |
| makepath recompose to out | **Yes** | **High** |
| Does not replace non-empty ext | **Yes** | **High** |
| Nested split/make product plates | residual | **Med** |

---

## 5. Gaps / open

1. Nested `FUN_0076af70` / `FUN_0076aba0` product CRT twin names.
2. Truncation / max length behavior inside nested helpers.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
