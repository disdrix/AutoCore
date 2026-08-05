# Review A (reconstruction fidelity): `aa_0076bc00` Fs_CreateDirectoryForce_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076bc00` |
| **VA** | `0x0076bc00`–`0x0076bc79` exclusive (**121 B** / `0x79`) |
| **Canonical name** | `Fs_CreateDirectoryForce_Inferred` (**Inferred**) |
| **Ghidra name** | `FUN_0076bc00` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-Z) |
| **Counterpart** | `reviews/B_aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` |
| **System** | filesystem / directory create with optional force clear |
| **Evidence pass** | Live Ghidra `batch_decompile` + `read_memory` (121 B full) + `analyze_function_complete` + callers/xrefs + call-site context. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

**Create directory** at `path`, optionally force-clearing an existing path:

1. If `force_clear`:
   - **Directory** (`FUN_0076adc0`): recursive force wipe (`FUN_0076ba10(path,1)`), then `CreateDirectoryA`, return.
   - **Regular file** (`stat` + `_S_IFREG` bit 15): force unlink (`FUN_0076b080(1)`, **ESI=path**).
2. Fall-through: `CreateDirectoryA(path, NULL)`; return BOOL as bool.

Used by CompactPackFile (`"_pk_"`, force=1) and mkpath-style siblings.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-Z append) | `docs/reconstruction/raw/aa_0076bc00_FUN_0076bc00.md` |
| Annotated | `docs/reconstruction/raw/aa_0076bc00_FUN_0076bc00.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_CreateDirectoryForce_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076bc00.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076bc00_FUN_0076bc00.md` |
| Named record | `docs/reconstruction/functions/aa_0076bc00_Fs_CreateDirectoryForce_Inferred.md` |
| Peer is_dir | `aa_0076adc0` Fs_PathIsDirectory_Stat (W33-C) |
| Peer wipe | `aa_0076ba10` Fs_DeleteDirTreeRecursive (W34-A) |
| Live | decompile CF ≡ scaffold; body 121 B; `SETNZ` returns |

---

## 3. Signature (sealed)

```c
// cdecl; 2 formals; bool AL; ADD ESP,0x24; RET
bool __cdecl Fs_CreateDirectoryForce_Inferred(const char* path, char force_clear);
```

| Formal | Source | Conf |
|---|---|---|
| path | stack; ESI after load; callees | **High** |
| force_clear | `CMP BYTE [esp+0x2c],0` after frame | **High** |
| epilogue | `ADD ESP,0x24; RET` (`C3`) | **High** |
| return | `SETNZ AL` from CreateDirectoryA | **High** |

Callers use `ADD ESP,8` after call → cdecl 2 args confirmed (CompactPackFile `0x009850ba`).

---

## 4. Control flow (decompile + bytes authority)

```
if force_clear:
  if is_dir(path):
    delete_tree(path, 1)
    return CreateDirectoryA(path,0) != 0
  if stat(path)==0 && (st_mode & _S_IFREG):
    force_unlink(1)  // ESI=path
return CreateDirectoryA(path,0) != 0
```

| Stage | Match | Conf |
|---|---|---|
| Force gate | Yes | **High** |
| Dir wipe + early create | Yes | **High** |
| File bit-15 + unlink | Yes (`SHR 0xF`/`AND 1`) | **High** |
| Always CreateDirectoryA | Yes | **High** |
| Body 121 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_004b52e0`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_00985010` |
| Callees | `FUN_0076adc0`, `FUN_0076ba10`, `FUN_0076b080`, `stat`, `CreateDirectoryA` |

---

## 6. Gaps

1. Product English demangle (structural `_Inferred` only).  
2. Full `FUN_0076b080` product plate (force-unlink; ESI=path sealed by peer).  
3. Non-force + already-exists-as-dir behavior (CreateDirectoryA fail) intentionality.  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI (cdecl path+force, bool AL), force/dir/file CF, and peer FS composition sealed. Residual product/unlink detail → does not block. **accept**.
