# Review A (reconstruction fidelity): `aa_004646e0` PtrVecShell_InitFill_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_004646e0` |
| **VA** | `0x004646e0`–`0x0046477e` (**159 B** / `0x9F`; main `RET 12` @ `0x0046476b`) |
| **Canonical name** | `PtrVecShell_InitFill_Inferred` |
| **Ghidra name** | `FUN_004646e0` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Reconstruction fidelity (OWN-ONLY W33-B) |
| **Counterpart** | `reviews/B_aa_004646e0_PtrVecShell_InitFill_Inferred.md` |
| **System** | shared pointer-vector shell init (hash bucket tables) |
| **Evidence pass** | Live Ghidra `decompile_function` + `analyze_function_complete` + `read_memory` + xrefs + callee decompile of `FUN_00436ef0` / `FUN_004540b0`. **No** `disassemble_bytes`. |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Initialize a **pointer-vector shell**: zero begin/end/cap, if `count≠0` allocate `count*4` bytes, **fill every slot with `*fill_src`**, set end = end_cap = full. AssResolver nested bags call with **count=9** and fill = circular sentinel*.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Raw (+ W33-B append) | `docs/reconstruction/raw/aa_004646e0_FUN_004646e0.md` |
| Annotated | `docs/reconstruction/raw/aa_004646e0_FUN_004646e0.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/PtrVecShell_InitFill_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_004646e0.cpp` |
| Function records | `functions/aa_004646e0_FUN_004646e0.md`, `functions/aa_004646e0_PtrVecShell_InitFill_Inferred.md` |
| Fill helper | `FUN_00436ef0` — ECX=count, EDX=src, EAX=dst; `*dst++=*src` |
| Max-size | `FUN_004540b0` — throws `"vector<T> too long"` |
| Live | decompile CF for zero/alloc/fill; **bytes** seal 3rd formal + `RET 12` |

---

## 3. Signature (sealed — bytes win)

```c
// stdcall 3 formals; RET 0xC; SEH LAB_009bd530
// decompiler shows only (shell, count) — incomplete
void __stdcall PtrVecShell_InitFill_Inferred(
    void* shell,       // +4 begin, +8 end, +0xc end_cap; +0 unwritten
    uint32_t count,    // elements (not bytes)
    void** fill_src);  // *fill_src replicated into each slot
```

| Formal | Source | Conf |
|---|---|---|
| shell* | `[ebp+8]` → EDI | **High** |
| count | `[ebp+0xc]` | **High** |
| fill_src* | `[ebp+0x10]` → EDX into fill | **High** |
| RET 12 | `C2 0C 00` | **High** |

---

## 4. Control flow (clean ≡ raw ≡ bytes)

```
SEH prolog
shell[+4/+8/+0xc] = 0
if count == 0: goto done
if count > 0x3fffffff: FUN_004540b0()   // noreturn
byte_len = count * 4
p = operator_new(byte_len)
shell.end_cap = p + byte_len
shell.begin = shell.end = p
FUN_00436ef0(count) with EAX=p, EDX=fill_src   // fill
shell.end = p + byte_len
done:
SEH epilog
ret 12
```

| Stage | Match | Conf |
|---|---|---|
| Zero +4/+8/+0xc only | **Yes** | **High** |
| count*4 alloc | **Yes** | **High** |
| Fill via 00436ef0 from *fill_src | **Yes** (bytes + callee decompile) | **High** |
| end advanced to full | **Yes** | **High** |
| max-size throw | **Yes** (string in 004540b0) | **High** |
| Decompiler 2-arg is complete | **No** — 3rd arg + RET 12 | **High** (falsified) |

---

## 5. Gaps

- Product meaning of unwritten **shell+0**.
- Per-caller product English for non-Ass xrefs (7 additional call sites).
- Exact ownership: does any caller expect non-null shell+0 beforehand?
- Runtime / bit-exact / differential.

---

## 6. Verdict

Fidelity pass seals 3-arg stdcall ABI, shell layout, count*4, fill-from-pointer, max-size throw, and Ass bag usage (count=9). Residual product English → **accept-with-gaps**.
