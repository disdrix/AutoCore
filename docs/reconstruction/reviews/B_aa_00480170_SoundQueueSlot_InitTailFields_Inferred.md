# Review B (skeptical / adversarial): `aa_00480170` SoundQueueSlot_InitTailFields_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00480170` |
| **VA** | `0x00480170` |
| **Canonical name** | `SoundQueueSlot_InitTailFields_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00480170_SoundQueueSlot_InitTailFields_Inferred.md` |
| **System** | client audio / `CSoundManager` queue slot |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | This **allocates** the queue slot | Body is five stores; no `new`/`malloc` | **Falsified** as allocator |
| 2 | Same as freelist pop `00480460` | Different VA; pop vs field init | **Falsified** |
| 3 | `param_1` is the slot | Stores **through** `in_EAX`; reads **from** `param_1` | **Falsified** — slot is EAX |
| 4 | Writes path / name string | Targets `+0x140..`; path is `strncpy` at parent to `+0` | **Falsified** path-init claim |
| 5 | Parent dual “`00480170` = alloc” | Parent `A_aa_007258a0` wording | **Correct parent wording is wrong** — this is **tail init**, freelist is `00480460` |
| 6 | Non-leaf / has callees | analyze: empty callees | **Attack fails** — leaf |
| 7 | Product name required | No string/RTTI | **Agree structural** |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Store offsets `+0x140..+0x14c`, `+0x158=-1` | **Confirmed** | Wrong field map in port |
| Slot via EAX | **Confirmed** | Crash / write wrong object |
| Not allocator | **Confirmed** | Double-free / leak models |
| Clustered with freelist + list insert | **High** | Wrong system ownership |
| 16-byte source identity | **Open** | Init garbage vs intended TFID |
| `-1` semantic | **Open** | Mixer handle misuse |

---

## 3. Cross-check against raw / live

```
raw scaffold CF ≡ live decompile (2026-07-29).
analyze_function_complete: leaf, 3 xrefs, callers 007252d0 / 007258a0 / 00725a70.
Parent 007258a0 sequence:
  iVar = FUN_00480460()
  if iVar: _Dest = FUN_00480170() else null
  strncpy(_Dest, path, 0x104) ...
```

### Parent dual wording trap

`A_aa_007258a0` said “`FUN_00480460` size query → `FUN_00480170` alloc”. **Reject that pairing.** Bodies show:

- `00480460` = aligned freelist pop (may grow slab)
- `00480170` = post-pop tail field init

---

## 4. Surviving contract for AutoCore

```
SoundQueueSlot_InitTailFields(slot_in_EAX, src16):
  slot[+0x140..+0x14c] = *src16 (16 bytes)
  slot[+0x158] = 0xFFFFFFFF
  // no alloc, no list link, no string copy

AutoCore must NOT:
  - treat this VA as operator_new / freelist
  - invent path/name strcpy here (parent does strncpy)
  - assume stack thiscall with slot as first stack arg
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Leaf tail init; EAX slot | **Agree Confirmed** |
| Four dwords + `-1` map | **Agree Confirmed** |
| Not allocator | **Agree Confirmed** |
| Callers in CSoundManager queue cluster | **Agree High** |
| 16-byte source / `-1` meaning open | **Agree** |
| accept-with-gaps | **Agree** |
