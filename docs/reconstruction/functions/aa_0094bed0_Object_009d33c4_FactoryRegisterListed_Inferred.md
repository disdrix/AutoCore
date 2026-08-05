# Function record: Object_009d33c4_FactoryRegisterListed_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bed0` |
| **Canonical name** | `Object_009d33c4_FactoryRegisterListed_Inferred` |
| **Ghidra name** | `FUN_0094bed0` |
| **Address** | `0x0094bed0`–`0x0094bf8d` inclusive (**190 B** / `0xBE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object factory / host listing registration |
| **Completion status** | **Dual sealed W30-K** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |
| **Dual A/B** | `reviews/A_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md`, `reviews/B_aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md` |
| **Last reviewed** | `2026-07-29` (W30-K) |

## Alias

- `FUN_0094bed0` (Ghidra)
- Scaffold: `Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094bed0` — superseded string-seed name

## Purpose

Factory that allocates and complete-constructs an `Object_009d33c4` (size `0x210`), runs two virtual initialization methods against host field `+0xe04` and global `DAT_00af30f4`, stamps COID via `Object_SetCoidIdentity`, and registers the object into the host listing manager at `+0xd34`. Failure HRESULT `< 0` scalar-deletes and returns null.

## Signature (image-sealed)

```c
// EDI = host; stack (coid_lo, coid_hi); ret 8; returns object* or NULL
void *Object_009d33c4_FactoryRegisterListed_Inferred(
    void *host /*EDI*/, uint32_t coid_lo, uint32_t coid_hi);
```

## Callers / callees

| Direction | Target |
|---|---|
| Callers (1) | `FUN_008119c0` @ `0x00811a0f` |
| Callees | `operator_new`; `Object_009d33c4_Ctor` (`0x00575440`); `Object_SetCoidIdentity` (`0x00512160`); `Object_RegisterListed` (`0x004bc180`); vtbl `+8`, `+0x218`, `[0]` |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.md`
- Annotated: `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Object_009d33c4_FactoryRegisterListed_Inferred.cpp`
- Clean twin: `docs/reconstruction/reconstructed-exact/FUN_0094bed0.cpp`
- Scaffold record: `docs/reconstruction/functions/aa_0094bed0_FUN_0094bed0.md`

## Confidence

| Claim | Level |
|---|---|
| Body size / `ret 8` / EDI host ABI | **High** |
| new(0x210) + ctor `00575440` | **High** |
| COID stack formals → `00512160` | **High** |
| Register on `host+0xd34` + fail scalar-delete | **High** |
| Product type English | **Low** (open) |
| vtbl+8 / +0x218 semantics | **Low** (open) |
