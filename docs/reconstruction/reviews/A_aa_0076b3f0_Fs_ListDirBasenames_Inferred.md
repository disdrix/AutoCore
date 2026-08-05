# Review A (reconstruction fidelity): `aa_0076b3f0` Fs_ListDirBasenames_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0076b3f0` |
| **VA** | `0x0076b3f0`–`0x0076b54e` (**351 B**) |
| **Canonical name** | `Fs_ListDirBasenames_Inferred` |
| **Ghidra name** | `FUN_0076b3f0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-C) |
| **Counterpart** | `reviews/B_aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` |
| **System** | filesystem / directory enumeration |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` (no disasm) + `read_memory` (full body) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Win32 FindFirst/Next **basename listing** into a caller string vector. If path is a directory (`FUN_0076adc0`), appends `"/*"` before search; skips `.` / `..`; pushes each `cFileName` via `FUN_004301f0`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-C append) | `docs/reconstruction/raw/aa_0076b3f0_FUN_0076b3f0.md` |
| Annotated | `docs/reconstruction/raw/aa_0076b3f0_FUN_0076b3f0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Fs_ListDirBasenames_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0076b3f0.cpp` |
| Function record | `docs/reconstruction/functions/aa_0076b3f0_Fs_ListDirBasenames_Inferred.md` |
| is_dir peer | `aa_0076adc0` (W33-C) |
| Consumer | `aa_009839b0` Fs_DirRecurseCollectLeafPaths (W32-D) |
| Push helper | `FUN_004301f0` (W33-D owned) |
| Live | decompile CF ≡ scaffold; body 351 B; SEH `LAB_009acd96` |

---

## 3. Signature (sealed)

```c
// cdecl; 2 formals; void; SEH LAB_009acd96; ADD ESP,0x184; RET
void __cdecl Fs_ListDirBasenames_Inferred(const char* path, void* out_string_vec);
```

| Formal | Source | Conf |
|---|---|---|
| path | stack (string ctor arg) | **High** |
| out_string_vec | stack; ECX before `FUN_004301f0` | **High** (bytes + callers; decompiler gap) |
| epilogue | SEH unlink + `ADD ESP,0x184; RET` | **High** |

---

## 4. Control flow (bytes authority)

```
pattern = string(path)
if is_dir(path): pattern += "/*"          // DAT_00a9d210
h = FindFirstFileA(pattern, &fd)
if h == INVALID: dtor; return
do:
  if name != "." and name != "..":        // REPE CMPSB len 2 / 3
    tmp = string(fd.cFileName)
    FUN_004301f0(out_vec, &tmp)           // thiscall
    ~tmp
while FindNextFileA(h, &fd)
FindClose(h); ~pattern; return
```

| Stage | Match | Conf |
|---|---|---|
| is_dir → `"/*"` | Yes | **High** |
| FindFirst fail early out | Yes | **High** |
| skip `.` / `..` exact | Yes | **High** |
| basename push only | Yes | **High** |
| Body size 351 B | Yes | **High** |

---

## 5. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_0076ba10`, `FUN_009698a0`, `FUN_009839b0`, `FUN_00984340` |
| Callees | `FUN_0076adc0`, string ops, FindFirst/Next/Close, `FUN_004301f0` |

---

## 6. Gaps

1. Product English / demangle.  
2. Full MSVC SSO field map beyond cap `< 0x10`.  
3. `FUN_004301f0` product plate (W33-D).  
4. Runtime / bit-exact / differential — open.

---

## 7. Verdict

ABI (2-arg cdecl), CF, basename-only push, and `"/*"` gate sealed. Decompiler 1-arg gap closed by bytes/callers. Residual product/SSO detail → **accept-with-gaps**.
