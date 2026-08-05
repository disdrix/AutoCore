# Review B (skeptical / adversarial): `FUN_008aa760` @ `0x008aa760`

| Field | Value |
|---|---|
| **Stable ID** | `aa_008aa760` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_008aa760_DialogRewardChrome.md` |
| **Verdict** | **accept-with-gaps** on CF + `+0x64c` byte store + caption matrix; **needs-more-evidence** on product names, multi-slot click writer, vtbl method names |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | `+0x64c` is only written by HandleButton | **Falsified** — this function’s first store is `MOV [EDI+0x64c],AL` | **Survives as Show→chrome writer** |
| 2 | `param_3` is a full `int` flag | **Overstated** — stack byte; stored as `undefined1` / `uint8_t` | **Survives as byte; consumers treat non-zero** |
| 3 | Show always passes turn-in=1 | **Falsified** — offer/active paths pass 0; only `FUN_0052b420` true → 1 | **Survives: both values** |
| 4 | Function always fills 4 visible rewards | **Falsified** — hard cap 4, but only resolved hits increment `+0x514`; nulls hide widgets | **Survives as “up to 4 attempts”** |
| 5 | `+0x64c` only affects HandleButton | **Falsified** — also selects reward header strings and multi-reward hint | **Survives as claim-mode bit for UI + C2S path** |
| 6 | Mission Complete banner strings depend on turn-in flag | **Falsified** — `+0x6e8` branch uses only `+0x514` | **Survives: count-only** |
| 7 | Auto-select always runs | **Falsified** — `FUN_008aa3f0(0)` only when count==1 **and** `+0x64c≠0` | **Survives with conditions** |
| 8 | `unaff_EDI` is unreliable decompiler junk | **Falsified** — caller `MOV EDI,EBX` immediately before CALL; all host offsets use EDI | **Survives as dialog this** |
| 9 | `DAT_00a1419b` is a real user-facing sentence | **Falsified** — `read_memory` first byte `0x00` (empty C-string) | **Survives as clear/empty hint** |
| 10 | Clean deleted the multi-reward branch | **Falsified** — clean preserves all caption/hint branches | **Survives** |
| 11 | Multiple callers pass different layouts | **Falsified this pass** — sole xref is Show @ `0x00943b6b` | **Survives: single owner call** |
| 12 | Scaffold alias `Mission_Mission_Complete_Select_a_reward` is product name | **Overstated** — derived from one banner string only | **Demote to Tentative alias** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Byte store `dialog+0x64c = param_3` | **High** | Accept vs claim inverted in HandleButton |
| EDI = dialog host | **High** | All offsets mapped to wrong object |
| Slot loop max 4 + TFID copy to `+0x558` | **High** | Wrong reward icons / selection index base |
| Resolve null → hide four widget banks | **High** | Ghost icons on empty slots |
| Caption matrix (flag × count) | **High** | Wrong offer vs claim UX strings |
| Single turn-in auto-select → `+0x578/+0x57c` | **High** | CompleteObjective missing reward COIDs |
| Banner `+0x6e8` count-only | **High** | Cosmetic only if wrong |
| `0x3f000000` = 0.5f show alpha | **High** | Cosmetic |
| Empty multi-offer hint `DAT_00a1419b` | **High** | Spurious must-choose on offer |
| Product name of helper | **Open** | Registry / clean symbol noise |
| Multi-reward click → selection writer | **Open** | Claim path missing user choice |
| UI vtbl ordinal product names | **Tentative** | Port notes mislabel widgets |
| Exact 8-byte TFID layout semantics | **Tentative** | Wrong Resolve args if field order inverted |

---

## 3. Cross-check against raw / asm

### 3.1 Authoritative spine

```
FUN_007a69d0()                              // string-table ensure
*(byte*)(dialog+0x64c) = param_3            // MOV [EDI+0x64c], AL
dialog+0x578 = dialog+0x57c = -1
dialog+0x514 = 0
if param_1 && param_2:
  for i in 0..param_2-1, break if i>3:
    copy 8B reward → dialog+0x558 + i*8
    obj = CVOGReaction_ResolveObjectTarget(1, lo, hi)
    if !obj: hide widgets[i]{+0x698,+0x6a8,+0x6b8,+0x6c8}
    else:    load name+".dds"; show icon/name/chrome; ++(+0x514)
  if count==1:
    if +0x64c: FUN_008aa3f0(0)              // select slot 0
    header = +0x64c ? "Your Reward:" : "You Will Receive:"
  elif count>=2:
    header = +0x64c ? "Select A Reward:" : "You Will Get To Choose From:"
    hint   = +0x64c ? "You must choose a reward item first" : empty(DAT_00a1419b)
  else: hide header +0x690
