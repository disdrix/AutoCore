# Function record: _com_error_ScalarDeletingDtor

| Field | Value |
|---|---|
| **Stable ID** | `aa_00718250` |
| **Canonical name** | `_com_error_ScalarDeletingDtor` |
| **Ghidra** | `FUN_00718250` |
| **Address** | `0x00718250` |
| **Body span** | `0x00718250`–`0x0071827b` exclusive (43 B) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | crt-com / MSVC `_com_error` |
| **Completion status** | **Dual A/B sealed** (2026-07-29 W25-P OWN-ONLY) |
| **Verdict** | **accept** |

## Purpose

Virtual deleting-dtor entry for `_com_error` (vftable `0x00a14034` slot0). Chains to sealed body dtor `aa_007182e0` then optional heap free.

## Signature

```c
_com_error * __thiscall _com_error_ScalarDeletingDtor(_com_error *self, uint32_t flags);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00718250_FUN_00718250.md`
- Annotated: `docs/reconstruction/raw/aa_00718250_FUN_00718250.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/_com_error_ScalarDeletingDtor.cpp`
- Scaffold: `docs/reconstruction/reconstructed-exact/FUN_00718250.cpp`
- Reviews: `A_aa_00718250__com_error_ScalarDeletingDtor.md`, `B_aa_00718250__com_error_ScalarDeletingDtor.md`

## Sibling duals (context)

- Body dtor: `aa_007182e0` `_com_error::~_com_error`
- Primary ctor: `aa_007181f0`
- Copy ctor: `aa_00718280`

## Gaps

1. Runtime / bit-exact deferred.
2. Vector deleting variant not present on this VA (scalar only).
