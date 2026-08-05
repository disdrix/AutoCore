# Review A (reconstruction fidelity): `aa_0054fa20` Skill_FormatFailureMessage

| Field | Value |
|---|---|
| **Stable ID** | `aa_0054fa20` |
| **VA** | `0x0054fa20` |
| **Canonical name** | `Skill_FormatFailureMessage` |
| **Review date** | `2026-07-29` (residual strengthen) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_0054fa20_Skill_FormatFailureMessage.md` |
| **Residual scratch** | `reviews/a_0054fa20.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept** (eSkillResponses string table sealed; 0x10 helper math residual) |

---

## 1. Purpose

Map `eSkillResponses` → user-facing toast/chat C string into `pOutBuf` (`__cdecl`). Pure UX formatter — no cast mutation. Locale ensure + key lookup, then byte-copy or sprintf.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_0054fa20_Skill_FormatFailureMessage.md` (+ re-verify appends) |
| Annotated | `docs/reconstruction/raw/aa_0054fa20_Skill_FormatFailureMessage.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Skill_FormatFailureMessage.cpp` |
| Function record | `docs/reconstruction/functions/aa_0054fa20_Skill_FormatFailureMessage.md` |
| Residual dual | `docs/reconstruction/reviews/a_0054fa20.md` |
| PACKET STRUCTURES enum | `Documentation/PACKET STRUCTURES.md` `eSkillResponses` |
| Fresh decompile | Ghidra MCP `decompile_function` @ `0x0054fa20` (2026-07-29 residual) — **≡ raw** |
| Function info | span `0054fa20`–`0054fdf9`; callers ×5; callees locale + sprintf + 0x10 FUN_004c* |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| VA / boundary `0054fa20`–`0054fdf9` | High | Ghidra function info |
| `__cdecl` + null → `""` | High | decompile |
| Cases **1–14** English keys exact | High | string literals in switch |
| Case **0x12** = stunted string (not summon) | High | case label + string; falsifies wave2 |
| Case **0x10** = summon sprintf (not 0x12) | High | goto caseD_10; fragments |
| Default covers 0 / 0x0F / 0x11 / 99 / other | High | switch default |
| No cast mutation | High | out-buf only |
| Pairs LocalCastValidate fail UX (3–7, 10–12) | High | shared codes; strings sealed here |
| Enum **names** from PACKET STRUCTURES | High doc | labels ≠ UX keys (see §3.1) |
| Case 0x10 vtbl+0x210 / FUN_004c* exact math | Medium/Tentative | opaque helpers out of unit |
| Locale FUN product names | Tentative | leave FUN_* |

### 3.1 Sealed table + enum crosswalk (must match clean/raw)

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
| 15 | 0x0F | AI_DIDNT_CAST | *(default)* Unhandled… |
| 16 | 0x10 | SUMMONCOUNT_TOTAL | summon-cap sprintf / case-8 fallback |
| 17 | 0x11 | CANCELLED_ACTIVE | *(default)* Unhandled… |
| 18 | 0x12 | TOO_SOON | Target has just been stunted |
| 99 | 0x63 | DEATHCAST | *(default)* Unhandled… |

**Name≠string residual (not table defects):** CORPSE↔wrecked, FACTION↔Wrong target type, TOO_SOON↔stunted. AutoCore UX parity follows **English keys**.

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Null gate → locale ensure → switch | Yes |
| Fixed cases 1–14, 0x12 copy locale string | Yes |
| 0x10 goto summon path with sprintf / fallback | Yes |
| Default unhandled | Yes |
| No invented server deny / no cast write | Yes |
| Clean not modernized this pass | Yes |

---

## 5. Gaps / open

1. Summon-count helper product names / exact count-vs-cap / level formula (`FUN_004c3f10` / `FUN_004c2e60` / `FUN_004c2eb0` + vtbl+0x210) — out of unit.
2. Locale helper product names (`FUN_007a69d0` / `FUN_007a6de0`).
3. Runtime toast capture per code (especially **0x0F** accuracy-miss generic unhandled).
4. Live paths formatting **0** or **99** (should be rare/none).

**Verdict:** **accept** for sealed eSkillResponses string table + CF + enum crosswalk; residual only on 0x10 helper internals, locale names, and runtime.