if banner +0x6e8:
  count==0 → "Mission Complete!"
  count==1 → "Mission Complete!  You receive:"
  count>=2 → "Mission Complete!  Select a reward:"
```

### 3.2 Byte store seal

| Evidence | Value |
|---|---|
| Decompile | `*(undefined1 *)(unaff_EDI + 0x64c) = param_3` |
| Bytes | `88 87 4C 06 00 00` @ entry sequence after `FUN_007a69d0` |
| Consumer (external) | HandleButton state 1: `+0x64c==0` GiveMission / `≠0` CompleteObjective + reward COIDs |

### 3.3 Call framing seal

| Item | Evidence |
|---|---|
| Sole caller | `Client_ShowNpcMissionDialogUI` |
| Call VA | `0x00943b6b` |
| Args | `push flag; push 4; push rewardPtr` (cdecl/right-to-left) |
| This | `MOV EDI,EBX` (EBX = mission UI from Show) |

### 3.4 What this unit is **not**

| Non-claim | Why |
|---|---|
| Does not set `+0x510` chrome mode | Show sets `piVar2[0x144]` before call |
| Does not set `+0x648` button router | No store; HandleButton consumer only |
| Does not send 0x206E | Prepare/Flush elsewhere |
| Does not invent multi-reward click handling | Only auto-select single turn-in via `FUN_008aa3f0` |

Clean preserves spine. **No deleted branches.**

---

## 4. Surviving contract for AutoCore

```
// dialog = mission dialog UI (EDI / client+0x1058 object)
void Dialog_FillRewardChrome(dialog, rewardTfid8* rewards, int nSlots, uint8_t turnInFlag)
{
  dialog->turnInMode        = turnInFlag;          // +0x64c
  dialog->selectedReward    = {-1,-1};             // +0x578 / +0x57c
  dialog->resolvedRewardCnt = 0;                   // +0x514
  for (i = 0; i < nSlots && i < 4; ++i) {
    dialog->rewardSlot[i] = rewards[i];            // +0x558 + i*8
    if (auto* obj = Resolve(rewards[i])) {
      ShowSlotChrome(dialog, i, obj);              // icon .dds, name, widgets
      dialog->resolvedRewardCnt++;
    } else {
      HideSlotChrome(dialog, i);
    }
  }
  ApplyRewardCaptions(dialog);                     // flag × count strings
  if (dialog->resolvedRewardCnt == 1 && turnInFlag)
    AutoSelectRewardSlot(dialog, 0);               // FUN_008aa3f0 → +0x578/57c
  ApplyMissionCompleteBanner(dialog);              // +0x6e8 by count only
}
```

Downstream (not this function): HandleButton state 1 reads `+0x64c` and selected `+0x578/+0x57c` into prepared 0x206E payload.

---

## 5. Open questions

1. Product / debug name for `FUN_008aa760` (beyond string-derived scaffold alias).
2. Which UI handler writes multi-choice selection into `+0x578/+0x57c` (click path).
3. Vtbl product names for widget methods used here.
4. Whether `+0x6e8` is null on offer-only chrome (always-null vs always-set).
5. Live capture: offer 0/1/2+ rewards vs turn-in 1 vs turn-in multi (caption + auto-select).
6. Bit-diff / runtime vs retail image.

---

## 6. Dual residual vs parent Show unit

Parent dual (`aa_009438f0`) already sealed “`+0x64c` via `FUN_008aa760`”. This dual **owns** the helper internals:

| Residual | Status after this dual |
|---|---|
| First-store `+0x64c` byte | **Sealed** (decomp + `MOV [EDI+0x64c],AL`) |
| Caption matrix on flag | **Sealed** |
| Auto-select single turn-in | **Sealed** (→ `FUN_008aa3f0`) |
| Slot/widget layout detail | **High layout / Tentative product names** |
| Multi-reward selection writer | **Open** (out of unit) |

**Verdict:** accept-with-gaps.
