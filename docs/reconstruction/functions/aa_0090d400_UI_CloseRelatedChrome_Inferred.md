# Function record: UI_CloseRelatedChrome_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0090d400` |
| **Canonical name** | `UI_CloseRelatedChrome_Inferred` |
| **Ghidra name** | `FUN_0090d400` |
| **Address** | `0x0090d400`–`0x0090d465` inclusive (**102 B** / `0x66`) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Partition** | MEGA-086 / parent dualed `UI_InteractionMenu_PopulateTargetButtons_Inferred` (`0x0082fe20`) |
| **Completion status** | **Dual A/B sealed** 2026-08-05 — **accept-with-gaps** |
| **Bit-for-bit / runtime / diff** | Open (Terminal **false**) |

## Signature (sealed)

```c
// Register contract (not ECX-thiscall entry); bare RET (C3)
// ESI = primary UI object closed
// EDI = secondary UI object notified / reset
void UI_CloseRelatedChrome_Inferred(void);
```

## Behavior (sealed CF)

1. Null-gate **ESI**; return if zero.
2. `ESI->vtbl+0x3d8()` — if AL == 0, return.
3. `ESI->vtbl+0xcc(0)` then `ESI->vtbl+0x440()`.
4. `EDI->vtbl+0xb0(ESI)`.
5. If `DAT_00d1b978 != 0` and `DAT_00d1b978->vtbl+0x3d8()`: `EDI->vtbl+0x3bc(DAT_00d1b978)`.
6. `EDI->vtbl+0x3f4(-1)`.

## Call-site families

| Family | ESI | EDI |
|---|---|---|
| Interaction menu | menu host | `*(host+0x2B0)` related chrome |
| Table flush `0090dab0` | chrome table entry | host (EAX) |
| Global chrome | chrome global | ambient host |

## Artifacts

| Kind | Path |
|---|---|
| Raw (+ re-verify) | `docs/reconstruction/raw/aa_0090d400_FUN_0090d400.md` |
| Annotated | `docs/reconstruction/raw/aa_0090d400_FUN_0090d400.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/UI_CloseRelatedChrome_Inferred.cpp` |
| Twin | `docs/reconstruction/reconstructed-exact/FUN_0090d400.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0090d400_UI_CloseRelatedChrome_Inferred.md` |
| Report | `docs/agents/task-dual-ab-0090d400-mega-086-report.md` |

## Gaps

- Product class / MSVC demangle for host and chrome.
- English names for vtbl `+0x3d8` / `+0xcc` / `+0x440` / `+0xb0` / `+0x3bc` / `+0x3f4`.
- Product identity of `DAT_00d1b978` (Tell/chat panel indicated only).
- Runtime / bit-exact / differential.

## Confidence

| Claim | Level |
|---|---|
| CF / ABI / offsets | **High** |
| Role name UI_CloseRelatedChrome | **Inferred** (partition + parent edge) |
| Runtime | **Open** |
