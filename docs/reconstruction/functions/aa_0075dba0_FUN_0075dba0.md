# Function record: NDResourceCache_LookupOrCreate

| Field | Value |
|---|---|
| **Stable ID** | `aa_0075dba0` |
| **Canonical name** | `NDResourceCache_LookupOrCreate` |
| **Address** | `0x0075dba0` |
| **Body** | `0x0075dba0`–`0x0075de54` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `nd-resource` |
| **Completion status** | **Dual A/B sealed (accept-with-gaps)** — scaffold three-rep present; CF/ABI High |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Global resource cache lookup-or-create by name key + type token. Returns existing entry on type match (with optional predicate when `resource+0x14 != 0`); otherwise factory walk and optional default `0x3c` allocation unless `param5 == 1`.

## Signature (machine-sealed)

```c
// __stdcall, ret 0x14
NDResource* NDResourceCache_LookupOrCreate(
    NDResourceCache* cache,  // +0x08 map end, +0x6c optional path
    void* keyObj,
    void* typeToken,         // vs resource+0x0C
    void* matchPredicateOpt, // vtbl+0x08 bool when res+0x14 != 0
    int noDefaultCreate);    // ==1 → NULL if factories fail (no new)
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0075dba0_FUN_0075dba0.md`
- Annotated: `docs/reconstruction/raw/aa_0075dba0_FUN_0075dba0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0075dba0.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0075dba0_NDResourceCache_LookupOrCreate.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0075dba0_NDResourceCache_LookupOrCreate.md`

## Callers / callees (summary)

**Callers (xrefs):** `NDResource_LoadByKey` `0x00423ac0`, `FUN_00445080`, `FUN_0074ee40`, `FUN_007b70e0`, `FUN_007b7420`, `FUN_007b7250`, `FUN_007b72b0`, `FUN_00764830`, `FUN_0096a440`, `FUN_0096ea60` (×2), `FUN_00981f50`, `0x004453c9`, …

**Callees:** map find `FUN_0044e8c0`; insert `FUN_0043c6f0`/`FUN_0043ba40`; alt `FUN_00970c00`/`00970b60`/`00971480`; factory list `FUN_0043c5f0`/`FUN_0040d9c0`; default `operator_new`+`FUN_00745d70`; log trio `FUN_0043e8f0`/`0043e7f0`/`0043e630`; indirect factory vtbl+4 / predicate vtbl+8.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + machine | **High** |
| stdcall 5-arg `ret 0x14` | **High** |
| Hit type `@+0x0c`, predicate `@+0x14` / vtbl+8 | **High** |
| `param5==1` no default create | **High** |
| Parameter C++ types / `+0x6c` meaning | **Tentative / Open** |
| Factory list layout | **Open** |
