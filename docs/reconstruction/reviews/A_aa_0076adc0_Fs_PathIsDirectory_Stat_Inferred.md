# Review A (reconstruction fidelity): `aa_0076adc0` Fs_PathIsDirectory_Stat_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076adc0` |
| **VA** | `0x0076adc0`–`0x0076ae35` (**118 B**) |
| **Canonical name** | `Fs_PathIsDirectory_Stat_Inferred` |
| **Ghidra name** | `FUN_0076adc0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-C) |
| **Counterpart** | `reviews/B_aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` |
| **System** | filesystem / path probe |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

CRT `stat`-based directory test: copy path → strip trailing separator → `stat` → return `S_IFDIR` bit (or false on failure). Shared FS helper for listing and recursive path collection.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-C append) | `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076adc0_FUN_0076adc0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_PathIsDirectory_Stat_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076adc0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076adc0_Fs_PathIsDirectory_Stat_Inferred.md` |
| Consumer dual | `aa_009839b0` Fs_DirRecurseCollectLeafPaths (W32-D) |
| Peer list | `aa_0076b3f0` Fs_ListDirBasenames (W33-C) |
| Live | decompile ≡ scaffold CF; body hex 118 B; dual bare RET |

---

## 3. Signature (sealed)

```c
// cdecl; path @ [esp+4]; bare RET; returns 0/1
uint32_t __cdecl Fs_PathIsDirectory_Stat_Inferred(const char* path);
```

| Formal | Source | Conf |
|---|---|---|
| path | stack `[esp+4]` (`8B 44 24 04`) | **High** |
| epilogue | `ADD ESP,0x128; RET` both exits | **High** |
| fail return | `XOR AL,AL` | **High** |
| success | `(dword[stat+6] >> 14) & 1` | **High** |

---

## 4. Control flow (bytes authority)

```
copy path → local[260]
if last == '\\' or '/': last = 0
rc = stat(local, &st)     // IAT [0x009c6504]
if rc != 0: return 0
return (st_mode_dword >> 14) & 1   // S_IFDIR
```

| Stage | Match | Conf |
|---|---|---|
| strcpy-style copy incl. NUL | Yes | **High** |
| strip `\` / `/` | Yes | **High** |
| stat fail → 0 | Yes | **High** |
| S_IFDIR bit test | Yes | **High** |
| Body size 118 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0076b3f0`, `FUN_0076ba10`, `FUN_0076bc00`, `FUN_0076bc80`, `FUN_007a13e0`, `FUN_007b75b0`, `FUN_009839b0`, `FUN_00984340` |
| Callees | `stat` only |

---

## 6. Gaps

1. Product/MSVC demangle for free helper.  
2. Exact CRT import symbol (`stat` / `_stat` / `_stat32`) beyond IAT slot.  
3. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI, CF, and S_IFDIR semantics sealed from live decompile + body bytes. Residual product plate only → **accept-with-gaps**.
