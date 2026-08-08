# Review A (reconstruction fidelity): `aa_00401f40` StdTree_Buynode_StringByte_Isnil2D_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00401f40` |
| **VA** | `0x00401f40` |
| **Body** | `0x00401f40`–`0x00401fbf` exclusive (**127** B / `0x7F`) |
| **Canonical name** | `StdTree_Buynode_StringByte_Isnil2D_Inferred` |
| **Ghidra symbol** | `FUN_00401f40` |
| **Prior scaffold** | `FUN_00401f40` / `Named_CalleeOf_*Mis_00401f40` |
| **Review date** | `2026-08-05` (MEGA-079 OWN dual) |
| **Reviewer role** | Reconstruction fidelity / evidence-only naming |
| **Counterpart** | `reviews/B_aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` |
| **System** | STL / map-set buynode (partition: missions-progression null dialog) |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `read_memory` + callers/xrefs + `get_assembly_context` + callee/parent decompiles. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

Allocate and construct one **isnil@+0x2d** tree node (**size 0x30**) whose value is **MSVC `basic_string` + 1 mapped byte**, for the residual insert/rebalance path `FUN_00401db0` (isnil2D family nested under string-key insert-or-find `FUN_00401c50` / mission null-dialog partition host).

```text
StdTree_Buynode_StringByte_Isnil2D_Inferred(left, parent, right, value*, color)
  SEH install (LAB_009bc811)
  node = operator_new(0x30)
  if node:
    FUN_00401fe0(node, parent, right, left, color)  // EDI=value
      links L/P/R; string+byte copy; color@+0x2c; isnil=0@+0x2d
  return node  // null on OOM
  RET 0x14
```

---

## 2. Inspected artifacts

| Artifact | Path / source |
|---|---|
| Raw (+ MEGA-079 re-verify) | `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.md` |
| Annotated | `docs/reconstruction/raw/aa_00401f40_FUN_00401f40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdTree_Buynode_StringByte_Isnil2D_Inferred.cpp` |
| Scaffold twin | `docs/reconstruction/reconstructed-exact/FUN_00401f40.cpp` |
| Function record | `docs/reconstruction/functions/aa_00401f40_StdTree_Buynode_StringByte_Isnil2D_Inferred.md` |
| Live body | `disassemble_function` + `read_memory` @ `0x00401f40` / epilogue `C2 14 00` |
| Ctor | `FUN_00401fe0` disasm (links + color@+0x2c + isnil0@+0x2d) |
| Value | `FUN_00402040` disasm (string copy ctor + byte @+0x1c) |
| Parent insert | `FUN_00401db0` call-site @ `0x00401e16` |
| Insert-or-find | `FUN_00401c50` string `operator<` + isnil@+0x2d |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body 127 B + `ret 0x14` | **Confirmed** | disasm ends `RET 0x14`; hex `C2 14 00` |
| `__stdcall` 5 stack args; EAX return | **Confirmed** | no ECX this; caller stores EAX after CALL |
| `operator_new(0x30)` | **Confirmed** | `PUSH 0x30` + call `00489892` |
| Ctor links + string + byte + color + isnil0 | **Confirmed** | ctor + value helper disasm |
| isnil@+0x2d / color@+0x2c / size 0x30 | **Confirmed** | ctor stores; insert rebalance uses color@+0x2c |
| Sole caller insert `00401db0` | **Confirmed** | 1 xref / 1 caller |
| SEH frame present | **Confirmed** | FS:[0] / `LAB_009bc811` |
| Decompiler arity elision | **Confirmed** | raw 1-arg + phantom; asm 5 args |
| Product / PDB demangle | **Open** | `_Inferred` |
| Runtime / bit-exact / differential | **Open** | deferred |

---

## 4. Control flow: raw ≡ live ≡ bytes

| Stage | Match |
|---|---|
| SEH setup → new(0x30) | **Yes** |
| null skip / else ctor | **Yes** |
| return node in EAX; RET 0x14 | **Yes** |

---

## 5. Naming gate

| Evidence | Present? |
|---|---|
| Node size 0x30 + isnil@+0x2d family | **Yes** |
| Value = string (0x1c) + byte | **Yes** (value helper) |
| Parent insert sole caller | **Yes** |
| Product/PDB English | **No** |

**Decision:** promote **`StdTree_Buynode_StringByte_Isnil2D_Inferred`** (structural High; English unproven). Reject chain-of-caller `Named_CalleeOf_*Mis_*` scaffold; reject isnil29 Val24 merge; reject isnil31 Val32 merge; reject BuyHead merge (`00409780` — no value).

---

## 6. Gaps

1. Product/PDB symbol for host map (`string→byte`-shaped) under null-dialog chain.
2. Full dual of ctor `FUN_00401fe0`, value `FUN_00402040`, insert `FUN_00401db0` (not OWN).
3. Runtime / bit-exact / image diff.

**Verdict:** **accept-with-gaps**
