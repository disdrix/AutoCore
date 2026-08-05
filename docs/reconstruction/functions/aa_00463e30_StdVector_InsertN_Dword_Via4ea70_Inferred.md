# Function record: StdVector_InsertN_Dword_Via4ea70_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00463e30` |
| **Canonical name** | `StdVector_InsertN_Dword_Via4ea70_Inferred` |
| **Ghidra name** | `FUN_00463e30` |
| **Address** | `0x00463e30` |
| **Body range** | `0x00463e30`–`0x00464070` inclusive (**577** B / `0x241`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | util / container (generic) |
| **Calling convention** | **`__thiscall`**; ECX = vector; stack `where*`, `count`, `value*`; **`ret 0x0C`** |
| **Completion status** | **Dual A/B sealed** — CF + triad + growth + ABI + helper roles; runtime/diff open; decompiler post-delete gap documented |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A** | `reviews/A_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |
| **Dual B** | `reviews/B_aa_00463e30_StdVector_InsertN_Dword_Via4ea70_Inferred.md` |
| **Last reviewed** | `2026-08-04` (W38-M) |

## Alias

- Ghidra: `FUN_00463e30`
- **Reject** scaffold `Named_CalleeOf_Named_effVertexDecl_00463e30`
- Twin family: `StdVector_InsertN_Dword_Inferred` @ `0x004073a0`; count-ECX twin `0x00419880`

## Purpose

MSVC-style `std::vector<T>` **insert-n** for **4-byte** elements. Inserts `count` copies of `*value` at iterator `where`, growing capacity when needed (1.5× with exact-fit floor). Generic infrastructure — **not** domain logic.

## Signature

```c
void __thiscall StdVector_InsertN_Dword_Via4ea70_Inferred(
    VectorDword* self,   // +4 begin, +8 end, +0xc capEnd
    uint32_t* where,
    uint32_t count,
    uint32_t* value);
/* ret 0x0C */
```

## Behavioral summary

| Branch | Condition | Effect |
|---|---|---|
| Early-out | `count==0` | return |
| Throw | `size+count > 0x3fffffff` | `FUN_004540b0` |
| Realloc | `cap < size+count` | 1.5× grow, relocate via 4ea70/36ef0, delete old, rewrite triad |
| In-place near end | room && distance-to-end < count | shift + fill + bump end |
| In-place mid | room else | bwd/fwd helpers + fill |

## Machine seal (`read_memory` 2026-08-04)

- SEH prolog; `mov edi,ecx` (this); stack triad args; epilogue **`ret 0x0C`**.
- Max size constant `0x3fffffff`; growth `cap + (cap>>1)`.

## Callers / callees

| Direction | Notes |
|---|---|
| **Callees** | `FUN_0044ea70`, `FUN_00436ef0`, `FUN_0044ea50`, `FUN_004540b0`, `operator_new`/`delete` |
| **Callers** | 13 funcs / 16 xrefs incl. `FUN_0044a380` (W37-Z), UI/gfx/net helpers |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.md` (+ W38-M append)
- Annotated: `docs/reconstruction/raw/aa_00463e30_FUN_00463e30.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/StdVector_InsertN_Dword_Via4ea70_Inferred.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00463e30.cpp`
- Report: `docs/agents/task-dual-ab-004129f0-00463e30-w38m-report.md`

## Confidence

| Claim | Level |
|---|---|
| Boundary + body size | **High** |
| thiscall + ret 0x0C ABI | **High** |
| Triad + stride 4 | **High** |
| 1.5× growth + max 0x3fffffff | **High** |
| Helper roles (copy/fill/throw) | **High** |
| Product demangled name | **Inferred** |
| Runtime / bit-exact | **Open** |

## Open questions

1. Exact MSVC demangled template args.
2. Full caller taxonomy.
3. Whether any caller relies on non-POD dword element ctor.
4. Runtime / differential.
