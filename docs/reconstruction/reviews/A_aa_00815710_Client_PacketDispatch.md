# Review A (reconstruction fidelity): `aa_00815710` Client_PacketDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **VA** | `0x00815710` |
| **Canonical name** | `Client_PacketDispatch` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review |
| **Counterpart** | `reviews/B_aa_00815710_Client_PacketDispatch.md` |
| **Verdict** | **accept-with-gaps** |

---

## 1. Inspected artifacts

| Artifact | Path |
|---|---|
| Raw | `docs/reconstruction/raw/aa_00815710_Client_PacketDispatch.md` |
| Clean | `docs/reconstruction/reconstructed-exact/Client_PacketDispatch.cpp` |
| Prior dual | `aa_00815710_reconstruction_review.md` / `aa_00815710_skeptical_review.md` |
| Opcode map | `src/AutoCore.Game/Constants/GameOpcode.cs` (comment labels only) |

---

## 2. Confidence table

| Claim | Confidence | Notes |
|---|---|---|
| Large S2C `switch(opcode)` with outer `< 0x8064` / `!= 0x8063` gates | **High** | Raw + clean CF match |
| Handled → `return 1`; unknown → `return 0` | **High** | Default + high-range else |
| Multi-case intentional no-op fallthrough (label 0x2003) | **High** | Shared goto preserved |
| `0x2017` → `Client_RecvCharacterLevel` | **High** | Named callee |
| `0x203C` → `Client_RecvInventoryEquip` | **High** | Named callee |
| `0x205F` → `Client_AwardKillExperience` | **High** | Named callee |
| `0x2070` → `Client_RecvCompleteDynamicObjective` | **High** | force-complete path |
| `0x2071` → `Client_RecvObjectiveState` | **High** | progress-only; not CompleteObjective |
| `0x2031` → `Client_RecvSkillStatusEffect` | **High** | Skills S2C |
| `0x2030` RequestCastSkill **absent** (C2S) | **High** | Important negative; not fabricated |
| Param rename `pCtx` / `pPacket` / `pPayload` | **Medium** | Roles clear from use; decomp types still imperfect |
| Register framing (`unaff_ESI` / `unaff_EDI`) for GiveXP/credits | **Tentative** | Dispatch register recovery open |
| `Packet_CharacterLevel*` type for all opcodes | **Low** (type only) | Header stand-in; field uses (`dwOpcode`) still valid |

---

## 3. Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| `*in_EAX = 1`; read `pPacket->dwOpcode` | **Yes** |
| Outer range gates + full case set | **Yes** |
| Mission / inventory / skill named cases | **Yes** |
| High opcodes `0x9001` / `0x9004` / `0x901c` | **Yes** |
| No invented cases or pruned branches | **Yes** |

---

## 4. Gaps

1. Decompiler types many packet bodies as `Packet_CharacterLevel*` — layout header only.
2. GiveCredits / GiveXP / grab handlers still depend on imperfect register recovery.
3. Many `FUN_*` case targets remain unresolved pending type recovery.

**Verdict:** Switch surface faithful. Comment/param readability pass does not change CF. **accept-with-gaps.**
