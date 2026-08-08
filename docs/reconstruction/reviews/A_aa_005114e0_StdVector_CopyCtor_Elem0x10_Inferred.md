# Review A (reconstruction fidelity): `aa_005114e0` StdVector_CopyCtor_Elem0x10_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_005114e0` |
| **VA** | `0x005114e0`–`0x00511583` inclusive (**164 B** / `0xA4`) |
| **Canonical name (Ghidra)** | `FUN_005114e0` |
| **Proposed name** | `StdVector_CopyCtor_Elem0x10_Inferred` |
| **Review date** | `2026-08-05` (R13-029 OWN-ONLY dual A; dual start 2686) |
| **Reviewer role** | Independent reconstruction review (clean ≡ raw ≡ live) |
| **Counterpart** | `reviews/B_aa_005114e0_StdVector_CopyCtor_Elem0x10_Inferred.md` |
| **System** | `skills-abilities` (partition parent `0x00511950`) |
| **Dual status** | **Present (first dual seal)** |
| **Verdict** | **accept-with-gaps** |

**Tools:** Ghidra `decompile_function` + `analyze_function_complete` + `disassemble_function` + `get_function_callers` + `get_function_xrefs` + `read_memory` + `get_assembly_context`. **No** `disassemble_bytes`. No Launcher.

---

## 1. Purpose

MSVC-style **`std::vector<T>` copy constructor** for **element stride 0x10** (16-byte / 4-dword POD):

1. Compute `n = (src.end - src.begin) >> 4` (0 if `src.begin == 0`).
2. Zero dest triad `+4/+8/+0xC` (begin/end/capEnd).
3. If `n == 0` → return `this`.
4. If `n > 0x0FFFFFFF` → `FUN_004540b0` (noreturn `"vector too long"` length_error).
5. Else `operator_new(n * 0x10)`; set begin=end=buf, capEnd=buf+n*0x10.
6. Uninitialized POD range-copy via `FUN_005dd920(src.begin, src.end, buf)` (4 dwords per element).
7. Set dest end = returned write cursor; return `this`.

Used by residual buynode `FUN_005118b0` to copy the **vector payload** of Node24 value_type `(int key, vector<Elem0x10>)` into `node+0x10`, and by skill-map insert path `FUN_0050ba90` when building value pairs for InsertOrFind `FUN_00511b40`.

---

## 2. Inspected artifacts / evidence

| Artifact | Path / tool |
|---|---|
| Live decompile | Ghidra `decompile_function` @ `0x005114e0` ≡ raw CF |
| Complete analysis | `analyze_function_complete` (xrefs/callers/callees/locals) |
| Assembly | `disassemble_function` body through `RET 0x4` (**not** `disassemble_bytes`) |
| Bytes | `read_memory` 256 B @ entry — SEH prolog `6A FF 68 A0 34 9A 00`; epilogue `C2 04 00`; pad `CC` before next |
| Range-copy callee | `decompile_function` @ `FUN_005dd920` — 4-dword POD loop, stride `+4` dwords |
| Callers / xrefs | `get_function_callers` (2) + `get_function_xrefs` (3 UNCONDITIONAL_CALL) |
| Call-site context | `get_assembly_context` @ `0050bb93`, `0050bbae`, `00511912` |
| Parent dual | `aa_00511950` StdTree_InsertAndRebalance_Node24_Isnil21_Inferred (R12-014) — value_type int + vector 0x10 |
| Elem0x10 family peers | PodCopy `00409f70`, ConstructN `00409e20`, InsertN `00408640`, UninitFillN `00407000` |
| Raw / annotated / clean | `docs/reconstruction/raw|reconstructed-exact|functions` for `aa_005114e0` |

**Not performed:** `disassemble_bytes` primary, Launcher, runtime Confirmed, parent ledger edits, dual of callees/callers.

---

## 3. Signature

