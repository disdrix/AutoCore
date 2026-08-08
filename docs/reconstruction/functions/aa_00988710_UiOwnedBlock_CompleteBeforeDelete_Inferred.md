# Function record: UiOwnedBlock_CompleteBeforeDelete_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00988710` |
| **Canonical name** | `UiOwnedBlock_CompleteBeforeDelete_Inferred` |
| **Ghidra name** | `FUN_00988710` |
| **Address** | `0x00988710`–`0x0098879e` (**143 B** / `0x8F`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | UI owned-block complete destructor |
| **Completion status** | **Dual sealed MEGA-123** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (Terminal false) |
| **Dual verdict** | **accept-with-gaps** |

## Purpose

MSVC-style complete destructor for a small heap-owned UI container:

1. Release refcounted iface at `this+0x0C` (refcount at iface+4; destroy via vtbl[+8]).
2. Erase tree `[begin, end)` via `FUN_0044f3c0` (container = this; head @ +0x04; isnil@node+0x25).
3. `operator_delete(head)`; null head and size.
4. Return without freeing host.

## Signature (sealed)

```c
void __fastcall UiOwnedBlock_CompleteBeforeDelete_Inferred(void* self);
// ECX = self; SEH LAB_009ad7cd; bare RET (C3); void
```

## Layout

| Off | Field |
|---|---|
| `+0x04` | tree head (sentinel) |
| `+0x08` | tree size |
| `+0x0C` | refcounted iface* |

## Call graph

```text
UiOwnedBlock_CompleteBeforeDelete_Inferred  [OWN MEGA-123]
  ├─ FUN_0044f3c0          tree erase/clear (isnil@+0x25)
  └─ operator_delete       sentinel head only

Callers (complete-then-delete):
  gfxUIWindow_CompleteDtor 00759de0   slots +0xB0 / +0xB4
  FUN_00586ac0 / FUN_004c0e90         slots +0x20..+0x38
  FUN_0055cdf0 / FUN_0055d750         slots [0..3]

Ctor twin: FUN_009886d0
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00988710_FUN_00988710.md`
- Annotated: `docs/reconstruction/raw/aa_00988710_FUN_00988710.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/UiOwnedBlock_CompleteBeforeDelete_Inferred.cpp`
- Twin: `docs/reconstruction/reconstructed-exact/FUN_00988710.cpp`
- Scaffold (retired): `docs/reconstruction/reconstructed-exact/Named_CalleeOf_Named_gfxUIWindow_00988710.cpp`
- Review A/B: `docs/reconstruction/reviews/A_aa_00988710_*.md`, `B_aa_00988710_*.md`
- Report: `docs/agents/task-dual-ab-00988710-mega-123-report.md`

## Gaps

- Product demangle (no RTTI on helper) → `_Inferred`
- Tree payload / key type
- Iface concrete type
- Runtime Confirmed

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / no-host-free | **High** |
| Name stem CompleteBeforeDelete | **High** (caller pattern + body) |
| Product class English | Tentative |
