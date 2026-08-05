# Review A (reconstruction fidelity): `aa_009436c0` Client_QuickBar_ActivateSlot

| Field | Value |
|---|---|
| **Stable ID** | `aa_009436c0` |
| **VA** | `0x009436c0` |
| **Canonical name** | `Client_QuickBar_ActivateSlot` |
| **Review date** | `2026-07-29` (residual refresh; base 2026-07-23) |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_009436c0_Client_QuickBar_ActivateSlot.md` |
| **System** | `skills-abilities` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Purpose

Hotbar slot dispatcher. Formals `(slot, mode, page)` with client in **EAX**. Resolves page (`-1` → QB UI host `client+0x10b0` → `+0x50c`). **Mode 1** (shift-QB from `PollBoundActions`) selects page via `FUN_008a0ed0` and returns. Else `flatIndex = slot + page*10`, busy latch `client+0x3b80+flatIndex`, then type switch on `client+0x3220+flatIndex*0x18`: **1** skill cast, **2** cargo item use, **5** chat-macro bank. When vehicle-host-visible, slots 0/1 remap to skill-slot cast (on-foot `+0x6b9`) or primary/secondary weapon fire.

---

## 2. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_009436c0_Client_QuickBar_ActivateSlot.md` |
| Annotated | `docs/reconstruction/raw/aa_009436c0_Client_QuickBar_ActivateSlot.annotated.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_QuickBar_ActivateSlot.cpp` |
| Function record | `docs/reconstruction/functions/aa_009436c0_Client_QuickBar_ActivateSlot.md` |
| Related | `Client_CastSkillFromQuickBarSlot`, `Client_QuickBarActivateSkillSlot`, `Input_TryFireSecondaryWeapons`, `Client_Input_PollBoundActions`, `Client_ChatMacroQuickPhrases` |
| System | `docs/reconstruction/systems/skills-abilities.md` |
| Scratch residual | `tmp/a_009436c0.md` |
| Residual callees (Ghidra) | `0x008a0ed0`, `0x00922270`, `0x00941d50`, `0x00941fb0`, `0x005710c0` |

---

## 3. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Client in EAX; (slot, mode, page) formals | **High** | Decomp surface + PollBoundActions callers |
| page==-1 → UI+0x50c | **High** | Direct |
| flatIndex = slot + page*10 | **High** | Arithmetic match |
| mode==1 → page select early (`FUN_008a0ed0`) | **High** | Body; PollBoundActions shift-QB `(i,1,-1)`; callee stores page 0..9 @ UI+0x50c |
| type 1 → CastSkillFromQuickBarSlot(skillId pack) | **High** | Call preserved |
| type 2 cargo find + subtype-8 block | **High** CF; **Medium** subtype product meaning |
| type 5 = **chat-macro bank** (not combat power) | **High** table owner + **Probable** product word | `DAT_00d177c8` owned by `Client_ChatMacroQuickPhrases`; activate walks 5 phrases; `FUN_00941fb0` builds **0x2021** |
| Type-5 window: `int64(payload)+3000 ∈ [0,14]` | **High** | `0xfffff447 == UINT32_MAX-3000` carry; gate `hiAdj<1 && (hiAdj<0 \|\| loPlus<0xf) && hiAdj>=-1` |
| Packing `(idx*3+0x645)*8` ≡ `0x3220+idx*0x18+8` | **High** | Algebra; type@+0, payload@+8 of stride-0x18 record |
| On-foot slot0/1 remap | **High** | `+0x6b9` gate |
| Slot0 off-foot → primary fire path `FUN_00922270` | **High** role | Sibling of Secondary; hardpoint skill walk then heat/fire |
| Slot1 off-foot → `Input_TryFireSecondaryWeapons` | **High** | Named callee |
| Busy latch `+0x3b80+idx` set/clear | **High** | Preserved; subtype-8 return may leave latch set |
| Outer vehicle-host visibility gate polarity | **High** CF | Compound on-foot/flag + host vtbl+0x3d8 |

---

## 4. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| Vehicle-visible vs UI path | **Yes** |
| Mode-1 early page select | **Yes** |
| Type switch + latch | **Yes** |
| Slot0/1 on-foot remap | **Yes** |
| Type-5 bank walk + early clear | **Yes** |
| No invented modernization branches | **Yes** |

---

## 5. Residual callee map (evidence-only)

| Addr | Inferred dual name | Seal basis |
|------|-------------------|------------|
| `0x008a0ed0` | `QuickBar_SelectPage_Inferred` | Page 0..9 → `param[0x143]`/`+0x50c`; 10-widget refresh |
| `0x00922270` | `Input_TryFirePrimaryWeapons_Inferred` | char+0x550 hardpoint skills → CastSkillFromQB; else primary heat/fire; DriveControlTick |
| `0x00941d50` | `Client_UseInventoryItem_Inferred` | C2S **0x2045** size 0x28; ConfirmEquip path; item-skill cast arm |
| `0x00941fb0` | `Client_SendChatOrMacro_Inferred` | Packet **0x2021**; channel cases; PollBoundActions macro edges |
| `0x005710c0` | cargo find-by-COID (open product name) | Grid walk `type+0x34==coid` |

Do **not** promote product symbols without string/RTTI/registry pass.

---

## 6. Gaps / open questions

1. Product names for residual callees (still `_Inferred` / FUN_* in clean).
2. Type enum 1/2/5 string seal from UI bind (type-5 product word **chat-macro** is evidence-strong; formal enum name open).
3. `FUN_00941fb0` call-site arg mapping (decomp drops phrase ptr vs host+0x510 — register noise).
4. Busy latch left set on type-2 subtype-8 early return — intentional re-entry block vs leak?
5. Runtime: shift-QB page switch + macro bank activate capture.
6. Bit-for-bit / differential open.

**Verdict:** Hotbar dispatcher CF faithful; type-5 math + packing + mode-1 page residual sealed. **accept-with-gaps.**
