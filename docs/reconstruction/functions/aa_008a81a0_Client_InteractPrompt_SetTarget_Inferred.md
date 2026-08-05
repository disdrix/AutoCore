# Function record: Client_InteractPrompt_SetTarget_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_008a81a0` |
| **Canonical name** | `Client_InteractPrompt_SetTarget_Inferred` |
| **Ghidra name** | `FUN_008a81a0` |
| **Address** | `0x008a81a0`–`0x008a856e` (**974 bytes**) |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | `interaction-activation` / UI chrome |
| **Completion status** | **accept-with-gaps** — dual A/B sealed 2026-07-29 (W19-I OWN) |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

## Purpose

Update interact-prompt host chrome for a world object held in **ESI**: build `Press <key> to {talk to|pick up|trade with|interact with} <name>` (or clear/hide on null / non-interactable). **Not** a UseObject sender.

## Signature (byte-sealed)

```c
// stack: promptHost*; ESI = target object* (caller convention); RET 4
void Client_InteractPrompt_SetTarget_Inferred(int *promptHost);
```

## Artifacts

- Raw: `docs/reconstruction/raw/aa_008a81a0_FUN_008a81a0.md`
- Annotated: `docs/reconstruction/raw/aa_008a81a0_FUN_008a81a0.annotated.md`
- Clean named: `docs/reconstruction/reconstructed-exact/Client_InteractPrompt_SetTarget_Inferred.cpp`
- Clean FUN_*: `docs/reconstruction/reconstructed-exact/FUN_008a81a0.cpp`
- Review A: `docs/reconstruction/reviews/A_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md`
- Review B: `docs/reconstruction/reviews/B_aa_008a81a0_Client_InteractPrompt_SetTarget_Inferred.md`
- Alias record: `docs/reconstruction/functions/aa_008a81a0_FUN_008a81a0.md`

## Callers / callees

| Direction | Target | Notes |
|---|---|---|
| Caller | `Client_RefreshInteractPromptTarget_Inferred` / `FUN_009210e0` | `0x0092134a`; host `DAT_00d1b8c8` |
| Caller | CODE `0x009254ae` | null-ESI clear path; containing fn undefined |
| Callee | `FUN_007a69d0` | key-bind resolve |
| Callee | `FUN_007a6de0` | localize |
| Callee | `FUN_007f9160` | tip / key fallback gate |
| Callee | `FUN_008a8140` | talkable gate |
| Callee | `FUN_005130e0` | pick-up gate |
| Callee | `CVOGCharacter_FindActiveObjectiveIdForInteract` (`FUN_00524520`) | interact default |
| Callee | `__RTDynamicCast`, `sprintf` | talk cast + format |

## Host fields

| Off | Role |
|---|---|
| `+0x50c` | last target object* |
| `+0x518` / `+0x51c` | copy-through after caption |
| `+0x68c` | prompt widget* (`vtbl+0x1d8` text, `vtbl+0xfc` show @ 0.5f) |

## Confidence

| Claim | Level |
|---|---|
| CF + verbs + ABI `ret 4` + ESI target | **Confirmed** |
| Role = interact chrome setter (not UseObject) | **Confirmed** |
| Product host/class English name | Open (`_Inferred`) |
| Runtime / image diff | Open |
