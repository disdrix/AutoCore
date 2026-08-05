# Reconstruction review: `aa_00921b50` Client_QuickBarActivateSkillSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_00921b50` |
| **VA** | `0x00921b50` |
| **Canonical name** | `Client_QuickBarActivateSkillSlot` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00921b50_Client_QuickBarActivateSkillSlot.md` | Authoritative decompile; slot walk; inline `0x2030` send |
| Annotated low-level | `docs/reconstruction/raw/aa_00921b50_Client_QuickBarActivateSkillSlot.annotated.md` | Scaffold copy |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` | Clean CF |
| Function record | `docs/reconstruction/functions/aa_00921b50_Client_QuickBarActivateSkillSlot.md` | Partial scaffold |
| Sibling | `reconstructed-exact/Client_RequestCastSkill.cpp` | Parallel send path (context) |
| Topic extraction | `docs/topic-extractions/skill-cast.md` | Layout / HB claims |

**Primary claims under review:**

1. Resolve character from global `DAT_00d1b6d8` chain + vtable `+0x1d8`
2. Walk skill list with traversal lock `+0x1d`, skip entries with `skill+0x615 & 1`, match `nSlotIndex`
3. `Skill_LocalCastValidate` must return `0`
4. Conditional `Skill_StartCastAgainHeartbeat` when world `+0x7e == 0` and `skill+0x61c == 0`
5. Pack `0x2030`, skill id at `skill+0x5fc`, resolve TFID, send size `0x28` via sector conn vtable `+0x18`

**Not re-authored.** Live re-decompile not performed.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw pseudocode | Raw capture | Ground truth |
| Annotated | Annotated | Confirm no CF drift |
| Clean C++ | reconstructed-exact | Line parity |
| Plate comment | Raw header | Packet layout claims vs stores |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Match |
|---|---|
| Character resolve gate | **Yes** |
| Default TFID from character offsets; override if `+0xa4` vehicle/object | **Yes** |
| Traversal lock set/clear around list walk | **Yes** |
| Slot counter vs `nSlotIndex`; skip `+0x615 & 1` | **Yes** |
| LocalCastValidate args `(entity, 0, (char)skill, 0)` | **Yes** (artifact preserved) |
| Optimistic HB + charge vtable `+0x238` | **Yes** |
| Opcode `0x2030`; `iStack_20 = skill+0x5fc` | **Yes** |
| `Client_Skill_ResolveCastTarget` into TFID slots | **Yes** |
| Send via `g_pSectorNetConnection_INFERRED` vtable `+0x18` size `0x28` | **Yes** |
| Optional UI `FUN_0089ff80` | **Yes** |

### 3.2 Absences

Clean correctly does **not** call `Client_RequestCastSkill` (raw also does not). Parallel packer path preserved.

### 3.3 Type renames only

`undefined4` → `uint32_t`; `undefined1` → `uint8_t`. HashError debug strings retained.

---

## 4. Discrepancies or improvements needed

Shared scaffold defects:

| Item | Severity | Notes |
|---|---|---|
| Aim copy from `uStack_60/5c/58` never written in body | Medium | Raw/clean both assign uninitialized locals into aim slots after zeroing `uStack_14/18/1c` — decompiler stack confusion; plate says aim “often 0” |
| `(char)pOwnerCtx` LocalCastValidate | High for ABI | Faithful to raw |
| `unaff_EDI` into StartCastAgainHeartbeat | Medium | Register hole preserved |
| `g_pSectorNetConnection_INFERRED` name | Doc | Inferred global; not sealed type |
| Variable reuse `pSkill` for many roles | Readability | Matches decompiler reuse; not a fidelity error |

**No revision required** for clean-vs-raw fidelity.

---

## 5. What remains uncertain

1. True aim vector source (zeros vs lost stack stores).
2. Global identities (`DAT_00d1b6d8`, sector connection).
3. Skill list container layout (`+0x74`, node `+0x14`, payload `+0x8`).
4. Whether DriveControlTick secondary call path uses same slot encoding.
5. Runtime / CE send capture.

---

## 6. Verdict

### **accept-with-gaps**

Clean matches raw/annotated CF, slot walk, validate gate, HB gate, explicit `skill+0x5fc` skill-id store, and sector send without inventing a RequestCastSkill wrapper.

**Gaps:** aim stack recovery, ABI register holes, no runtime seal.

**Not needs-revision** for faithfulness.

---

## 7. Reviewer role statement

Faithfulness of clean C++ to low-level only. Does not certify live hotbar behavior or aim bytes.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Slot walk + skip flag preserved | **Pass** |
| Skill id `+0x5fc` store preserved | **Pass** |
| Does not invent RequestCastSkill call | **Pass** |
| Aim sources sealed | **Open** |
| Verdict | **accept-with-gaps** |
