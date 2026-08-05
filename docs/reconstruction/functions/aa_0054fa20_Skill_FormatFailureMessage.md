# Function record: Skill_FormatFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fa20` |
| **Canonical name** | `Skill_FormatFailureMessage` |
| **Address** | `0x0054fa20` |
| **Span** | `0x0054fa20`–`0x0054fdf9` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **Calling convention** | MSVC `__cdecl` |
| **Return type** | `char*` (`pOutBuf`, or `""` if null) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual** — sealed eSkillResponses English string table + enum crosswalk; 0x10 CF residual |
| **Bit-for-bit / runtime / diff** | Open (deferred / not run) |

---

## 1. Summary

Client-side **eSkillResponses → toast/chat string** bridge. Fills caller-provided C buffer via locale lookup (`FUN_007a6de0`) of English keys. Switch covers **1–14** and **0x12** as fixed strings; **0x10** is a summon-level-cap sprintf path needing optional `pCharacterCtx`; all other codes (including **0**, **0x0F**, **0x11**, **99**) fall through **default** `"Unhandled reason for skill failure."`. Null `pOutBuf` returns empty string without write. **No cast mutation.**

---

## 2. Signature

```c
char* __cdecl Skill_FormatFailureMessage(
    int eSkillResponse,   // eSkillResponses
    char* pOutBuf,        // output C string buffer (caller-owned)
    void* pCharacterCtx); // optional; used only for case 0x10 summon cap
```

---

## 3. Sealed string table (VERIFIED 2026-07-29 residual)

Crosswalk: English keys from decompile switch; enum names from `Documentation/PACKET STRUCTURES.md` `eSkillResponses` (product labels; not retyped into clean).

| Code | Hex | Enum name (docs) | English key / path |
|---:|---|---|---|
| 0 | 0x00 | OK | *(default if formatted)* Unhandled reason for skill failure. |
| 1 | 0x01 | SERVER_CHECKS_FAILED | Server checks failed! |
| 2 | 0x02 | GENERIC_FAILED | Skill failed. |
| 3 | 0x03 | CORPSE | Cannot do that while wrecked! |
| 4 | 0x04 | POWER | You don't have enough power! |
| 5 | 0x05 | STATUS | You can't do that with your current status. |
| 6 | 0x06 | BUSY | You're already actively using a skill! |
| 7 | 0x07 | RECHARGE | This skill is not ready to use again yet! |
| 8 | 0x08 | SUMMONCOUNT | You have too many of that summon. |
| 9 | 0x09 | NOAIR | You can't do that while in the air. |
| 10 | 0x0A | EXCLUSIVE | You have an active skill that prevents you from doing that. |
| 11 | 0x0B | NEEDSTEALTH | You must be hidden to use this. |
| 12 | 0x0C | NOSTEALTH | You can't do this while hidden. |
| 13 | 0x0D | RANGE | Target out of range. |
| 14 | 0x0E | FACTION | Wrong target type. |
| 15 | 0x0F | AI_DIDNT_CAST | *(default)* Unhandled… — LocalRange accuracy miss also uses 0x0F |
| 16 | 0x10 | SUMMONCOUNT_TOTAL | sprintf summon cap (or case-8 fallback) |
| 17 | 0x11 | CANCELLED_ACTIVE | *(default)* Unhandled… — wire cancel |
| 18 | 0x12 | TOO_SOON | Target has just been stunted |
| 99 | 0x63 | DEATHCAST | *(default)* Unhandled… |

**Name≠UX residual:** CORPSE↔wrecked, FACTION↔wrong target type, TOO_SOON↔stunted. AutoCore toast parity uses **English keys**.

### Case 0x10 sprintf

- With valid `pCharacterCtx` + plant query + count gate (`uVar4 <= uVar3` raw; operand meaning open):
  - `requiredLevel > 0x50` → `"You can only have %d summons at a time."` (via fragment keys)
  - else → `"You can only have %d summons at a time until Level %d."`
- Else → same as case **8**.

---

## 4. Callers / callees

**Callers:** `Client_RecvSkillStatusEffect` (`0x00811170`), `Client_RequestCastSkill` (`0x00941590`), `Client_Skill_ResolveCastTarget` (`0x0093b3a0`), `Client_StanceOrGadgetActivatePath` (`0x0093a3d0`), `FUN_0091f6b0`.

**Callees:** `FUN_007a69d0` (locale ensure), `FUN_007a6de0` (locale lookup), `sprintf`, and for 0x10 only `FUN_004c3f10` / `FUN_004c2e60` / `FUN_004c2eb0` + `pCharacterCtx` vtbl `+0x210`.

**Leave-FUN:** all `FUN_*` above until sealed elsewhere.

---

## 5. Artifacts

| Kind | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054fa20_Skill_FormatFailureMessage.md` |
| Annotated | `docs/reconstruction/raw/aa_0054fa20_Skill_FormatFailureMessage.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FormatFailureMessage.cpp` |
| Dual A | `docs/reconstruction/reviews/A_aa_0054fa20_Skill_FormatFailureMessage.md` |
| Dual B | `docs/reconstruction/reviews/B_aa_0054fa20_Skill_FormatFailureMessage.md` |
| Dual residual | `docs/reconstruction/reviews/a_0054fa20.md` |
| System | `docs/reconstruction/systems/skills-abilities.md` |
| Topic | `docs/topic-extractions/skill-cast.md` |
| Prior scratch | `tmp/a_format_fail.md` |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Function boundary / VA | **High** (named Ghidra; span sealed) |
| Fixed string cases 1–14, 0x12 | **High** (decompile keys) |
| Default residual (0 / 0x0F / 0x11 / 99 / other) | **High** (switch default) |
| Case 0x10 message templates | **High** |
| Case 0x10 plant/count math exactness | **Tentative–Probable** (vtbl + FUN_* opaque) |
| Enum name crosswalk (docs) | **High** for numbers; name≠string is intentional residual |
| Locale helper product names | **Tentative** (FUN_* left) |
| Overall | **Human-refined; table sealed; 0x10 + runtime open** |

---

## 7. Open questions

1. Product names for `FUN_007a69d0` / `FUN_007a6de0` (shared locale).
2. Exact `FUN_004c2e60` / `FUN_004c2eb0` / `FUN_004c3f10` semantics for summon counts (out of unit).
3. Runtime capture of each deny code once for UX parity.
4. Whether any live path formats **0** (should not), **0x0F** (gets generic unhandled), or **99**.

---

## 8. Correction notes

- **2026-07-29 initial dual:** Earlier dual A prose (2026-07-23) shifted mid-table labels (e.g. claimed 9=active-skill, 0x12=summon). Authoritative mapping is §3.
- **2026-07-29 residual:** Wave2 high-signal still said “cases 1–14, **0x12** summon level” — **falsified**. Summon-cap is **0x10** (`SUMMONCOUNT_TOTAL`); **0x12** is stunted / `TOO_SOON`. Dual A/B + this record carry full enum crosswalk.
