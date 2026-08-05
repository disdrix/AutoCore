# Function record: `AnimSlot_BindResourceFromPath`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0074ee40` |
| **Canonical name** | `AnimSlot_BindResourceFromPath` (structural, **Inferred**) |
| **Ghidra name** | `FUN_0074ee40` |
| **Address** | `0x0074ee40` |
| **Body** | `0074ee40`–`0074eea9` (through `ret 4`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `client::anim` / ND resource |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W24-S)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra: `FUN_0074ee40`
- Prior scaffold alias: `Named_CalleeOf_Named_CalleeOf_Named_VOG_DEBUG_STOP_0074ee40`
- Role in parent: path/resource bind for 0x78 anim slot (see W18-C `Object_LoadOrReplaceAnimSlot`)

## Purpose

Resolve `pathKey` through `NDResourceCache_LookupOrCreate` on global `DAT_00d1f050`, attach resource at slot `+0x70`, acquire inner at `+0x74`, extract channels (`FUN_00963950`), initialize weights (`FUN_0074eaa0`), return ready bool (0/1) or `0xFFFFFFFF` on failure.

## Signature

```c
uint32_t __thiscall AnimSlot_BindResourceFromPath(AnimSlot *self, void *pathKey);
// epilogue: ret 4
```

## Slot offsets

| Off | Field |
|----:|-------|
| `+0x70` | `NDResource*` (cache entry) |
| `+0x74` | acquired inner object* |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0074ee40_FUN_0074ee40.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/AnimSlot_BindResourceFromPath.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0074ee40.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0074ee40_AnimSlot_BindResourceFromPath.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0074ee40_FUN_0074ee40.md` |

## Callers / callees

**Callees:** `FUN_00449070`, `NDResourceCache_LookupOrCreate`, resource vtbl `+4`, `NDResource_AcquireInnerObject`, `FUN_00963950`, `FUN_0074eaa0`

**Callers (direct, analyze_function_complete):**

| Symbol | Notes |
|--------|-------|
| `FUN_005828b0` | `Object_LoadOrReplaceAnimSlot` (W18-C) — gate `result >= 0` |
| `FUN_00581e20` | `CVOGGraphicsBase_LoadNextChildAsset` |
| `FUN_005866d0`, `FUN_005942d0`, `FUN_00504d40`, `FUN_004c50c0`, `FUN_0073b7f0`, `FUN_009106d0`, `FUN_004930b0` | additional load sites |

## Confidence

| Claim | Level |
|---|---|
| thiscall `ret 4` / one stack path arg | **Confirmed** |
| `+0x70` / `+0x74` store order | **Confirmed** |
| Fail `-1` / success 0–1 from vtbl+4 | **Confirmed** |
| Product ND type / path string form | **Open** |
| Nested helper duals | **Open** (not OWN) |
