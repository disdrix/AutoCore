# Review A (reconstruction fidelity): `aa_00969830` StringVec_PushFront_EnsureTrailingDirSep

| Field | Value |
|---|---|
| **Stable ID** | `aa_00969830` |
| **VA** | `0x00969830`–`0x00969897` exclusive (**103 B**) |
| **Canonical name** | `StringVec_PushFront_EnsureTrailingDirSep` |
| **Ghidra name** | `FUN_00969830` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W31-E) |
| **Counterpart** | `reviews/B_aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` |
| **System** | assManager / `StringVecShell` path list (`DAT_00d1f1fc`) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + caller call-site bytes + nested decompiles. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Normalize input path (ensure trailing directory separator), then insert that string at the **front** of the global `StringVecShell` pointed by `DAT_00d1f1fc`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W31-E append) | `docs/reconstruction/raw/aa_00969830_FUN_00969830.md` |
| Annotated | `docs/reconstruction/raw/aa_00969830_FUN_00969830.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StringVec_PushFront_EnsureTrailingDirSep.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00969830.cpp` |
| Function record | `docs/reconstruction/functions/aa_00969830_StringVec_PushFront_EnsureTrailingDirSep.md` |
| Parent dual | `aa_007b75b0` AssManager_InitPrecompileAndResolvers (W30-D) |
| Release peer | `AssManager_ReleaseOwnedResolvers` front-erase on same vec |
| Live | decompile + 103 B hex + call sites `mov esi,[DAT_00d1f1fc]` |

---

## 3. Signature (sealed)

```c
// ESI = StringVecShell*; stack path*; RET 4; void
void StringVec_PushFront_EnsureTrailingDirSep(StringVecShell* self /*ESI*/,
                                              const void* path /*stack*/);
```

| Formal | Source | Conf |
|---|---|---|
| self | ESI (`8B CE` before insert; callers load ESI) | **High** |
| path | stack formal (`8B 44 24 2C` after SEH+local) | **High** |
| return | void | **High** |
| cleanup | `C2 04 00` | **High** |

---

## 4. Control flow (bytes authority)

```
SEH LAB_009acaf6; sub esp, 0x1c
FUN_009694e0(&local, path)     // ensure trailing dir sep
EH = 0
// insert at begin:
//   push local; push *(ESI+4)=begin; push &out; mov ecx,ESI; call FUN_00430310
EH = -1
IAT ~basic_string(local)
restore SEH; add esp,0x28; ret 4
```

| Stage | Match | Conf |
|---|---|---|
| SEH + local string | hex + decompile | **High** |
| Normalize then insert | call order | **High** |
| Insert pos = begin | `8B 46 04` + `FUN_00430310` | **High** |
| Trailing-sep rules | `FUN_009694e0` decompile (`: / \\`) | **High** (helper) |
| Elem stride 0x1c | insert family + release dual | **High** |

---

## 5. Machine bytes (`read_memory`)

Full body hex (103 B) — see raw W31-E append.

Entry: `6A FF 68 F6 CA 9A 00` (SEH).  
Epilogue: `83 C4 28 C2 04 00`.

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | `FUN_007b75b0` ×2 (precompile path + `DAT_00d1e570` bag walk) |
| Callees | `FUN_009694e0`, `FUN_00430310`, IAT dtor |

---

## 7. Gaps

1. Product English for the path-list role (search roots vs cache dirs).  
2. Nested helpers `FUN_009694e0` / `FUN_00430310` not dual-owned here.  
3. Full `StringVecShell` product plate beyond begin/end/stride.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

ESI ABI, front-insert, trailing-sep normalize stage, and caller binding to `DAT_00d1f1fc` are sealed. Residual product English + nested helpers → **accept-with-gaps**.
