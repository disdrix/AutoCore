# Function record: Object_ResolveFromTFID

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bb950` |
| **Canonical name** | `Object_ResolveFromTFID` |
| **Ghidra / FUN alias** | `FUN_004bb950` |
| **Address** | `0x004bb950`–`0x004bb966` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / TFID (cross-cutting client) |
| **Completion status** | **Partial** — three-rep + dual A/B **accept-with-gaps** (2026-07-29); runtime/diff/bit-exact open |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** (A+B) |

## Purpose

Thin **TFID_16 → object\*** unwrap used everywhere a packed TFID must become a live world object pointer. Unpacks `bGlobal` / `dwCoidLo` / `dwCoidHi` and thiscall-passthroughs resolve context into `CVOGReaction_ResolveObjectTarget`.

**No mutation** in this body. Domain gates, dual hash tables, and miss→NULL live in the callee (`aa_004bae70`).

## Signature (image-sealed)

```c
// __thiscall: ECX = resolve context; stack pTfid; RET 4
void * __thiscall Object_ResolveFromTFID(void *ctx, TFID_16 *pTfid);
// returns object* or NULL
```

Ghidra’s `void * __stdcall Object_ResolveFromTFID(TFID_16*)` is **incomplete** (missing ECX). Callers load ctx (often `*(host+0xe4e8)` or `*(host+0xd34)`) immediately before `CALL`.

## Behavioral summary

1. Load `pTfid` from `[esp+4]`.
2. Push `*(pTfid+4)`, `*(pTfid+0)`, low-byte `*(pTfid+8)`.
3. `CALL CVOGReaction_ResolveObjectTarget` with **ECX preserved**.
4. `RET 4`; EAX = result.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **Confirmed** (Ghidra + INT3 pad) |
| Signature (thiscall + pTfid) | **High** (body RET 4 + call-site ECX loads) |
| Control flow | **High** (straight-line; bytes ≡ unpack) |
| Naming | **High** (plate + high fan-in; registry use) |
| Side effects | **High** — none local |
| Callee dual-table behavior | **High** via `aa_004bae70` dual (not re-proven here) |
| Overall | **accept-with-gaps** |

## Open questions

- Product type name of resolve `ctx` / table objects (owned residual of callee).
- Runtime observation of global vs local domain hit rates.
- Differential / bit-exact vs retail image.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_004bb950_FUN_004bb950.md` |
| Annotated | `raw/aa_004bb950_FUN_004bb950.annotated.md` |
| Clean | `reconstructed-exact/Object_ResolveFromTFID.cpp` |
| Clean (legacy name) | `reconstructed-exact/FUN_004bb950.cpp` |
| Review A | `reviews/A_aa_004bb950_Object_ResolveFromTFID.md` |
| Review B | `reviews/B_aa_004bb950_Object_ResolveFromTFID.md` |
| Callee dual | `reviews/A_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
