# Review A (reconstruction fidelity): `aa_0056f570` EmptyRet

| Field | Value |
|---|---|
| **Stable ID** | `aa_0056f570` |
| **VA** | `0x0056f570` |
| **Body** | `0x0056f570` only (**1** byte `c3`) |
| **Canonical name** | `EmptyRet` |
| **Prior / alias** | `FUN_0056f570`; parent-seed `Named_CalleeOf_…_InitInstance_0056f570` (**misleading**) |
| **Review date** | `2026-07-29` (W17-P OWN-ONLY dual) |
| **Reviewer role** | Independent reconstruction review (Path A — fidelity) |
| **Counterpart** | `reviews/B_aa_0056f570_EmptyRet.md` |
| **System** | shared / multi-domain nop leaf |
| **Live tools** | Ghidra `decompile_function`, `read_memory`, `get_function_xrefs`, `analyze_function_complete`, `search_byte_patterns` (no `disassemble_bytes`) |
| **Verdict** | **accept** |

---

## 1. Purpose

**Shared empty leaf** — a single-byte `RET` with zero side effects.

This is **not** a domain-specific hook tied to one system. Live xrefs show mass reuse as:

1. **Default empty virtual methods** (DATA dword `70 f5 56 00` in many `.rdata` vtables; sample: base HB `PTR` @ `0x009cdfb0` **slot 7** = `0x009cdfcc`).
2. **MSVC EH Unwind** / trivial vector dtor targets (hundreds of `Unwind@…` CALL sites).
3. **Stripped debug-print sinks** (e.g. `FUN_0048a280` GetCapabilities path passes format strings; body ignores them).

Product English / PDB symbol is open; behavioral name **`EmptyRet`** is descriptive, not invented RTTI.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.md` |
| Annotated | `docs/reconstruction/raw/aa_0056f570_FUN_0056f570.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/EmptyRet.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0056f570.cpp` |
| Function record | `docs/reconstruction/functions/aa_0056f570_EmptyRet.md` |
| Live decompile | `decompile_function` @ `0x0056f570` → empty `return;` |
| Live bytes | `read_memory` → `c3` then `cc` pad |
| Classification | `analyze_function_complete` → **stub**, callees=[] |

---

## 3. Byte seal (`read_memory` @ `0x0056f570`)

```
c3                 ret
cc cc cc …         int3 pad (not body)
```

| Claim | Evidence | Conf |
|---|---|---|
| Body is pure `ret` | hex `c3` only | **High** |
| No stack cleanup in callee | not `c2 xx 00` | **High** |
| No stores / no callees | 1-byte body | **High** |
| Decompile ≡ raw ≡ bytes | all empty return | **High** |
| Next leaf distinct | `0x0056f580` different body | **High** |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| single `return;` | **Yes** |
| No invented domain work | **Yes** |
| No invented stack args / `ret N` | **Yes** |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Shared multi-role empty leaf | **High** | xrefs + DATA pattern flood |
| Ignores `this` / stack args | **High** | body has no loads |
| Base HB slot 7 default | **High** | `read_memory` `0x009cdfcc` = `70 f5 56 00` |
| Not the same VA as DrivePathNoOp | **High** | DrivePathNoOp is `0x004f3700` |
| Product/PDB symbol | **Open** | no string in body |
| Full DATA census | **Open** | hundreds of hits; CF seal does not need it |

---

## 6. Gaps / open

1. Original compiler/PDB symbol for the shared empty.
2. Whether any historical build had non-empty body at this VA (stripped-hook hypothesis only).
3. Exhaustive listing of every vtbl slot using this address.

**Verdict:** **accept**
