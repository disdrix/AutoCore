# Function record: Client_CastSkillFromQuickBarSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **Canonical name** | `Client_CastSkillFromQuickBarSlot` |
| **Address** | `0x009418e0` |
| **Module** | `autoassault.exe` (image base `0x400000`) |
| **System** | skills-abilities |
| **Completion status** | **Human-refined + dual residual 2026-07-29** — CF + ESI ABI sealed; flag enum names open |

---

## 1. Summary

Resolves aim / selected-target context for a **skill id**, then calls `Client_RequestCastSkill`. Early-out on cast-block probe (`FUN_0093b7f0`, multi-state “can’t do that while…”) or missing skill. When `skill+0x614` has bit `0x800` and not bit `0x20`, enters target-select mode (`Client_PromptSkillTargetSelect` / `FUN_0093bac0`) without casting — stores skillId at `client+0x30c0`.

**Not** a slot-index walker. Slot→skill is `Client_QuickBar_ActivateSlot` type-1 (and other skill-id callers).

---

## 2. Signature (ABI sealed)

```c
// Retail: client in ESI; skillId @ [ESP+4]; stdcall RET 4
void Client_CastSkillFromQuickBarSlot(int skillId);

// Clean lift:
void Client_CastSkillFromQuickBarSlot(void* client /*ESI*/, int skillId);
```

| Register / slot | Role | Evidence |
|---|---|---|
| **ESI** | Client object | Prologue never loads it; `MOV EAX,ESI` → block probe; `PUSH ESI` → prompt; callers set ESI |
| Stack arg0 | Skill id | `[EBP+8]` → vtbl+0x234 lookup + RequestCast + prompt EAX |
| `RET 4` | stdcall 1 arg | Epilogue `0x0094197d` |

---

## 3. Behavior outline

1. Seed TFID locals from `g_abTfidInvalid_A15870`; zero aim (MOVSS/XORPS)
2. `FUN_0093b7f0()` with EAX=client — nonzero → return
3. Lookup skill on entity `vtbl+0x234(skillId)`; null → return
4. If `(skill+0x614 & 0x800) == 0` (`TEST AH,8` clear):
   - No selection at root-link `+0xa4` → TFID from related/self `+0x160`; aim from `vtbl+0x1a0`
   - Selection present → TFID from selected `+0x160`; if selected flags bit5 set, aim via `FUN_00404c90` after `vtbl+0x1c8`; else goto cast with zero aim
5. Else if `(skill+0x614 & 0x20) == 0`: `Client_PromptSkillTargetSelect(client, 1)` with EAX=skillId; return
6. `Client_RequestCastSkill(skillId, tfid…, &aim)` (client still ESI for callee conventions)

---

## 4. Callers (Ghidra xrefs)

| Caller | Address | skill source |
|---|---|---|
| `Client_QuickBar_ActivateSlot` | `0x009436c0` | QB pack type-1 payload |
| `FUN_00922270` | `0x00922270` | hardpoint skill `+0x5fc` |
| `FUN_008c4fc0` | `0x008c4fc0` | HB skill `+0x5fc` if `+0x614 & 0x200` |
| `FUN_0082f510` | `0x0082f510` | immediate **0xED5** |

Three of four non-ActivateSlot sites set `ESI = &DAT_00d1a840` before call.

---

## 5. Related artifacts

| Kind | Path |
|---|---|
| Raw / annotated | `raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.*` |
| Clean | `reconstructed-exact/Client_CastSkillFromQuickBarSlot.cpp` |
| Residual scratch | `reviews/a_009418e0.md` |
| Dual A/B | `reviews/A_aa_009418e0_*`, `reviews/B_aa_009418e0_*` |
| Callee | `aa_00941590` RequestCastSkill |
| Prompt | `aa_0093bac0` Client_PromptSkillTargetSelect |
| Block probe | `aa_0093b7f0` FUN_0093b7f0 |

---

## 6. Confidence

| Dimension | Level |
|---|---|
| Control flow | **Confirmed** (live ≡ raw) |
| Client ESI + skillId stack | **Confirmed** |
| Flag bit **masks** `0x800` / `0x20` | **Confirmed** |
| Flag bit **names** | Open |
| `FUN_0093b7f0` role | **High** (strings); name open |
| `FUN_0093bac0` name/role | **High** |
| Overall | **Human-refined + dual residual; runtime open** |

---

## 7. Open questions

1. Product name for `FUN_0093b7f0`.
2. Full skill flag enum at `+0x614`.
3. Runtime seal of both-flags-set fall-through.
