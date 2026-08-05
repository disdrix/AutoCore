# Review A (reconstruction fidelity): `aa_0076b080` Fs_UnlinkFile_ESI_ForceChmod_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b080` |
| **VA** | `0x0076b080`–`0x0076b0f1` (**114 B** / `0x72`) |
| **Canonical name** | `Fs_UnlinkFile_ESI_ForceChmod_Inferred` |
| **Ghidra name** | `FUN_0076b080` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-S) |
| **Counterpart** | `reviews/B_aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` |
| **System** | filesystem / single-file force-unlink |
| **Evidence pass** | Live Ghidra `decompile_function` + full-body `read_memory` (114 B hex) + `analyze_function_complete` + `get_function_by_address` + callers + call-site `read_memory` + peer decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept** |

---

## 1. Purpose

Delete one file path held in **ESI**. When stack `force != 0` and the path is a regular file lacking write permission, `_chmod(path, 0x180)` then always `_unlink(path)`. Return success boolean.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-S append + full hex) | `docs/reconstruction/raw/aa_0076b080_FUN_0076b080.md` |
| Annotated | `docs/reconstruction/raw/aa_0076b080_FUN_0076b080.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_UnlinkFile_ESI_ForceChmod_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076b080.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076b080_FUN_0076b080.md` |
| Named record | `docs/reconstruction/functions/aa_0076b080_Fs_UnlinkFile_ESI_ForceChmod_Inferred.md` |
| Peer | W34-A `Fs_DeleteDirTreeRecursive` (file arm) |
| Call sites | `0076bb7d`, `0076bc5f`, `007b765d` |

**Not performed:** Launcher, runtime, bit-exact, parent ledgers, `disassemble_bytes`.

---

## 3. Signature (sealed)

```c
// cdecl; ESI = path; stack force; ADD ESP,0x28; RET
bool __cdecl Fs_UnlinkFile_ESI_ForceChmod_Inferred(char force /* ESI=path */);
```

| Formal | Source | Conf |
|---|---|---|
| force | `CMP BYTE [esp+0x28],0` after `SUB ESP,0x24` | **High** |
| path ESI | push ESI to stat/chmod/unlink; call-site LEA ESI | **High** |
| return | `NEG/SBB/ADD` after unlink → unlink==0 | **High** |
| cdecl | callers `ADD ESP,4`; callee plain `RET` | **High** |

---

## 4. Control flow (bytes authority)

```
if force != 0:
  if stat(ESI)==0 and (mode>>15)&1:           // regular file
    if stat(ESI)==0 and (~(mode_byte>>7))&1: // not writable
      _chmod(ESI, 0x180)
return _unlink(ESI) == 0
```

Full hex (114 B):  
`83ec24807c2428007456578b3d04659c008d4424045056ffd783c40885c0753f8b4c240ac1e90f80e101884c242c742f8d5424045256ffd783c40885c075208a44240ac0e807f6d024018844242c740f688001000056ff1568659c0083c4085f56ff15a0649c00f7d81bc083c00183c428c3`

| Stage | Match | Conf |
|---|---|---|
| Force gate | Yes | **High** |
| S_IFREG bit15 | Yes | **High** |
| !writable → chmod 0x180 | Yes | **High** |
| Always unlink | Yes | **High** |
| Body 114 B | Yes | **High** |

**Decompile ≡ bytes** for CF; ESI path is register formal (decompiler `unaff_ESI`).

---

## 5. Callers / classification

| Caller | Site | Notes |
|---|---|---|
| `FUN_0076ba10` | `0x0076bb7d` | LEA ESI path; PUSH force; ADD ESP,4 |
| `FUN_0076bc00` | `0x0076bc5f` | PUSH 1; force-unlink before CreateDirectoryA |
| `FUN_007b75b0` | `0x007b765d` | PUSH 1; asset precompile dir prep |

**Classification:** worker (filesystem).

---

## 6. Naming

| Name | Status |
|---|---|
| `Fs_UnlinkFile_ESI_ForceChmod_Inferred` | **Accept** — structural + CRT callees + callers |
| `Named_CalleeOf_Named_assManager_*` | **Reject** as product plate |

---

## 7. Gaps

- Product English (no body string).
- Runtime / bit-exact / differential (policy open).

---

## 8. Verdict

Full-body hex + call sites seal ESI path, force chmod gate, and unlink return. Residual product plate only → **accept** (gaps do not affect port contract).
