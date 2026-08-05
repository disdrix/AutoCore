# Function record: `Net_SockaddrIn_Init`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0a0` |
| **Canonical name** | `Net_SockaddrIn_Init` (structural) |
| **Ghidra name** | `FUN_0067b0a0` |
| **Address** | `0x0067b0a0` |
| **Body** | `0067b0a0`–`0067b0d0` (49 B through `ret 8` + `CC` pad) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `network` / sockaddr fill |
| **Completion status** | **Dual A/B sealed 2026-07-29 (W17-C)** — accept |
| **Bit-for-bit / runtime / diff** | Open (deferred) |

## Alias

- Prior scaffold: `FUN_0067b0a0`
- Prior auto-alias: `Named_CalleeOf_Named_CalleeOf_Client_EncryptAndPrepareAuthReque_0067b0a0`
- Sibling wrapper: `Net_SockaddrIn_InitInvalid` (`aa_0046e280`)

## Purpose

Fill a 16-byte IPv4 endpoint buffer: zero → `AF_INET` → store addr dword → `htons(port)` → return buffer.

## Signature

```c
SockaddrIn16 * __thiscall Net_SockaddrIn_Init(SockaddrIn16 *sa, uint32_t ipv4Addr, uint16_t hostPort);
// epilogue: ret 8
```

## Layout

| Off | Field | Value |
|----:|-------|-------|
| +0 | family | `2` (AF_INET) |
| +2 | port | `htons(hostPort)` |
| +4 | addr | `ipv4Addr` (no htonl) |
| +8..+F | pad | 0 |

## Artifacts

| Kind | Path |
|------|------|
| Raw | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.md` (+ 2026-07-29 live append) |
| Annotated | `docs/reconstruction/raw/aa_0067b0a0_FUN_0067b0a0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Net_SockaddrIn_Init.cpp` |
| Scaffold clean | `docs/reconstruction/reconstructed-exact/FUN_0067b0a0.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0067b0a0_Net_SockaddrIn_Init.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0067b0a0_Net_SockaddrIn_Init.md` |

## Callers / callees

**Callees:** `htons` (IAT `0x009c6830`)

**Callers (direct):**

| Symbol | VA |
|--------|-----|
| `Net_SockaddrIn_InitInvalid` / `FUN_0046e280` | `0x0046e294` |
| `FUN_00681950` | `0x00681967` |

## Confidence

| Claim | Level |
|---|---|
| Control flow + layout | **Confirmed** |
| thiscall `ret 8` | **Confirmed** |
| No htonl on addr | **Confirmed** |
| Product English type name | **Open** |
