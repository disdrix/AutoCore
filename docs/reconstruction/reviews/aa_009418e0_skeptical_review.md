# Skeptical / adversarial review: `Client_CastSkillFromQuickBarSlot` @ `0x009418e0`

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **Review type** | Skeptical / adversarial |
| **Date** | 2026-07-23 |
| **Scope** | Pre-RequestCast skill/target prep unit and naming claims |
| **Verdict** | **needs-more-evidence** |

---

## 1. What was inspected

| Path | Role |
|------|------|
| `raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` | Authoritative body |
| `raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.annotated.md` | Scaffold |
| `reconstructed-exact/Client_CastSkillFromQuickBarSlot.cpp` | Clean |
| `functions/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` | Record |
| `reconstructed-exact/Client_RequestCastSkill.cpp` | Callee |
| `reconstructed-exact/Client_QuickBarActivateSkillSlot.cpp` | Competing “quick bar” path |
| `systems/skills-abilities.md` | System listing |

**Not performed:** re-decompile, runtime, bit producer map for `skill+0x614`.

---

## 2. Evidence used

### Mechanical body

1. `param_1` used only as skill lookup key (`vtable+0x234`) and passed through as first arg to RequestCastSkill — **not** a slot index.
2. `skill+0x614` bit `0x800`: when clear, build TFID from selected/vehicle object `+0x160..+0x16c` and aim from vtable/`FUN_00404c90`.
3. When `0x800` set and bit `0x20` clear: `FUN_0093bac0(client, 1)` and **return without cast**.
4. When `0x800` set and bit `0x20` set: fall through to RequestCast with **invalid TFID seed + zero aim** (initialized at entry).
5. Selection object path can `goto` RequestCast without filling aim if a bit on `piVar1[0x5f]` fails.

### Competing path

`Client_QuickBarActivateSkillSlot` walks a skill list by **slot index**, validates, packs `0x2030` itself — never calls this function.

---

## 3. Attack results

### Claim 1 — Name means “cast the skill bound to quick-bar slot N”

| Sub-claim | Attack result |
|-----------|----------------|
| Function implements slot→cast | **BROKEN.** Signature is `int param_1` used as skill id / lookup key |
| “QuickBar” in name is body-proven | **Unproven.** No slot table, no bar widget, no `nSlotIndex` |
| Role is prep + RequestCastSkill | **Survives** as mechanical role |

**Severity:** High for registry naming if consumers assume slot semantics.

---

### Claim 2 — Always resolves a real target before cast

| Sub-claim | Attack result |
|-----------|----------------|
| Target TFID filled on common path when `0x800` clear | **Not broken** for that arm |
| Always | **BROKEN.** `0x800` set + `0x20` set → RequestCast with invalid TFID seed; selection bit fail → goto without aim fill |

---

### Claim 3 — Flag `0x800` / `0x20` meanings are known

| Sub-claim | Attack result |
|-----------|----------------|
| Masks present | **Not broken** |
| Semantic names (self/ground/item/…) | **None in artifacts** — pure speculation if invented |

**Alternate flag stories (none selected by body):** self-only skill; ground-target skill; item skill; “needs explicit target UI”; cancel-other-mode.

---

### Claim 4 — This is the quick-bar cast path used by hotkeys

| Sub-claim | Attack result |
|-----------|----------------|
| System map lists both this and QuickBarActivate | True as listing |
| Hotkey / bar uses this unit | **Not evidenced here** |
| Relationship to QuickBarActivate | **Unknown** — sibling, not callee/caller |

---

### Claim 5 — Clean is a complete behavioral port

| Sub-claim | Attack result |
|-----------|----------------|
| CF parity with raw | **Holds** |
| ABI-complete (`unaff_ESI`) | **Fails** |
| Safe aim pointer always defined | **Fails** on some goto paths (defaults / uninit decompiler paths) |

---

## 4. Alternate interpretations

### Minimal reading

```
lookup skill(param_1);
if flags say "needs target prep" and bit0x800 clear: fill TFID+aim from selection/vehicle;
else if bit0x20 clear: alternate UI path FUN_0093bac0; return;
RequestCastSkill(param_1, tfid_or_invalid, aim_or_zero);
```

### Not proven

- Slot index API.
- Enum names for `+0x614` bits.
- That FUN_0093bac0 is “target picker” (could be stance, cancel, emote, …).

---

## 5. What was confirmed despite skepticism

1. Terminal handoff to `Client_RequestCastSkill` with six args.
2. Numeric flag tests on `skill+0x614`.
3. Early returns on prep helper / null skill.
4. Independent of QuickBarActivateSkillSlot’s slot walk.
5. Clean did not invent slot math.

---

## 6. Critical contradictions found

### C1 — Name vs signature

Canonical name says **QuickBarSlot**; body consumes **skill id**. System map treats this as “Cast from slot” without evidence.

### C2 — Two “quick bar” cast mechanisms

ActivateSkillSlot builds and sends `0x2030` itself. This unit never sends; it only prepares and calls RequestCast. Docs that collapse them into one path are wrong.

### Body CF

Not overturned: flag-gated prep → RequestCastSkill.

---

## 7. Residual uncertainty

| # | Item | Blocks sealing? |
|---|------|-----------------|
| R1 | `+0x614` bit meanings | Yes for ports of targeting modes |
| R2 | Client register | Yes for API |
| R3 | Callers (who converts slot→skill id?) | Yes for UI wiring |
| R4 | FUN_0093bac0 role | Yes for the `0x20` arm |
| R5 | Runtime | Yes |

---

## 8. Concrete checks performed

1. Confirmed `param_1` never used as slot index (grep body uses: lookup + RequestCast only).
2. Expanded both `0x614` mask branches and fall-through.
3. Traced init of TFID invalid seed and zero aim.
4. Compared to QuickBarActivateSkillSlot for call relationship — **none**.
5. Verified clean goto/flag parity with raw.
6. Checked function record for overclaim — scaffold only.

---

## 9. Verdict

### **`needs-more-evidence`**

Interpretation package oversells “quick bar slot” semantics and does not map skill flag bits. Mechanical prep→RequestCast spine holds.

### Port guidance

- Treat as **skill-id cast prep**, not slot activate.
- Keep flag tests numeric until producers/consumers named.
- Do not delete QuickBarActivate path in favor of this unit alone.

---

## 10. Summary table

| # | Claim | Result |
|---|-------|--------|
| 1 | Slot-index cast | **Falsified** |
| 2 | Always real target | **Falsified** |
| 3 | Flag semantics known | **Fails** |
| 4 | Hotkey wiring proven | **Fails** |
| 5 | ABI-complete clean | **Fails** (`unaff_ESI`) |

**Final verdict: `needs-more-evidence`**
