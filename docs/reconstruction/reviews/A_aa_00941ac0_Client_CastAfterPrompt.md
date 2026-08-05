# Review A (reconstruction fidelity): `aa_00941ac0` Client_CastAfterPrompt

| Field | Value |
|---|---|
| **Stable ID** | `aa_00941ac0` |
| **VA** | `0x00941ac0` |
| **Canonical name** | `Client_CastAfterPrompt` |
| **Review date** | `2026-07-29` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00941ac0_Client_CastAfterPrompt.md` |
| **Residual scratch** | `reviews/a_00941ac0.md` |
| **System tag** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00941ac0_FUN_00941ac0.md` |
| Annotated | `docs/reconstruction/raw/aa_00941ac0_FUN_00941ac0.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_CastAfterPrompt.cpp` |
| Function record | `docs/reconstruction/functions/aa_00941ac0_Client_CastAfterPrompt.md` |
| Live Ghidra decompile + `read_memory` bytes + call-site asm context | `0x00941ac0` (2026-07-29) |
| Callee cast send | `Client_RequestCastSkill` @ `0x00941590` (`RET 0x18`) |
| Callee block | `Client_CastBlockFeedback` / `FUN_0093b7f0` @ `0x0093b7f0` |
| Callee clear | `Client_PromptSkillTargetSelect` @ `0x0093bac0` |
| Callers | `Client_InteractClickPickTarget` @ `0x00924e29`; `FUN_00861680` @ `0x00861a52` |
| Enter path | `Client_CastSkillFromQuickBarSlot` → Prompt (`+0x30c0`) |
| Sibling residuals | `a_0093bac0.md`, `a_00941590.md`, `a_009418e0.md` |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Body: CastBlock → conditional RequestCast → always Prompt clear | **Confirmed** | live decomp ≡ raw; asm CF |
| Client in **EDI** | **Confirmed** | callers `MOV EDI,0xD1A840`; body `MOV EAX,EDI` twice |
| TFID* in **ESI** (16B) | **Confirmed** | callers `LEA ESI,[obj+0x160]`; body copies 4 dwords |
| Stack formal = aim* ; `RET 4` | **Confirmed** | both xrefs `PUSH &DAT_00d1a640/660`; epilogue `C2 04 00` |
| skillId = `*(client+0x30c0)` | **Confirmed** | `MOV EAX,[EDI+0x30c0]` / `PUSH EAX` before RequestCast |
| `DAT_00d1d900` = `&client+0x30c0` | **Confirmed** | `0xD1A840+0x30C0=0xD1D900` |
| CastBlock return 0 = allow cast | **Confirmed** | `TEST AL,AL` / `JNZ` skip send |
| Prompt clear: EAX=-1, show=0, client=EDI | **Confirmed** | `OR EAX,-1; PUSH 0; PUSH EDI; CALL 0093bac0` |
| RequestCast client in EAX | **Confirmed** | `MOV EAX,EDI` immediately before call; callee `MOV EDI,EAX` |
| RequestCast arg pack: skill + TFID×4 + aim | **Confirmed** | matches sibling CastFromQB call plate; callee `RET 0x18` |
| Does **not** enter prompt (complete only) | **Confirmed** | no show=1 path |
| Live decompile ≡ frozen raw | **Confirmed** | 2026-07-29 re-decompile |

---

## 3. Control flow: clean ≡ raw ≡ live

| Stage | Match |
|---|---|
| CastBlockFeedback (EAX=client) | **Yes** |
| if allow: read `+0x30c0`, copy `*ESI` TFID, call RequestCast | **Yes** |
| Always PromptSkillTargetSelect(client,0) with EAX=-1 | **Yes** |
| `RET 4` | **Yes** |

---

## 4. Sealed handoff plate

```
// retail register + stack convention
//   EDI = client*
//   ESI = TFID*          // usually selected object + 0x160
//   [ESP+4] = aim float3*
void Client_CastAfterPrompt(float* pAim)
{
    if (Client_CastBlockFeedback() == 0) {          // EAX=client in
        int skillId = *(int*)(client + 0x30c0);
        Client_RequestCastSkill(skillId,            // EAX=client in
            tfid[0], tfid[1], tfid[2], tfid[3], pAim);
    }
    // EAX = -1 (mode clear)
    Client_PromptSkillTargetSelect(client, /*show=*/0);
}
```

Wire result on allow path: same C2S `0x2030` size `0x28` as other RequestCast callers (WI-SKL-001); skill id field = pending `+0x30c0`.

---

## 5. Gaps

1. Product English name not in binary strings (role name `Client_CastAfterPrompt` is human).
2. `FUN_00861680` second caller still FUN_* (UI click family).
3. Aim globals `DAT_00d1a640` / `DAT_00d1a660` exact product identity open (default look / zero-aim region).
4. Entry `SUB ESP,8` + `+0x30c4` dead stack store — non-semantic; not required for AutoCore cast complete.
5. Runtime / CE / bit-exact open.

**Verdict:** CF faithful; **`client+0x30c0` → RequestCastSkill sealed**. **accept-with-gaps.**
