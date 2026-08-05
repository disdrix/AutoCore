# Reconstruction review: `aa_00941590` Client_RequestCastSkill

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941590` |
| **VA** | `0x00941590` |
| **Canonical name** | `Client_RequestCastSkill` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role / claims reviewed |
|---|---|---|
| Raw capture | `docs/reconstruction/raw/aa_00941590_Client_RequestCastSkill.md` | Authoritative Ghidra decompile; C2S `0x2030` / size `0x28` plate; LocalCastValidate → resolve TFID → optional cast-again HB → `Client_SendSectorPacket` |
| Annotated low-level | `docs/reconstruction/raw/aa_00941590_Client_RequestCastSkill.annotated.md` | Widths; same CF as raw; scaffold uncertainty on signature/types |
| Exact C++ | `docs/reconstruction/reconstructed-exact/Client_RequestCastSkill.cpp` | Port-shaped rewrite of decompiler CF |
| Function record | `docs/reconstruction/functions/aa_00941590_Client_RequestCastSkill.md` | Partial scaffold; confidence Tentative–Probable |
| System map | `docs/reconstruction/systems/skills-abilities.md` | Cast request entry point |
| Topic extraction | `docs/topic-extractions/skill-cast.md` | Packet layout + optimistic CD claims (context only) |

**Primary claims under review (clean must match low-level):**

1. Guard: client `+0xe98` non-null, skill lookup vtable `+0x234(nSkillId)` non-null, rank short `skill+0x5f6 != 0`
2. On success path: `Skill_LocalCastValidate` returns `0`, then `Client_Skill_ResolveCastTarget`, reject invalid TFID, optional `Skill_StartCastAgainHeartbeat`, pack `0x2030`, `Client_SendSectorPacket(..., 0x28, ...)`
3. On validate failure: `Skill_FormatFailureMessage` + UI call when `DAT_00d1b8dc != 0`
4. No modernization of calling convention beyond typed renames (`undefined4` → `uint32_t`)

**Not re-authored:** No edits to reconstructed-exact, function records, raw, or annotated layers.

**Optional live re-decompile:** Not performed this session. Static evidence is the 2026-07-23 raw capture + annotated copy.

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Authoritative pseudocode | Raw § “Raw pseudocode” | Ground truth for CF, callees, packet stores |
| Plate (WI-SKL-001) | Raw header comment | Claimed packet layout / flow summary |
| Annotated CF | Annotated pseudocode | Confirm scaffold did not silently change branches |
| Clean implementation | `Client_RequestCastSkill.cpp` | Line-by-line map to annotated/raw |
| Cross-caller context | `Client_CastSkillFromQuickBarSlot.cpp` | Arg order into this unit (skill id + TFID dwords + aim) |

No runtime / CE packet capture. No instruction-level body-end measure.

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ annotated ≡ raw

| Stage | Raw / annotated | Clean | Match |
|---|---|---|---|
| Outer skill lookup gate | `e98` + vtable `+0x234` + rank `+0x5f6` | Same | **Yes** |
| Local validate | `Skill_LocalCastValidate(entity, 0, (char)skill, 0)` | Same args + cast | **Yes** |
| Success branch | `iVar2 == 0` | Same | **Yes** |
| Resolve target | `Client_Skill_ResolveCastTarget` | Same | **Yes** |
| Invalid TFID early exit | `TFID_EqualsObjectId` → skip send | Same | **Yes** |
| Optimistic HB gate | world `+0x7e == 0`, binding invalid, `skill+0x61c == 0` | Same | **Yes** |
| Charge UI branch | `skill+0x14 > 0` + binding invalid | Same | **Yes** |
| Packet opcode / size | `0x2030`, size `0x28` | Same | **Yes** |
| QB UI notify | client `+0x10b0` vtable `+0x3d8` / `+0x450` | Same | **Yes** |
| First-time tip | cost fields → tip `0x23` | Same | **Yes** |
| Failure message | `Skill_FormatFailureMessage` + `FUN_008f8200` | Same | **Yes** |

### 3.2 Side-effect order

Clean preserves call order: validate → resolve → (lookup binding / clear / start HB) → (charge FX) → pack → send → optional QB widget → optional tip. Failure path does not send.

### 3.3 Type renames only

`undefined4` → `uint32_t /* or float bits */`, `undefined1` → `uint8_t` are width-preserving renames. No clamps, no extra stores, no reordered branches.

### 3.4 Function record honesty

Record correctly marks **Partial scaffold**, signature Tentative–Probable, runtime Open. That matches the artifact quality.

---

## 4. Discrepancies or improvements needed

None that break clean-vs-raw fidelity. Scaffold defects **shared** by raw/annotated/clean:

| Item | Severity | Notes |
|---|---|---|
| `in_EAX` as implicit client/`this` | High for portability | Decompiler never recovered a formal `this` / first arg; clean leaves `in_EAX` |
| `unaff_EBX` / `unaff_retaddr` into callees | High for exact arg recovery | Passed into `Skill_StartCastAgainHeartbeat` and vtable `+0x238` — not real recovered params |
| `(char)pOwnerCtx` into LocalCastValidate | High for signature seal | Truncates skill pointer in the decompile surface; clean correctly mirrors raw (does not invent a fixed signature) |
| Packet skill-id slot | Medium | Stack packing writes TFID into `iStack_134..128` and aim into `uStack_120..118`; plate claims `+0x18 = skillId`, but no explicit store of original `nSkillId` into that slot is visible after `nSkillId` is overwritten with TFID dword0 |
| Parallel QB path | Out of unit body | `Client_QuickBarActivateSkillSlot` builds `0x2030` without calling this function — clean correctly does not invent a shared helper |

**No revision required** for faithfulness of clean to the filed low-level. Signature recovery / packet slot seal remain open work, not clean-vs-raw drift.

---

## 5. What remains uncertain

1. True calling convention (thiscall client vs free function with hidden register).
2. Whether Ghidra lost a skill-id store into the `0x28` buffer (layout plate vs visible stores).
3. Identity of client `+0xe04` (world/sim) and meaning of `+0x7e`.
4. Full `Client_Skill_ResolveCastTarget` contract (`FUN_0093b3a0` family).
5. Runtime confirmation of optimistic HB + send order.
6. Live re-decompile not performed this review.

---

## 6. Verdict

### **accept-with-gaps**

**Accept because:**

- Clean C++ reproduces raw/annotated control flow, callee order, opcode `0x2030`, size `0x28`, success/failure split, and HB gates without inventing modernized structure.
- Scaffold decompiler artifacts (`in_EAX`, unaff_*, char-truncated skill) are **preserved**, not papered over with unproven “fixed” signatures.
- Function record completion status matches evidence level.

**Gaps (do not block acceptance of *fidelity*):**

- Formal signature and client `this` recovery incomplete.
- Packet skill-id field not sealed against plate.
- No runtime / CE / instruction seal.

**Not reject:** No material fidelity error between clean and low-level.

**Not needs-revision:** No required change to `Client_RequestCastSkill.cpp` solely for raw parity.

---

## 7. Reviewer role statement

This review judges **faithfulness of reconstructed-exact C++ to the low-level evidence** (raw + annotated). It does not certify a production-ready port signature, does not re-author the unit, and does not validate live packet bytes.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Clean callee order matches raw | **Pass** |
| Opcode `0x2030` / size `0x28` preserved | **Pass** |
| No invented clamps / modern API | **Pass** |
| Decompiler register/arg holes preserved (not silently “fixed”) | **Pass** |
| Function record does not overclaim completion | **Pass** |
| Signature / skill-id slot sealed | **Open** (documented gap) |
| Verdict | **accept-with-gaps** |
