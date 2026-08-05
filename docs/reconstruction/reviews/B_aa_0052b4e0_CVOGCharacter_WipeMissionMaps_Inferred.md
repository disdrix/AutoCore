# Review B (skeptical / adversarial): `aa_0052b4e0` CVOGCharacter_WipeMissionMaps_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052b4e0` |
| **VA** | `0x0052b4e0` |
| **Canonical name** | `CVOGCharacter_WipeMissionMaps_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_0052b4e0_CVOGCharacter_WipeMissionMaps_Inferred.md` |
| **System** | missions-progression |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Single hash recreate only | Two recreates (+0x530 and +0x55c) + five clears | **Falsified** single |
| 2 | Clears are freelist-only / no vcall | Five `call [reg+4]` through map objects | **Falsified** |
| 3 | Order is 540 then 548 | Order is **548, 540, 538, 53c, 544** | **Attack fails** — body order fixed |
| 4 | Same recreate helper both ends | `00539dd0` vs `00539e30` (different stamps) | **Falsified** same-helper |
| 5 | Inventory / skill wipe lives here | Only mission-map offsets | **Falsified** domain sprawl |
| 6 | log2Bits hard-coded | Pushed from each hash's `+0x1c` | **Falsified** hardcoded |
| 7 | Recreate duals wrong about +0x530/+0x55c | Callers of recreates are this VA only (static) | **Attack fails** |
| 8 | Can skip middle clears if recreate empties all | Different objects; recreate only 530/55c | **Falsified** skip-clears |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| 7-step linear CF | **Confirmed** | Partial wipe bugs |
| Offset map 530/538/53c/540/544/548/55c | **Confirmed** | Wrong slot clears |
| Dual recreate stamps | **High** | Wrong freelist/alloc |
| System-map English for 538/540/548/55c | **High** | Docs |
| +0x530 / +0x544 English | **Open** | Naming only |
| Caller when-wipe | **Tentative** | Wrong lifecycle docs |

---

## 3. Cross-check against raw / live / bytes

```
read_memory @ 0x0052b4e0:
  56                push esi
  8B F1             mov esi, ecx          ; character
  8B 8E 30 05 00 00 mov ecx, [esi+0x530]
  8A 41 1C          mov al, [ecx+0x1c]
  50                push eax
  E8 …              call FUN_00539dd0
  8B 8E 48 05 00 00 mov ecx, [esi+0x548]
  … call [edx+4] …
  ; 540, 538, 53c, 544 likewise
  ; end: call FUN_00539e30 on [esi+0x55c]
```

### Merge trap

Do **not** merge with individual `CNDHash_Recreate_*` duals — those own teardown/alloc; **this** VA owns the character-level batch order.

Do **not** treat as “clear only” — ends recreate pending (`+0x55c`) and front recreates `+0x530`.

### Order trap

Documented clear order must match body (548 first, not 540). Ports that clear in map-index order will diverge if any clear has side effects.

---

## 4. Surviving contract for AutoCore

```
CVOGCharacter_WipeMissionMaps(ch):
  Recreate(ch+0x530, bits)
  Clear(ch+0x548); Clear(ch+0x540); Clear(ch+0x538);
  Clear(ch+0x53c); Clear(ch+0x544)
  Recreate(ch+0x55c, bits)
```

**Verdict:** **accept-with-gaps** — adversarial review does not break batch wipe contract.
