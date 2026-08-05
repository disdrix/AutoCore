# Reconstruction review: `aa_00815710` Client_PacketDispatch

| Field | Value |
|---|---|
| **Stable ID** | `aa_00815710` |
| **VA** | `0x00815710` |
| **Canonical name** | `Client_PacketDispatch` |
| **Review date** | `2026-07-23` |
| **Reviewer role** | Independent reconstruction review (faithfulness of clean C++ to low-level / raw) |
| **Author of reconstruction** | Not this reviewer |
| **Verdict** | **accept-with-gaps** |

---

## 1. What was inspected

| Artifact | Path | Role |
|---|---|---|
| Raw | `docs/reconstruction/raw/aa_00815710_Client_PacketDispatch.md` | Authoritative decompile |
| Annotated | `…annotated.md` | Scaffold copy |
| Exact C++ | `reconstructed-exact/Client_PacketDispatch.cpp` | Clean surface (human-refined comments) |
| Function record | `functions/aa_00815710_Client_PacketDispatch.md` | Status |
| Fresh decompile | Ghidra MCP `batch_decompile` → `coverage/tmp_batch_packetdispatch.json` | Cross-check 2026-07-23 |
| Callee units | CharacterLevel / GiveCredits / CompleteDynamicObjective / inventory recv units | Named case targets |
| Opcode map | `src/AutoCore.Game/Constants/GameOpcode.cs` | Comment labels only |

**Primary claims under review:**

1. Large S2C `switch(opcode)` with outer gates `< 0x8064` and `!= 0x8063`, plus high opcodes `0x9001` / `0x9004` / `0x901c`
2. Handled → return `1`; unknown → return `0`; multi-case fallthroughs share intentional no-op
3. Mission/XP/inventory/skill named cases call reconstructed handlers as in raw
4. Clean comment pass does not invent callees or drop cases
5. `0x2030` RequestCastSkill is **absent** (C2S) — correctly not fabricated

**Not re-authored.** Fresh decompile confirmed CF parity with raw (whitespace / unicode only).

---

## 2. What evidence was used

| Evidence | Source | Use |
|---|---|---|
| Raw full switch body | Raw capture | Ground-truth CF |
| Fresh batch_decompile of `0x00815710` | Ghidra HTTP `/batch_decompile` | Confirm raw not stale |
| Clean C++ | reconstructed-exact | Fidelity + comment hygiene |
| GameOpcode.cs | AutoCore | Label comments for known opcodes |
| Sibling reviews (grab/drop) | reviews/aa_00811be0*, aa_00813730* | Shared-handler cases |

---

## 3. What was confirmed

### 3.1 Control flow: clean ≡ raw

| Stage | Match |
|---|---|
| `*in_EAX = 1`; read `param_2->dwOpcode` | **Yes** |
| Outer `uVar1 < 0x8064` then `!= 0x8063` | **Yes** |
| Full case set (121 labels including multi-case fallthroughs) | **Yes** |
| Default → `return 0` | **Yes** |
| Shared no-op goto `switchD_00815749_caseD_2003` | **Yes** |
| `0x8063` path: coid check → `FUN_00540c50` / `FUN_005409c0` | **Yes** |
| High range: `0x9001`, `0x9004`, `0x901c`, else 0 | **Yes** |

### 3.2 Priority mission / XP / inventory / skill cases

| Opcode | Handler in clean/raw | Match |
|---|---|---|
| `0x2017` | `Client_RecvCharacterLevel` | **Yes** |
| `0x2031` | `Client_RecvSkillStatusEffect` | **Yes** |
| `0x2035`/`0x2039` | `Client_RecvInventoryGrabResponse` | **Yes** |
| `0x2037`/`0x203b` | `Client_RecvInventoryDropResponse` | **Yes** |
| `0x203c` | `Client_RecvInventoryEquip` | **Yes** |
| `0x203e`/`0x203f` | Unequip notify/response | **Yes** |
| `0x2040`–`0x2043` | No-op fallthrough | **Yes** |
| `0x2044`/`0x2046`/`0x2047` | Paint / UseItemResponse / AddItem | **Yes** |
| `0x205e` | `Client_RecvGiveCredits` | **Yes** |
| `0x205f` | `Client_AwardKillExperience` | **Yes** |
| `0x206c`/`0x206d` | GroupReactionCall / NpcMissionDialog | **Yes** |
| `0x2070`/`0x2071` | CompleteDynamicObjective / ObjectiveState | **Yes** |

### 3.3 Type renames only

`undefined4`→`uint32_t /* width from decompiler */`, `undefined1`→`uint8_t`. No branch pruning.

### 3.4 Comment pass honesty

Plate + per-case comments map AutoCore `GameOpcode` names onto decompiler cases. Comments do not replace `FUN_*` with invented symbols where Ghidra still has FUN names. Explicit note that `0x2030` is C2S-only.

### 3.5 Function record honesty

Partial scaffold — appropriate for a mega-switch.

---

## 4. Discrepancies or improvements needed

| Item | Severity | Notes |
|---|---|---|
| Signature / packet type | Medium | Decompiler types `param_2` as `Packet_CharacterLevel *` for all opcodes — type is wrong for most cases; field uses (`dwOpcode`, `dwCoidLo`) still match layout header |
| `unaff_ESI` / `unaff_EDI` on credits/XP/grab | Medium | Register recovery fragile; same as raw. Formal args to GiveCredits look swapped vs plate “ESI=game, EDI=packet” in callee unit |
| High opcodes `0x9xxx` / `0x8063` semantics | Low | Not fully named; CF preserved |
| Many remaining `FUN_*` leaves | Expected | Out of unit scope |
| Annotated layer | Meta | Still scaffold; no per-case recovered structs |

**No fidelity revision required** for clean≡raw control flow after human comment refine.

---

## 5. What remains uncertain

1. True C ABI (thiscall/fastcall registers for client vs packet vs out-flag).
2. Complete semantic map for every `FUN_*` leaf (store, refinery, trade, etc.).
3. Whether all no-op fallthrough opcodes are truly empty in retail or only empty in this decompile view of dispatch.
4. Packet header struct shared across cases (`dwOpcode`, coid fields).
5. Live traffic differential for priority paths.
6. Boundary behavior for opcodes in gaps (e.g. `0x2011`, `0x2030`, `0x2045`) → default `0`.

---

## 6. Verdict

### **accept-with-gaps**

Mega-switch is scaffolded faithfully from raw and re-confirmed against live Ghidra `batch_decompile`. Human comments improve navigability for mission/inventory/skill/XP cases without CF drift. Gaps are ABI typing, register-arg recovery on a few paths, and un-named FUN leaves — not clean/raw mismatch.

---

## Checklist (reviewer)

| Check | Result |
|---|---|
| Clean CF matches raw | **Pass** |
| Fresh decompile vs raw | **Pass** (whitespace only) |
| Priority named cases preserved | **Pass** |
| No invented `0x2030` S2C case | **Pass** |
| Signature / packet types complete | **Open** |
| All FUN leaves named | **Open** |
| Verdict | **accept-with-gaps** |
