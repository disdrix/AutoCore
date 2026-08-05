# Review A (reconstruction fidelity): `aa_00984910` AssPackManager_AddOrReplaceFileInPack_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00984910` |
| **VA** | `0x00984910`–`0x00984c65` (**854 B**) |
| **Canonical name** | `AssPackManager_AddOrReplaceFileInPack_Inferred` |
| **Ghidra name** | `FUN_00984910` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-Q) |
| **Counterpart** | `reviews/B_aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` |
| **System** | palantir assets / assPackManager |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body hex) + two call-site byte patterns. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Add a filesystem file into an open pack, or skip when unchanged and not forced; optional replace-prep; compress/meta insert; plate logs.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-Q append) | `docs/reconstruction/raw/aa_00984910_FUN_00984910.md` |
| Annotated | `docs/reconstruction/raw/aa_00984910_FUN_00984910.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPackManager_AddOrReplaceFileInPack_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00984910.cpp` |
| Function record | `docs/reconstruction/functions/aa_00984910_AssPackManager_AddOrReplaceFileInPack_Inferred.md` |
| Related | W32-E compact; W33-E `FUN_00984c70`; W32-D dir recurse |
| Live | decompile ≡ CF; full hex seals ABI + RET 0x14 |

---

## 3. Signature (sealed)

```c
// ECX=srcPath, 5 stack formals, RET 0x14
int AssPackManager_AddOrReplaceFileInPack_Inferred(
    const char* srcPath /*ECX*/,
    AssPackHost* host /*stack0*/,
    int typeId /*stack1*/,
    char forceReplace /*stack2*/,
    uint32_t arg4 /*stack3*/,
    uint32_t replaceCookie /*stack4*/);
```

| Formal | Source | Conf |
|---|---|---|
| srcPath | ECX (`8B F1`) | **High** |
| host | stack0 (`8B BC …`; `80 7F 50`; `8D 47 38`) | **High** |
| typeId | stack1 (vs `entry+0x14`; meta write) | **High** |
| forceReplace | stack2 (skip gate when 0) | **High** |
| arg4 | stack3 (callers push 0 / duplicate) | **Med** |
| replaceCookie | stack4 → `FUN_009847c0` | **High** |
| return | EAX 1 skip / ≥0 add / −1 fail | **High** |

---

## 4. Control flow (bytes authority)

```
SEH frame LAB_009b07af
if host.lockEnable(+0x50): EnterCS(host+0x38)
FUN_00719630(); entry = FUN_009835f0()
if entry:
  if force==0 && mtime match && size match && typeId==(short)entry+0x14:
    log "Not replacing %s." :0x128 level1; LeaveCS; return 1
  FUN_009847c0(replaceCookie)
open file object; FUN_007669d0(path, 1, 0)
if open fail: log Unable to open :0x163 level3; rc=-1
else: read full file; compress/hash; build meta; insert FUN_00469910
log "Added file %s" :0x166 level1
close; FUN_00766750; LeaveCS; return rc
```

| Stage | Match | Conf |
|---|---|---|
| CS gate + leave | decompile ≡ bytes | **High** |
| Skip-if-same triad | stat + `FUN_0076ad40` + type i16 | **High** |
| Replace prep | `FUN_009847c0` only when entry exists and not skipped | **High** |
| Open mode 1 | `6A 00 6A 01 56` + `FUN_007669d0` | **High** |
| RET 0x14 | epilogue `C2 14 00` | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (854 B) — see raw W33-Q append.

Entry: `6A FF 68 AF 07 9B 00` SEH; `81 EC 70 01 00 00`; `8B F1`; `80 7F 50 00`.  
Epilogue: `81 C4 7C 01 00 00` / `C2 14 00`.  
Pad `CC` then `FUN_00984c70`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_00984c70` @ `0x00984ce5`; `FUN_00985010` @ `0x00985198` |
| Plate | `assPackManager.cpp` |

---

## 7. Gaps

- Nested compress (`FUN_0071aaf0` / `FUN_0071ad70` / `FUN_007199e0`) product English.
- Exact MSVC `stat` field selected for mtime mask (local_118) vs `entry+0x0c`.
- arg4 product meaning (often 0).
- `FUN_009847c0` replace contract (not OWN).
- Runtime / bit-exact / differential.

---

## 8. Verdict

CF + ABI + skip/add/fail paths sealed with full hex and dual call-site proof. Nested compress + arg4 residual → **accept-with-gaps**.
