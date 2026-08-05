# Annotated low-level: CVOGCharacter_HasCompletedMission (`aa_0052aa20`)

| Field | Value |
|---|---|
| **Stable ID** | `aa_0052aa20` |
| **VA** | `0x0052aa20` |
| **Module** | `autoassault.exe` @ image base `0x400000` |
| **System** | missions-progression |
| **Source raw** | `aa_0052aa20_CVOGCharacter_HasCompletedMission.md` (capture 2026-07-23) |

This file is the **annotated** layer: widths, signedness, branch order, side effects, and decompiler corrections. It does not replace the immutable raw capture.

---

## 1. Corrected signature

```c
// MSVC thiscall: ECX = this (CVOGCharacter*)
bool __thiscall CVOGCharacter_HasCompletedMission(CVOGCharacter* this, uint32_t missionId);
```

| Name | Width | Signedness | Origin | Role |
|---|---|---|---|---|
| `this` | 32-bit pointer | unsigned address | `ECX` | Character owning mission hashes |
| `missionId` | **u32** | unsigned | stack arg | Mission definition / hash key |
| return | **bool** (byte / al) | 0/1 | `EAX` | True if treated as already completed |

Decompiler `void*` / `uint` are storage-level; semantic type is character + mission key.

---

## 2. Decompiler corrections

| Decompiler artifact | Correction | Confidence |
|---|---|---|
| `void *this` | **`CVOGCharacter*`** | **High** |
| `uint missionId` | **u32** mission hash key | **High** |
| `FUN_0053fff0()` | Global / singleton mission-definition hash root (returns `undefined4*` → deref to table) | **Probable** |
| `CVOGCharacter_WeaponAllowsKillXpBonus()` | Name is **suspicious** here — used as instance/mode gate selecting `+0x538` vs `+0x53c` completed set | **Tentative** (name may be wrong symbol attach) |
| Continent chain `*(*( *(this+4)+4 ) + this + 0xa8)` | World/continent object pointer; null → simplified path | **High** (structure), role **Probable** |
| Mission def `+0xfc` | Continent / zone id for match vs live continent `+0xfc` | **Probable** |

---

## 3. Pointer / field map (integer-width expanded)

| Offset / expression | Width | Role |
|---|---|---|
| `*(*( *(this+4)+4 ) + this + 0xa8)` | u32 ptr | Continent/world context; **0** → simple completed-hash only |
| `this+0x538` | ptr → CNDHash | **Permanent** completed-mission hash |
| `this+0x53c` | ptr → CNDHash | **Instance** completed-mission hash |
| missionDef `+0xfc` | s32/u32 | Continent id on mission def |
| continentObj `+0xfc` | s32/u32 | Live continent id compared to def |

All `CNDHash_LookupByKey` keys and payloads are **32-bit** pointer / id widths on x86.

---

## 4. Control flow and branches

```text
cont = load_continent_ptr(this)
if (cont == NULL):
    return Lookup(this+0x538, missionId) != NULL     // simple path — never +0x53c

// Path A symbols (short-circuit left-to-right):
//   A = *FUN_0053fff0() == null
//   B = Lookup(defTable, id) == null
//   C = def+0xfc != cont+0xfc
//   D = !modeFlag   (WeaponAllowsKillXpBonus → +0x100==0 && +0xac!=2)
//   E = Lookup(this+0x538, id) != null
// Path A: (A || B || C || D) && E → true
// Path B: modeFlag && Lookup(this+0x53c, id) → true
// else false
```

| Branch | Condition | Effect |
|---|---|---|
| **Simple** | continent ptr == 0 | Only `+0x538`; no def/continent/`+0x53c` |
| **Path A true** | `(A\|\|B\|\|C\|\|D) && E` | `return true` via permanent hash |
| **Path B true** | mode && hit in `+0x53c` | `return true` via instance hash |
| **Match+mode dead-A** | mode && !A && !B && !C (def OK + match) | Path A **cannot** fire; only Path B |
| **Miss** | neither | `return false` |

**Critical row (tighten 2026-07-29):** attached + mode true + def present + `+0xfc` match + hit **only** in `+0x538` → **false**. Naïve `538 || 53c` is wrong.

**Mode gate body (`aa_004ce340`):** not weapon math — `+0x100` clear and `+0xac != 2`. Same polarity as GiveMission dual-hash skip.

Control-flow confidence: **High** on structure and truth table; **Probable** on semantic labels for continent/`+0xfc`.

---

## 5. Side-effect order

1. Read continent pointer chain (up to 3–4 dword loads).
2. Zero or more `CNDHash_LookupByKey` (read-only).
3. Optional `FUN_0053fff0` + def lookup + dword compare at `+0xfc`.
4. Up to two calls to mode-gate helper (no stores observed in this function body).
5. **Return bool only** — **no** writes to character or hashes.

---

## 6. Call-site context

Live Ghidra callers (2026-07-29, 13 xrefs): `CVOGCharacter_CheckMissionRequirements`, `CVOGObject_EvalOfferableMissionInteractState`, `CVOGObject_EvalInteractStateFromChildren`, `Client_UpdateNpcInteractIcons`, `CVOGVariable_EvaluateComputed` (logic var type 9), plus glue `FUN_004d5c10` / `FUN_004d2e50` / `FUN_0052c9d0`.

Sibling: permanent vs instance completed sets matter for instance missions; GiveMission uses the same mode→hash policy when blocking re-grant.

---

## 7. Open questions

- Exact product type of object at continent chain `+0xa8` and field `+0xfc`.
- Producers of mode fields `+0x100` / `+0xac==2` (when instance policy is active).
- Whether simple path (null continent) is logout/UI-only or early-init.
- Runtime inject of both completed hashes under null vs attached continent.
