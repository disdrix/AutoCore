# Function record: Client_MissionDialogHandleButton

| Field | Value |
|---|---|
| **Stable ID** | `aa_008ae7c0` |
| **Canonical name** | `Client_MissionDialogHandleButton` |
| **Address** | `0x008ae7c0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | missions-progression |
| **Calling convention** | MSVC `__cdecl`; dialog object in EAX |
| **Completion status** | **Human-refined clean** — state matrix sealed; abandon open dual-id High; some UI helpers open |
| **Bit-for-bit / runtime / diff** | Open (runtime residual) |

## Purpose

Dialog button router. State at dialog `+0x648`:

| State | Behavior |
|---|---|
| 0 | Send sector `0x206F` accept-request |
| 1 | Accept offer (`GiveMission`) **or** turn-in complete (`CompleteObjective`) when `+0x64c` |
| 2 | Abandon confirmation modal (dual-id open) |
| 3 | Re-show NPC mission dialog UI |

## Signature

```c
char __cdecl Client_MissionDialogHandleButton(int* pDialogContext, int iButtonIndex);
```

## State 1 notes

- Reward selection masks at `+0x558/+0x55c` and `+0x578/+0x57c`.
- Inventory space via `FUN_005714e0` when reward COID present.
- Turn-in uses last objective in mission list, toast `"Finished Mission"`, then `CompleteObjective`.
- Fills 0x206E **payload** only (`+0x654/+0x658/+0x660`); does **not** send 0x206E.

## State 2 abandon (UF-017 / UF-009)

When `+0x648 == 2` and button context `== 1`:

1. Stash mission id: `DAT_00d1b4b4 = **(dialog+0x670)` or `0xFFFFFFFF`.
2. Build confirm string: `Are you sure you wish to abandon "%s"?`.
3. Open modal via `Client_ShowModalPrompt` (`0x007fdfb0`):
   - **Yes / OK id:** `EAX = 0x4e46` at open site (image `MOV EAX,0x4e46` @ ~`0x008ae8be`) → stored `modal+0x498`
   - **No / Cancel id:** stack secondary **`0x4e47`** (decompiler third arg) → stored `modal+0x49c`
4. Return `0` — **no** C2S, **no** `CVOGReaction_FailMission` in this function.

Decompiler lag: body listing often shows only `FUN_007fdfb0(..., 0x4e47, 1, 0)` and omits EAX. **Do not treat third arg alone as Yes id.**

Static e2e (confirm → C2S `0x20B2` → S2C → FailMission):  
`reviews/CHAIN_2026-07-29_abandon_failmission.md`  
**Residual:** runtime live capture only.

## Confidence by dimension

| Dimension | Level | Rationale |
|---|---|---|
| State matrix 0–3 | High | plate + CF |
| Opcode `0x206F` | High | literal in packet build |
| GiveMission / CompleteObjective wiring | High | named callees |
| 0x206E fill here / send elsewhere | High | Prepare + Flush chain |
| State-2 dual-id Yes `0x4e46` / No `0x4e47` | **High** | open-site image + ShowModalPrompt stores |
| Static abandon e2e (chain) | **High** | outside this body; pointer sealed |
| Dialog field map (+0x648..+0x67c) | Probable | consistent within body |
| Inventory helper `FUN_005714e0` | Probable | full space semantics open |
| Overall | **High (static)** | Runtime button / abandon click open |

## Open questions (updated 2026-07-29)

- ~~Exact C2S `0x206E` send site relative to this handler.~~ **Sealed:** fill only here; send is `Client_MissionDialog_FlushPreparedResponse` @ `0x008ab8f0` (dialog teardown; size 0x20 from `+0x650`). See `reviews/CHAIN_2026-07-29_c2s_206e_seal.md`.
- Full meaning of `pDialogContext` when used as button index vs mode flag.
- ~~Modal Yes id pairing Probable / abandon e2e dual lag.~~ **Sealed High (static):** Yes EAX `0x4e46` / No stack `0x4e47`; e2e → `CHAIN_2026-07-29_abandon_failmission.md`. **Runtime** abandon observation still open.
- Flush invoker after hide (UF-010) — outside this unit’s body proof.
- Accepted / reward overload at `+0x658` vs AutoCore packet bool.

## Related artifacts

| Kind | Path |
|---|---|
| Raw | `raw/aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| Annotated | `raw/aa_008ae7c0_Client_MissionDialogHandleButton.annotated.md` |
| Clean | `reconstructed-exact/Client_MissionDialogHandleButton.cpp` |
| Dual A | `reviews/A_aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| Dual B | `reviews/B_aa_008ae7c0_Client_MissionDialogHandleButton.md` |
| 0x206E flush | `functions/aa_008ab8f0_Client_MissionDialog_FlushPreparedResponse.md` |
| ShowModalPrompt | `functions/aa_007fdfb0_Client_ShowModalPrompt.md` (if present) / duals |
| Abandon e2e chain | `reviews/CHAIN_2026-07-29_abandon_failmission.md` |
| Abandon confirm slice | `reconstructed-exact/Client_UiModalDispatch_AbandonConfirm.cpp` |
