# Review B (skeptical / adversarial): `FUN_008af020` @ `0x008af020`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008af020` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008af020_Client_MissionDialog_PrimaryButtonClose.md` |
| **Verdict** | **accept-with-gaps** on CF + sibling-close role + flush chain link; **do not** overclaim exclusive Accept path or msg-0x0D product ID |

---

## 1. Claims under attack

| # | Claim | Attack | Outcome |
|---|---|---|---|
| 1 | This is *the* mission-dialog accept handler | Real accept logic is `Client_MissionDialogHandleButton`; this only wraps context 0 + close | **Hits naming** — unit is glue, not router |
| 2 | Only path that flushes 0x206E | Sibling `FUN_008aec40` also calls `FUN_007fca10` on success/close | **Hits exclusivity** — alt, not sole |
| 3 | Always closes dialog | Close gated on HandleButton ≠ 0; state 2 context 1 returns 0 (modal) → no close here | **Survives with gate** |
| 4 | `+0x648==2` means “abandon journal” always reopen | Same reopen used after abandon modal confirm (`FUN_007fef20(0x13,1,0)` elsewhere); index 0x13 identity still inferred | **Mechanism High; English Medium** |
| 5 | Decompiler `unaff_retaddr` is real 2nd arg | Asm only `push 0`; HandleButton body does not use `iButtonIndex` | **Decompiler lag** — ignore 2nd arg |
| 6 | `CONCAT31` return is multi-byte status | Asm `mov al,1; ret` only | **Decompiler noise** |
| 7 | Direct vtable entry is this VA | Vtable points at parent `0x008af060`; this is CALLed for msg `0x0D` only | **Must document indirection** |
| 8 | Msg `0x0D` == BN_CLICKED / Accept | Only integer compare in parent; no string | **Unproven product meaning** |
| 9 | Safe after GiveMission hide | State 1 may HideMissionDialogIfOpen then still `FUN_007fca10` | **Static double-path**; not proven harmful |
| 10 | Missing function would break dual A/B wave | Function **exists** (body + xrefs) | **Exists** — dual proceeds |

---

## 2. What the evidence actually proves

| Fact | Strength |
|---|---|
| Function body at `0x008af020`–`0x008af056` | **Proven** (Ghidra + bytes) |
| Calls HandleButton with stack arg 0 and EAX=ESI | **Proven** |
| On AL≠0 calls `FUN_007fca10` with EBX=`DAT_00d1a840` | **Proven** |
| Then if `[ESI+0x648]==2` calls `FUN_007fef20(0x13,1,0)` with ECX=client | **Proven** |
| Returns AL=1 | **Proven** |
| Sole CODE xref is CALL @ `0x008af090` in parent @ `0x008af060` | **Proven** |
| Parent is DATA at vtbl `0x00a4a870` (offset +0x354 from `0x00a4a51c`) | **Proven** |
| Parent only reaches this on message id `0x0D` | **Proven** (asm) |
| Same close+reopen tail as `FUN_008aec40` success/close | **Proven** (decompile compare) |
| Live user binding of msg 0x0D | **Not proven** |
| Table index 0x13 object class name | **Probable** (mission UI reopen pattern) |

---

## 3. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Body CF / callees | High | Wrong close chain |
| ESI dialog +0x648 state field | High | Wrong reopen gate |
| Flush via FUN_007fca10 | High (static) | Miss 0x206E path |
| Sibling-of-008aec40 close tail | High | Duplicate analysis debt |
| Primary context always 0 | High | Wrong button id |
| Name “PrimaryButtonClose” | Probable | Rename churn |
| Msg 0x0D = Accept click | Tentative | Wrong UI event mapping |
| Exclusive accept UX path | **Low / false** | Ignore list/button ids path |

---

## 4. Surviving contract for AutoCore

```
Mission dialog object (ESI / parent ECX)
  thin path FUN_008af020 @ 0x008af020:
    success = Client_MissionDialogHandleButton(dialog, context=0)
    if (!success) return 1;
    FUN_007fca10(client=DAT_00d1a840)   // visible → vtbl+0x440 FlushPreparedResponse
    if (*(dialog+0x648) == 2)
      FUN_007fef20(client, dialogIndex=0x13, open=1, flag=0)
    return 1

Reachability (static):
  dialog vtbl+0x354 → code 0x008af060
    if msgId == 0x0D: call FUN_008af020

Not this unit:
  full button id matrix / list / reward hover (FUN_008aec40)
  HandleButton state machine (aa_008ae7c0)
  Flush send body (aa_008ab8f0)
```

---

## 5. Open questions (must not be papered over)

1. What UI framework message is **`0x0D`** (product docs / other dispatch tables)?
2. Exact dialog class at client table index **`0x13`** (journal vs other mission chrome)?
3. Runtime: does Accept on NPC dialog hit msg `0x0D` or only sibling btn ids `0x9c46..`?
4. After state-1 GiveMission + Hide, does second `FUN_007fca10` still flush nonzero `+0x650`?

---

## 6. Verdict

**accept-with-gaps.**

Adversarial position: body is **tiny, well-sealed glue** — not a second HandleButton. Treat as **dialog close sibling** under parent vtbl+0x354 / msg `0x0D`. Keep dual verdict below full **accept** until runtime msg mapping and optional rename settle. Do **not** claim sole Accept or sole Flush invoker.
