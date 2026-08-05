# Function record: Client_UiToastQueue_Push

| Field | Value |
|---|---|
| **Stable ID** | `aa_0040c5c0` |
| **Canonical name** | `Client_UiToastQueue_Push` |
| **Ghidra / legacy** | `FUN_0040c5c0` |
| **Address** | `0x0040c5c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `missions-progression` (shared UI toast helper; GiveMission path dual owner) |
| **Completion status** | **Dual A/B sealed 2026-07-29** — accept-with-gaps |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Alias

- `FUN_0040c5c0`
- `Named_CalleeOf_Client_RecvCraftFromAssemblyKitResponse_0040c5c0` (historical scaffold alias)

## Purpose

Growable **UI toast element** queue push-back. Element stride **`0x98`**. Fast path in-place POD copy when capacity remains; otherwise grow via `FUN_0040c720` / `FUN_00403980`. Used by GiveMission ("Received Mission"), CompleteObjective, craft success, requirement progress toasts, and other UI sites — **not** mission-state mutation.

## Signature (decompiler-derived + ABI seal)

```c
void __thiscall Client_UiToastQueue_Push(void* toastQueue /* ECX */,
                                         void* pElement  /* stack; sizeof *pElement == 0x98 */);
// ret 4
```

### Queue layout (this VA)

| Offset | Role |
|--------|------|
| `+0x00` | unused in body (open) |
| `+0x04` | begin |
| `+0x08` | end |
| `+0x0C` | capacity end |

### Element layout (caller packing evidence)

| Offset | Role |
|--------|------|
| `+0x00` | `char text[0x80]` |
| `+0x80` | ARGB color (often `0xffeee3d8`) |
| `+0x84` | f32 (often 2.0 @ `0x00a10e74`) |
| `+0x88` | f32 (often 1.5 @ `0x00aaa68c`) |
| `+0x8C` | int (often 0) |
| `+0x90` | int64-ish entity / `-1,-1` pair |

## Typical `this` recovery (callers)

```
obj   = *(*(character + 4) + 4 + character + 0xA8);
queue = (uint8_t*)obj + 0xE8C8;
Client_UiToastQueue_Push(queue, &element);
```

## Artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_0040c5c0_FUN_0040c5c0.md` |
| Annotated | `raw/aa_0040c5c0_FUN_0040c5c0.annotated.md` |
| Clean | `reconstructed-exact/Client_UiToastQueue_Push.cpp` |
| Dual A | `reviews/A_aa_0040c5c0_Client_UiToastQueue_Push.md` |
| Dual B | `reviews/B_aa_0040c5c0_Client_UiToastQueue_Push.md` |
| Scratch | `reviews/a_0040c5c0.md` |

## Callers / callees

**Callees:** `FUN_00404670` (in-place construct loop), `FUN_0040c720` (grow path).

**Callers (named):** `CVOGReaction_GiveMission`, `CVOGReaction_CompleteObjective`, `FUN_005307e0`, `Client_RecvCraftFromAssemblyKitResponse`, `FUN_00637de0`, `FUN_006081b0`, `FUN_007fe8d0`, `FUN_0080db30`, `FUN_00921360`, `FUN_0099c2a0` (+ code xrefs).

## Confidence

| Claim | Level |
|---|---|
| Control flow + stride + ABI | **Confirmed** |
| Toast-queue role | **High** |
| Parameter product names / queue class | **Tentative** / **Open** |
| Element field English | **High** offsets; product words **Open** |
