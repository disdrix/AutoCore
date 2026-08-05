# Function record: netAddress_CopyAssign

| Field | Value |
|---|---|
| **Stable ID** | `aa_0067b0e0` |
| **Canonical name** | `netAddress_CopyAssign` |
| **Ghidra** | `FUN_0067b0e0` |
| **Address** | `0x0067b0e0` |
| **Body span** | `0x0067b0e0`–`0x0067b102` exclusive (34 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | network-nazgul-netAddress |
| **Completion status** | **Dual A/B sealed** (2026-07-29 W25-P OWN-ONLY) |
| **Verdict** | **accept-with-gaps** |

## Purpose

Copy four dwords from source Address into destination Address (`this`). Used after `getpeername`/`getsockname` and in Address copy-ctor paths.

## Signature

```c
void __thiscall netAddress_CopyAssign(NetAddress16 *dest /* this */, const NetAddress16 *src);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.md`
- Annotated: `docs/reconstruction/raw/aa_0067b0e0_FUN_0067b0e0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/netAddress_CopyAssign.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_0067b0e0.cpp`
- Reviews: `A_aa_0067b0e0_netAddress_CopyAssign.md`, `B_aa_0067b0e0_netAddress_CopyAssign.md`

## Gaps

1. Product class English (`netAddress` vs `Address`).
2. Full sockaddr field names (family/port/addr).
3. Runtime / bit-exact.
