# Function record: FUN_0094bed0

| Field | Value |
|---|---|
| **Stable ID** | `aa_0094bed0` |
| **Canonical name** | `Object_009d33c4_FactoryRegisterListed_Inferred` |
| **Ghidra name** | `FUN_0094bed0` |
| **Address** | `0x0094bed0`–`0x0094bf8d` (**190 B** / `0xBE`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object factory / host listing registration |
| **Completion status** | **Dual sealed W30-K** — accept-with-gaps (see named record) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- Named: `Object_009d33c4_FactoryRegisterListed_Inferred`
- Scaffold string-seed: `Named_CalleeOf_Named_CalleeOf_Named_Error_Received_a_packet_of_0094bed0` (superseded)

## Purpose

See `aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md`.

## Signature (image-sealed)

```c
void *FUN_0094bed0(void *host /*EDI*/, uint32_t coid_lo, uint32_t coid_hi); // ret 8
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.md`
- Annotated: `docs/reconstruction/raw/aa_0094bed0_FUN_0094bed0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_0094bed0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/Object_009d33c4_FactoryRegisterListed_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_0094bed0_Object_009d33c4_FactoryRegisterListed_Inferred.md`

## Callers / callees

| Direction | Target |
|---|---|
| Callers (1) | `FUN_008119c0` @ `0x00811a0f` |
| Callees | `operator_new`, `FUN_00575440`, `FUN_00512160`, `FUN_004bc180`, vtbl+8/+0x218/[0] |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI from bytes | **High** |
| Product English | **Low** |
