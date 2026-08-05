# Function record: NDResource_Ctor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00745d70` |
| **Canonical name** | `NDResource_Ctor` |
| **Ghidra name** | `FUN_00745d70` |
| **Address** | `0x00745d70`–`0x00745dec` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | ndresource / ND resource object base |
| **Classification** | in-place constructor (0x3c object + critical section) |
| **Completion status** | **Sealed** — dual A/B 2026-07-29 W19-R; ABI + layout + CF sealed |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

Construct an NDResource-family object in a caller-provided **0x3c**-byte buffer: install base vtbl `PTR_FUN_00aa1d40`, copy name key, store type token, zero internal slots, init critical section at `+0x20`, set ready flag at `+0x38`, optionally fill `+0x14` from `optionalSrc->vtbl+4()`. Default-cache path then overwrites vtbl with `PTR_FUN_00a9e850`.

## Signature (sealed)

```c
// EDX = typeToken
// stack: this, nameKey*, optionalSrc* ; cleaned by RET 0xC
// returns this
void * __fastcall NDResource_Ctor(
    void *ecx_unused,
    std::uint32_t typeToken,
    void *self,
    std::uint32_t *nameKey,
    void *optionalSrc);
```

| Param | Location | Meaning |
|---|---|---|
| (unused) | ECX | not read by body |
| `typeToken` | **EDX** | stored at `this+0x0c` |
| `self` | `[esp+4]` | object under construction |
| `nameKey` | `[esp+8]` | `*nameKey → this+0x04` |
| `optionalSrc` | `[esp+0xC]` | null or source for `vtbl+4` → `this+0x14` |
| return | EAX | `self` |

## Layout (sealed)

| Off | Init |
|---:|---|
| `+0x00` | `PTR_FUN_00aa1d40` |
| `+0x04` | `*nameKey` |
| `+0x08` | `0` |
| `+0x0c` | typeToken (EDX) |
| `+0x10` | `0` |
| `+0x14` | `0` or `optionalSrc->vtbl+4()` |
| `+0x18` | `0xffffffff` |
| `+0x20` | `CRITICAL_SECTION` |
| `+0x38` | `u8 = 1` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.md`
- Annotated: `docs/reconstruction/raw/aa_00745d70_FUN_00745d70.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDResource_Ctor.cpp`
- Scaffold alias: `docs/reconstruction/reconstructed-exact/FUN_00745d70.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00745d70_NDResource_Ctor.md`
- Review B: `docs/reconstruction/reviews/B_aa_00745d70_NDResource_Ctor.md`
- Report: `docs/agents/task-dual-ab-00745d70-0076a900-w19r-report.md`

## Callers / callees

**Callees:** `InitializeCriticalSection`; indirect `optionalSrc->vtbl+4`.

**Callers (7):**

- `NDResourceCache_LookupOrCreate` `0x0075dba0` (default `operator_new(0x3c)` path; patches vtbl to `00a9e850`)
- `FUN_0044e560`
- `FUN_00970c00`
- `FUN_0043b910`
- `FUN_00732e80`
- `FUN_00995f60`
- `FUN_0073b9a0`

**Xrefs:** 9.

**Sibling:** dtor pattern `FUN_00745ff0` (same base vtbl + `DeleteCriticalSection`).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| `RET 0xC` + EDX type token ABI | **High** |
| Layout offsets + CS at `+0x20` | **High** |
| Object size `0x3c` (caller new) | **High** |
| Product class name `NDResource` | **High** role / **Probable** spelling |
| `vtbl+4` optionalSrc semantics | **Tentative** |
