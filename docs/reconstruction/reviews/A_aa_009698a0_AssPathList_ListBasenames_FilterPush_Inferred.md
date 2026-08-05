# Review A (reconstruction fidelity): `aa_009698a0` AssPathList_ListBasenames_FilterPush_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_009698a0` |
| **VA** | `0x009698a0`–`0x00969a4c` (**428 B**) |
| **Canonical name** | `AssPathList_ListBasenames_FilterPush_Inferred` |
| **Ghidra name** | `FUN_009698a0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W34-B) |
| **Counterpart** | `reviews/B_aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` |
| **System** | asset path-list enumeration / filter collect |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full 428 B + wrapper 28 B) + xrefs. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Enumerate basenames under each path in a string vector (`path + "*.*"` → `FUN_0076b3f0`), resolve names to handles (`FUN_00989e00`), classify via virtual `+0x10`, push matching handles into an **EDI** dword vector. Filter **0** accepts all.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W34-B append) | `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.md` |
| Annotated | `docs/reconstruction/raw/aa_009698a0_FUN_009698a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AssPathList_ListBasenames_FilterPush_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_009698a0.cpp` |
| Function record | `docs/reconstruction/functions/aa_009698a0_AssPathList_ListBasenames_FilterPush_Inferred.md` |
| Basename peer | `aa_0076b3f0` Fs_ListDirBasenames_Inferred (W33-C) |
| Wrapper | bytes @ `0x00996aa0` (not a Ghidra function) |
| Live | decompile CF ≡ scaffold; EDI recovered from wrapper + body |

---

## 3. Signature (sealed)

```c
// stdcall; RET 0xC; EDI = out PtrVecShell* (register formal)
// returns 0
uint32_t __stdcall AssPathList_ListBasenames_FilterPush_Inferred(
    StringVecShell* path_list,
    void* classifier,
    int type_filter);
```

| Formal | Source | Conf |
|---|---|---|
| path_list | stack; `+4/+8` walk stride 0x1c | **High** |
| classifier | stack; `(*obj)->vtbl[+0x10]` | **High** |
| type_filter | stack; `0` or compare to class_id | **High** |
| out_ids | **EDI**; wrapper loads from stack arg | **High** |
| epilogue | SEH unlink + `ADD ESP,0x44; RET 0xC` | **High** |

---

## 4. Control flow (bytes authority)

```
for path in path_list:
  pattern = path + "*.*"                 // DAT_00aa1d38
  FUN_0076b3f0(pattern, &names)
  for basename in names:
    FUN_00989e00(this=0x00d1eac8, &handle, basename)
    classifier->vtbl[+0x10](&handle, &class_id)
    if type_filter==0 || class_id==type_filter:
      push handle → EDI vec              // 00436ef0 or 0043bfb0
  destroy names; ~pattern
return 0
```

| Stage | Match | Conf |
|---|---|---|
| `"*.*"` append | Yes | **High** |
| List basenames via 0076b3f0 | Yes | **High** |
| Resolve ECX=`0x00d1eac8` | Yes (`B9 C8 EA D1 00`) | **High** |
| Filter gate | Yes | **High** |
| EDI capacity push | Yes | **High** |
| Body 428 B / RET 0xC | Yes | **High** |
| operator_delete noreturn | False — loop continues | **High** |

---

## 5. Wrapper `0x00996aa0`

| Item | Value |
|---|---|
| Size | 28 B |
| Role | bind `path_list=*DAT_00d1f1fc`, `EDI=out`, call this |
| ABI | stdcall RET 0xC (3 stack args) |
| Sole code xref into body | `0x00996ab6` |

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | worker |
| Callers | thin wrapper only |
| Callees | `FUN_00416490`, `FUN_0076b3f0`, `FUN_00989e00`, `FUN_00436ef0`, `FUN_0043bfb0`, string dtor, `operator_delete` |

---

## 7. Gaps

1. Product English for classifier `vtbl[+0x10]` and handle type from `FUN_00989e00`.  
2. AssManager product plate for `DAT_00d1f1fc` list (W31-E residual).  
3. Nested duals of `FUN_00989e00` / grow helpers not owned here.  
4. Runtime / bit-exact / differential — open.

---

## 8. Verdict

**accept-with-gaps** — ABI/CF/filter/list stages sealed; product plates for classifier and resolve helper remain open.
