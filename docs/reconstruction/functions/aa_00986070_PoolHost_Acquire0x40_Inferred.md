# Function record: PoolHost_Acquire0x40_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00986070` |
| **Canonical name** | `PoolHost_Acquire0x40_Inferred` |
| **Ghidra name** | `FUN_00986070` |
| **Address** | `0x00986070`–`0x00986124` inclusive (**181 B** / `0xB5`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | process pool host (`*DAT_00d1f624`) / HostBase aux |
| **Completion status** | **Dual A/B sealed (W33-R)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Purpose

Acquire a **0x40** object from the pool host:

- If freelist @`+0x14/+0x18` empty → `operator_new(0x40)` + `FUN_0074e380` (or 0 on OOM).
- Else pop last freelist entry and shrink via `FUN_00456780(size-1, host+0x10)`.
- Always push result onto track vector @`+4/+8/+0xC` via `FUN_004406e0`.
- Return object\*.

Sole use: `HostBase_EnsureAuxPtrs_Inferred` stores result at `host+4` when `(flags & 1)`.

## Signature

```c
// Retail: EBX = pool host (*DAT_00d1f624); no stack args; bare ret; EAX = obj*
void* PoolHost_Acquire0x40_Inferred(/* EBX */);
```

## Classification

worker (pool acquire)

## Callers / callees

| Dir | Symbol |
|---|---|
| Callers (1) | `FUN_00756320` / `HostBase_EnsureAuxPtrs_Inferred` @ `0x00756352` |
| Callees | `operator_new`, `FUN_0074e380`, `FUN_00456780`, `FUN_004406e0` |

## Related

- Host ensure: `HostBase_EnsureAuxPtrs_Inferred` (`0x00756320`, W32-Q)
- 0x40 ctor: `FUN_0074e380` → sub `FUN_0043fdf0` → `StdList_AllocSentinel_0xC` (`0x004933f0`, W32-P)
- Global: `DAT_00d1f624`

## Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00986070_FUN_00986070.md` |
| Annotated | `docs/reconstruction/raw/aa_00986070_FUN_00986070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/PoolHost_Acquire0x40_Inferred.cpp` |
| Clean twin | `docs/reconstruction/reconstructed-exact/FUN_00986070.cpp` |
| Function FUN_ | `docs/reconstruction/functions/aa_00986070_FUN_00986070.md` |
| A | `docs/reconstruction/reviews/A_aa_00986070_PoolHost_Acquire0x40_Inferred.md` |
| B | `docs/reconstruction/reviews/B_aa_00986070_PoolHost_Acquire0x40_Inferred.md` |

## Confidence

| Claim | Level |
|---|---|
| EBX=pool; empty→new(0x40)+ctor; else pop; track push; return | **High** |
| Body 181 B / SEH / sole caller | **High** |
| Freelist vs track dual-vector layout | **High** (structural) |
| Product pool/element demangle | **Low** |
| Release/freelist push path | **Open** (other VA) |
| Runtime / bit-exact | **Open** |