```c
// thiscall; ECX = dest vector*; stack = const source vector*; ret 4
// Vector layout (MSVC Dinkumware): +0 allocator/proxy, +4 begin, +8 end, +0xC capEnd
void* __thiscall StdVector_CopyCtor_Elem0x10_Inferred(
    /*ECX*/ StdVector_Elem0x10 *this,
    /*stack*/ const StdVector_Elem0x10 *src);
// returns this in EAX
```

| Item | Evidence |
|---|---|
| Convention | entry `MOV ESI,ECX`; call sites `LEA ECX,[…]` / `LEA ECX,[ESI+0x10]` then `CALL`; epilogue **`RET 0x4`** (`C2 04 00`) |
| Dest triad | `MOV [ESI+4/8/C], EDX` (EDX=0) then alloc path rewrites |
| Element stride | `SAR EAX,0x4` size; `SHL EAX,0x4` byte count; max `CMP EAX,0x0FFFFFFF` |
| Return | `MOV EAX,ESI` before epilogue |
| Body size | 164 B (`0xA4`); main path ends `RET 0x4` @ `0x00511581`–`0x00511583` |

---

## 4. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| SEH frame (`LAB_009a34a0`) | **Yes** |
| Size 0 if `src.begin==0` else `(end-begin)>>4` | **Yes** |
| Zero dest begin/end/capEnd | **Yes** |
| Empty → return this (no alloc) | **Yes** |
| Max-size gate → `FUN_004540b0` noreturn | **Yes** (decomp may fake-assign return; bytes = CALL only) |
| `new(n*0x10)` + triad plant + uninit_copy | **Yes** |
| End cursor from `FUN_005dd920` | **Yes** |
| thiscall + RET 4 + return this | **Yes** |
| No insert/erase/rebalance inside unit | **Yes** |

### Layout (sealed)

| Off | Role |
|----:|------|
| vec `+0` | allocator / proxy (untouched) |
| vec `+4` | `_Myfirst` begin |
| vec `+8` | `_Mylast` end |
| vec `+0xC` | `_Myend` capacity end |
| elem | **0x10** B POD (4 dwords) |

### Call-site samples

| Site | ECX (this) | Stack src | Follow-on |
|---|---|---|---|
| `0x00511912` `FUN_005118b0` buynode | `LEA ECX,[ESI+0x10]` (node payload vector) | `PUSH EAX` where `EAX = value+4` (src vector after int key) | color@`+0x20`, isnil@`+0x21`=0 |
| `0x0050bb93` `FUN_0050ba90` | `LEA ECX,[ESP+0x38]` scratch vec | push prior local | second copy @ `0x0050bbae` then `FUN_00511b40` InsertOrFind |
| `0x0050bbae` `FUN_0050ba90` | `LEA ECX,[ESP+0x4c]` | `PUSH EDX` (`LEA EDX,[ESP+0x34]`) | value pair → map insert |

---

## 5. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| CF + ABI thiscall + RET 4 + return this | **High** | disasm + bytes + call-site LEA ECX |
| Element stride 0x10 | **High** | SAR/SHL 4 + max 0x0FFFFFFF |
| Vector triad +4/+8/+0xC | **High** | stores + buynode node+0x10 embed |
| Role = vector copy-ctor (not assign / insert) | **High** | zeros dest then range-copy; no old buffer free |
| Ties to Node24 value_type payload | **High** | buynode parent dual + key@+0xC / vec@+0x10 |
| Product element type English | **Open** | `_Inferred` hygiene |
| Dual of `FUN_005dd920` / `FUN_004540b0` | **Open** | role sealed from peeks only |
| Runtime / bit-exact | **Open** | no Launcher |

---

## 6. Gaps / open

1. Product/PDB demangle for `std::vector<T>::vector(const vector&)` / exact `T`.
2. Full dual of range-copy `FUN_005dd920` and length_error `FUN_004540b0` (roles sealed; not OWN).
3. Runtime Confirmed / differential / cold heap contents.
4. Whether empty-base allocator lives at `+0` vs proxy pointer (untouched; layout of pointers sealed).

**Verdict:** **accept-with-gaps** — CF/ABI/stride/role/family High; product English + runtime open. Keep `_Inferred`.
