# Function record: FUN_004cd8f0

| Field | Value |
|---|---|
| **Stable ID** | `aa_004cd8f0` |
| **Canonical name** | `Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred` (Ghidra `FUN_004cd8f0`) |
| **Address** | `0x004cd8f0` |
| **Body** | `0x004cd8f0`–`0x004cd991` exclusive (**161 B**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | host owned 0x30 grid-list object replace + populate |
| **Completion status** | **Dual A/B complete (W38-S)** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open |

## Purpose

Replace owned grid-list object at host `+0xe4fc` (destroy / new 0x30 / default ctor / scaled populate). See named function record.

## Signature

```c
// __thiscall; ECX = host; stack 4 args; void; ret 0x10
void __thiscall FUN_004cd8f0(void *host, uint32_t a, uint32_t b, uint32_t c, uint32_t ctx);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.md`
- Annotated: `docs/reconstruction/raw/aa_004cd8f0_FUN_004cd8f0.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/FUN_004cd8f0.cpp`
- Named clean: `docs/reconstruction/reconstructed-exact/Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.cpp`
- Named record: `docs/reconstruction/functions/aa_004cd8f0_Host_ReplaceOwnedGridObj_E4FC_CtorPopulate_Inferred.md`

## Callers / callees

| Direction | Detail |
|---|---|
| Callers | none (Ghidra) |
| Callees | `operator_new`, `FUN_005b3f60`, `FUN_005b3fa0`, scalar dtor |

## Confidence

| Claim | Level |
|---|---|
| Control flow + ABI | **Confirmed** |
| Parameter semantic names | **High** for role; float vs dword open at host boundary |
| Product English / live callers | **Open** |
