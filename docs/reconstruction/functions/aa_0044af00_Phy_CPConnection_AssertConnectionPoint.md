# Function record: Phy_CPConnection_AssertConnectionPoint

| Field | Value |
|---|---|
| **Stable ID** | `aa_0044af00` |
| **Canonical name** | `Phy_CPConnection_AssertConnectionPoint` |
| **Address** | `0x0044af00` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | physics |
| **Completion status** | **Dual A/B sealed 2026-07-29** — three-rep + machine ABI; accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Original / decompiler: `FUN_0044af00`
- Prior auto-slug names (if any): leave on disk; canonical is `Phy_CPConnection_AssertConnectionPoint`

## Purpose

Assert/bind helper for connection-point lookup (`phyCPConnection.h`): resolve connection-point **id** on **`owner+0x64`**, AddRef into a caller smart-pointer slot, or log + fail if missing. **`id == -1`** is explicit none (success, clear slot).

## String evidence

`"..\\palantir/physics/phyCPConnection.h" / "Connection point not found!"`  
(VA strings `0x00aa0880` / `0x00aa08a8`; log line **0x8F**, level **3**)

## Signature (machine-derived multi-reg)

```c
// Not standard MSVC thiscall/fastcall alone — register formals:
//   EAX = int connectionPointId   // -1 = none
//   ECX = void* owner
//   EBX = RefCountedObject** pSmartSlot
//   EDI = void** pOutOwner
//   returns int in EAX: 0 ok, -1 not found; ret (no stack cleanup)
int Phy_CPConnection_AssertConnectionPoint(/* multi-reg */);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0044af00_FUN_0044af00.md`
- Annotated: `docs/reconstruction/raw/aa_0044af00_FUN_0044af00.annotated.md`
- Clean (canonical): `docs/reconstruction/reconstructed-exact/Phy_CPConnection_AssertConnectionPoint.cpp`
- Clean (FUN scaffold retained): `docs/reconstruction/reconstructed-exact/FUN_0044af00.cpp`
- Dual A: `docs/reconstruction/reviews/A_aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md`
- Dual B: `docs/reconstruction/reviews/B_aa_0044af00_Phy_CPConnection_AssertConnectionPoint.md`

## Callers / callees

**Callees**

| VA | Role |
|---|---|
| `0x0040d4b0` | thiscall find-by-id on registry (`owner+0x64`) |
| `vog_LogMessage` | miss path only |

**Callers** (code xrefs, 10 sites / 5 functions)

| Function | VA |
|---|---|
| `FUN_0096dc80` | `0x0096dc80` |
| `FUN_00855ff0` | `0x00855ff0` |
| `ClientSpecialEvent_Respawn_Update` | `0x00979730` |
| `ClientSpecialEvent_TeleportIn_ctor` | `0x00978d20` |
| `FUN_009784f0` | `0x009784f0` |

Typical pattern: allocate 0x10 pair block; call twice with two connection ids; require both returns 0.

## Confidence

| Claim | Level |
|---|---|
| Control flow from machine + decompiler | **High** |
| Multi-reg ABI (EAX/ECX/EBX/EDI) | **High** |
| Naming from string literals | **High** |
| Refcount protocol (+4 count; vtbl+4 / +8) | **High** |
| Registry offset `owner+0x64` | **High** |
| Parameter semantic type names | **Probable** |
| Connection id taxonomy / full C++ types | **Tentative / Open** |
