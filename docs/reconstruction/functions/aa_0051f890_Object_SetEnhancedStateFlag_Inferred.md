# Function record: Object_SetEnhancedStateFlag_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0051f890` |
| **Canonical name** | `Object_SetEnhancedStateFlag_Inferred` |
| **Ghidra name** | `FUN_0051f890` |
| **Address** | `0x0051f890`–`0x0051f89c` (**13 B**; pad `CC` after) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | object / character status |
| **Completion status** | **Dual A/B complete** (2026-07-29 OWN-ONLY W28-G) — **accept** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0051f890`
- Prior scaffold plate only

## Purpose

**Leaf flag setter:** write `uint8_t` to `this+0x6b9` (enhanced-state gate). No validation, no side effects, no callees. Parent activate path sets **1**; a second undelimited code site clears with **0**.

## Signature (image-sealed)

```c
// __thiscall ECX=this, stack fEnhanced, ret 4, void
void Object_SetEnhancedStateFlag_Inferred(void *this, uint8_t fEnhanced);
```

## Artifacts

| Role | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.md` |
| Annotated | `docs/reconstruction/raw/aa_0051f890_FUN_0051f890.annotated.md` |
| Clean named | `docs/reconstruction/reconstructed-exact/Object_SetEnhancedStateFlag_Inferred.cpp` |
| Clean alias | `docs/reconstruction/reconstructed-exact/FUN_0051f890.cpp` |
| Review A | `docs/reconstruction/reviews/A_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` |
| Review B | `docs/reconstruction/reviews/B_aa_0051f890_Object_SetEnhancedStateFlag_Inferred.md` |
| Scaffold record | `docs/reconstruction/functions/aa_0051f890_FUN_0051f890.md` |
| Dual report | `docs/agents/task-dual-ab-0051f890-006264e0-w28g-report.md` |

## Callers / callees

| Direction | Address | Name / role |
|---|---|---|
| Caller | `0x00626890` / site `0x00626916` | `Object_ActivatePlayerEnqueueHB_Inferred` — `push 1` set |
| Code xref | `0x0062667b` | undelimited; `push 0` clear (no Ghidra function) |
| Callees | — | none |

## Layout / constants

| Item | Value | Conf |
|---|---|---|
| Flag byte offset | `+0x6b9` | **High** |
| ABI `ret 4` | `C2 04 00` | **High** |
| Role = enhanced-state | string/readers siblings | **High** (role) / product spelling **Inferred** |

## Confidence

| Claim | Level |
|---|---|
| Control flow / bytes | **High** |
| ABI thiscall + 1 byte stack arg | **High** |
| Enhanced-state role of +0x6b9 | **High** (cross-unit string + readers) |
| Product method name | **Tentative / Inferred** |
| Exhaustive writer set | **Open** (2 code xrefs known) |
