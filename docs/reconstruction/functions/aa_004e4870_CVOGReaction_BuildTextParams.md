# Function record: CVOGReaction_BuildTextParams

| Field | Value |
|---|---|
| **Stable ID** | `aa_004e4870` |
| **Canonical name** | `CVOGReaction_BuildTextParams` |
| **Address** | `0x004e4870` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Completion status** | **Human-refined scaffold** — clean rewritten; dual review open; node payload type untyped |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Insert one text-parameter node into the doubly-linked list rooted at `this+0x04`. Reaction dialog/toast substitution chain builder.

## Signature (decompiler-derived + refined)

```c
void __thiscall CVOGReaction_BuildTextParams(int thisListHost, uint32_t payload);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_004e4870_CVOGReaction_BuildTextParams.md`
- Annotated: `docs/reconstruction/raw/aa_004e4870_CVOGReaction_BuildTextParams.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/CVOGReaction_BuildTextParams.cpp`

## Callers / callees

| Direction | Symbol / VA | Notes |
|---|---|---|
| Callee | `FUN_004e29c0` | Allocate/link list node |
| Callee | `FUN_004e29f0(1)` | Post-insert hook |
| Callers | reaction text builders (xrefs follow-up) | |

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler | High |
| List head at this+0x04 | High |
| Payload semantic type | Tentative |
