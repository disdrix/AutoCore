# Review A (reconstruction fidelity): `aa_009418e0` Client_CastSkillFromQuickBarSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009418e0` |
| **VA** | `0x009418e0` |
| **Canonical name** | `Client_CastSkillFromQuickBarSlot` |
| **Review date** | `2026-07-29` (dual residual refresh; base 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009418e0_Client_CastSkillFromQuickBarSlot.md` |
| **Residual scratch** | `reviews/a_009418e0.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` |
| Annotated | `docs/reconstruction/raw/aa_009418e0_Client_CastSkillFromQuickBarSlot.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CastSkillFromQuickBarSlot.cpp` |
| Function record | `docs/reconstruction/functions/aa_009418e0_Client_CastSkillFromQuickBarSlot.md` |
| Live Ghidra decompile + asm context | `0x009418e0` (2026-07-29) |
| Callee | `Client_RequestCastSkill` @ `0x00941590` |
| Prompt | `Client_PromptSkillTargetSelect` @ `0x0093bac0` |
| Primary caller | `Client_QuickBar_ActivateSlot` @ `0x009436c0` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Arg is skill id (not slot index) | **Confirmed** | Body + all call sites |
| Client in **ESI** at entry | **Confirmed** | asm residual; callers set ESI / `&DAT_00d1a840` |
| `RET 4` stdcall 1 stack arg | **Confirmed** | epilogue |
| Early-out `FUN_0093b7f0` (EAX=client) + null skill | **Confirmed** | `MOV EAX,ESI` before call |
| Flag `skill+0x614 & 0x800` default TFID aim path | **Confirmed** | `TEST AH,8` |
| Flag `0x800` set + `0x20` clear → PromptTargetSelect return | **Confirmed** | `PUSH 1; PUSH ESI; CALL 0093bac0` |
| Both flags set → cast with invalid TFID seed + zero aim | **High** | Fall-through; runtime intent open |
| Selection `+0xa4` vs self/related TFID | **High** | Nested CF |
| Bit5 on selected skips aim fill → cast with zero aim | **High** | Raw goto preserved |
| Terminal `Client_RequestCastSkill` skill + TFID×4 + aim ptr | **High** | Handoff; RequestCast residual sealed packet |
| Live decompile ≡ frozen raw | **Confirmed** | 2026-07-29 re-decompile |

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| Invalid TFID seed + zero aim | **Yes** |
| Block / skill lookup | **Yes** |
| Flag 0x800 / 0x20 arms | **Yes** |
| Terminal RequestCast | **Yes** |
| Clean adds explicit `client` formal for ESI | **Yes** (documented lift) |

---

## 4. Gaps (post-residual)

1. ~~Client register OPEN~~ **Closed** — ESI Confirmed.
2. ~~Callers / slot→skill OPEN~~ **Closed** — ActivateSlot type-1 + 3 other skill-id callers.
3. ~~`FUN_0093bac0` identity OPEN~~ **Closed** — `Client_PromptSkillTargetSelect`; skillId→`client+0x30c0`.
4. `FUN_0093b7f0` **product name** still open (role sealed: cast-block + feedback strings).
5. Semantic **enum names** for `skill+0x614` bits still open (masks sealed).
6. Runtime / bit-exact open.

**Verdict:** Pre-cast aim/target resolver CF faithful; ABI sealed. **accept-with-gaps.**
