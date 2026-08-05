# Review A (reconstruction fidelity): `aa_007669d0` stoFileOSFile_Open

| Field | Value |
|---|---|
| **Stable ID** | `aa_007669d0` |
| **VA** | `0x007669d0`–`0x00766d8c` (**956 B** / `0x3BC`) |
| **Canonical name** | `stoFileOSFile_Open` |
| **Ghidra name** | `FUN_007669d0` |
| **Review date** | `2026-08-04` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W37-E) |
| **Counterpart** | `reviews/B_aa_007669d0_stoFileOSFile_Open.md` |
| **System** | arda2 storage — `stoFileOSFile` OS open |
| **Evidence pass** | Live Ghidra `batch_decompile` + `analyze_function_complete` + `read_memory` (body + string constants + jump table region) + xrefs/callers. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Open a filesystem path on a `stoFileOSFile` instance: store mode, optionally quality-remap `.ogg`/`.dds` paths, `CreateFileA` with mode-mapped access/disposition, store HANDLE, return 0/-1. On failure, format system error and log against `stoFileOSFile.cpp:0xB9`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W37-E append) | `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.md` |
| Annotated | `docs/reconstruction/raw/aa_007669d0_FUN_007669d0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/stoFileOSFile_Open.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_007669d0.cpp` |
| Function record | `docs/reconstruction/functions/aa_007669d0_stoFileOSFile_Open.md` |
| Source plate | `read_memory` @ `0x00a9d944` → `…\stoFileOSFile.cpp` |
| Fail fmt | `read_memory` @ `0x00a9d97c` → `"File open error <%s> - %s"` |
| Quality tags | `read_memory` @ `0x00a9d998` → `_DE`/`_FR`/`_UK`/`.ogg` |
| DDS ext | `read_memory` @ `0x00a2c53c` → `.dds` |
| Suffix table | `read_memory` @ `0x00b01838` → `_on/_off/_over/_down`… |
| Callers | analyze_function_complete — 10 funcs / 14 sites |
| Live | dual `C2 0C 00`; mode switch table @ `0x00766d90` |

---

## 3. Signature (sealed)

```c
// ECX = stoFileOSFile*; stack path, mode, attrs; RET 0x0C; 0 ok / -1 fail
int32_t __thiscall stoFileOSFile_Open(
    stoFileOSFile* self,
    const char* path,
    uint32_t mode,
    DWORD attrs);
```

| Formal | Source | Conf |
|---|---|---|
| this | ECX | **High** |
| path | stack | **High** |
| mode | stack → `this+4` (`89 41 04`) | **High** |
| attrs | stack → CreateFile | **High** |
| handle | `this+8` | **High** |
| return | 0 / `0xFFFFFFFF` | **High** |
| cleanup | dual `C2 0C 00` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Store mode @+4 | decomp + bytes | **High** |
| Quality gate via `FUN_007a69d0()->+0x2c` | decomp | **High** |
| `.ogg` / `.dds` remap + fopen probe | decomp + strings | **High** |
| Mode switch access/disposition | decomp + jump table + bytes | **High** |
| CreateFileA share=1, sa/template null | decomp | **High** |
| Success → HANDLE @+8, return 0 | bytes | **High** |
| Fail → FormatMessage + log line 0xB9 → -1 | decomp + strings | **High** |

### Mode matrix (sealed)

| mode | access | disposition |
|---|---|---|
| 0 | — | fail |
| 1 | `0x20001` | OPEN_EXISTING (3) |
| 2 | `0x20006` | OPEN_EXISTING (3) |
| 3 | `0x20007` | OPEN_EXISTING (3) |
| 4,5 | `0` | OPEN_EXISTING (3) |
| 6 | `0x20006` | CREATE_ALWAYS (2) |

---

## 5. Machine bytes (`read_memory`)

Full body hex (956 B) — see raw W37-E append.

Entry: `81 EC 04 02 00 00 … 89 41 04`  
Epilogues: `83 C8 FF … C2 0C 00` (fail) and `33 C0 … C2 0C 00` (success).  
Switch: `FF 24 95 90 6D 76 00` → table `0x00766d90`.

---

## 6. Gaps

- Exact product C++ method demangle (Open / OpenEx).
- Full semantics of `FUN_007a69d0` quality field; 5th DDS table entry string.
- Runtime / bit-exact / differential.

## 7. Verdict

Fidelity pass seals ABI/mode matrix/HANDLE layout/log plate/quality-remap CF against live decompile + full hex + string constants + xrefs. Residual method demangle + quality singleton plate → **accept-with-gaps**.
