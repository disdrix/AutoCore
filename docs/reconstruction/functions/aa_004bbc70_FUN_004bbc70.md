# Function record: FUN_004bbc70

| Field | Value |
|---|---|
| **Stable ID** | `aa_004bbc70` |
| **Canonical name** | `COList_Destructor` |
| **Ghidra name** | `FUN_004bbc70` |
| **Address** | `0x004bbc70`–`0x004bbea4` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client / COList |
| **Completion status** | **Human-refined** + dual A/B **accept** 2026-07-29 (W26-J) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

Scaffold Ghidra symbol record. Canonical: `aa_004bbc70_COList_Destructor.md`.

## Purpose

COList destructor body — see named function record.

## Signature (decompiler-derived)

```c
void __fastcall FUN_004bbc70(uint32_t *param_1);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.md`
- Annotated: `docs/reconstruction/raw/aa_004bbc70_FUN_004bbc70.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/COList_Destructor.cpp`
- Clean scaffold: `docs/reconstruction/reconstructed-exact/FUN_004bbc70.cpp`

## Callers / callees

**Caller:** `FUN_004bd1b0` (scalar-deleting).  
**Callees:** see named record / raw re-verify.

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + bytes | **High** |
| Product class COList | **High** |
| Field English beyond indices | **Partial** |
