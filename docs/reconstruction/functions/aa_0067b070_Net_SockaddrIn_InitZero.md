# Function record: `Net_SockaddrIn_InitZero`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b070` |
| **Canonical name** | `Net_SockaddrIn_InitZero` (**Inferred** / structural) |
| **Ghidra name** | `FUN_0067b070` |
| **Address** | `0x0067b070` |
| **Body** | `0067b070`–`0067b094` (37 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network` / sockaddr fill |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W25-O)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Ghidra / scaffold: `FUN_0067b070`
- Prior auto-alias: `Named_CalleeOf_Named_VOGChat_0067b070` (superseded)
- Siblings: `Net_SockaddrIn_Init` @ `0x0067b0a0`; `Net_SockaddrIn_InitInvalid` @ `0x0046e280`

## Purpose

Fill a 16-byte endpoint buffer to all-zero family/addr and `htons(0)` port; return buffer.

## Signature

```c
SockaddrIn16 * __fastcall Net_SockaddrIn_InitZero(SockaddrIn16 *sa);
```

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.md` |
| Annotated | `docs/reconstruction/raw/aa_0067b070_FUN_0067b070.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_InitZero.cpp` |
| Scaffold | `docs/reconstruction/reconstructed-exact/FUN_0067b070.cpp` |
| FUN record | `docs/reconstruction/functions/aa_0067b070_FUN_0067b070.md` |
| Review A | `docs/reconstruction/reviews/A_aa_0067b070_Net_SockaddrIn_InitZero.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0067b070_Net_SockaddrIn_InitZero.md` |

## Callers / callees

**Callees:** `htons` @ IAT `0x009c6830`

**Callers:** 12 symbols (see FUN record) including getsockname/getpeername prep and net object ctors.

## Confidence

| Claim | Level |
|---|---|
| CF + layout | **Confirmed** |
| Structural family name | **High** |
| Product English type | **Open** |
