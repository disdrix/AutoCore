# Review A (reconstruction fidelity): `aa_009841d0` Fs_ReadPathListFileToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009841d0` |
| **VA** | `0x009841d0`–`0x00984335` exclusive (**357 B**) |
| **Canonical name** | `Fs_ReadPathListFileToStringVec_Inferred` |
| **Ghidra name** | `FUN_009841d0` |
| **Review date** | `2026-07-29` (W34-I dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-I) |
| **Counterpart** | `reviews/B_aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` |
| **System** | filesystem / path-list text reader |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (entry/exit + body size) + xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Read a text path-list file into a string vector:

1. SEH `LAB_009af6c0`; `SUB ESP,0x44`; stack `stoFileOSFile` (vtable `0x00a9d84c`).
2. Open `path` mode **1** via `FUN_007669d0` (success `0`, fail `-1`).
3. **Fail:** `FUN_00469d10` assign empty collector → out; dtor file; tidy; return out.
4. **Ok:** default-ctor line string; while `Tell < Size`: `FUN_00766ee0` + `StringVec_PushBack`; assign → out; cleanup; return out.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009841d0_FUN_009841d0.md` (+ W34-I append) |
| Annotated | `docs/reconstruction/raw/aa_009841d0_FUN_009841d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ReadPathListFileToStringVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_009841d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009841d0_FUN_009841d0.md` |
| Named record | `docs/reconstruction/functions/aa_009841d0_Fs_ReadPathListFileToStringVec_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 357 B; sole xref `0x00984395` |
| File plate | nested `FUN_007669d0` / `FUN_007667f0` log strings → `stoFileOSFile.cpp` |

---

## 3. Signature (sealed)

```c
// cdecl 2 formals; bare RET; EAX = out_vec*
void* Fs_ReadPathListFileToStringVec_Inferred(void* out_string_vec,
                                              const char* path);
```

| Slot | Source | Conf |
|---|---|---|
| out_vec | Stack param_1 / `EBP` | **High** |
| path | Stack param_2 | **High** |
| return | out_vec in EAX (`MOV EAX,EBP`) | **High** |
| cleanup | bare `RET` after `ADD ESP,0x50` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| stoFile open mode 1 | **Yes** | **High** |
| Fail empty assign | **Yes** | **High** |
| Tell/Size line loop + push | **Yes** | **High** |
| Assign collector → out | **Yes** | **High** |
| Product English | shape only | **Inferred** |

---

## 5. Gaps / open

1. Product demangle / exact stream method names beyond open/tell/readline shape.
2. Nested `FUN_00766ee0` / `FUN_007669d0` full dual residual.
3. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
