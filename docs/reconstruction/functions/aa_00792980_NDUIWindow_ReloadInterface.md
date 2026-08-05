# Function record: NDUIWindow_ReloadInterface

| Field | Value |
|---|---|
| **Stable ID** | `aa_00792980` |
| **Canonical name** | `NDUIWindow_ReloadInterface` |
| **Address** | `0x00792980` – `0x00792a41` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | client UI / NDUI (chrome leaf; not mission/skill/inventory domain) |
| **Completion status** | **Three-rep + dual A/B present** (2026-07-29 OWN-ONLY dual) |
| **Dual verdict** | **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Reload an NDUI window interface from a path string (`NDUIWindow_LoadInterfaceFile`), clear cached sub-object at `this+0x4B4` and companion slots `+0x4B8/+0x4BC`. If **path is null**, traverse the child hash at `this+0x4C0` and invoke each child’s virtual `+0x28(0)` (hide/set-visible style), then unlock the hash and call `this` virtual `+0x34c`.

Hot leaf: inventory coverage cites **~241** xrefs (UI ctors / wrappers with `i_*.xml` paths).

## Signature (decompiler + bytes)

```c
// MSVC __thiscall
void __thiscall NDUIWindow_ReloadInterface(void* this /* ECX */, const char* pathOrNull /* stack */);
```

## Key fields (this unit)

| Byte off | Dword idx | Op | Confidence |
|---:|---:|---|---|
| `+0x4B4` | `[0x12d]` | Cond. virtual release `(1)` then zero | **High** |
| `+0x4B8` | `[0x12e]` | Zero | **High** |
| `+0x4BC` | `[0x12f]` | Zero | **High** |
| `+0x4C0` | `[0x130]` | Hash root (null-path only) | **High** |

## Artifacts

- Raw: `docs/reconstruction/raw/aa_00792980_NDUIWindow_ReloadInterface.md`
- Annotated: `docs/reconstruction/raw/aa_00792980_NDUIWindow_ReloadInterface.annotated.md`
- Clean: `docs/reconstruction/reconstructed-exact/NDUIWindow_ReloadInterface.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_00792980_NDUIWindow_ReloadInterface.md`
- Review B: `docs/reconstruction/reviews/B_aa_00792980_NDUIWindow_ReloadInterface.md`

## Callers / callees

**Callees:**

| VA | Name | Notes |
|---|---|---|
| `0x007b0ef0` | `NDUIWindow_LoadInterfaceFile` | Always first; body out of unit |
| `0x00411e10` | `FUN_00411e10` | Hash lock prelude (Probable) |
| `0x007a4480` | `FUN_007a4480` | Debug log (`HashError:TraverseToNext…`, `VOG_DEBUG_STOP`) |

**Callers:** dozens (e.g. `FUN_00825bf0` QB button, options `i_o_*.xml` ctors, `i_d_target.xml`, `i_d_speed.xml`, wrappers that forward `param_2`). Full list via Ghidra xrefs (~241).

## Confidence

| Claim | Level |
|---|---|
| Control flow from decompiler + prologue bytes | **High** |
| Field byte offsets | **High** |
| Null-path-only child hide | **High** |
| Virtual slot product names | **Tentative / Probable** |
| LoadInterfaceFile body | **Out of unit** |
| Parameter product types beyond path string | **Probable** |
