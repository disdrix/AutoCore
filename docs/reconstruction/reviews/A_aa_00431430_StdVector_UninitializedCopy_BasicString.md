# Review A (reconstruction fidelity): `aa_00431430` StdVector_UninitializedCopy_BasicString

| Field | Value |
|---|---|
| **Stable ID** | `aa_00431430` |
| **VA** | `0x00431430`–`0x00431450` (**32 B**) |
| **Canonical name** | `StdVector_UninitializedCopy_BasicString` |
| **Ghidra name** | `FUN_00431430` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-H) |
| **Counterpart** | `reviews/B_aa_00431430_StdVector_UninitializedCopy_BasicString.md` |
| **System** | MSVC `vector<basic_string<char>>` uninitialized copy (thin rebind) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` (full body) + xrefs + parent insert use-sites. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Thiscall member rebind of range uninitialized copy: placement copy-construct `[first, last)` into `dest` via `FUN_0046a2c0`. Returns new dest end for in-place insert shifts.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-H append) | `docs/reconstruction/raw/aa_00431430_FUN_00431430.md` |
| Annotated | `docs/reconstruction/raw/aa_00431430_FUN_00431430.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/StdVector_UninitializedCopy_BasicString.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_00431430.cpp` |
| Function record | `docs/reconstruction/functions/aa_00431430_StdVector_UninitializedCopy_BasicString.md` |
| Core callee | `FUN_0046a2c0` decompile (string ctor loop stride 0x1c) |
| Parent | `StdVector_InsertN_BasicString` hole + mid-shift arms |
| Live | 32 B thin body; `C2 0C 00`; `ADD ESP,0x14` |

---

## 3. Signature (sealed)

```c
// ECX = vector*; stack first*, last*, dest*; RET 0x0C
// returns dest_end (EAX) — decompiler void is wrong
BasicString_0x1c* __thiscall StdVector_UninitializedCopy_BasicString(
    VectorBasicString* vec,
    BasicString_0x1c* first,
    BasicString_0x1c* last,
    BasicString_0x1c* dest);
```

| Formal | Source | Conf |
|---|---|---|
| vec | ECX | **High** |
| first/last/dest | stack; RET 0x0C | **High** |
| forward | `FUN_0046a2c0(first,last,dest,vec,dest)` | **High** |
| EAX return | insert assigns `uVar3 = FUN_00431430(...)` | **High** |

---

## 4. Control flow

| Stage | Match | Conf |
|---|---|---|
| Arg shuffle + call | full body hex | **High** |
| Cdecl cleanup 0x14 | `83 C4 14` | **High** |
| RET 0x0C | `C2 0C 00` | **High** |
| No local string loop | body has no dtor/ctor IAT | **High** (in callee) |

---

## 5. Machine bytes (`read_memory`)

Full body hex (32 B) — see raw W33-H append.

```
8b44240c8b542408508b442408518b4c2414515250e8768e030083c414c20c00
```

---

## 6. Callers / classification

| Item | Value |
|---|---|
| Classification | wrapper |
| Callers | `FUN_004306b0` @ `0x004308e2`, `0x00430976` only |
| Callees | `FUN_0046a2c0` |

---

## 7. Gaps

1. Product/MSVC demangle (`_Ucopy` / `_Umove`).  
2. Nested `FUN_0046a2c0` dual (core loop not owned).  
3. Residual 4th/5th args (`this`, trailing `dest`) purpose.  
4. Runtime / bit-exact / differential.

---

## 8. Verdict

**accept-with-gaps** — thin Ucopy rebind ABI/CF/return sealed; product demangle + core callee residual.
