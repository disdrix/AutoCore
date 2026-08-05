# Review A (reconstruction fidelity): `aa_00984340` Fs_ExpandPathSpecToStringVec_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984340` |
| **VA** | `0x00984340`–`0x009847bb` (**1148 B**) |
| **Canonical name** | `Fs_ExpandPathSpecToStringVec_Inferred` |
| **Ghidra name** | `FUN_00984340` |
| **Review date** | `2026-07-29` (W33-E dual seal) |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-E) |
| **Counterpart** | `reviews/B_aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` |
| **System** | filesystem / path-spec expansion |
| **Evidence pass** | Live Ghidra decompile + `read_memory` (entry/exit + separator) + xrefs |
| **Verdict** | **accept-with-gaps** |

**Tools:** decompile + read_memory only (no `disassemble_bytes`). No Launcher.

---

## 1. Purpose

Path-spec expander into a string vector:

1. SEH `LAB_009af78c`; `SUB ESP,0x1A8`.
2. **`path[0]=='@'`:** `FUN_009841d0(path+1)` path-list; for each line recurse self; merge results.
3. **Else if not directory** (`FUN_0076adc0==0`):
   - Regular file (`stat` + `st_mode>>15&1`): push path.
   - Else glob: split dir/pattern (`/` or `\`); list + `FUN_0076b210` match; push `dir+"/"+entry`.
4. **Else directory:**
   - `recurse_flag!=0`: `FUN_009839b0` leaf walk into collector.
   - Else: one-level list; push `path+"/"+entry`.
5. `FUN_00469d10` assign collector → out; return out.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00984340_FUN_00984340.md` (+ W33-E append) |
| Annotated | `docs/reconstruction/raw/aa_00984340_FUN_00984340.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ExpandPathSpecToStringVec_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00984340.cpp` |
| Function record | `docs/reconstruction/functions/aa_00984340_FUN_00984340.md` |
| Named record | `docs/reconstruction/functions/aa_00984340_Fs_ExpandPathSpecToStringVec_Inferred.md` |
| Live | decompile ≡ scaffold CF; body 1148 B; self-xref only |
| Separator | `read_memory 00a2eb5c` → `2f 00 00 00` (`"/"`) |

---

## 3. Signature (sealed)

```c
// cdecl 3 formals; bare RET; EAX = out_vec*
void* Fs_ExpandPathSpecToStringVec_Inferred(void* out_string_vec,
                                            const char* path_spec,
                                            char recurse_dirs);
```

| Slot | Source | Conf |
|---|---|---|
| out_vec | Stack param_1 | **High** |
| path_spec | Stack param_2 / EDI `@` test | **High** |
| recurse | Stack param_3 | **High** |
| return | out_vec in EAX (`MOV EAX,EBP`) | **High** |
| cleanup | bare `RET` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

| Stage | Match | Conf |
|---|---|---|
| `@` list expand + self recurse | **Yes** | **High** |
| Regular-file push | **Yes** | **High** |
| Glob list+match+join `/` | **Yes** | **High** |
| Dir recurse via `009839b0` | **Yes** | **High** |
| Dir one-level | **Yes** | **High** |
| Assign via `00469d10` | **Yes** | **High** |
| Product English | shape only | **Inferred** |

---

## 5. Gaps / open

1. External invokers (0 static xrefs beyond self).
2. Product plates for `FUN_009841d0` / glob helper / this unit.
3. Exact which local is thiscall ECX for every `FUN_004301f0` site (collector vs out) — assign-at-end seals observable result.
4. Runtime / bit-exact / differential.

**Verdict:** **accept-with-gaps**
