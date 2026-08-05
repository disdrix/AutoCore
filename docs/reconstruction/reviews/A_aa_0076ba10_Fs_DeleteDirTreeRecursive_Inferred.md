# Review A (reconstruction fidelity): `aa_0076ba10` Fs_DeleteDirTreeRecursive_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076ba10` |
| **VA** | `0x0076ba10`–`0x0076bbff` (**495 B** / `0x1EF`) |
| **Canonical name** | `Fs_DeleteDirTreeRecursive_Inferred` |
| **Ghidra name** | `FUN_0076ba10` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-A) |
| **Counterpart** | `reviews/B_aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` |
| **System** | filesystem / recursive directory delete |
| **Evidence pass** | Live Ghidra `decompile_function` + `read_memory` (prologue/epilogue + `DAT_00a2eb5c`) + `get_function_by_address` + `get_function_xrefs`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Recursive directory tree delete: when `recursive_force != 0`, list basenames (`FUN_0076b3f0`), join `path + "/" + name`, recurse into directories, force-unlink files (`FUN_0076b080` with ESI=path), then `_rmdir` root. When flag is 0, only `_rmdir(path)`. Failures print and continue.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-A append) | `docs/reconstruction/raw/aa_0076ba10_FUN_0076ba10.md` |
| Annotated | `docs/reconstruction/raw/aa_0076ba10_FUN_0076ba10.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_DeleteDirTreeRecursive_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076ba10.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076ba10_FUN_0076ba10.md` |
| Named record | `docs/reconstruction/functions/aa_0076ba10_Fs_DeleteDirTreeRecursive_Inferred.md` |
| Peer list | `aa_0076b3f0` Fs_ListDirBasenames (W33-C) |
| Peer is_dir | `aa_0076adc0` Fs_PathIsDirectory_Stat (W33-C) |
| Live | decompile CF ≡ scaffold; body 495 B; SEH `LAB_009adcab` |

---

## 3. Signature (sealed)

```c
// cdecl; 2 formals; bool AL; SEH LAB_009adcab; ADD ESP,0x70; RET
bool __cdecl Fs_DeleteDirTreeRecursive_Inferred(const char* path, char recursive_force);
```

| Formal | Source | Conf |
|---|---|---|
| path | stack; early `_rmdir` arg; join base | **High** |
| recursive_force | `CMP BYTE [esp+0x78],0` after frame | **High** |
| epilogue | SEH unlink + `ADD ESP,0x70; RET` | **High** |
| return | `SETZ` / `MOV AL,BL` from `_rmdir==0` | **High** |

---

## 4. Control flow (decompile + bytes authority)

```
if recursive_force == 0:
  return _rmdir(path) == 0

listing = empty vector<string>
FUN_0076b3f0(path, &listing)          // basenames only
for each basename (stride 0x1c):
  full = path + "/" + basename        // DAT_00a2eb5c = "/"
  if FUN_0076adc0(full):              // is directory
    if !FUN_0076ba10(full, force):
      printf("Delete directory failed for: %s %d\n", full, errno)
  else:
    if !FUN_0076b080(force) [ESI=full]:
      printf("Delete file failed for: %s %d\n", basename, errno)
  // continue on fail
rc = _rmdir(path)
FUN_00431ae0(&listing)
return rc == 0
```

| Stage | Match | Conf |
|---|---|---|
| Non-recursive early rmdir | Yes | **High** |
| List then join with `"/"` | Yes | **High** |
| Recurse dirs / unlink files | Yes | **High** |
| Fail printf + continue | Yes | **High** |
| Final rmdir + vector tidy | Yes | **High** |
| Body size 495 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | self; `FUN_0076bc00`; `FUN_007b75b0`; `FUN_00985010` (CompactPackFile) |
| Callees | `FUN_0076b3f0`, `FUN_0076adc0`, `FUN_0076b080`, self, `FUN_00416490`, `_rmdir`, `_errno`, `printf`, `FUN_00431ae0` |

---

## 6. Gaps

1. Product English demangle (structural `_Inferred` only).  
2. Exact ECX layout into `FUN_00431ae0` vector tidy.  
3. Full `FUN_0076b080` product plate (chmod mode bits sealed in peer decompile only).  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI (cdecl path+flag), recursive CF, plate strings, and `"/" join` sealed. Residual product/tidy detail → **accept-with-gaps**.
