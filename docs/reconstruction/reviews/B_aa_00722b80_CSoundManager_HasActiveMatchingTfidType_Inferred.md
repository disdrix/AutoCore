# Review B (skeptical / adversarial): `aa_00722b80` CSoundManager_HasActiveMatchingTfidType_Inferred

| Field | Value |
|---|---|
| **Stable ID** | `aa_00722b80` |
| **VA** | `0x00722b80` |
| **Canonical name** | `CSoundManager_HasActiveMatchingTfidType_Inferred` |
| **Review type** | Skeptical / adversarial |
| **Date** | `2026-07-29` |
| **Counterpart** | `reviews/A_aa_00722b80_CSoundManager_HasActiveMatchingTfidType_Inferred.md` |
| **System** | client audio / `CSoundManager` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Claims under attack

| # | Claim | Attack | Result |
|---|---|---|---|
| 1 | Always true / always queues | Parents treat non-zero as **busy → return 0** | **Falsified** always-true |
| 2 | Matches name string only | Compares type + 64-bit TFID + flags | **Falsified** |
| 3 | Mutates play table | Read-only walk | **Falsified** mutator |
| 4 | `this` is stack formal | `in_EAX` + offsets `+0x210/+0x31C` | **Falsified** stack-this |
| 5 | Sentinel is `lo == -1 \|\| hi == -1` | Test is **`(lo & hi) == -1`** (both all-ones) | **Refine** — AND not OR |
| 6 | Requires **both** active flags | OR of `+0x1C5` / `+0x3A` | **Falsified** both-required |
| 7 | Exclusive to proximity path | Also `Client_PlayNamedInterfaceSound` | **Falsified** exclusive |

---

## 2. Confidence table (adversarial)

| Area | Confidence | Risk if wrong |
|---|---|---|
| Bool busy probe | **Confirmed** | Suppress wrong plays |
| Table `+0x210` / `+0x31C` | **Confirmed** | Walk wrong memory |
| Match fields | **Confirmed** | False busy / false free |
| Active OR flags | **Confirmed** | Miss inactive entries |
| Sentinel AND -1 | **Confirmed** | Wrong invalid TFID |
| Entry object full layout | **Open** | Wrong free/reuse |

---

## 3. Cross-check

```
raw ≡ live.
Parents:
  007258a0: if type in {0xC,0xD} && FUN_00722b80(desc+0x120, +0x124, type): return 0
  Client_PlayNamedInterfaceSound: type in {0xC,0xD,0x28} special; busy check same helper
Leaf: no callees; 2 xrefs
```

### Sentinel trap

`lo & hi == 0xFFFFFFFF` is **not** “either half is -1”. Only the all-ones TFID pair fails early.

### Flag trap

Inactive entries with matching TFID/type must **not** block if both flags are zero.

---

## 4. Surviving contract for AutoCore

```
bool HasActiveMatchingTfidType(mgr, lo, hi, type):
  if (lo & hi) == 0xFFFFFFFF: return false
  for e in mgr.playTable[+0x31C][0..count+0x210):
    if e && e.type(+0x2C)==type && e.tfid=={lo,hi}
       && (e.flag1C5 || e.flag3A): return true
  return false

// Used to suppress duplicate 0xC/0xD (and UI 0x28) plays

AutoCore must NOT:
  - mutate table here
  - require both flags
  - treat as string/name match
```

---

## 5. CF challenge of Review A

| A claim | B position |
|---|---|
| Busy bool over +0x31C | **Agree Confirmed** |
| Offsets type/TFID/flags | **Agree Confirmed** |
| Sentinel AND -1 | **Agree Confirmed** |
| Parent 0xC/0xD(/0x28) gates | **Agree High** |
| accept-with-gaps | **Agree** |
