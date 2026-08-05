# Review B (skeptical / adversarial): `aa_0071ffc0` CSoundManager_EraseNamedRecordByName_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0071ffc0` |
| **VA** | `0x0071ffc0` |
| **Canonical name** | `CSoundManager_EraseNamedRecordByName_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0071ffc0_CSoundManager_EraseNamedRecordByName_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Marks channel stop flags (`+0x38`) | Body only shifts table + shrinks end | **Falsified** as MarkStop |
| 2 | Uses CS `+0x158` like MarkStopByName | Bytes use **`+0x170`** | **Falsified** same-CS claim |
| 3 | Scans 4 bank slots at `+0x80` | Scans pointer ranges `+0x44`/`+0x54` | **Falsified** |
| 4 | Case-sensitive match | `_stricmp` | **Falsified** case-sensitive |
| 5 | Removes **all** matches | First hit returns | **Falsified** multi-remove |
| 6 | Standard `__thiscall` ECX | Entry uses **ESI**; stack name only; **ret 4** | **Falsified** ECX-thiscall |
| 7 | `FUN_00480970` frees memory | Helper is dword block **move** (0x32×4=200) | **Falsified** free claim |
| 8 | Scaffold invents CF | Live ≡ raw ≡ clean | **Attack fails** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| ESI manager; ret 4 | **Confirmed** | Crash / wrong object |
| CS `+0x170` | **Confirmed** | Race / deadlock vs +0x158 ports |
| Dual ranges + stride 200 | **Confirmed** | Corrupt tables |
| First-match erase only | **Confirmed** | Stale duplicate records |
| Erase = shift, not free block | **High** | Capacity leak if port free() wrongly |
| Record payload fields | **Open** | Incomplete port of queue data |
| A vs B table roles | **Open** | Wrong table targeted |

---

## 3. Cross-check against raw / live

```
push ebx
push ebp
mov  ebp, [esp+0x0C]        ; name
push edi
lea  ebx, [esi+0x170]       ; CS — ESI is manager
push ebx
call [EnterCriticalSection]
mov  edi, [esi+0x44]
cmp  edi, [esi+0x48]
je   try_B
loop_A:
  push ebp / push edi / call [_stricmp] / add esp,8
  test eax,eax / je erase_A
  add  edi, 200
  cmp  edi, [esi+0x48] / jne loop_A
try_B:
  ... same pattern on +0x54/+0x58 ...
erase_*:
  FUN_00480970(match+200, end, match)  ; caller pushes 4 dwords, cleans 0x10
  end -= 200
  LeaveCriticalSection
  ret 4
```

### Parent dual trap

`A_aa_007203b0` called this “extra stop/teardown residual.” **Sealed now:** it is **table erase by name**, not flag stop. MarkStop still does `+0x38`/`+0x1b0` under **different** CS.

### Music-fail path

`FUN_00721a80` after create fail: erase pending named record then release stream object — consistent with queue cleanup, not channel flag scan.

### Extra push on erase call

Fourth stack arg (name) is pushed but `FUN_00480970` only consumes three pointers. Harmless; do not invent a 4-arg erase API.

---

## 4. Surviving contract for AutoCore

```
CSoundManager_EraseNamedRecordByName(mgr /*ESI*/, name):
  lock(mgr.cs_at_0x170)
  if erase_first_match(rangeA stride 200): unlock; return
  if erase_first_match(rangeB stride 200): unlock; return
  unlock

erase_first_match:
  shift tail down with 200-byte moves; end -= 200
  // does NOT free the removed element's heap (if any) here
  // does NOT mark channel +0x38

AutoCore must NOT:
  - use CS +0x158 for this unit
  - treat as MarkStopByName
  - assume ECX thiscall
  - free() on erase without evidence
  - remove all duplicates (binary removes one)
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| ESI manager; ret 4; CS +0x170 | **Agree Confirmed** |
| Two ranges; stride 200; stricmp | **Agree Confirmed** |
| First-match erase + end-=200 | **Agree Confirmed** |
| Not channel MarkStop | **Agree Confirmed** |
| Table names / record schema Open | **Agree** |
| accept-with-gaps | **Agree** |

---

## 6. Open questions

1. Range A vs B product roles.
2. Record fields past name.
3. Runtime.

**Verdict:** **accept-with-gaps** — agree with A; block MarkStop conflation and free-on-erase mistakes.
