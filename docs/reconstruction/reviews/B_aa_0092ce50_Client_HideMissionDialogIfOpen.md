# Review B (skeptical / adversarial): `Client_HideMissionDialogIfOpen` @ `0x0092ce50`

| Field | Value |
|---|---|
| **Stable ID** | `aa_0092ce50` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (UF-010 contrast re-seal) |
| **Counterpart** | `reviews/A_aa_0092ce50_Client_HideMissionDialogIfOpen.md` |
| **Verdict** | **accept** — attacks that this is the Flush invoker **fail** |

---

## 1. Claims under attack

| # | Attack claim | Result | Why |
|---|---|---|---|
| 1 | This function **is** the UF-010 Flush invoker | **Falsified** | Body never calls `vtbl+0x440`, `0x008ab8f0`, or `FUN_007fca10` |
| 2 | Hiding dialog sends 0x206E | **Falsified** | No `+0x650`, no `DAT_00d1b4b8`, no send `+0x18` |
| 3 | `+0x107c` is the same host as Flush dialog | **Falsified** | Flush host sealed at `client+0x1058` (idx 10); Hide uses `+0x107c` only |
| 4 | `vtbl+0x448` is Flush | **Falsified** | Flush slot is **`+0x440`** (DATA `0x00a4a95c` → `0x008ab8f0`); Hide uses **`+0x448`** then **`+0x34c`** |
| 5 | Destroys mission / quest state | **Falsified** | UI visibility + layout only |
| 6 | Always creates dialog | **Falsified** | hide-if-open; null and invisible early-outs |
| 7 | HandleButton Hide path substitutes for Flush | **Falsified** | HandleButton can call Hide after fill; Flush is separate `FUN_007fca10` → `+0x440` on close/success lifecycle |

---

## 2. Adversarial byte audit

Full function body (through `C3`) is 55 bytes; remainder INT3 pad. Decoded:

```
cmp  [esi+0x107c], 0
je   exit
mov  ecx, [esi+0x107c]
call [vtbl+0x3d8]          ; visible?
test al, al
je   exit
mov  ecx, [esi+0x107c]
call [vtbl+0x448]          ; hide  — NOT +0x440
mov  ecx, [esi+0x107c]
jmp  [vtbl+0x34c]          ; layout tail  — FFA0
ret
```

**Attack residual:** decompiler warns "jumptable" on `+0x34c`. Asm is plain `FFA0` indirect **jmp** — not a multi-way table. No hidden Flush branch.

**Attack residual:** "Maybe `+0x448` on this object is Flush." Contrast with mission-dialog class: Flush is at **`+0x440`**; on that class **`+0x448` is empty stub** (`FUN_0056f570` per Flush dual). Even under wrong-object assumption, Hide slots do not send.

---

## 3. UF-010 negative seal (B perspective)

True invoker chain (static, sealed on `aa_008ab8f0` dual):

```
FUN_008aec40 / FUN_008af020
  → FUN_007fca10 (if object visible +0x3d8)
    → obj.vtbl+0x440 = Client_MissionDialog_FlushPreparedResponse @ 0x008ab8f0
      → if *(dialog+0x650): send 0x20 via DAT_00d1b4b8 vtbl+0x18
```

Hide sits **outside** that chain:

- Different field (`+0x107c` vs `+0x1058`)
- Different vtable actions (`+0x448/+0x34c` vs `+0x440`)
- Called from HandleButton post-local-ops, not as the close→Flush virtual

**Contract surviving attack:**

```
HideMissionDialogIfOpen(client/*ESI*/):
  UI hide + layout only on missionUiRoot @ +0x107c
  NO packet
  NOT Flush invoker (UF-010)
```

---

## 4. Confidence (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Not Flush invoker | **High** | Misattribute 0x206E send site |
| Host `+0x107c` | **High** | Wrong window |
| Slot triple `+0x3d8/+0x448/+0x34c` | **High** | Stuck / wrong UI op |
| No wire side effects | **High** | False C2S on hide |
| Third caller name @ `0x00954652` | **Low–Med** | Completeness only; CALL target sealed |

---

## 5. Open questions (non-blocking for UF-010)

1. Name/type of object at `client+0x107c`.
2. Function wrapping CALL at `0x00954652`.
3. Runtime live order: Hide vs Flush when both fire on same accept/close — static shows they are independent mechanisms.

**Verdict:** **accept** — UF-010 **negative** seal holds under adversarial review.
