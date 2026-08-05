# Annotated low-level: FUN_008aec40 / Client_MissionDialog_ControlDispatch_Inferred

| Field | Value |
|---|---|
| Stable ID | `aa_008aec40` |
| VA | `0x008aec40` |
| Body span | `008aec40` – `008aefbb` |
| System | `missions-progression` / client mission dialog UI |
| Date | 2026-07-29 (OWN-ONLY dual A/B seal) |
| Canonical (structural) | `Client_MissionDialog_ControlDispatch_Inferred` |
| Ghidra | `FUN_008aec40` |

---

## Machine-level notes

- **Convention:** `__thiscall` — dialog UI object in ECX; stack `(msgType, controlId)`; `ret 8`.
- **Install:** DATA vtable slot `0x00a4a854` → `0x008aec40` (not a direct code CALL site).
- **Role:** Mission dialog **control-message dispatch** for widget IDs in the `0x9c40` band (close, scale, reward slots, accept/abandon buttons, NPC multi-select ≥`0x9c4f`).
- Prefer entry bytes when decompiler invents `unaff_EDI`.
- UF-010/UF-011 chain: close path `0x9c40`/button-success → `LAB_008aef8f` → `FUN_007fca10` → FlushPreparedResponse (C2S `0x206E`) — sealed elsewhere; this VA is the **UI invoker**.

### Signature

```c
// msgType examples: 5, 6, 8, 0x1a
// controlId: 0x9c40.. and NPC multi ≥0x9c4f
undefined4 __thiscall FUN_008aec40(int thisDialog, int msgType, int controlId);
```

### Message / control matrix (High CF)

| controlId | msg | Behavior |
|---|---|---|
| `0x9c46`–`0x9c4d` | 8 | `Client_MissionDialogHandleButton(controlId-0x9c46)` with EAX=this; on non-zero fall into close |
| `>0x9c4e` (≥`0x9c4f`) | 8 | if index in `[+0x72c,+0x730)` dword table → `Client_ShowNpcMissionDialogUI(client, this+0x644, 0)` |
| `0x9c40` (40000) | 8 | close: `FUN_007fca10`; if `+0x648==2` also `FUN_007fef20(0x13,1,0)` |
| `0x9c41` | `0x1a` | read scale from widget `+0x700` vtbl+0x458; apply to `+0x6e0` if changed |
| `0x9c42`–`0x9c45` | 5 | resolve reward TFID; UI rect/focus helpers; optional highlight if not selected reward |
| same | 6 | drag cursor globals `DAT_00d1d8f4/f5`; optional UI; `FUN_0087b500(6,id)` |
| same | 8 | if `+0x64c` reward-mode: `FUN_008aa3f0(id-0x9c42)` then `FUN_0087b500(8,id)` |
| default | any | fallthrough `FUN_0087b500(msg, id)` |

### Dialog object fields touched (this body)

| Off | Use |
|---|---|
| `+0x578/+0x57c` | selected reward TFID |
| `+0x584 / +0x590` | focus style A + scale float |
| `+0x594 / +0x5a0` | focus style B + scale float |
| `+0x644` | mission/context handle into ShowNpc |
| `+0x648` | dialog state (2 = abandon chrome on close) |
| `+0x64c` | reward-selection mode flag |
| `+0x6e0` | primary UI widget (scale apply) |
| `+0x700/+0x704` | secondary widget + integer scale source |
| `+0x72c/+0x730` | NPC multi-select table begin/end (dword ptrs) |
| reward TFID bank | `this+0x558` base for id `0x9c42` via `-0x4dcb8+id*8` |
| reward widget bank | `this+0x698` base for id `0x9c42` via `-0x26a70+id*4` |

### Callees (named + structural)

| Target | Role |
|---|---|
| `Client_MissionDialogHandleButton` `0x008ae7c0` | Accept / claim / abandon / re-show buttons |
| `Client_ShowNpcMissionDialogUI` `0x009438f0` | NPC multi-select re-show |
| `FUN_007fca10` | Close / flush chain (→ FlushPreparedResponse) |
| `FUN_007fef20` | Modal/chrome helper on abandon-state close |
| `CVOGReaction_ResolveObjectTarget` | Reward item resolve |
| `FUN_007fd420` | UI geometry / tooltip pair apply |
| `FUN_008aa3f0` | Reward slot click index handler |
| `FUN_0087b500` | Default / residual control forwarder |
| many vtbl `+0xf8,+0x120,+0x140,+0x158,+0x214,+0x218,+0x34c,+0x458` | Widget get/set/invalidate |

### Decompiler artifacts

1. **`unaff_EDI`** — not a real second stack arg to HandleButton; asm is `push index; mov eax,this; call`.
2. **HandleButton first arg typed `int*`** — value is button index 0..7 (integer).
3. **`get_function_callees` incomplete** — trust full decompile body through `008aefbb`.

---

## Pseudocode (annotated copy of raw CF)

Faithful to raw; see reconstructed-exact for plate comments. Do not modernize control flow.

---

## Open questions

1. Product English name for this vtable slot / class method.
2. Exact UI toolkit meaning of msg 5/6/8/0x1a (focus/drag/click/scroll).
3. Full type of `FUN_0087b500` / `FUN_008aa3f0` / `FUN_007fd420`.
4. Runtime wire: close emits unfilled 0x206E (UF-011 residual).
