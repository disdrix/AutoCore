# Function record: CVOGReaction_ResolveObjectTarget

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bae70` |
| **Canonical name** | `CVOGReaction_ResolveObjectTarget` |
| **Address** | `0x004bae70` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object-resolve / reaction |
| **Completion status** | **Dual accept-with-gaps** — residual strengthen 2026-07-29 (assembly dual-table seal) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Permissioned **TFID → live object\*** resolve for reactions, skills, net handlers, and patrol. Selects one of **two** hash tables on the resolve context via the TFID global/domain byte, gated by enable flags, then returns the object pointer from the hash node (or null). **No mutation.**

## Signature (image-sealed)

```c
// __thiscall ECX=ctx; ret 0x0c
void * CVOGReaction_ResolveObjectTarget(
    void *ctx,              // +0x4/+0x8 tables; +0xc/+0xd enable flags
    unsigned char bGlobal,
    unsigned int coidLo,
    unsigned int coidHi);
```

## Behavioral summary

1. If `(coidLo & coidHi) == 0xFFFFFFFF` → null (both id halves all-ones).
2. If `bGlobal != 0`: require `ctx[+0xc]`; `FUN_004e3260(*(ctx+0x4), lo, hi)`.
3. If `bGlobal == 0`: require `ctx[+0xd]`; `FUN_004e3260(*(ctx+0x8), lo, hi)`.
4. `FUN_004e3260` (thiscall on table) walks hash chain; returns `*(node+0xc)` object*.

**Decompiler gap (closed in clean 2026-07-29):** raw Ghidra omitted `mov ecx,[ecx+4|8]` table selection; both arms looked like bare `FUN_004e3260(lo,hi)`.

## Confidence by dimension

| Dimension | Level |
|---|---|
| Function boundary | **High** (image) |
| Signature / calling convention | **High** (`ret 0x0c`, ECX ctx) |
| Control flow | **High** (bytes; dual-table switch sealed) |
| Naming | **Probable** (Ghidra product-style name; TFID field names from wrappers) |
| Side effects | **High** (none) |
| Flag / table product English | **Tentative / open** |
| Overall | **accept-with-gaps** |

## Open questions

- Product names for tables + `FUN_004e3260` / `FUN_004e23d0`
- Who sets `ctx+0xc` / `ctx+0xd`
- Runtime dual-table hit rates
- Full C++ type of `ctx`

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Annotated | `raw/aa_004bae70_CVOGReaction_ResolveObjectTarget.annotated.md` |
| Clean | `reconstructed-exact/CVOGReaction_ResolveObjectTarget.cpp` |
| Dual A | `reviews/A_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Dual B | `reviews/B_aa_004bae70_CVOGReaction_ResolveObjectTarget.md` |
| Scratch | `tmp/a_004bae70.md` |
| Callee (not owned) | `functions/aa_004e3260_FUN_004e3260.md` |
| TFID wrap | `Object_ResolveFromTFID` `0x004bb950` |
