# Review B (skeptical / adversarial): `aa_004b6a80` NDSpecialFX_List1e0_AnyFlag10

| Field | Value |
|---|---|
| **Stable ID** | `aa_004b6a80` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` (OWN-ONLY W26-G) |
| **Counterpart** | `reviews/A_aa_004b6a80_NDSpecialFX_List1e0_AnyFlag10.md` |
| **Scratch** | `tmp/a_004b6a80.md` |
| **Verdict** | **accept** |

---

## 1. Claims under attack

| # | Claim | Attack / result |
|---|---|---|
| 1 | Walks list at `+0x204` (owned-child list) | **Falsified** — bytes `MOV ECX,[ECX+0x1e0]` |
| 2 | Tests bit `0x80` / `+0x90e` (peer FX flags) | **Falsified** — `TEST [ESI+0x989], 0x10` |
| 3 | Returns full EAX pointer | **Falsified** — `XOR AL,AL` / `MOV AL,1`; callers use as char |
| 4 | Has callees / mutates list | **Falsified** — leaf read-only walk |
| 5 | cdecl with stack this | **Falsified** — ECX host |
| 6 | Product name is retail | **Overstated** — structural inference only |
| 7 | Always deactivates type 4 | **Falsified** — non-zero **prevents** deactivate path in HostTick |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| List `+0x1e0` + flag `+0x989&0x10` | **High** | Wrong re-enter → FX flicker/leak |
| ECX / AL ABI | **High** | Call-site crash |
| Leaf | **High** | Missed side effects |
| Type-4 re-enter role | **High** | HostTick dual residual left open |
| Flag English | **Open** | Naming only |
| Runtime | **Open** | Matrix policy |

---

## 3. Cross-check against raw + bytes

```
raw / live:
  node = **(host+0x1e0)
  while node != *(host+0x1e0):  // after ECX:=sentinel, compare to ECX
    if ([node+8]+0x989) & 0x10: return 1
    node = *node
  return 0

bytes (40 B full):
  8B 89 E0 01 00 00  … B2 10 … 84 96 89 09 00 00 … 32 C0 5E C3 / B0 01 5E C3
```

Live decompile 2026-07-29 ≡ raw 2026-07-23. Closes residual noted by W24-C HostTick dual for `FUN_004b6a80`.

---

## 4. Surviving contract for AutoCore

```
// Type-4 host keep-active probe:
bool keep = NDSpecialFX_List1e0_AnyFlag10(host);
// true if any residual-list payload has flags[0x989] bit 0x10
// HostTick: if type==4 && keep → active path; else may DeactivateClear
```

---

## 5. Verdict

Adversarial pass **confirms** A: leaf CF/ABI/offsets/caller role sealed → **accept**.
